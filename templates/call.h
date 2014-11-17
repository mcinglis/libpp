
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


#ifndef LIBPP_CALL_H
#define LIBPP_CALL_H


#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
//
//     PP_CALL( ( a, b ), sep, m )
//     >>> m( a, b )
//     PP_CALL( ( a ), sep, m, n )
//     >>> m( a ) sep( m, n ) n( a )
//     PP_CALL( ( a, b ), sep, m, n, o )
//     >>> m( a, b ) sep( m, n ) n( a, b ) sep( n, o ) o( a, b )
//
// The result is undefined for more than {limit} variable arguments.
#define PP_CALL( A, SEP, ... ) \
    PP_CONCAT( PP_CALL_, PP_COUNT( __VA_ARGS__ ) )( A, SEP, __VA_ARGS__ )


// Generated code:
{impls}


#endif // ifndef LIBPP_CALL_H


#####

def context(limit):
    call_n = ('#define PP_CALL_{n}( A, S, {args} ) \\\n'
              '    {body}\n')

    impls = ''
    args = '_1'
    body = '_1 A'
    for i in range(1, limit+1):
        impls += call_n.format(n=i, args=args, body=body)
        next_arg = '_{}'.format(i+1)
        args += ',{}'.format(next_arg)
        body += ' S(_{cur},{next}) {next} A'.format(cur=i, next=next_arg)

    return {'impls': impls}

