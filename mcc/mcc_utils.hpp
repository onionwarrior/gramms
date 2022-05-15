#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>
#if !defined(MCC_UTILS)
#define MCC_UTILS
namespace mcc {
enum class Primitive {
  Int,
  UInt,
  Long,
  LongLong,
  ULong,
  ULongLong,
  Short,
  UShort,
  Char,
  UChar,
  Float,
  Double,
  LongDouble,
  Void
};
enum class TextColor { Error, Warning, Good };
inline auto PrintColored(const std::string &text, TextColor color) {
  switch (color) {
  case TextColor::Error:
    std::cout << "\033[31m"
              << "<<<"
              << "Error: " << text << "\033[0m";
    break;
  case TextColor::Warning:
    std::cout << "\033[33m"
              << "<<<"
              << "Warning: " << text << "\033[0m";
    break;
  case TextColor::Good:
    std::cout << "\033[32m"
              << "<<<"
              << "Debug: " << text << "\033[0m";
    break;
  }
}
enum class UsrTypeKind { Struct, Union, Typedef };
class UserType {
private:
  UsrTypeKind kind_;
  // Either a single type in case of a typedef or a list of types (union or
  // struct)
  // maps a type alias to a real type or a field name to type
  std::map<std::string, std::string> types_;

public:
  UserType(UsrTypeKind kind, const std::map<std::string, std::string> &types)
      : kind_{kind}, types_{types} {}
  auto IsTypeSum() const { return kind_ != UsrTypeKind::Typedef; }
  auto HasField(const std::string &field) {
    return types_.find(field) != types_.cend();
  }
  auto IsTypedef() const { return kind_ == UsrTypeKind::Typedef; }
  auto GetUnderlyingType() const {
    auto &&[_, type] = *(types_.begin());
    return type;
  }
};

struct Func;
typedef std::variant<bool,Primitive, UserType, Func *> type_t;
struct Func {
  type_t return_type_;
  std::vector<type_t> args;
};
inline auto IsIntegerT(const type_t &t) {
  std::array<std::string, 10> integer_types{
      {"int", "unsigned int", "char", "unsigned char", "long", "long long",
       "unsigned long", "unsigned long long", "short", "unsigned short"}};
  if (std::holds_alternative<UserType>(t))
    return std::find(integer_types.cbegin(), integer_types.cend(),
                     std::get<UserType>(t).GetUnderlyingType()) !=
           integer_types.cend();
  if (std::holds_alternative<Primitive>(t)) {
    const auto e_type = std::get<Primitive>(t);
    return e_type != Primitive::Void && e_type != Primitive::Float &&
           e_type != Primitive::Double && e_type != Primitive::LongDouble;
  }
  return false;
}
class Symbol {
  bool is_lvalue_ = true;
  mcc::type_t type_;
  bool defined_ = false;
  std::size_t indirection_lvl_ = 0;
  bool is_const_ = false;

public:
  auto inline GetIndLevel() const { return indirection_lvl_; }
  auto inline IsPtr() const { return indirection_lvl_ > 0; }
  auto inline IsLvalue() const { return is_lvalue_; }

  Symbol(const type_t &type, const std::size_t indirection_lvl,
         const bool is_const, bool defined, bool is_lvalue)
      : type_{type}, indirection_lvl_(indirection_lvl),
        is_const_(is_const), defined_{defined},is_lvalue_(is_lvalue) {}
  Symbol() = default;
  auto GetType() const { return type_; }
};
class SymbolTable {

private:
  std::map<std::string, Symbol> symbols_;
  // 0 -> inst, 1 -> pointer, 2 -> pointer to pointer etc.
public:
  auto Dump() const
  {
    for(auto && [k,v]:symbols_)
    {
      mcc::PrintColored("\n|"+k+"|\n", TextColor::Warning);
    }
  }
  SymbolTable() = default;

  auto DefineNewSymbol(const std::string &symbol_name, const Symbol &symbol) {
    if (symbols_.find(symbol_name) != symbols_.cend())
      return false;
    symbols_[symbol_name] = symbol;
    return true;
  }
  auto GetSymbol(const std::string &name) {
    if (symbols_.find(name) != symbols_.cend()) {
      return std::optional{symbols_[name]};
    }
    return std::optional<Symbol>{};
  }
};
class TypeTable {
private:
  std::map<std::string, type_t> types_ = {
      {"int", Primitive::Int},
      {"unsigned int", Primitive::UInt},
      {"long", Primitive::Long},
      {"long long", Primitive::LongLong},
      {"unsigned long", Primitive::ULong},
      {"unsigned long long", Primitive::ULongLong},
      {"short", Primitive::Short},
      {"unsigned short", Primitive::UShort},
      {"char", Primitive::Char},
      {"unsigned char", Primitive::UChar},
      {"float", Primitive::Float},
      {"double", Primitive::Double},
      {"long double", Primitive::LongDouble},
      {"void", Primitive::Void}};

public:
  TypeTable() = default;
  auto DefineNewType(const std::string &type_name, const UserType &type) {
    if (types_.find(type_name) != types_.cend())
      return false;
    types_[type_name] = type;
    return true;
  }

}; // namespace mcc
} // namespace mcc
#endif
