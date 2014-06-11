
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


#ifndef LIBPP_CONCAT_H
#define LIBPP_CONCAT_H


// @public
// The `##` operator is specified to only replace a preprocessor expression
// if that expression is exactly the name of an argument of the macro using
// the `##` operator. This macro can be used to concatenate any two
// preprocessor expressions, and not just arguments, by delaying the
// concatenation to after a round of evaluation of the two expressions.
#define PP_CONCAT( X, Y ) \
    PP_CONCAT_( X, Y )


#define PP_CONCAT_( X, Y ) \
    X ## Y


#endif // ifndef LIBPP_CONCAT_H

