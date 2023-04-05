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

void merge(int *vet, int ini, int meio, int final){

	int *temp, taman, ini1, ini2;

	taman = final - ini + 1;
	ini1 = ini;
	ini2 = meio + 1;
	
	temp = (int *) malloc(taman*sizeof(int));

	for(int i = 0; i < taman; i++)
  {

    if((ini1 <= meio) && (ini2 <= final))
    {

      if(vet[ini1] > vet[ini2])
      {
          temp[i] = vet[ini1++];
      }
      else
      {
        temp[i] = vet[ini2++];
      }

    }
    else
    {
      if(ini1 <= meio)
      {
        temp[i] = vet[ini1++];
      }
        
      else
      {
        temp[i] = vet[ini2++];
      }
    }
	}

	for(int i = 0, j = ini; i < taman; i++, j++)
  {
		vet[j] = temp[i];
	}

	free(temp);
}
void mergeSort(int *vet, int ini, int final){

  int meio;                      

  if (ini < final) {                  

    meio = (ini+final)/2;
    mergeSort(vet, ini, meio);      
    mergeSort(vet, meio+1, final);
    merge(vet, ini, meio, final);   

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
  mergeSort(vetA, 0, 4999);
  ponto[1] = clock();
  tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
  printf("Foi gasto %g s para ordenar vetor A\n", tempo);

  ponto[0] = clock();
  mergeSort(vetB, 0, 9999);
  ponto[1] = clock();
  tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
  printf("Foi gasto %g s para ordenar vetor B\n", tempo);

  ponto[0] = clock();
  mergeSort(vetC, 0, 19999);
  ponto[1] = clock();
  tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
  printf("Foi gasto %g s para ordenar vetor C\n", tempo);

  ponto[0] = clock();
  mergeSort(vetD, 0, 29999);
  ponto[1] = clock();
  tempo = ((ponto[1] - ponto[0]) * 1000.0 / CLOCKS_PER_SEC) / 1000.0;
  printf("Foi gasto %g s para ordenar vetor D\n", tempo);

  escreverVetOrdenado(vetA, vetB, vetC, vetD);
  
  return 0;

}