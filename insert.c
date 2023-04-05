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

void insertionSort(int vetA[], int vetB[], int vetC[], int vetD[]){
    int valor, k;
    clock_t ponto[2];
    double tempo;

    ponto[0] = clock();
    for(int i = 1; i < 5000; i++)
    {
      valor = vetA[i];

      for(k = i-1; k >= 0 && valor > vetA[k]; k--)
      {
        vetA[k+1] = vetA[k];
      }
      vetA[k+1] = valor;
    
    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor A\n", tempo);


    ponto[0] = clock();
    for(int i = 1; i < 10000; i++)
    {
      valor = vetB[i];
      
      for(k = i-1; k >= 0 && valor > vetB[k]; k--)
      {
        vetB[k+1] = vetB[k];
      }
      vetB[k+1] = valor;
    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor B\n", tempo);


    ponto[0] = clock();
    for(int i = 1; i < 20000; i++)
    {
      valor = vetC[i];
      
      for(k = i-1; k >= 0 && valor > vetC[k]; k--)
      {
        vetC[k+1] = vetC[k];
      }
      vetC[k+1] = valor;
    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor C\n", tempo);


    ponto[0] = clock();
    for(int i = 1; i < 30000; i++)
    {
      valor = vetD[i];

      for(k = i-1; k >= 0 && valor > vetD[k]; k--)
      {
        vetD[k+1] = vetD[k];
      }
      vetD[k+1] = valor;
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

    insertionSort(vetA, vetB, vetC, vetD);

    escreverVetOrdenado(vetA, vetB, vetC, vetD);

    return 0;

}