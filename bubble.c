#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


void lerVet(int vetA[], int vetB[], int vetC[], int vetD[]){

  FILE *arq;

  arq = fopen("A.txt", "r");

    for(int i = 0; i < 5000; i++)
    {
      fscanf(arq, "%d", &vetA[i]);
    }
    fclose(arq);

    arq = fopen("B.txt", "r");

    for(int i = 0; i < 10000; i++)
    {
      fscanf(arq, "%d", &vetB[i]);
    }
    fclose(arq);

    arq = fopen("C.txt", "r");

    for(int i = 0; i < 20000; i++)
    {
      fscanf(arq, "%d", &vetC[i]);
    }
    fclose(arq);

    arq = fopen("D.txt", "r");

    for(int i = 0; i < 30000; i++)
    {
      fscanf(arq, "%d", &vetD[i]);
    }
    fclose(arq);

}

void bubbleSort(int vetA[], int vetB[], int vetC[], int vetD[]){

    int aux;
    clock_t ponto[2];
    double tempo;

    ponto[0] = clock();
    for(int i = 0; i < 5000; i++)
    {
        for(int j = 0; j < 4999; j++)
        {
            if(vetA[j] < vetA[j+1])
            {
                aux = vetA[j];
                vetA[j] = vetA[j+1];
                vetA[j+1] = aux;
            }
        
        }
    
    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor A\n", tempo);


    ponto[0] = clock();
    for(int i = 0; i < 10000; i++)
    {
        for(int j = 0; j < 9999; j++)
        {
            if(vetB[j] < vetB[j+1])
            {
                aux = vetB[j];
                vetB[j] = vetB[j+1];
                vetB[j+1] = aux;
            }
        
        }
    
    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor B\n", tempo);


    ponto[0] = clock();
    for(int i = 0; i < 20000; i++)
    {
        for(int j = 0; j < 19999; j++)
        {
            if(vetC[j] < vetC[j+1])
            {
                aux = vetC[j];
                vetC[j] = vetC[j+1];
                vetC[j+1] = aux;
            }
        
        }
    
    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor C\n", tempo);


    ponto[0] = clock();
    for(int i = 0; i < 30000; i++)
    {
        for(int j = 0; j < 29999; j++)
        {
            if(vetD[j] < vetD[j+1])
            {
                aux = vetD[j];
                vetD[j] = vetD[j+1];
                vetD[j+1] = aux;
            }
        }
    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor D\n", tempo);

}


void escreverVetOrdenado(int vetA[], int vetB[], int vetC[], int vetD[]){
    FILE *arq;

    arq = fopen("Ordenado-A.txt", "w");

    for(int i = 0; i < 5000; i++)
    {
        fprintf(arq, "%d\n", vetA[i]);
    }
    fclose(arq);

    arq = fopen("Ordenado-B.txt", "w");

    for(int i = 0; i < 10000; i++)
    {
        fprintf(arq, "%d\n", vetB[i]);
    }
    fclose(arq);

    arq = fopen("Ordenado-C.txt", "w");

    for(int i = 0; i < 20000; i++)
    {
        fprintf(arq, "%d\n", vetC[i]);
    }
    fclose(arq);

    arq = fopen("Ordenado-D.txt", "w");

    for(int i = 0; i < 30000; i++)
    {
        fprintf(arq, "%d\n", vetD[i]);
    }
    fclose(arq);
}

int main (){

    int vetA[5000], vetB[10000], vetC[20000], vetD[30000];

    lerVet(vetA, vetB, vetC, vetD);

    bubbleSort(vetA, vetB, vetC, vetD);

    escreverVetOrdenado(vetA, vetB, vetC, vetD);

    return 0;

}