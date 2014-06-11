
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

// @public
#define PP_SEP_NONE( ... )
// @public
#define PP_SEP_COMMA( ... )                ,
// @public
#define PP_SEP_SEMICOLON( ... )            ;
// @public
#define PP_SEP_PLUS( ... )                 +
// @public
#define PP_SEP_MINUS( ... )                -
// @public
#define PP_SEP_TIMES( ... )                *
// @public
#define PP_SEP_DIVIDE( ... )               /
// @public
#define PP_SEP_MODULO( ... )               %
// @public
#define PP_SEP_AND( ... )                  &&
// @public
#define PP_SEP_OR( ... )                   ||
// @public
#define PP_SEP_LT( ... )                   <
// @public
#define PP_SEP_LE( ... )                   <=
// @public
#define PP_SEP_EQ( ... )                   ==
// @public
#define PP_SEP_NEQ( ... )                  !=
// @public
#define PP_SEP_GE( ... )                   >=
// @public
#define PP_SEP_GT( ... )                   >
// @public
#define PP_SEP_BIT_AND( ... )              &
// @public
#define PP_SEP_BIT_OR( ... )               |
// @public
#define PP_SEP_BIT_XOR( ... )              ^
// @public
#define PP_SEP_BIT_LSHIFT( ... )           <<
// @public
#define PP_SEP_BIT_RSHIFT( ... )           >>
// @public
#define PP_SEP_ASSIGN( ... )               =
// @public
#define PP_SEP_PLUS_ASSIGN( ... )          +=
// @public
#define PP_SEP_MINUS_ASSIGN( ... )         -=
// @public
#define PP_SEP_TIMES_ASSIGN( ... )         *=
// @public
#define PP_SEP_DIVIDE_ASSIGN( ... )        /=
// @public
#define PP_SEP_MODULO_ASSIGN( ... )        %=
// @public
#define PP_SEP_BIT_AND_ASSIGN( ... )       &=
// @public
#define PP_SEP_BIT_OR_ASSIGN( ... )        |=
// @public
#define PP_SEP_BIT_XOR_ASSIGN( ... )       ^=
// @public
#define PP_SEP_BIT_LSHIFT_ASSIGN( ... )    <<=
// @public
#define PP_SEP_BIT_RSHIFT_ASSIGN( ... )    >>=
// @public
#define PP_SEP_FIELD( ... )                .
// @public
#define PP_SEP_DEREF_FIELD( ... )          ->


#endif // ifndef LIBPP_SEPARATORS_H

