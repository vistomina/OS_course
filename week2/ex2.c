#include <string.h>
#include <stdio.h>

int main(){
char str[100];
printf ("Enter your string\n");
gets(str);
int length = strlen(str);
printf ("\nYour string in reverse:\n");
for (int i = length; i>=0; i--){
printf ("%c", str[i]);
}
return 0;
}
