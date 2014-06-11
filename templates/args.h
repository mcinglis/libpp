
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


#ifndef LIBPP_ARGS_H
#define LIBPP_ARGS_H


// Generated code:
{impls}


#endif // ifndef LIBPP_ARGS_H


#####

def context(limit):
    args_n = '#define PP_ARGS_{n}( {args}, ... ) {body}\n'

    impls = ''
    args = ['_1']
    for i in range(1, limit+1):
        impls += args_n.format(n=i,
                               args=','.join(args),
                               body=args[i-1])
        args.append('_{}'.format(i+1))
    return {'impls': impls}

