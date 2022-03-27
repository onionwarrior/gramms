// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 3 "calc.y"

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


#line 276 "calc.tab.cc"


#include "calc.tab.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 354 "calc.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      default:
        break;
    }

  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3: // Polynomial: Polynomial PLUS Polynomial
#line 252 "calc.y"
                                { yylhs.value=yystack_[2].value+yystack_[0].value; }
#line 828 "calc.tab.cc"
    break;

  case 4: // Polynomial: Polynomial MINUS Polynomial
#line 254 "calc.y"
                                        { yylhs.value=yystack_[2].value-yystack_[0].value; }
#line 834 "calc.tab.cc"
    break;

  case 5: // Polynomial: Polynomial MUL Polynomial
#line 256 "calc.y"
                                { yylhs.value = yystack_[2].value*yystack_[0].value; }
#line 840 "calc.tab.cc"
    break;

  case 6: // Polynomial: '-' Polynomial
#line 258 "calc.y"
                                { yylhs.value = -yystack_[0].value; }
#line 846 "calc.tab.cc"
    break;

  case 7: // Polynomial: LEFT Polynomial RIGHT
#line 260 "calc.y"
                                { yylhs.value = yystack_[1].value; }
#line 852 "calc.tab.cc"
    break;

  case 8: // Polynomial: Polynomial DIV Polynomial
#line 262 "calc.y"
                                { yylhs.value = yystack_[2].value/yystack_[1].value;}
#line 858 "calc.tab.cc"
    break;

  case 9: // Polynomial: Polynomial POW INTEGER
#line 264 "calc.y"
                          { yylhs.value=yystack_[2].value^yystack_[0].value;}
#line 864 "calc.tab.cc"
    break;


#line 868 "calc.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -8;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -7,    -7,    -7,    10,    15,     5,    -8,    -7,    -7,    -7,
      -7,     0,    -8,     5,     5,    -4,    -4,    -8
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     2,     2,     0,     0,     6,     1,     2,     2,     2,
       2,     0,     7,     3,     4,     5,     8,     9
  };

  const signed char
  parser::yypgoto_[] =
  {
      -8,    -1
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3
  };

  const signed char
  parser::yytable_[] =
  {
       4,     5,     1,    17,    11,     2,    13,    14,    15,    16,
       6,     9,    10,    11,     7,     8,     9,    10,    11,     7,
       8,     9,    10,    11,     0,    12
  };

  const signed char
  parser::yycheck_[] =
  {
       1,     2,     9,     3,     8,    12,     7,     8,     9,    10,
       0,     6,     7,     8,     4,     5,     6,     7,     8,     4,
       5,     6,     7,     8,    -1,    10
  };

  const signed char
  parser::yystos_[] =
  {
       0,     9,    12,    14,    14,    14,     0,     4,     5,     6,
       7,     8,    10,    14,    14,    14,    14,     3
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    13,    14,    14,    14,    14,    14,    14,    14,    14
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     3,     3,     3,     2,     3,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "PLUS",
  "MINUS", "MUL", "DIV", "POW", "LEFT", "RIGHT", "END", "'-'", "$accept",
  "Polynomial", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   250,   250,   251,   253,   255,   257,   259,   261,   263
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    12,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11
    };
    // Last valid token kind.
    const int code_max = 266;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1219 "calc.tab.cc"

#line 267 "calc.y"

