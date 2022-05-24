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
#line 137 "mcc_c.y"

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
#line 145 "mcc_c.y"
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
#line 895 "mcc_c.tab.c"
    break;

  case 3: // primary_expression: "constant"
#line 165 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 903 "mcc_c.tab.c"
    break;

  case 4: // primary_expression: "literal"
#line 169 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 911 "mcc_c.tab.c"
    break;

  case 5: // primary_expression: "(" expression ")"
#line 173 "mcc_c.y"
        {
	yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ();
	}
#line 919 "mcc_c.tab.c"
    break;

  case 6: // postfix_expression: primary_expression
#line 180 "mcc_c.y"
        {
		yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();
	}
#line 927 "mcc_c.tab.c"
    break;

  case 7: // postfix_expression: postfix_expression "[" expression "]"
#line 184 "mcc_c.y"
        {
		const auto is_sub_int = mcc::IsIntegerT(yystack_[1].value.as < mcc::Symbol > ().GetType());
		const auto ind = yystack_[1].value.as < mcc::Symbol > ().GetIndLevel();
		if( yystack_[3].value.as < mcc::Symbol > ().IsPtr()||std::holds_alternative<mcc::CArray>(yystack_[3].value.as < mcc::Symbol > ().GetType()))
		{
			const auto ind_lhs = yystack_[3].value.as < mcc::Symbol > ().GetIndLevel();
			yylhs.value.as < mcc::Symbol > ()={{yystack_[3].value.as < mcc::Symbol > ().GetType(),yystack_[3].value.as < mcc::Symbol > ().GetDeref()},yystack_[3].value.as < mcc::Symbol > ().DerefIsConst(),true,false};
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
#line 949 "mcc_c.tab.c"
    break;

  case 8: // postfix_expression: postfix_expression "(" ")"
#line 202 "mcc_c.y"
        {
		if(mcc::IsFuncPtr(yystack_[2].value.as < mcc::Symbol > ()))
		{
			const auto ftype = std::get<std::shared_ptr<mcc::Func>>(yystack_[2].value.as < mcc::Symbol > ().GetType());
			yylhs.value.as < mcc::Symbol > ()={ftype->GetReturnType(),false,true,false};
		}
		else
		{
			mcc::PrintColored("Is not a function",mcc::TextColor::Error);
			yylhs.value.as < mcc::Symbol > ()={};
		}
		mcc::PrintColored("Function call with no args",mcc::TextColor::Good);
	}
#line 967 "mcc_c.tab.c"
    break;

  case 9: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 216 "mcc_c.y"
        {mcc::PrintColored("Function call with args",mcc::TextColor::Good);}
#line 973 "mcc_c.tab.c"
    break;

  case 10: // postfix_expression: postfix_expression "." "identifier"
#line 218 "mcc_c.y"
        {mcc::PrintColored("Non ptr struct or union field access",mcc::TextColor::Good);}
#line 979 "mcc_c.tab.c"
    break;

  case 11: // postfix_expression: postfix_expression "->" "identifier"
#line 220 "mcc_c.y"
        {mcc::PrintColored("Ptr struct or union field access",mcc::TextColor::Good);}
#line 985 "mcc_c.tab.c"
    break;

  case 12: // postfix_expression: postfix_expression "++"
#line 222 "mcc_c.y"
        {mcc::PrintColored("Postfix increment",mcc::TextColor::Good);}
#line 991 "mcc_c.tab.c"
    break;

  case 13: // postfix_expression: postfix_expression "--"
#line 224 "mcc_c.y"
        {mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);}
#line 997 "mcc_c.tab.c"
    break;

  case 16: // unary_expression: postfix_expression
#line 234 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1003 "mcc_c.tab.c"
    break;

  case 17: // unary_expression: "++" unary_expression
#line 236 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1009 "mcc_c.tab.c"
    break;

  case 18: // unary_expression: "--" unary_expression
#line 238 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1015 "mcc_c.tab.c"
    break;

  case 19: // unary_expression: unary_operator cast_expression
#line 240 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1021 "mcc_c.tab.c"
    break;

  case 20: // unary_expression: "sizeof" unary_expression
#line 242 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
#line 1027 "mcc_c.tab.c"
    break;

  case 21: // unary_expression: "sizeof" "(" type_name ")"
#line 244 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
#line 1033 "mcc_c.tab.c"
    break;

  case 28: // cast_expression: unary_expression
#line 259 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1039 "mcc_c.tab.c"
    break;

  case 29: // cast_expression: "(" type_name ")" cast_expression
#line 261 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol{yystack_[2].value.as < mcc::T > (),true,true,false};}
#line 1045 "mcc_c.tab.c"
    break;

  case 30: // multiplicative_expression: cast_expression
#line 266 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1051 "mcc_c.tab.c"
    break;

  case 31: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 267 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1057 "mcc_c.tab.c"
    break;

  case 32: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 268 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1063 "mcc_c.tab.c"
    break;

  case 33: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 269 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1069 "mcc_c.tab.c"
    break;

  case 34: // additive_expression: multiplicative_expression
#line 274 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1075 "mcc_c.tab.c"
    break;

  case 35: // additive_expression: additive_expression "+" multiplicative_expression
#line 276 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1081 "mcc_c.tab.c"
    break;

  case 36: // additive_expression: additive_expression "-" multiplicative_expression
#line 277 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1087 "mcc_c.tab.c"
    break;

  case 37: // shift_expression: additive_expression
#line 282 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1093 "mcc_c.tab.c"
    break;

  case 38: // shift_expression: shift_expression "<<" additive_expression
#line 284 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1099 "mcc_c.tab.c"
    break;

  case 39: // shift_expression: shift_expression ">>" additive_expression
#line 285 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1105 "mcc_c.tab.c"
    break;

  case 40: // relational_expression: shift_expression
#line 290 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1111 "mcc_c.tab.c"
    break;

  case 41: // relational_expression: relational_expression "<=" shift_expression
#line 292 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1117 "mcc_c.tab.c"
    break;

  case 42: // relational_expression: relational_expression ">=" shift_expression
#line 293 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1123 "mcc_c.tab.c"
    break;

  case 43: // relational_expression: relational_expression "<" shift_expression
#line 294 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1129 "mcc_c.tab.c"
    break;

  case 44: // relational_expression: relational_expression ">" shift_expression
#line 295 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1135 "mcc_c.tab.c"
    break;

  case 45: // equality_expression: relational_expression
#line 300 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1141 "mcc_c.tab.c"
    break;

  case 46: // equality_expression: equality_expression "==" relational_expression
#line 302 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1147 "mcc_c.tab.c"
    break;

  case 47: // equality_expression: equality_expression "!=" relational_expression
#line 303 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1153 "mcc_c.tab.c"
    break;

  case 48: // and_expression: equality_expression
#line 308 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1159 "mcc_c.tab.c"
    break;

  case 49: // and_expression: and_expression "&" equality_expression
#line 310 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1165 "mcc_c.tab.c"
    break;

  case 50: // exclusive_or_expression: and_expression
#line 315 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1171 "mcc_c.tab.c"
    break;

  case 51: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 317 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1177 "mcc_c.tab.c"
    break;

  case 52: // inclusive_or_expression: exclusive_or_expression
#line 322 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1183 "mcc_c.tab.c"
    break;

  case 53: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 324 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1189 "mcc_c.tab.c"
    break;

  case 54: // logical_and_expression: inclusive_or_expression
#line 328 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1195 "mcc_c.tab.c"
    break;

  case 55: // logical_and_expression: logical_and_expression "||" inclusive_or_expression
#line 330 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1201 "mcc_c.tab.c"
    break;

  case 56: // logical_or_expression: logical_and_expression
#line 335 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1207 "mcc_c.tab.c"
    break;

  case 57: // logical_or_expression: logical_or_expression "&&" logical_and_expression
#line 337 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1213 "mcc_c.tab.c"
    break;

  case 58: // conditional_expression: logical_or_expression
#line 342 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1219 "mcc_c.tab.c"
    break;

  case 59: // $@1: %empty
#line 343 "mcc_c.y"
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
#line 1236 "mcc_c.tab.c"
    break;

  case 60: // conditional_expression: logical_or_expression $@1 "?" expression ":" conditional_expression
#line 343 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[5].value.as < mcc::Symbol > (); }
#line 1242 "mcc_c.tab.c"
    break;

  case 61: // assignment_expression: conditional_expression
#line 360 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=yystack_[0].value.as < mcc::Symbol > ();}
#line 1248 "mcc_c.tab.c"
    break;

  case 62: // $@2: %empty
#line 362 "mcc_c.y"
        {
		if(!yystack_[0].value.as < mcc::Symbol > ().IsLvalue()||yystack_[0].value.as < mcc::Symbol > ().IsConst())
		{mcc::PrintColored("Can only assign to a non-const lvalue",mcc::TextColor::Error);}
	}
#line 1257 "mcc_c.tab.c"
    break;

  case 63: // assignment_expression: unary_expression $@2 assignment_operator assignment_expression
#line 367 "mcc_c.y"
        {
		if(yystack_[3].value.as < mcc::Symbol > ().GetType().index()!=yystack_[0].value.as < mcc::Symbol > ().GetType().index())
		{
			mcc::PrintColored("Cant assign a non primitive to a primitive or vise-versa",mcc::TextColor::Error);
		}
	}
#line 1268 "mcc_c.tab.c"
    break;

  case 75: // expression: assignment_expression
#line 391 "mcc_c.y"
        {yylhs.value.as < mcc::Symbol > ()=mcc::Symbol({yystack_[0].value.as < mcc::Symbol > ().GetType(),yystack_[0].value.as < mcc::Symbol > ().GetIndLevel()},false,true,true);}
#line 1274 "mcc_c.tab.c"
    break;

  case 76: // expression: expression "," assignment_expression
#line 392 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 1280 "mcc_c.tab.c"
    break;

  case 77: // constant_expression: conditional_expression
#line 396 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[0].value.as < mcc::Symbol > (); }
#line 1286 "mcc_c.tab.c"
    break;

  case 78: // declaration: declaration_specifiers ";"
#line 401 "mcc_c.y"
        {mcc::PrintColored("declaration does not declare anything",mcc::TextColor::Warning);}
#line 1292 "mcc_c.tab.c"
    break;

  case 79: // declaration: declaration_specifiers init_declarator_list ";"
#line 403 "mcc_c.y"
        {
		drv.UnsetCurrentType();
	}
#line 1300 "mcc_c.tab.c"
    break;

  case 80: // declaration_specifiers: storage_class_specifier
#line 410 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1309 "mcc_c.tab.c"
    break;

  case 81: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 415 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1317 "mcc_c.tab.c"
    break;

  case 82: // declaration_specifiers: type_specifier
#line 419 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1326 "mcc_c.tab.c"
    break;

  case 83: // declaration_specifiers: type_specifier declaration_specifiers
#line 424 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={yystack_[1].value.as < mcc::T > ()};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1335 "mcc_c.tab.c"
    break;

  case 84: // declaration_specifiers: type_qualifier
#line 429 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());}
#line 1343 "mcc_c.tab.c"
    break;

  case 85: // declaration_specifiers: type_qualifier declaration_specifiers
#line 433 "mcc_c.y"
        {
		yylhs.value.as < mcc::T > ()={yystack_[0].value.as < mcc::T > ()};
		drv.SetCurrentType(yylhs.value.as < mcc::T > ());
	}
#line 1352 "mcc_c.tab.c"
    break;

  case 86: // init_declarator_list: init_declarator
#line 441 "mcc_c.y"
        {drv.SetInConst(false);}
#line 1358 "mcc_c.tab.c"
    break;

  case 87: // init_declarator_list: init_declarator_list "," init_declarator
#line 442 "mcc_c.y"
          { yylhs.value.as < std::vector<mcc::Symbol> > () = yystack_[2].value.as < std::vector<mcc::Symbol> > (); }
#line 1364 "mcc_c.tab.c"
    break;

  case 88: // init_declarator: declarator
#line 447 "mcc_c.y"
        {
		auto sym = mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first,yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second);
	}
#line 1373 "mcc_c.tab.c"
    break;

  case 89: // init_declarator: declarator "=" initializer
#line 452 "mcc_c.y"
        {
		auto sym=mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol(yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().first,yystack_[2].value.as < std::pair<std::string,mcc::Symbol> > ().second);
	}
#line 1382 "mcc_c.tab.c"
    break;

  case 95: // type_specifier: "void"
#line 467 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Void};}
#line 1388 "mcc_c.tab.c"
    break;

  case 96: // type_specifier: "char"
#line 468 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Char};}
#line 1394 "mcc_c.tab.c"
    break;

  case 97: // type_specifier: "short"
#line 469 "mcc_c.y"
                 {yylhs.value.as < mcc::T > ()={mcc::Primitive::Short};}
#line 1400 "mcc_c.tab.c"
    break;

  case 98: // type_specifier: "int"
#line 470 "mcc_c.y"
               {yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};}
#line 1406 "mcc_c.tab.c"
    break;

  case 99: // type_specifier: "long"
#line 471 "mcc_c.y"
                {yylhs.value.as < mcc::T > ()={mcc::Primitive::Long};}
#line 1412 "mcc_c.tab.c"
    break;

  case 100: // type_specifier: "float"
#line 472 "mcc_c.y"
                 {yylhs.value.as < mcc::T > ()={mcc::Primitive::Float};}
#line 1418 "mcc_c.tab.c"
    break;

  case 101: // type_specifier: "double"
#line 473 "mcc_c.y"
                  {yylhs.value.as < mcc::T > ()={mcc::Primitive::Double};}
#line 1424 "mcc_c.tab.c"
    break;

  case 102: // type_specifier: "signed"
#line 474 "mcc_c.y"
                   {yylhs.value.as < mcc::T > ()={mcc::Primitive::Int};}
#line 1430 "mcc_c.tab.c"
    break;

  case 103: // type_specifier: "unsigned"
#line 475 "mcc_c.y"
                    {yylhs.value.as < mcc::T > ()={mcc::Primitive::UInt};}
#line 1436 "mcc_c.tab.c"
    break;

  case 104: // type_specifier: struct_or_union_specifier
#line 476 "mcc_c.y"
                                   {}
#line 1442 "mcc_c.tab.c"
    break;

  case 105: // type_specifier: enum_specifier
#line 477 "mcc_c.y"
                        {}
#line 1448 "mcc_c.tab.c"
    break;

  case 106: // type_specifier: "typename"
#line 479 "mcc_c.y"
                {
			yylhs.value.as < mcc::T > () = drv.GetType(yystack_[0].value.as < std::string > ()).value();
		}
#line 1456 "mcc_c.tab.c"
    break;

  case 115: // specifier_qualifier_list: type_specifier specifier_qualifier_list
#line 504 "mcc_c.y"
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
#line 1472 "mcc_c.tab.c"
    break;

  case 116: // specifier_qualifier_list: type_specifier
#line 516 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();}
#line 1478 "mcc_c.tab.c"
    break;

  case 117: // specifier_qualifier_list: type_qualifier specifier_qualifier_list
#line 518 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()=yystack_[0].value.as < mcc::T > ();}
#line 1484 "mcc_c.tab.c"
    break;

  case 118: // specifier_qualifier_list: type_qualifier
#line 520 "mcc_c.y"
        {yylhs.value.as < mcc::T > ()={true};}
#line 1490 "mcc_c.tab.c"
    break;

  case 124: // struct_declarator: id_or_idptr "(" identifier_list ")"
#line 532 "mcc_c.y"
        {
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
	}
#line 1498 "mcc_c.tab.c"
    break;

  case 132: // type_qualifier: "const"
#line 554 "mcc_c.y"
                 {yylhs.value.as < std::string > ()="const";drv.SetInConst(true);}
#line 1504 "mcc_c.tab.c"
    break;

  case 133: // type_qualifier: "volatile"
#line 555 "mcc_c.y"
                    {yylhs.value.as < std::string > ()="";}
#line 1510 "mcc_c.tab.c"
    break;

  case 134: // declarator: pointer direct_declarator
#line 560 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1518 "mcc_c.tab.c"
    break;

  case 135: // declarator: direct_declarator
#line 564 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()=yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ();
	}
#line 1526 "mcc_c.tab.c"
    break;

  case 136: // id_or_idptr: "identifier"
#line 570 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[0].value.as < std::string > (),{drv.GetCurrentType(),drv.GetInConst(),true,true}};
		//symbol has no indirection, i.e. int arr[] - array of int
	}
#line 1535 "mcc_c.tab.c"
    break;

  case 137: // id_or_idptr: "(" "identifier" ")"
#line 576 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::string > (),{drv.GetCurrentType(),drv.GetInConst(),true,true}};
	}
#line 1543 "mcc_c.tab.c"
    break;

  case 138: // id_or_idptr: "(" pointer "identifier" ")"
#line 582 "mcc_c.y"
        {
		yylhs.value.as < std::pair<std::string,mcc::Symbol> > ()={yystack_[1].value.as < std::string > (),{{drv.GetCurrentType().GetType(),yystack_[2].value.as < mcc::PtrBits > ().GetIndirection()},drv.GetInConst(),true,true}};
	//symbol HAS indirection, i.e int (*arr)[] - POINTER to an array of int
	}
#line 1552 "mcc_c.tab.c"
    break;

  case 139: // array_dim: "[" constant_expression "]"
#line 588 "mcc_c.y"
        {
		yylhs.value.as < std::size_t > ()=1;
	}
#line 1560 "mcc_c.tab.c"
    break;

  case 140: // array_dim: "[" "]"
#line 592 "mcc_c.y"
        {
		yylhs.value.as < std::size_t > ()=0;
	}
#line 1568 "mcc_c.tab.c"
    break;

  case 141: // array_dim_list: array_dim
#line 598 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::size_t> > ()={};
		yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ());
	}
#line 1577 "mcc_c.tab.c"
    break;

  case 142: // array_dim_list: array_dim_list array_dim
#line 603 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::size_t> > ()=yystack_[1].value.as < std::vector<std::size_t> > ();
		yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ());
	}
#line 1586 "mcc_c.tab.c"
    break;

  case 143: // direct_declarator: id_or_idptr
#line 611 "mcc_c.y"
        {
		//this is name of the symbol or type idk
	}
#line 1594 "mcc_c.tab.c"
    break;

  case 144: // direct_declarator: id_or_idptr array_dim_list
#line 616 "mcc_c.y"
        {
		auto as_arr_t = mcc::T{yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetType()}.ToArrT();
		mcc::PrintColored(std::to_string(yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetIndLevel()),mcc::TextColor::Error);
		drv.AddSymbol(yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().first,{{mcc::CArray{as_arr_t,yystack_[0].value.as < std::vector<std::size_t> > ().begin(),yystack_[0].value.as < std::vector<std::size_t> > ().end()},yystack_[1].value.as < std::pair<std::string,mcc::Symbol> > ().second.GetIndLevel()},drv.GetInConst(),true,false});
		mcc::PrintColored("Array:",mcc::TextColor::Good);
	}
#line 1605 "mcc_c.tab.c"
    break;

  case 145: // direct_declarator: id_or_idptr "(" parameter_type_list ")"
#line 623 "mcc_c.y"
        {
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
	}
#line 1613 "mcc_c.tab.c"
    break;

  case 146: // direct_declarator: id_or_idptr "(" ")"
#line 627 "mcc_c.y"
        {

	}
#line 1621 "mcc_c.tab.c"
    break;

  case 147: // pointer: "*"
#line 633 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1630 "mcc_c.tab.c"
    break;

  case 148: // pointer: "*" type_qualifier_list
#line 638 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()={};
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[0].value.as < std::string > ()=="const");
	}
#line 1639 "mcc_c.tab.c"
    break;

  case 149: // pointer: "*" pointer
#line 643 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(false);
	}
#line 1648 "mcc_c.tab.c"
    break;

  case 150: // pointer: "*" type_qualifier_list pointer
#line 648 "mcc_c.y"
        {
		yylhs.value.as < mcc::PtrBits > ()=yystack_[0].value.as < mcc::PtrBits > ();
		yylhs.value.as < mcc::PtrBits > ().AddIndirection(yystack_[1].value.as < std::string > ()=="const");
	}
#line 1657 "mcc_c.tab.c"
    break;

  case 151: // type_qualifier_list: type_qualifier
#line 657 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 1663 "mcc_c.tab.c"
    break;

  case 152: // type_qualifier_list: type_qualifier_list type_qualifier
#line 659 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ()+yystack_[0].value.as < std::string > ();}
#line 1669 "mcc_c.tab.c"
    break;

  case 153: // parameter_type_list: parameter_list
#line 665 "mcc_c.y"
        {
		yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();
	}
#line 1677 "mcc_c.tab.c"
    break;

  case 154: // parameter_type_list: parameter_list "," "..."
#line 669 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[2].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();}
#line 1683 "mcc_c.tab.c"
    break;

  case 155: // parameter_list: parameter_declaration
#line 674 "mcc_c.y"
        {yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()=yystack_[0].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ();}
#line 1689 "mcc_c.tab.c"
    break;

  case 156: // parameter_list: parameter_list "," parameter_declaration
#line 675 "mcc_c.y"
          { yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > () = yystack_[2].value.as < std::vector<std::pair<std::string,mcc::Symbol>> > (); }
#line 1695 "mcc_c.tab.c"
    break;

  case 157: // parameter_declaration: declaration_specifiers declarator
#line 680 "mcc_c.y"
        {
			auto decl = yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second;
			mcc::PrintColored(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first+"\n",mcc::TextColor::Warning);
			yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ()={};
			yylhs.value.as < std::vector<std::pair<std::string,mcc::Symbol>> > ().push_back({yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first,{yystack_[1].value.as < mcc::T > (),drv.GetInConst(),true,true}});
	}
#line 1706 "mcc_c.tab.c"
    break;

  case 160: // type_name: specifier_qualifier_list
#line 694 "mcc_c.y"
          { yylhs.value.as < mcc::T > () = yystack_[0].value.as < mcc::T > (); }
#line 1712 "mcc_c.tab.c"
    break;

  case 161: // type_name: specifier_qualifier_list abstract_declarator
#line 695 "mcc_c.y"
          { yylhs.value.as < mcc::T > () = yystack_[1].value.as < mcc::T > (); }
#line 1718 "mcc_c.tab.c"
    break;

  case 180: // $@3: %empty
#line 729 "mcc_c.y"
          {drv.EnterNewScope("");}
#line 1724 "mcc_c.tab.c"
    break;

  case 181: // statement: $@3 compound_statement
#line 731 "mcc_c.y"
                {drv.LeaveScope();}
#line 1730 "mcc_c.tab.c"
    break;

  case 187: // labeled_statement: "identifier" ":" statement
#line 742 "mcc_c.y"
        {
		drv.AddLabel(yystack_[2].value.as < std::string > ());
	}
#line 1738 "mcc_c.tab.c"
    break;

  case 199: // $@4: %empty
#line 771 "mcc_c.y"
                                 {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1744 "mcc_c.tab.c"
    break;

  case 201: // $@5: %empty
#line 772 "mcc_c.y"
                                                {mcc::EvalsToBool(yystack_[0].value.as < mcc::Symbol > ());}
#line 1750 "mcc_c.tab.c"
    break;

  case 203: // iteration_statement: "for" "(" expression_statement expression_statement ")" statement
#line 775 "mcc_c.y"
        {std::cout<<"param decl\n";}
#line 1756 "mcc_c.tab.c"
    break;

  case 205: // jump_statement: "goto" "identifier" ";"
#line 781 "mcc_c.y"
        {
		drv.AddLabelRef(yystack_[1].value.as < std::string > ());
	}
#line 1764 "mcc_c.tab.c"
    break;

  case 213: // external_declaration: declaration
#line 798 "mcc_c.y"
        {mcc::PrintColored("New global definition",mcc::TextColor::Good);}
#line 1770 "mcc_c.tab.c"
    break;

  case 214: // $@6: %empty
#line 802 "mcc_c.y"
                                                  {drv.EnterNewScope(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first);}
#line 1776 "mcc_c.tab.c"
    break;

  case 215: // function_definition: declaration_specifiers direct_declarator $@6 compound_statement
#line 803 "mcc_c.y"
                {drv.LeaveScope();}
#line 1782 "mcc_c.tab.c"
    break;

  case 216: // $@7: %empty
#line 805 "mcc_c.y"
                {
			if(!mcc::IsFuncPtr(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().second))
			{
				//drv.AddSymbol();
				drv.EnterNewScope(yystack_[0].value.as < std::pair<std::string,mcc::Symbol> > ().first);
			}
			else
			{
			//bad
			}
		}
#line 1798 "mcc_c.tab.c"
    break;

  case 217: // function_definition: direct_declarator $@7 compound_statement
#line 817 "mcc_c.y"
                {drv.LeaveScope();}
#line 1804 "mcc_c.tab.c"
    break;


#line 1808 "mcc_c.tab.c"

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
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "$@3", "labeled_statement", "compound_statement",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "$@4", "$@5", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", "$@6",
  "$@7", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -257;

  const short parser::yytable_ninf_ = -215;

  const short
  parser::yypact_[] =
  {
    1045,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
      12,  -257,    20,  -257,    17,  1250,  1250,  -257,    15,  -257,
    1250,    36,  -257,   842,  -257,  -257,   -23,    37,    -7,    81,
      61,  -257,    28,  -257,    10,    11,    16,  -257,  -257,    25,
    1276,  -257,  1102,   574,  -257,    69,    78,  -257,  -257,    37,
     100,   -45,  -257,  -257,  -257,  -257,    81,   118,  -257,    89,
     589,    78,  -257,  1276,  1276,  1170,  -257,    13,  1276,  -257,
      89,   120,    85,  -257,  -257,  -257,  -257,   714,  -257,  -257,
    -257,  -257,  -257,  -257,   551,  -257,   753,   753,  -257,   139,
    -257,   776,  -257,   146,   106,   189,   105,    33,   132,   149,
     165,   150,    93,  -257,   167,  -257,   296,  -257,   -38,   776,
    -257,    37,  -257,  -257,  -257,  -257,  -257,   589,   749,  -257,
    -257,  -257,  -257,  1207,  -257,  -257,  -257,   776,   136,  -257,
     161,    91,  -257,  -257,  -257,   899,   551,  -257,  -257,   -33,
      -5,   190,   776,  -257,  -257,   612,   253,   776,  -257,  -257,
     263,  -257,   776,   776,   776,   776,   776,   776,   776,   776,
     776,   776,   776,   776,   776,   776,   776,   776,   776,   776,
     182,  -257,   191,   776,   195,   206,   207,   215,   446,   216,
     278,   205,   209,   188,  -257,  -257,   144,  -257,    17,  -257,
      78,  -257,   371,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,   -31,  1287,  -257,  -257,  -257,    13,   776,  1003,  -257,
    -257,   223,  -257,   776,   941,   653,   138,  -257,   151,   776,
    -257,   -26,  -257,  -257,    29,  -257,  -257,  -257,  -257,   146,
     146,   106,   106,   189,   189,   189,   189,   105,   105,    33,
     132,   149,   165,   150,   776,   446,   210,   446,   776,   776,
     776,   264,   481,   214,  -257,  -257,  -257,   156,  -257,  -257,
    -257,  -257,  -257,   222,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,   776,  -257,  -257,  -257,   -25,
    -257,  -257,  -257,   231,   232,  -257,   228,   151,  1144,   676,
    -257,  -257,   776,  -257,   173,  -257,   446,  -257,    64,    70,
     243,   271,   481,  -257,  -257,  -257,  -257,  -257,  -257,   332,
    -257,  -257,  -257,  -257,   272,  -257,   268,  -257,   776,  -257,
     446,   446,   274,   776,   691,  -257,  -257,  -257,  -257,   313,
    -257,   446,   243,   446,    72,   446,  -257,   276,  -257,   446,
    -257,   265,  -257,  -257
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   136,    90,    91,    92,    93,    94,    96,    97,    99,
     102,   103,   100,   101,   132,   133,    95,    98,   110,   111,
       0,   106,     0,   213,     0,    80,    82,   104,     0,   105,
      84,   143,   216,     0,   210,   212,   127,     0,     0,   147,
       0,    78,     0,    86,    88,   135,     0,    81,    83,   109,
       0,    85,     0,     0,   141,   144,     0,     1,   211,     0,
     130,     0,   128,   137,   151,   149,   148,     0,    79,     0,
       0,     0,   134,     0,   116,     0,   112,     0,   118,   146,
       0,     0,   153,   155,     2,     3,     4,     0,    22,    25,
      23,    24,    27,    26,     0,   140,     0,     0,     6,    16,
      28,     0,    30,    34,    37,    40,    45,    48,    50,    52,
      54,    56,    58,    77,     0,   142,   180,   217,     0,     0,
     125,     0,   152,   150,   138,    87,   135,     0,    28,    61,
     174,    89,   215,     0,   115,   108,   113,     0,     0,   119,
     121,   143,   117,   157,   145,     0,     0,    20,    75,     0,
     160,     0,     0,    17,    18,     0,     0,     0,    12,    13,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,     2,     0,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,   191,   194,     0,   186,     0,   192,
       0,   179,   180,   182,   183,   184,   185,   126,   131,   129,
     177,     0,     0,   107,   122,   114,     0,     0,     0,   154,
     156,     0,     5,     0,     0,     0,   162,   161,   163,     0,
       8,     0,    14,    11,     0,    10,    31,    32,    33,    35,
      36,    38,    39,    42,    41,    43,    44,    46,    47,    49,
      51,    53,    55,    57,     0,   180,     0,   180,     0,     0,
       0,     0,     0,     0,   206,   207,   208,     0,   195,   181,
     190,   193,   175,     0,    66,    67,    65,    69,    68,    70,
      71,    72,    73,    74,    64,     0,   120,   123,   158,     0,
      21,    76,   170,     0,     0,   166,     0,   164,     0,     0,
      29,     9,     0,     7,     0,   187,   180,   189,     0,     0,
     199,     0,     0,   205,   209,   176,   178,    63,   124,     0,
     171,   165,   167,   172,     0,   168,     0,    15,     0,   188,
     180,   180,     0,     0,     0,   159,   173,   169,    60,   196,
     198,   180,   201,   180,     0,   180,   200,     0,   203,   180,
     197,     0,   204,   202
  };

  const short
  parser::yypgoto_[] =
  {
    -257,  -257,  -257,  -257,   -52,  -257,   -89,    92,    94,    60,
      90,   166,   169,   172,   174,   164,  -257,   -51,  -257,   -65,
    -257,  -257,   -91,   -87,    27,     0,  -257,   281,  -257,     9,
    -257,  -257,   280,   -62,   -57,  -257,   135,  -257,   297,   234,
     122,   -69,   -68,   305,  -257,   129,   -15,  -257,  -210,  -257,
     217,  -257,   218,   137,   140,  -123,  -257,  -160,  -257,  -257,
     -61,  -257,  -256,  -257,  -257,  -257,  -257,  -257,  -257,   336,
    -257,  -257,  -257
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    98,    99,   231,   128,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   129,   180,   148,
     212,   285,   196,   114,   197,   198,    42,    43,    25,    26,
      27,    28,    75,    76,    77,   138,   139,    29,    61,    62,
      30,    44,    31,    54,    55,   126,    46,    66,    81,    82,
      83,   289,   151,   227,   228,   131,   211,   199,   200,   201,
     117,   202,   203,   204,   205,   332,   347,   206,    33,    34,
      35,    71,    56
  };

  const short
  parser::yytable_[] =
  {
      24,   100,   113,   149,   210,   130,   312,    40,   140,   141,
     132,   143,   161,   136,   293,    36,     1,   134,    49,     1,
       1,   142,   120,    38,    65,    47,    48,    23,   261,   207,
      51,   222,   208,    24,   121,   147,   272,   150,   301,   318,
      60,   121,   271,    59,   153,   154,   223,    39,   273,   100,
     214,   123,    80,   302,   319,   149,   334,    63,   224,    74,
      23,   149,   130,   225,    67,    39,   234,   100,   113,    39,
      70,   136,    39,   236,   237,   238,    22,  -214,    37,    22,
      22,    50,    74,    74,    74,   100,   113,    74,   324,   150,
     232,    73,     1,   137,    41,   305,   256,   307,   303,    52,
      14,    15,   267,    74,    53,    68,   173,    69,   223,   174,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   330,    32,
     287,   100,   113,    39,   331,   226,   349,    53,   296,   269,
     300,    39,    74,   223,   116,    80,   329,   140,   141,   223,
     316,   223,    22,    45,   218,    74,   165,   166,   291,    53,
     119,    64,    32,   304,   145,   100,   113,   308,   309,   310,
     339,   340,    78,   100,   113,    72,   179,   100,   -59,   169,
     170,   346,   124,   348,   144,   350,   171,   172,   122,   352,
     175,    84,    85,    86,    87,    78,    78,    78,   162,   163,
      78,   224,   155,   176,   156,   164,   225,   157,   130,   226,
     158,   159,   326,   215,   298,   216,    78,   160,    80,   299,
     317,   268,   177,   223,    80,    84,    85,    86,    87,   243,
     244,   245,   246,   314,   178,   223,   181,   327,    88,    89,
      90,   217,   342,   344,   167,   168,    91,   100,   113,    92,
      93,    94,   223,   328,   229,    78,   233,   239,   240,    96,
      97,   241,   242,   247,   248,   266,   235,   254,    78,   258,
     259,   255,    88,    89,    90,   257,   100,   338,   260,   262,
      91,   263,   264,    92,    93,    94,   265,   290,   127,   315,
     306,   313,   311,    96,    97,   320,   321,   322,    80,   182,
      85,    86,    87,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   183,   184,
     185,    17,   223,   186,   187,   188,   189,   190,   191,   192,
     193,    18,    19,    20,   333,   335,   336,   337,   341,   345,
     351,   249,   353,   253,    21,   250,    88,    89,    90,   251,
     125,   286,   252,   133,    91,   209,   118,    92,    93,    94,
     115,   294,   220,   194,   221,     0,   297,    96,    97,    58,
       0,     0,     0,   195,   182,    85,    86,    87,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   183,   184,   185,    17,     0,   186,   187,
     188,   189,   190,   191,   192,   193,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,    88,    89,    90,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,    94,     0,     0,     0,   270,     0,
       0,     0,    96,    97,     0,     0,     0,     0,   195,   182,
      85,    86,    87,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   183,   184,
     185,    17,     0,   186,   187,   188,   189,   190,   191,   192,
     193,    18,    19,    20,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,    21,     0,    88,    89,    90,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
       0,     0,     0,   195,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    84,    85,    86,    87,   195,     0,
       0,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,    17,    84,    85,    86,
      87,     0,     0,     0,     0,     0,    18,    19,    20,     0,
       0,     0,    84,    85,    86,    87,     0,     0,     0,    21,
       0,    88,    89,    90,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,    94,    84,    85,    86,    87,     0,
       0,     0,    96,    97,    88,    89,    90,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,    94,     0,    88,
      89,    90,     0,    95,     0,    96,    97,    91,     0,     0,
      92,    93,    94,     0,     0,   127,    84,    85,    86,    87,
      96,    97,    88,    89,    90,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,    94,   230,     0,     0,    84,
      85,    86,    87,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,     0,     0,
       0,     0,     0,    88,    89,    90,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,    94,    84,    85,    86,
      87,     0,   295,     0,    96,    97,    88,    89,    90,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,    94,
       0,    88,    89,    90,     0,   325,     0,    96,    97,    91,
       0,     0,    92,    93,    94,   343,    84,    85,    86,    87,
       0,     0,    96,    97,    88,    89,    90,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,   146,     0,    84,
      85,    86,    87,     0,     0,    96,    97,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,     0,
       0,     0,     0,    88,    89,    90,     0,     0,     0,   -62,
       0,    91,     0,     0,    92,    93,   152,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    88,    89,    90,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,    94,
       0,     0,    57,     0,     0,     1,     0,    96,    97,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,    17,     0,     0,   219,
       0,     0,     0,     0,     0,     0,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   224,   292,   288,     0,     0,   225,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,    21,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    79,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    79,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    21,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,    17,     0,     0,     0,     0,   135,     0,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     0,   213,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    21,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284
  };

  const short
  parser::yycheck_[] =
  {
       0,    53,    53,    94,   127,    70,   262,    22,    77,    77,
      71,    80,   101,    75,   224,     3,     3,    74,     3,     3,
       3,    78,    67,     3,    39,    25,    26,     0,   188,    67,
      30,    64,   119,    33,    79,    87,    67,    94,    64,    64,
       3,    79,   202,    66,    96,    97,    79,    52,    79,   101,
     137,    66,    52,    79,    79,   146,   312,    64,    63,    50,
      33,   152,   127,    68,     3,    52,   157,   119,   119,    52,
      60,   133,    52,   162,   163,   164,    63,    66,    66,    63,
      63,    66,    73,    74,    75,   137,   137,    78,   298,   146,
     155,    66,     3,    80,    77,   255,   183,   257,    69,    63,
      19,    20,   193,    94,    68,    77,    73,    79,    79,    76,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,    64,     0,
     217,   183,   183,    52,    64,   150,    64,    68,   225,   200,
     229,    52,   133,    79,    66,   145,   306,   216,   216,    79,
     273,    79,    63,    24,    63,   146,    50,    51,   223,    68,
      60,    39,    33,   254,    79,   217,   217,   258,   259,   260,
     330,   331,    50,   225,   225,    46,    83,   229,    85,    74,
      75,   341,    64,   343,    64,   345,    81,    82,    66,   349,
      58,     3,     4,     5,     6,    73,    74,    75,    52,    53,
      78,    63,    63,    54,    65,    59,    68,    68,   273,   224,
      71,    72,   299,    77,    63,    79,    94,    78,   218,    68,
     285,    77,    57,    79,   224,     3,     4,     5,     6,   169,
     170,   171,   172,    77,    84,    79,    69,   302,    50,    51,
      52,    80,   333,   334,    55,    56,    58,   299,   299,    61,
      62,    63,    79,    80,    64,   133,     3,   165,   166,    71,
      72,   167,   168,   173,   174,    77,     3,    85,   146,    63,
      63,    80,    50,    51,    52,    80,   328,   328,    63,    63,
      58,     3,    77,    61,    62,    63,    77,    64,    66,    67,
      80,    77,    28,    71,    72,    64,    64,    69,   298,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    79,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    63,     3,    64,    69,    64,    26,
      64,   175,    77,   179,    48,   176,    50,    51,    52,   177,
      69,   216,   178,    73,    58,   121,    59,    61,    62,    63,
      55,   224,   145,    67,   146,    -1,   226,    71,    72,    33,
      -1,    -1,    -1,    77,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,     3,     4,     5,     6,    77,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,     3,     4,     5,     6,    -1,
      -1,    -1,    71,    72,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,    50,
      51,    52,    -1,    69,    -1,    71,    72,    58,    -1,    -1,
      61,    62,    63,    -1,    -1,    66,     3,     4,     5,     6,
      71,    72,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,     3,
       4,     5,     6,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    62,    63,     3,     4,     5,
       6,    -1,    69,    -1,    71,    72,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    50,    51,    52,    -1,    69,    -1,    71,    72,    58,
      -1,    -1,    61,    62,    63,    64,     3,     4,     5,     6,
      -1,    -1,    71,    72,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,     3,
       4,     5,     6,    -1,    -1,    71,    72,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    60,
      -1,    58,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    -1,     0,    -1,    -1,     3,    -1,    71,    72,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,     3,    -1,    -1,    68,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    48,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    64,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    64,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    48,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    67,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    48,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    25,    35,    36,
      37,    48,    63,   110,   111,   114,   115,   116,   117,   123,
     126,   128,   131,   154,   155,   156,     3,    66,     3,    52,
     132,    77,   112,   113,   127,   131,   132,   111,   111,     3,
      66,   111,    63,    68,   129,   130,   158,     0,   155,    66,
       3,   124,   125,    64,   126,   132,   133,     3,    77,    79,
      60,   157,   131,    66,   115,   118,   119,   120,   126,    64,
     111,   134,   135,   136,     3,     4,     5,     6,    50,    51,
      52,    58,    61,    62,    63,    69,    71,    72,    87,    88,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   109,   129,    66,   146,   124,    60,
      67,    79,   126,   132,    64,   113,   131,    66,    90,   103,
     105,   141,   146,   118,   120,    67,   119,    80,   121,   122,
     127,   128,   120,   127,    64,    79,    63,    90,   105,   108,
     120,   138,    63,    90,    90,    63,    65,    68,    71,    72,
      78,    92,    52,    53,    59,    50,    51,    55,    56,    74,
      75,    81,    82,    73,    76,    58,    54,    57,    84,    83,
     104,    69,     3,    22,    23,    24,    27,    28,    29,    30,
      31,    32,    33,    34,    67,    77,   108,   110,   111,   143,
     144,   145,   147,   148,   149,   150,   153,    67,   109,   125,
     141,   142,   106,    67,   109,    77,    79,    80,    63,    70,
     136,   138,    64,    79,    63,    68,   132,   139,   140,    64,
      64,    89,   105,     3,   108,     3,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    96,    96,    97,
      98,    99,   100,   101,    85,    80,   109,    80,    63,    63,
      63,   143,    63,     3,    77,    77,    77,   108,    77,   146,
      67,   143,    67,    79,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    60,   107,   122,   109,     3,   137,
      64,   105,    64,   134,   139,    69,   109,   140,    63,    68,
      92,    64,    79,    69,   108,   143,    80,   143,   108,   108,
     108,    28,   148,    77,    77,    67,   141,   105,    64,    79,
      64,    64,    69,    64,   134,    69,   109,   105,    80,   143,
      64,    64,   151,    63,   148,     3,    64,    69,   103,   143,
     143,    64,   108,    64,   108,    26,   143,   152,   143,    64,
     143,    64,   143,    77
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
     121,   122,   122,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   129,
     129,   130,   130,   131,   131,   131,   131,   132,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   137,   137,
     138,   138,   139,   139,   139,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   143,
     144,   143,   143,   143,   143,   143,   143,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   149,   151,
     150,   152,   150,   150,   150,   153,   153,   153,   153,   153,
     154,   154,   155,   155,   157,   156,   158,   156
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
       3,     1,     2,     3,     4,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       2,     1,     2,     1,     2,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     3,     4,     3,
       3,     2,     1,     2,     1,     2,     5,     7,     5,     0,
       6,     0,     8,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     0,     4,     0,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   144,   144,   164,   168,   172,   179,   183,   201,   215,
     217,   219,   221,   223,   228,   229,   233,   235,   237,   239,
     241,   243,   249,   250,   251,   252,   253,   254,   258,   260,
     265,   267,   268,   269,   273,   276,   277,   281,   284,   285,
     289,   292,   293,   294,   295,   299,   302,   303,   307,   310,
     314,   317,   321,   324,   327,   330,   334,   337,   341,   343,
     343,   359,   362,   361,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   390,   392,   396,   400,   402,
     409,   414,   418,   423,   428,   432,   440,   442,   446,   451,
     459,   460,   461,   462,   463,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   484,   485,   486,
     489,   490,   494,   495,   499,   503,   515,   517,   519,   524,
     525,   529,   530,   531,   531,   539,   540,   541,   545,   546,
     550,   551,   554,   555,   559,   563,   569,   575,   581,   587,
     591,   597,   602,   609,   615,   622,   626,   632,   637,   642,
     647,   656,   658,   664,   668,   673,   675,   679,   689,   690,
     694,   695,   699,   700,   701,   705,   706,   707,   708,   709,
     710,   711,   712,   713,   717,   718,   719,   723,   724,   728,
     729,   729,   732,   733,   734,   735,   736,   741,   745,   746,
     751,   752,   756,   757,   760,   761,   765,   766,   767,   771,
     771,   772,   772,   773,   776,   780,   784,   785,   786,   787,
     791,   792,   796,   797,   802,   802,   805,   804
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
#line 2840 "mcc_c.tab.c"

#line 820 "mcc_c.y"

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
