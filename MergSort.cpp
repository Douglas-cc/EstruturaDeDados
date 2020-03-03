#include <stdio.h>
#include <stdlib.h>

void intercalar(int vetor[], int inicio, int meio, int fim)
{
	int i,m,f,*auxiliar;
	auxiliar =(int*) calloc(sizeof(int),fim-inicio+1);
	
	i = inicio;
	m = meio+1;
	f=0;
	
	while(i<=meio && m<=fim)
	{
		if(vetor[i] <= vetor[m])
		{
			auxiliar[f] = vetor[i];
			i++;
		}else{
			auxiliar[f] = vetor[m];
			m++;
		}
		f++;
	}
	
	while(i<=meio)
	{
		auxiliar[f] = vetor[i];
		i++;
		f++;
	}
	
	while(m<=fim)
	{
		auxiliar[f] = vetor[m];
		m++;
		f++;
	}
	
	for(i=0;i<(fim-inicio)+1;i++)
	{
		vetor[inicio+i] = auxiliar[i];
	}
	
	free(auxiliar);
	return;
}

void MergSort(int vetor[], int inicio, int fim)
{
	int meio;
	if(inicio<fim)
	{
		meio=(inicio+fim)/2;
		MergSort(vetor,inicio,meio);
		MergSort(vetor,meio+1,fim);
		intercalar(vetor,inicio,meio,fim);
	}
	return;
}

int main(void)
{
	int vetor[] = {3,5,8,1,9,2,4,7,0,6};
	int n = 10;
	
	MergSort(vetor,0,n);

	printf("Ordenado: ");

	for(int i = 0; i < n; i++)
	{
		printf("%d", vetor[i]);	
	}
	
	printf("\n");
	return 0;
}
