#include "my_ceil.h"
#define SDK_EXPORTS
#include <math.h>
//using < pour utilise le header dans le path
SDK_API double my_ceil2(double d) // this is a fake lib
{
    if (d - floor(d) != 0.0) d += 1.0;
    return floor(d);
}
