#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
	int info;
	int bal;
	struct NO *esquerda, *direita;
}no, *arvore;

arvore aux= NULL;

void inserir(arvore *p, int chave)
{
	if(*p == NULL)
	{
		*p = (arvore)malloc(sizeof(no));
		(*p)->info = chave;
		(*p)->esquerda = NULL;
		(*p)->direita = NULL;
	}
	else if((*p)->info < chave)
	{
		inserir(&(*p)->direita,chave);
	}
	else
	{
		inserir(&(*p)->esquerda,chave);
	}
}

void exibir(arvore v, int nivel)
{
	int contador;
	
	if(v != NULL)
	{
		exibir(v->esquerda, nivel+1);
		for(contador=0; contador<nivel; contador++)
		{
			printf(" ");
		}
		printf("%d\n", v->info);
		exibir(v->direita, nivel+1);
	}
	return;
}

void pre_ordem(no * arvore)
{
	if(arvore == NULL)
	{
		return;
	}
	
	printf(" %d", arvore->info);
	pre_ordem(arvore->esquerda);
	pre_ordem(arvore->direita);
	
	return;
}

void pos_ordem(no * arvore)
{
	if(arvore == NULL)
	{
		return;
	}
	
	pos_ordem(arvore->esquerda);
	pos_ordem(arvore->direita);
	printf(" %d", arvore->info);
	
	return;
}

void ordem(no * arvore)
{
	if(arvore == NULL)
	{
		return;
	}
	
	ordem(arvore->esquerda);
	printf(" %d", arvore->info);
	ordem(arvore->direita);
	
	return;	
}

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
	int x,y,opcao;
	
	do
	{
		printf("\n-----Realize uma das Operações------");
		printf("\n1: Inserir item");
		printf("\n2: Exibir Arvore");
		printf("\n3: Sair\n");
		printf("\n DIGITE O NUMERO DA OPERAÇÂO:");
		fflush(stdin);
		scanf("%d", &opcao);
		switch(opcao) 
		{
			case 1:
				{
					printf("Informe o valor que deseja inserir: ");
					scanf("%d", &x);
					inserir(&aux, x);
					exibir(aux, 0);
					break;
				}
			
			case 2:
				{
					printf("\n Ordem: ");
					ordem(aux);
					printf("\n Pré Ordem: ");
					pre_ordem(aux);
					printf("\n Pós Ordem: ");
					pos_ordem(aux);
					break;
				}	
		}
	}while(opcao !=4);
}

