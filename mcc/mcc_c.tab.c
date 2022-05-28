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
#line 138 "mcc_c.y"

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
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.YY_MOVE_OR_COPY< mcc::T > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_id_or_idptr: // id_or_idptr
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.YY_MOVE_OR_COPY< std::pair<std::string,mcc::Symbol> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dim: // array_dim
        value.YY_MOVE_OR_COPY< std::size_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.YY_MOVE_OR_COPY< std::vector<mcc::Symbol> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string,mcc::Symbol>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dim_list: // array_dim_list
        value.YY_MOVE_OR_COPY< std::vector<std::size_t> > (YY_MOVE (that.value));
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
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.move< mcc::T > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_id_or_idptr: // id_or_idptr
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< std::pair<std::string,mcc::Symbol> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dim: // array_dim
        value.move< std::size_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<mcc::Symbol> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< std::vector<std::pair<std::string,mcc::Symbol>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dim_list: // array_dim_list
        value.move< std::vector<std::size_t> > (YY_MOVE (that.value));
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
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.copy< mcc::T > (that.value);
        break;

      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_id_or_idptr: // id_or_idptr
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.copy< std::pair<std::string,mcc::Symbol> > (that.value);
        break;

      case symbol_kind::S_array_dim: // array_dim
        value.copy< std::size_t > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.copy< std::vector<mcc::Symbol> > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.copy< std::vector<std::pair<std::string,mcc::Symbol>> > (that.value);
        break;

      case symbol_kind::S_array_dim_list: // array_dim_list
        value.copy< std::vector<std::size_t> > (that.value);
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
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        value.move< mcc::T > (that.value);
        break;

      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_id_or_idptr: // id_or_idptr
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< std::pair<std::string,mcc::Symbol> > (that.value);
        break;

      case symbol_kind::S_array_dim: // array_dim
        value.move< std::size_t > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<mcc::Symbol> > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< std::vector<std::pair<std::string,mcc::Symbol>> > (that.value);
        break;

      case symbol_kind::S_array_dim_list: // array_dim_list
        value.move< std::vector<std::size_t> > (that.value);
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
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_name: // type_name
        yylhs.value.emplace< mcc::T > ();
        break;

      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_id_or_idptr: // id_or_idptr
      case symbol_kind::S_direct_declarator: // direct_declarator
        yylhs.value.emplace< std::pair<std::string,mcc::Symbol> > ();
        break;

      case symbol_kind::S_array_dim: // array_dim
        yylhs.value.emplace< std::size_t > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE_NAME: // "typename"
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
      case symbol_kind::S_init_declarator_list: // init_declarator_list
        yylhs.value.emplace< std::vector<mcc::Symbol> > ();
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        yylhs.value.emplace< std::vector<std::pair<std::string,mcc::Symbol>> > ();
        break;

      case symbol_kind::S_array_dim_list: // array_dim_list
        yylhs.value.emplace< std::vector<std::size_t> > ();
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
#line 146 "mcc_c.y"
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
#line 900 "mcc_c.tab.c"
    break;

  case 3: // primary_expression: "constant"
#line 166 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 908 "mcc_c.tab.c"
    break;

  case 4: // primary_expression: "literal"
#line 170 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 916 "mcc_c.tab.c"
    break;

  case 5: // primary_expression: "(" expression ")"
#line 174 "mcc_c.y"
        {
	yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ();
	}
#line 924 "mcc_c.tab.c"
    break;

  case 6: // postfix_expression: primary_expression
#line 181 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 932 "mcc_c.tab.c"
    break;

  case 7: // postfix_expression: postfix_expression "[" expression "]"
#line 185 "mcc_c.y"
        {
		const auto is_sub_int = mcc::IsIntegerT(yystack_[1].value.as < mcc::Symbol > ().GetType());
		const auto ind = yystack_[1].value.as < mcc::Symbol > ().GetIndLevel();
		if(!is_sub_int || yystack_[1].value.as < mcc::Symbol > ().IsPtr())
			{
				mcc::PrintColored("Array subscript can't be non integer",mcc::TextColor::Error);
			}

		else if( yystack_[3].value.as < mcc::Symbol > ().IsPtr())
		{
			const auto ind_lhs = yystack_[3].value.as < mcc::Symbol > ().GetIndLevel();
			yylhs.value.as < mcc::Symbol > ()={{yystack_[3].value.as < mcc::Symbol > ().GetType(),yystack_[3].value.as < mcc::Symbol > ().GetDeref()},yystack_[3].value.as < mcc::Symbol > ().DerefIsConst(),true,false};
					}
		else if(std::holds_alternative<mcc::CArray>(yystack_[3].value.as < mcc::Symbol > ().GetType()))
		{
			auto arr_t = std::get<mcc::CArray>(yystack_[3].value.as < mcc::Symbol > ().GetType());
			auto deref_t = arr_t.GetDerefT();
			yylhs.value.as < mcc::Symbol > ()={{deref_t},true,true,false};
					}
		else
		{
			mcc::PrintColored("Cannot apply subscript operator to a non pointer value",mcc::TextColor::Error);
		}
	}
#line 961 "mcc_c.tab.c"
    break;

  case 8: // postfix_expression: postfix_expression "(" ")"
#line 210 "mcc_c.y"
        {
		if(mcc::IsFuncPtr(yystack_[2].value.as < mcc::Symbol > ()))
		{
			const auto ftype = std::get<std::shared_ptr<mcc::Func>>(yystack_[2].value.as < mcc::Symbol > ().GetType());
			auto & fargs = ftype->GetArgs();
			if (!fargs.size())
			{
				yylhs.value.as < mcc::Symbol > ()={};
				mcc::PrintColored("Argument count mismatch, function requires " +
				 std::to_string(fargs.size())+" arguments," + " have 0"
				,mcc::TextColor::Error);
			}
			else
			yylhs.value.as < mcc::Symbol > ()={ftype->GetReturnType(),false,true,false};
		}
		else
		{
			mcc::PrintColored("Is not a function",mcc::TextColor::Error);
			yylhs.value.as < mcc::Symbol > ()={};
		}
	}
#line 987 "mcc_c.tab.c"
    break;

  case 9: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 232 "mcc_c.y"
        {
		if(mcc::IsFuncPtr(yystack_[3].value.as < mcc::Symbol > ()))
		{
			const auto ftype = std::get<std::shared_ptr<mcc::Func>>(yystack_[3].value.as < mcc::Symbol > ().GetType());
			auto & fargs = ftype->GetArgs();
			const auto arg_count_eq = fargs.size()==yystack_[1].value.as < std::vector<mcc::Symbol> > ().size();
			if (!arg_count_eq)
			{
				yylhs.value.as < mcc::Symbol > ()={};
				mcc::PrintColored("Argument count mismatch, function requires " +
				std::to_string(fargs.size()) + " arguments, " + "have " + std::to_string(yystack_[1].value.as < std::vector<mcc::Symbol> > ().size())
				,mcc::TextColor::Error);
			}
			else
			yylhs.value.as < mcc::Symbol > ()={ftype->GetReturnType(),false,true,false};
		}
		else
		{
			mcc::PrintColored("Is not a function",mcc::TextColor::Error);
			yylhs.value.as < mcc::Symbol > ()={};
		}
	}
#line 1014 "mcc_c.tab.c"
    break;

  case 10: // postfix_expression: postfix_expression "." "identifier"
#line 255 "mcc_c.y"
        {mcc::PrintColored("Non ptr struct or union field access",mcc::TextColor::Good);}
#line 1020 "mcc_c.tab.c"
    break;

  case 11: // postfix_expression: postfix_expression "->" "identifier"
#line 257 "mcc_c.y"
        {mcc::PrintColored("Ptr struct or union field access",mcc::TextColor::Good);}
#line 1026 "mcc_c.tab.c"
    break;

  case 12: // postfix_expression: postfix_expression "++"
#line 259 "mcc_c.y"
        {mcc::PrintColored("Postfix increment",mcc::TextColor::Good);}
#line 1032 "mcc_c.tab.c"
    break;

  case 13: // postfix_expression: postfix_expression "--"
#line 261 "mcc_c.y"
        {mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);}
#line 1038 "mcc_c.tab.c"
    break;

  case 14: // argument_expression_list: assignment_expression
#line 266 "mcc_c.y"
                {yylhs.value.as < std::vector<mcc::Symbol> > ()={};yylhs.value.as < std::vector<mcc::Symbol> > ().push_back(yystack_[0].value.as < mcc::Symbol > ());}
#line 1044 "mcc_c.tab.c"
    break;

  case 15: // argument_expression_list: argument_expression_list "," assignment_expression
#line 268 "mcc_c.y"
        {
		yylhs.value.as < std::vector<mcc::Symbol> > ()=yystack_[2].value.as < std::vector<mcc::Symbol> > ();
		yylhs.value.as < std::vector<mcc::Symbol> > ().push_back(yystack_[0].value.as < mcc::Symbol > ());
	}
#line 1053 "mcc_c.tab.c"
    break;

  case 16: // unary_expression: postfix_expression
#line 276 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1059 "mcc_c.tab.c"
    break;

  case 17: // unary_expression: "++" unary_expression
#line 278 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1065 "mcc_c.tab.c"
    break;

  case 18: // unary_expression: "--" unary_expression
#line 280 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1071 "mcc_c.tab.c"
    break;

  case 19: // unary_expression: unary_operator cast_expression
#line 282 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1077 "mcc_c.tab.c"
    break;

  case 20: // unary_expression: "sizeof" unary_expression
#line 284 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
#line 1083 "mcc_c.tab.c"
    break;

  case 21: // unary_expression: "sizeof" "(" type_name ")"
#line 286 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
#line 1089 "mcc_c.tab.c"
    break;

  case 28: // cast_expression: unary_expression
#line 301 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1095 "mcc_c.tab.c"
    break;

  case 29: // cast_expression: "(" type_name ")" cast_expression
#line 303 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol{yystack_[2].value.as < mcc::T > (),true,true,false};}
#line 1101 "mcc_c.tab.c"
    break;

  case 30: // multiplicative_expression: cast_expression
#line 308 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1107 "mcc_c.tab.c"
    break;

  case 31: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 310 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1113 "mcc_c.tab.c"
    break;

  case 32: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 312 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1119 "mcc_c.tab.c"
    break;

  case 33: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 314 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1125 "mcc_c.tab.c"
    break;

  case 34: // additive_expression: multiplicative_expression
#line 320 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1131 "mcc_c.tab.c"
    break;

  case 35: // additive_expression: additive_expression "+" multiplicative_expression
#line 323 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1137 "mcc_c.tab.c"
    break;

  case 36: // additive_expression: additive_expression "-" multiplicative_expression
#line 325 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1143 "mcc_c.tab.c"
    break;

  case 37: // shift_expression: additive_expression
#line 330 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1149 "mcc_c.tab.c"
    break;

  case 38: // shift_expression: shift_expression "<<" additive_expression
#line 333 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1155 "mcc_c.tab.c"
    break;

  case 39: // shift_expression: shift_expression ">>" additive_expression
#line 335 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1161 "mcc_c.tab.c"
    break;

  case 40: // relational_expression: shift_expression
#line 340 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1167 "mcc_c.tab.c"
    break;

  case 41: // relational_expression: relational_expression "<=" shift_expression
#line 342 "mcc_c.y"
                                                     {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1173 "mcc_c.tab.c"
    break;

  case 42: // relational_expression: relational_expression ">=" shift_expression
#line 344 "mcc_c.y"
                                                     {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1179 "mcc_c.tab.c"
    break;

  case 43: // relational_expression: relational_expression "<" shift_expression
#line 346 "mcc_c.y"
                                                    {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1185 "mcc_c.tab.c"
    break;

  case 44: // relational_expression: relational_expression ">" shift_expression
#line 348 "mcc_c.y"
                                                    {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1191 "mcc_c.tab.c"
    break;

  case 45: // equality_expression: relational_expression
#line 354 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1197 "mcc_c.tab.c"
    break;

  case 46: // equality_expression: equality_expression "==" relational_expression
#line 356 "mcc_c.y"
                                                        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1203 "mcc_c.tab.c"
    break;

  case 47: // equality_expression: equality_expression "!=" relational_expression
#line 358 "mcc_c.y"
                                                        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1209 "mcc_c.tab.c"
    break;

  case 48: // and_expression: equality_expression
#line 364 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1215 "mcc_c.tab.c"
    break;

  case 49: // and_expression: and_expression "&" equality_expression
#line 366 "mcc_c.y"
                                                {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1221 "mcc_c.tab.c"
    break;

  case 50: // exclusive_or_expression: and_expression
#line 372 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1227 "mcc_c.tab.c"
    break;

  case 51: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 374 "mcc_c.y"
                                                    {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1233 "mcc_c.tab.c"
    break;

  case 52: // inclusive_or_expression: exclusive_or_expression
#line 380 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1239 "mcc_c.tab.c"
    break;

  case 53: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 382 "mcc_c.y"
                                                             {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1245 "mcc_c.tab.c"
    break;

  case 54: // logical_and_expression: inclusive_or_expression
#line 387 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1251 "mcc_c.tab.c"
    break;

  case 55: // logical_and_expression: logical_and_expression "||" inclusive_or_expression
#line 389 "mcc_c.y"
                                                             {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1257 "mcc_c.tab.c"
    break;

  case 56: // logical_or_expression: logical_and_expression
#line 395 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1263 "mcc_c.tab.c"
    break;

  case 57: // logical_or_expression: logical_or_expression "&&" logical_and_expression
#line 397 "mcc_c.y"
                                                           {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1269 "mcc_c.tab.c"
    break;

  case 58: // conditional_expression: logical_or_expression
#line 403 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1275 "mcc_c.tab.c"
    break;

  case 59: // $@1: %empty
#line 404 "mcc_c.y"
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
#line 1292 "mcc_c.tab.c"
    break;

  case 60: // conditional_expression: logical_or_expression $@1 "?" expression ":" conditional_expression
#line 416 "mcc_c.y"
                                                  {yylhs.value.as < mcc::Symbol > ()=yystack_[5].value.as < mcc::Symbol > ();}
#line 1298 "mcc_c.tab.c"
    break;

  case 61: // assignment_expression: conditional_expression
#line 422 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1304 "mcc_c.tab.c"
    break;

  case 62: // $@2: %empty
#line 424 "mcc_c.y"
        {
		if(!yystack_[0].value.as < mcc::Symbol > ().IsLvalue()||yystack_[0].value.as < mcc::Symbol > ().IsConst())
		{mcc::PrintColored("Can only assign to a non-const lvalue",mcc::TextColor::Error);}
	}
#line 1313 "mcc_c.tab.c"
    break;

  case 63: // assignment_expression: unary_expression $@2 assignment_operator assignment_expression
#line 429 "mcc_c.y"
        {
		if(yystack_[3].value.as < mcc::Symbol > ().GetType().index()!=yystack_[0].value.as < mcc::Symbol > ().GetType().index())
		{
			mcc::PrintColored("Cant assign a non primitive to a primitive or vise-versa",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()=yystack_[3].value.as < mcc::Symbol > ();
	}
#line 1325 "mcc_c.tab.c"
    break;

  case 75: // expression: assignment_expression
#line 454 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({yystack_[0].value.as < mcc::Symbol > ().GetType(),yystack_[0].value.as < mcc::Symbol > ().GetIndLevel()},false,true,true);}
#line 1331 "mcc_c.tab.c"
    break;

  case 76: // expression: expression "," assignment_expression
#line 455 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1337 "mcc_c.tab.c"
    break;

  case 77: // constant_expression: conditional_expression
#line 459 "mcc_c.y"
                                {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1343 "mcc_c.tab.c"
    break;

  case 78: // declaration: declaration_specifiers ";"
#line 465 "mcc_c.y"
        {mcc::PrintColored("declaration does not declare anything",mcc::TextColor::Warning);}
#line 1349 "mcc_c.tab.c"
    break;

  case 79: // declaration: declaration_specifiers init_declarator_list ";"
#line 467 "mcc_c.y"
        {
		drv.UnsetCurrentType();
	}
#line 1357 "mcc_c.tab.c"
    break;

  case 80: // declaration_specifiers: storage_class_specifier
#line 474 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1366 "mcc_c.tab.c"
    break;

  case 81: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 479 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1374 "mcc_c.tab.c"
    break;

  case 82: // declaration_specifiers: type_specifier
#line 483 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1383 "mcc_c.tab.c"
    break;

  case 83: // declaration_specifiers: type_specifier declaration_specifiers
#line 488 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={yystack_[1].value.as < mcc::T > ()};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1392 "mcc_c.tab.c"
    break;

  case 84: // declaration_specifiers: type_qualifier
#line 493 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());}
#line 1400 "mcc_c.tab.c"
    break;

  case 85: // declaration_specifiers: type_qualifier declaration_specifiers
#line 497 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={yystack_[0].value.as < mcc::T > ()};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1409 "mcc_c.tab.c"
    break;

  case 86: // init_declarator_list: init_declarator
#line 505 "mcc_c.y"
        {drv.SetInConst(false);}
#line 1415 "mcc_c.tab.c"
    break;

  case 87: // init_declarator_list: init_declarator_list "," init_declarator
#line 506 "mcc_c.y"
          { yylhs.value.as < std::vector<mcc::Symbol> > () = yystack_[2].value.as < std::vector<mcc::Symbol> > (); }
#line 1421 "mcc_c.tab.c"
    break;

  case 88: // init_declarator: declarator
#line 511 "mcc_c.y"
        {
		auto sym = mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first,yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second);
	}
#line 1430 "mcc_c.tab.c"
    break;

  case 89: // init_declarator: declarator "=" initializer
#line 516 "mcc_c.y"
        {
		auto sym=mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().first,yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().second);
	}
#line 1439 "mcc_c.tab.c"
    break;

  case 95: // type_specifier: "void"
#line 531 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Void};}
#line 1445 "mcc_c.tab.c"
    break;

  case 96: // type_specifier: "char"
#line 532 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Char};}
#line 1451 "mcc_c.tab.c"
    break;

  case 97: // type_specifier: "short"
#line 533 "mcc_c.y"
                 {yylhs.value.as < mcc::T > ()={mcc::Primitive::Short};}
#line 1457 "mcc_c.tab.c"
    break;

  case 98: // type_specifier: "int"
#line 534 "mcc_c.y"
               {yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};}
#line 1463 "mcc_c.tab.c"
    break;

  case 99: // type_specifier: "long"
#line 535 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Long};}
#line 1469 "mcc_c.tab.c"
    break;

  case 100: // type_specifier: "float"
#line 536 "mcc_c.y"
                 {yylhs.value.as < mcc::T > ()={mcc::Primitive::Float};}
#line 1475 "mcc_c.tab.c"
    break;

  case 101: // type_specifier: "double"
#line 537 "mcc_c.y"
                  {yylhs.value.as < mcc::T > ()={mcc::Primitive::Double};}
#line 1481 "mcc_c.tab.c"
    break;

  case 102: // type_specifier: "signed"
#line 538 "mcc_c.y"
                   {yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};}
#line 1487 "mcc_c.tab.c"
    break;

  case 103: // type_specifier: "unsigned"
#line 539 "mcc_c.y"
                    {yylhs.value.as < mcc::T > ()={mcc::Primitive::UInt};}
#line 1493 "mcc_c.tab.c"
    break;

  case 104: // type_specifier: struct_or_union_specifier
#line 540 "mcc_c.y"
                                   {}
#line 1499 "mcc_c.tab.c"
    break;

  case 105: // type_specifier: enum_specifier
#line 541 "mcc_c.y"
                        {}
#line 1505 "mcc_c.tab.c"
    break;

  case 106: // type_specifier: "typename"
#line 543 "mcc_c.y"
                {
			yylhs.value.as < mcc::T > () = drv.GetType(yystack_[0].value.as < std::string > ()).value();
		}
#line 1513 "mcc_c.tab.c"
    break;

  case 115: // specifier_qualifier_list: type_specifier specifier_qualifier_list
#line 568 "mcc_c.y"
        {
		if(std::holds_alternative<mcc::NoneType>(yystack_[1].value.as < mcc::T > ().GetType())^std::holds_alternative<mcc::NoneType>(yystack_[0].value.as < mcc::T > ().GetType()))
		{
			yylhs.value.as < mcc::T > ()=yystack_[1].value.as < mcc::T > ();
		}
		else
		{
			mcc::PrintColored("Invalid type",mcc::TextColor::Error);
			yylhs.value.as < mcc::T > ()={mcc::Primitive::Void};
		}
	}
#line 1529 "mcc_c.tab.c"
    break;

  case 116: // specifier_qualifier_list: type_specifier
#line 580 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();}
#line 1535 "mcc_c.tab.c"
    break;

  case 117: // specifier_qualifier_list: type_qualifier specifier_qualifier_list
#line 582 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();}
#line 1541 "mcc_c.tab.c"
    break;

  case 118: // specifier_qualifier_list: type_qualifier
#line 584 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()={true};}
#line 1547 "mcc_c.tab.c"
    break;

  case 131: // type_qualifier: "const"
#line 614 "mcc_c.y"
                 {yylhs.value.as < std::string > ()="const";drv.SetInConst(true);}
#line 1553 "mcc_c.tab.c"
    break;

  case 132: // type_qualifier: "volatile"
#line 615 "mcc_c.y"
                    {yylhs.value.as < std::string > ()="";}
#line 1559 "mcc_c.tab.c"
    break;

  case 133: // declarator: pointer direct_declarator
#line 620 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1567 "mcc_c.tab.c"
    break;

  case 134: // declarator: direct_declarator
#line 624 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1575 "mcc_c.tab.c"
    break;

  case 135: // id_or_idptr: "identifier"
#line 630 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[0].value.as < std::string > (),{drv.GetCurrentType(),drv.GetInConst(),true,true}};
		//symbol has no indirection, i.e. int arr[] - array of int
	}
#line 1584 "mcc_c.tab.c"
    break;

  case 136: // id_or_idptr: "(" "identifier" ")"
#line 636 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::string > (),{drv.GetCurrentType(),drv.GetInConst(),true,true}};
	}
#line 1592 "mcc_c.tab.c"
    break;

  case 137: // id_or_idptr: "(" pointer "identifier" ")"
#line 642 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::string > (),{{drv.GetCurrentType().GetType(),yystack_[2].value.as < mcc::PtrBits > ().GetIndirection()},drv.GetInConst(),true,true}};
	//symbol HAS indirection, i.e int (*arr)[] - POINTER to an array of int
	}
#line 1601 "mcc_c.tab.c"
    break;

  case 138: // array_dim: "[" constant_expression "]"
#line 648 "mcc_c.y"
        {
		yylhs.value.as < std::size_t > ()=1;
	}
#line 1609 "mcc_c.tab.c"
    break;

  case 139: // array_dim: "[" "]"
#line 652 "mcc_c.y"
        {
		yylhs.value.as < std::size_t > ()=0;
	}
#line 1617 "mcc_c.tab.c"
    break;

  case 140: // array_dim_list: array_dim
#line 658 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::size_t> > ()={};
		yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ());
	}
#line 1626 "mcc_c.tab.c"
    break;

  case 141: // array_dim_list: array_dim_list array_dim
#line 663 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::size_t> > ()=yystack_[1].value.as < std::vector<std::size_t> > ();
		yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ());
	}
#line 1635 "mcc_c.tab.c"
    break;

  case 142: // direct_declarator: id_or_idptr
#line 671 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1643 "mcc_c.tab.c"
    break;

  case 143: // direct_declarator: id_or_idptr array_dim_list
#line 676 "mcc_c.y"
        {
		auto as_arr_t = mcc::T{yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetType()}.ToArrT();
		drv.AddSymbol(yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{mcc::CArray{as_arr_t,yystack_[0].value.as < std::vector<std::size_t> > ().begin(),yystack_[0].value.as < std::vector<std::size_t> > ().end()},yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetIndLevel()},drv.GetInConst(),true,false});
		mcc::PrintColored("Array:",mcc::TextColor::Good);
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{mcc::CArray{as_arr_t,yystack_[0].value.as < std::vector<std::size_t> > ().begin(),yystack_[0].value.as < std::vector<std::size_t> > ().end()},yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetIndLevel()},drv.GetInConst(),true,false}};
	}
#line 1654 "mcc_c.tab.c"
    break;

  case 144: // direct_declarator: id_or_idptr "(" parameter_type_list ")"
#line 683 "mcc_c.y"
        {
		std::vector<mcc::T> param_types;
		std::transform(yystack_[1].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().begin(),yystack_[1].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().end(),std::back_inserter(param_types),[](auto&&arg)
			{
				return arg.second.GetType();
			});
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
		for(auto && param: yystack_[1].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ())
		{
			mcc::PrintColored("Param: "+param.first+'\n',mcc::TextColor::Warning);
		}
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[3].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{std::make_shared<mcc::Func>(param_types),0},drv.GetInConst(),true,false}};
	}
#line 1672 "mcc_c.tab.c"
    break;

  case 145: // direct_declarator: id_or_idptr "(" ")"
#line 697 "mcc_c.y"
        {
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{std::make_shared<mcc::Func>(std::vector<mcc::T>{}),0},drv.GetInConst(),true,false}};
	}
#line 1681 "mcc_c.tab.c"
    break;

  case 146: // pointer: "*"
#line 704 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1690 "mcc_c.tab.c"
    break;

  case 147: // pointer: "*" type_qualifier_list
#line 709 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[0].value.as < std::string > ()=="const");
	}
#line 1699 "mcc_c.tab.c"
    break;

  case 148: // pointer: "*" pointer
#line 714 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1708 "mcc_c.tab.c"
    break;

  case 149: // pointer: "*" type_qualifier_list pointer
#line 719 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[1].value.as < std::string > ()=="const");
	}
#line 1717 "mcc_c.tab.c"
    break;

  case 150: // type_qualifier_list: type_qualifier
#line 728 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 1723 "mcc_c.tab.c"
    break;

  case 151: // type_qualifier_list: type_qualifier_list type_qualifier
#line 730 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ()+yystack_[0].value.as < std::string > ();}
#line 1729 "mcc_c.tab.c"
    break;

  case 152: // parameter_type_list: parameter_list
#line 736 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();
	}
#line 1737 "mcc_c.tab.c"
    break;

  case 153: // parameter_type_list: parameter_list "," "..."
#line 740 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[2].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();}
#line 1743 "mcc_c.tab.c"
    break;

  case 154: // parameter_list: parameter_declaration
#line 745 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();}
#line 1749 "mcc_c.tab.c"
    break;

  case 155: // parameter_list: parameter_list "," parameter_declaration
#line 747 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[2].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();
	yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().push_back(yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()[0]);}
#line 1756 "mcc_c.tab.c"
    break;

  case 156: // parameter_declaration: declaration_specifiers declarator
#line 753 "mcc_c.y"
        {
			auto decl = yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second;
			yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()={};
			yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().push_back({yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first,{yystack_[1].value.as < mcc::T > (),drv.GetInConst(),true,true}});
	}
#line 1766 "mcc_c.tab.c"
    break;

  case 157: // type_name: specifier_qualifier_list
#line 762 "mcc_c.y"
          { yylhs.value.as < mcc::T > () = yystack_[0].value.as < mcc::T > (); }
#line 1772 "mcc_c.tab.c"
    break;

  case 158: // type_name: specifier_qualifier_list abstract_declarator
#line 763 "mcc_c.y"
          { yylhs.value.as < mcc::T > () = yystack_[1].value.as < mcc::T > (); }
#line 1778 "mcc_c.tab.c"
    break;

  case 177: // $@3: %empty
#line 797 "mcc_c.y"
          {drv.EnterNewScope("");}
#line 1784 "mcc_c.tab.c"
    break;

  case 178: // statement: $@3 compound_statement
#line 799 "mcc_c.y"
                {drv.LeaveScope();}
#line 1790 "mcc_c.tab.c"
    break;

  case 184: // labeled_statement: "identifier" ":" statement
#line 810 "mcc_c.y"
        {
		drv.AddLabel(yystack_[2].value.as < std::string > ());
	}
#line 1798 "mcc_c.tab.c"
    break;

  case 196: // $@4: %empty
#line 839 "mcc_c.y"
                                 {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1804 "mcc_c.tab.c"
    break;

  case 198: // $@5: %empty
#line 840 "mcc_c.y"
                                                {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1810 "mcc_c.tab.c"
    break;

  case 200: // iteration_statement: "for" "(" expression_statement expression_statement ")" statement
#line 843 "mcc_c.y"
        {std::cout<<"param decl\n";}
#line 1816 "mcc_c.tab.c"
    break;

  case 202: // jump_statement: "goto" "identifier" ";"
#line 849 "mcc_c.y"
        {
		drv.AddLabelRef(yystack_[1].value.as < std::string > ());
	}
#line 1824 "mcc_c.tab.c"
    break;

  case 210: // external_declaration: declaration
#line 866 "mcc_c.y"
        {mcc::PrintColored("New global definition",mcc::TextColor::Good);}
#line 1830 "mcc_c.tab.c"
    break;

  case 211: // $@6: %empty
#line 871 "mcc_c.y"
                {
			if(mcc::IsFuncPtr(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second))
			{
				auto func = std::get<std::shared_ptr<mcc::Func>>(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetType());
				func->SetReturnType(yystack_[1].value.as < mcc::T > ());
				drv.AddSymbol(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{func,0},drv.GetInConst(),true,false});
			}
			else
			{
				mcc::PrintColored("Is not a valid function declaration",mcc::TextColor::Error);
			}
			drv.EnterNewScope(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first);
		}
#line 1848 "mcc_c.tab.c"
    break;

  case 212: // function_definition: declaration_specifiers direct_declarator $@6 compound_statement
#line 885 "mcc_c.y"
                {
					drv.LeaveScope();
		}
#line 1856 "mcc_c.tab.c"
    break;

  case 213: // $@7: %empty
#line 889 "mcc_c.y"
                {
			if(mcc::IsFuncPtr(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second))
			{
				drv.EnterNewScope(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first);
			}
			else
			{
				mcc::PrintColored("Is not a valid function declaration",mcc::TextColor::Error);
			}
		}
#line 1871 "mcc_c.tab.c"
    break;

  case 214: // function_definition: direct_declarator $@7 compound_statement
#line 900 "mcc_c.y"
                {drv.LeaveScope();}
#line 1877 "mcc_c.tab.c"
    break;


#line 1881 "mcc_c.tab.c"

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
  "type_qualifier", "declarator", "id_or_idptr", "array_dim",
  "array_dim_list", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "$@3",
  "labeled_statement", "compound_statement", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "$@4", "$@5", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "$@6", "$@7", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -244;

  const short parser::yytable_ninf_ = -212;

  const short
  parser::yypact_[] =
  {
    1017,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
      10,  -244,    26,  -244,     6,  1222,  1222,  -244,    11,  -244,
    1222,    66,  -244,   856,  -244,  -244,   -32,    60,    25,    -1,
      79,  -244,   101,  -244,    67,    87,     8,  -244,  -244,    95,
    1248,  -244,  1074,   588,  -244,   105,   111,  -244,  -244,    60,
     125,   -31,  -244,  -244,  -244,  -244,    -1,   132,  -244,    18,
     611,   111,  -244,  1248,  1248,  1142,  -244,    12,  1248,  -244,
      18,   149,   138,  -244,  -244,  -244,  -244,   751,  -244,  -244,
    -244,  -244,  -244,  -244,   547,  -244,   775,   775,  -244,   158,
    -244,   790,  -244,    44,    55,    84,    77,   -14,   170,   178,
     176,   150,    99,  -244,   166,  -244,   292,  -244,   -26,   790,
    -244,    60,  -244,  -244,  -244,  -244,  -244,   611,  1259,  -244,
    -244,  -244,  -244,  1179,  -244,  -244,  -244,   790,   109,  -244,
     162,  -244,  -244,  -244,   913,   547,  -244,  -244,   -36,   -21,
     181,   790,  -244,  -244,   649,   243,   790,  -244,  -244,   245,
    -244,   790,   790,   790,   790,   790,   790,   790,   790,   790,
     790,   790,   790,   790,   790,   790,   790,   790,   790,   164,
    -244,   173,   790,   174,   192,   193,   195,   442,   196,   259,
     186,   187,   189,  -244,  -244,   112,  -244,     6,  -244,   111,
    -244,   367,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
      28,  1269,  -244,  -244,  -244,    12,   790,  -244,  -244,   201,
    -244,   790,   955,   675,    78,  -244,    80,   790,  -244,   -25,
    -244,  -244,   -42,  -244,  -244,  -244,  -244,    44,    44,    55,
      55,    84,    84,    84,    84,    77,    77,   -14,   170,   178,
     176,   150,   790,   442,   188,   442,   790,   790,   790,   239,
     477,   197,  -244,  -244,  -244,   126,  -244,  -244,  -244,  -244,
    -244,   570,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,   790,  -244,  -244,  -244,  -244,  -244,   208,
     209,  -244,   206,    80,  1116,   690,  -244,  -244,   790,  -244,
     121,  -244,   442,  -244,    15,    20,   198,   213,   477,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,   214,  -244,
     210,  -244,   790,  -244,   442,   442,   216,   790,   713,  -244,
    -244,  -244,   255,  -244,   442,   198,   442,    29,   442,  -244,
     218,  -244,   442,  -244,   207,  -244,  -244
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   135,    90,    91,    92,    93,    94,    96,    97,    99,
     102,   103,   100,   101,   131,   132,    95,    98,   110,   111,
       0,   106,     0,   210,     0,    80,    82,   104,     0,   105,
      84,   142,   213,     0,   207,   209,   126,     0,     0,   146,
       0,    78,     0,    86,    88,   134,     0,    81,    83,   109,
       0,    85,     0,     0,   140,   143,     0,     1,   208,     0,
     129,     0,   127,   136,   150,   148,   147,     0,    79,     0,
       0,     0,   133,     0,   116,     0,   112,     0,   118,   145,
       0,     0,   152,   154,     2,     3,     4,     0,    22,    25,
      23,    24,    27,    26,     0,   139,     0,     0,     6,    16,
      28,     0,    30,    34,    37,    40,    45,    48,    50,    52,
      54,    56,    58,    77,     0,   141,   177,   214,     0,     0,
     124,     0,   151,   149,   137,    87,   134,     0,    28,    61,
     171,    89,   212,     0,   115,   108,   113,     0,     0,   119,
     121,   117,   156,   144,     0,     0,    20,    75,     0,   157,
       0,     0,    17,    18,     0,     0,     0,    12,    13,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     2,     0,     0,     0,     0,     0,   177,     0,     0,
       0,     0,     0,   188,   191,     0,   183,     0,   189,     0,
     176,   177,   179,   180,   181,   182,   125,   130,   128,   174,
       0,     0,   107,   122,   114,     0,     0,   153,   155,     0,
       5,     0,     0,     0,   159,   158,   160,     0,     8,     0,
      14,    11,     0,    10,    31,    32,    33,    35,    36,    38,
      39,    42,    41,    43,    44,    46,    47,    49,    51,    53,
      55,    57,     0,   177,     0,   177,     0,     0,     0,     0,
       0,     0,   203,   204,   205,     0,   192,   178,   187,   190,
     172,     0,    66,    67,    65,    69,    68,    70,    71,    72,
      73,    74,    64,     0,   120,   123,    21,    76,   167,     0,
       0,   163,     0,   161,     0,     0,    29,     9,     0,     7,
       0,   184,   177,   186,     0,     0,   196,     0,     0,   202,
     206,   173,   175,    63,   168,   162,   164,   169,     0,   165,
       0,    15,     0,   185,   177,   177,     0,     0,     0,   170,
     166,    60,   193,   195,   177,   198,   177,     0,   177,   197,
       0,   200,   177,   194,     0,   201,   199
  };

  const short
  parser::yypgoto_[] =
  {
    -244,  -244,  -244,  -244,   -52,  -244,   -89,    47,    53,    39,
      52,   113,   108,   110,   114,   107,  -244,   -51,  -244,   -67,
    -244,  -244,   -90,   -81,    57,     0,  -244,   219,  -244,    82,
    -244,  -244,   217,   -53,   -54,  -244,    74,  -244,   233,   172,
     124,   -70,  -244,   263,  -244,   104,   -16,  -244,  -206,  -244,
     190,   185,   115,   117,  -122,  -244,  -155,  -244,  -244,   -63,
    -244,  -243,  -244,  -244,  -244,  -244,  -244,  -244,   298,  -244,
    -244,  -244
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    98,    99,   229,   128,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   129,   179,   147,
     211,   283,   195,   114,   196,   197,    42,    43,    25,    26,
      27,    28,    75,    76,    77,   138,   139,    29,    61,    62,
      30,    44,    31,    54,    55,   126,    46,    66,    81,    82,
      83,   150,   225,   226,   131,   210,   198,   199,   200,   117,
     201,   202,   203,   204,   326,   340,   205,    33,    34,    35,
      71,    56
  };

  const short
  parser::yytable_[] =
  {
      24,   100,   113,   130,   148,   209,    40,   140,   132,     1,
     142,     1,   160,    36,    49,     1,   289,   308,    14,    15,
     134,     1,   136,    65,   141,    47,    48,   299,   220,    38,
      51,    39,   259,    24,    59,   146,   120,   221,   207,   297,
     149,   206,   222,   221,   152,   153,   269,   223,   121,   100,
     123,    39,    80,   121,   298,   148,   213,    23,    39,   172,
     130,   148,   173,    60,    39,   328,   232,   100,   113,    22,
      39,    22,   234,   235,   236,    22,    37,    50,    39,   324,
     136,    22,    67,    41,   325,   100,   113,   230,   318,    63,
      23,   149,   137,   342,   221,   270,   161,   162,   301,   221,
     303,   254,   265,   163,    32,   164,   165,   271,   221,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,    70,    45,    52,
     100,   113,    74,   224,    53,   285,   267,    32,   296,   166,
     167,   222,   292,   294,    80,   140,   223,   323,   295,   312,
      72,   168,   169,  -211,   287,    74,    74,    74,   170,   171,
      74,    73,   300,    64,   100,   113,   304,   305,   306,   332,
     333,   100,   113,    53,    78,   100,    74,   116,    68,   339,
      69,   341,   178,   343,   -59,   119,   214,   345,   215,   266,
     122,   221,    84,    85,    86,    87,   124,    78,    78,    78,
     221,   322,    78,   310,   130,   221,   224,   241,   242,   243,
     244,   237,   238,   143,   320,    74,   313,   144,    78,   239,
     240,   154,    80,   155,   245,   246,   156,    74,   174,   157,
     158,   321,   175,   176,   177,   180,   159,   335,   337,    88,
      89,    90,   216,   100,   113,   227,   231,    91,   233,   252,
      92,    93,    94,   253,   255,   256,   257,    78,   258,   260,
      96,    97,   261,   262,   263,   286,   264,   307,   302,    78,
     100,   331,   314,   315,   309,   316,   327,   221,   329,   330,
     334,   338,   344,   248,   346,   251,   249,   247,   125,   284,
     133,   250,   118,   208,    80,   181,    85,    86,    87,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   182,   183,   184,    17,   115,   185,
     186,   187,   188,   189,   190,   191,   192,    18,    19,    20,
     219,    58,     0,     0,   218,     0,     0,   290,     0,     0,
      21,   293,    88,    89,    90,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,    94,     0,     0,     0,   193,
       0,     0,     0,    96,    97,     0,     0,     0,     0,   194,
     181,    85,    86,    87,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   182,
     183,   184,    17,     0,   185,   186,   187,   188,   189,   190,
     191,   192,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    88,    89,    90,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
      94,     0,     0,     0,   268,     0,     0,     0,    96,    97,
       0,     0,     0,     0,   194,   181,    85,    86,    87,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   182,   183,   184,    17,     0,   185,
     186,   187,   188,   189,   190,   191,   192,    18,    19,    20,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      21,     0,    88,    89,    90,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      84,    85,    86,    87,   194,     0,     0,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,    17,    84,    85,    86,    87,     0,     0,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    21,     0,    88,    89,    90,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
      94,     0,     0,     0,    84,    85,    86,    87,    96,    97,
      88,    89,    90,     0,     0,     0,     0,     0,    91,     0,
       0,    92,    93,    94,     0,     0,   127,   311,    88,    89,
      90,    96,    97,     0,     0,     0,    91,     0,     0,    92,
      93,    94,    84,    85,    86,    87,     0,    95,     0,    96,
      97,    88,    89,    90,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,    94,     0,     0,   127,    84,    85,
      86,    87,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,    87,     0,     0,    88,
      89,    90,     0,     0,     0,     0,     0,    91,     0,     0,
      92,    93,    94,   228,     0,     0,    84,    85,    86,    87,
      96,    97,     0,     0,     0,    88,    89,    90,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,    94,     0,
      88,    89,    90,     0,   291,     0,    96,    97,    91,     0,
       0,    92,    93,    94,    84,    85,    86,    87,     0,   319,
       0,    96,    97,    88,    89,    90,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,    94,   336,    84,    85,
      86,    87,     0,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,    87,     0,     0,     0,
       0,    88,    89,    90,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,   145,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    88,    89,    90,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,   151,     0,
      88,    89,    90,     0,     0,     0,    96,    97,    91,     0,
       0,    92,    93,    94,     0,     0,    57,     0,     0,     1,
       0,    96,    97,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,     0,
      17,     0,     0,   217,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   288,
       1,     0,     0,   223,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    79,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    21,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
     317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,     0,    17,     0,     0,     0,     0,   135,
       0,     0,     0,     0,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,   212,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      21,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,   -62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282
  };

  const short
  parser::yycheck_[] =
  {
       0,    53,    53,    70,    94,   127,    22,    77,    71,     3,
      80,     3,   101,     3,     3,     3,   222,   260,    19,    20,
      74,     3,    75,    39,    78,    25,    26,    69,    64,     3,
      30,    52,   187,    33,    66,    87,    67,    79,   119,    64,
      94,    67,    63,    79,    96,    97,   201,    68,    79,   101,
      66,    52,    52,    79,    79,   145,   137,     0,    52,    73,
     127,   151,    76,     3,    52,   308,   156,   119,   119,    63,
      52,    63,   161,   162,   163,    63,    66,    66,    52,    64,
     133,    63,     3,    77,    64,   137,   137,   154,   294,    64,
      33,   145,    80,    64,    79,    67,    52,    53,   253,    79,
     255,   182,   192,    59,     0,    50,    51,    79,    79,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    60,    24,    63,
     182,   182,    50,   149,    68,   216,   199,    33,   227,    55,
      56,    63,   223,    63,   144,   215,    68,   302,    68,   271,
      46,    74,    75,    66,   221,    73,    74,    75,    81,    82,
      78,    66,   252,    39,   216,   216,   256,   257,   258,   324,
     325,   223,   223,    68,    50,   227,    94,    66,    77,   334,
      79,   336,    83,   338,    85,    60,    77,   342,    79,    77,
      66,    79,     3,     4,     5,     6,    64,    73,    74,    75,
      79,    80,    78,    77,   271,    79,   222,   168,   169,   170,
     171,   164,   165,    64,   295,   133,   283,    79,    94,   166,
     167,    63,   222,    65,   172,   173,    68,   145,    58,    71,
      72,   298,    54,    57,    84,    69,    78,   327,   328,    50,
      51,    52,    80,   295,   295,    64,     3,    58,     3,    85,
      61,    62,    63,    80,    80,    63,    63,   133,    63,    63,
      71,    72,     3,    77,    77,    64,    77,    28,    80,   145,
     322,   322,    64,    64,    77,    69,    63,    79,    64,    69,
      64,    26,    64,   175,    77,   178,   176,   174,    69,   215,
      73,   177,    59,   121,   294,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    55,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     145,    33,    -1,    -1,   144,    -1,    -1,   222,    -1,    -1,
      48,   224,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      -1,    -1,    -1,    -1,    77,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
       3,     4,     5,     6,    77,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    48,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,     3,     4,     5,     6,    71,    72,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    -1,    -1,    66,    67,    50,    51,
      52,    71,    72,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,     3,     4,     5,     6,    -1,    69,    -1,    71,
      72,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,    -1,    -1,    66,     3,     4,
       5,     6,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,     3,     4,     5,     6,
      71,    72,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,
      50,    51,    52,    -1,    69,    -1,    71,    72,    58,    -1,
      -1,    61,    62,    63,     3,     4,     5,     6,    -1,    69,
      -1,    71,    72,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    62,    63,    64,     3,     4,
       5,     6,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,
      50,    51,    52,    -1,    -1,    -1,    71,    72,    58,    -1,
      -1,    61,    62,    63,    -1,    -1,     0,    -1,    -1,     3,
      -1,    71,    72,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
       3,    -1,    -1,    68,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    64,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    48,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    67,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      48,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    25,    35,    36,
      37,    48,    63,   110,   111,   114,   115,   116,   117,   123,
     126,   128,   131,   153,   154,   155,     3,    66,     3,    52,
     132,    77,   112,   113,   127,   131,   132,   111,   111,     3,
      66,   111,    63,    68,   129,   130,   157,     0,   154,    66,
       3,   124,   125,    64,   126,   132,   133,     3,    77,    79,
      60,   156,   131,    66,   115,   118,   119,   120,   126,    64,
     111,   134,   135,   136,     3,     4,     5,     6,    50,    51,
      52,    58,    61,    62,    63,    69,    71,    72,    87,    88,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   109,   129,    66,   145,   124,    60,
      67,    79,   126,   132,    64,   113,   131,    66,    90,   103,
     105,   140,   145,   118,   120,    67,   119,    80,   121,   122,
     127,   120,   127,    64,    79,    63,    90,   105,   108,   120,
     137,    63,    90,    90,    63,    65,    68,    71,    72,    78,
      92,    52,    53,    59,    50,    51,    55,    56,    74,    75,
      81,    82,    73,    76,    58,    54,    57,    84,    83,   104,
      69,     3,    22,    23,    24,    27,    28,    29,    30,    31,
      32,    33,    34,    67,    77,   108,   110,   111,   142,   143,
     144,   146,   147,   148,   149,   152,    67,   109,   125,   140,
     141,   106,    67,   109,    77,    79,    80,    70,   136,   137,
      64,    79,    63,    68,   132,   138,   139,    64,    64,    89,
     105,     3,   108,     3,    92,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    96,    96,    97,    98,    99,
     100,   101,    85,    80,   109,    80,    63,    63,    63,   142,
      63,     3,    77,    77,    77,   108,    77,   145,    67,   142,
      67,    79,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    60,   107,   122,   109,    64,   105,    64,   134,
     138,    69,   109,   139,    63,    68,    92,    64,    79,    69,
     108,   142,    80,   142,   108,   108,   108,    28,   147,    77,
      77,    67,   140,   105,    64,    64,    69,    64,   134,    69,
     109,   105,    80,   142,    64,    64,   150,    63,   147,    64,
      69,   103,   142,   142,    64,   108,    64,   108,    26,   142,
     151,   142,    64,   142,    64,   142,    77
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
     125,   126,   126,   127,   127,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   132,   132,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   137,   137,   138,
     138,   138,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   140,   140,   140,   141,   141,   142,   143,   142,   142,
     142,   142,   142,   142,   144,   144,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   148,   150,   149,   151,   149,
     149,   149,   152,   152,   152,   152,   152,   153,   153,   154,
     154,   156,   155,   157,   155
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
       3,     1,     1,     2,     1,     1,     3,     4,     3,     2,
       1,     2,     1,     2,     4,     3,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     2,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     3,     4,     3,     3,     2,     1,
       2,     1,     2,     5,     7,     5,     0,     6,     0,     8,
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     0,     4,     0,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   145,   145,   165,   169,   173,   180,   184,   209,   231,
     254,   256,   258,   260,   265,   267,   275,   277,   279,   281,
     283,   285,   291,   292,   293,   294,   295,   296,   300,   302,
     307,   309,   311,   313,   319,   322,   324,   329,   332,   334,
     339,   342,   344,   346,   348,   353,   356,   358,   363,   366,
     371,   374,   379,   382,   386,   389,   394,   397,   402,   404,
     404,   421,   424,   423,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   453,   455,   459,   464,   466,
     473,   478,   482,   487,   492,   496,   504,   506,   510,   515,
     523,   524,   525,   526,   527,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   548,   549,   550,
     553,   554,   558,   559,   563,   567,   579,   581,   583,   588,
     589,   593,   594,   595,   599,   600,   601,   605,   606,   610,
     611,   614,   615,   619,   623,   629,   635,   641,   647,   651,
     657,   662,   669,   675,   682,   696,   703,   708,   713,   718,
     727,   729,   735,   739,   744,   746,   752,   762,   763,   767,
     768,   769,   773,   774,   775,   776,   777,   778,   779,   780,
     781,   785,   786,   787,   791,   792,   796,   797,   797,   800,
     801,   802,   803,   804,   809,   813,   814,   819,   820,   824,
     825,   828,   829,   833,   834,   835,   839,   839,   840,   840,
     841,   844,   848,   852,   853,   854,   855,   859,   860,   864,
     865,   871,   870,   889,   888
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
#line 2905 "mcc_c.tab.c"

#line 902 "mcc_c.y"

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
