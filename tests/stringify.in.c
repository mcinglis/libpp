
#include <limits.h>
#include "stringify.h"

PP_STRINGIFY( example )

PP_STRINGIFY( example of multiple words )

PP_STRINGIFY( example, of, multiple, arguments )

PP_STRINGIFY( argument, spacing,     isnt,          preserved )

PP_STRINGIFY( CHAR_BIT is not evaluated )

PP_STRINGIFY_E( CHAR_BIT is evaluated )


