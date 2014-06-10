
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


#ifndef LIBPP_MAP_PAIRS_H
#define LIBPP_MAP_PAIRS_H


#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
//
//     PP_MAP_PAIRS( m, sep, a, b )
//     >>>  m( a, b )
//     PP_MAP_PAIRS( m, sep, a, b, c )
//     >>>  m( a, b ) sep( a, b, c ) m( b, c )
//     PP_MAP_PAIRS( m, sep, a, b, c, d )
//     >>>  m( a, b ) sep( a, b, c ) m( b, c ) sep( b, c, d ) m( c, d )
//
// The result is undefined for more than {limit} variable arguments.
#define PP_MAP_PAIRS( M, SEP, ... ) \
    PP_CONCAT( PP_MAP_PAIRS_, PP_COUNT( __VA_ARGS__ ) )( M, SEP, __VA_ARGS__ )


// Generated code:
{impls}


#endif // ifndef LIBPP_MAP_PAIRS_H


#####

def context(limit):
    map_pairs_n = ('#define PP_MAP_PAIRS_{n}( M, S, {args} ) \\\n'
                   '    {body}\n')

    impls = ''
    args = '_1,_2'
    body = 'M(_1,_2)'
    for i in range(2, limit+1):
        impls += map_pairs_n.format(n=i, args=args, body=body)
        next_arg = '_{}'.format(i+1)
        args += ',{}'.format(next_arg)
        body += (' S(_{prev},_{cur},{next}) M(_{cur},{next})'
                 .format(prev=i-1, cur=i, next=next_arg))

    return {'impls': impls}

