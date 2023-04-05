#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>



int main () {

    clock_t t;
    srand(time(NULL));
    FILE *A, *B, *C, *D;

    A = fopen("A.txt", "a");
    B = fopen("B.txt", "a");
    C = fopen("C.txt", "a");
    D = fopen("D.txt", "a");


    int vetA[5000], vetB[10000], vetC[20000], vetD[30000];

    for (int i = 0; i < 5000; i++)
    {
        vetA[i] = 1 + ( rand() % 10000);
        fprintf(A, "%d\n",vetA[i]);
    }

    for (int i = 0; i < 10000; i++)
    {
        vetB[i] = 1 + ( rand() % 10000);
        fprintf(B, "%d\n",vetB[i]);
    }

    for (int i = 0; i < 20000; i++)
    {
        vetC[i] = 1 + ( rand() % 10000);
        fprintf(C, "%d\n",vetC[i]);
    }

    for (int i = 0; i < 30000; i++)
    {
        vetD[i] = 1 + ( rand() % 10000);
        fprintf(D, "%d\n",vetD[i]);
    }
    
    fclose(A);
    fclose(B);
    fclose(C);
    fclose(D);

    t = clock();
    t = clock() - t;

    printf("Tempo de execução foi de: %ld s \n", t);

    return 0;
}