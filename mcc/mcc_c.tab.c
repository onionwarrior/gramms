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





#include "mcc_c.tab.h"


// Unqualified %code blocks.
#line 133 "mcc_c.y"

# include "driver.h"

#line 50 "mcc_c.tab.c"


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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
#line 142 "mcc_c.tab.c"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



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
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_pointer: // pointer
        value.YY_MOVE_OR_COPY< mcc::PtrBits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.YY_MOVE_OR_COPY< mcc::Symbol > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.YY_MOVE_OR_COPY< mcc::type_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.YY_MOVE_OR_COPY< std::pair<mcc::type_t,mcc::PtrBits> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.YY_MOVE_OR_COPY< std::vector<mcc::Symbol> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_pointer: // pointer
        value.move< mcc::PtrBits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.move< mcc::Symbol > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.move< mcc::type_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.move< std::pair<mcc::type_t,mcc::PtrBits> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<mcc::Symbol> > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_pointer: // pointer
        value.copy< mcc::PtrBits > (that.value);
        break;

      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.copy< mcc::Symbol > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< mcc::type_t > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.copy< std::pair<mcc::type_t,mcc::PtrBits> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.copy< std::vector<mcc::Symbol> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_pointer: // pointer
        value.move< mcc::PtrBits > (that.value);
        break;

      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.move< mcc::Symbol > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.move< mcc::type_t > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.move< std::pair<mcc::type_t,mcc::PtrBits> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<mcc::Symbol> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
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
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
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

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

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
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      case symbol_kind::S_pointer: // pointer
        yylhs.value.emplace< mcc::PtrBits > ();
        break;

      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_init_declarator: // init_declarator
        yylhs.value.emplace< mcc::Symbol > ();
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        yylhs.value.emplace< mcc::type_t > ();
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        yylhs.value.emplace< std::pair<mcc::type_t,mcc::PtrBits> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        yylhs.value.emplace< std::vector<mcc::Symbol> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // primary_expression: "identifier"
#line 141 "mcc_c.y"
        {
		const auto sym = drv.GetSymbol(drv.GetCurrentScope()+yystack_[0].value.as < std::string > ());
		if(sym)
		{
			yylhs.value.as < mcc::Symbol > ()=sym.value();
		}
		else
		{
			const auto global_lookup = drv.GetSymbol("@::"+yystack_[0].value.as < std::string > ());
			if(global_lookup)
			{
				yylhs.value.as < mcc::Symbol > ()=global_lookup.value();
			}
			else
			{
				yylhs.value.as < mcc::Symbol > ()={};
			}
		}
	}
#line 820 "mcc_c.tab.c"
    break;

  case 3: // primary_expression: "constant"
#line 161 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 828 "mcc_c.tab.c"
    break;

  case 4: // primary_expression: "literal"
#line 165 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 836 "mcc_c.tab.c"
    break;

  case 5: // primary_expression: "(" expression ")"
#line 169 "mcc_c.y"
        {
	yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ();
	}
#line 844 "mcc_c.tab.c"
    break;

  case 6: // postfix_expression: primary_expression
#line 175 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[0].value.as < mcc::Symbol > (); }
#line 850 "mcc_c.tab.c"
    break;

  case 7: // postfix_expression: postfix_expression "[" expression "]"
#line 177 "mcc_c.y"
        {
		const auto is_sub_int = mcc::IsIntegerT(yystack_[1].value.as < mcc::Symbol > ().GetType());
		const auto ind = yystack_[1].value.as < mcc::Symbol > ().GetType().index();
		if( yystack_[3].value.as < mcc::Symbol > ().IsPtr())
		{
			if(!is_sub_int || yystack_[1].value.as < mcc::Symbol > ().IsPtr())
			{
				mcc::PrintColored("Array subscript can't be non integer",mcc::TextColor::Error);
			}
		}
		else
		{
			mcc::PrintColored("Cannot apply subscript operator to a non pointer value",mcc::TextColor::Error);
		}
	}
#line 870 "mcc_c.tab.c"
    break;

  case 8: // postfix_expression: postfix_expression "(" ")"
#line 193 "mcc_c.y"
        {mcc::PrintColored("Function call with no args",mcc::TextColor::Good);}
#line 876 "mcc_c.tab.c"
    break;

  case 9: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 195 "mcc_c.y"
        {mcc::PrintColored("Function call with args",mcc::TextColor::Good);}
#line 882 "mcc_c.tab.c"
    break;

  case 10: // postfix_expression: postfix_expression "." "identifier"
#line 197 "mcc_c.y"
        {mcc::PrintColored("Non ptr struct or union field access",mcc::TextColor::Good);}
#line 888 "mcc_c.tab.c"
    break;

  case 11: // postfix_expression: postfix_expression "->" "identifier"
#line 199 "mcc_c.y"
        {mcc::PrintColored("Ptr struct or union field access",mcc::TextColor::Good);}
#line 894 "mcc_c.tab.c"
    break;

  case 12: // postfix_expression: postfix_expression "++"
#line 201 "mcc_c.y"
        {mcc::PrintColored("Postfix increment",mcc::TextColor::Good);}
#line 900 "mcc_c.tab.c"
    break;

  case 13: // postfix_expression: postfix_expression "--"
#line 203 "mcc_c.y"
        {mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);}
#line 906 "mcc_c.tab.c"
    break;

  case 16: // unary_expression: postfix_expression
#line 213 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 912 "mcc_c.tab.c"
    break;

  case 17: // unary_expression: "++" unary_expression
#line 215 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 918 "mcc_c.tab.c"
    break;

  case 18: // unary_expression: "--" unary_expression
#line 217 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 924 "mcc_c.tab.c"
    break;

  case 19: // unary_expression: unary_operator cast_expression
#line 219 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 930 "mcc_c.tab.c"
    break;

  case 20: // unary_expression: "sizeof" unary_expression
#line 221 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol(mcc::Primitive::ULongLong,0,true,true,false);}
#line 936 "mcc_c.tab.c"
    break;

  case 21: // unary_expression: "sizeof" "(" type_name ")"
#line 223 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol(mcc::Primitive::ULongLong,0,true,true,false);}
#line 942 "mcc_c.tab.c"
    break;

  case 28: // cast_expression: unary_expression
#line 238 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 948 "mcc_c.tab.c"
    break;

  case 29: // cast_expression: "(" type_name ")" cast_expression
#line 240 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol{yystack_[2].value.as < std::pair<mcc::type_t,mcc::PtrBits> > ().first,yystack_[2].value.as < std::pair<mcc::type_t,mcc::PtrBits> > ().second.GetIndirection(),true,true,false};}
#line 954 "mcc_c.tab.c"
    break;

  case 30: // multiplicative_expression: cast_expression
#line 245 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 960 "mcc_c.tab.c"
    break;

  case 31: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 246 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 966 "mcc_c.tab.c"
    break;

  case 32: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 247 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 972 "mcc_c.tab.c"
    break;

  case 33: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 248 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 978 "mcc_c.tab.c"
    break;

  case 34: // additive_expression: multiplicative_expression
#line 253 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 984 "mcc_c.tab.c"
    break;

  case 35: // additive_expression: additive_expression "+" multiplicative_expression
#line 255 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 990 "mcc_c.tab.c"
    break;

  case 36: // additive_expression: additive_expression "-" multiplicative_expression
#line 256 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 996 "mcc_c.tab.c"
    break;

  case 37: // shift_expression: additive_expression
#line 261 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1002 "mcc_c.tab.c"
    break;

  case 38: // shift_expression: shift_expression "<<" additive_expression
#line 263 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1008 "mcc_c.tab.c"
    break;

  case 39: // shift_expression: shift_expression ">>" additive_expression
#line 264 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1014 "mcc_c.tab.c"
    break;

  case 40: // relational_expression: shift_expression
#line 269 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1020 "mcc_c.tab.c"
    break;

  case 41: // relational_expression: relational_expression "<=" shift_expression
#line 271 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1026 "mcc_c.tab.c"
    break;

  case 42: // relational_expression: relational_expression ">=" shift_expression
#line 272 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1032 "mcc_c.tab.c"
    break;

  case 43: // relational_expression: relational_expression "<" shift_expression
#line 273 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1038 "mcc_c.tab.c"
    break;

  case 44: // relational_expression: relational_expression ">" shift_expression
#line 274 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1044 "mcc_c.tab.c"
    break;

  case 45: // equality_expression: relational_expression
#line 279 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1050 "mcc_c.tab.c"
    break;

  case 46: // equality_expression: equality_expression "==" relational_expression
#line 281 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1056 "mcc_c.tab.c"
    break;

  case 47: // equality_expression: equality_expression "!=" relational_expression
#line 282 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1062 "mcc_c.tab.c"
    break;

  case 48: // and_expression: equality_expression
#line 287 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1068 "mcc_c.tab.c"
    break;

  case 49: // and_expression: and_expression "&" equality_expression
#line 289 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1074 "mcc_c.tab.c"
    break;

  case 50: // exclusive_or_expression: and_expression
#line 294 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1080 "mcc_c.tab.c"
    break;

  case 51: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 296 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1086 "mcc_c.tab.c"
    break;

  case 52: // inclusive_or_expression: exclusive_or_expression
#line 301 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1092 "mcc_c.tab.c"
    break;

  case 53: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 303 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1098 "mcc_c.tab.c"
    break;

  case 54: // logical_and_expression: inclusive_or_expression
#line 308 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1104 "mcc_c.tab.c"
    break;

  case 55: // logical_and_expression: logical_and_expression "||" inclusive_or_expression
#line 310 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1110 "mcc_c.tab.c"
    break;

  case 56: // logical_or_expression: logical_and_expression
#line 315 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1116 "mcc_c.tab.c"
    break;

  case 57: // logical_or_expression: logical_or_expression "&&" logical_and_expression
#line 317 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1122 "mcc_c.tab.c"
    break;

  case 58: // conditional_expression: logical_or_expression
#line 322 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1128 "mcc_c.tab.c"
    break;

  case 59: // $@1: %empty
#line 323 "mcc_c.y"
                                {
		const auto is_primitive = std::holds_alternative<mcc::Primitive>(yystack_[0].value.as < mcc::Symbol > ().GetType());
		const auto is_ptr = yystack_[0].value.as < mcc::Symbol > ().IsPtr();
		if(!is_primitive && !is_ptr)
		{
			mcc::PrintColored("Could not evaluate as pointer or arithmetic type",mcc::TextColor::Error);
		}
		else if(std::get<mcc::Primitive>(yystack_[0].value.as < mcc::Symbol > ().GetType())==mcc::Primitive::Void)
		{
			mcc::PrintColored("Void where pointer or arithmetic type is required",mcc::TextColor::Error);
		}
	}
#line 1145 "mcc_c.tab.c"
    break;

  case 60: // conditional_expression: logical_or_expression $@1 "?" expression ":" conditional_expression
#line 323 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[5].value.as < mcc::Symbol > (); }
#line 1151 "mcc_c.tab.c"
    break;

  case 61: // assignment_expression: conditional_expression
#line 340 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1157 "mcc_c.tab.c"
    break;

  case 62: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 341 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1163 "mcc_c.tab.c"
    break;

  case 74: // expression: assignment_expression
#line 360 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol(yystack_[0].value.as < mcc::Symbol > ().GetType(),yystack_[0].value.as < mcc::Symbol > ().GetIndLevel(),false,true,true);}
#line 1169 "mcc_c.tab.c"
    break;

  case 75: // expression: expression "," assignment_expression
#line 361 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1175 "mcc_c.tab.c"
    break;

  case 76: // constant_expression: conditional_expression
#line 365 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[0].value.as < mcc::Symbol > (); }
#line 1181 "mcc_c.tab.c"
    break;

  case 77: // declaration: declaration_specifiers ";"
#line 370 "mcc_c.y"
        {mcc::PrintColored("declaration does not declare anything",mcc::TextColor::Warning);}
#line 1187 "mcc_c.tab.c"
    break;

  case 78: // declaration: declaration_specifiers init_declarator_list ";"
#line 372 "mcc_c.y"
        {
		const auto t = yystack_[2].value.as < mcc::type_t > ();
		drv.UnsetCurrentType();
	}
#line 1196 "mcc_c.tab.c"
    break;

  case 79: // declaration_specifiers: storage_class_specifier
#line 380 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Int;drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 1202 "mcc_c.tab.c"
    break;

  case 80: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 382 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=yystack_[0].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 1208 "mcc_c.tab.c"
    break;

  case 81: // declaration_specifiers: type_specifier
#line 384 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=yystack_[0].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 1214 "mcc_c.tab.c"
    break;

  case 82: // declaration_specifiers: type_specifier declaration_specifiers
#line 386 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=yystack_[1].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 1220 "mcc_c.tab.c"
    break;

  case 83: // declaration_specifiers: type_qualifier
#line 388 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Int;drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 1226 "mcc_c.tab.c"
    break;

  case 84: // declaration_specifiers: type_qualifier declaration_specifiers
#line 390 "mcc_c.y"
        { yylhs.value.as < mcc::type_t > ()=yystack_[0].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 1232 "mcc_c.tab.c"
    break;

  case 86: // init_declarator_list: init_declarator_list "," init_declarator
#line 395 "mcc_c.y"
          { yylhs.value.as < std::vector<mcc::Symbol> > () = yystack_[2].value.as < std::vector<mcc::Symbol> > (); }
#line 1238 "mcc_c.tab.c"
    break;

  case 87: // init_declarator: declarator
#line 400 "mcc_c.y"
        {
		auto sym = mcc::Symbol{drv.GetCurrentType(),0,false,true,true};
		drv.AddSymbol(yystack_[0].value.as < std::string > (),std::move(sym));
	}
#line 1247 "mcc_c.tab.c"
    break;

  case 88: // init_declarator: declarator "=" initializer
#line 405 "mcc_c.y"
        {
		auto sym=mcc::Symbol{drv.GetCurrentType(),0,false,true,true};
		drv.AddSymbol(yystack_[2].value.as < std::string > (),std::move(sym));
	}
#line 1256 "mcc_c.tab.c"
    break;

  case 94: // type_specifier: "void"
#line 420 "mcc_c.y"
                {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Void;}
#line 1262 "mcc_c.tab.c"
    break;

  case 95: // type_specifier: "char"
#line 421 "mcc_c.y"
                {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Char;}
#line 1268 "mcc_c.tab.c"
    break;

  case 96: // type_specifier: "short"
#line 422 "mcc_c.y"
                 {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Short;}
#line 1274 "mcc_c.tab.c"
    break;

  case 97: // type_specifier: "int"
#line 423 "mcc_c.y"
               {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Int;}
#line 1280 "mcc_c.tab.c"
    break;

  case 98: // type_specifier: "long"
#line 424 "mcc_c.y"
                {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Long;}
#line 1286 "mcc_c.tab.c"
    break;

  case 99: // type_specifier: "float"
#line 425 "mcc_c.y"
                 {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Float;}
#line 1292 "mcc_c.tab.c"
    break;

  case 100: // type_specifier: "double"
#line 426 "mcc_c.y"
                  {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Double;}
#line 1298 "mcc_c.tab.c"
    break;

  case 101: // type_specifier: "signed"
#line 428 "mcc_c.y"
        {}
#line 1304 "mcc_c.tab.c"
    break;

  case 102: // type_specifier: "unsigned"
#line 429 "mcc_c.y"
                    {}
#line 1310 "mcc_c.tab.c"
    break;

  case 103: // type_specifier: struct_or_union_specifier
#line 430 "mcc_c.y"
                                   {}
#line 1316 "mcc_c.tab.c"
    break;

  case 104: // type_specifier: enum_specifier
#line 431 "mcc_c.y"
                        {}
#line 1322 "mcc_c.tab.c"
    break;

  case 105: // type_specifier: "typename"
#line 433 "mcc_c.y"
                {
			yylhs.value.as < mcc::type_t > () = drv.GetType(yystack_[0].value.as < std::string > ()).value();
		}
#line 1330 "mcc_c.tab.c"
    break;

  case 114: // specifier_qualifier_list: type_specifier specifier_qualifier_list
#line 458 "mcc_c.y"
        {yylhs.value.as < std::pair<mcc::type_t,mcc::PtrBits> > ()=yystack_[1].value.as < mcc::type_t > ();}
#line 1336 "mcc_c.tab.c"
    break;

  case 115: // specifier_qualifier_list: type_specifier
#line 460 "mcc_c.y"
        {yylhs.value.as < std::pair<mcc::type_t,mcc::PtrBits> > ()=yystack_[0].value.as < mcc::type_t > ();}
#line 1342 "mcc_c.tab.c"
    break;

  case 116: // specifier_qualifier_list: type_qualifier specifier_qualifier_list
#line 462 "mcc_c.y"
        {yylhs.value.as < std::pair<mcc::type_t,mcc::PtrBits> > ()=yystack_[0].value.as < std::pair<mcc::type_t,mcc::PtrBits> > ();}
#line 1348 "mcc_c.tab.c"
    break;

  case 117: // specifier_qualifier_list: type_qualifier
#line 464 "mcc_c.y"
        {yylhs.value.as < std::pair<mcc::type_t,mcc::PtrBits> > ()={};}
#line 1354 "mcc_c.tab.c"
    break;

  case 130: // type_qualifier: "const"
#line 495 "mcc_c.y"
                 {yylhs.value.as < std::string > ()="const";}
#line 1360 "mcc_c.tab.c"
    break;

  case 131: // type_qualifier: "volatile"
#line 496 "mcc_c.y"
                    {yylhs.value.as < std::string > ()="";}
#line 1366 "mcc_c.tab.c"
    break;

  case 132: // declarator: pointer direct_declarator
#line 501 "mcc_c.y"
        {
		yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
	}
#line 1374 "mcc_c.tab.c"
    break;

  case 133: // declarator: direct_declarator
#line 505 "mcc_c.y"
        {
		yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
	}
#line 1382 "mcc_c.tab.c"
    break;

  case 134: // direct_declarator: "identifier"
#line 512 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 1388 "mcc_c.tab.c"
    break;

  case 135: // direct_declarator: "(" declarator ")"
#line 514 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ();}
#line 1394 "mcc_c.tab.c"
    break;

  case 136: // direct_declarator: direct_declarator "[" constant_expression "]"
#line 516 "mcc_c.y"
        {
		mcc::PrintColored("Array def:",mcc::TextColor::Good);
		drv.AddSymbol(yystack_[3].value.as < std::string > (),mcc::Symbol{drv.GetCurrentType(),1,true,true,true});
	}
#line 1403 "mcc_c.tab.c"
    break;

  case 137: // direct_declarator: direct_declarator "[" "]"
#line 521 "mcc_c.y"
        {
		mcc::PrintColored("Array def VLA:",mcc::TextColor::Good);
		drv.AddSymbol(yystack_[2].value.as < std::string > (),mcc::Symbol{drv.GetCurrentType(),1,true,true,true});
	}
#line 1412 "mcc_c.tab.c"
    break;

  case 138: // direct_declarator: direct_declarator "(" parameter_type_list ")"
#line 526 "mcc_c.y"
        { mcc::PrintColored("Function ptr only type proto",mcc::TextColor::Good);}
#line 1418 "mcc_c.tab.c"
    break;

  case 139: // direct_declarator: direct_declarator "(" identifier_list ")"
#line 528 "mcc_c.y"
        {
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
	}
#line 1426 "mcc_c.tab.c"
    break;

  case 140: // direct_declarator: direct_declarator "(" ")"
#line 531 "mcc_c.y"
          { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > (); }
#line 1432 "mcc_c.tab.c"
    break;

  case 141: // pointer: "*"
#line 536 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1441 "mcc_c.tab.c"
    break;

  case 142: // pointer: "*" type_qualifier_list
#line 541 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[0].value.as < std::string > ()=="const");
	}
#line 1450 "mcc_c.tab.c"
    break;

  case 143: // pointer: "*" pointer
#line 546 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1459 "mcc_c.tab.c"
    break;

  case 144: // pointer: "*" type_qualifier_list pointer
#line 551 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[1].value.as < std::string > ()=="const");
	}
#line 1468 "mcc_c.tab.c"
    break;

  case 145: // type_qualifier_list: type_qualifier
#line 560 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 1474 "mcc_c.tab.c"
    break;

  case 146: // type_qualifier_list: type_qualifier_list type_qualifier
#line 562 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ()+yystack_[0].value.as < std::string > ();}
#line 1480 "mcc_c.tab.c"
    break;

  case 156: // type_name: specifier_qualifier_list
#line 588 "mcc_c.y"
          { yylhs.value.as < std::pair<mcc::type_t,mcc::PtrBits> > () = yystack_[0].value.as < std::pair<mcc::type_t,mcc::PtrBits> > (); }
#line 1486 "mcc_c.tab.c"
    break;

  case 157: // type_name: specifier_qualifier_list abstract_declarator
#line 589 "mcc_c.y"
          { yylhs.value.as < std::pair<mcc::type_t,mcc::PtrBits> > () = yystack_[1].value.as < std::pair<mcc::type_t,mcc::PtrBits> > (); }
#line 1492 "mcc_c.tab.c"
    break;

  case 176: // $@2: %empty
#line 623 "mcc_c.y"
          {drv.EnterNewScope("");}
#line 1498 "mcc_c.tab.c"
    break;

  case 177: // statement: $@2 compound_statement
#line 625 "mcc_c.y"
                {drv.LeaveScope();}
#line 1504 "mcc_c.tab.c"
    break;

  case 197: // $@3: %empty
#line 664 "mcc_c.y"
                                 {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1510 "mcc_c.tab.c"
    break;

  case 199: // $@4: %empty
#line 665 "mcc_c.y"
                                                {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1516 "mcc_c.tab.c"
    break;

  case 211: // external_declaration: declaration
#line 687 "mcc_c.y"
        {mcc::PrintColored("New global definition",mcc::TextColor::Good);}
#line 1522 "mcc_c.tab.c"
    break;

  case 212: // $@5: %empty
#line 691 "mcc_c.y"
                                                             {drv.EnterNewScope(yystack_[1].value.as < std::string > ());}
#line 1528 "mcc_c.tab.c"
    break;

  case 213: // function_definition: declaration_specifiers declarator declaration_list $@5 compound_statement
#line 692 "mcc_c.y"
                {drv.LeaveScope();}
#line 1534 "mcc_c.tab.c"
    break;

  case 214: // $@6: %empty
#line 693 "mcc_c.y"
                                            {drv.EnterNewScope(yystack_[0].value.as < std::string > ());}
#line 1540 "mcc_c.tab.c"
    break;

  case 215: // function_definition: declaration_specifiers declarator $@6 compound_statement
#line 694 "mcc_c.y"
                {drv.LeaveScope();}
#line 1546 "mcc_c.tab.c"
    break;

  case 216: // $@7: %empty
#line 695 "mcc_c.y"
                                      {drv.EnterNewScope(yystack_[1].value.as < std::string > ());}
#line 1552 "mcc_c.tab.c"
    break;

  case 217: // function_definition: declarator declaration_list $@7 compound_statement
#line 696 "mcc_c.y"
                {drv.LeaveScope();}
#line 1558 "mcc_c.tab.c"
    break;

  case 218: // $@8: %empty
#line 697 "mcc_c.y"
                     {drv.EnterNewScope(yystack_[0].value.as < std::string > ());}
#line 1564 "mcc_c.tab.c"
    break;

  case 219: // function_definition: declarator $@8 compound_statement
#line 698 "mcc_c.y"
                {drv.LeaveScope();}
#line 1570 "mcc_c.tab.c"
    break;


#line 1574 "mcc_c.tab.c"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
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

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
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
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "identifier", "constant",
  "literal", "sizeof", "typedef", "extern", "static", "auto", "register",
  "char", "short", "long", "signed", "unsigned", "float", "double",
  "const", "volatile", "void", "case", "default", "if", "int", "else",
  "switch", "while", "do", "for", "goto", "continue", "break", "return",
  "struct", "union", "enum", "/=", "%=", "*=", "-=", "+=", "<<=", ">>=",
  "&=", "^=", "|=", "typename", "\n", "+", "-", "*", "/", "^", "<<", ">>",
  "|", "&", "%", "=", "!", "~", "(", ")", "->", "{", "}", "[", "]", "...",
  "++", "--", "==", ">=", "<=", "!=", ";", ".", ",", ":", "<", ">", "&&",
  "||", "?", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "$@1", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "$@2", "labeled_statement",
  "compound_statement", "statement_list", "declaration_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "$@3", "$@4", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "$@5", "$@6", "$@7",
  "$@8", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -228;

  const short parser::yytable_ninf_ = -215;

  const short
  parser::yypact_[] =
  {
    1148,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
      18,  -228,    21,    45,  -228,    13,  1371,  1371,  -228,    19,
    -228,  1371,  1371,    47,    39,   945,  -228,  -228,   -42,    50,
    -228,  -228,    21,    -6,  -228,     1,  -228,  1205,  -228,  -228,
     -17,  1397,  -228,  -228,    13,  1371,    58,  1106,   616,    47,
    -228,  -228,    50,     9,   -56,  -228,  -228,  -228,  -228,  -228,
      45,   639,  1371,    58,  1397,  1397,  1291,  -228,    11,  1397,
     127,  -228,    58,   320,  -228,  -228,  -228,    35,    99,    87,
    -228,   -45,  -228,  -228,  -228,   779,  -228,  -228,  -228,  -228,
    -228,  -228,   575,  -228,   794,   794,  -228,    57,  -228,   817,
    -228,     3,   -18,   115,   165,   -19,   132,   144,   162,   125,
      51,  -228,   160,    54,   817,  -228,    50,  -228,   639,  1408,
    -228,  -228,  -228,    58,  -228,  1328,  -228,  -228,  -228,   817,
     109,  -228,   154,  -228,  -228,   163,   817,   171,   182,   194,
     199,   470,   200,   261,   188,   190,   232,  -228,  -228,  -228,
     122,  -228,  -228,    58,  -228,   395,  -228,  -228,  -228,  -228,
     883,   677,  -228,     7,  -228,   126,  -228,  1002,  -228,   265,
     575,  -228,   -36,    55,   205,   817,  -228,  -228,   703,   267,
     817,  -228,  -228,   268,  -228,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   187,  -228,  -228,  -228,  -228,  -228,    94,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,   817,  -228,  -228,  -228,  -228,    11,   817,   470,   195,
     470,   817,   817,   817,   246,   505,   201,  -228,  -228,  -228,
     145,  -228,   817,  -228,  -228,  -228,  -228,   212,   215,  -228,
     216,   126,  1265,   718,  -228,  -228,  -228,   222,  -228,  1044,
     152,  -228,   817,  -228,    48,  -228,  -228,   106,  -228,  -228,
    -228,  -228,     3,     3,   -18,   -18,   115,   115,   115,   115,
     165,   165,   -19,   132,   144,   162,   125,   817,  -228,   598,
    -228,  -228,  -228,  -228,   470,  -228,    52,    53,   208,   225,
     505,  -228,  -228,  -228,  -228,  -228,  -228,  -228,   227,  -228,
     220,  -228,  -228,  -228,   817,  -228,   148,  -228,  -228,  -228,
     470,   470,   228,   817,   753,  -228,  -228,  -228,   817,   270,
    -228,   470,   208,   470,   103,  -228,   470,  -228,   233,  -228,
     470,  -228,   221,  -228,  -228
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   134,    89,    90,    91,    92,    93,    95,    96,    98,
     101,   102,    99,   100,   130,   131,    94,    97,   109,   110,
       0,   105,   141,     0,   211,     0,    79,    81,   103,     0,
     104,    83,   218,   133,     0,     0,   208,   210,   125,     0,
     145,   143,   142,     0,    77,     0,    85,    87,    80,    82,
     108,     0,    84,   190,     0,   216,     0,     0,     0,   132,
       1,   209,     0,   128,     0,   126,   146,   144,   135,    78,
       0,     0,   212,     0,     0,   115,     0,   111,     0,   117,
      87,   191,     0,   176,   219,   154,   140,   153,     0,   147,
     149,     0,     2,     3,     4,     0,    22,    25,    23,    24,
      27,    26,     0,   137,     0,     0,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      58,    76,     0,     0,     0,   123,     0,    86,     0,    28,
      61,   170,    88,     0,   215,     0,   114,   107,   112,     0,
       0,   118,   120,   116,   217,     2,     0,     0,     0,     0,
       0,   176,     0,     0,     0,     0,     0,   187,   192,    74,
       0,   182,   188,     0,   175,   176,   178,   179,   180,   181,
       0,     0,   151,   158,   152,   159,   138,     0,   139,     0,
       0,    20,     0,   156,     0,     0,    17,    18,     0,     0,
       0,    12,    13,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   124,   129,   127,   173,     0,
      65,    66,    64,    68,    67,    69,    70,    71,    72,    73,
      63,     0,   213,   106,   121,   113,     0,     0,   176,     0,
     176,     0,     0,     0,     0,     0,     0,   204,   205,   206,
       0,   193,     0,   177,   186,   189,   166,     0,     0,   162,
       0,   160,     0,     0,   148,   150,   155,     0,     5,     0,
     158,   157,     0,     8,     0,    14,    11,     0,    10,    31,
      32,    33,    35,    36,    38,    39,    42,    41,    43,    44,
      46,    47,    49,    51,    53,    55,    57,     0,   171,     0,
      62,   119,   122,   183,   176,   185,     0,     0,   197,     0,
       0,   203,   207,    75,   167,   161,   163,   168,     0,   164,
       0,    21,    29,     9,     0,     7,     0,   172,   174,   184,
     176,   176,     0,     0,     0,   169,   165,    15,     0,   194,
     196,   176,   199,   176,     0,    60,   176,   198,     0,   201,
     176,   195,     0,   202,   200
  };

  const short
  parser::yypgoto_[] =
  {
    -228,  -228,  -228,  -228,   -58,  -228,  -103,    33,    41,    56,
      46,    91,    93,    90,    95,    96,  -228,   -57,  -228,   -69,
    -228,   -85,   -60,   178,     4,  -228,   235,  -228,   121,  -228,
    -228,   236,   -26,   -50,  -228,    71,  -228,   249,   186,   142,
     -10,   -14,   -15,  -228,   -54,  -228,   136,  -228,   134,   -79,
    -164,  -123,  -228,  -139,  -228,  -228,   -37,  -228,   269,  -227,
    -228,  -228,  -228,  -228,  -228,  -228,   280,  -228,  -228,  -228,
    -228,  -228
  };

  const short
  parser::yydefgoto_[] =
  {
       0,   106,   107,   274,   129,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   130,   213,   159,
     231,   160,   122,   161,    54,    45,    46,    26,    27,    28,
      29,    76,    77,    78,   140,   141,    30,    64,    65,    31,
      32,    33,    34,    42,   257,    89,    90,    91,   184,   258,
     175,   132,   219,   162,   163,   164,    84,   165,    55,   166,
     167,   168,   332,   348,   169,    35,    36,    37,   133,    73,
      82,    56
  };

  const short
  parser::yytable_[] =
  {
     108,   121,   131,    88,    25,   218,   194,    41,   174,   261,
       1,   125,   244,    43,     1,    47,     1,   182,   310,   178,
      59,    38,    50,   126,    62,   136,   255,    67,   268,   143,
      48,    49,   198,   199,   179,    52,   134,   181,     1,    25,
      14,    15,     1,   252,    80,   144,   186,   187,     1,    74,
     138,   108,   183,    63,   206,   195,   196,   207,    68,   131,
      80,    87,   197,    22,   216,    22,   108,   121,   142,   124,
     170,   250,   173,    22,    23,   171,    23,   172,    69,   234,
      70,   108,   121,   334,    39,    51,   239,    22,   108,   121,
      44,   139,   279,   280,   281,   182,   232,    22,   170,   303,
     182,   305,    23,   171,   271,   277,   261,    22,    23,   138,
      57,   260,   323,   108,   121,    58,   330,   331,   269,   275,
     188,   215,   189,   171,    83,   190,   253,   324,   191,   192,
     183,   252,   252,   126,   212,   193,   -59,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   173,   306,   307,   308,    59,
      43,   298,   300,   176,    40,   329,   177,   350,   270,   322,
     200,   201,    75,   299,    87,   325,   328,   302,    24,   108,
     121,    87,   252,   313,    66,   252,   235,    71,   236,   262,
     208,   339,   340,    79,   263,    75,    75,    75,   209,   251,
      75,   252,   347,   320,   349,   108,   121,   351,   318,   211,
      53,   353,   326,    24,   108,   269,    79,    79,    79,   210,
     171,    79,   312,    75,   252,    53,   142,   252,   338,   214,
     131,   282,   283,    81,   237,    92,    93,    94,    95,   202,
     203,   284,   285,   238,    79,   241,   204,   205,   342,   344,
      81,   240,   290,   291,   270,   337,    75,   242,   286,   287,
     288,   289,   243,   245,   246,   247,    87,   248,   266,   272,
     276,   278,   297,    87,   309,   304,   314,    79,   311,   315,
     108,   345,    96,    97,    98,   316,   321,   252,   333,   336,
      99,   335,   341,   100,   101,   102,   346,   352,   354,   292,
     294,    75,   293,   104,   105,   127,   295,   301,   296,   249,
     135,   123,   217,   265,   267,    61,    72,     0,     0,     0,
       0,     0,    79,   145,    93,    94,    95,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   146,   147,   148,    17,     0,   149,   150,   151,
     152,   153,   154,   155,   156,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      96,    97,    98,     0,     0,     0,     0,     0,    99,     0,
       0,   100,   101,   102,     0,     0,     0,   157,     0,     0,
       0,   104,   105,     0,     0,     0,     0,   158,   145,    93,
      94,    95,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   146,   147,   148,
      17,     0,   149,   150,   151,   152,   153,   154,   155,   156,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    96,    97,    98,     0,     0,
       0,     0,     0,    99,     0,     0,   100,   101,   102,     0,
       0,     0,   254,     0,     0,     0,   104,   105,     0,     0,
       0,     0,   158,   145,    93,    94,    95,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   146,   147,   148,    17,     0,   149,   150,   151,
     152,   153,   154,   155,   156,    18,    19,    20,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    21,     0,
      96,    97,    98,     0,     0,     0,     0,     0,    99,     0,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,   104,   105,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,     0,
       0,     0,     0,    99,     0,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,   104,   105,    92,    93,
      94,    95,   158,     0,     0,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,     0,
      17,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    21,     0,    96,    97,    98,     0,     0,
       0,     0,     0,    99,     0,     0,   100,   101,   102,     0,
       0,     0,    92,    93,    94,    95,   104,   105,    96,    97,
      98,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,   102,     0,     0,   128,   327,    96,    97,    98,   104,
     105,     0,     0,     0,    99,     0,     0,   100,   101,   102,
      92,    93,    94,    95,     0,   103,     0,   104,   105,    96,
      97,    98,     0,     0,     0,     0,     0,    99,     0,     0,
     100,   101,   102,     0,     0,   128,    92,    93,    94,    95,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,     0,    96,    97,    98,
       0,     0,     0,     0,     0,    99,     0,     0,   100,   101,
     102,     0,     0,     0,     0,     0,   259,     0,   104,   105,
       0,     0,     0,    96,    97,    98,    92,    93,    94,    95,
       0,    99,     0,     0,   100,   101,   102,   273,    96,    97,
      98,     0,     0,     0,   104,   105,    99,     0,     0,   100,
     101,   102,    92,    93,    94,    95,     0,   319,     0,   104,
     105,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,     0,    96,    97,    98,     0,     0,     0,     0,
       0,    99,     0,     0,   100,   101,   102,   343,     0,     0,
      92,    93,    94,    95,   104,   105,     0,     0,     0,    96,
      97,    98,     0,     0,     0,     0,     0,    99,     0,     0,
     100,   101,   180,     0,    96,    97,    98,     0,     0,     0,
     104,   105,    99,     0,     0,   100,   101,   185,     0,     0,
       0,     0,     0,     0,     0,   104,   105,    96,    97,    98,
       0,     0,     0,     0,     0,    99,     0,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     1,     0,   104,   105,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,   170,   256,     1,     0,
       0,   171,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,    17,
       0,     0,   264,     0,     0,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,   256,    85,
       0,     0,   171,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,    21,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      86,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,  -214,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    21,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,   317,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,     0,     0,    17,     0,     0,     0,     0,   137,     0,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,   233,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    21,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230
  };

  const short
  parser::yycheck_[] =
  {
      58,    58,    71,    57,     0,   128,   109,    22,    87,   173,
       3,    67,   151,    23,     3,    25,     3,   102,   245,    64,
      34,     3,     3,    79,    66,    75,   165,    42,    64,    79,
      26,    27,    50,    51,    79,    31,    73,    95,     3,    35,
      19,    20,     3,    79,    54,    82,   104,   105,     3,    66,
      76,   109,   102,     3,    73,    52,    53,    76,    64,   128,
      70,    57,    59,    52,   124,    52,   124,   124,    78,    60,
      63,   156,    87,    52,    63,    68,    63,    87,    77,   139,
      79,   139,   139,   310,    66,    66,   146,    52,   146,   146,
      77,    80,   195,   196,   197,   180,   133,    52,    63,   238,
     185,   240,    63,    68,   183,   190,   270,    52,    63,   135,
      63,   171,    64,   171,   171,    68,    64,    64,    63,   188,
      63,    67,    65,    68,    66,    68,   163,    79,    71,    72,
     180,    79,    79,    79,    83,    78,    85,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   170,   241,   242,   243,   173,
     170,    67,   231,    64,    22,   304,    79,    64,   183,   272,
      55,    56,    51,    79,   170,    69,   299,   237,     0,   237,
     237,   177,    79,   252,    42,    79,    77,    60,    79,    63,
      58,   330,   331,    51,    68,    74,    75,    76,    54,    77,
      79,    79,   341,   263,   343,   263,   263,   346,   262,    84,
      32,   350,   297,    35,   272,    63,    74,    75,    76,    57,
      68,    79,    77,   102,    79,    47,   236,    79,    80,    69,
     299,   198,   199,    55,    80,     3,     4,     5,     6,    74,
      75,   200,   201,    80,   102,    63,    81,    82,   333,   334,
      72,    80,   206,   207,   269,   324,   135,    63,   202,   203,
     204,   205,    63,    63,     3,    77,   262,    77,     3,    64,
       3,     3,    85,   269,    28,    80,    64,   135,    77,    64,
     338,   338,    50,    51,    52,    69,    64,    79,    63,    69,
      58,    64,    64,    61,    62,    63,    26,    64,    77,   208,
     210,   180,   209,    71,    72,    70,   211,   236,   212,    77,
      74,    62,   126,   177,   180,    35,    47,    -1,    -1,    -1,
      -1,    -1,   180,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    77,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,    77,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,     3,     4,
       5,     6,    77,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    48,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,
      -1,    -1,     3,     4,     5,     6,    71,    72,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    -1,    -1,    66,    67,    50,    51,    52,    71,
      72,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
       3,     4,     5,     6,    -1,    69,    -1,    71,    72,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    63,    -1,    -1,    66,     3,     4,     5,     6,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    -1,    50,    51,    52,     3,     4,     5,     6,
      -1,    58,    -1,    -1,    61,    62,    63,    64,    50,    51,
      52,    -1,    -1,    -1,    71,    72,    58,    -1,    -1,    61,
      62,    63,     3,     4,     5,     6,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
       3,     4,     5,     6,    71,    72,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    63,    -1,    50,    51,    52,    -1,    -1,    -1,
      71,    72,    58,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,     3,    -1,    71,    72,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    63,    64,     3,    -1,
      -1,    68,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,     3,
      -1,    -1,    68,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    48,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      64,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    48,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    67,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    48,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    25,    35,    36,
      37,    48,    52,    63,   109,   110,   113,   114,   115,   116,
     122,   125,   126,   127,   128,   151,   152,   153,     3,    66,
     125,   128,   129,   126,    77,   111,   112,   126,   110,   110,
       3,    66,   110,   109,   110,   144,   157,    63,    68,   127,
       0,   152,    66,     3,   123,   124,   125,   128,    64,    77,
      79,    60,   144,   155,    66,   114,   117,   118,   119,   125,
     126,   109,   156,    66,   142,     3,    64,   110,   130,   131,
     132,   133,     3,     4,     5,     6,    50,    51,    52,    58,
      61,    62,    63,    69,    71,    72,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   108,   123,    60,    67,    79,   112,    66,    90,
     103,   105,   137,   154,   142,   117,   119,    67,   118,    80,
     120,   121,   126,   119,   142,     3,    22,    23,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    67,    77,   105,
     107,   109,   139,   140,   141,   143,   145,   146,   147,   150,
      63,    68,   126,   128,   135,   136,    64,    79,    64,    79,
      63,    90,   107,   119,   134,    63,    90,    90,    63,    65,
      68,    71,    72,    78,    92,    52,    53,    59,    50,    51,
      55,    56,    74,    75,    81,    82,    73,    76,    58,    54,
      57,    84,    83,   104,    69,    67,   108,   124,   137,   138,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      60,   106,   142,    67,   108,    77,    79,    80,    80,   108,
      80,    63,    63,    63,   139,    63,     3,    77,    77,    77,
     107,    77,    79,   142,    67,   139,    64,   130,   135,    69,
     108,   136,    63,    68,    70,   132,     3,   134,    64,    63,
     128,   135,    64,    64,    89,   105,     3,   107,     3,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    98,    99,   100,   101,    85,    67,    79,
     105,   121,   108,   139,    80,   139,   107,   107,   107,    28,
     145,    77,    77,   105,    64,    64,    69,    64,   130,    69,
     108,    64,    92,    64,    79,    69,   107,    67,   137,   139,
      64,    64,   148,    63,   145,    64,    69,   105,    80,   139,
     139,    64,   107,    64,   107,   103,    26,   139,   149,   139,
      64,   139,    64,   139,    77
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   104,
     103,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   138,   138,   139,   140,   139,   139,   139,
     139,   139,   139,   141,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   146,   148,   147,   149,
     147,   147,   147,   150,   150,   150,   150,   150,   151,   151,
     152,   152,   154,   153,   155,   153,   156,   153,   157,   153
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     0,
       6,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     3,     4,     3,     3,     2,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     0,     6,     0,
       8,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     0,     5,     0,     4,     0,     4,     0,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   140,   140,   160,   164,   168,   175,   176,   192,   194,
     196,   198,   200,   202,   207,   208,   212,   214,   216,   218,
     220,   222,   228,   229,   230,   231,   232,   233,   237,   239,
     244,   246,   247,   248,   252,   255,   256,   260,   263,   264,
     268,   271,   272,   273,   274,   278,   281,   282,   286,   289,
     293,   296,   300,   303,   307,   310,   314,   317,   321,   323,
     323,   339,   341,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   359,   361,   365,   369,   371,   379,
     381,   383,   385,   387,   389,   394,   395,   399,   404,   412,
     413,   414,   415,   416,   420,   421,   422,   423,   424,   425,
     426,   427,   429,   430,   431,   432,   438,   439,   440,   443,
     444,   448,   449,   453,   457,   459,   461,   463,   468,   469,
     473,   474,   475,   479,   480,   481,   485,   486,   490,   491,
     495,   496,   500,   504,   511,   513,   515,   520,   525,   527,
     531,   535,   540,   545,   550,   559,   561,   567,   568,   572,
     573,   577,   578,   579,   583,   584,   588,   589,   593,   594,
     595,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     611,   612,   613,   617,   618,   622,   623,   623,   626,   627,
     628,   629,   630,   634,   635,   636,   640,   641,   645,   646,
     649,   650,   653,   654,   658,   659,   660,   664,   664,   665,
     665,   666,   668,   672,   673,   674,   675,   676,   680,   681,
     685,   686,   691,   691,   693,   693,   695,   695,   697,   697
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


} // yy
#line 2630 "mcc_c.tab.c"

#line 701 "mcc_c.y"

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
