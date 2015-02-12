
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


#ifndef LIBPP_INTERSPERSE_H
#define LIBPP_INTERSPERSE_H


#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
//
//     PP_INTERSPERSE( sep, a )
//     >>> a
//     PP_INTERSPERSE( sep, a, b )
//     >>> a sep( a, b ) b
//     PP_INTERSPERSE( sep, a, b, c )
//     >>> a sep( a, b ) b sep( b, c ) c
//
// Note that arguments are not parenthesized between calls to the separator
// macro; if you are separating expressions by arithmetic operators, you
// should probably use `PP_MAP` with `PP_PAREN` to parenthesize the
// individual arguments. The result is undefined for more than {limit}
// variable arguments.
#define PP_INTERSPERSE( SEP, ... ) \
    PP_CONCAT( PP_INTERSPERSE_, PP_COUNT( __VA_ARGS__ ) )( SEP, __VA_ARGS__ )


{impls}


#endif // ifndef LIBPP_INTERSPERSE_H


#####

def context(limit):
    intersperse_n = ('#define PP_INTERSPERSE_{n}( S, {args} ) \\\n'
                     '    {body}\n')

    impls = ''
    args = '_1'
    body = '_1'
    for i in range(1, limit+1):
        impls += intersperse_n.format(n=i, args=args, body=body)
        next_arg = '_{}'.format(i+1)
        args += ',{}'.format(next_arg)
        body += ' S(_{cur},{next}) {next}'.format(cur=i, next=next_arg)

    return {'impls': impls}

