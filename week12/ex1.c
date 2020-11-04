#include <stdio.h>

int main() {
	FILE *ran = fopen("/dev/random", "r");
	char ranChars[21];

	fscanf(ran, "%c", ranChars);
	fclose(ran);

	ranChars[20] = '\0';
	char *it = ranChars;
	for (int i = 0; i < 20; ++i, it++) {
		*it = (*it % (char) 62) + (char) 65;
	}

	FILE *outF = fopen("ex1.txt", "w");
	fprintf(outF, "%s\n", ranChars);
	fclose(outF);

	return 0;
}
