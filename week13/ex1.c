#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    char buff[100];
    int existingRes[3];
    int availableRes[3];
    int matrixAlloc[5][3];
    int matrixReq[5][3];
    int dlProcs[5];


    int dl = 0;
    int finished[5];
    int currSymb = 0;
    int canExecute[5];
    int changed = 1;

    FILE *input = fopen("input_dl.txt", "r");

    fgets(buff, 100, input);
    for (size_t i = 0; i < 3; i++) {
        existingRes[i] = (int)(buff[currSymb] - '0');
        currSymb += 2;
    }

    currSymb = 0;
    fgets(buff, 100, input);
    fgets(buff, 100, input);

    fgets(buff, 100, input);
    for (size_t i = 0; i < 3; i++) {
        availableRes[i] = (int)(buff[currSymb] - '0');
        currSymb += 2;
    }

    currSymb = 0;
    fgets(buff, 100, input);
    fgets(buff, 100, input);

    fgets(buff, 100, input);
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 3; j++) {
            matrixAlloc[i][j] = (int)(buff[currSymb] - '0');
            currSymb += 2;
        }

        currSymb = 0;
        fgets(buff, 100, input);
    }

    currSymb = 0;

    fgets(buff, 100, input);
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 3; j++) {
            matrixReq[i][j] = (int)(buff[currSymb] - '0');
            currSymb += 2;
        }

        currSymb = 0;
        fgets(buff, 100, input);
    }
    fclose(input);

    for (size_t i = 0; i < 5; i++) {
        dlProcs[i] = 0;
        canExecute[i] = 1;
        finished[i] = 0;
    }

    while (changed) {
        changed = 0;
        for (size_t i = 0; i < 5; i++) {
            canExecute[i] = 1;
            for (size_t j = 0; j < 3; j++) {
                if (matrixReq[i][j] > availableRes[j]) {
                    canExecute[i] = 0;
                    break;
                }
            }
        }

        for (size_t i = 0; i < 5; i++) {
            if (canExecute[i] && finished[i] == 0) {
                for (size_t j = 0; j < 3; j++) {
                    availableRes[j] += matrixAlloc[i][j];
                    matrixAlloc[i][j] = 0;
                    matrixReq[i][j] = 0;
                    changed = 1;
                    finished[i] = 1;
                }
            }
        }
    }

    for (size_t i = 0; i < 5; i++) {
        if (finished[i] == 0) {
            dlProcs[i] = 1;
            dl = 1;
        }
    }
    
    FILE *output = fopen("output_dl.txt", "w");

    if (dl) {
        for (size_t i = 0; i < 5; i++) {
            if (dlProcs[i]) {
                fprintf(output, "Process %ld is in a dl\n", i+1);
            }
        }
        fprintf(output, "(Counting from 1 to %d)", 5);
    } else {
        fprintf(output, "No dls found");
    }

    fclose(output);

    return 0;
}
