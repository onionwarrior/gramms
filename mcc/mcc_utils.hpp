#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <memory>
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
template <class... Args> struct variant_cast_proxy {
  std::variant<Args...> v;

  template <class... ToArgs> operator std::variant<ToArgs...>() const {
    return std::visit([](auto &&arg) -> std::variant<ToArgs...> { return arg; },
                      v);
  }
};

template <class... Args>
auto variant_cast(const std::variant<Args...> &v)
    -> variant_cast_proxy<Args...> {
  return {v};
}
class PtrBits {
  // if a bit is set - ptr is const;
  std::bitset<256> ptrs_ = 0;
  std::size_t counter_ = 0;

public:
  auto AddIndirection(const bool is_const) { ptrs_[counter_++] = is_const; }
  auto GetIndirection() const { return counter_; }
  auto GetBit(const size_t b) const { return ptrs_[b]; }
  PtrBits(const std::size_t ind) {

    for (counter_ = 0u; counter_ < ind; counter_++)
      ptrs_.set(counter_);
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
  // maps a field name to type
  std::map<std::string, std::string> types_;
  std::string name_;

public:
  UserType(UsrTypeKind kind, const std::map<std::string, std::string> &types)
      : kind_{kind}, types_{types} {}
  auto HasField(const std::string &field) {
    return types_.find(field) != types_.cend();
  }
  auto GetFieldTName(const std::string &field) const {
    return types_.at(field);
  }
  friend bool operator==(const UserType &l, const UserType &r) {
    return l.name_ == r.name_;
  }
  friend bool operator!=(const UserType &l, const UserType &r) {
    return !(l == r);
  }
};

struct Func;
typedef bool NoneType;
typedef std::variant<Primitive, UserType, std::shared_ptr<Func>, Enum>
    ArrayType;

/* An array is represented as a vector of size_t's, which indicate array sizes
 * * i.e.
 * int arr[10][5][33] is represented as <10,5,33>
 */
class CArray;
typedef std::variant<NoneType, Primitive, UserType, std::shared_ptr<Func>, Enum,
                     CArray>
    TypeOrNone;
class CArray {
  mcc::ArrayType arr_type_;
  std::vector<std::size_t> sizes_;

public:
  auto GetArrayIndirection() const { return sizes_.size(); }
  auto GetSizeAt(const std::size_t idx) const { return sizes_[idx]; }
  mcc::TypeOrNone GetDerefT() const {
    if (sizes_.size() > 1)
      return mcc::CArray{arr_type_, sizes_.begin(), sizes_.end() - 1};
    else
      return variant_cast(arr_type_);
  }
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

class T {
  mcc::PtrBits ptr_;
  mcc::TypeOrNone t_;

public:
  T(const mcc::PtrBits &ptr, const mcc::TypeOrNone &t) : ptr_{ptr}, t_{t} {}
  T(const mcc::TypeOrNone &t, const mcc::PtrBits &ptr) : ptr_{ptr}, t_{t} {}
  T(const mcc::TypeOrNone &t) : t_{t} {}
  T() = default;
  mcc::ArrayType ToArrT() const {
    return std::visit(
        [this](auto &&arg) {
          using T = std::decay_t<decltype(arg)>;
          if constexpr (std::is_same_v<T, Primitive>)
            return mcc::ArrayType{std::get<T>(t_)};
          else if constexpr (std::is_same_v<T, std::shared_ptr<Func>>)
            return mcc::ArrayType{std::get<T>(t_)};
          else if constexpr (std::is_same_v<T, UserType>)
            return mcc::ArrayType(std::get<T>(t_));
          else if constexpr (std::is_same_v<T, Enum>)
            return mcc::ArrayType(std::get<T>(t_));
          else
            return mcc::ArrayType{mcc::Primitive::Void};
        },
        t_);
  }
  template <typename T> auto IsT() const {
    return std::holds_alternative<T>(t_);
  }
  auto IsVoid() const {
    return IsT<mcc::Primitive>() &&
           std::get<mcc::Primitive>(t_) == mcc::Primitive::Void;
  }

  auto GetType() const { return t_; }
  auto GetPtr() const { return ptr_; }
  auto GetInd() const { return ptr_.GetIndirection(); }
  auto IsPtrT() const { return ptr_.GetIndirection() > 0; }
  /*typedef std::variant<NoneType, Primitive, UserType, std::shared_ptr<Func>,
    Enum, CArray> TypeOrNone;
*/
  friend bool operator==(const mcc::T &l, const mcc::T &r) {
    auto lt = l.GetType();
    auto rt = r.GetType();
    auto li = l.GetInd();
    auto ri = r.GetInd();
    if (std::holds_alternative<NoneType>(lt) &&
        std::holds_alternative<NoneType>(rt))
      return true;
    if ((std::holds_alternative<Primitive>(lt) ||
         std::holds_alternative<Enum>(lt)) &&
        (std::holds_alternative<Primitive>(rt) ||
         std::holds_alternative<Enum>(rt)))
      return std::get<Primitive>(lt) != mcc::Primitive::Void &&
             std::get<Primitive>(rt) != mcc::Primitive::Void;
    if (std::holds_alternative<UserType>(lt) &&
        std::holds_alternative<UserType>(rt))
      return std::get<UserType>(lt) == std::get<UserType>(rt);
    return false;
  }
  friend bool operator!=(const mcc::T &l, const mcc::T &r) { return !(l == r); }
};
inline auto IsNoneType(const mcc::TypeOrNone &t) {
  return std::holds_alternative<mcc::NoneType>(t);
}
class Func {
  T return_type_ = {mcc::Primitive::Int};
  std::vector<T> args_;
  std::vector<std::string> names_;
  std::vector<bool> consts_;

public:
  auto SetReturnType(const mcc::T &new_t) { return_type_ = new_t; }
  auto GetReturnType() const { return return_type_; }
  const auto GetParams() const {
    std::vector<std::tuple<std::string, T,bool>> ret;
    for (auto i = 0u; i < args_.size(); i++) {
      ret.emplace_back(std::make_tuple(names_[i], args_[i],consts_[i]));
    }
    return ret;
  }
  const auto &GetArgs() const { return args_; }
  Func(const std::vector<T> &args, const std::vector<std::string> &names,
       const std::vector<bool> &consts)
      : args_{args}, names_{names}, consts_{consts} {}
  Func(const T &ret, const std::vector<T> &args,
       const std::vector<std::string> &names,const std::vector<bool>&consts)
      : return_type_{ret}, args_{args}, names_{names},consts_{consts}{}
};
inline auto IsIntegerT(const T &t) {
  if (std::holds_alternative<Enum>(t.GetType()) && !t.IsPtrT())
    return true;
  if (std::holds_alternative<Primitive>(t.GetType()) && !t.IsPtrT()) {
    const auto e_type = std::get<Primitive>(t.GetType());
    return e_type != Primitive::Void && e_type != Primitive::Float &&
           e_type != Primitive::Double && e_type != Primitive::LongDouble;
  }
  return false;
}
class Symbol {
  bool is_lvalue_ = true;
  mcc::T type_;
  bool defined_ = false;
  bool is_const_ = false;
  bool is_default_constructed_ = true;

public:
  auto inline GetIndLevel() const { return type_.GetInd(); }
  auto inline IsPtr() const { return type_.IsPtrT(); }
  auto inline EvalsToInt() const {
    const auto t = type_.GetType();
    return type_.IsPtrT() || std::holds_alternative<Enum>(t) ||
           std::holds_alternative<mcc::Primitive>(t);
  }
  auto inline DerefIsConst() const {
    return type_.GetPtr().GetBit(GetIndLevel() - 1);
  }
  auto inline GetPtrTo() const {
    return mcc::Symbol{
        {type_.GetType(), type_.GetInd() + 1}, true, true, false};
  }
  auto inline GetDeref() const { return mcc::PtrBits{type_.GetInd() - 1}; }
  auto inline IsLvalue() const { return is_lvalue_; }
  auto inline IsConst() const { return is_const_; }
  auto inline IsDefined() const { return defined_; }
  Symbol(const T &type, const bool is_const, bool defined, bool is_lvalue)
      : type_{type}, is_const_(is_const), defined_{defined},
        is_lvalue_(is_lvalue) {
    is_default_constructed_ = false;
  }
  Symbol() = default;
  Symbol(const Symbol &) = default;
  auto GetType() const { return type_.GetType(); }
  auto GetRvalue() const { return Symbol{type_, is_const_, defined_, false}; }
  auto IsUserType() const {
    return std::holds_alternative<mcc::UserType>(type_.GetType());
  }
  friend auto inline AreComparable(const Symbol &l, const Symbol &r);
  friend auto inline AreCompactible(const Symbol &l, const Symbol &r);
};
auto inline AreComparable(const Symbol &l, const Symbol &r) {
  return (l.EvalsToInt() && r.EvalsToInt());
}
auto inline AreCompactible(const Symbol &l, const Symbol &r) {
  return AreComparable(l, r) || (l.type_ == r.type_);
}

auto inline IsFuncPtr(const mcc::Symbol &s) {
  return std::holds_alternative<std::shared_ptr<Func>>(s.GetType());
}
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
  std::map<std::string, T> types_ = {
      {"int", {Primitive::Int}},
      {"unsigned int", {Primitive::UInt}},
      {"long", {Primitive::Long}},
      {"long long", {Primitive::LongLong}},
      {"unsigned long", {Primitive::ULong}},
      {"unsigned long long", {Primitive::ULongLong}},
      {"short", {Primitive::Short}},
      {"unsigned short", {Primitive::UShort}},
      {"char", {Primitive::Char}},
      {"unsigned char", {Primitive::UChar}},
      {"float", {Primitive::Float}},
      {"double", {Primitive::Double}},
      {"long double", {Primitive::LongDouble}},
      {"blah", {Primitive::Int}},
      {"void", {Primitive::Void}}};

public:
  TypeTable() = default;
  auto DefineNewType(const std::string &type_name, const UserType &type) {
    if (types_.find(type_name) != types_.cend())
      return false;
    types_[type_name] = {type};
    return true;
  }
  auto TypeDefined(const std::string &name) const {
    return types_.find(name) != types_.cend();
  }
  auto GetTypeByName(const std::string &name) const {
    if (TypeDefined(name))
      return std::optional<T>(types_.at(name));
    return std::optional<T>{};
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
