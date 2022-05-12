#ifndef _DRIVER_H_
#define _DRIVER_H_
#include "location.hh"
#include "mcc_c.tab.h"
#include <deque>
#include <numeric>
#include <set>
#include <string>
#define YY_DECL yy::parser::symbol_type yylex(driver &drv)
YY_DECL;
class driver {
private:
  std::deque<std::string> scopes_;
  std::size_t anon_scope_cnt_;
  mcc::SymbolTable symb_table_;
  mcc::TypeTable type_table_;
  std::set<std::string> labels_;

public:
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
      scopes_.push_back(scope);
    } else {
      anon_scope_cnt_++;
      scopes_.push_back("@" + std::to_string(anon_scope_cnt_) + "::");
    }
  }
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
};
#endif
