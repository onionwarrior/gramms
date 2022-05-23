#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <type_traits>
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
class PtrBits {
  // if a bit is set - ptr is const;
  std::bitset<64> ptrs_;
  std::size_t counter_ = 0;

public:
  auto AddIndirection(const bool is_const) { ptrs_[counter_++] = is_const; }
  auto GetIndirection() const { return counter_; }
  auto GetBit(const size_t b) const { return ptrs_[b]; }
  PtrBits(const std::size_t ind) {
    for (auto i = 0u; i < ind; i++)
      ptrs_.set(i);
  }
  PtrBits() = default;
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
typedef std::vector<std::string> Enum;
enum class UsrTypeKind { Struct, Union };
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
  auto HasField(const std::string &field) {
    return types_.find(field) != types_.cend();
  }
  auto GetUnderlyingType() const {
    auto &&[_, type] = *(types_.begin());
    return type;
  }
};

struct Func;
typedef std::false_type NoneType;
typedef std::variant<NoneType, Primitive, UserType, Func *, Enum> TypeOrNone;
typedef std::variant<Primitive, UserType, Func *, Enum> ArrayType;
inline auto IsNoneType(const mcc::TypeOrNone &t) {
  return std::holds_alternative<mcc::NoneType>(t);
}
/* An array is represented as a vector of size_t's, which indicate array sizes
 * * i.e.
 * int arr[10][5][33] is represented as <10,5,33>
 */
class CArray {
  mcc::ArrayType arr_type_;
  std::vector<std::size_t> sizes_;

public:
  auto GetArrayIndirection() const { return sizes_.size(); }
  auto GetSizeAt(const std::size_t idx) const { return sizes_[idx]; }
  template <
      typename T, typename It,
      std::enable_if_t<
          std::is_constructible_v<ArrayType, T> &&
              std::is_convertible_v<decltype(*std::declval<It>()), std::size_t>,
          bool> = true>
  CArray(const T &type, It begin, It end)
      : arr_type_{type}, sizes_{begin, end} {
    assert(begin != end);
  }
};
typedef std::variant<Primitive, UserType, Func *, Enum, CArray> Type;
class Func {
  Type return_type_;
  std::vector<Type> args_;

public:
  Func(const Type &ret, const std::vector<Type> &args)
      : return_type_{ret}, args_{args} {}
};
inline auto IsIntegerT(const Type &t) {
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
  mcc::Type type_;
  bool defined_ = false;
  mcc::PtrBits indirection_;
  bool is_const_ = false;

public:
  bool is_default = true;

  auto inline GetIndLevel() const { return indirection_.GetIndirection(); }
  auto inline IsPtr() const { return GetIndLevel() > 0; }
  auto inline DerefIsConst() const {
    return indirection_.GetBit(GetIndLevel() - 1);
  }
  auto inline IsLvalue() const { return is_lvalue_; }
  auto inline IsConst() const { return is_const_; }
  Symbol(const Type &type, const std::size_t indirection_lvl,
         const bool is_const, bool defined, bool is_lvalue)
      : type_{type}, indirection_(indirection_lvl),
        is_const_(is_const), defined_{defined}, is_lvalue_(is_lvalue) {
    is_default = false;
  }
  Symbol() = default;
  Symbol(const Symbol &) = default;
  auto GetType() const { return type_; }
};
class SymbolTable {

private:
  std::map<std::string, Symbol> symbols_;
  // 0 -> inst, 1 -> pointer, 2 -> pointer to pointer etc.
public:
  auto Dump() const {
    for (auto &&[k, v] : symbols_) {
      mcc::PrintColored("\n|" + k + "|\n", TextColor::Warning);
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
  std::map<std::string, Type> types_ = {
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
      {"blah", Primitive::Int},
      {"void", Primitive::Void}};

public:
  TypeTable() = default;
  auto DefineNewType(const std::string &type_name, const UserType &type) {
    if (types_.find(type_name) != types_.cend())
      return false;
    types_[type_name] = type;
    return true;
  }
  auto TypeDefined(const std::string &name) const {
    return types_.find(name) != types_.cend();
  }
  auto GetTypeByName(const std::string &name) const {
    if (TypeDefined(name))
      return std::optional<Type>(types_.at(name));
    return std::optional<Type>{};
  }
  auto DefineNewTypedef(const std::string &type_name,
                        const std::string &alias) {
    types_[alias] = types_[type_name];
  }
};
inline auto EvalsToBool(const Symbol &sym) {
  const auto is_primitive =
      std::holds_alternative<mcc::Primitive>(sym.GetType());
  const auto is_ptr = sym.IsPtr();
  if (!is_primitive && !is_ptr) {
    mcc::PrintColored("Could not evaluate as pointer or arithmetic type",
                      mcc::TextColor::Error);
  } else if (std::get<mcc::Primitive>(sym.GetType()) == mcc::Primitive::Void) {
    mcc::PrintColored("Void where pointer or arithmetic type is required",
                      mcc::TextColor::Error);
  }
}

} // namespace mcc
#endif
