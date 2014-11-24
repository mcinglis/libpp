
**Libpp** provides functional-programming macros for the C preprocessor, enabling a crude form of a metaprogramming. Libpp is simple, fast, and standards-conformant (C99 and up).

``` c
#include <libpp/foldr.h>         // PP_FOLDR
#include <libpp/intersperse.h>   // PP_INTERSPERSE
#include <libpp/map.h>           // PP_MAP
#include <libpp/separators.h>    // PP_SEP_SEMICOLON, PP_SEP_AND

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
PRODUCT( 87, 6.324, -732 )  // ( 87 * ( 6.324 * ( -732 * 1 ) ) )
```

I've found Libpp to be useful for:

- improving APIs and removing repetition in my code.
- treating code as data, e.g. by defining a struct's invariants as a list of expressions, then using that list in multiple places.
- defining variable-argument generic macros as demonstrated above.
- doing simplistic compile-time computations (although in general I prefer to rely on intelligent compilation).

I'm using Libpp to build a testing library with a really nice interface:

``` c
return assertions( ASSERTION( 1 + 3 < 6 ),
                   ASSERTION( "test"[2] == 'x' ),
                   ASSERTION( func() != NULL ) );
// Thanks to PP_MAP, can become:
return assertions( 1 + 3 < 6,
                   "test"[2] == 'x',
                   func() != NULL );
```

See the [`realistic` test input](tests/realistic.in.c) and [output](tests/realistic.out.c) for more examples.

Because the C preprocessor doesn't permit true recursion, the supposedly variable-argument macros (`PP_MAP`, `PP_FOLDR`, etc) are actually limited in how many arguments they can take: by default, 128. This limit, as well as notable preprocessing speed improvements, lead me to automatically generating parts of the header files. Running `make` will generate the header files from the corresponding templates in the [`templates/`](templates/) directory. If you want the macros to accept more or fewer arguments, just set the `LIBPP_LIMIT` environment variable and run `make clean all`.

Note that `make` will execute the [`templates/render.py`](templates/render.py) script, which was written for Python 3.3; it assumes `python3` is on your PATH.

I'm storing the rendered templates in version control to make the project more approachable. People can read the code as it's used without cloning the repository and running Make. Also, users can clone the repository and include the headers without requiring Python 3 to generate them.


## Releases

I'll tag the releases according to [semantic versioning](http://semver.org/spec/v2.0.0.html). All the macros preceded by `// @public`, or between `// @public begin` and `// @public end`, are considered public: they'll only change between major versions. The other macros could change any time. The `PP_` namespace is reserved by Libpp, so new identifiers prefixed with `PP_` don't warrant a major version bump.

Every version tag will be signed with [my GPG key](http://pool.sks-keyservers.net/pks/lookup?op=vindex&search=0xD020F814) (fingerprint: `0xD020F814`).


## Tests

```
$ make test
tests/run.bash
Pass: call
Pass: foldl
Pass: foldr
Pass: intersperse
...
```

The tests work by `diff`ing the output of `gcc -E` with each `tests/*.in.c` against the corresponding `tests/*.out.c`. Those `out.c` files contain the preprocessor output provided by GCC 4.8. Thus, the tests may "fail" with other preprocessors, even though they output functionally-equivalent code.


## Collaboration

Libpp is available at [Gitorious](https://gitorious.org/mcinglis/libpp), [Bitbucket](https://bitbucket.org/mcinglis/libpp), and [GitHub](https://github.com/mcinglis/libpp).

Questions, discussion, bug reports and feature requests are welcome at [the GitHub issue tracker](https://github.com/mcinglis/libpp/issues), or via [emails](mailto:me@minglis.id.au).

To contribute changes, you're welcome to [email me](mailto:me@minglis.id.au) patches as per `git format-patch`, or to send me a pull request on any of the aforementioned sites. You're also welcome to just send me a link to your remote repository, and I'll merge stuff from that as I want to.

To accept notable contributions, I'll require you to assign your copyright to me. In your email/pull request and commit messages, please insert: "*I hereby irrevocably transfer to Malcolm Inglis (http://minglis.id.au) all copyrights, title, and interest, throughout the world, in these contributions to Libpp*". If you can, please sign the email or pull request, ensuring your GPG key is publicly available.


## Q&A

### How is this different from other C preprocessor libraries?

Libpp is simple and pragmatic: it's not a quirky experiment. The macros have clean interfaces and understandable implementations. The macros evaluate as fast as possible, and the header files are as small as possible, so your build times won't suffer. Also, Libpp is actively maintained!

### Generating preprocessor code? Are you insane?

Yes, I am. Still, generating the code is the best way out: it's maintainable, flexible, and fast.

### Why don't you provide a header that includes everything?

I don't like unified headers, and I don't want to encourage their use. Unified headers:

- relieve the library developer of their responsibility to provide loosely-coupled modules clearly separated by their purpose and abstraction, and of the user to use those modules as such;
- make it harder to determine where a certain identifier came from;
- make code slower to compile and link.
- pollute the namespace, which can lead to all kinds of nasty bugs;
- make it harder to maintain ABI compatibility;

If you need to include six header files from Libpp, your source file is probably doing too much, and should be broken up.


## License

**Copyright 2014 Malcolm Inglis <http://minglis.id.au>**

Libpp is free software: you can redistribute it and/or modify it under the terms of the [GNU Affero General Public License](https://gnu.org/licenses/agpl.html) as published by the [Free Software Foundation](https://fsf.org), either version 3 of the License, or (at your option) any later version.

Libpp is distributed in the hope that it will be useful, but **without any warranty**; without even the implied warranty of **merchantability** or **fitness for a particular purpose**. See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with Libpp. If not, see <https://gnu.org/licenses/>.

[Contact me](mailto:me@minglis.id.au) for proprietary licensing options.

### Why AGPL?

[I believe that nonfree software is harmful](http://minglis.id.au/blog/2014/04/09/free-software-free-society.html), and I don't want to contribute to its development at all. I believe that a free society must necessarily operate on free software. I want to encourage the development of free software, and discourage the development of nonfree software.

The [GPL](https://gnu.org/licenses/gpl.html) was designed to ensure that the software stays free software; "to ensure that every user has freedom". The GPL's protections may have sufficed in 1990, but they don't in 2014. The GPL doesn't consider users of a web service to be users of the software implementing that server. Thankfully, the AGPL does.

The AGPL ensures that if Libpp is used to implement a web service, then the entire source code of that web service must be free software. This way, I'm not contributing to nonfree software, whether it's executed locally or provided over a network.

