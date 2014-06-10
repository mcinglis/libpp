
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


#ifndef LIBPP_MAP_H
#define LIBPP_MAP_H


#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
//
//     PP_MAP( m, sep, a )
//     >>> m( a )
//     PP_MAP( m, sep, a, b )
//     >>> m( a ) sep( a, b ) m( b )
//     PP_MAP( m, sep, a, b, c )
//     >>> m( a ) sep( a, b ) m( b ) sep( b, c ) m( c )
//
// The result is undefined for more than {limit} variable arguments.
#define PP_MAP( M, SEP, ... ) \
    PP_CONCAT( PP_MAP_, PP_COUNT( __VA_ARGS__ ) )( M, SEP, __VA_ARGS__ )


// Generated code:
{impls}


#endif // ifndef LIBPP_MAP_H


#####

def context(limit):
    map_n = ('#define PP_MAP_{n}( M, S, {args} ) \\\n'
             '    {body}\n')

    impls = ''
    args = '_1'
    body = 'M(_1)'
    for i in range(1, limit+1):
        impls += map_n.format(n=i, args=args, body=body)
        next_arg = '_{}'.format(i+1)
        args += ',{}'.format(next_arg)
        body += ' S(_{cur},{next}) M({next})'.format(cur=i, next=next_arg)

    return {'impls': impls}

