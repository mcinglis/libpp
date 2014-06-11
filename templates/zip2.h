
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


#ifndef LIBPP_ZIP2_H
#define LIBPP_ZIP2_H


#include "args.h"   // PP_ARGS_*
#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
// Takes two lists `XS` and `YS` of at most {limit} elements, where `YS` has
// at least as many elements as `XS`, and returns `n` pairs separated by
// commas, where `n` is the length of `XS`. The `i`th returned pair will be
// `(x,y)`, where `x` is the `i`th element of `XS`, and `y` is the `i`th
// element of `YS`. Both lists must have at least one element.
//
//     PP_ZIP2( (a), (n) )                  >>>  (a,n)
//     PP_ZIP2( (a), (n,o) )                >>>  (a,n)
//     PP_ZIP2( (a,b), (n,o) )              >>>  (a,n), (b,o)
//     PP_ZIP2( (a,b), (n,o,p,q) )          >>>  (a,n), (b,o)
//     PP_ZIP2( (a,b,c), (n,o,p) )          >>>  (a,n), (b,o), (c,p)
//     PP_ZIP2( ((a,b),(c,d)), (n,(o,p)) )  >>>  ((a,b),n), ((c,d),(o,p))
//
#define PP_ZIP2( XS, YS ) \
    PP_CONCAT( PP_ZIP2_, PP_COUNT XS )( PP_ZIP2_BUFFER XS, PP_ZIP2_BUFFER YS )


// PP_ZIP2_ARG_ERROR, which doesn't evaluate to anything, will be in a pair
// if the second list was shorter than the first, and this will prompt a
// compilation error.
#define PP_ZIP2_BUFFER( ... ) \
    ( __VA_ARGS__, PP_ZIP2_ARG_ERROR )


// Generated code:
{impls}
// End of generated code.


#endif // ifndef LIBPP_ZIP2_H


#####

def context(limit):
    zip2_n = ('#define PP_ZIP2_{n}( XS, YS ) \\\n'
              '    {body}\n')
    nth_pair = '(PP_ARGS_{n} XS,PP_ARGS_{n} YS)'

    impls = ''
    body = ''
    for i in range(1, limit+1):
        body += nth_pair.format(n=i)
        impls += zip2_n.format(n=i, body=body)
        body += ','
    return {'impls': impls}

