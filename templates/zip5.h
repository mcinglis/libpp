
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


#ifndef LIBPP_ZIP5_H
#define LIBPP_ZIP5_H


#include "args.h"   // PP_ARGS_*
#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
// Takes five lists, `VS`, `WS`, `XS`, `YS`, and `ZS`, of at most {limit}
// elements and at least one element, where `WS`, `XS`, `YS` and `ZS` each
// have at least as many elements as `VS`, and returns `n` 5-element lists
// separated by commas, where `n` is the length of `VS`. The `i`th returned
// list will be `(v,w,x,y,z)`, consisting of the `i`th elements of the five
// given lists.
//
//     PP_ZIP5( (a), (e), (j), (q), (v) )
//     >>> (a,e,j,q,v)
//     PP_ZIP5( (a), (e,f), (j,k,l), (q,r), (v) )
//     >>> (a,e,j,q,v)
//     PP_ZIP5( (a,b), (e,f), (j,k), (q,r), (v,w) )
//     >>> (a,e,j,q,v), (b,f,k,r,w)
//     PP_ZIP5( (a,b), (e,f,g), (j,k), (q,r,s,t), (v,w) )
//     >>> (a,e,j,q,v), (b,f,k,r,w)
//     PP_ZIP5( (a,b,c), (e,f,g), (j,k,l), (q,r,s), (v,w,x) )
//     >>> (a,e,j,q,v), (b,f,k,r,w), (c,g,l,s,x)
//
#define PP_ZIP5( VS, WS, XS, YS, ZS ) \
    PP_CONCAT( PP_ZIP5_, PP_COUNT VS ) \
        ( PP_ZIP5_BUFFER VS, PP_ZIP5_BUFFER WS, PP_ZIP5_BUFFER XS, \
          PP_ZIP5_BUFFER YS, PP_ZIP5_BUFFER ZS )


// PP_ZIP5_ARG_ERROR, which doesn't evaluate to anything, will be in a pair
// if the second list was shorter than the first, and this will prompt a
// compilation error.
#define PP_ZIP5_BUFFER( ... ) \
    ( __VA_ARGS__, PP_ZIP5_ARG_ERROR )


// Generated code:
{impls}
// End of generated code.


#endif // ifndef LIBPP_ZIP5_H


#####

def context(limit):
    zip5_n = ('#define PP_ZIP5_{n}( VS, WS, XS, YS, ZS ) \\\n'
              '    {body}\n')
    nth_list = ('(PP_ARGS_{n} VS,PP_ARGS_{n} WS,PP_ARGS_{n} XS,'
                'PP_ARGS_{n} YS,PP_ARGS_{n} ZS)')

    impls = ''
    body = ''
    for i in range(1, limit+1):
        body += nth_list.format(n=i)
        impls += zip5_n.format(n=i, body=body)
        body += ','
    return {'impls': impls}

