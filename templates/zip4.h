
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


#ifndef LIBPP_ZIP4_H
#define LIBPP_ZIP4_H


#include "args.h"   // PP_ARGS_*
#include "concat.h" // PP_CONCAT
#include "count.h"  // PP_COUNT


// @public
// Takes four lists, `WS`, `XS`, `YS`, and `ZS`, of at most {limit} elements
// and at least one element, where `XS`, `YS` and `ZS` each have at least as
// many elements as `WS`, and returns `n` 4-element lists separated by
// commas, where `n` is the length of `WS`. The `i`th returned list will be
// `(w,x,y,z)`, consisting of the `i`th elements of the four given lists.
//
//     PP_ZIP4( (a), (f), (m), (v) )            >>>  (a,f,m,v)
//     PP_ZIP4( (a), (f,g), (m,n,o), (v) )      >>>  (a,f,m,v)
//     PP_ZIP4( (a,b), (f,g), (m,n), (v,w) )    >>>  (a,f,m,v), (b,g,n,w)
//
#define PP_ZIP4( WS, XS, YS, ZS ) \
    PP_CONCAT( PP_ZIP4_, PP_COUNT WS ) \
        ( PP_ZIP4_BUFFER WS, PP_ZIP4_BUFFER XS, \
          PP_ZIP4_BUFFER YS, PP_ZIP4_BUFFER ZS )


// PP_ZIP4_ARG_ERROR, which doesn't evaluate to anything, will be in a pair
// if the second list was shorter than the first, and this will prompt a
// compilation error.
#define PP_ZIP4_BUFFER( ... ) \
    ( __VA_ARGS__, PP_ZIP4_ARG_ERROR )


// Generated code:
{impls}
// End of generated code.


#endif // ifndef LIBPP_ZIP4_H


#####

def context(limit):
    zip4_n = ('#define PP_ZIP4_{n}( WS, XS, YS, ZS ) \\\n'
              '    {body}\n')
    nth_list = ('(PP_ARGS_{n} WS,PP_ARGS_{n} XS,'
                'PP_ARGS_{n} YS,PP_ARGS_{n} ZS)')

    impls = ''
    body = ''
    for i in range(1, limit+1):
        body += nth_list.format(n=i)
        impls += zip4_n.format(n=i, body=body)
        body += ','
    return {'impls': impls}

