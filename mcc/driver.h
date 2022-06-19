#ifndef _DRIVER_H_
#define _DRIVER_H_
#include "location.hh"
#include "mcc.tab.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#define YY_DECL yy::parser::symbol_type yylex(driver &drv)
YY_DECL;
class driver {
private:
  std::deque<std::string> scopes_;
  std::deque<mcc::T> switch_types_;
  std::size_t anon_scope_cnt_ = 0;
  mcc::SymbolTable symb_table_;
  mcc::TypeTable type_table_;
  std::set<std::string> labels_;
  std::set<std::string> labels_refd_;
  mcc::T cur_type_;
  mcc::T current_func_ret_type;
  mcc::Symbol subroutine_sym_;
  bool is_in_const_;

public:
  auto SetInConst(bool c) { is_in_const_ = c; }
  auto GetInConst() const { return is_in_const_; }
  driver();
  int64_t result = 0;
  int parse(const std::string &f);
  std::string file;
  bool trace_parsing = false;
  void scan_begin();
  void scan_end();
  bool trace_scanning = false;
  yy::location location;
  auto AddLabel(const std::string &label) {
    if (labels_.find(label) != labels_.cend())
      {
      mcc::PrintColored("Label " + label + " already defined in this scope",
                        mcc::TextColor::Error);
    } else {
      labels_.insert(label);
    }
  }
  auto SetCurrentFuncReturnType(const mcc::T &t) { current_func_ret_type = t; }
  auto GetCurrentFuncReturnType() const { return current_func_ret_type; }
  auto EnterSubroutine(const mcc::Symbol &s) { subroutine_sym_ = s; }
  const auto GetSubroutineSymbol() const { return subroutine_sym_; }
  auto UndefLabelRefs() const {
    std::set<std::string> diff;
    std::set_difference(labels_refd_.begin(), labels_refd_.end(),
                        labels_.begin(), labels_.end(),
                        std::inserter(diff, diff.begin()));
    return diff;
  }

  auto AddLabelRef(const std::string &label) { labels_refd_.insert(label); }
  auto EnterNewScope(const std::string &scope) {
    if (!scope.empty()) {
      scopes_.push_back(scope + "::");
    } else {
      anon_scope_cnt_++;
      scopes_.push_back("@" + std::to_string(anon_scope_cnt_) + "::");
    }
  }
  auto SetCurrentSwitchType(const mcc::T&t) { switch_types_.push_back(t);}
  auto GetCurrentSwitchType() const { return switch_types_.back();}
  auto UnsetCurrentSwitchType() {switch_types_.pop_back();}
  auto GetCurrentType() const { return cur_type_; }
  auto SetCurrentType(const mcc::T &t) { cur_type_ = t; }
  auto UnsetCurrentType() { cur_type_ = {}; }
  auto LeaveScope() {
    if (scopes_.back()[0] == '@')
      anon_scope_cnt_--;

    scopes_.pop_back();
    if (anon_scope_cnt_ == 0) {
      const auto error_labels = UndefLabelRefs();
      if (!error_labels.empty()) {
        for (auto &&label : error_labels) {
          mcc::PrintColored("Label " + label + " is referenced but not defined",
                            mcc::TextColor::Error);
        }
      }
      labels_refd_.clear();
      labels_.clear();
    }
  }
  auto GetCurrentScope() const {
    if (scopes_.empty()) {
      return std::string{"@::"};
    } else
      return std::accumulate(scopes_.begin(), scopes_.end(), std::string{});
  }
  auto AddSymbol(const std::string &name, const mcc::Symbol &symbol) {
   return symb_table_.DefineNewSymbol(GetCurrentScope() + name, symbol);
  }
  auto GetType(const std::string &name) const {
    return type_table_.GetTypeByName(name);
  }
  auto GetSymbol(const std::string &name) {
    return symb_table_.GetSymbol(name);
  }
  auto DumpSymbols() const { symb_table_.Dump(); }
  auto AddTypeAlias(const std::string &type_name, const std::string &alias) {
    type_table_.DefineNewTypedef(type_name, alias);
  }
};
#endif
