// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file mcc_c.tab.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_MCC_C_TAB_H_INCLUDED
# define YY_YY_MCC_C_TAB_H_INCLUDED
// "%code requires" blocks.
#line 3 "mcc_c.y"

#include <stdio.h>
#include "mcc_utils.hpp"
void yyerror(char *s);
class driver;

#line 56 "mcc_c.tab.h"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 191 "mcc_c.tab.h"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "identifier"
      // declarator
      // direct_declarator
      char dummy1[sizeof (std::string)];

      // identifier_list
      char dummy2[sizeof (std::vector<std::string>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_YYEMPTY = -2,
    TOK_END = 0,                   // "end of file"
    TOK_YYerror = 1,               // error
    TOK_YYUNDEF = 2,               // "invalid token"
    TOK_IDENTIFIER = 3,            // "identifier"
    TOK_CONSTANT = 4,              // "constant"
    TOK_STRING_LITERAL = 5,        // "literal"
    TOK_SIZEOF = 6,                // "sizeof"
    TOK_TYPEDEF = 7,               // "typedef"
    TOK_EXTERN = 8,                // "extern"
    TOK_STATIC = 9,                // "static"
    TOK_AUTO = 10,                 // "auto"
    TOK_REGISTER = 11,             // "register"
    TOK_CHAR = 12,                 // "char"
    TOK_SHORT = 13,                // "short"
    TOK_LONG = 14,                 // "long"
    TOK_SIGNED = 15,               // "signed"
    TOK_UNSIGNED = 16,             // "unsigned"
    TOK_FLOAT = 17,                // "float"
    TOK_DOUBLE = 18,               // "double"
    TOK_CONST = 19,                // "const"
    TOK_VOLATILE = 20,             // "volatile"
    TOK_VOID = 21,                 // "void"
    TOK_CASE = 22,                 // "case"
    TOK_DEFAULT = 23,              // "default"
    TOK_IF = 24,                   // "if"
    TOK_INT = 25,                  // "int"
    TOK_ELSE = 26,                 // "else"
    TOK_SWITCH = 27,               // "switch"
    TOK_WHILE = 28,                // "while"
    TOK_DO = 29,                   // "do"
    TOK_FOR = 30,                  // "for"
    TOK_GOTO = 31,                 // "goto"
    TOK_CONTINUE = 32,             // "continue"
    TOK_BREAK = 33,                // "break"
    TOK_RETURN = 34,               // "return"
    TOK_STRUCT = 35,               // "struct"
    TOK_UNION = 36,                // "union"
    TOK_ENUM = 37,                 // "enum"
    TOK_DIV_ASSIGN = 38,           // "/="
    TOK_MOD_ASSIGN = 39,           // "%="
    TOK_MUL_ASSIGN = 40,           // "*="
    TOK_SUB_ASSIGN = 41,           // "-="
    TOK_ADD_ASSIGN = 42,           // "+="
    TOK_LEFT_ASSIGN = 43,          // "<<="
    TOK_RIGHT_ASSIGN = 44,         // ">>="
    TOK_AND_ASSIGN = 45,           // "&="
    TOK_XOR_ASSIGN = 46,           // "^="
    TOK_OR_ASSIGN = 47,            // "|="
    TOK_TYPE_NAME = 48,            // "typename"
    TOK_NL = 49,                   // "\n"
    TOK_PLUS = 50,                 // "+"
    TOK_MINUS = 51,                // "-"
    TOK_MUL = 52,                  // "*"
    TOK_DIV = 53,                  // "/"
    TOK_XOR = 54,                  // "^"
    TOK_SHL = 55,                  // "<<"
    TOK_SHR = 56,                  // ">>"
    TOK_OR = 57,                   // "|"
    TOK_AND = 58,                  // "&"
    TOK_MOD = 59,                  // "%"
    TOK_ASS = 60,                  // "="
    TOK_NOT = 61,                  // "!"
    TOK_FLIP = 62,                 // "~"
    TOK_LEFT_PAR = 63,             // "("
    TOK_RIGHT_PAR = 64,            // ")"
    TOK_PTR = 65,                  // "->"
    TOK_L_CURLY = 66,              // "{"
    TOK_R_CURLY = 67,              // "}"
    TOK_L_SQBR = 68,               // "["
    TOK_R_SQBR = 69,               // "]"
    TOK_ELLIPSIS = 70,             // "..."
    TOK_INC = 71,                  // "++"
    TOK_DEC = 72,                  // "--"
    TOK_EQ = 73,                   // "=="
    TOK_GEQ = 74,                  // ">="
    TOK_LEQ = 75,                  // "<="
    TOK_NEQ = 76,                  // "!="
    TOK_SEMI = 77,                 // ";"
    TOK_DOT = 78,                  // "."
    TOK_COMMA = 79,                // ","
    TOK_COL = 80,                  // ":"
    TOK_LE = 81,                   // "<"
    TOK_GE = 82,                   // ">"
    TOK_LOR = 83,                  // "&&"
    TOK_LAND = 84,                 // "||"
    TOK_Q_MARK = 85                // "?"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 86, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_IDENTIFIER = 3,                        // "identifier"
        S_CONSTANT = 4,                          // "constant"
        S_STRING_LITERAL = 5,                    // "literal"
        S_SIZEOF = 6,                            // "sizeof"
        S_TYPEDEF = 7,                           // "typedef"
        S_EXTERN = 8,                            // "extern"
        S_STATIC = 9,                            // "static"
        S_AUTO = 10,                             // "auto"
        S_REGISTER = 11,                         // "register"
        S_CHAR = 12,                             // "char"
        S_SHORT = 13,                            // "short"
        S_LONG = 14,                             // "long"
        S_SIGNED = 15,                           // "signed"
        S_UNSIGNED = 16,                         // "unsigned"
        S_FLOAT = 17,                            // "float"
        S_DOUBLE = 18,                           // "double"
        S_CONST = 19,                            // "const"
        S_VOLATILE = 20,                         // "volatile"
        S_VOID = 21,                             // "void"
        S_CASE = 22,                             // "case"
        S_DEFAULT = 23,                          // "default"
        S_IF = 24,                               // "if"
        S_INT = 25,                              // "int"
        S_ELSE = 26,                             // "else"
        S_SWITCH = 27,                           // "switch"
        S_WHILE = 28,                            // "while"
        S_DO = 29,                               // "do"
        S_FOR = 30,                              // "for"
        S_GOTO = 31,                             // "goto"
        S_CONTINUE = 32,                         // "continue"
        S_BREAK = 33,                            // "break"
        S_RETURN = 34,                           // "return"
        S_STRUCT = 35,                           // "struct"
        S_UNION = 36,                            // "union"
        S_ENUM = 37,                             // "enum"
        S_DIV_ASSIGN = 38,                       // "/="
        S_MOD_ASSIGN = 39,                       // "%="
        S_MUL_ASSIGN = 40,                       // "*="
        S_SUB_ASSIGN = 41,                       // "-="
        S_ADD_ASSIGN = 42,                       // "+="
        S_LEFT_ASSIGN = 43,                      // "<<="
        S_RIGHT_ASSIGN = 44,                     // ">>="
        S_AND_ASSIGN = 45,                       // "&="
        S_XOR_ASSIGN = 46,                       // "^="
        S_OR_ASSIGN = 47,                        // "|="
        S_TYPE_NAME = 48,                        // "typename"
        S_NL = 49,                               // "\n"
        S_PLUS = 50,                             // "+"
        S_MINUS = 51,                            // "-"
        S_MUL = 52,                              // "*"
        S_DIV = 53,                              // "/"
        S_XOR = 54,                              // "^"
        S_SHL = 55,                              // "<<"
        S_SHR = 56,                              // ">>"
        S_OR = 57,                               // "|"
        S_AND = 58,                              // "&"
        S_MOD = 59,                              // "%"
        S_ASS = 60,                              // "="
        S_NOT = 61,                              // "!"
        S_FLIP = 62,                             // "~"
        S_LEFT_PAR = 63,                         // "("
        S_RIGHT_PAR = 64,                        // ")"
        S_PTR = 65,                              // "->"
        S_L_CURLY = 66,                          // "{"
        S_R_CURLY = 67,                          // "}"
        S_L_SQBR = 68,                           // "["
        S_R_SQBR = 69,                           // "]"
        S_ELLIPSIS = 70,                         // "..."
        S_INC = 71,                              // "++"
        S_DEC = 72,                              // "--"
        S_EQ = 73,                               // "=="
        S_GEQ = 74,                              // ">="
        S_LEQ = 75,                              // "<="
        S_NEQ = 76,                              // "!="
        S_SEMI = 77,                             // ";"
        S_DOT = 78,                              // "."
        S_COMMA = 79,                            // ","
        S_COL = 80,                              // ":"
        S_LE = 81,                               // "<"
        S_GE = 82,                               // ">"
        S_LOR = 83,                              // "&&"
        S_LAND = 84,                             // "||"
        S_Q_MARK = 85,                           // "?"
        S_YYACCEPT = 86,                         // $accept
        S_primary_expression = 87,               // primary_expression
        S_postfix_expression = 88,               // postfix_expression
        S_argument_expression_list = 89,         // argument_expression_list
        S_unary_expression = 90,                 // unary_expression
        S_unary_operator = 91,                   // unary_operator
        S_cast_expression = 92,                  // cast_expression
        S_multiplicative_expression = 93,        // multiplicative_expression
        S_additive_expression = 94,              // additive_expression
        S_shift_expression = 95,                 // shift_expression
        S_relational_expression = 96,            // relational_expression
        S_equality_expression = 97,              // equality_expression
        S_and_expression = 98,                   // and_expression
        S_exclusive_or_expression = 99,          // exclusive_or_expression
        S_inclusive_or_expression = 100,         // inclusive_or_expression
        S_logical_and_expression = 101,          // logical_and_expression
        S_logical_or_expression = 102,           // logical_or_expression
        S_conditional_expression = 103,          // conditional_expression
        S_assignment_expression = 104,           // assignment_expression
        S_assignment_operator = 105,             // assignment_operator
        S_expression = 106,                      // expression
        S_constant_expression = 107,             // constant_expression
        S_declaration = 108,                     // declaration
        S_declaration_specifiers = 109,          // declaration_specifiers
        S_init_declarator_list = 110,            // init_declarator_list
        S_init_declarator = 111,                 // init_declarator
        S_storage_class_specifier = 112,         // storage_class_specifier
        S_type_specifier = 113,                  // type_specifier
        S_struct_or_union_specifier = 114,       // struct_or_union_specifier
        S_struct_or_union = 115,                 // struct_or_union
        S_struct_declaration_list = 116,         // struct_declaration_list
        S_struct_declaration = 117,              // struct_declaration
        S_specifier_qualifier_list = 118,        // specifier_qualifier_list
        S_struct_declarator_list = 119,          // struct_declarator_list
        S_struct_declarator = 120,               // struct_declarator
        S_enum_specifier = 121,                  // enum_specifier
        S_enumerator_list = 122,                 // enumerator_list
        S_enumerator = 123,                      // enumerator
        S_type_qualifier = 124,                  // type_qualifier
        S_declarator = 125,                      // declarator
        S_direct_declarator = 126,               // direct_declarator
        S_pointer = 127,                         // pointer
        S_type_qualifier_list = 128,             // type_qualifier_list
        S_parameter_type_list = 129,             // parameter_type_list
        S_parameter_list = 130,                  // parameter_list
        S_parameter_declaration = 131,           // parameter_declaration
        S_identifier_list = 132,                 // identifier_list
        S_type_name = 133,                       // type_name
        S_abstract_declarator = 134,             // abstract_declarator
        S_direct_abstract_declarator = 135,      // direct_abstract_declarator
        S_initializer = 136,                     // initializer
        S_initializer_list = 137,                // initializer_list
        S_statement = 138,                       // statement
        S_139_1 = 139,                           // $@1
        S_labeled_statement = 140,               // labeled_statement
        S_compound_statement = 141,              // compound_statement
        S_statement_list = 142,                  // statement_list
        S_declaration_list = 143,                // declaration_list
        S_expression_statement = 144,            // expression_statement
        S_selection_statement = 145,             // selection_statement
        S_iteration_statement = 146,             // iteration_statement
        S_jump_statement = 147,                  // jump_statement
        S_translation_unit = 148,                // translation_unit
        S_external_declaration = 149,            // external_declaration
        S_function_definition = 150,             // function_definition
        S_151_2 = 151,                           // $@2
        S_152_3 = 152,                           // $@3
        S_153_4 = 153,                           // $@4
        S_154_5 = 154                            // $@5
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.template destroy< std::vector<std::string> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    parser (driver& drv_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOK_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOK_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOK_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOK_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOK_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSTANT (location_type l)
      {
        return symbol_type (token::TOK_CONSTANT, std::move (l));
      }
#else
      static
      symbol_type
      make_CONSTANT (const location_type& l)
      {
        return symbol_type (token::TOK_CONSTANT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (location_type l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const location_type& l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF (location_type l)
      {
        return symbol_type (token::TOK_SIZEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZEOF (const location_type& l)
      {
        return symbol_type (token::TOK_SIZEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF (location_type l)
      {
        return symbol_type (token::TOK_TYPEDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEDEF (const location_type& l)
      {
        return symbol_type (token::TOK_TYPEDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERN (location_type l)
      {
        return symbol_type (token::TOK_EXTERN, std::move (l));
      }
#else
      static
      symbol_type
      make_EXTERN (const location_type& l)
      {
        return symbol_type (token::TOK_EXTERN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (location_type l)
      {
        return symbol_type (token::TOK_STATIC, std::move (l));
      }
#else
      static
      symbol_type
      make_STATIC (const location_type& l)
      {
        return symbol_type (token::TOK_STATIC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTO (location_type l)
      {
        return symbol_type (token::TOK_AUTO, std::move (l));
      }
#else
      static
      symbol_type
      make_AUTO (const location_type& l)
      {
        return symbol_type (token::TOK_AUTO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGISTER (location_type l)
      {
        return symbol_type (token::TOK_REGISTER, std::move (l));
      }
#else
      static
      symbol_type
      make_REGISTER (const location_type& l)
      {
        return symbol_type (token::TOK_REGISTER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (location_type l)
      {
        return symbol_type (token::TOK_CHAR, std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const location_type& l)
      {
        return symbol_type (token::TOK_CHAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHORT (location_type l)
      {
        return symbol_type (token::TOK_SHORT, std::move (l));
      }
#else
      static
      symbol_type
      make_SHORT (const location_type& l)
      {
        return symbol_type (token::TOK_SHORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG (location_type l)
      {
        return symbol_type (token::TOK_LONG, std::move (l));
      }
#else
      static
      symbol_type
      make_LONG (const location_type& l)
      {
        return symbol_type (token::TOK_LONG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIGNED (location_type l)
      {
        return symbol_type (token::TOK_SIGNED, std::move (l));
      }
#else
      static
      symbol_type
      make_SIGNED (const location_type& l)
      {
        return symbol_type (token::TOK_SIGNED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNSIGNED (location_type l)
      {
        return symbol_type (token::TOK_UNSIGNED, std::move (l));
      }
#else
      static
      symbol_type
      make_UNSIGNED (const location_type& l)
      {
        return symbol_type (token::TOK_UNSIGNED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (location_type l)
      {
        return symbol_type (token::TOK_FLOAT, std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const location_type& l)
      {
        return symbol_type (token::TOK_FLOAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (location_type l)
      {
        return symbol_type (token::TOK_DOUBLE, std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE (const location_type& l)
      {
        return symbol_type (token::TOK_DOUBLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (location_type l)
      {
        return symbol_type (token::TOK_CONST, std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const location_type& l)
      {
        return symbol_type (token::TOK_CONST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOLATILE (location_type l)
      {
        return symbol_type (token::TOK_VOLATILE, std::move (l));
      }
#else
      static
      symbol_type
      make_VOLATILE (const location_type& l)
      {
        return symbol_type (token::TOK_VOLATILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (location_type l)
      {
        return symbol_type (token::TOK_VOID, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const location_type& l)
      {
        return symbol_type (token::TOK_VOID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::TOK_CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::TOK_CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (location_type l)
      {
        return symbol_type (token::TOK_DEFAULT, std::move (l));
      }
#else
      static
      symbol_type
      make_DEFAULT (const location_type& l)
      {
        return symbol_type (token::TOK_DEFAULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::TOK_IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::TOK_IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (location_type l)
      {
        return symbol_type (token::TOK_INT, std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const location_type& l)
      {
        return symbol_type (token::TOK_INT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::TOK_ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::TOK_ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (location_type l)
      {
        return symbol_type (token::TOK_SWITCH, std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const location_type& l)
      {
        return symbol_type (token::TOK_SWITCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::TOK_WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::TOK_WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (location_type l)
      {
        return symbol_type (token::TOK_DO, std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const location_type& l)
      {
        return symbol_type (token::TOK_DO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::TOK_FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::TOK_FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO (location_type l)
      {
        return symbol_type (token::TOK_GOTO, std::move (l));
      }
#else
      static
      symbol_type
      make_GOTO (const location_type& l)
      {
        return symbol_type (token::TOK_GOTO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::TOK_CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::TOK_CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::TOK_BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::TOK_BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::TOK_RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::TOK_RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (location_type l)
      {
        return symbol_type (token::TOK_STRUCT, std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const location_type& l)
      {
        return symbol_type (token::TOK_STRUCT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNION (location_type l)
      {
        return symbol_type (token::TOK_UNION, std::move (l));
      }
#else
      static
      symbol_type
      make_UNION (const location_type& l)
      {
        return symbol_type (token::TOK_UNION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (location_type l)
      {
        return symbol_type (token::TOK_ENUM, std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const location_type& l)
      {
        return symbol_type (token::TOK_ENUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_DIV_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_DIV_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_MOD_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_MOD_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_MUL_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_MUL_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_SUB_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_SUB_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_ADD_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ADD_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_ADD_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_LEFT_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_LEFT_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_RIGHT_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_RIGHT_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_AND_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_AND_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_AND_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_XOR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_XOR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_XOR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_OR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_OR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_OR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_NAME (location_type l)
      {
        return symbol_type (token::TOK_TYPE_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE_NAME (const location_type& l)
      {
        return symbol_type (token::TOK_TYPE_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NL (location_type l)
      {
        return symbol_type (token::TOK_NL, std::move (l));
      }
#else
      static
      symbol_type
      make_NL (const location_type& l)
      {
        return symbol_type (token::TOK_NL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::TOK_PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::TOK_PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::TOK_MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::TOK_MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL (location_type l)
      {
        return symbol_type (token::TOK_MUL, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL (const location_type& l)
      {
        return symbol_type (token::TOK_MUL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::TOK_DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::TOK_DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR (location_type l)
      {
        return symbol_type (token::TOK_XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_XOR (const location_type& l)
      {
        return symbol_type (token::TOK_XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHL (location_type l)
      {
        return symbol_type (token::TOK_SHL, std::move (l));
      }
#else
      static
      symbol_type
      make_SHL (const location_type& l)
      {
        return symbol_type (token::TOK_SHL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHR (location_type l)
      {
        return symbol_type (token::TOK_SHR, std::move (l));
      }
#else
      static
      symbol_type
      make_SHR (const location_type& l)
      {
        return symbol_type (token::TOK_SHR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::TOK_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::TOK_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::TOK_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::TOK_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::TOK_MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::TOK_MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASS (location_type l)
      {
        return symbol_type (token::TOK_ASS, std::move (l));
      }
#else
      static
      symbol_type
      make_ASS (const location_type& l)
      {
        return symbol_type (token::TOK_ASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::TOK_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::TOK_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLIP (location_type l)
      {
        return symbol_type (token::TOK_FLIP, std::move (l));
      }
#else
      static
      symbol_type
      make_FLIP (const location_type& l)
      {
        return symbol_type (token::TOK_FLIP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_PAR (location_type l)
      {
        return symbol_type (token::TOK_LEFT_PAR, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_PAR (const location_type& l)
      {
        return symbol_type (token::TOK_LEFT_PAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_PAR (location_type l)
      {
        return symbol_type (token::TOK_RIGHT_PAR, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_PAR (const location_type& l)
      {
        return symbol_type (token::TOK_RIGHT_PAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PTR (location_type l)
      {
        return symbol_type (token::TOK_PTR, std::move (l));
      }
#else
      static
      symbol_type
      make_PTR (const location_type& l)
      {
        return symbol_type (token::TOK_PTR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_CURLY (location_type l)
      {
        return symbol_type (token::TOK_L_CURLY, std::move (l));
      }
#else
      static
      symbol_type
      make_L_CURLY (const location_type& l)
      {
        return symbol_type (token::TOK_L_CURLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_CURLY (location_type l)
      {
        return symbol_type (token::TOK_R_CURLY, std::move (l));
      }
#else
      static
      symbol_type
      make_R_CURLY (const location_type& l)
      {
        return symbol_type (token::TOK_R_CURLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_SQBR (location_type l)
      {
        return symbol_type (token::TOK_L_SQBR, std::move (l));
      }
#else
      static
      symbol_type
      make_L_SQBR (const location_type& l)
      {
        return symbol_type (token::TOK_L_SQBR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_SQBR (location_type l)
      {
        return symbol_type (token::TOK_R_SQBR, std::move (l));
      }
#else
      static
      symbol_type
      make_R_SQBR (const location_type& l)
      {
        return symbol_type (token::TOK_R_SQBR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSIS (location_type l)
      {
        return symbol_type (token::TOK_ELLIPSIS, std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSIS (const location_type& l)
      {
        return symbol_type (token::TOK_ELLIPSIS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INC (location_type l)
      {
        return symbol_type (token::TOK_INC, std::move (l));
      }
#else
      static
      symbol_type
      make_INC (const location_type& l)
      {
        return symbol_type (token::TOK_INC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC (location_type l)
      {
        return symbol_type (token::TOK_DEC, std::move (l));
      }
#else
      static
      symbol_type
      make_DEC (const location_type& l)
      {
        return symbol_type (token::TOK_DEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::TOK_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::TOK_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GEQ (location_type l)
      {
        return symbol_type (token::TOK_GEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_GEQ (const location_type& l)
      {
        return symbol_type (token::TOK_GEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEQ (location_type l)
      {
        return symbol_type (token::TOK_LEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LEQ (const location_type& l)
      {
        return symbol_type (token::TOK_LEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQ (location_type l)
      {
        return symbol_type (token::TOK_NEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_NEQ (const location_type& l)
      {
        return symbol_type (token::TOK_NEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMI (location_type l)
      {
        return symbol_type (token::TOK_SEMI, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMI (const location_type& l)
      {
        return symbol_type (token::TOK_SEMI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::TOK_DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::TOK_DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COL (location_type l)
      {
        return symbol_type (token::TOK_COL, std::move (l));
      }
#else
      static
      symbol_type
      make_COL (const location_type& l)
      {
        return symbol_type (token::TOK_COL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::TOK_LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::TOK_LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::TOK_GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::TOK_GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOR (location_type l)
      {
        return symbol_type (token::TOK_LOR, std::move (l));
      }
#else
      static
      symbol_type
      make_LOR (const location_type& l)
      {
        return symbol_type (token::TOK_LOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAND (location_type l)
      {
        return symbol_type (token::TOK_LAND, std::move (l));
      }
#else
      static
      symbol_type
      make_LAND (const location_type& l)
      {
        return symbol_type (token::TOK_LAND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Q_MARK (location_type l)
      {
        return symbol_type (token::TOK_Q_MARK, std::move (l));
      }
#else
      static
      symbol_type
      make_Q_MARK (const location_type& l)
      {
        return symbol_type (token::TOK_Q_MARK, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1436,     ///< Last index in yytable_.
      yynnts_ = 69,  ///< Number of nonterminal symbols.
      yyfinal_ = 60 ///< Termination state number.
    };


    // User arguments.
    driver& drv;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_identifier_list: // identifier_list
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2760 "mcc_c.tab.h"




#endif // !YY_YY_MCC_C_TAB_H_INCLUDED
