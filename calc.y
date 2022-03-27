%language "c++"
%require "3.2"
%{
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
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
  std::string repr() const {
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
    return display_coef + 'x' + display_pow;
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
};
class Polynomial {
  std::list<Monom> terms_;

public:
  inline int64_t degree() const { return terms_.front().get_pow(); }
  inline Monom lead() const { return terms_.front(); }
  inline auto begin() const { return terms_.begin(); }
  inline auto end() const { return terms_.end(); }
  inline void remove_zero() {
    std::remove_if(terms_.begin(), terms_.end(),
                   [](auto &&term) { return term.coef() == 0; });
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
    auto rem = *this;
    while (rem.degree() >= rhs.degree()) {
      auto t = rem.lead() / rhs.lead();
      quot += t;
      rem -= rhs * t;
    }
    *this = quot + rem;
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
      res += term.repr();
    }
    return res.substr(1);
  }
  Polynomial & operator^=(const int64_t pow)
  {
    const auto copy = *this;
    if(pow==0)
    {
      *this=Monom{1,0};
    }
    for(auto i =0u;i<pow-1;++i)
      *this*=copy;
    return *this;
  }
  friend Polynomial operator^(Polynomial lhs,const int64_t rhs)
  {
    lhs^=rhs;
    return lhs;
  }
  Polynomial operator-() const {return *this*Monom{-1,0};};
  Polynomial() {};
  Polynomial(Polynomial&&)=default;
  Polynomial(const Polynomial&)=default;
  Polynomial& operator=(const Polynomial&)=default;
  Polynomial&operator=(Polynomial&&)=default;
  Polynomial (const Monom & monom)
  {
    *this+=monom;
  }
};

%}

%define api.value.type variant
%token INTEGER
%token PLUS MINUS MUL DIV POW
%token LEFT RIGHT
%token END

%left PLUS MINUS
%left MUL DIV
%right POW

%%

Polynomial:
			| Polynomial PLUS Polynomial
				{ $$=$1+$3; }
			| Polynomial MINUS Polynomial
					{ $$=$1-$3; }
			| Polynomial MUL Polynomial
				{ $$ = $1*$3; }
			| '-' Polynomial %prec MINUS
				{ $$ = -$2; }
			| LEFT Polynomial RIGHT
				{ $$ = $2; }
			| Polynomial DIV Polynomial
				{ $$ = $1/$2;}
			| Polynomial POW INTEGER
			  { $$=$1^$3;}


%%
