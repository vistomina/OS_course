#include <stdio.h>
int main(){

int n;
scanf("%d", &n);
int a = 1;
for (int i = 0; i < n; i++){
	
	for (int j = 0; j <= (2*n-1-a)/2; j++){
		printf (" ");
	}

	for (int g = 0; g < a; g++){
		printf ("*");
	} 
	
	a += 2;

	for (int f = (2*n-1+a)/2; f <= (2*n-1); f++){
		printf (" ");
	}
	
	printf ("\n");

}

return 0;

}
