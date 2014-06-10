
#include "foldr.h"
#include "map-pairs.h"
#include "separators.h"


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

