#include <math.h>
#include "my_ceil.h"
#define SDK_EXPORTS
SDK_API double my_ceil(double d)
{
    if (d - floor(d) != 0.0) d += 1.0;
    return floor(d);
}
