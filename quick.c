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


int particiona(int *vet, int ini, int final){
	
  int pivo = vet[ini], i = ini, k, aux;

	for(k = ini+1; k <= final; k++)
  {
    if(vet[k] >= pivo)
    {
	    i++;
	    aux = vet[i]; 
	    vet[i] = vet[k]; 
	    vet[k] = aux; 
	  }
	}

	aux = vet[i]; 
	vet[i] = vet[ini]; 
	vet[ini] = aux;

	return i;
}

void quickSort(int *vet, int ini, int final){

  int meio;   

  if (ini < final){                  
    meio = particiona(vet, ini, final);
    quickSort(vet, ini, meio-1);    
    quickSort(vet, meio+1, final);
  }
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

    clock_t ponto[4];
    double tempo;

    lerVet(vetA, vetB, vetC, vetD);

    ponto[2] = clock();

    ponto[0] = clock();
    quickSort(vetA, 0, 4999);
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor A\n", tempo);

    ponto[0] = clock();
    quickSort(vetB, 0, 9999);
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor B\n", tempo);

    ponto[0] = clock();
    quickSort(vetC, 0, 19999);
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor C\n", tempo);

    ponto[0] = clock();
    quickSort(vetD, 0, 29999);
    ponto[1] = clock();
    tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
    printf("Foi gasto %g s para ordenar vetor D\n", tempo);


    escreverVetOrdenado(vetA, vetB, vetC, vetD);

    return 0;

}