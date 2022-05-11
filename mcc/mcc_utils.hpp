#include <array>
#include <cstddef>
#include <iostream>
#include <map>
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
              << "<<<" << "Error: " << text << "\033[0m" << std::endl;
    break;
  case TextColor::Warning:
    std::cout << "\033[33m"
              << "<<<" << "Warning: " << text << "\033[0m" << std::endl;
    break;
  case TextColor::Good:
    std::cout <<"\033[32m"
              << "<<<" << "Debug: " << text << "\033[0m" << std::endl;
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
};
struct Func;
using type_t = std::variant<Primitive, UserType, Func *>;
struct Func {
  type_t return_type_;
  std::vector<type_t> args;
};
inline auto Mangle(const std::string &name, const std::string &ns_name) {
  if (ns_name.empty())
    return "::" + name;
  return ns_name + "::" + name;
}
class Symbol {
  type_t type;
  bool is_const;
private:
};
class SymbolTable {

protected:
  static SymbolTable *inst_;

private:
  std::map<std::string, Symbol> symbols_;
  SymbolTable() = default;
  // 0 -> inst, 1 -> pointer, 2 -> pointer to pointer etc.
  std::size_t indirection_lvl_ = 0;

public:
  auto DefineNewSymbol(const std::string &symbol_name, const Symbol &symbol) {
    if (symbols_.find(symbol_name) != symbols_.cend())
      return false;
    symbols_[symbol_name] = symbol;
    return true;
  }
  auto inline Init() { inst_ = new SymbolTable(); }
  auto inline GetIndLevel() const { return indirection_lvl_; }
  auto inline IsPtr() const { return indirection_lvl_ > 0; }
};
class TypeTable {
private:
  TypeTable() = default;

protected:
  static TypeTable *table_;
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
  static void Init() { table_ = new TypeTable(); }
  auto DefineNewType(const std::string &type_name, const UserType &type) {
    if (types_.find(type_name) != types_.cend())
      return false;
    types_[type_name] = type;
    return true;
  }

}; // namespace mcc
} // namespace mcc
#endif
