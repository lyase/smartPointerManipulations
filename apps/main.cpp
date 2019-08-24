/* \File main.c
* \detail project demo using cmake for
* lib build static
* shared
* , config files generation & usage ....
* debugging cmake
* verbose build
* running  tests with build
* rm -rvf build-raspi2.1 ; mkdir build-raspi2.1 ; cd build-raspi2.1 ; cmake --debug-output .. ; make VERBOSE=1 ;  make test  ; cd ..
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/my_ceil.h"
#include "config.hpp"
int main(int argc, char * argv[])
{
    int i;
    for (i=0; i < argc; i++) {
        printf("Argument %ld : %s \n", i+1, argv[i]);
    }
    double d = atof(argv[1]);
    printf("using function my_ceil of librairy %f\n", my_ceil(d));
    printf("using function my_ceil2 of librairy %f\n", my_ceil2(d));
    printf("build time coded path  :%s\n",DATA_DIR);
    return EXIT_SUCCESS;
}
