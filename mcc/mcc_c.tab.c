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
#line 123 "mcc_c.y"

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
      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.YY_MOVE_OR_COPY< mcc::Symbol > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.YY_MOVE_OR_COPY< mcc::type_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.YY_MOVE_OR_COPY< std::vector<mcc::Symbol> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.move< mcc::Symbol > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.move< mcc::type_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<mcc::Symbol> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.copy< mcc::Symbol > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< mcc::type_t > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.copy< std::vector<mcc::Symbol> > (that.value);
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.copy< std::vector<std::string> > (that.value);
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
      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_init_declarator: // init_declarator
        value.move< mcc::Symbol > (that.value);
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        value.move< mcc::type_t > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        value.move< std::vector<mcc::Symbol> > (that.value);
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (that.value);
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
      case symbol_kind::S_CONSTANT: // "constant"
      case symbol_kind::S_STRING_LITERAL: // "literal"
      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_init_declarator: // init_declarator
        yylhs.value.emplace< mcc::Symbol > ();
        break;

      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_type_specifier: // type_specifier
        yylhs.value.emplace< mcc::type_t > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
        yylhs.value.emplace< std::vector<mcc::Symbol> > ();
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        yylhs.value.emplace< std::vector<std::string> > ();
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
#line 131 "mcc_c.y"
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

			}
			else
			{
				yylhs.value.as < mcc::Symbol > ()={};
			mcc::PrintColored("No such identifier: "+drv.GetCurrentScope()+yystack_[0].value.as < std::string > (),mcc::TextColor::Error);
			drv.DumpSymbols();
			}
		}
	}
#line 707 "mcc_c.tab.c"
    break;

  case 3: // primary_expression: "constant"
#line 153 "mcc_c.y"
        {
		mcc::PrintColored("Numeric const",mcc::TextColor::Good);
		yylhs.value.as < mcc::Symbol > ()={mcc::Primitive::Int,0,true,true,true};
	}
#line 716 "mcc_c.tab.c"
    break;

  case 4: // primary_expression: "literal"
#line 158 "mcc_c.y"
        {
		mcc::PrintColored("String literal",mcc::TextColor::Good);
		yylhs.value.as < mcc::Symbol > ()={mcc::Primitive::Char,1,true,true,true};
	}
#line 725 "mcc_c.tab.c"
    break;

  case 5: // primary_expression: "(" expression ")"
#line 163 "mcc_c.y"
        {
	yylhs.value.as < mcc::Symbol > ()=yystack_[1].value.as < mcc::Symbol > ();
	}
#line 733 "mcc_c.tab.c"
    break;

  case 6: // postfix_expression: primary_expression
#line 169 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[0].value.as < mcc::Symbol > (); }
#line 739 "mcc_c.tab.c"
    break;

  case 7: // postfix_expression: postfix_expression "[" expression "]"
#line 171 "mcc_c.y"
        {
		mcc::PrintColored("Array or ptr subscript operation",mcc::TextColor::Good);
		const auto is_sub_int = mcc::IsIntegerT(yystack_[1].value.as < mcc::Symbol > ().GetType());
		const auto ind = yystack_[1].value.as < mcc::Symbol > ().GetType().index();
		mcc::PrintColored(std::to_string(ind),mcc::TextColor::Error);
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
#line 761 "mcc_c.tab.c"
    break;

  case 8: // postfix_expression: postfix_expression "(" ")"
#line 189 "mcc_c.y"
        {mcc::PrintColored("Function call with no args",mcc::TextColor::Good);}
#line 767 "mcc_c.tab.c"
    break;

  case 9: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 191 "mcc_c.y"
        {mcc::PrintColored("Function call with args",mcc::TextColor::Good);}
#line 773 "mcc_c.tab.c"
    break;

  case 10: // postfix_expression: postfix_expression "." "identifier"
#line 193 "mcc_c.y"
        {mcc::PrintColored("Non ptr struct or union field access",mcc::TextColor::Good);}
#line 779 "mcc_c.tab.c"
    break;

  case 11: // postfix_expression: postfix_expression "->" "identifier"
#line 195 "mcc_c.y"
        {mcc::PrintColored("Ptr struct or union field access",mcc::TextColor::Good);}
#line 785 "mcc_c.tab.c"
    break;

  case 12: // postfix_expression: postfix_expression "++"
#line 197 "mcc_c.y"
        {mcc::PrintColored("Postfix increment",mcc::TextColor::Good);}
#line 791 "mcc_c.tab.c"
    break;

  case 13: // postfix_expression: postfix_expression "--"
#line 199 "mcc_c.y"
        {mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);}
#line 797 "mcc_c.tab.c"
    break;

  case 74: // expression: expression "," assignment_expression
#line 314 "mcc_c.y"
          { yylhs.value.as < mcc::Symbol > () = yystack_[2].value.as < mcc::Symbol > (); }
#line 803 "mcc_c.tab.c"
    break;

  case 76: // declaration: declaration_specifiers ";"
#line 323 "mcc_c.y"
        {mcc::PrintColored("declaration does not declare anything",mcc::TextColor::Warning);}
#line 809 "mcc_c.tab.c"
    break;

  case 77: // declaration: declaration_specifiers init_declarator_list ";"
#line 325 "mcc_c.y"
        {
		const auto t = yystack_[2].value.as < mcc::type_t > ();
		drv.UnsetCurrentType();
	}
#line 818 "mcc_c.tab.c"
    break;

  case 78: // declaration_specifiers: storage_class_specifier
#line 333 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Int;drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 824 "mcc_c.tab.c"
    break;

  case 79: // declaration_specifiers: storage_class_specifier declaration_specifiers
#line 335 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=yystack_[0].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 830 "mcc_c.tab.c"
    break;

  case 80: // declaration_specifiers: type_specifier
#line 337 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=yystack_[0].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 836 "mcc_c.tab.c"
    break;

  case 81: // declaration_specifiers: type_specifier declaration_specifiers
#line 339 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=yystack_[1].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 842 "mcc_c.tab.c"
    break;

  case 82: // declaration_specifiers: type_qualifier
#line 341 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Int;drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 848 "mcc_c.tab.c"
    break;

  case 83: // declaration_specifiers: type_qualifier declaration_specifiers
#line 343 "mcc_c.y"
        { yylhs.value.as < mcc::type_t > ()=yystack_[0].value.as < mcc::type_t > ();drv.SetCurrentType(yylhs.value.as < mcc::type_t > ());}
#line 854 "mcc_c.tab.c"
    break;

  case 85: // init_declarator_list: init_declarator_list "," init_declarator
#line 348 "mcc_c.y"
          { yylhs.value.as < std::vector<mcc::Symbol> > () = yystack_[2].value.as < std::vector<mcc::Symbol> > (); }
#line 860 "mcc_c.tab.c"
    break;

  case 86: // init_declarator: declarator
#line 353 "mcc_c.y"
        {
		mcc::PrintColored("New decl "+yystack_[0].value.as < std::string > (),mcc::TextColor::Good);
		mcc::PrintColored("Type "+std::string(std::holds_alternative<mcc::Primitive>(drv.GetCurrentType())?"primitive":"amogus"),mcc::TextColor::Good);
		auto sym = mcc::Symbol{drv.GetCurrentType(),0,false,true,true};
		drv.AddSymbol(yystack_[0].value.as < std::string > (),std::move(sym));
	}
#line 871 "mcc_c.tab.c"
    break;

  case 87: // init_declarator: declarator "=" initializer
#line 360 "mcc_c.y"
        {
		mcc::PrintColored("Type "+std::string(std::holds_alternative<mcc::Primitive>(drv.GetCurrentType())?"primitive":"amogus"),mcc::TextColor::Good);
		mcc::PrintColored("New decl "+yystack_[2].value.as < std::string > (),mcc::TextColor::Good);
		auto sym=mcc::Symbol{drv.GetCurrentType(),0,false,true,true};
		drv.AddSymbol(yystack_[2].value.as < std::string > (),std::move(sym));
	}
#line 882 "mcc_c.tab.c"
    break;

  case 93: // type_specifier: "void"
#line 378 "mcc_c.y"
        {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Void;}
#line 888 "mcc_c.tab.c"
    break;

  case 94: // type_specifier: "char"
#line 379 "mcc_c.y"
                {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Char;}
#line 894 "mcc_c.tab.c"
    break;

  case 95: // type_specifier: "short"
#line 380 "mcc_c.y"
                 {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Short;}
#line 900 "mcc_c.tab.c"
    break;

  case 96: // type_specifier: "int"
#line 381 "mcc_c.y"
               {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Int;}
#line 906 "mcc_c.tab.c"
    break;

  case 97: // type_specifier: "long"
#line 382 "mcc_c.y"
                {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Long;}
#line 912 "mcc_c.tab.c"
    break;

  case 98: // type_specifier: "float"
#line 383 "mcc_c.y"
                 {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Float;}
#line 918 "mcc_c.tab.c"
    break;

  case 99: // type_specifier: "double"
#line 384 "mcc_c.y"
                  {yylhs.value.as < mcc::type_t > ()=mcc::Primitive::Double;}
#line 924 "mcc_c.tab.c"
    break;

  case 100: // type_specifier: "signed"
#line 386 "mcc_c.y"
        {}
#line 930 "mcc_c.tab.c"
    break;

  case 101: // type_specifier: "unsigned"
#line 387 "mcc_c.y"
                    {}
#line 936 "mcc_c.tab.c"
    break;

  case 102: // type_specifier: struct_or_union_specifier
#line 388 "mcc_c.y"
                                   {}
#line 942 "mcc_c.tab.c"
    break;

  case 103: // type_specifier: enum_specifier
#line 389 "mcc_c.y"
                        {}
#line 948 "mcc_c.tab.c"
    break;

  case 104: // type_specifier: "typename"
#line 390 "mcc_c.y"
                    {}
#line 954 "mcc_c.tab.c"
    break;

  case 129: // type_qualifier: "const"
#line 447 "mcc_c.y"
                 {drv.SetInConst(true);}
#line 960 "mcc_c.tab.c"
    break;

  case 130: // type_qualifier: "volatile"
#line 448 "mcc_c.y"
                    {}
#line 966 "mcc_c.tab.c"
    break;

  case 131: // declarator: pointer direct_declarator
#line 453 "mcc_c.y"
        {
		yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
	}
#line 974 "mcc_c.tab.c"
    break;

  case 132: // declarator: direct_declarator
#line 457 "mcc_c.y"
        {
		yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
	}
#line 982 "mcc_c.tab.c"
    break;

  case 133: // direct_declarator: "identifier"
#line 464 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 988 "mcc_c.tab.c"
    break;

  case 134: // direct_declarator: "(" declarator ")"
#line 466 "mcc_c.y"
        {yylhs.value.as < std::string > ()=yystack_[1].value.as < std::string > ();}
#line 994 "mcc_c.tab.c"
    break;

  case 135: // direct_declarator: direct_declarator "[" constant_expression "]"
#line 468 "mcc_c.y"
        {
		mcc::PrintColored("Array def:",mcc::TextColor::Good);
		drv.AddSymbol(yystack_[3].value.as < std::string > (),mcc::Symbol{drv.GetCurrentType(),1,true,true,true});
	}
#line 1003 "mcc_c.tab.c"
    break;

  case 136: // direct_declarator: direct_declarator "[" "]"
#line 473 "mcc_c.y"
        {
		mcc::PrintColored("Array def VLA:",mcc::TextColor::Good);
	}
#line 1011 "mcc_c.tab.c"
    break;

  case 137: // direct_declarator: direct_declarator "(" parameter_type_list ")"
#line 477 "mcc_c.y"
          { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > (); }
#line 1017 "mcc_c.tab.c"
    break;

  case 138: // direct_declarator: direct_declarator "(" identifier_list ")"
#line 479 "mcc_c.y"
        {
	mcc::PrintColored("Function call:" +yystack_[3].value.as < std::string > (),mcc::TextColor::Good);
	}
#line 1025 "mcc_c.tab.c"
    break;

  case 139: // direct_declarator: direct_declarator "(" ")"
#line 482 "mcc_c.y"
          { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > (); }
#line 1031 "mcc_c.tab.c"
    break;

  case 153: // identifier_list: "identifier"
#line 516 "mcc_c.y"
        {
		 yylhs.value.as < std::vector<std::string> > ()={};
		 yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
		 mcc::PrintColored("Id"+yystack_[0].value.as < std::string > (),mcc::TextColor::Good);
	}
#line 1041 "mcc_c.tab.c"
    break;

  case 154: // identifier_list: identifier_list "," "identifier"
#line 522 "mcc_c.y"
        {
		yystack_[2].value.as < std::vector<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
		yylhs.value.as < std::vector<std::string> > ()=std::move(yystack_[2].value.as < std::vector<std::string> > ());
		for(auto && id : yylhs.value.as < std::vector<std::string> > ())
		{
			mcc::PrintColored("Id:"+id,mcc::TextColor::Good);
		}
	}
#line 1054 "mcc_c.tab.c"
    break;

  case 175: // $@1: %empty
#line 568 "mcc_c.y"
          {drv.EnterNewScope("");}
#line 1060 "mcc_c.tab.c"
    break;

  case 176: // statement: $@1 compound_statement
#line 570 "mcc_c.y"
                {drv.LeaveScope();}
#line 1066 "mcc_c.tab.c"
    break;

  case 208: // external_declaration: declaration
#line 631 "mcc_c.y"
        {mcc::PrintColored("New global definition",mcc::TextColor::Good);}
#line 1072 "mcc_c.tab.c"
    break;

  case 209: // $@2: %empty
#line 635 "mcc_c.y"
                                                             {mcc::PrintColored("Entered new scope: "+ yystack_[1].value.as < std::string > (),mcc::TextColor::Good);drv.EnterNewScope(yystack_[1].value.as < std::string > ());}
#line 1078 "mcc_c.tab.c"
    break;

  case 210: // function_definition: declaration_specifiers declarator declaration_list $@2 compound_statement
#line 636 "mcc_c.y"
                {drv.LeaveScope();}
#line 1084 "mcc_c.tab.c"
    break;

  case 211: // $@3: %empty
#line 637 "mcc_c.y"
                                            {mcc::PrintColored("Entered new scope: "+yystack_[0].value.as < std::string > (),mcc::TextColor::Good);drv.EnterNewScope(yystack_[0].value.as < std::string > ());}
#line 1090 "mcc_c.tab.c"
    break;

  case 212: // function_definition: declaration_specifiers declarator $@3 compound_statement
#line 638 "mcc_c.y"
                {drv.LeaveScope();}
#line 1096 "mcc_c.tab.c"
    break;

  case 213: // $@4: %empty
#line 639 "mcc_c.y"
                                      {mcc::PrintColored("Entered new scope: "+yystack_[1].value.as < std::string > (),mcc::TextColor::Good);drv.EnterNewScope(yystack_[1].value.as < std::string > ());}
#line 1102 "mcc_c.tab.c"
    break;

  case 214: // function_definition: declarator declaration_list $@4 compound_statement
#line 640 "mcc_c.y"
                {drv.LeaveScope();}
#line 1108 "mcc_c.tab.c"
    break;

  case 215: // $@5: %empty
#line 641 "mcc_c.y"
                     {mcc::PrintColored("Entered new scope"+yystack_[0].value.as < std::string > (),mcc::TextColor::Good);drv.EnterNewScope(yystack_[0].value.as < std::string > ());}
#line 1114 "mcc_c.tab.c"
    break;

  case 216: // function_definition: declarator $@5 compound_statement
#line 642 "mcc_c.y"
        {drv.LeaveScope();}
#line 1120 "mcc_c.tab.c"
    break;


#line 1124 "mcc_c.tab.c"

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
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "$@1", "labeled_statement",
  "compound_statement", "statement_list", "declaration_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "$@2", "$@3", "$@4", "$@5", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -225;

  const short parser::yytable_ninf_ = -212;

  const short
  parser::yypact_[] =
  {
    1116,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
      16,  -225,    36,    56,  -225,    51,  1339,  1339,  -225,    21,
    -225,  1339,  1339,     3,    22,   913,  -225,  -225,   -29,    11,
    -225,  -225,    36,   -14,  -225,   115,  -225,  1173,  -225,  -225,
      -2,  1365,  -225,  -225,    51,  1339,    38,  1074,   607,     3,
    -225,  -225,    11,    67,   -37,  -225,  -225,  -225,  -225,  -225,
      56,   630,  1339,    38,  1365,  1365,  1259,  -225,    37,  1365,
     119,  -225,    38,   283,  -225,  -225,  -225,    13,   129,   138,
    -225,    -4,  -225,  -225,  -225,   193,  -225,  -225,  -225,  -225,
    -225,  -225,   566,  -225,   770,   770,  -225,   -27,  -225,   785,
    -225,   131,    84,   120,   140,    98,   169,   209,   210,   182,
     126,  -225,   199,    53,   785,  -225,    11,  -225,   630,  1376,
    -225,  -225,  -225,    38,  -225,  1296,  -225,  -225,  -225,   785,
     160,  -225,   192,  -225,  -225,   194,   785,   195,   213,   214,
     217,   433,   218,   270,   205,   207,   468,  -225,  -225,  -225,
     163,  -225,  -225,    38,  -225,   358,  -225,  -225,  -225,  -225,
     851,   668,  -225,    10,  -225,    62,  -225,   970,  -225,   280,
     566,  -225,    34,    -5,   245,   785,  -225,  -225,   694,   318,
     785,  -225,  -225,   319,  -225,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,  -225,  -225,  -225,  -225,  -225,   101,
    -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,   785,  -225,  -225,  -225,  -225,    37,   785,   433,   243,
     433,   785,   785,   785,   297,   496,   249,  -225,  -225,  -225,
     181,  -225,   785,  -225,  -225,  -225,  -225,   263,   264,  -225,
     260,    62,  1233,   709,  -225,  -225,  -225,   268,  -225,  1012,
      68,  -225,   785,  -225,    45,  -225,  -225,   -46,  -225,  -225,
    -225,  -225,   131,   131,    84,    84,   120,   120,   120,   120,
     140,   140,    98,   169,   209,   210,   182,   124,  -225,   589,
    -225,  -225,  -225,  -225,   433,  -225,    47,    54,    58,   273,
     496,  -225,  -225,  -225,  -225,  -225,  -225,  -225,   274,  -225,
     271,  -225,  -225,  -225,   785,  -225,   785,  -225,  -225,  -225,
     433,   433,   433,   785,   744,  -225,  -225,  -225,  -225,   311,
    -225,  -225,    59,   433,    99,   433,   262,  -225,   433,  -225,
    -225,  -225
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   133,    88,    89,    90,    91,    92,    94,    95,    97,
     100,   101,    98,    99,   129,   130,    93,    96,   108,   109,
       0,   104,   140,     0,   208,     0,    78,    80,   102,     0,
     103,    82,   215,   132,     0,     0,   205,   207,   124,     0,
     144,   142,   141,     0,    76,     0,    84,    86,    79,    81,
     107,     0,    83,   189,     0,   213,     0,     0,     0,   131,
       1,   206,     0,   127,     0,   125,   145,   143,   134,    77,
       0,     0,   209,     0,     0,   114,     0,   110,     0,   116,
      86,   190,     0,   175,   216,   153,   139,   152,     0,   146,
     148,     0,     2,     3,     4,     0,    22,    25,    23,    24,
      27,    26,     0,   136,     0,     0,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      58,    75,     0,     0,     0,   122,     0,    85,     0,    28,
      60,   169,    87,     0,   212,     0,   113,   106,   111,     0,
       0,   117,   119,   115,   214,     2,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,   186,   191,    73,
       0,   181,   187,     0,   174,   175,   177,   178,   179,   180,
       0,     0,   150,   157,   151,   158,   137,     0,   138,     0,
       0,    20,     0,   155,     0,     0,    17,    18,     0,     0,
       0,    12,    13,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   123,   128,   126,   172,     0,
      64,    65,    63,    67,    66,    68,    69,    70,    71,    72,
      62,     0,   210,   105,   120,   112,     0,     0,   175,     0,
     175,     0,     0,     0,     0,     0,     0,   201,   202,   203,
       0,   192,     0,   176,   185,   188,   165,     0,     0,   161,
       0,   159,     0,     0,   147,   149,   154,     0,     5,     0,
     157,   156,     0,     8,     0,    14,    11,     0,    10,    31,
      32,    33,    35,    36,    38,    39,    42,    41,    43,    44,
      46,    47,    49,    51,    53,    55,    57,     0,   170,     0,
      61,   118,   121,   182,   175,   184,     0,     0,     0,     0,
       0,   200,   204,    74,   166,   160,   162,   167,     0,   163,
       0,    21,    29,     9,     0,     7,     0,   171,   173,   183,
     175,   175,   175,     0,     0,   168,   164,    15,    59,   193,
     195,   196,     0,   175,     0,   175,     0,   198,   175,   194,
     197,   199
  };

  const short
  parser::yypgoto_[] =
  {
    -225,  -225,  -225,  -225,   -56,  -225,  -103,    14,    30,    31,
      41,   134,   139,   133,   136,   137,  -225,   -55,   -67,  -225,
     -84,   -72,   206,     0,  -225,   281,  -225,   150,  -225,  -225,
     278,   -33,   -68,  -225,   117,  -225,   294,   231,   144,    -8,
      -6,   -10,  -225,   -52,  -225,   219,  -225,   178,   -78,  -163,
    -127,  -225,  -143,  -225,  -225,   -53,  -225,   312,  -224,  -225,
    -225,  -225,  -225,   349,  -225,  -225,  -225,  -225,  -225
  };

  const short
  parser::yydefgoto_[] =
  {
       0,   106,   107,   274,   129,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   130,   159,   231,
     160,   122,   161,    54,    45,    46,    26,    27,    28,    29,
      76,    77,    78,   140,   141,    30,    64,    65,    31,    32,
      33,    34,    42,   257,    89,    90,    91,   184,   258,   175,
     132,   219,   162,   163,   164,    84,   165,    55,   166,   167,
     168,   169,    35,    36,    37,   133,    73,    82,    56
  };

  const short
  parser::yytable_[] =
  {
      25,   218,   108,   121,   131,    88,   194,   136,   244,   174,
     261,   143,    41,     1,    63,    43,     1,    47,   182,    38,
     134,   310,   255,   325,    50,     1,    48,    49,    59,   144,
     125,    52,    67,   252,   183,    25,   188,    62,   189,   181,
       1,   190,   126,   138,   191,   192,    80,    22,   186,   187,
      68,   193,   216,   108,     1,    14,    15,    87,   269,     1,
     178,   131,    80,   171,    74,    22,    57,   234,   108,   121,
     142,    58,   250,   170,   239,   179,   170,   173,   171,   172,
     232,   171,    39,   108,   121,    23,   334,    51,    22,    22,
     108,   121,   279,   280,   281,   303,   182,   305,   268,   260,
      23,   182,   138,    22,    83,   271,   277,   261,    22,   323,
     253,   330,   183,   252,    23,   108,   121,   139,   331,    23,
     215,   275,   332,   346,   324,   262,   252,   124,    44,   297,
     263,   269,   126,   252,   198,   199,   171,   252,   252,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   306,   307,   308,
     173,   329,    43,   348,   300,   302,    40,    59,   298,   322,
      87,   206,   328,   270,   207,   200,   201,    87,   252,    71,
     299,   108,   121,   195,   196,   313,    66,   339,   340,   341,
     197,   320,    69,   176,    70,    79,    92,    93,    94,    95,
     347,    75,   349,   252,   326,   351,    24,   108,   121,   212,
     318,   213,   282,   283,   202,   203,   108,   177,    79,    79,
      79,   204,   205,    79,    75,    75,    75,   208,   142,    75,
     284,   285,   131,   286,   287,   288,   289,   235,    53,   236,
     251,    24,   252,    96,    97,    98,    79,   290,   291,   342,
     344,    99,    75,    53,   100,   101,   180,   337,   312,   270,
     252,    81,    87,   209,   104,   105,   211,   210,   214,    87,
     108,   338,   237,   246,   238,   240,   241,   242,    81,    79,
     243,   245,   247,   266,   248,    75,   145,    93,    94,    95,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   146,   147,   148,    17,   272,
     149,   150,   151,   152,   153,   154,   155,   156,    18,    19,
      20,   276,   278,   304,    79,   309,   311,   314,   315,   316,
      75,    21,   321,    96,    97,    98,   333,   345,   335,   350,
     336,    99,   292,   294,   100,   101,   102,   295,   293,   296,
     157,   127,   135,   301,   104,   105,   123,   217,   267,    72,
     158,   145,    93,    94,    95,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     146,   147,   148,    17,    61,   149,   150,   151,   152,   153,
     154,   155,   156,    18,    19,    20,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    96,    97,
      98,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,   102,     0,     0,     0,   254,     0,     0,     0,   104,
     105,     0,     0,     0,     0,   158,   145,    93,    94,    95,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   146,   147,   148,    17,     0,
     149,   150,   151,   152,   153,   154,   155,   156,    18,    19,
      20,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,    21,     0,    96,    97,    98,     0,     0,     0,     0,
       0,    99,     0,     0,   100,   101,   102,     0,     0,    92,
      93,    94,    95,     0,   104,   105,     0,     0,     0,     0,
     158,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,   104,
     105,     0,     0,     0,     0,   249,    96,    97,    98,     0,
       0,     0,     0,     0,    99,     0,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,   104,   105,    92,
      93,    94,    95,   158,     0,     0,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,    17,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    21,     0,    96,    97,    98,     0,
       0,     0,     0,     0,    99,     0,     0,   100,   101,   102,
       0,     0,     0,    92,    93,    94,    95,   104,   105,    96,
      97,    98,     0,     0,     0,     0,     0,    99,     0,     0,
     100,   101,   102,     0,     0,   128,   327,    96,    97,    98,
     104,   105,     0,     0,     0,    99,     0,     0,   100,   101,
     102,    92,    93,    94,    95,     0,   103,     0,   104,   105,
      96,    97,    98,     0,     0,     0,     0,     0,    99,     0,
       0,   100,   101,   102,     0,     0,   128,    92,    93,    94,
      95,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,     0,    96,    97,
      98,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,   102,     0,     0,     0,     0,     0,   259,     0,   104,
     105,     0,     0,     0,    96,    97,    98,    92,    93,    94,
      95,     0,    99,     0,     0,   100,   101,   102,   273,    96,
      97,    98,     0,     0,     0,   104,   105,    99,     0,     0,
     100,   101,   102,    92,    93,    94,    95,     0,   319,     0,
     104,   105,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,     0,    96,    97,    98,     0,     0,     0,
       0,     0,    99,     0,     0,   100,   101,   102,   343,     0,
       0,     0,     0,     0,     0,   104,   105,     0,     0,     0,
      96,    97,    98,     0,     0,     0,     0,     0,    99,     0,
       0,   100,   101,   185,     0,    96,    97,    98,     0,     0,
       0,   104,   105,    99,     0,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     1,     0,   104,   105,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,   170,   256,     1,     0,     0,   171,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,    17,     0,     0,
     264,     0,     0,     0,     0,     0,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,   256,    85,     0,     0,
     171,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,    21,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    86,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,     0,     0,     0,  -211,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    21,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,   317,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,    17,     0,     0,     0,     0,   137,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,   233,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    21,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230
  };

  const short
  parser::yycheck_[] =
  {
       0,   128,    58,    58,    71,    57,   109,    75,   151,    87,
     173,    79,    22,     3,     3,    23,     3,    25,   102,     3,
      73,   245,   165,    69,     3,     3,    26,    27,    34,    82,
      67,    31,    42,    79,   102,    35,    63,    66,    65,    95,
       3,    68,    79,    76,    71,    72,    54,    52,   104,   105,
      64,    78,   124,   109,     3,    19,    20,    57,    63,     3,
      64,   128,    70,    68,    66,    52,    63,   139,   124,   124,
      78,    68,   156,    63,   146,    79,    63,    87,    68,    87,
     133,    68,    66,   139,   139,    63,   310,    66,    52,    52,
     146,   146,   195,   196,   197,   238,   180,   240,    64,   171,
      63,   185,   135,    52,    66,   183,   190,   270,    52,    64,
     163,    64,   180,    79,    63,   171,   171,    80,    64,    63,
      67,   188,    64,    64,    79,    63,    79,    60,    77,   213,
      68,    63,    79,    79,    50,    51,    68,    79,    79,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   241,   242,   243,
     170,   304,   170,    64,   231,   237,    22,   173,    67,   272,
     170,    73,   299,   183,    76,    55,    56,   177,    79,    60,
      79,   237,   237,    52,    53,   252,    42,   330,   331,   332,
      59,   263,    77,    64,    79,    51,     3,     4,     5,     6,
     343,    51,   345,    79,    80,   348,     0,   263,   263,    83,
     262,    85,   198,   199,    74,    75,   272,    79,    74,    75,
      76,    81,    82,    79,    74,    75,    76,    58,   236,    79,
     200,   201,   299,   202,   203,   204,   205,    77,    32,    79,
      77,    35,    79,    50,    51,    52,   102,   206,   207,   333,
     334,    58,   102,    47,    61,    62,    63,   324,    77,   269,
      79,    55,   262,    54,    71,    72,    84,    57,    69,   269,
     326,   326,    80,     3,    80,    80,    63,    63,    72,   135,
      63,    63,    77,     3,    77,   135,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    64,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     3,     3,    80,   180,    28,    77,    64,    64,    69,
     180,    48,    64,    50,    51,    52,    63,    26,    64,    77,
      69,    58,   208,   210,    61,    62,    63,   211,   209,   212,
      67,    70,    74,   236,    71,    72,    62,   126,   180,    47,
      77,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    35,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    77,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    62,    63,    -1,    -1,     3,
       4,     5,     6,    -1,    71,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    77,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,     3,
       4,     5,     6,    77,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    48,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,     3,     4,     5,     6,    71,    72,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    63,    -1,    -1,    66,    67,    50,    51,    52,
      71,    72,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      63,     3,     4,     5,     6,    -1,    69,    -1,    71,    72,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    -1,    -1,    66,     3,     4,     5,
       6,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    50,    51,    52,     3,     4,     5,
       6,    -1,    58,    -1,    -1,    61,    62,    63,    64,    50,
      51,    52,    -1,    -1,    -1,    71,    72,    58,    -1,    -1,
      61,    62,    63,     3,     4,     5,     6,    -1,    69,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    -1,    50,    51,    52,    -1,    -1,
      -1,    71,    72,    58,    -1,    -1,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    71,    72,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    63,    64,     3,    -1,    -1,    68,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,     3,    -1,    -1,
      68,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    48,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    64,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    48,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    67,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    48,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    25,    35,    36,
      37,    48,    52,    63,   108,   109,   112,   113,   114,   115,
     121,   124,   125,   126,   127,   148,   149,   150,     3,    66,
     124,   127,   128,   125,    77,   110,   111,   125,   109,   109,
       3,    66,   109,   108,   109,   143,   154,    63,    68,   126,
       0,   149,    66,     3,   122,   123,   124,   127,    64,    77,
      79,    60,   143,   152,    66,   113,   116,   117,   118,   124,
     125,   108,   153,    66,   141,     3,    64,   109,   129,   130,
     131,   132,     3,     4,     5,     6,    50,    51,    52,    58,
      61,    62,    63,    69,    71,    72,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   107,   122,    60,    67,    79,   111,    66,    90,
     103,   104,   136,   151,   141,   116,   118,    67,   117,    80,
     119,   120,   125,   118,   141,     3,    22,    23,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    67,    77,   104,
     106,   108,   138,   139,   140,   142,   144,   145,   146,   147,
      63,    68,   125,   127,   134,   135,    64,    79,    64,    79,
      63,    90,   106,   118,   133,    63,    90,    90,    63,    65,
      68,    71,    72,    78,    92,    52,    53,    59,    50,    51,
      55,    56,    74,    75,    81,    82,    73,    76,    58,    54,
      57,    84,    83,    85,    69,    67,   107,   123,   136,   137,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      60,   105,   141,    67,   107,    77,    79,    80,    80,   107,
      80,    63,    63,    63,   138,    63,     3,    77,    77,    77,
     106,    77,    79,   141,    67,   138,    64,   129,   134,    69,
     107,   135,    63,    68,    70,   131,     3,   133,    64,    63,
     127,   134,    64,    64,    89,   104,     3,   106,     3,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    98,    99,   100,   101,   106,    67,    79,
     104,   120,   107,   138,    80,   138,   106,   106,   106,    28,
     144,    77,    77,   104,    64,    64,    69,    64,   129,    69,
     107,    64,    92,    64,    79,    69,    80,    67,   136,   138,
      64,    64,    64,    63,   144,    64,    69,   104,   103,   138,
     138,   138,   106,    64,   106,    26,    64,   138,    64,   138,
      77,   138
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   106,   106,   107,   108,   108,   109,   109,
     109,   109,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   117,   118,   118,   118,   118,   119,   119,   120,
     120,   120,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   136,
     136,   136,   137,   137,   138,   139,   138,   138,   138,   138,
     138,   138,   140,   140,   140,   141,   141,   142,   142,   143,
     143,   144,   144,   145,   145,   145,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   151,
     150,   152,   150,   153,   150,   154,   150
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     3,     4,     3,     3,     2,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     0,
       5,     0,     4,     0,     4,     0,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   130,   130,   152,   157,   162,   169,   170,   188,   190,
     192,   194,   196,   198,   203,   204,   208,   209,   210,   211,
     212,   213,   217,   218,   219,   220,   221,   222,   226,   227,
     231,   232,   233,   234,   238,   239,   240,   244,   245,   246,
     250,   251,   252,   253,   254,   258,   259,   260,   264,   265,
     269,   270,   274,   275,   279,   280,   284,   285,   289,   290,
     294,   295,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   313,   314,   318,   322,   324,   332,   334,
     336,   338,   340,   342,   347,   348,   352,   359,   369,   370,
     371,   372,   373,   377,   379,   380,   381,   382,   383,   384,
     385,   387,   388,   389,   390,   394,   395,   396,   399,   400,
     404,   405,   409,   413,   414,   415,   416,   420,   421,   425,
     426,   427,   431,   432,   433,   437,   438,   442,   443,   447,
     448,   452,   456,   463,   465,   467,   472,   477,   478,   482,
     486,   487,   488,   489,   493,   494,   499,   500,   504,   505,
     509,   510,   511,   515,   521,   533,   534,   538,   539,   540,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   556,
     557,   558,   562,   563,   567,   568,   568,   571,   572,   573,
     574,   575,   579,   580,   581,   585,   586,   590,   591,   594,
     595,   598,   599,   603,   604,   605,   609,   610,   611,   612,
     616,   617,   618,   619,   620,   624,   625,   629,   630,   635,
     635,   637,   637,   639,   639,   641,   641
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
#line 2170 "mcc_c.tab.c"

#line 645 "mcc_c.y"

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
