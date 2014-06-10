
**[Libpp](https://github.com/mcinglis/libpp)** provides functional-programming macros for the C preprocessor, enabling a crude form of a metaprogramming. Libpp is usable, simple, and fast. Best of all, unlike my [previous efforts](https://github.com/mcinglis/macrofun), it conforms to the C11 and C99 standards.

``` c
#include <libpp/foldr.h>         // PP_FOLDR
#include <libpp/intersperse.h>   // PP_INTERSPERSE
#include <libpp/map.h>           // PP_MAP

#define ASSERT( ... ) \
    PP_MAP( assert, PP_SEP_SEMICOLON, __VA_ARGS__ )
ASSERT( X, Y, Z );  // assert( X ); assert( Y ); assert( Z );

#define ALL( ... ) \
    ( PP_INTERSPERSE( PP_SEP_AND, __VA_ARGS__ ) )
ALL( X, Y, Z )  // ( ( X ) && ( Y ) && ( Z ) )

#define MULTIPLY( X, Y ) \
    ( ( X ) * ( Y ) )
#define PRODUCT( ... ) \
    ( PP_FOLDR( MULTIPLY, 1, __VA_ARGS__ ) )
PRODUCT( 87, 6.324, -732 )  // ( 87 * ( 6.324 * -732 ) )
```

I've found Libpp to be useful for building macros that let me test and assert the invariants of a structure, without repetition of the individual invariants. `PP_MAP_LISTS` makes it much easier to write generic macros with C11's `_Generic`. I'm also Libpp to (re)build a testing library with a really nice interface. As a taster:

``` c
return assertions( ASSERTION( 1 + 3 == 4 ),
                   ASSERTION( "test"[2] == 'x' ),
                   ASSERTION( some_function() ) );
// Can become (thanks to PP_MAP):
return ASSERTIONS( 1 + 3 == 4,
                   "test"[2] == 'x',
                   some_function() );
```

Because the C preprocessing language doesn't permit true recursion, the supposedly variable-argument macros (`PP_MAP`, `PP_FOLDR`, etc) are actually limited in how many arguments they can take: by default, 128. This limit, as well as notable preprocessing speed improvements, lead me to automatically generating parts of the header files. Running `make` will generate the header files from the corresponding templates in the `templates/` directory. So, if you want the macros to accept more arguments, just change the `limit` variable in the Makefile, then `make clean && make`.

Note that the Make targets run the `templates/render.py` script, which was written for Python 3; it requires a `python3` program in your PATH.

I'm storing the rendered templates in version control to make the project more approachable. People can read the code as it's used without cloning the repository and running Make. Also, users can clone the repository and use the headers without requiring Python 3.

The definitions of public macros are preceded by a comment with a `// @public` line: the behavior of these macros will only change between major versions, as per [semantic versioning](http://semver.org/). Any macro not preceded by such a line is private, and its behavior could change any time. The header files also include example usage of the more-complicated macros.


## Q&A

#### How is this different from other C preprocessor libraries?

Libpp is simple and pragmatic: it's not a quirky experiment. The macros have clean interfaces and understandable implementations. The macros evaluate as fast as possible, and the header files are as small as possible, so your build times won't suffer. Also, Libpp is actively maintained!

#### Generating preprocessor code? Are you insane?

Yes, I am. Still, generating the code is the best way out. It's maintainable, flexible and fast.

#### Why don't you provide a header that includes everything?

I don't like unified headers, and I don't want to encourage their use. Unified headers:

- make it harder to determine where a certain identifier came from;
- pollute the namespace, which can lead to all kinds of nasty bugs;
- relieve the library developer of their responsibility to provide loosely-coupled modules clearly separated by their purpose and abstraction, and of the user to use those modules as such;
- make it harder to maintain ABI compatibility;
- make code slower to compile and link.

If you need to include six header files from Libpp, your source file is probably doing too much, and should be broken up.

#### Does this work for C++ or Objective-C?

This library depends on C99 macro syntax, so it won't work for C++. Apparently Objective-C [is a superset of C99](https://lists.apple.com/archives/objc-language/2005/Aug/msg00050.html), so it should work there, but I haven't tested it.

For Objective-C users, please note the AGPL license: you can't use this library to develop nonfree software. Contact me for proprietary licensing options (but I'd encourage you to consider releasing your work as free software!).

### Why do you license Libmacro under the AGPL?

[I believe that nonfree software is harmful](http://minglis.id.au/blog/2014/04/09/free-software-free-society.html), and I don't want to contribute to its development at all. I believe that a free society must necessarily operate on free software. I want to encourage the development of free software, and discourage the development of nonfree software.

The [GPL](https://gnu.org/licenses/gpl.html) was designed to ensure that the software stays free software; "to ensure that every user has freedom". The GPL's protections may have sufficed in 1990, but they don't in 2014. The GPL doesn't consider users of a web service to be users of the software implementing that server. Thankfully, the [AGPL](https://www.gnu.org/licenses/agpl.html) does.

The AGPL ensures that if Libpp is used to implement a web service, then the entire source code of that web service must be made available. This way, I'm not contributing to nonfree software, whether it's executed locally or provided over a network.


## License: AGPL

**Copyright 2014 Malcolm Inglis <http://minglis.id.au>**

Libpp is free software: you can redistribute it and/or modify it under the terms of the [GNU Affero General Public License](https://gnu.org/licenses/agpl.html) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Libpp is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with Libpp. If not, see <https://gnu.org/licenses/>.

Contact me for proprietary licensing options.

