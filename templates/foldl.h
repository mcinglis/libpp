
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


#ifndef LIBPP_FOLDL_H
#define LIBPP_FOLDL_H


#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
//
//     PP_FOLDL( m, acc, a )
//     >>> m( acc, a )
//     PP_FOLDL( m, acc, a, b )
//     >>> m( m( acc, a ), b )
//     PP_FOLDL( m, acc, a, b, c )
//     >>> m( m( m( acc, a ), b ), c )
//
// The result is undefined for more than {limit} arguments.
#define PP_FOLDL( M, ACC, ... ) \
    PP_CONCAT( PP_FOLDL_, PP_COUNT( __VA_ARGS__ ) )( M, ACC, __VA_ARGS__ )


// Generated code:
{impls}


#endif // ifndef LIBPP_FOLDL_H


#####

def context(limit):
    foldl_n = ('#define PP_FOLDL_{n}( M, ACC, {args} ) \\\n'
               '    {body}\n')

    impls = ''
    args = '_1'
    body = 'M(ACC,_1)'
    for i in range(1, limit+1):
        impls += foldl_n.format(n=i, args=args, body=body)
        next_arg = '_{}'.format(str(i+1))
        args += ',{}'.format(next_arg)
        body = 'M({},{})'.format(body, next_arg)

    return {'impls': impls}

