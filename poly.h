#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <stdexcept>
#include <string>
#include <variant>
class Monom {
  int64_t coef_ = 1;
  int64_t pow_ = 1;

public:
  Monom(int64_t coef, int64_t pow) : coef_{coef}, pow_{pow} {}
  Monom() = default;
  Monom &operator=(const Monom &) = default;
  Monom &operator+=(const Monom &rhs) {
    assert(rhs.pow_ == pow_);
    coef_ += rhs.coef_;
    return *this;
  }
  Monom &operator-=(const Monom &rhs) {
    assert(rhs.pow_ == pow_);
    coef_ -= rhs.coef_;
    return *this;
  }
  inline int64_t get_pow() const { return pow_; };
  std::string repr(const char var) const {
    if (coef_ == 0)
      return {};
    if (pow_ == 0)
      return (coef_ > 0 ? "+" : "") + std::to_string(coef_);
    std::string display_coef{};
    if (coef_ == -1) {
      display_coef += '-';
    } else if (coef_ > 0) {
      { display_coef += '+'; }
    }

    display_coef += std::abs(coef_) == 1 ? "" : std::to_string(coef_);
    auto display_pow = pow_ == 1 ? "" : "^" + std::to_string(pow_);
    return display_coef + var + display_pow;
  }
  inline int64_t coef() const { return coef_; }
  friend Monom operator+(Monom lhs, const Monom &rhs) {
    lhs += rhs;
    return lhs;
  }
  friend Monom operator-(Monom lhs, const Monom &rhs) {
    lhs -= rhs;
    return lhs;
  }
  friend Monom operator*(Monom lhs, const Monom &rhs) {
    return {lhs.coef_ * rhs.coef_, lhs.pow_ + rhs.pow_};
  }
  friend Monom operator/(Monom lhs, const Monom &rhs) {
    return {lhs.coef_ / rhs.coef_, lhs.pow_ - rhs.pow_};
  }
  Monom &operator^=(const int64_t power) {
    pow_ *= power;
    return *this;
  }
  friend Monom operator^(Monom lhs, const int64_t rhs) {
    lhs ^= rhs;
    return lhs;
  }
  Monom operator-() const { return {-coef_, pow_}; }
  friend std::ostream &operator<<(std::ostream &stream, const Monom &mono) {
    stream << mono.repr('x');
    return stream;
  }
};
class Polynomial {
  std::list<Monom> terms_;
  char variable_ = '\0';

public:
  inline auto GetBase() const { return variable_; }
  inline auto SetBase(const char base) { variable_ = base; }
  inline int64_t degree() const {
    return terms_.empty() ? 0 : terms_.front().get_pow();
  }
  inline Monom lead() const { return terms_.front(); }
  inline auto begin() const { return terms_.begin(); }
  inline auto end() const { return terms_.end(); }
  inline void remove_zero() {
    terms_.remove_if([](auto &&term) { return term.coef() == 0; });
  }
  Polynomial &operator+=(const Monom &rhs) {
    auto same_power =
        std::find_if(terms_.begin(), terms_.end(), [rhs](auto &&term) {
          return term.get_pow() == rhs.get_pow();
        });
    if (same_power != terms_.cend()) {
      *same_power += rhs;
    } else {
      auto first_less = std::lower_bound(
          terms_.begin(), terms_.end(), rhs,
          [](auto &&lhs, auto &&rhs) { return lhs.get_pow() > rhs.get_pow(); });
      terms_.insert(first_less, rhs);
    }
    remove_zero();
    return *this;
  }
  friend Polynomial operator+(Polynomial lhs, const Monom &rhs) {
    lhs += rhs;
    return lhs;
  }
  Polynomial &operator-=(const Monom &rhs) {
    auto same_power =
        std::find_if(terms_.begin(), terms_.end(), [rhs](auto &&term) {
          return term.get_pow() == rhs.get_pow();
        });
    if (same_power != terms_.cend()) {
      *same_power -= rhs;
    } else {
      auto first_less = std::lower_bound(
          terms_.begin(), terms_.end(), rhs,
          [](auto &&lhs, auto &&rhs) { return lhs.get_pow() > rhs.get_pow(); });
      terms_.insert(first_less, -rhs);
    }
    remove_zero();

    return *this;
  }
  friend Polynomial operator-(Polynomial lhs, const Monom &rhs) {
    lhs -= rhs;
    return lhs;
  }
  Polynomial &operator-=(const Polynomial &rhs) {
    for (auto &&term : rhs) {
      *this -= term;
    }
    remove_zero();

    return *this;
  }
  friend Polynomial operator-(Polynomial lhs, const Polynomial &rhs) {
    lhs -= rhs;
    return lhs;
  }

  Polynomial &operator+=(const Polynomial &rhs) {
    for (auto &&term : rhs) {
      *this += term;
    }
    remove_zero();
    return *this;
  }
  friend Polynomial operator+(Polynomial lhs, const Polynomial &rhs) {
    lhs += rhs;
    return lhs;
  }
  Polynomial &operator*=(const Monom &rhs) {
    std::transform(terms_.begin(), terms_.end(), terms_.begin(),
                   [rhs](auto &&term) { return term * rhs; });
    remove_zero();

    return *this;
  }
  friend Polynomial operator*(Polynomial lhs, const Monom &rhs) {
    lhs *= rhs;
    return lhs;
  }
  Polynomial &operator/=(const Monom &rhs) {
    std::transform(terms_.begin(), terms_.end(), terms_.begin(),
                   [rhs](auto &&term) { return term / rhs; });
    remove_zero();

    return *this;
  }
  friend Polynomial operator/(Polynomial lhs, const Monom &rhs) {
    lhs /= rhs;
    return lhs;
  }

  Polynomial &operator/=(const Polynomial &rhs) {
    auto quot = Polynomial{};
    if (rhs.degree() == 0) {
      *this /= rhs.lead();
      return *this;
    }
    while (this->degree() >= rhs.degree()) {
      auto t = this->lead() / rhs.lead();
      quot += t;
      *this -= rhs * t;
      remove_zero();
    }
    *this = quot;
    remove_zero();
    return *this;
  }
  friend Polynomial operator/(Polynomial lhs, const Polynomial &rhs) {
    lhs /= rhs;
    return lhs;
  }
  Polynomial &operator*=(const Polynomial &rhs) {
    auto copy = *this;
    terms_.clear();
    for (auto &&term : rhs) {
      *this += copy * term;
    }
    remove_zero();

    return *this;
  }
  friend Polynomial operator*(Polynomial lhs, const Polynomial &rhs) {
    lhs *= rhs;
    return lhs;
  }
  std::string to_string() const {
    std::string res{};
    for (auto &&term : terms_) {
      res += term.repr(variable_);
    }
    return res.substr(res[0] == '+');
  }
  friend std::ostream &operator<<(std::ostream &output,
                                  const Polynomial &poly) {
    const auto view = poly.to_string();
    output << (!view.empty() ? view : "0");
    return output;
  }
  Polynomial &operator^=(const int64_t pow) {
    const auto copy = *this;
    if (pow == 0) {
      *this = Monom{1, 0};
    }
    for (auto i = 0u; i < pow - 1; ++i)
      *this *= copy;
    return *this;
  }
  friend Polynomial operator^(Polynomial lhs, const int64_t rhs) {
    lhs ^= rhs;
    return lhs;
  }
  Polynomial operator-() const { return *this * Monom{-1, 0}; };
  Polynomial(){};
  Polynomial(Polynomial &&) = default;
  Polynomial(const Polynomial &) = default;
  Polynomial &operator=(const Polynomial &) = default;
  Polynomial &operator=(Polynomial &&) = default;
  Polynomial(const Monom &monom) { *this += monom; }
  Polynomial(int64_t coef, int64_t pow, const char variable)
      : Polynomial{Monom{coef, pow}} {
    variable_ = variable;
  }
};
inline int64_t ipow64(const int64_t base, const int64_t power) {
  int64_t rv = 1;
  for (int64_t i = 0; i < power; ++i)
    rv *= base;
  return rv;
}
class SymbolTable {
  std::map<std::string, Polynomial> symbols_;
  inline static SymbolTable *inst_ = nullptr;
  SymbolTable() = default;

public:
  static auto GetInst() {
    if (inst_ == nullptr)
      inst_ = new SymbolTable();
    return inst_;
  }
  Polynomial &GetVar(const std::string &var_name) { return symbols_[var_name]; }
  const std::optional<Polynomial> ReadVar(const std::string &var_name) const {
    if (symbols_.find(var_name) != symbols_.cend())
      return symbols_.at(var_name);
    return {};
  }
};
