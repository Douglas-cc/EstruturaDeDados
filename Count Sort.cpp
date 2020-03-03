#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void CountSort(int *A, int n, int *B, int *C, int k)
{
	int i;
	
	//1ª - (Inicializar com zero)
	for(i=0; i<n; i++)
	{
		C[A[i]]++;
	}
	
	 //2ª - Contagem das ocorrencias
	for (i=1; i<k; i++)
	{
		C[i] += C[i-1];
	}
	
	 //3ª - Ordenando os indices do vetor auxiliar
	for (i= n-1; i>=0; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}

int main(){
	int i, tamanho, y, maior = 0;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%i", &tamanho);
	
	int vetA[tamanho], vetB[tamanho];
	srand(time(NULL));
	for(i = 0; i<tamanho; i++)
	{
		vetA[i] = rand()%1000;
	}
	
	for(i = 0; i<tamanho; i++)
	{
		if(vetA[i] > maior)
		maior = vetA[i];
	}
	
	int vetC[maior+1];
	for(i = 0; i < maior+1; i++)
	vetC[i] = 0;
	
	CountSort(vetA, tamanho, vetB, vetC, maior+1);
	
	printf("\n\nVetor Original:\n\n");
	
	for(i=1; i<tamanho;i++)
	{
		printf("%d ", vetA[i]);
	}
	
	printf("\n\nVetor Reorganizado:\n\n");
	
	for(i=1;i<tamanho;i++)
	{ 
		printf("%d ", vetB[i]);
	}
	
	getch();
}
