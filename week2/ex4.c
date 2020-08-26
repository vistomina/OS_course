#include <stdio.h>
 void swap (int *a, int *b){
     int t;
     t = *a;
     *a = *b;
     *b = t;
}
int main() {
    int a;
    int b;
    printf ("Enter 1st num: ");
    scanf ("%d", &a);
    printf ("Enter 2nd num: ");
    scanf ("%d", &b);
    printf ("\n");
    swap(&a, &b);
    printf ("New 1st num: ");
    printf ("%d", a);
    printf ("\nNew 2nd num: ");
    printf ("%d", b); return 0;
}
