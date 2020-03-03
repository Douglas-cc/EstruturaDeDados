#include <stdio.h>
#include <stdlib.h>

int dividir(int vetor[] , int esquerda, int direita)
{
	int auxiliar;
	int contador = esquerda;
	
	for(int i = esquerda+1; i <= direita; i++)
	{
		if(vetor[i] < vetor[esquerda]) 
		{
			contador++;
			
			auxiliar = vetor[i];
			vetor[i] = vetor[contador];
			vetor[contador] = auxiliar;
		}
	}
	auxiliar = vetor[esquerda];
	vetor[esquerda] = vetor[contador];
	vetor[contador] = auxiliar;
	
	return contador;
}

void QuickSort (int vetor[], int esquerda, int direita)
{
	int pos;
	if (esquerda < direita)
	{
		pos = dividir(vetor, esquerda, direita);
		QuickSort(vetor, esquerda, pos-1);
		QuickSort(vetor, pos+1, direita);
	}
}

int main(void)
{
	int vetor[] = {3,5,8,1,9,2,4,7,0,6};
	int n = 10;
	
	QuickSort(vetor,0,n);

	printf("Ordenado: ");

	for(int i = 0; i < n; i++)
	{
		printf("%d", vetor[i]);	
	}
	
	printf("\n");
	return 0;
}

