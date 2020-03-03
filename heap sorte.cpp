#include <stdio.h>
#include <stdlib.h>

void construir(int *p_vetor, int tamanho, int indice_Raiz) //seleção do Heap Maxímo 
{
	int ramificacao, valor;
	valor = p_vetor[ indice_Raiz];
	
	while(indice_Raiz <= tamanho/2){
		ramificacao = 2 * indice_Raiz;
		
		if (ramificacao < tamanho && p_vetor[ramificacao] < p_vetor[ ramificacao + 1 ] )
			ramificacao++;
		if (valor >= p_vetor[ramificacao])
			break;
		p_vetor[ indice_Raiz]	= p_vetor[ramificacao];
		indice_Raiz = ramificacao;
	}
	p_vetor[ indice_Raiz] = valor;
}

void HeapSort (int *p_vetor, int tamanho) //ordenação 
{
	int indice, troca;
	for(indice = tamanho/2; indice >= 0; indice--)	
		construir(p_vetor, tamanho, indice);
	
	while(tamanho > 0)	
	{
		troca = p_vetor[0];
		p_vetor[0] = p_vetor[tamanho];
		p_vetor[tamanho] = troca;
		construir(p_vetor, --tamanho, 0);
	}
}

int main(int argc, char *argv[]){
	int vetor[] = {23, 32, 65, 7, 8, 98, 123, 34, 92, 54, 33, 45};
	int tamanho = 12;
	int indice;

	HeapSort(vetor, tamanho);
	
	for (indice=0 ;indice <= tamanho-1 ;indice++){
		printf("O valor do indice %d ordenado e: %d \n", indice, vetor[indice]);
 	}
 	
	 system("PAUSE");
	 return 0;
}
