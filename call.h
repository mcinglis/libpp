
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


#ifndef LIBPP_CALL_H
#define LIBPP_CALL_H


// @public
// Invokes the macro `M` with the variable arguments as they evaluate to,
// rather than what they were written as. This works by delaying the
// invokation to a second round of preprocessor evaluation.
#define PP_CALL( M, ... ) \
    PP_CALL_EVAL( M PP_CALL_SEP ( __VA_ARGS__ ) )


#define PP_CALL_SEP
#define PP_CALL_EVAL( ... ) __VA_ARGS__


#endif // ifndef LIBPP_BLANK_H

