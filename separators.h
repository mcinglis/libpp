
// Copyright 2014  Malcolm Inglis <http://minglis.id.au>
//
// This file is part of Libpp.
//
// Libpp is free software: you can redistribute it and/or modify it under the
// terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// Libpp is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
// more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with Libpp. If not, see <https://gnu.org/licenses/>.


#ifndef LIBPP_SEPARATORS_H
#define LIBPP_SEPARATORS_H


// You can pass one of these following separator macros as the separator
// argument to `PP_MAP`, `PP_MAP_LISTS` or `PP_INTERSPERSE` to separate each
// resulting expression by a constant expression.
//
//      PP_MAP( m, PP_SEP_NONE, a, b, c )
//      >>> m( a ) m( b ) m( c )
//      PP_MAP( m, PP_SEP_COMMA, a, b, c )
//      >>> m( a ), m( b ), m( c )
//      PP_MAP_LISTS( m, PP_SEP_TIMES, (a,b), (c) )
//      >>> m( a, b ) * m( c )
//      PP_MAP_LISTS( m, PP_SEP_SEMICOLON, (a,b), (c) )
//      >>> m( a, b ); m( c )
//      PP_INTERSPERSE( PP_SEP_AND, a, b, c )
//      >>> ( a ) && ( b ) && ( c )
//
// Be careful about how you use some of these separators. For example, the
// comparison operators don't work like mathematical notation when they're
// chained: `2 < 3 < 2 == true`.


// @public begin
#define PP_SEP_NONE( ... )
#define PP_SEP_COMMA( ... )                ,
#define PP_SEP_SEMICOLON( ... )            ;
#define PP_SEP_PLUS( ... )                 +
#define PP_SEP_MINUS( ... )                -
#define PP_SEP_TIMES( ... )                *
#define PP_SEP_DIVIDE( ... )               /
#define PP_SEP_MODULO( ... )               %
#define PP_SEP_AND( ... )                  &&
#define PP_SEP_OR( ... )                   ||
#define PP_SEP_LT( ... )                   <
#define PP_SEP_LE( ... )                   <=
#define PP_SEP_EQ( ... )                   ==
#define PP_SEP_NEQ( ... )                  !=
#define PP_SEP_GE( ... )                   >=
#define PP_SEP_GT( ... )                   >
#define PP_SEP_BIT_AND( ... )              &
#define PP_SEP_BIT_OR( ... )               |
#define PP_SEP_BIT_XOR( ... )              ^
#define PP_SEP_BIT_LSHIFT( ... )           <<
#define PP_SEP_BIT_RSHIFT( ... )           >>
#define PP_SEP_ASSIGN( ... )               =
#define PP_SEP_PLUS_ASSIGN( ... )          +=
#define PP_SEP_MINUS_ASSIGN( ... )         -=
#define PP_SEP_TIMES_ASSIGN( ... )         *=
#define PP_SEP_DIVIDE_ASSIGN( ... )        /=
#define PP_SEP_MODULO_ASSIGN( ... )        %=
#define PP_SEP_BIT_AND_ASSIGN( ... )       &=
#define PP_SEP_BIT_OR_ASSIGN( ... )        |=
#define PP_SEP_BIT_XOR_ASSIGN( ... )       ^=
#define PP_SEP_BIT_LSHIFT_ASSIGN( ... )    <<=
#define PP_SEP_BIT_RSHIFT_ASSIGN( ... )    >>=
#define PP_SEP_FIELD( ... )                .
#define PP_SEP_DEREF_FIELD( ... )          ->
#define PP_SEP_SPACE( ... )                " "
#define PP_SEP_TAB( ... )                  "\t"
#define PP_SEP_LF( ... )                   "\n"
#define PP_SEP_CR( ... )                   "\r"
// @public end


#endif // ifndef LIBPP_SEPARATORS_H

