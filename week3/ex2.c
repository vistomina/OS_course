#include <stdio.h> 
#include <string.h>
void bubble_sort(int *list, int n) {
    int t;
  for (int c = n - 1 ; c >= 0; c--) {
    for (int d = 0 ; d < c; d++) {
      if (list[d] > list[d+1]) {
        t = list[d];
        list[d] = list[d+1];
        list[d+1] = t;
      }
    }
  };
}
int main() {
    int n; //array size
    printf("Print the size of your array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Print your array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nYour sorted array: ");
    bubble_sort(arr, n);
    for ( int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    return 0;
}
