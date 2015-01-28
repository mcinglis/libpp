
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


#ifndef LIBPP_STRINGIFY_H
#define LIBPP_STRINGIFY_H


// @public
// Replaces the given tokens with a string literal of those tokens conjoined
// by a comma and a space.
//
//     PP_STRINGIFY( example )
//     >>> "example"
//     PP_STRINGIFY( example of multiple words )
//     >>> "example of multiple words"
//     PP_STRINGIFY( example, of, multiple, arguments )
//     >>> "example, of, multiple, arguments"
//     PP_STRINGIFY( argument, spacing,     isnt,          preserved )
//     >>> "argument, spacing, isnt, preserved"
//
#define PP_STRINGIFY( ... ) #__VA_ARGS__


// @public
// Replaces the first evaluation of the given tokens with a string literal of
// those evaluations conjoined by a comma and a space.
//
//     PP_STRINGIFY( CHAR_BIT is not evaluated )
//     >>> "CHAR_BIT"
//     PP_STRINGIFY_E( CHAR_BIT is evaluated )
//     >>> "8"
//
#define PP_STRINGIFY_E( ... ) PP_STRINGIFY( __VA_ARGS__ )


#endif

