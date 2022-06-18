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
#line 139 "mcc_c.y"

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
      case symbol_kind::S_bitwise_logical_expression: // bitwise_logical_expression
      case symbol_kind::S_logical_expression: // logical_expression
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
      case symbol_kind::S_unary_operator: // unary_operator
      case symbol_kind::S_bitwise_logical_operator: // bitwise_logical_operator
      case symbol_kind::S_logical_binary_operator: // logical_binary_operator
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
      case symbol_kind::S_bitwise_logical_expression: // bitwise_logical_expression
      case symbol_kind::S_logical_expression: // logical_expression
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
      case symbol_kind::S_unary_operator: // unary_operator
      case symbol_kind::S_bitwise_logical_operator: // bitwise_logical_operator
      case symbol_kind::S_logical_binary_operator: // logical_binary_operator
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
      case symbol_kind::S_bitwise_logical_expression: // bitwise_logical_expression
      case symbol_kind::S_logical_expression: // logical_expression
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
      case symbol_kind::S_unary_operator: // unary_operator
      case symbol_kind::S_bitwise_logical_operator: // bitwise_logical_operator
      case symbol_kind::S_logical_binary_operator: // logical_binary_operator
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
      case symbol_kind::S_bitwise_logical_expression: // bitwise_logical_expression
      case symbol_kind::S_logical_expression: // logical_expression
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
      case symbol_kind::S_unary_operator: // unary_operator
      case symbol_kind::S_bitwise_logical_operator: // bitwise_logical_operator
      case symbol_kind::S_logical_binary_operator: // logical_binary_operator
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
      case symbol_kind::S_bitwise_logical_expression: // bitwise_logical_expression
      case symbol_kind::S_logical_expression: // logical_expression
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
      case symbol_kind::S_unary_operator: // unary_operator
      case symbol_kind::S_bitwise_logical_operator: // bitwise_logical_operator
      case symbol_kind::S_logical_binary_operator: // logical_binary_operator
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
#line 147 "mcc_c.y"
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
#line 167 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 908 "mcc_c.tab.c"
    break;

  case 4: // primary_expression: "literal"
#line 171 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 916 "mcc_c.tab.c"
    break;

  case 5: // primary_expression: "(" expression ")"
#line 175 "mcc_c.y"
        {
	yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ();
	}
#line 924 "mcc_c.tab.c"
    break;

  case 6: // postfix_expression: primary_expression
#line 182 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 932 "mcc_c.tab.c"
    break;

  case 7: // postfix_expression: postfix_expression "[" expression "]"
#line 186 "mcc_c.y"
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
			yylhs.value.as < mcc::Symbol > ()={{yystack_[3].value.as < mcc::Symbol > ().GetType(),yystack_[3].value.as < mcc::Symbol > ().GetDeref()},yystack_[3].value.as < mcc::Symbol > ().DerefIsConst(),true,true};
					}
		else if(std::holds_alternative<mcc::CArray>(yystack_[3].value.as < mcc::Symbol > ().GetType()))
		{
			auto arr_t = std::get<mcc::CArray>(yystack_[3].value.as < mcc::Symbol > ().GetType());
			auto deref_t = arr_t.GetDerefT();
			yylhs.value.as < mcc::Symbol > ()={{deref_t},true,true,true};
			mcc::PrintColored(std::to_string(yylhs.value.as < mcc::Symbol > ().IsLvalue()),mcc::TextColor::Error);
					}
		else
		{
			mcc::PrintColored("Cannot apply subscript operator to a non pointer value",mcc::TextColor::Error);
		}
	}
#line 962 "mcc_c.tab.c"
    break;

  case 8: // postfix_expression: postfix_expression "(" ")"
#line 212 "mcc_c.y"
        {
		if(mcc::IsFuncPtr(yystack_[2].value.as < mcc::Symbol > ()))
		{
			if(!yystack_[2].value.as < mcc::Symbol > ().IsDefined())
			{
				mcc::PrintColored("Function is declared,but not defined",mcc::TextColor::Warning);
			}
			const auto ftype = std::get<std::shared_ptr<mcc::Func>>(yystack_[2].value.as < mcc::Symbol > ().GetType());
			auto & fargs = ftype->GetArgs();
			if (fargs.size())
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
#line 992 "mcc_c.tab.c"
    break;

  case 9: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 238 "mcc_c.y"
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
			{
				if(std::equal(fargs.begin(),fargs.end(),yystack_[1].value.as < std::vector<mcc::Symbol> > ().begin(),yystack_[1].value.as < std::vector<mcc::Symbol> > ().end(),[](auto&&l,auto&&r)
				{
					return l==r.GetType();
				}))
				yylhs.value.as < mcc::Symbol > ()={ftype->GetReturnType(),false,true,false};
				else {
					yylhs.value.as < mcc::Symbol > ()={};
					mcc::PrintColored("Wrong func arg types",mcc::TextColor::Error);
				}
			}
		}
		else
		{
			mcc::PrintColored("Is not a function",mcc::TextColor::Error);
			yylhs.value.as < mcc::Symbol > ()={};
		}
	}
#line 1029 "mcc_c.tab.c"
    break;

  case 10: // postfix_expression: postfix_expression "." "identifier"
#line 271 "mcc_c.y"
        {
		mcc::PrintColored("Non ptr struct or union field access",mcc::TextColor::Good);
	}
#line 1037 "mcc_c.tab.c"
    break;

  case 11: // postfix_expression: postfix_expression "->" "identifier"
#line 275 "mcc_c.y"
        {
		auto t = yystack_[2].value.as < mcc::Symbol > ().GetType();
		if(!yystack_[2].value.as < mcc::Symbol > ().IsUserType()&&!yystack_[2].value.as < mcc::Symbol > ().IsPtr())
		{
			mcc::PrintColored("Cannot apply ++ operator to a non-lvalue",mcc::TextColor::Error);
		}
		mcc::PrintColored("Ptr struct or union field access",mcc::TextColor::Good);
	}
#line 1050 "mcc_c.tab.c"
    break;

  case 12: // postfix_expression: postfix_expression "++"
#line 284 "mcc_c.y"
        {
		if(!yystack_[1].value.as < mcc::Symbol > ().IsLvalue())
		{
					mcc::PrintColored("Cannot apply ++ operator to a non-lvalue",mcc::TextColor::Error);
		}

		yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ().GetRvalue();
		mcc::PrintColored("Postfix increment",mcc::TextColor::Good);
	}
#line 1064 "mcc_c.tab.c"
    break;

  case 13: // postfix_expression: postfix_expression "--"
#line 294 "mcc_c.y"
        {
		if(!yystack_[1].value.as < mcc::Symbol > ().IsLvalue())
		{
			mcc::PrintColored("Cannot apply -- operator to a non-lvalue",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ().GetRvalue();
		mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);
	}
#line 1077 "mcc_c.tab.c"
    break;

  case 14: // argument_expression_list: assignment_expression
#line 306 "mcc_c.y"
                {yylhs.value.as < std::vector<mcc::Symbol> > ()={};yylhs.value.as < std::vector<mcc::Symbol> > ().push_back(yystack_[0].value.as < mcc::Symbol > ());}
#line 1083 "mcc_c.tab.c"
    break;

  case 15: // argument_expression_list: argument_expression_list "," assignment_expression
#line 308 "mcc_c.y"
        {
		yylhs.value.as < std::vector<mcc::Symbol> > ()=yystack_[2].value.as < std::vector<mcc::Symbol> > ();
		yylhs.value.as < std::vector<mcc::Symbol> > ().push_back(yystack_[0].value.as < mcc::Symbol > ());
	}
#line 1092 "mcc_c.tab.c"
    break;

  case 16: // unary_expression: postfix_expression
#line 316 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 1100 "mcc_c.tab.c"
    break;

  case 17: // unary_expression: "++" unary_expression
#line 320 "mcc_c.y"
        {
		if(!yystack_[0].value.as < mcc::Symbol > ().IsLvalue())
		{
			mcc::PrintColored("Cannot apply ++ operator to a non-lvalue",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ().GetRvalue();
	}
#line 1112 "mcc_c.tab.c"
    break;

  case 18: // unary_expression: "--" unary_expression
#line 328 "mcc_c.y"
        {
		if(!yystack_[0].value.as < mcc::Symbol > ().IsLvalue())
		{
			mcc::PrintColored("Cannot apply -- operator to a non-lvalue",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ().GetRvalue();
	}
#line 1124 "mcc_c.tab.c"
    break;

  case 19: // unary_expression: unary_operator cast_expression
#line 336 "mcc_c.y"
        {
		const auto sym = yystack_[1].value.as < std::string > ()[0];
		switch(sym)
		{
			case '+':
			case '-':
			case '~':
			if(!(yystack_[0].value.as < mcc::Symbol > ().EvalsToInt()&&!yystack_[0].value.as < mcc::Symbol > ().IsUserType()&&!yystack_[0].value.as < mcc::Symbol > ().IsPtr()))
			{
				mcc::PrintColored("Invalid type for operand to unary operator " + ("\""+yystack_[1].value.as < std::string > ())+"\"",mcc::TextColor::Error);
			}
			yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
			break;
			case '!':
			if(yystack_[0].value.as < mcc::Symbol > ().IsUserType())
			{
				mcc::PrintColored("Operand for unary operator \"!\" can't be of a struct or a union type",mcc::TextColor::Error);
			}
			yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
			break;
			case '*':
			if(!yystack_[0].value.as < mcc::Symbol > ().IsPtr())
			{
				mcc::PrintColored("Indirection requires pointer operand",mcc::TextColor::Error);
			}
			yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
			break;
			case '&':
			if(!yystack_[0].value.as < mcc::Symbol > ().IsLvalue())
			{
				mcc::PrintColored("Cannot take address of an rvalue",mcc::TextColor::Error);
			}
			yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ().GetPtrTo();
			break;

		}
	}
#line 1166 "mcc_c.tab.c"
    break;

  case 20: // unary_expression: "sizeof" unary_expression
#line 374 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
#line 1172 "mcc_c.tab.c"
    break;

  case 21: // unary_expression: "sizeof" "(" type_name ")"
#line 376 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
#line 1178 "mcc_c.tab.c"
    break;

  case 22: // unary_operator: "+"
#line 382 "mcc_c.y"
        {yylhs.value.as < std::string > ()="+";}
#line 1184 "mcc_c.tab.c"
    break;

  case 23: // unary_operator: "*"
#line 384 "mcc_c.y"
        {yylhs.value.as < std::string > ()="*";}
#line 1190 "mcc_c.tab.c"
    break;

  case 24: // unary_operator: "&"
#line 386 "mcc_c.y"
        {yylhs.value.as < std::string > ()="&";}
#line 1196 "mcc_c.tab.c"
    break;

  case 25: // unary_operator: "-"
#line 388 "mcc_c.y"
        {yylhs.value.as < std::string > ()="-";}
#line 1202 "mcc_c.tab.c"
    break;

  case 26: // unary_operator: "~"
#line 390 "mcc_c.y"
        {yylhs.value.as < std::string > ()="~";}
#line 1208 "mcc_c.tab.c"
    break;

  case 27: // unary_operator: "!"
#line 392 "mcc_c.y"
        {yylhs.value.as < std::string > ()="!";}
#line 1214 "mcc_c.tab.c"
    break;

  case 28: // cast_expression: unary_expression
#line 397 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1220 "mcc_c.tab.c"
    break;

  case 29: // cast_expression: "(" type_name ")" cast_expression
#line 399 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol{yystack_[2].value.as < mcc::T > (),true,true,false};}
#line 1226 "mcc_c.tab.c"
    break;

  case 30: // multiplicative_expression: cast_expression
#line 404 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1232 "mcc_c.tab.c"
    break;

  case 31: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 406 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1238 "mcc_c.tab.c"
    break;

  case 32: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 408 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1244 "mcc_c.tab.c"
    break;

  case 33: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 410 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1250 "mcc_c.tab.c"
    break;

  case 34: // additive_expression: multiplicative_expression
#line 416 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1256 "mcc_c.tab.c"
    break;

  case 35: // additive_expression: additive_expression "+" multiplicative_expression
#line 419 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1262 "mcc_c.tab.c"
    break;

  case 36: // additive_expression: additive_expression "-" multiplicative_expression
#line 421 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1268 "mcc_c.tab.c"
    break;

  case 37: // shift_expression: additive_expression
#line 426 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1274 "mcc_c.tab.c"
    break;

  case 38: // shift_expression: shift_expression "<<" additive_expression
#line 429 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1280 "mcc_c.tab.c"
    break;

  case 39: // shift_expression: shift_expression ">>" additive_expression
#line 431 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1286 "mcc_c.tab.c"
    break;

  case 40: // relational_expression: shift_expression
#line 436 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1292 "mcc_c.tab.c"
    break;

  case 41: // relational_expression: relational_expression "<=" shift_expression
#line 438 "mcc_c.y"
                                                     {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1298 "mcc_c.tab.c"
    break;

  case 42: // relational_expression: relational_expression ">=" shift_expression
#line 440 "mcc_c.y"
                                                     {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1304 "mcc_c.tab.c"
    break;

  case 43: // relational_expression: relational_expression "<" shift_expression
#line 442 "mcc_c.y"
                                                    {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1310 "mcc_c.tab.c"
    break;

  case 44: // relational_expression: relational_expression ">" shift_expression
#line 444 "mcc_c.y"
                                                    {yylhs.value.as < mcc::Symbol > ()=yystack_[2].value.as < mcc::Symbol > ();}
#line 1316 "mcc_c.tab.c"
    break;

  case 45: // equality_expression: relational_expression
#line 450 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1322 "mcc_c.tab.c"
    break;

  case 46: // equality_expression: equality_expression "==" relational_expression
#line 453 "mcc_c.y"
        {
		if(!mcc::AreComparable(yystack_[2].value.as < mcc::Symbol > (),yystack_[0].value.as < mcc::Symbol > ()))
		{
			mcc::PrintColored("Invalid operands to binary operator ==",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()={{mcc::Primitive::Int,0},true,true,false};
	}
#line 1334 "mcc_c.tab.c"
    break;

  case 47: // equality_expression: equality_expression "!=" relational_expression
#line 462 "mcc_c.y"
        {
		if(!mcc::AreComparable(yystack_[2].value.as < mcc::Symbol > (),yystack_[0].value.as < mcc::Symbol > ()))
		{
			mcc::PrintColored("Invalid operands to binary operator !=",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()={{mcc::Primitive::Int,0},true,true,false};
	}
#line 1346 "mcc_c.tab.c"
    break;

  case 48: // bitwise_logical_operator: "^"
#line 471 "mcc_c.y"
           {yylhs.value.as < std::string > ()="&";}
#line 1352 "mcc_c.tab.c"
    break;

  case 49: // bitwise_logical_operator: "|"
#line 472 "mcc_c.y"
            {yylhs.value.as < std::string > ()="|";}
#line 1358 "mcc_c.tab.c"
    break;

  case 50: // bitwise_logical_operator: "&"
#line 473 "mcc_c.y"
            {yylhs.value.as < std::string > ()="&";}
#line 1364 "mcc_c.tab.c"
    break;

  case 51: // bitwise_logical_expression: equality_expression
#line 476 "mcc_c.y"
                            {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1370 "mcc_c.tab.c"
    break;

  case 52: // bitwise_logical_expression: bitwise_logical_expression bitwise_logical_operator equality_expression
#line 478 "mcc_c.y"
        {
		if(!(mcc::AreComparable(yystack_[2].value.as < mcc::Symbol > (),yystack_[0].value.as < mcc::Symbol > ()))||yystack_[2].value.as < mcc::Symbol > ().IsPtr()||yystack_[0].value.as < mcc::Symbol > ().IsPtr())
		{
			mcc::PrintColored("Invalid operands for binary " + yystack_[1].value.as < std::string > () + " operator",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()={{mcc::Primitive::Int,0},true,true,false};

	}
#line 1383 "mcc_c.tab.c"
    break;

  case 53: // logical_binary_operator: "&&"
#line 487 "mcc_c.y"
            {yylhs.value.as < std::string > ()="&&";}
#line 1389 "mcc_c.tab.c"
    break;

  case 54: // logical_binary_operator: "||"
#line 488 "mcc_c.y"
            {yylhs.value.as < std::string > ()="||";}
#line 1395 "mcc_c.tab.c"
    break;

  case 55: // logical_expression: bitwise_logical_expression
#line 491 "mcc_c.y"
                                  {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1401 "mcc_c.tab.c"
    break;

  case 56: // logical_expression: logical_expression logical_binary_operator bitwise_logical_expression
#line 493 "mcc_c.y"
        {
		if(!(mcc::AreComparable(yystack_[2].value.as < mcc::Symbol > (),yystack_[0].value.as < mcc::Symbol > ())))
		{
			mcc::PrintColored("Invalid operands for binary " + yystack_[1].value.as < std::string > () + " operator",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()={{mcc::Primitive::Int,0},true,true,false};

	}
#line 1414 "mcc_c.tab.c"
    break;

  case 57: // conditional_expression: logical_expression
#line 503 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1420 "mcc_c.tab.c"
    break;

  case 58: // $@1: %empty
#line 504 "mcc_c.y"
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
#line 1437 "mcc_c.tab.c"
    break;

  case 59: // conditional_expression: logical_expression $@1 "?" expression ":" conditional_expression
#line 516 "mcc_c.y"
                                                  {yylhs.value.as < mcc::Symbol > ()=yystack_[5].value.as < mcc::Symbol > ();}
#line 1443 "mcc_c.tab.c"
    break;

  case 60: // assignment_expression: conditional_expression
#line 522 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1449 "mcc_c.tab.c"
    break;

  case 61: // $@2: %empty
#line 524 "mcc_c.y"
        {
		if(!yystack_[0].value.as < mcc::Symbol > ().IsLvalue()||yystack_[0].value.as < mcc::Symbol > ().IsConst())
		{mcc::PrintColored("Can only assign to a non-const lvalue",mcc::TextColor::Error);}
	}
#line 1458 "mcc_c.tab.c"
    break;

  case 62: // assignment_expression: unary_expression $@2 assignment_operator assignment_expression
#line 529 "mcc_c.y"
        {
		if(yystack_[3].value.as < mcc::Symbol > ().GetType().index()!=yystack_[0].value.as < mcc::Symbol > ().GetType().index())
		{
			mcc::PrintColored("Cant assign a non primitive to a primitive or vise-versa",mcc::TextColor::Error);
		}
		yylhs.value.as < mcc::Symbol > ()=yystack_[3].value.as < mcc::Symbol > ();
	}
#line 1470 "mcc_c.tab.c"
    break;

  case 74: // expression: assignment_expression
#line 554 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({yystack_[0].value.as < mcc::Symbol > ().GetType(),yystack_[0].value.as < mcc::Symbol > ().GetIndLevel()},false,true,true);}
#line 1476 "mcc_c.tab.c"
    break;

  case 75: // expression: expression "," assignment_expression
#line 555 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1482 "mcc_c.tab.c"
    break;

  case 76: // constant_expression: conditional_expression
#line 559 "mcc_c.y"
                                {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1488 "mcc_c.tab.c"
    break;

  case 77: // declaration: declaration_specifiers ";"
#line 565 "mcc_c.y"
        {mcc::PrintColored("declaration does not declare anything",mcc::TextColor::Warning);}
#line 1494 "mcc_c.tab.c"
    break;

  case 78: // declaration: declaration_specifiers init_declarator_list ";"
#line 567 "mcc_c.y"
        {
		drv.UnsetCurrentType();
	}
#line 1502 "mcc_c.tab.c"
    break;

  case 79: // declaration_specifiers: storage_class_specifier
#line 574 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1511 "mcc_c.tab.c"
    break;

  case 80: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 579 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1519 "mcc_c.tab.c"
    break;

  case 81: // declaration_specifiers: type_specifier
#line 583 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1528 "mcc_c.tab.c"
    break;

  case 82: // declaration_specifiers: type_specifier declaration_specifiers
#line 588 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={yystack_[1].value.as < mcc::T > ()};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1537 "mcc_c.tab.c"
    break;

  case 83: // declaration_specifiers: type_qualifier
#line 593 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());}
#line 1545 "mcc_c.tab.c"
    break;

  case 84: // declaration_specifiers: type_qualifier declaration_specifiers
#line 597 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={yystack_[0].value.as < mcc::T > ()};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1554 "mcc_c.tab.c"
    break;

  case 85: // init_declarator_list: init_declarator
#line 605 "mcc_c.y"
        {drv.SetInConst(false);}
#line 1560 "mcc_c.tab.c"
    break;

  case 86: // init_declarator_list: init_declarator_list "," init_declarator
#line 606 "mcc_c.y"
          { yylhs.value.as < std::vector<mcc::Symbol> > () = yystack_[2].value.as < std::vector<mcc::Symbol> > (); }
#line 1566 "mcc_c.tab.c"
    break;

  case 87: // init_declarator: declarator
#line 611 "mcc_c.y"
        {
		auto sym = mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first,yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second);
	}
#line 1575 "mcc_c.tab.c"
    break;

  case 88: // init_declarator: declarator "=" initializer
#line 616 "mcc_c.y"
        {
		auto sym=mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().first,yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().second);
	}
#line 1584 "mcc_c.tab.c"
    break;

  case 94: // type_specifier: "void"
#line 631 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Void};}
#line 1590 "mcc_c.tab.c"
    break;

  case 95: // type_specifier: "char"
#line 632 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Char};}
#line 1596 "mcc_c.tab.c"
    break;

  case 96: // type_specifier: "short"
#line 633 "mcc_c.y"
                 {yylhs.value.as < mcc::T > ()={mcc::Primitive::Short};}
#line 1602 "mcc_c.tab.c"
    break;

  case 97: // type_specifier: "int"
#line 634 "mcc_c.y"
               {yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};}
#line 1608 "mcc_c.tab.c"
    break;

  case 98: // type_specifier: "long"
#line 635 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Long};}
#line 1614 "mcc_c.tab.c"
    break;

  case 99: // type_specifier: "float"
#line 636 "mcc_c.y"
                 {yylhs.value.as < mcc::T > ()={mcc::Primitive::Float};}
#line 1620 "mcc_c.tab.c"
    break;

  case 100: // type_specifier: "double"
#line 637 "mcc_c.y"
                  {yylhs.value.as < mcc::T > ()={mcc::Primitive::Double};}
#line 1626 "mcc_c.tab.c"
    break;

  case 101: // type_specifier: "signed"
#line 638 "mcc_c.y"
                   {yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};}
#line 1632 "mcc_c.tab.c"
    break;

  case 102: // type_specifier: "unsigned"
#line 639 "mcc_c.y"
                    {yylhs.value.as < mcc::T > ()={mcc::Primitive::UInt};}
#line 1638 "mcc_c.tab.c"
    break;

  case 103: // type_specifier: struct_or_union_specifier
#line 640 "mcc_c.y"
                                   {}
#line 1644 "mcc_c.tab.c"
    break;

  case 104: // type_specifier: enum_specifier
#line 641 "mcc_c.y"
                        {}
#line 1650 "mcc_c.tab.c"
    break;

  case 105: // type_specifier: "typename"
#line 643 "mcc_c.y"
                {
			yylhs.value.as < mcc::T > () = drv.GetType(yystack_[0].value.as < std::string > ()).value();
		}
#line 1658 "mcc_c.tab.c"
    break;

  case 114: // specifier_qualifier_list: type_specifier specifier_qualifier_list
#line 668 "mcc_c.y"
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
#line 1674 "mcc_c.tab.c"
    break;

  case 115: // specifier_qualifier_list: type_specifier
#line 680 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();}
#line 1680 "mcc_c.tab.c"
    break;

  case 116: // specifier_qualifier_list: type_qualifier specifier_qualifier_list
#line 682 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();}
#line 1686 "mcc_c.tab.c"
    break;

  case 117: // specifier_qualifier_list: type_qualifier
#line 684 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()={true};}
#line 1692 "mcc_c.tab.c"
    break;

  case 130: // type_qualifier: "const"
#line 714 "mcc_c.y"
                 {yylhs.value.as < std::string > ()="const";drv.SetInConst(true);}
#line 1698 "mcc_c.tab.c"
    break;

  case 131: // type_qualifier: "volatile"
#line 715 "mcc_c.y"
                    {yylhs.value.as < std::string > ()="";}
#line 1704 "mcc_c.tab.c"
    break;

  case 132: // declarator: pointer direct_declarator
#line 720 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1712 "mcc_c.tab.c"
    break;

  case 133: // declarator: direct_declarator
#line 724 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1720 "mcc_c.tab.c"
    break;

  case 134: // id_or_idptr: "identifier"
#line 730 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[0].value.as < std::string > (),{drv.GetCurrentType(),drv.GetInConst(),true,true}};
		//symbol has no indirection, i.e. int arr[] - array of int
	}
#line 1729 "mcc_c.tab.c"
    break;

  case 135: // id_or_idptr: "(" "identifier" ")"
#line 736 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::string > (),{drv.GetCurrentType(),drv.GetInConst(),true,true}};
	}
#line 1737 "mcc_c.tab.c"
    break;

  case 136: // id_or_idptr: "(" pointer "identifier" ")"
#line 742 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::string > (),{{drv.GetCurrentType().GetType(),yystack_[2].value.as < mcc::PtrBits > ().GetIndirection()},drv.GetInConst(),true,true}};
	//symbol HAS indirection, i.e int (*arr)[] - POINTER to an array of int
	}
#line 1746 "mcc_c.tab.c"
    break;

  case 137: // array_dim: "[" constant_expression "]"
#line 748 "mcc_c.y"
        {
		yylhs.value.as < std::size_t > ()=1;
	}
#line 1754 "mcc_c.tab.c"
    break;

  case 138: // array_dim: "[" "]"
#line 752 "mcc_c.y"
        {
		yylhs.value.as < std::size_t > ()=0;
	}
#line 1762 "mcc_c.tab.c"
    break;

  case 139: // array_dim_list: array_dim
#line 758 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::size_t> > ()={};
		yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ());
	}
#line 1771 "mcc_c.tab.c"
    break;

  case 140: // array_dim_list: array_dim_list array_dim
#line 763 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::size_t> > ()=yystack_[1].value.as < std::vector<std::size_t> > ();
		yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ());
	}
#line 1780 "mcc_c.tab.c"
    break;

  case 141: // direct_declarator: id_or_idptr
#line 771 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1788 "mcc_c.tab.c"
    break;

  case 142: // direct_declarator: id_or_idptr array_dim_list
#line 776 "mcc_c.y"
        {
		auto as_arr_t = mcc::T{yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetType()}.ToArrT();
		drv.AddSymbol(yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{mcc::CArray{as_arr_t,yystack_[0].value.as < std::vector<std::size_t> > ().begin(),yystack_[0].value.as < std::vector<std::size_t> > ().end()},yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetIndLevel()},drv.GetInConst(),true,false});
		mcc::PrintColored("Array:",mcc::TextColor::Good);
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{mcc::CArray{as_arr_t,yystack_[0].value.as < std::vector<std::size_t> > ().begin(),yystack_[0].value.as < std::vector<std::size_t> > ().end()},yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetIndLevel()},drv.GetInConst(),true,false}};
	}
#line 1799 "mcc_c.tab.c"
    break;

  case 143: // direct_declarator: id_or_idptr "(" parameter_type_list ")"
#line 783 "mcc_c.y"
        {
		std::vector<mcc::T> param_types;
		std::transform(yystack_[1].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().begin(),yystack_[1].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().end(),std::back_inserter(param_types),[](auto&&arg)
			{
				return arg.second.GetType();
			});
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[3].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{std::make_shared<mcc::Func>(param_types),0},drv.GetInConst(),false,false}};
	}
#line 1813 "mcc_c.tab.c"
    break;

  case 144: // direct_declarator: id_or_idptr "(" ")"
#line 793 "mcc_c.y"
        {
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{std::make_shared<mcc::Func>(std::vector<mcc::T>{}),0},drv.GetInConst(),true,false}};
	}
#line 1822 "mcc_c.tab.c"
    break;

  case 145: // pointer: "*"
#line 800 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1831 "mcc_c.tab.c"
    break;

  case 146: // pointer: "*" type_qualifier_list
#line 805 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[0].value.as < std::string > ()=="const");
	}
#line 1840 "mcc_c.tab.c"
    break;

  case 147: // pointer: "*" pointer
#line 810 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1849 "mcc_c.tab.c"
    break;

  case 148: // pointer: "*" type_qualifier_list pointer
#line 815 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[1].value.as < std::string > ()=="const");
	}
#line 1858 "mcc_c.tab.c"
    break;

  case 149: // type_qualifier_list: type_qualifier
#line 824 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 1864 "mcc_c.tab.c"
    break;

  case 150: // type_qualifier_list: type_qualifier_list type_qualifier
#line 826 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ()+yystack_[0].value.as < std::string > ();}
#line 1870 "mcc_c.tab.c"
    break;

  case 151: // parameter_type_list: parameter_list
#line 832 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();
	}
#line 1878 "mcc_c.tab.c"
    break;

  case 152: // parameter_type_list: parameter_list "," "..."
#line 836 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[2].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();}
#line 1884 "mcc_c.tab.c"
    break;

  case 153: // parameter_list: parameter_declaration
#line 841 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();}
#line 1890 "mcc_c.tab.c"
    break;

  case 154: // parameter_list: parameter_list "," parameter_declaration
#line 843 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[2].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();
	yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().push_back(yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()[0]);}
#line 1897 "mcc_c.tab.c"
    break;

  case 155: // parameter_declaration: declaration_specifiers declarator
#line 849 "mcc_c.y"
        {
			auto decl = yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second;
			yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()={};
			yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().push_back({yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first,{yystack_[1].value.as < mcc::T > (),drv.GetInConst(),true,true}});
	}
#line 1907 "mcc_c.tab.c"
    break;

  case 156: // type_name: specifier_qualifier_list
#line 858 "mcc_c.y"
          { yylhs.value.as < mcc::T > () = yystack_[0].value.as < mcc::T > (); }
#line 1913 "mcc_c.tab.c"
    break;

  case 157: // type_name: specifier_qualifier_list abstract_declarator
#line 859 "mcc_c.y"
          { yylhs.value.as < mcc::T > () = yystack_[1].value.as < mcc::T > (); }
#line 1919 "mcc_c.tab.c"
    break;

  case 176: // $@3: %empty
#line 893 "mcc_c.y"
          {drv.EnterNewScope("");}
#line 1925 "mcc_c.tab.c"
    break;

  case 177: // statement: $@3 compound_statement
#line 895 "mcc_c.y"
                {drv.LeaveScope();}
#line 1931 "mcc_c.tab.c"
    break;

  case 183: // labeled_statement: "identifier" ":" statement
#line 906 "mcc_c.y"
        {
		drv.AddLabel(yystack_[2].value.as < std::string > ());
	}
#line 1939 "mcc_c.tab.c"
    break;

  case 195: // $@4: %empty
#line 935 "mcc_c.y"
                                 {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1945 "mcc_c.tab.c"
    break;

  case 197: // $@5: %empty
#line 936 "mcc_c.y"
                                                {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1951 "mcc_c.tab.c"
    break;

  case 199: // iteration_statement: "for" "(" expression_statement expression_statement ")" statement
#line 939 "mcc_c.y"
        {std::cout<<"param decl\n";}
#line 1957 "mcc_c.tab.c"
    break;

  case 201: // jump_statement: "goto" "identifier" ";"
#line 945 "mcc_c.y"
        {
		drv.AddLabelRef(yystack_[1].value.as < std::string > ());
	}
#line 1965 "mcc_c.tab.c"
    break;

  case 209: // external_declaration: declaration
#line 962 "mcc_c.y"
        {mcc::PrintColored("New global definition",mcc::TextColor::Good);}
#line 1971 "mcc_c.tab.c"
    break;

  case 210: // $@6: %empty
#line 967 "mcc_c.y"
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
#line 1989 "mcc_c.tab.c"
    break;

  case 211: // function_definition: declaration_specifiers direct_declarator $@6 compound_statement
#line 981 "mcc_c.y"
                {
					drv.LeaveScope();
		}
#line 1997 "mcc_c.tab.c"
    break;

  case 212: // $@7: %empty
#line 985 "mcc_c.y"
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
#line 2012 "mcc_c.tab.c"
    break;

  case 213: // function_definition: direct_declarator $@7 compound_statement
#line 996 "mcc_c.y"
                {drv.LeaveScope();}
#line 2018 "mcc_c.tab.c"
    break;


#line 2022 "mcc_c.tab.c"

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
  "bitwise_logical_operator", "bitwise_logical_expression",
  "logical_binary_operator", "logical_expression",
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


  const short parser::yypact_ninf_ = -215;

  const short parser::yytable_ninf_ = -211;

  const short
  parser::yypact_[] =
  {
     978,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
      12,  -215,    10,  -215,    24,  1183,  1183,  -215,    13,  -215,
    1183,   -10,  -215,   817,  -215,  -215,   -38,    47,     6,    -1,
     141,  -215,    96,  -215,    91,   110,    26,  -215,  -215,   113,
    1209,  -215,  1035,   549,  -215,   130,   121,  -215,  -215,    47,
     142,   -43,  -215,  -215,  -215,  -215,    -1,   126,  -215,    36,
     572,   121,  -215,  1209,  1209,  1103,  -215,    11,  1209,  -215,
      36,   147,   140,  -215,  -215,  -215,  -215,   712,  -215,  -215,
    -215,  -215,  -215,  -215,   508,  -215,   736,   736,  -215,   -31,
    -215,   751,  -215,    41,    87,   173,   107,    29,    38,   125,
    -215,   155,  -215,   288,  -215,    19,   751,  -215,    47,  -215,
    -215,  -215,  -215,  -215,   572,  1220,  -215,  -215,  -215,  -215,
    1140,  -215,  -215,  -215,   751,   122,  -215,   168,  -215,  -215,
    -215,   874,   508,  -215,  -215,   -33,    -9,   171,   751,  -215,
    -215,   610,   247,   751,  -215,  -215,   252,  -215,   751,   751,
     751,   751,   751,   751,   751,   751,   751,   751,   751,   751,
     751,  -215,  -215,  -215,   751,  -215,  -215,   751,   174,  -215,
     176,   751,   178,   197,   202,   205,   438,   206,   268,   195,
     199,   180,  -215,  -215,   143,  -215,    24,  -215,   121,  -215,
     363,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,   101,
    1230,  -215,  -215,  -215,    11,   751,  -215,  -215,   213,  -215,
     751,   916,   636,   109,  -215,   128,   751,  -215,    -4,  -215,
    -215,    52,  -215,  -215,  -215,  -215,    41,    41,    87,    87,
     173,   173,   173,   173,   107,   107,    29,    38,   751,   438,
     198,   438,   751,   751,   751,   251,   212,   203,  -215,  -215,
    -215,   146,  -215,  -215,  -215,  -215,  -215,   531,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,   751,
    -215,  -215,  -215,  -215,  -215,   217,   218,  -215,   216,   128,
    1077,   651,  -215,  -215,   751,  -215,   154,  -215,   438,  -215,
      60,    68,   207,   224,   212,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,   250,  -215,   219,  -215,   751,  -215,
     438,   438,   262,   751,   674,  -215,  -215,  -215,   301,  -215,
     438,   207,   438,    76,   438,  -215,   264,  -215,   438,  -215,
     253,  -215,  -215
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   134,    89,    90,    91,    92,    93,    95,    96,    98,
     101,   102,    99,   100,   130,   131,    94,    97,   109,   110,
       0,   105,     0,   209,     0,    79,    81,   103,     0,   104,
      83,   141,   212,     0,   206,   208,   125,     0,     0,   145,
       0,    77,     0,    85,    87,   133,     0,    80,    82,   108,
       0,    84,     0,     0,   139,   142,     0,     1,   207,     0,
     128,     0,   126,   135,   149,   147,   146,     0,    78,     0,
       0,     0,   132,     0,   115,     0,   111,     0,   117,   144,
       0,     0,   151,   153,     2,     3,     4,     0,    22,    25,
      23,    24,    27,    26,     0,   138,     0,     0,     6,    16,
      28,     0,    30,    34,    37,    40,    45,    51,    55,    57,
      76,     0,   140,   176,   213,     0,     0,   123,     0,   150,
     148,   136,    86,   133,     0,    28,    60,   170,    88,   211,
       0,   114,   107,   112,     0,     0,   118,   120,   116,   155,
     143,     0,     0,    20,    74,     0,   156,     0,     0,    17,
      18,     0,     0,     0,    12,    13,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,     0,    53,    54,     0,     0,   137,
       2,     0,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,   187,   190,     0,   182,     0,   188,     0,   175,
     176,   178,   179,   180,   181,   124,   129,   127,   173,     0,
       0,   106,   121,   113,     0,     0,   152,   154,     0,     5,
       0,     0,     0,   158,   157,   159,     0,     8,     0,    14,
      11,     0,    10,    31,    32,    33,    35,    36,    38,    39,
      42,    41,    43,    44,    46,    47,    52,    56,     0,   176,
       0,   176,     0,     0,     0,     0,     0,     0,   202,   203,
     204,     0,   191,   177,   186,   189,   171,     0,    65,    66,
      64,    68,    67,    69,    70,    71,    72,    73,    63,     0,
     119,   122,    21,    75,   166,     0,     0,   162,     0,   160,
       0,     0,    29,     9,     0,     7,     0,   183,   176,   185,
       0,     0,   195,     0,     0,   201,   205,   172,   174,    62,
     167,   161,   163,   168,     0,   164,     0,    15,     0,   184,
     176,   176,     0,     0,     0,   169,   165,    59,   192,   194,
     176,   197,   176,     0,   176,   196,     0,   199,   176,   193,
       0,   200,   198
  };

  const short
  parser::yypgoto_[] =
  {
    -215,  -215,  -215,  -215,   -52,  -215,   -91,    83,    90,    39,
      77,   157,  -215,   152,  -215,  -215,   -51,  -215,   -67,  -215,
    -215,   -87,   -96,    23,     0,  -215,   263,  -215,   119,  -215,
    -215,   260,   -58,     3,  -215,   120,  -215,   276,   223,    84,
     -68,  -215,   282,  -215,   103,   -18,  -215,  -210,  -215,   201,
     210,   123,   124,  -119,  -215,  -178,  -215,  -215,   -65,  -215,
    -214,  -215,  -215,  -215,  -215,  -215,  -215,   310,  -215,  -215,
    -215
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    98,    99,   228,   125,   101,   102,   103,   104,   105,
     106,   107,   174,   108,   177,   109,   126,   178,   144,   210,
     279,   194,   111,   195,   196,    42,    43,    25,    26,    27,
      28,    75,    76,    77,   135,   136,    29,    61,    62,    30,
      44,    31,    54,    55,   123,    46,    66,    81,    82,    83,
     147,   224,   225,   128,   209,   197,   198,   199,   114,   200,
     201,   202,   203,   322,   336,   204,    33,    34,    35,    71,
      56
  };

  const short
  parser::yytable_[] =
  {
      24,   100,   110,   127,    40,   208,   129,   145,   255,   137,
     157,   285,   139,    38,     1,    36,    49,   133,    14,    15,
     206,    65,   265,    23,   117,    47,    48,     1,    59,     1,
      51,   219,   151,    24,   152,   143,   118,   153,   212,     1,
     154,   155,   304,    39,   149,   150,   220,   156,   120,   100,
      60,    39,    80,    52,   221,   145,    23,   127,    53,   222,
     293,   145,    39,    39,   100,   110,   231,   233,   234,   235,
      63,   297,   133,   299,    22,   294,    39,   131,    37,    50,
     314,   138,   100,   110,   229,   250,   205,    22,    39,    22,
     324,   134,   171,   158,   159,   172,   173,   146,   118,    22,
     160,    41,   169,    32,   261,   170,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   281,
     319,   295,   100,    64,   320,   100,   288,    45,   223,   100,
     110,   220,   321,   263,    78,   292,    32,   161,   162,   220,
     338,    80,   328,   329,    67,   146,   137,   220,   308,    72,
     119,    70,   335,   283,   337,   220,   339,    78,    78,    78,
     341,   296,    78,   100,   110,   300,   301,   302,   266,    74,
     100,   110,   221,    68,   100,    69,  -210,   222,    78,    73,
     267,   165,   166,    84,    85,    86,    87,   113,   167,   168,
     121,   290,    74,    74,    74,   316,   291,    74,    53,   213,
     127,   214,   116,   223,   240,   241,   242,   243,   175,   176,
     -58,   140,   309,    74,    78,    84,    85,    86,    87,   141,
     262,    80,   220,   306,   179,   220,    78,   317,   163,   164,
      88,    89,    90,   220,   318,   226,   331,   333,    91,   100,
     110,    92,    93,    94,   236,   237,   244,   245,   215,    74,
     230,    96,    97,   238,   239,   232,   249,   260,   251,   248,
     252,    74,    88,    89,    90,   253,   100,   327,   254,   256,
      91,   257,   258,    92,    93,    94,   259,   282,   298,   303,
     305,   310,   311,    96,    97,   312,   220,   323,   326,   193,
      80,   180,    85,    86,    87,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     181,   182,   183,    17,   325,   184,   185,   186,   187,   188,
     189,   190,   191,    18,    19,    20,   330,   334,   340,   247,
     342,   246,   122,   130,   280,   115,    21,   112,    88,    89,
      90,   207,   217,    58,   286,     0,    91,   289,     0,    92,
      93,    94,   218,     0,     0,   192,     0,     0,     0,    96,
      97,     0,     0,     0,     0,   193,   180,    85,    86,    87,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   181,   182,   183,    17,     0,
     184,   185,   186,   187,   188,   189,   190,   191,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    88,    89,    90,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,    94,     0,     0,     0,
     264,     0,     0,     0,    96,    97,     0,     0,     0,     0,
     193,   180,    85,    86,    87,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     181,   182,   183,    17,     0,   184,   185,   186,   187,   188,
     189,   190,   191,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    88,    89,
      90,     0,     0,     0,     0,     0,    91,     0,     0,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    84,    85,    86,    87,   193,     0,     0,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,     0,     0,    17,    84,    85,    86,    87,     0,     0,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    21,     0,    88,    89,
      90,     0,     0,     0,     0,     0,    91,     0,     0,    92,
      93,    94,     0,     0,     0,    84,    85,    86,    87,    96,
      97,    88,    89,    90,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,    94,     0,     0,   124,   307,    88,
      89,    90,    96,    97,     0,     0,     0,    91,     0,     0,
      92,    93,    94,    84,    85,    86,    87,     0,    95,     0,
      96,    97,    88,    89,    90,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,    94,     0,     0,   124,    84,
      85,    86,    87,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,     0,     0,
      88,    89,    90,     0,     0,     0,     0,     0,    91,     0,
       0,    92,    93,    94,   227,     0,     0,    84,    85,    86,
      87,    96,    97,     0,     0,     0,    88,    89,    90,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,    94,
       0,    88,    89,    90,     0,   287,     0,    96,    97,    91,
       0,     0,    92,    93,    94,    84,    85,    86,    87,     0,
     315,     0,    96,    97,    88,    89,    90,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,    94,   332,    84,
      85,    86,    87,     0,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,     0,     0,
       0,     0,    88,    89,    90,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,   142,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,    88,    89,    90,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,   148,
       0,    88,    89,    90,     0,     0,     0,    96,    97,    91,
       0,     0,    92,    93,    94,     0,     0,    57,     0,     0,
       1,     0,    96,    97,     2,     3,     4,     5,     6,     7,
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
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,    17,     0,     0,   216,     0,     0,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
     284,     1,     0,     0,   222,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    79,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    21,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,   313,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     0,     0,    17,     0,     0,     0,     0,
     132,     0,     0,     0,     0,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,   211,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    21,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
     -61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278
  };

  const short
  parser::yycheck_[] =
  {
       0,    53,    53,    70,    22,   124,    71,    94,   186,    77,
     101,   221,    80,     3,     3,     3,     3,    75,    19,    20,
     116,    39,   200,     0,    67,    25,    26,     3,    66,     3,
      30,    64,    63,    33,    65,    87,    79,    68,   134,     3,
      71,    72,   256,    52,    96,    97,    79,    78,    66,   101,
       3,    52,    52,    63,    63,   142,    33,   124,    68,    68,
      64,   148,    52,    52,   116,   116,   153,   158,   159,   160,
      64,   249,   130,   251,    63,    79,    52,    74,    66,    66,
     290,    78,   134,   134,   151,   181,    67,    63,    52,    63,
     304,    80,    54,    52,    53,    57,    58,    94,    79,    63,
      59,    77,    73,     0,   191,    76,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   215,
     298,    69,   174,    39,    64,   177,   222,    24,   146,   181,
     181,    79,    64,   198,    50,   226,    33,    50,    51,    79,
      64,   141,   320,   321,     3,   142,   214,    79,   267,    46,
      66,    60,   330,   220,   332,    79,   334,    73,    74,    75,
     338,   248,    78,   215,   215,   252,   253,   254,    67,    50,
     222,   222,    63,    77,   226,    79,    66,    68,    94,    66,
      79,    74,    75,     3,     4,     5,     6,    66,    81,    82,
      64,    63,    73,    74,    75,   291,    68,    78,    68,    77,
     267,    79,    60,   221,   165,   166,   167,   168,    83,    84,
      85,    64,   279,    94,   130,     3,     4,     5,     6,    79,
      77,   221,    79,    77,    69,    79,   142,   294,    55,    56,
      50,    51,    52,    79,    80,    64,   323,   324,    58,   291,
     291,    61,    62,    63,   161,   162,   169,   170,    80,   130,
       3,    71,    72,   163,   164,     3,    80,    77,    80,    85,
      63,   142,    50,    51,    52,    63,   318,   318,    63,    63,
      58,     3,    77,    61,    62,    63,    77,    64,    80,    28,
      77,    64,    64,    71,    72,    69,    79,    63,    69,    77,
     290,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    64,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    64,    26,    64,   177,
      77,   174,    69,    73,   214,    59,    48,    55,    50,    51,
      52,   118,   141,    33,   221,    -1,    58,   223,    -1,    61,
      62,    63,   142,    -1,    -1,    67,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    77,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,
      77,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,     3,     4,     5,     6,    77,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    48,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,     3,     4,     5,     6,    71,
      72,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,    -1,    -1,    66,    67,    50,
      51,    52,    71,    72,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    63,     3,     4,     5,     6,    -1,    69,    -1,
      71,    72,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    62,    63,    -1,    -1,    66,     3,
       4,     5,     6,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    64,    -1,    -1,     3,     4,     5,
       6,    71,    72,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    50,    51,    52,    -1,    69,    -1,    71,    72,    58,
      -1,    -1,    61,    62,    63,     3,     4,     5,     6,    -1,
      69,    -1,    71,    72,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    64,     3,
       4,     5,     6,    -1,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    50,    51,    52,    -1,    -1,    -1,    71,    72,    58,
      -1,    -1,    61,    62,    63,    -1,    -1,     0,    -1,    -1,
       3,    -1,    71,    72,     7,     8,     9,    10,    11,    12,
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
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,     3,    -1,    -1,    68,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    64,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    48,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    67,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    48,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    25,    35,    36,
      37,    48,    63,   109,   110,   113,   114,   115,   116,   122,
     125,   127,   130,   152,   153,   154,     3,    66,     3,    52,
     131,    77,   111,   112,   126,   130,   131,   110,   110,     3,
      66,   110,    63,    68,   128,   129,   156,     0,   153,    66,
       3,   123,   124,    64,   125,   131,   132,     3,    77,    79,
      60,   155,   130,    66,   114,   117,   118,   119,   125,    64,
     110,   133,   134,   135,     3,     4,     5,     6,    50,    51,
      52,    58,    61,    62,    63,    69,    71,    72,    87,    88,
      90,    91,    92,    93,    94,    95,    96,    97,    99,   101,
     102,   108,   128,    66,   144,   123,    60,    67,    79,   125,
     131,    64,   112,   130,    66,    90,   102,   104,   139,   144,
     117,   119,    67,   118,    80,   120,   121,   126,   119,   126,
      64,    79,    63,    90,   104,   107,   119,   136,    63,    90,
      90,    63,    65,    68,    71,    72,    78,    92,    52,    53,
      59,    50,    51,    55,    56,    74,    75,    81,    82,    73,
      76,    54,    57,    58,    98,    83,    84,   100,   103,    69,
       3,    22,    23,    24,    27,    28,    29,    30,    31,    32,
      33,    34,    67,    77,   107,   109,   110,   141,   142,   143,
     145,   146,   147,   148,   151,    67,   108,   124,   139,   140,
     105,    67,   108,    77,    79,    80,    70,   135,   136,    64,
      79,    63,    68,   131,   137,   138,    64,    64,    89,   104,
       3,   107,     3,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    95,    96,    96,    97,    99,    85,    80,
     108,    80,    63,    63,    63,   141,    63,     3,    77,    77,
      77,   107,    77,   144,    67,   141,    67,    79,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    60,   106,
     121,   108,    64,   104,    64,   133,   137,    69,   108,   138,
      63,    68,    92,    64,    79,    69,   107,   141,    80,   141,
     107,   107,   107,    28,   146,    77,    77,    67,   139,   104,
      64,    64,    69,    64,   133,    69,   108,   104,    80,   141,
      64,    64,   149,    63,   146,    64,    69,   102,   141,   141,
      64,   107,    64,   107,    26,   141,   150,   141,    64,   141,
      64,   141,    77
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   103,   102,
     104,   105,   104,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   136,   136,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   140,   140,   141,   142,   141,   141,   141,
     141,   141,   141,   143,   143,   143,   144,   144,   145,   145,
     146,   146,   147,   147,   147,   149,   148,   150,   148,   148,
     148,   151,   151,   151,   151,   151,   152,   152,   153,   153,
     155,   154,   156,   154
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     0,     6,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     2,     1,
       2,     1,     2,     4,     3,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     3,     4,     3,     3,     2,     1,     2,
       1,     2,     5,     7,     5,     0,     6,     0,     8,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       0,     4,     0,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   146,   146,   166,   170,   174,   181,   185,   211,   237,
     270,   274,   283,   293,   305,   307,   315,   319,   327,   335,
     373,   375,   381,   383,   385,   387,   389,   391,   396,   398,
     403,   405,   407,   409,   415,   418,   420,   425,   428,   430,
     435,   438,   440,   442,   444,   449,   452,   461,   471,   472,
     473,   476,   477,   487,   488,   491,   492,   502,   504,   504,
     521,   524,   523,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   553,   555,   559,   564,   566,   573,
     578,   582,   587,   592,   596,   604,   606,   610,   615,   623,
     624,   625,   626,   627,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   648,   649,   650,   653,
     654,   658,   659,   663,   667,   679,   681,   683,   688,   689,
     693,   694,   695,   699,   700,   701,   705,   706,   710,   711,
     714,   715,   719,   723,   729,   735,   741,   747,   751,   757,
     762,   769,   775,   782,   792,   799,   804,   809,   814,   823,
     825,   831,   835,   840,   842,   848,   858,   859,   863,   864,
     865,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     881,   882,   883,   887,   888,   892,   893,   893,   896,   897,
     898,   899,   900,   905,   909,   910,   915,   916,   920,   921,
     924,   925,   929,   930,   931,   935,   935,   936,   936,   937,
     940,   944,   948,   949,   950,   951,   955,   956,   960,   961,
     967,   966,   985,   984
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
#line 3040 "mcc_c.tab.c"

#line 998 "mcc_c.y"

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
