#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>


#define CUBE(x) (x*x*x)

int main()
{
    int a, b=3;
    a = CUBE(++b);
    printf("%d, %dn", a, b);
    return 0;
}