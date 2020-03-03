#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define TAM 20

int main()
{
	int arr[TAM];
	srand((unsigned)time(NULL));
	
	printf("Gerando numeros aleatorios...");
	
	printf("\n\n");
	
	for(int v = 0; v < TAM; v++)
	{
		arr[v] = rand() % TAM;
	}
	
	printf("Numeros aleatorios gerados: ");
	
	for(int v = 0; v < TAM; v++)
	{
		printf("%d: %d", v, arr[v]);
	}
	
	return 0;
}
