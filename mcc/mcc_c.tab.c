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

      case symbol_kind::S_type_specifier: // type_specifier
        value.YY_MOVE_OR_COPY< mcc::Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.YY_MOVE_OR_COPY< mcc::TypeOrNone > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.YY_MOVE_OR_COPY< std::pair<mcc::Type,mcc::PtrBits> > (YY_MOVE (that.value));
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

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< mcc::Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.move< mcc::TypeOrNone > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.move< std::pair<mcc::Type,mcc::PtrBits> > (YY_MOVE (that.value));
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

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< mcc::Type > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.copy< mcc::TypeOrNone > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.copy< std::pair<mcc::Type,mcc::PtrBits> > (that.value);
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

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< mcc::Type > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        value.move< mcc::TypeOrNone > (that.value);
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.move< std::pair<mcc::Type,mcc::PtrBits> > (that.value);
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

      case symbol_kind::S_type_specifier: // type_specifier
        yylhs.value.emplace< mcc::Type > ();
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
        yylhs.value.emplace< mcc::TypeOrNone > ();
        break;

      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        yylhs.value.emplace< std::pair<mcc::Type,mcc::PtrBits> > ();
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
#line 835 "mcc_c.tab.c"
    break;

  case 3: // primary_expression: "constant"
#line 161 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 843 "mcc_c.tab.c"
    break;

  case 4: // primary_expression: "literal"
#line 165 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 851 "mcc_c.tab.c"
    break;

  case 5: // primary_expression: "(" expression ")"
#line 169 "mcc_c.y"
        {
	yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ();
	}
#line 859 "mcc_c.tab.c"
    break;

  case 6: // postfix_expression: primary_expression
#line 175 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[0].value.as < mcc::Symbol > (); }
#line 865 "mcc_c.tab.c"
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
#line 885 "mcc_c.tab.c"
    break;

  case 8: // postfix_expression: postfix_expression "(" ")"
#line 193 "mcc_c.y"
        {mcc::PrintColored("Function call with no args",mcc::TextColor::Good);}
#line 891 "mcc_c.tab.c"
    break;

  case 9: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 195 "mcc_c.y"
        {mcc::PrintColored("Function call with args",mcc::TextColor::Good);}
#line 897 "mcc_c.tab.c"
    break;

  case 10: // postfix_expression: postfix_expression "." "identifier"
#line 197 "mcc_c.y"
        {mcc::PrintColored("Non ptr struct or union field access",mcc::TextColor::Good);}
#line 903 "mcc_c.tab.c"
    break;

  case 11: // postfix_expression: postfix_expression "->" "identifier"
#line 199 "mcc_c.y"
        {mcc::PrintColored("Ptr struct or union field access",mcc::TextColor::Good);}
#line 909 "mcc_c.tab.c"
    break;

  case 12: // postfix_expression: postfix_expression "++"
#line 201 "mcc_c.y"
        {mcc::PrintColored("Postfix increment",mcc::TextColor::Good);}
#line 915 "mcc_c.tab.c"
    break;

  case 13: // postfix_expression: postfix_expression "--"
#line 203 "mcc_c.y"
        {mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);}
#line 921 "mcc_c.tab.c"
    break;

  case 16: // unary_expression: postfix_expression
#line 213 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 927 "mcc_c.tab.c"
    break;

  case 17: // unary_expression: "++" unary_expression
#line 215 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 933 "mcc_c.tab.c"
    break;

  case 18: // unary_expression: "--" unary_expression
#line 217 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 939 "mcc_c.tab.c"
    break;

  case 19: // unary_expression: unary_operator cast_expression
#line 219 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 945 "mcc_c.tab.c"
    break;

  case 20: // unary_expression: "sizeof" unary_expression
#line 221 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol(mcc::Primitive::ULongLong,0,true,true,false);}
#line 951 "mcc_c.tab.c"
    break;

  case 21: // unary_expression: "sizeof" "(" type_name ")"
#line 223 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol(mcc::Primitive::ULongLong,0,true,true,false);}
#line 957 "mcc_c.tab.c"
    break;

  case 28: // cast_expression: unary_expression
#line 238 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 963 "mcc_c.tab.c"
    break;

  case 29: // cast_expression: "(" type_name ")" cast_expression
#line 240 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol{yystack_[2].value.as < std::pair<mcc::Type,mcc::PtrBits> > ().first,yystack_[2].value.as < std::pair<mcc::Type,mcc::PtrBits> > ().second.GetIndirection(),true,true,false};}
#line 969 "mcc_c.tab.c"
    break;

  case 30: // multiplicative_expression: cast_expression
#line 245 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 975 "mcc_c.tab.c"
    break;

  case 31: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 246 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 981 "mcc_c.tab.c"
    break;

  case 32: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 247 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 987 "mcc_c.tab.c"
    break;

  case 33: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 248 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 993 "mcc_c.tab.c"
    break;

  case 34: // additive_expression: multiplicative_expression
#line 253 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 999 "mcc_c.tab.c"
    break;

  case 35: // additive_expression: additive_expression "+" multiplicative_expression
#line 255 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1005 "mcc_c.tab.c"
    break;

  case 36: // additive_expression: additive_expression "-" multiplicative_expression
#line 256 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1011 "mcc_c.tab.c"
    break;

  case 37: // shift_expression: additive_expression
#line 261 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1017 "mcc_c.tab.c"
    break;

  case 38: // shift_expression: shift_expression "<<" additive_expression
#line 263 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1023 "mcc_c.tab.c"
    break;

  case 39: // shift_expression: shift_expression ">>" additive_expression
#line 264 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1029 "mcc_c.tab.c"
    break;

  case 40: // relational_expression: shift_expression
#line 269 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1035 "mcc_c.tab.c"
    break;

  case 41: // relational_expression: relational_expression "<=" shift_expression
#line 271 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1041 "mcc_c.tab.c"
    break;

  case 42: // relational_expression: relational_expression ">=" shift_expression
#line 272 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1047 "mcc_c.tab.c"
    break;

  case 43: // relational_expression: relational_expression "<" shift_expression
#line 273 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1053 "mcc_c.tab.c"
    break;

  case 44: // relational_expression: relational_expression ">" shift_expression
#line 274 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1059 "mcc_c.tab.c"
    break;

  case 45: // equality_expression: relational_expression
#line 279 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1065 "mcc_c.tab.c"
    break;

  case 46: // equality_expression: equality_expression "==" relational_expression
#line 281 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1071 "mcc_c.tab.c"
    break;

  case 47: // equality_expression: equality_expression "!=" relational_expression
#line 282 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1077 "mcc_c.tab.c"
    break;

  case 48: // and_expression: equality_expression
#line 287 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1083 "mcc_c.tab.c"
    break;

  case 49: // and_expression: and_expression "&" equality_expression
#line 289 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1089 "mcc_c.tab.c"
    break;

  case 50: // exclusive_or_expression: and_expression
#line 294 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1095 "mcc_c.tab.c"
    break;

  case 51: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 296 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1101 "mcc_c.tab.c"
    break;

  case 52: // inclusive_or_expression: exclusive_or_expression
#line 301 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1107 "mcc_c.tab.c"
    break;

  case 53: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 303 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1113 "mcc_c.tab.c"
    break;

  case 54: // logical_and_expression: inclusive_or_expression
#line 308 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1119 "mcc_c.tab.c"
    break;

  case 55: // logical_and_expression: logical_and_expression "||" inclusive_or_expression
#line 310 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1125 "mcc_c.tab.c"
    break;

  case 56: // logical_or_expression: logical_and_expression
#line 315 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1131 "mcc_c.tab.c"
    break;

  case 57: // logical_or_expression: logical_or_expression "&&" logical_and_expression
#line 317 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1137 "mcc_c.tab.c"
    break;

  case 58: // conditional_expression: logical_or_expression
#line 322 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1143 "mcc_c.tab.c"
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
#line 1160 "mcc_c.tab.c"
    break;

  case 60: // conditional_expression: logical_or_expression $@1 "?" expression ":" conditional_expression
#line 323 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[5].value.as < mcc::Symbol > (); }
#line 1166 "mcc_c.tab.c"
    break;

  case 61: // assignment_expression: conditional_expression
#line 340 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1172 "mcc_c.tab.c"
    break;

  case 62: // $@2: %empty
#line 342 "mcc_c.y"
        {
		if(!yystack_[0].value.as < mcc::Symbol > ().IsLvalue()||yystack_[0].value.as < mcc::Symbol > ().IsConst())
		{mcc::PrintColored("Can only assign to a non-const lvalue",mcc::TextColor::Error);}
	}
#line 1181 "mcc_c.tab.c"
    break;

  case 63: // assignment_expression: unary_expression $@2 assignment_operator assignment_expression
#line 347 "mcc_c.y"
        {
		if(yystack_[3].value.as < mcc::Symbol > ().GetType().index()!=yystack_[0].value.as < mcc::Symbol > ().GetType().index())
		{
			mcc::PrintColored("Cant assign a non primitive to a primitive or vise-versa",mcc::TextColor::Error);
		}
	}
#line 1192 "mcc_c.tab.c"
    break;

  case 75: // expression: assignment_expression
#line 371 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol(yystack_[0].value.as < mcc::Symbol > ().GetType(),yystack_[0].value.as < mcc::Symbol > ().GetIndLevel(),false,true,true);}
#line 1198 "mcc_c.tab.c"
    break;

  case 76: // expression: expression "," assignment_expression
#line 372 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1204 "mcc_c.tab.c"
    break;

  case 77: // constant_expression: conditional_expression
#line 376 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[0].value.as < mcc::Symbol > (); }
#line 1210 "mcc_c.tab.c"
    break;

  case 78: // declaration: declaration_specifiers ";"
#line 381 "mcc_c.y"
        {mcc::PrintColored("declaration does not declare anything",mcc::TextColor::Warning);}
#line 1216 "mcc_c.tab.c"
    break;

  case 79: // declaration: declaration_specifiers init_declarator_list ";"
#line 383 "mcc_c.y"
        {
		drv.UnsetCurrentType();
	}
#line 1224 "mcc_c.tab.c"
    break;

  case 80: // declaration_specifiers: storage_class_specifier
#line 390 "mcc_c.y"
        {yylhs.value.as < mcc::TypeOrNone > ()=mcc::Primitive::Int;drv.SetCurrentType(yylhs.value.as < mcc::TypeOrNone > ());}
#line 1230 "mcc_c.tab.c"
    break;

  case 81: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 392 "mcc_c.y"
        {yylhs.value.as < mcc::TypeOrNone > ()=yystack_[0].value.as < mcc::TypeOrNone > ();drv.SetCurrentType(yylhs.value.as < mcc::TypeOrNone > ());}
#line 1236 "mcc_c.tab.c"
    break;

  case 82: // declaration_specifiers: type_specifier
#line 394 "mcc_c.y"
        {yylhs.value.as < mcc::TypeOrNone > ()=yystack_[0].value.as < mcc::Type > ();drv.SetCurrentType(yylhs.value.as < mcc::TypeOrNone > ());}
#line 1242 "mcc_c.tab.c"
    break;

  case 83: // declaration_specifiers: type_specifier declaration_specifiers
#line 396 "mcc_c.y"
        {yylhs.value.as < mcc::TypeOrNone > ()=yystack_[1].value.as < mcc::Type > ();drv.SetCurrentType(yylhs.value.as < mcc::TypeOrNone > ());}
#line 1248 "mcc_c.tab.c"
    break;

  case 84: // declaration_specifiers: type_qualifier
#line 398 "mcc_c.y"
        {yylhs.value.as < mcc::TypeOrNone > ()=mcc::Primitive::Int;drv.SetCurrentType(yylhs.value.as < mcc::TypeOrNone > ());}
#line 1254 "mcc_c.tab.c"
    break;

  case 85: // declaration_specifiers: type_qualifier declaration_specifiers
#line 400 "mcc_c.y"
        { yylhs.value.as < mcc::TypeOrNone > ()=yystack_[0].value.as < mcc::TypeOrNone > ();drv.SetCurrentType(yylhs.value.as < mcc::TypeOrNone > ());}
#line 1260 "mcc_c.tab.c"
    break;

  case 86: // init_declarator_list: init_declarator
#line 405 "mcc_c.y"
        {drv.SetInConst(false);}
#line 1266 "mcc_c.tab.c"
    break;

  case 87: // init_declarator_list: init_declarator_list "," init_declarator
#line 406 "mcc_c.y"
          { yylhs.value.as < std::vector<mcc::Symbol> > () = yystack_[2].value.as < std::vector<mcc::Symbol> > (); }
#line 1272 "mcc_c.tab.c"
    break;

  case 88: // init_declarator: declarator
#line 411 "mcc_c.y"
        {
		auto sym = mcc::Symbol{drv.GetCurrentType(),0,drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[0].value.as < std::string > (),std::move(sym));
	}
#line 1281 "mcc_c.tab.c"
    break;

  case 89: // init_declarator: declarator "=" initializer
#line 416 "mcc_c.y"
        {
		auto sym=mcc::Symbol{drv.GetCurrentType(),0,drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[2].value.as < std::string > (),std::move(sym));
	}
#line 1290 "mcc_c.tab.c"
    break;

  case 95: // type_specifier: "void"
#line 431 "mcc_c.y"
                {yylhs.value.as < mcc::Type > ()=mcc::Primitive::Void;}
#line 1296 "mcc_c.tab.c"
    break;

  case 96: // type_specifier: "char"
#line 432 "mcc_c.y"
                {yylhs.value.as < mcc::Type > ()=mcc::Primitive::Char;}
#line 1302 "mcc_c.tab.c"
    break;

  case 97: // type_specifier: "short"
#line 433 "mcc_c.y"
                 {yylhs.value.as < mcc::Type > ()=mcc::Primitive::Short;}
#line 1308 "mcc_c.tab.c"
    break;

  case 98: // type_specifier: "int"
#line 434 "mcc_c.y"
               {yylhs.value.as < mcc::Type > ()=mcc::Primitive::Int;}
#line 1314 "mcc_c.tab.c"
    break;

  case 99: // type_specifier: "long"
#line 435 "mcc_c.y"
                {yylhs.value.as < mcc::Type > ()=mcc::Primitive::Long;}
#line 1320 "mcc_c.tab.c"
    break;

  case 100: // type_specifier: "float"
#line 436 "mcc_c.y"
                 {yylhs.value.as < mcc::Type > ()=mcc::Primitive::Float;}
#line 1326 "mcc_c.tab.c"
    break;

  case 101: // type_specifier: "double"
#line 437 "mcc_c.y"
                  {yylhs.value.as < mcc::Type > ()=mcc::Primitive::Double;}
#line 1332 "mcc_c.tab.c"
    break;

  case 102: // type_specifier: "signed"
#line 439 "mcc_c.y"
        {}
#line 1338 "mcc_c.tab.c"
    break;

  case 103: // type_specifier: "unsigned"
#line 440 "mcc_c.y"
                    {}
#line 1344 "mcc_c.tab.c"
    break;

  case 104: // type_specifier: struct_or_union_specifier
#line 441 "mcc_c.y"
                                   {}
#line 1350 "mcc_c.tab.c"
    break;

  case 105: // type_specifier: enum_specifier
#line 442 "mcc_c.y"
                        {}
#line 1356 "mcc_c.tab.c"
    break;

  case 106: // type_specifier: "typename"
#line 444 "mcc_c.y"
                {
			yylhs.value.as < mcc::Type > () = drv.GetType(yystack_[0].value.as < std::string > ()).value();
		}
#line 1364 "mcc_c.tab.c"
    break;

  case 115: // specifier_qualifier_list: type_specifier specifier_qualifier_list
#line 469 "mcc_c.y"
        {
		if(std::holds_alternative<mcc::NoneType>(yystack_[1].value.as < mcc::Type > ())^std::holds_alternative<mcc::NoneType>(yystack_[0].value.as < std::pair<mcc::Type,mcc::PtrBits> > ().first))
		{yylhs.value.as < std::pair<mcc::Type,mcc::PtrBits> > ()={yystack_[1].value.as < mcc::Type > (),{}};}
		else
		{
			mcc::PrintColored("Invalid type",mcc::TextColor::Error);
			yylhs.value.as < std::pair<mcc::Type,mcc::PtrBits> > ()={};
		}
	}
#line 1378 "mcc_c.tab.c"
    break;

  case 116: // specifier_qualifier_list: type_specifier
#line 479 "mcc_c.y"
        {yylhs.value.as < std::pair<mcc::Type,mcc::PtrBits> > ()={yystack_[0].value.as < mcc::Type > (),{}};}
#line 1384 "mcc_c.tab.c"
    break;

  case 117: // specifier_qualifier_list: type_qualifier specifier_qualifier_list
#line 481 "mcc_c.y"
        {yylhs.value.as < std::pair<mcc::Type,mcc::PtrBits> > ()=yystack_[0].value.as < std::pair<mcc::Type,mcc::PtrBits> > ();}
#line 1390 "mcc_c.tab.c"
    break;

  case 118: // specifier_qualifier_list: type_qualifier
#line 483 "mcc_c.y"
        {yylhs.value.as < std::pair<mcc::Type,mcc::PtrBits> > ()={};}
#line 1396 "mcc_c.tab.c"
    break;

  case 131: // type_qualifier: "const"
#line 513 "mcc_c.y"
                 {yylhs.value.as < std::string > ()="const";drv.SetInConst(true);}
#line 1402 "mcc_c.tab.c"
    break;

  case 132: // type_qualifier: "volatile"
#line 514 "mcc_c.y"
                    {yylhs.value.as < std::string > ()="";}
#line 1408 "mcc_c.tab.c"
    break;

  case 133: // declarator: pointer direct_declarator
#line 519 "mcc_c.y"
        {
		yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
	}
#line 1416 "mcc_c.tab.c"
    break;

  case 134: // declarator: direct_declarator
#line 523 "mcc_c.y"
        {
		yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
	}
#line 1424 "mcc_c.tab.c"
    break;

  case 135: // direct_declarator: "identifier"
#line 530 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 1430 "mcc_c.tab.c"
    break;

  case 136: // direct_declarator: "(" declarator ")"
#line 532 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ();}
#line 1436 "mcc_c.tab.c"
    break;

  case 137: // direct_declarator: direct_declarator "[" constant_expression "]"
#line 534 "mcc_c.y"
        {
		mcc::PrintColored("Array def:",mcc::TextColor::Good);
		drv.AddSymbol(yystack_[3].value.as < std::string > (),mcc::Symbol{drv.GetCurrentType(),1,true,true,true});
	}
#line 1445 "mcc_c.tab.c"
    break;

  case 138: // direct_declarator: direct_declarator "[" "]"
#line 539 "mcc_c.y"
        {
		mcc::PrintColored("Array def VLA:",mcc::TextColor::Good);
		drv.AddSymbol(yystack_[2].value.as < std::string > (),mcc::Symbol{,0,true,true,true});
	}
#line 1454 "mcc_c.tab.c"
    break;

  case 139: // direct_declarator: direct_declarator "(" parameter_type_list ")"
#line 544 "mcc_c.y"
        { mcc::PrintColored("Function ptr only type proto",mcc::TextColor::Good);}
#line 1460 "mcc_c.tab.c"
    break;

  case 140: // direct_declarator: direct_declarator "(" identifier_list ")"
#line 546 "mcc_c.y"
        {
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
	}
#line 1468 "mcc_c.tab.c"
    break;

  case 141: // direct_declarator: direct_declarator "(" ")"
#line 549 "mcc_c.y"
          { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > (); }
#line 1474 "mcc_c.tab.c"
    break;

  case 142: // pointer: "*"
#line 554 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1483 "mcc_c.tab.c"
    break;

  case 143: // pointer: "*" type_qualifier_list
#line 559 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[0].value.as < std::string > ()=="const");
	}
#line 1492 "mcc_c.tab.c"
    break;

  case 144: // pointer: "*" pointer
#line 564 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1501 "mcc_c.tab.c"
    break;

  case 145: // pointer: "*" type_qualifier_list pointer
#line 569 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[1].value.as < std::string > ()=="const");
	}
#line 1510 "mcc_c.tab.c"
    break;

  case 146: // type_qualifier_list: type_qualifier
#line 578 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 1516 "mcc_c.tab.c"
    break;

  case 147: // type_qualifier_list: type_qualifier_list type_qualifier
#line 580 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ()+yystack_[0].value.as < std::string > ();}
#line 1522 "mcc_c.tab.c"
    break;

  case 157: // type_name: specifier_qualifier_list
#line 606 "mcc_c.y"
          { yylhs.value.as < std::pair<mcc::Type,mcc::PtrBits> > () = yystack_[0].value.as < std::pair<mcc::Type,mcc::PtrBits> > (); }
#line 1528 "mcc_c.tab.c"
    break;

  case 158: // type_name: specifier_qualifier_list abstract_declarator
#line 607 "mcc_c.y"
          { yylhs.value.as < std::pair<mcc::Type,mcc::PtrBits> > () = yystack_[1].value.as < std::pair<mcc::Type,mcc::PtrBits> > (); }
#line 1534 "mcc_c.tab.c"
    break;

  case 177: // $@3: %empty
#line 641 "mcc_c.y"
          {drv.EnterNewScope("");}
#line 1540 "mcc_c.tab.c"
    break;

  case 178: // statement: $@3 compound_statement
#line 643 "mcc_c.y"
                {drv.LeaveScope();}
#line 1546 "mcc_c.tab.c"
    break;

  case 198: // $@4: %empty
#line 682 "mcc_c.y"
                                 {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1552 "mcc_c.tab.c"
    break;

  case 200: // $@5: %empty
#line 683 "mcc_c.y"
                                                {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1558 "mcc_c.tab.c"
    break;

  case 212: // external_declaration: declaration
#line 705 "mcc_c.y"
        {mcc::PrintColored("New global definition",mcc::TextColor::Good);}
#line 1564 "mcc_c.tab.c"
    break;

  case 213: // $@6: %empty
#line 709 "mcc_c.y"
                                                             {drv.EnterNewScope(yystack_[1].value.as < std::string > ());}
#line 1570 "mcc_c.tab.c"
    break;

  case 214: // function_definition: declaration_specifiers declarator declaration_list $@6 compound_statement
#line 710 "mcc_c.y"
                {drv.LeaveScope();}
#line 1576 "mcc_c.tab.c"
    break;

  case 215: // $@7: %empty
#line 711 "mcc_c.y"
                                            {drv.EnterNewScope(yystack_[0].value.as < std::string > ());}
#line 1582 "mcc_c.tab.c"
    break;

  case 216: // function_definition: declaration_specifiers declarator $@7 compound_statement
#line 712 "mcc_c.y"
                {drv.LeaveScope();}
#line 1588 "mcc_c.tab.c"
    break;

  case 217: // $@8: %empty
#line 713 "mcc_c.y"
                                      {drv.EnterNewScope(yystack_[1].value.as < std::string > ());}
#line 1594 "mcc_c.tab.c"
    break;

  case 218: // function_definition: declarator declaration_list $@8 compound_statement
#line 714 "mcc_c.y"
                {drv.LeaveScope();}
#line 1600 "mcc_c.tab.c"
    break;

  case 219: // $@9: %empty
#line 715 "mcc_c.y"
                     {drv.EnterNewScope(yystack_[0].value.as < std::string > ());}
#line 1606 "mcc_c.tab.c"
    break;

  case 220: // function_definition: declarator $@9 compound_statement
#line 716 "mcc_c.y"
                {drv.LeaveScope();}
#line 1612 "mcc_c.tab.c"
    break;


#line 1616 "mcc_c.tab.c"

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
  "conditional_expression", "$@1", "assignment_expression", "$@2",
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
  "initializer_list", "statement", "$@3", "labeled_statement",
  "compound_statement", "statement_list", "declaration_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "$@4", "$@5", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "$@6", "$@7", "$@8",
  "$@9", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -220;

  const short parser::yytable_ninf_ = -216;

  const short
  parser::yypact_[] =
  {
    1138,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,
       4,  -220,    12,    54,  -220,    33,  1361,  1361,  -220,    21,
    -220,  1361,  1361,    36,    11,   935,  -220,  -220,   -44,    37,
    -220,  -220,    12,     9,  -220,   113,  -220,  1195,  -220,  -220,
      -4,  1387,  -220,  -220,    33,  1361,    69,  1096,   606,    36,
    -220,  -220,    37,   -11,   -51,  -220,  -220,  -220,  -220,  -220,
      54,   629,  1361,    69,  1387,  1387,  1281,  -220,    32,  1387,
      68,  -220,    69,   310,  -220,  -220,  -220,    66,   102,   100,
    -220,   -38,  -220,  -220,  -220,   769,  -220,  -220,  -220,  -220,
    -220,  -220,   565,  -220,   784,   784,  -220,   194,  -220,   807,
    -220,   130,   -32,    -2,   103,    24,   135,   145,   148,   128,
     117,  -220,   158,    92,   807,  -220,    37,  -220,   629,  1398,
    -220,  -220,  -220,    69,  -220,  1318,  -220,  -220,  -220,   807,
     127,  -220,   152,  -220,  -220,   154,   807,   163,   182,   183,
     187,   460,   188,   255,   193,   197,   217,  -220,  -220,  -220,
     134,  -220,  -220,    69,  -220,   385,  -220,  -220,  -220,  -220,
     873,   667,  -220,    39,  -220,    62,  -220,   992,  -220,   257,
     565,  -220,   -14,    -7,   200,   807,  -220,  -220,   693,   268,
     807,  -220,  -220,   273,  -220,   807,   807,   807,   807,   807,
     807,   807,   807,   807,   807,   807,   807,   807,   807,   807,
     807,   807,   807,   192,  -220,  -220,  -220,  -220,  -220,    97,
    1408,  -220,  -220,  -220,  -220,    32,   807,   460,   203,   460,
     807,   807,   807,   256,   495,   208,  -220,  -220,  -220,   149,
    -220,   807,  -220,  -220,  -220,  -220,   222,   223,  -220,   221,
      62,  1255,   708,  -220,  -220,  -220,   227,  -220,  1034,    64,
    -220,   807,  -220,    44,  -220,  -220,    42,  -220,  -220,  -220,
    -220,   130,   130,   -32,   -32,    -2,    -2,    -2,    -2,   103,
     103,    24,   135,   145,   148,   128,   807,  -220,   588,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,
     807,  -220,  -220,  -220,   460,  -220,    45,    52,   214,   232,
     495,  -220,  -220,  -220,  -220,  -220,  -220,  -220,   233,  -220,
     229,  -220,  -220,  -220,   807,  -220,   150,  -220,  -220,  -220,
    -220,   460,   460,   235,   807,   743,  -220,  -220,  -220,   807,
     270,  -220,   460,   214,   460,    96,  -220,   460,  -220,   236,
    -220,   460,  -220,   224,  -220,  -220
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   135,    90,    91,    92,    93,    94,    96,    97,    99,
     102,   103,   100,   101,   131,   132,    95,    98,   110,   111,
       0,   106,   142,     0,   212,     0,    80,    82,   104,     0,
     105,    84,   219,   134,     0,     0,   209,   211,   126,     0,
     146,   144,   143,     0,    78,     0,    86,    88,    81,    83,
     109,     0,    85,   191,     0,   217,     0,     0,     0,   133,
       1,   210,     0,   129,     0,   127,   147,   145,   136,    79,
       0,     0,   213,     0,     0,   116,     0,   112,     0,   118,
      88,   192,     0,   177,   220,   155,   141,   154,     0,   148,
     150,     0,     2,     3,     4,     0,    22,    25,    23,    24,
      27,    26,     0,   138,     0,     0,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      58,    77,     0,     0,     0,   124,     0,    87,     0,    28,
      61,   171,    89,     0,   216,     0,   115,   108,   113,     0,
       0,   119,   121,   117,   218,     2,     0,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,   188,   193,    75,
       0,   183,   189,     0,   176,   177,   179,   180,   181,   182,
       0,     0,   152,   159,   153,   160,   139,     0,   140,     0,
       0,    20,     0,   157,     0,     0,    17,    18,     0,     0,
       0,    12,    13,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   125,   130,   128,   174,     0,
       0,   214,   107,   122,   114,     0,     0,   177,     0,   177,
       0,     0,     0,     0,     0,     0,   205,   206,   207,     0,
     194,     0,   178,   187,   190,   167,     0,     0,   163,     0,
     161,     0,     0,   149,   151,   156,     0,     5,     0,   159,
     158,     0,     8,     0,    14,    11,     0,    10,    31,    32,
      33,    35,    36,    38,    39,    42,    41,    43,    44,    46,
      47,    49,    51,    53,    55,    57,     0,   172,     0,    66,
      67,    65,    69,    68,    70,    71,    72,    73,    74,    64,
       0,   120,   123,   184,   177,   186,     0,     0,   198,     0,
       0,   204,   208,    76,   168,   162,   164,   169,     0,   165,
       0,    21,    29,     9,     0,     7,     0,   173,   175,    63,
     185,   177,   177,     0,     0,     0,   170,   166,    15,     0,
     195,   197,   177,   200,   177,     0,    60,   177,   199,     0,
     202,   177,   196,     0,   203,   201
  };

  const short
  parser::yypgoto_[] =
  {
    -220,  -220,  -220,  -220,   -58,  -220,  -103,    40,    41,    13,
      46,    94,    95,    93,    98,   124,  -220,   -57,  -220,   -69,
    -220,  -220,   -23,   -56,   201,     3,  -220,   237,  -220,   112,
    -220,  -220,   231,   -49,   -54,  -220,    81,  -220,   246,   184,
       1,   -15,   -17,    -9,  -220,   -53,  -220,   171,  -220,   169,
     -78,  -161,  -123,  -220,  -107,  -220,  -220,   -62,  -220,   303,
    -219,  -220,  -220,  -220,  -220,  -220,  -220,   316,  -220,  -220,
    -220,  -220,  -220
  };

  const short
  parser::yydefgoto_[] =
  {
       0,   106,   107,   263,   129,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   130,   213,   159,
     220,   300,   160,   122,   161,    54,    45,    46,    26,    27,
      28,    29,    76,    77,    78,   140,   141,    30,    64,    65,
      31,    32,    33,    34,    42,   246,    89,    90,    91,   184,
     247,   175,   132,   219,   162,   163,   164,    84,   165,    55,
     166,   167,   168,   333,   349,   169,    35,    36,    37,   133,
      73,    82,    56
  };

  const short
  parser::yytable_[] =
  {
     108,   121,   131,    25,    88,   218,   194,    38,    43,   174,
      47,   134,   250,    41,     1,   310,   125,    59,   198,   199,
     144,   136,    62,    40,    50,   143,   178,   138,   126,    48,
      49,    14,    15,    67,    52,     1,     1,   181,    25,    80,
      63,   179,     1,    66,   233,    22,   186,   187,   183,   124,
     257,   108,    79,   200,   201,    80,   258,     1,   244,   131,
      87,   171,    74,   142,    22,   241,   108,   121,   216,     1,
      39,   221,   172,    68,    23,    79,    79,    79,   173,   182,
      79,   108,   121,   223,    22,    22,   138,    51,   108,   121,
     228,   335,   268,   269,   270,    23,    23,   206,   250,    57,
     207,   242,   170,    79,    58,   260,    22,   171,   323,   331,
      44,   325,   139,   108,   121,   249,   332,    23,    22,   264,
     303,   241,   305,   324,   241,   251,   183,   258,    71,   170,
     252,   241,   171,   239,   171,    83,    79,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,    43,    59,   182,   322,   215,
     351,   173,   182,    75,   287,   328,   176,   266,   108,   121,
     302,   126,   313,    87,   259,   241,   288,   202,   203,   177,
      87,    79,   195,   196,   204,   205,    75,    75,    75,   197,
      69,    75,    70,   208,   108,   121,   320,   330,   318,   209,
     212,    24,   -59,   108,   224,   210,   225,   306,   307,   308,
     142,   240,   211,   241,    75,   275,   276,   277,   278,   131,
      92,    93,    94,    95,   340,   341,   312,   214,   241,   241,
     339,   329,   226,    53,   227,   348,    24,   350,   271,   272,
     352,   273,   274,   229,   354,   230,   231,    75,    53,   259,
     232,   234,   279,   280,    87,   338,    81,   188,   235,   189,
     255,    87,   190,   326,   261,   191,   192,    96,    97,    98,
     236,   265,   193,    81,   237,    99,   267,   286,   100,   101,
     102,   108,   346,   304,   309,   311,   314,   315,   104,   105,
     316,   321,    75,   241,   238,   334,   347,   336,   337,   342,
     353,   355,   281,   283,   282,   135,   301,   127,   123,   284,
     217,   343,   345,   145,    93,    94,    95,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   146,   147,   148,    17,   285,   149,   150,   151,
     152,   153,   154,   155,   156,    18,    19,    20,   254,   256,
      72,    61,     0,     0,     0,     0,     0,     0,    21,     0,
      96,    97,    98,     0,     0,     0,     0,     0,    99,     0,
       0,   100,   101,   102,     0,     0,     0,   157,     0,     0,
       0,   104,   105,     0,     0,     0,     0,   158,   145,    93,
      94,    95,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   146,   147,   148,
      17,     0,   149,   150,   151,   152,   153,   154,   155,   156,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    96,    97,    98,     0,     0,
       0,     0,     0,    99,     0,     0,   100,   101,   102,     0,
       0,     0,   243,     0,     0,     0,   104,   105,     0,     0,
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
     102,     0,     0,     0,     0,     0,   248,     0,   104,   105,
       0,     0,     0,    96,    97,    98,    92,    93,    94,    95,
       0,    99,     0,     0,   100,   101,   102,   262,    96,    97,
      98,     0,     0,     0,   104,   105,    99,     0,     0,   100,
     101,   102,    92,    93,    94,    95,     0,   319,     0,   104,
     105,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,     0,    96,    97,    98,     0,     0,     0,     0,
       0,    99,     0,     0,   100,   101,   102,   344,     0,     0,
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
       0,     0,     0,     0,     0,    60,   170,   245,     1,     0,
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
       0,     0,   253,     0,     0,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   245,    85,
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
       0,  -215,     2,     3,     4,     5,     6,     7,     8,     9,
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
      14,    15,    16,     0,     0,   222,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    21,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,     0,   -62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   299
  };

  const short
  parser::yycheck_[] =
  {
      58,    58,    71,     0,    57,   128,   109,     3,    23,    87,
      25,    73,   173,    22,     3,   234,    67,    34,    50,    51,
      82,    75,    66,    22,     3,    79,    64,    76,    79,    26,
      27,    19,    20,    42,    31,     3,     3,    95,    35,    54,
       3,    79,     3,    42,   151,    52,   104,   105,   102,    60,
      64,   109,    51,    55,    56,    70,    63,     3,   165,   128,
      57,    68,    66,    78,    52,    79,   124,   124,   124,     3,
      66,   133,    87,    64,    63,    74,    75,    76,    87,   102,
      79,   139,   139,   139,    52,    52,   135,    66,   146,   146,
     146,   310,   195,   196,   197,    63,    63,    73,   259,    63,
      76,   163,    63,   102,    68,   183,    52,    68,    64,    64,
      77,    69,    80,   171,   171,   171,    64,    63,    52,   188,
     227,    79,   229,    79,    79,    63,   180,    63,    60,    63,
      68,    79,    68,   156,    68,    66,   135,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   170,   173,   180,   261,    67,
      64,   170,   185,    51,    67,   288,    64,   190,   226,   226,
     226,    79,   241,   170,   183,    79,    79,    74,    75,    79,
     177,   180,    52,    53,    81,    82,    74,    75,    76,    59,
      77,    79,    79,    58,   252,   252,   252,   304,   251,    54,
      83,     0,    85,   261,    77,    57,    79,   230,   231,   232,
     225,    77,    84,    79,   102,   202,   203,   204,   205,   288,
       3,     4,     5,     6,   331,   332,    77,    69,    79,    79,
      80,   300,    80,    32,    80,   342,    35,   344,   198,   199,
     347,   200,   201,    80,   351,    63,    63,   135,    47,   258,
      63,    63,   206,   207,   251,   324,    55,    63,     3,    65,
       3,   258,    68,   286,    64,    71,    72,    50,    51,    52,
      77,     3,    78,    72,    77,    58,     3,    85,    61,    62,
      63,   339,   339,    80,    28,    77,    64,    64,    71,    72,
      69,    64,   180,    79,    77,    63,    26,    64,    69,    64,
      64,    77,   208,   210,   209,    74,   225,    70,    62,   211,
     126,   334,   335,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   212,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   177,   180,
      47,    35,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
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
      42,    43,    44,    45,    46,    47,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    25,    35,    36,
      37,    48,    52,    63,   110,   111,   114,   115,   116,   117,
     123,   126,   127,   128,   129,   152,   153,   154,     3,    66,
     126,   129,   130,   127,    77,   112,   113,   127,   111,   111,
       3,    66,   111,   110,   111,   145,   158,    63,    68,   128,
       0,   153,    66,     3,   124,   125,   126,   129,    64,    77,
      79,    60,   145,   156,    66,   115,   118,   119,   120,   126,
     127,   110,   157,    66,   143,     3,    64,   111,   131,   132,
     133,   134,     3,     4,     5,     6,    50,    51,    52,    58,
      61,    62,    63,    69,    71,    72,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   109,   124,    60,    67,    79,   113,    66,    90,
     103,   105,   138,   155,   143,   118,   120,    67,   119,    80,
     121,   122,   127,   120,   143,     3,    22,    23,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    67,    77,   105,
     108,   110,   140,   141,   142,   144,   146,   147,   148,   151,
      63,    68,   127,   129,   136,   137,    64,    79,    64,    79,
      63,    90,   108,   120,   135,    63,    90,    90,    63,    65,
      68,    71,    72,    78,    92,    52,    53,    59,    50,    51,
      55,    56,    74,    75,    81,    82,    73,    76,    58,    54,
      57,    84,    83,   104,    69,    67,   109,   125,   138,   139,
     106,   143,    67,   109,    77,    79,    80,    80,   109,    80,
      63,    63,    63,   140,    63,     3,    77,    77,    77,   108,
      77,    79,   143,    67,   140,    64,   131,   136,    69,   109,
     137,    63,    68,    70,   133,     3,   135,    64,    63,   129,
     136,    64,    64,    89,   105,     3,   108,     3,    92,    92,
      92,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      96,    97,    98,    99,   100,   101,    85,    67,    79,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    60,
     107,   122,   109,   140,    80,   140,   108,   108,   108,    28,
     146,    77,    77,   105,    64,    64,    69,    64,   131,    69,
     109,    64,    92,    64,    79,    69,   108,    67,   138,   105,
     140,    64,    64,   149,    63,   146,    64,    69,   105,    80,
     140,   140,    64,   108,    64,   108,   103,    26,   140,   150,
     140,    64,   140,    64,   140,    77
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
     103,   105,   106,   105,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     117,   117,   118,   118,   119,   120,   120,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   133,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   138,   139,   139,   140,   141,   140,   140,
     140,   140,   140,   140,   142,   142,   142,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   147,   147,   149,   148,
     150,   148,   148,   148,   151,   151,   151,   151,   151,   152,
     152,   153,   153,   155,   154,   156,   154,   157,   154,   158,
     154
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
       6,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     3,     4,     3,     3,     2,     1,
       2,     1,     2,     1,     2,     5,     7,     5,     0,     6,
       0,     8,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     0,     5,     0,     4,     0,     4,     0,
       3
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
     323,   339,   342,   341,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   370,   372,   376,   380,   382,
     389,   391,   393,   395,   397,   399,   404,   406,   410,   415,
     423,   424,   425,   426,   427,   431,   432,   433,   434,   435,
     436,   437,   438,   440,   441,   442,   443,   449,   450,   451,
     454,   455,   459,   460,   464,   468,   478,   480,   482,   487,
     488,   492,   493,   494,   498,   499,   500,   504,   505,   509,
     510,   513,   514,   518,   522,   529,   531,   533,   538,   543,
     545,   549,   553,   558,   563,   568,   577,   579,   585,   586,
     590,   591,   595,   596,   597,   601,   602,   606,   607,   611,
     612,   613,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   629,   630,   631,   635,   636,   640,   641,   641,   644,
     645,   646,   647,   648,   652,   653,   654,   658,   659,   663,
     664,   667,   668,   671,   672,   676,   677,   678,   682,   682,
     683,   683,   684,   686,   690,   691,   692,   693,   694,   698,
     699,   703,   704,   709,   709,   711,   711,   713,   713,   715,
     715
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
#line 2675 "mcc_c.tab.c"

#line 719 "mcc_c.y"

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}