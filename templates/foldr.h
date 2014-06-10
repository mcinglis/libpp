
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


#ifndef LIBPP_FOLDR_H
#define LIBPP_FOLDR_H


#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
//
//     PP_FOLDR( m, acc, a )
//     >>> m( a, acc )
//     PP_FOLDR( m, acc, a, b )
//     >>> m( a, m( b, acc ) )
//     PP_FOLDR( m, acc, a, b, c )
//     >>> m( a, m( b, m( c, acc ) ) )
//
// The result is undefined for more than {limit} arguments.
#define PP_FOLDR( M, ACC, ... ) \
    PP_CONCAT( PP_FOLDR_, PP_COUNT( __VA_ARGS__ ) )( M, ACC, __VA_ARGS__ )


// Generated code:
{impls}


#endif // ifndef LIBPP_FOLDR_H


#####

def context(limit):
    from functools import reduce

    foldr_n = ('#define PP_FOLDR_{n}( M, ACC, {args} ) \\\n'
               '    {body}\n')

    impls = ''
    args = ['_1']
    for i in range(1, limit+1):
        impls += foldr_n.format(n    = i,
                                args = ','.join(args),
                                body = reduce(lambda acc, x:
                                                'M({},{})'.format( x, acc ),
                                              reversed(args),
                                              'ACC'))
        args.append('_{}'.format(str(i+1)))

    return {'impls': impls}

