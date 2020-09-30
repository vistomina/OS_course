#include <stdio.h>
#include <stdlib.h>
int main(){
    
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    
    int * a = (int*)malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; i++ ){
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    free(a);
    
    return 0;
    
}
