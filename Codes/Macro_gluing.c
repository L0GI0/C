#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>


#define FUN(i, j) i##j

int main()
{
    int va1=10;
    int va12=20;
    int va13=30;
    printf("%d", FUN(va1, 3));
    return 0;
}