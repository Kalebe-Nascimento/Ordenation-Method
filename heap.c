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

void heap(int vetAux[], int n, int i) {

    int auxiliar, menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if(esquerda < n && vetAux[esquerda] < vetAux[menor])
	{
        menor = esquerda;
    }

    if(direita < n && vetAux[direita] < vetAux[menor])
	{
        menor = direita;
    }

    if (menor != i)
	{
    auxiliar = vetAux[menor];
    vetAux[menor] = vetAux[i];
    vetAux[i] = auxiliar;

    heap(vetAux, n, menor);
  }

}
void heapSort(int vetA[], int vetB[], int vetC[], int vetD[]){
    
	int auxiliar;
    clock_t ponto[2];
    double tempo;

    ponto[0] = clock();
    for (int i = 5000 / 2 - 1; i >= 0; i--)
	{
        heap(vetA, 5000, i);
    }

    for (int i = 4999; i >= 0; i--) 
	{
		auxiliar = vetA[0];
		vetA[0] = vetA[i];
		vetA[i] = auxiliar;
		heap(vetA, i, 0);

	}
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor A\n", tempo);


    ponto[0] = clock();
    for (int i = 10000 / 2 - 1; i >= 0; i--)
	{
        heap(vetB, 10000, i);
    }
    
    for (int i = 9999; i >= 0; i--)
	{
		auxiliar = vetB[0];
		vetB[0] = vetB[i];
		vetB[i] = auxiliar;
		heap(vetB, i, 0);

    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor B\n", tempo);


    ponto[0] = clock();
    for (int i = 20000 / 2 - 1; i >= 0; i--)
	{
        heap(vetC, 20000, i);
    }

    for (int i = 19999; i >= 0; i--) 
	{
		auxiliar = vetC[0];
		vetC[0] = vetC[i];
		vetC[i] = auxiliar;
		heap(vetC, i, 0);

    }
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor C\n", tempo);


    ponto[0] = clock();
    for (int i = 30000 / 2 - 1; i >= 0; i--)
	{
        heap(vetD, 30000, i);
    }

    for (int i = 29999; i >= 0; i--) 
	{
		auxiliar = vetD[0];
		vetD[0] = vetD[i];
		vetD[i] = auxiliar;
		heap(vetD, i, 0);
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

    heapSort(vetA, vetB, vetC, vetD);

    escreverVetOrdenado(vetA, vetB, vetC, vetD);

    return 0;

}