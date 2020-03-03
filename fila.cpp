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
void iniciar_Fila(no *FILA);
void opcao(no *FILA, int op);
void Mostrar_Fila(no *FILA);
void Liberar_Memoria(no *FILA);
no *Alocar_Memoria();
void inserir(no *FILA);
no *retirar(no *FILA);

int main (void)
{
	setlocale(LC_ALL,"Portuguese");
	
	no *FILA = (no *) malloc(sizeof(no));
	if(!FILA){
		printf("\nSEM MEMORIA DISPONIVEL\n");
		exit(1);	
	}else{
		iniciar_Fila(FILA);
		int opt;
	do{
		opt=menu();
		opcao(FILA,opt);
	}while(opt)	;
	
	free(FILA);
	return 0;
	}
}

void iniciar_Fila(no *FILA){
	FILA->proximo = NULL;
	TAMANHO=0;
}


int menu(void)
{
 int opt;

 printf("<================Escolha a opcão=====================>\n");
 printf("0. Sair\n");
 printf("1. Zerar FILA\n");
 printf("2. Exibir FILA\n");
 printf("3. Inserir No\n");
 printf("4. Retirar No\n");
 printf("\nOpcão: "); scanf("%d", &opt);

 return opt;
}

void opcao(no *FILA, int op){
	no *aux;
	switch(op){
		case 0:
			Liberar_Memoria(FILA);
			break;
		
		case 1:
			Liberar_Memoria(FILA);
			iniciar_Fila(FILA);
			break;
			
		case 2:
			Mostrar_Fila(FILA);
			break;
			
		case 3:
			inserir(FILA);
	        break;
	    
		case 4:
			aux = retirar(FILA);
        	if(aux != NULL)
		    printf("Retirado: %3d\n\n", aux->valor);
		    break;

       default:
            printf("Comando invalido\n\n");			
	}
}

int vazia(no *FILA){
	if(FILA->proximo == NULL)
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


void Mostrar_Fila(no *FILA)
{
	if(vazia(FILA)){
		printf("Fila vazia!\n\n");
		return ;
	}

	no *aux;
	aux = FILA->proximo;
	printf("Fila :");
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

void Liberar_Memoria(no *FILA)
{
	if(!vazia(FILA)){
		no *ProxNo,
			*atual;
	atual = FILA->proximo;
	while(atual != NULL){
		ProxNo = atual->proximo;
		free(atual)		;
		atual = ProxNo;
	}
 }
}

void inserir(no *FILA){
	no *NovoNo = Alocar_Memoria();
	NovoNo->proximo = NULL;
	
	if(vazia(FILA)){
		FILA->proximo = NovoNo;
	}else{
		no *aux = FILA->proximo;
		
		while(aux->proximo != NULL)
		 aux = aux->proximo;
		
		aux->proximo = NovoNo; 
	}
	TAMANHO++;
}

no *retirar(no *FILA)
{
	if(FILA->proximo == NULL){
		printf("FILA VAZIA!\n\n");
		return NULL;
	}else{
		no *aux = FILA->proximo;
		FILA->proximo = aux->proximo;
		TAMANHO--;
		return aux;
	}
}

