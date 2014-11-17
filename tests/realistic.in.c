
#include "call.h"       // PP_CALL
#include "foldr.h"      // PP_FOLDR
#include "map-lists.h"  // PP_MAP_LISTS
#include "map-pairs.h"  // PP_MAP_PAIRS
#include "separators.h" // PP_SEP_AND, PP_SEP_NONE
#include "zip.h"        // PP_ZIP


#define PLUS( X, Y ) \
    ( ( X ) + ( Y ) )

#define SUM( ... ) \
    PP_FOLDR( PLUS, 0, __VA_ARGS__ )

SUM( 6 )
SUM( 49, 1.56, 0x76, 'e', 748172 )


#define LESS_THAN( X, Y ) \
    ( ( X ) < ( Y ) )

#define INCREASING( ... ) \
    PP_MAP_PAIRS( LESS_THAN, PP_SEP_AND, __VA_ARGS__ )

INCREASING( 873, 9283 )
INCREASING( 14, 87, 1267, 9837.542, ( 123 * 471 ), 0746 )


#define NAMES foo, bar, baz, glop, duh
#define VALUES 98, 47, 9.38, 756, 2376

#define PAIRS PP_ZIP( ( NAMES ), ( VALUES ) )

#define DEFINE_FUNC( NAME, VALUE ) \
    double calc_##NAME(double const x) { \
        return x * VALUE; \
    }
PP_MAP_LISTS( DEFINE_FUNC, PP_SEP_NONE, PAIRS )


#define PTR_TYPE ( void *, ptr )

#define MAKE_FUNC_A( T, N ) \
    T func_a_##N( T const x ) { return x; }

#define MAKE_FUNC_B( T, N ) \
    T func_b_##N( T const x ) { return x != NULL; }

#define MAKE_FUNC_C( T, N ) \
    T func_c_##N( T const x ) { return x == NULL; }

PP_CALL( PTR_TYPE, PP_SEP_NONE, MAKE_FUNC_A,
                                MAKE_FUNC_B,
                                MAKE_FUNC_C )



