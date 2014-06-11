
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


#ifndef LIBPP_ZIP_H
#define LIBPP_ZIP_H


#include "args.h"       // PP_ARGS_*
#include "concat.h"     // PP_CONCAT
#include "count.h"      // PP_COUNT
#include "map-lists.h"  // PP_MAP_LISTS
#include "separators.h" // PP_SEP_COMMA


// @public
// Let `n` be the number of lists given.
// Let `m` be the length of the first given list, `XS`.
//
// This macro takes at least 2 and at most {limit} lists, each having a
// length of at least 1 and at most {limit}, and each list being at least `m`
// elements long, and evaluates to `n` lists of length `m`, where the `i`th
// list consists of the `i`th elements in each given lists.
//
// A list is a series of comma-separated expressions surrounded by
// parentheses, like `(1,2,3)`.
//
//     PP_ZIP( (10), (20), (30) )
//     >>> (10,20,30)
//     PP_ZIP( (10,11), (20,21), (30,31) )
//     >>> (10,20,30), (11,21,31)
//     PP_ZIP( (10,11,12), (20,21,22,23,24,25), (30,31,32) )
//     >>> (10,20,30), (11,21,31), (12,22,32)
//
#define PP_ZIP( XS, ... ) \
    PP_CONCAT( PP_ZIP_, PP_COUNT XS ) \
        ( PP_MAP_LISTS( PP_ZIP_BUFFER, PP_SEP_COMMA, XS, __VA_ARGS__ ) )

#define PP_ZIP_BUFFER( ... ) \
    ( __VA_ARGS__, PP_ZIP_ARG_LIMIT_EXCEEDED )

// We append an element to each given list so that the `PP_ARGS` macros are
// always called with their variable argument supplied, as the ISO C standard
// requires.


// Generated code:
{impls}
// End of generated code


#endif // ifndef LIBPP_ZIP_H


#####

def context(limit):
    zip_n = ('#define PP_ZIP_{n}( ... ) \\\n'
             '    {body}\n')
    nth_list = ('( PP_MAP_LISTS( PP_ARGS_{n}, PP_SEP_COMMA, __VA_ARGS__ ) )')
    # We implement the macros with `MAP_LISTS` so that we don't need to
    # generate limit*limit different macros to handle each possible
    # combination of the number of given lists and the size of the first list.
    # `MAP_LISTS` is already really fast, and I expect that the preprocessor
    # can evaluate it a few times quicker than it could read and parse a
    # multi-megabyte header file.

    impls = ''
    body = ''
    for i in range(1, limit+1):
        body += nth_list.format(n=i)
        impls += zip_n.format(n=i, body=body)
        body += ', '
    return {'impls': impls}

