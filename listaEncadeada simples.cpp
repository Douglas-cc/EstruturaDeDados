#include <stdio.h>
#include <stdlib.h>


typedef struct No{
	int valor;
	struct No *proximo;
}No;

void listar(No *cabeca){
	No *atual = cabeca;
	while(atual != NULL){
		printf("%d -> ", atual->valor);
		atual = atual->proximo;
	}
}

int vazia(No *lista){
	if(lista->proximo == NULL)
		return 1;
	else
		return 0;
}

No* inserir(No *cabeca, int valor){
	No *novo = (No*) malloc(sizeof(No));
	novo->valor = valor;
	novo->proximo = cabeca;

	return novo;
}

No* retirar(No *cabeca){
	if(vazia(cabeca)){
		printf("Lista vazia!!!\n");
	}else{
		No *aux = cabeca;
		No *novaCabeca = (No*) malloc(sizeof(No));
		while(aux->proximo != NULL){
		novaCabeca->valor = aux->valor;
			novaCabeca->proximo = aux->proximo;
			aux = aux->proximo;
			
		}
		
		return novaCabeca;
	}
	
}

No* insereFim(No *cabeca){
    No *novo = (No*) malloc(sizeof(No));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    printf("Novo elemento: "); scanf("%d", &novo->valor);
    novo->proximo = NULL;

    if(vazia(cabeca)){
        cabeca->proximo=novo;
    }else{
        No *aux = cabeca->proximo;

        while(aux->proximo != NULL)
			aux = aux->proximo;
			    
        aux->proximo = novo;
    }
	return novo;
}

void zerar(No *cabeca){
	if(vazia(cabeca)){
		printf("LISTA JÁ ZERADA!");
	}else{
			
	while(aux->proximo != NULL){
        proximo = NULL;
		aux = aux->proximo;
		printf("lista zerada!!!");
	}
			
}

void retiraFim(No *cabeca){
 
    if(vazia(cabeca)){
        printf("Lista vazia!!!\n");
    }else{
        No *aux = cabeca->proximo,
        		*penultimo = cabeca;

        while(aux->proximo != NULL){
        	penultimo = aux;
			aux = aux->proximo;
		
		} 
        penultimo->proximo = NULL;
    }
}

int main(int argc, char **argv){
	int opt, valor;
	
	No *cabeca = NULL;
	do{	
		printf("\n\n");
		printf("0. Sair\n");
		printf("1. Listar\n");
		printf("2. Inserir no do Inicio\n");
		printf("3. Inserir no do Fim \n");
		printf("4. Exclui no do FIM\n");
		printf("5. Excluir no do INICIO\n");
		printf("6.ZERAR");
		printf("\nEscolha a opcao: "); scanf ("%d", &opt);

		switch(opt){
			case 0:
					break;
			case 1:
					listar(cabeca);
					break;
			case 2:
					printf("Informe um valor:");
					scanf("%d", &valor);
					cabeca = inserir(cabeca, valor);
					break;
            case 3:
                    insereFim(cabeca);
                    break;

            case 4:
					retiraFim(cabeca);
					break;
			case 5: 
					cabeca = retirar(cabeca);					
					break;
			case 6:
					zerar(cabeca);
					break;
			default:
					printf("Opcao invalida");
					break;
	}
	}while(opt != 0);

	return 0;
}
