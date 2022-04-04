#include <libmain/okr.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 100

void okr(float rad)
{
    printf("\nPerim: ");
    printf("%f\n", 2 * M_PI * rad);
    printf("Square: ");
    printf("%f", M_PI * pow(rad, 2));
}
