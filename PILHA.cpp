#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct No{
	int valor;
	struct No *proximo;
};

typedef struct No no; 
int TAMANHO;

int menu(void);
void iniciar_Pilha(no *PILHA);
void opcao(no *PILHA, int op);
void Mostrar_Pilha(no *PILHA);
void Liberar_Memoria(no *PILHA);
void Empilhar(no *PILHA);
no *Desempilhar(no *PILHA);

int main (void)
{
	setlocale(LC_ALL,"Portuguese");
	
	no *PILHA = (no *) malloc(sizeof(no));
	if(!PILHA){
		printf("\nSEM MEMORIA DISPONIVEL\n");
		exit(1);	
	}else{
		iniciar_Pilha(PILHA);
		int opt;
	do{
		opt=menu();
		opcao(PILHA,opt);
	}while(opt)	;
	
	free(PILHA);
	return 0;
	}
}

void iniciar_Pilha(no *PILHA){
	PILHA->proximo = NULL;
	TAMANHO=0;
}

int menu(void)
{
 int opt;

 printf("<================Escolha a opcão=====================>\n");
 printf("0. Sair\n");
 printf("1. Zerar PILHA\n");
 printf("2. Exibir PILHA\n");
 printf("3. Empilhar\n");
 printf("4. Desempilhar\n");
 printf("\nOpcão: "); scanf("%d", &opt);

 return opt;
}

void opcao(no *PILHA, int op){
	no *aux;
	switch(op){
		case 0:
			Liberar_Memoria(PILHA);
			break;
		
		case 1:
			Liberar_Memoria(PILHA);
			iniciar_Pilha(PILHA);
			break;
			
		case 2:
			Mostrar_Pilha(PILHA);
			break;
			
		case 3:
			Empilhar(PILHA);
	        break;
	    
		case 4:
			aux = Desempilhar(PILHA);
        	if(aux != NULL)
		    printf("Retirado: %3d\n\n", aux->valor);
		    break;

       default:
            printf("Comando invalido\n\n");			
	}
}
	
int vazia(no *PILHA){
	if(PILHA->proximo == NULL)
		return 1;
	else
		return 0;
}

no *Alocar_Memoria()
{
	no *NovoNo = (no*) malloc(sizeof(no));
	if(!NovoNo){
		printf("\n<MOMORIA INDISPONIVEL>\n");
		exit(1);
	}else{
		printf("Novo elemento: "); scanf("%d", &NovoNo->valor);
		return NovoNo;
	}
}

void Mostrar_Pilha(no *PILHA)
{
 if(vazia(PILHA)){
  printf("PILHA vazia!\n\n");
  return ;
 }

 no *aux;
 aux = PILHA->proximo;
 printf("PILHA:");
 
 while( aux != NULL){
  printf("%5d", aux->valor);
  aux = aux->proximo;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < TAMANHO ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < TAMANHO ; count++)
  printf("%5d", count+1);


 printf("\n\n");
}


void Liberar_Memoria(no *PILHA)
{
	if(!vazia(PILHA)){
		no *ProxNo,
			*atual;
	atual = PILHA->proximo;
	while(atual != NULL){
	ProxNo = atual->proximo;
	free(atual)		;
	atual = ProxNo;
	}
 }
}

void Empilhar(no *PILHA){
	no *NovoNo = Alocar_Memoria();
	NovoNo->proximo = NULL;
	
	if(vazia(PILHA)){
		PILHA->proximo = NovoNo;
	}else{
		no *aux = PILHA->proximo;
		
		while(aux->proximo != NULL)
		 aux = aux->proximo;
		
		aux->proximo = NovoNo; 
	}
	TAMANHO++;
}

no *Desempilhar(no *PILHA)
{
	if(PILHA->proximo == NULL){
		printf("PILHA VAZIA!\n\n");
		return NULL;
	}else{
		no *ultimo = PILHA->proximo,
		         *penultimo = PILHA;
	
	while(ultimo->proximo != NULL){
	 penultimo = ultimo;
	 ultimo = ultimo->proximo;
	}
	
	penultimo->proximo = NULL;
	TAMANHO--;
	return ultimo;
	}
}

