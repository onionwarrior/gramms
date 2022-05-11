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
#line 136 "mcc_c.tab.c"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false)
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

    location = that.location;
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
            symbol_type yylookahead (yylex ());
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

#line 538 "mcc_c.tab.c"

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
  "const", "volatile", "void", "case", "default", "if", "else", "switch",
  "while", "do", "for", "goto", "continue", "break", "return", "struct",
  "union", "enum", "/=", "%=", "*=", "-=", "+=", "<<=", ">>=", "&=", "^=",
  "|=", "typename", "\n", "+", "-", "*", "/", "^", "<<", ">>", "|", "&",
  "%", "=", "!", "~", "(", ")", "->", "{", "}", "[", "]", "...", "++",
  "--", "==", ">=", "<=", "!=", ";", ".", ",", ":", "<", ">", "?", "||",
  "&&", "int", "$accept", "primary_expression", "postfix_expression",
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
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -226;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     677,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,    15,
    -226,    47,    50,  -226,  -226,    48,  1017,  1017,  -226,    19,
    -226,  1017,   894,    -2,    40,   297,  -226,  -226,   -50,    43,
    -226,  -226,    47,    -1,  -226,   -38,  -226,   835,  -226,  -226,
       5,  1330,  -226,   380,  -226,    48,  -226,   894,   733,   827,
      -2,  -226,  -226,    43,    26,   -42,  -226,  -226,  -226,  -226,
    -226,    50,  1310,  -226,   894,  1330,  1330,  1246,  -226,    17,
    1330,    29,  -226,  -226,  1442,  1457,    37,    77,    87,   127,
    1181,   140,   179,   110,   133,    70,  -226,  -226,  -226,  -226,
    -226,  -226,   537,  -226,  1480,  1480,  -226,  -226,   117,   283,
    1457,  -226,   163,   169,   173,   160,    61,   156,   171,   188,
     183,    66,  -226,  -226,   147,  -226,  -226,  -226,   463,  1043,
    -226,  -226,  -226,  -226,   191,  -226,  -226,  -226,  -226,    10,
     199,   176,  -226,    -7,  -226,  -226,  -226,  -226,   201,    60,
    1457,  -226,    43,  -226,  1310,  -226,  -226,  -226,  1256,  -226,
    -226,  -226,  1457,   167,  -226,   202,  -226,  1181,   537,  -226,
     204,  1181,  1457,  1457,  1457,   243,   290,   208,  -226,  -226,
    -226,   175,    27,   -17,   222,  1457,  -226,  -226,  1333,   284,
    1457,  -226,  -226,   285,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  1457,  -226,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  -226,  1457,  -226,  1112,
    -226,  -226,   616,  1349,  -226,    16,  -226,    80,  -226,   935,
    -226,   287,  -226,  -226,  -226,  -226,  -226,   114,  -226,  -226,
    -226,    17,  1457,  -226,   223,  1181,  -226,    59,   113,   120,
     229,   290,  -226,  -226,  -226,   774,   144,  -226,  1457,  -226,
     130,  -226,  -226,   -21,  -226,  -226,  -226,  -226,  -226,   163,
     163,   169,   169,   173,   173,   173,   173,   160,   160,    61,
     156,   171,   188,   178,   183,  -226,  -226,  -226,   236,   239,
    -226,   251,    80,   976,  1382,  -226,  -226,  -226,  -226,   611,
    -226,  -226,  -226,  -226,  1181,  1181,  1181,  1457,  1418,  -226,
    -226,  1457,  -226,  1457,  -226,  -226,  -226,  -226,   267,  -226,
     266,  -226,  -226,   310,  -226,  -226,   132,  1181,   142,  -226,
    -226,  -226,  -226,  1181,   260,  -226,  1181,  -226,  -226,  -226
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,   133,    88,    89,    90,    91,    92,    94,    95,    97,
     100,   101,    98,    99,   129,   130,    93,   108,   109,     0,
     104,   140,     0,    96,   208,     0,    78,    80,   102,     0,
     103,    82,     0,   132,     0,     0,   205,   207,   124,     0,
     144,   142,   141,     0,    76,     0,    84,    86,    79,    81,
     107,     0,    83,     0,   187,     0,   212,     0,     0,     0,
     131,     1,   206,     0,   127,     0,   125,   145,   143,   134,
      77,     0,     0,   210,     0,     0,   114,     0,   110,     0,
     116,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    25,    23,    24,
      27,    26,     0,   183,     0,     0,   191,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    60,    73,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    86,   188,   211,   153,   139,   152,
       0,   146,   148,     0,     2,   136,    28,    75,     0,     0,
       0,   122,     0,    85,     0,   169,    87,   209,     0,   113,
     106,   111,     0,     0,   117,   119,   115,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
     203,     0,     0,   155,     0,     0,    17,    18,     0,     0,
       0,    12,    13,     0,    64,    65,    63,    67,    66,    68,
      69,    70,    71,    72,    62,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   123,   128,   126,   172,     0,   105,   120,
     112,     0,     0,   180,     0,     0,   182,     0,     0,     0,
       0,     0,   200,   204,     5,     0,   157,   156,     0,     8,
       0,    14,    11,     0,    10,    61,    31,    32,    33,    35,
      36,    38,    39,    42,    41,    43,    44,    46,    47,    49,
      51,    53,    55,     0,    57,    74,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,   170,     0,
     118,   121,    21,   181,     0,     0,     0,     0,     0,    29,
       9,     0,     7,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,   193,   195,   196,     0,     0,     0,    15,
      59,   168,   164,     0,     0,   198,     0,   194,   197,   199
  };

  const short
  parser::yypgoto_[] =
  {
    -226,  -226,  -226,  -226,   -56,  -226,   -94,    49,    51,    63,
      56,   118,   116,   121,   122,   128,  -226,   -55,   -20,  -226,
     -81,   -62,     7,     0,  -226,   275,  -226,   124,  -226,  -226,
     274,   -69,   -43,  -226,   104,  -226,   293,   205,   196,   -16,
     -32,   -10,  -226,   -57,  -226,   119,  -226,   194,  -114,  -225,
    -137,  -226,   -85,  -226,    71,    64,   235,  -164,  -226,  -226,
    -226,  -226,   330,  -226
  };

  const short
  parser::yydefgoto_[] =
  {
       0,   107,   108,   270,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    54,    55,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   163,   164,    30,    65,    66,    31,    32,
      33,    34,    42,   298,   141,   142,   143,   184,   299,   237,
     156,   247,   125,   126,   127,    57,   129,   130,   131,   132,
     133,    35,    36,    37
  };

  const short
  parser::yytable_[] =
  {
      25,   140,    60,   146,   147,   175,    43,    24,   161,    47,
     302,    41,   261,     1,   181,    63,   206,   246,    38,     1,
       1,   182,    50,   170,   151,   236,    48,    49,   169,   146,
     147,    52,    68,   159,    21,    25,   152,   166,    70,   134,
      71,   302,    24,     1,   231,   265,    64,   322,   186,   187,
     233,     1,   155,     1,   146,   134,   240,   227,   139,   183,
      58,    21,    69,   165,   135,    59,    14,    15,    21,   267,
      75,   241,   232,   144,    82,    83,    84,   233,   232,    22,
      39,   135,   253,   233,    51,   150,   256,   182,   244,   161,
     264,   257,   258,   259,   146,   147,   162,   318,    21,    21,
     249,    21,    22,    56,   182,   227,   146,   147,   167,   273,
      22,    74,    22,   276,   277,   278,   171,   128,    73,    96,
      97,    98,   314,   234,    44,   183,   243,    99,   136,   235,
     100,   101,   102,   218,   155,   135,   219,   227,   152,   172,
     104,   105,   303,   293,   231,   157,   180,   304,   224,   173,
     225,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   271,   146,
     313,   301,   332,   266,   319,    76,   315,   146,   147,   188,
     308,   189,   177,   316,   190,   275,   178,   191,   192,   174,
     311,   227,   309,   320,   193,   344,   146,   147,   227,    76,
      76,    76,   176,    60,    76,   346,   265,   295,   321,   179,
     227,   233,   146,   220,   207,   208,    43,    40,   210,   211,
     227,   209,   235,   226,   221,   227,    76,   212,   213,   333,
     334,   335,   139,   214,   215,   165,   336,   338,    67,   139,
     216,   217,   330,   250,   222,   251,   328,    80,   146,   147,
      72,   263,   345,   227,   239,   266,   227,   323,   347,   279,
     280,   349,   238,   281,   282,   139,   223,   146,   340,   242,
     260,    80,    80,    80,   287,   288,    80,   283,   284,   285,
     286,   252,    76,   255,   262,   268,   312,   272,   274,   155,
     307,   317,    76,   144,    82,    83,    84,    61,    80,   324,
       1,   339,   325,   139,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   326,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     341,    17,    18,    19,   342,   343,   348,   290,   289,    96,
      97,    98,   204,   291,    20,   292,   153,    99,    21,   158,
     100,   101,   102,   294,    80,   310,   149,   245,   306,    22,
     104,   105,   254,   229,    80,    62,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    81,    82,    83,    84,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    85,    86,    87,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,    96,
      97,    98,     0,     0,     0,     0,     0,    99,     0,     0,
     100,   101,   102,     0,     0,    53,   103,     0,     0,     0,
     104,   105,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    81,    82,    83,    84,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    85,    86,    87,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,    96,    97,    98,     0,     0,     0,     0,     0,
      99,     0,     0,   100,   101,   102,     0,     0,    53,   228,
       0,     0,     0,   104,   105,     0,     0,     0,     0,   106,
     144,    82,    83,    84,     0,     0,     0,     0,    23,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,    96,    97,    98,     0,
       0,     0,     0,     0,    99,     0,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,   144,    82,    83,    84,     0,     1,
       0,     0,    23,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    20,     0,     0,     0,    21,    99,     0,
       0,   100,   101,   102,     0,     0,   154,   331,   232,   297,
       1,   104,   105,   233,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,    22,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,    20,     0,     0,     0,    21,     0,     0,     0,     0,
     144,    82,    83,    84,     0,     0,   265,   297,     0,     0,
       0,   233,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,     0,     0,     0,     0,    96,    97,    98,     0,
       0,     0,    20,     0,    99,     0,     0,   100,   101,   102,
       0,     0,     0,     0,    72,   145,     0,   104,   105,     0,
      53,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,    20,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,    20,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   327,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
       0,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,    23,     0,     0,    20,    85,    86,    87,     0,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,     0,     0,     0,     0,
      99,     0,    23,   100,   101,   102,     0,     0,    53,   230,
       0,     0,     0,   104,   105,    81,    82,    83,    84,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,     0,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,     0,     0,     0,     0,    99,
       0,     0,   100,   101,   102,     0,     0,    53,   296,     0,
       0,     0,   104,   105,    81,    82,    83,    84,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,     0,     0,     0,     0,    99,     0,
       0,   100,   101,   102,     0,     0,    53,     0,     0,     0,
       0,   104,   105,     0,     0,     0,     0,   106,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   144,    82,    83,    84,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,   144,    82,    83,    84,
       0,    23,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   144,    82,    83,    84,     0,     0,     0,    96,
      97,    98,     0,     0,    17,    18,    19,    99,     0,     0,
     100,   101,   102,     0,     0,   154,     0,    20,     0,     0,
     104,   105,    96,    97,    98,   144,    82,    83,    84,     0,
      99,     0,     0,   100,   101,   102,   269,     0,    96,    97,
      98,     0,     0,   104,   105,     0,    99,     0,     0,   100,
     101,   102,     0,     0,     0,    23,     0,   300,     0,   104,
     105,   144,    82,    83,    84,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,     0,     0,     0,     0,    99,
       0,     0,   100,   101,   102,   144,    82,    83,    84,     0,
     329,     0,   104,   105,     0,     0,     0,     0,     0,     0,
     144,    82,    83,    84,     0,     0,     0,    96,    97,    98,
       0,     0,     0,     0,     0,    99,     0,     0,   100,   101,
     102,   337,     0,   144,    82,    83,    84,     0,   104,   105,
       0,    96,    97,    98,     0,     0,     0,     0,     0,    99,
       0,     0,   100,   101,   168,     0,    96,    97,    98,     0,
       0,     0,   104,   105,    99,     0,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,   104,   105,    96,
      97,    98,     0,     0,     0,     0,     0,    99,     0,     0,
     100,   101,   185,     0,     0,     0,     0,     0,     0,     0,
     104,   105
  };

  const short
  parser::yycheck_[] =
  {
       0,    58,    34,    59,    59,    90,    22,     0,    77,    25,
     235,    21,   176,     3,    95,    65,   110,   154,     3,     3,
       3,   102,     3,    85,    66,   139,    26,    27,    84,    85,
      85,    31,    42,    76,    51,    35,    78,    80,    76,    55,
      78,   266,    35,     3,   129,    62,     3,    68,   104,   105,
      67,     3,    72,     3,   110,    71,    63,    78,    58,   102,
      62,    51,    63,    79,    57,    67,    19,    20,    51,   183,
      65,    78,    62,     3,     4,     5,     6,    67,    62,    62,
      65,    74,   167,    67,    65,    59,   171,   168,   150,   158,
      63,   172,   173,   174,   150,   150,    79,   261,    51,    51,
     162,    51,    62,    32,   185,    78,   162,   162,    79,   190,
      62,    47,    62,   207,   208,   209,    79,    53,    47,    49,
      50,    51,    63,   139,    76,   168,    66,    57,    57,   139,
      60,    61,    62,    72,   154,   128,    75,    78,    78,    62,
      70,    71,    62,   224,   229,    74,    76,    67,    82,    62,
      84,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   188,   225,
     255,   233,   309,   183,   268,    51,    63,   233,   233,    62,
      66,    64,     3,    63,    67,   205,    76,    70,    71,    62,
     252,    78,    78,    63,    77,    63,   252,   252,    78,    75,
      76,    77,    62,   235,    80,    63,    62,   227,    78,    76,
      78,    67,   268,    57,    51,    52,   232,    21,    49,    50,
      78,    58,   232,    76,    53,    78,   102,    54,    55,   314,
     315,   316,   232,    73,    74,   251,   317,   318,    42,   239,
      80,    81,   304,    76,    56,    78,   303,    51,   304,   304,
      59,    76,   337,    78,    78,   265,    78,    79,   343,   210,
     211,   346,    63,   212,   213,   265,    83,   323,   323,    68,
      27,    75,    76,    77,   218,   219,    80,   214,   215,   216,
     217,    79,   158,    79,    76,    63,    63,     3,     3,   309,
       3,    62,   168,     3,     4,     5,     6,     0,   102,    63,
       3,   321,    63,   303,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    68,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      63,    34,    35,    36,    68,    25,    76,   221,   220,    49,
      50,    51,    59,   222,    47,   223,    71,    57,    51,    75,
      60,    61,    62,   225,   158,   251,    63,   152,   239,    62,
      70,    71,   168,   128,   168,    35,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      60,    61,    62,    -1,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    60,    61,    62,    -1,    -1,    65,    66,
      -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    76,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    85,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     3,
      -1,    -1,    85,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    47,    -1,    -1,    -1,    51,    57,    -1,
      -1,    60,    61,    62,    -1,    -1,    65,    66,    62,    63,
       3,    70,    71,    67,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    62,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    62,    63,    -1,    -1,
      -1,    67,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    47,    -1,    57,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    59,    68,    -1,    70,    71,    -1,
      65,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    47,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    47,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    63,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    47,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    85,    60,    61,    62,    -1,    -1,    65,    66,
      -1,    -1,    -1,    70,    71,     3,     4,     5,     6,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    60,    61,    62,    -1,    -1,    65,    66,    -1,
      -1,    -1,    70,    71,     3,     4,     5,     6,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    -1,    -1,    76,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    85,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     3,     4,     5,     6,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    34,    35,    36,    57,    -1,    -1,
      60,    61,    62,    -1,    -1,    65,    -1,    47,    -1,    -1,
      70,    71,    49,    50,    51,     3,     4,     5,     6,    -1,
      57,    -1,    -1,    60,    61,    62,    63,    -1,    49,    50,
      51,    -1,    -1,    70,    71,    -1,    57,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    85,    -1,    68,    -1,    70,
      71,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    60,    61,    62,     3,     4,     5,     6,    -1,
      68,    -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    60,    61,
      62,    63,    -1,     3,     4,     5,     6,    -1,    70,    71,
      -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    60,    61,    62,    -1,    49,    50,    51,    -1,
      -1,    -1,    70,    71,    57,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    34,    35,    36,
      47,    51,    62,    85,   108,   109,   112,   113,   114,   115,
     121,   124,   125,   126,   127,   147,   148,   149,     3,    65,
     124,   127,   128,   125,    76,   110,   111,   125,   109,   109,
       3,    65,   109,    65,   108,   109,   140,   141,    62,    67,
     126,     0,   148,    65,     3,   122,   123,   124,   127,    63,
      76,    78,    59,   140,   141,    65,   113,   116,   117,   118,
     124,     3,     4,     5,     6,    22,    23,    24,    26,    27,
      28,    29,    30,    31,    32,    33,    49,    50,    51,    57,
      60,    61,    62,    66,    70,    71,    76,    87,    88,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   106,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   125,   108,   140,     3,    63,   109,
     129,   130,   131,   132,     3,    68,    90,   103,   107,   122,
      59,    66,    78,   111,    65,   104,   136,   140,   116,   118,
      66,   117,    79,   119,   120,   125,   118,    79,    62,    90,
     107,    79,    62,    62,    62,   138,    62,     3,    76,    76,
      76,   106,   106,   118,   133,    62,    90,    90,    62,    64,
      67,    70,    71,    77,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    59,   105,    92,    51,    52,    58,
      49,    50,    54,    55,    73,    74,    80,    81,    72,    75,
      57,    53,    56,    83,    82,    84,    76,    78,    66,   142,
      66,   138,    62,    67,   125,   127,   134,   135,    63,    78,
      63,    78,    68,    66,   107,   123,   136,   137,    66,   107,
      76,    78,    79,   138,   133,    79,   138,   106,   106,   106,
      27,   143,    76,    76,    63,    62,   127,   134,    63,    63,
      89,   104,     3,   106,     3,   104,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    96,    96,    97,
      98,    99,   100,   106,   101,   104,    66,    63,   129,   134,
      68,   107,   135,    62,    67,    69,   131,     3,    66,    78,
     120,   107,    63,   138,    63,    63,    63,    62,   143,    92,
      63,    78,    68,    79,    63,    63,    68,    63,   129,    68,
     107,    66,   136,   138,   138,   138,   106,    63,   106,   104,
     103,    63,    68,    25,    63,   138,    63,   138,    76,   138
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
     136,   136,   137,   137,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   145,   145,   145,   145,
     146,   146,   146,   146,   146,   147,   147,   148,   148,   149,
     149,   149,   149
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
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   110,   110,   111,   112,   113,   117,   118,   119,   120,
     121,   122,   123,   124,   128,   129,   133,   134,   135,   136,
     137,   138,   142,   143,   144,   145,   146,   147,   151,   152,
     156,   157,   158,   159,   163,   164,   165,   169,   170,   171,
     175,   176,   177,   178,   179,   183,   184,   185,   189,   190,
     194,   195,   199,   200,   204,   205,   209,   210,   214,   215,
     219,   220,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   238,   239,   243,   247,   248,   252,   253,
     254,   255,   256,   257,   261,   262,   266,   267,   271,   272,
     273,   274,   275,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   294,   295,   296,   300,   301,
     305,   306,   310,   314,   315,   316,   317,   321,   322,   326,
     327,   328,   332,   333,   334,   338,   339,   343,   344,   348,
     349,   353,   354,   358,   359,   360,   361,   362,   363,   364,
     368,   369,   370,   371,   375,   376,   381,   382,   386,   387,
     391,   392,   393,   397,   398,   402,   403,   407,   408,   409,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   425,
     426,   427,   431,   432,   436,   437,   438,   439,   440,   441,
     445,   446,   447,   451,   452,   453,   454,   458,   459,   463,
     464,   468,   469,   473,   474,   475,   479,   480,   481,   482,
     486,   487,   488,   489,   490,   494,   495,   499,   500,   504,
     505,   506,   507
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
#line 1605 "mcc_c.tab.c"

#line 510 "mcc_c.y"

#include <stdio.h>

extern char yytext[];
extern int column;
extern FILE * yyin;
void yyerror(char *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
int main() {
	yyin = fopen("input.c","r");
	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}
