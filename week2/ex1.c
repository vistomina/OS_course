#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
int a = INT_MAX;
float b = FLT_MAX;
double c = DBL_MAX;

printf ("Integer = %d\nFloat = %f\nDouble = %f\n");

printf ("Size of a %lu\nSize of b %lu\nSize of c %lu\n", sizeof(a), sizeof(b), sizeof(c));
return 0;
}
