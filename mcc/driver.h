#ifndef _DRIVER_H_
#define _DRIVER_H_
#include "location.hh"
#include "mcc_c.tab.h"
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
  std::size_t anon_scope_cnt_=0;
  mcc::SymbolTable symb_table_;
  mcc::TypeTable type_table_;
  std::set<std::string> labels_;
  mcc::Type cur_type_;
  bool is_in_const_;
public:
  auto SetInConst(bool c) {is_in_const_=c;}
  auto GetInConst() const {return is_in_const_;}
  driver();
  int64_t result = 0;
  int parse(const std::string &f);
  std::string file;
  bool trace_parsing = false;
  void scan_begin();
  void scan_end();
  bool trace_scanning = false;
  yy::location location;
  auto EnterNewScope(const std::string &scope) {
    if (!scope.empty()) {
      scopes_.push_back(scope+"::");
    } else {
      anon_scope_cnt_++;
      scopes_.push_back("@" + std::to_string(anon_scope_cnt_) + "::");
    }
  }
  auto GetCurrentType() const {return cur_type_;}
  auto SetCurrentType(const mcc::Type &t) { cur_type_ = t; }
  auto UnsetCurrentType() { cur_type_ = {}; }
  auto LeaveScope() {
    if (scopes_.back()[0] == '@')
      anon_scope_cnt_--;
    scopes_.pop_back();
  }
  auto GetCurrentScope() const {
    if (scopes_.empty()) {
      return std::string{"@::"};
    } else
      return std::accumulate(scopes_.begin(), scopes_.end(), std::string{});
  }
  auto AddSymbol(const std::string &name, mcc::Symbol &&symbol) {
    symb_table_.DefineNewSymbol(GetCurrentScope() + name, symbol);
  }
  auto GetType(const std::string & name) const {return type_table_.GetTypeByName(name);}
  auto GetSymbol(const std::string &name) {
    return symb_table_.GetSymbol(name);
  }
  auto DumpSymbols() const
  {
    symb_table_.Dump();
  }
  auto AddTypeAlias(const std::string & type_name,const std::string & alias)
  {
    type_table_.DefineNewTypedef(type_name, alias);
  }
};
#endif
