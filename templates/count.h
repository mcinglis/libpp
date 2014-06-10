
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


#ifndef LIBPP_COUNT_H
#define LIBPP_COUNT_H


// The arguments of these macros have been generated.


// @public
// Evaluates to the number of arguments given. The result is undefined for
// more than {limit} arguments.
#define PP_COUNT( ... ) \
    PP_COUNT_( __VA_ARGS__, {limit_to_1}, vararg when given 1 )


// Evaluates to argument {limit}.
#define PP_COUNT_( {limit_to_1_args}, X, ... ) X


#endif // ifndef LIBPP_COUNT_H


#####

def context(limit):
    limit_to_1 = [str(i) for i in range(limit, 0, -1)]
    return {'limit_to_1':      ','.join(limit_to_1),
            'limit_to_1_args': ','.join('_{}'.format(n) for n in limit_to_1)}

