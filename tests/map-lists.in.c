#include "map-lists.h"

PP_MAP_LISTS( m, s, (a) )
PP_MAP_LISTS( m, s, (a), (b) )
PP_MAP_LISTS( m, s, (a), (b), (c) )
PP_MAP_LISTS( m, s, (a,b) )
PP_MAP_LISTS( m, s, (a,b), (c,d) )
PP_MAP_LISTS( m, s, (a,b), (c,d), (e,f) )
PP_MAP_LISTS( m, s, (a,b,c) )
PP_MAP_LISTS( m, s, (a,b,c), (d,e,f) )
PP_MAP_LISTS( m, s, (a,b,c), (d,e,f), (g,h,i) )
PP_MAP_LISTS( m, s, (a,b), (c,d), (e,f,g) )
PP_MAP_LISTS( m, s, (a,b,c), (d), (e,f) )

#define M( ... ) \
    ( blah __VA_ARGS__ )
#define S( X, Y ) \
    ( left: X, right: Y )
PP_MAP_LISTS( M, S, (a,b), (c,d), (e,f,g) )

