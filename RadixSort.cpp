#include<iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std; 

#define TAM_VETOR 500

// Função para obter o valor máximo 
int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

// Função para fazer a contagem de acordo com o dígito representado (exp)

void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; // matriz de saída
	int i, count[10] = {0}; 

	// armazenar contagem
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 

	// Contagem de alterações para posição real na saída
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1];

	// Contrução da saída
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 

	// Copiar a saída com os números classificados
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

// Radix Sort 
void radixsort(int arr[], int n) 
{ 
	// Encontrar o número máximo para saber o número de dígitos
	int m = getMax(arr, n); 

	// Contagem para cada dígito 
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 

// Função para imprimir uma matriz
void print(int arr[], int n) 
{ 
	printf("Numeros ordenados: ");
	
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Função para testar as funções acima
int main() 
{ 
	int arr[TAM_VETOR];
	int v;
	
	printf("Numeros aleatorios gerados: ");
	
	for(int v = 0; v < TAM_VETOR; v++)
	{
		arr[v] = rand() % TAM_VETOR;
		printf("%d ", arr[v]);
	}
	
	printf("\n\n");
	
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	radixsort(arr, n); 
	
	print(arr, n); 
	
	return 0;
}
