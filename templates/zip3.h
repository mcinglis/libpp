
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


#ifndef LIBPP_ZIP3_H
#define LIBPP_ZIP3_H


#include "args.h"   // PP_ARGS_*
#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
// Takes three lists, `XS`, `YS`, and `ZS`, of at most {limit} elements and
// at least one element, where `YS` and `ZS` each have at least as many
// elements as `XS`, and returns `n` triples separated by commas, where `n`
// is the length of `XS`. The `i`th returned triple will be `(x,y,z)`,
// consisting of the `i`th elements of the three given lists.
//
//     PP_ZIP3( (a), (j), (r) )                 >>>  (a,j,r)
//     PP_ZIP3( (a), (j,k), (r) )               >>>  (a,j,r)
//     PP_ZIP3( (a), (j,k), (r,s) )             >>>  (a,j,r)
//     PP_ZIP3( (a,b), (j,k), (r,s) )           >>>  (a,j,r), (b,k,s)
//     PP_ZIP3( (a,b,c), (j,k,l), (r,s,t,u) )   >>>  (a,j,r), (b,k,s), (c,l,t)
//
#define PP_ZIP3( XS, YS, ZS ) \
    PP_CONCAT( PP_ZIP3_, PP_COUNT XS ) \
        ( PP_ZIP3_BUFFER XS, PP_ZIP3_BUFFER YS, PP_ZIP3_BUFFER ZS )


// PP_ZIP3_ARG_ERROR, which doesn't evaluate to anything, will be in a pair
// if the second list was shorter than the first, and this will prompt a
// compilation error.
#define PP_ZIP3_BUFFER( ... ) \
    ( __VA_ARGS__, PP_ZIP3_ARG_ERROR )


// Generated code:
{impls}
// End of generated code.


#endif // ifndef LIBPP_ZIP3_H


#####

def context(limit):
    zip3_n = ('#define PP_ZIP3_{n}( XS, YS, ZS ) \\\n'
              '    {body}\n')
    nth_triple = '(PP_ARGS_{n} XS,PP_ARGS_{n} YS,PP_ARGS_{n} ZS)'

    impls = ''
    body = ''
    for i in range(1, limit+1):
        body += nth_triple.format(n=i)
        impls += zip3_n.format(n=i, body=body)
        body += ','
    return {'impls': impls}

