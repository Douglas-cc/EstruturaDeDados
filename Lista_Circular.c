#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No
{
    int valor;
    struct No *proximo;
    struct No *p;
}No;

int tamanho_lista(No *cabeca){
	int t=0;
	No *atual = cabeca->proximo;
    if(cabeca->proximo == NULL)
        return 0;
    else
    {
        do
        {
            t++;
            atual = atual->proximo;
        }while(atual != cabeca->proximo);
        return t;
    }
}

void listar(No *cabeca)
{
    No *atual = cabeca->proximo;

    if(atual == NULL)
        printf("LISTA VAZIA");
    else
    {
        do
        {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }while(atual != cabeca->proximo);
    }
}

void listar_pos(No *cabeca)
{
    No *atual;
    No *save_cabeca = cabeca->proximo;
    int c=0, pos;

    printf("\nLista atual\n");
    listar(cabeca);

    if(cabeca->proximo != NULL)
    {
        do
        {
            printf("\nInforme a posição [0 a %d]: ", tamanho_lista(cabeca)-1);
            scanf("%d", &pos);

            if(pos>tamanho_lista(cabeca)-1)
                printf("\nPosição Inválida.\n");

        }while(pos>tamanho_lista(cabeca)-1);

        if(pos == 0)
            listar(cabeca);
        else
        {
            atual = cabeca->proximo;
            do
            {
                if(c == pos)
                {
                    cabeca->proximo = atual;
                    break;
                }
                atual = atual->proximo;
                c++;
            }while(atual != cabeca->proximo);
        printf("\nLista a partir da posição: %d\n", pos);
        listar(cabeca);
        cabeca->proximo = save_cabeca;
        }
    }
    printf("\n");
    system("pause");
}

void inserir_inicio(No *cabeca)
{
    No *atual, *anterior;
    No *novo = (No*) malloc(sizeof(No));    //passo 1: alocar o novo nó na memória do computador

    novo->proximo = cabeca->proximo;       //passo 2: apontar o novo nó para onde a cabeça aponta
    cabeca->proximo = novo;                // passo 3: apontar a cabeça para o novo nó
    if(novo->proximo == NULL)
        novo->proximo = novo;
    else
    {
        atual = cabeca->proximo;
        do
        {
            anterior = atual;
            atual = atual->proximo;
            if(atual->proximo == novo->proximo)
            {
                atual->proximo = cabeca->proximo;
                break;
            }
        }while(atual != cabeca->proximo);
    }
    printf("\nInforme um valor para inseri-lo na lista: ");
    scanf("%d", &novo->valor);         //passo 4: inserir um valor no novo nó
}

void inserir_final(No *cabeca)
{
    No *novo = (No*) malloc(sizeof(No));
    No *temp = cabeca->proximo;

    if(temp == NULL)
        inserir_inicio(cabeca);
    else
    {
        do
            temp = temp->proximo;
        while(temp->proximo != cabeca->proximo);
        novo->proximo = cabeca->proximo;
        temp->proximo = novo;
        printf("\nInfrome um valor para inseri-lo na lista: ");
        scanf("%d", &novo->valor);
    }
}

void inserir_pos(No *cabeca)
{
    int pos, c;
    No *atual;
    No *anterior;
    No *novo = (No*)malloc(sizeof(No));

    printf("\nLista atual\n");
    listar(cabeca);
    do
    {
        printf("Informe a posição [0 a %d]: ", tamanho_lista(cabeca));
        scanf("%d", &pos);

        if(pos>tamanho_lista(cabeca))
            printf("\nPosição Inválida.\n");

    }while(pos>tamanho_lista(cabeca));

    if(pos == 0)
        inserir_inicio(cabeca);
    else if((pos>0) && (pos<tamanho_lista(cabeca)))
    {
        atual = cabeca->proximo;
        c = 1;

        do
        {
            anterior = atual;
            atual = atual->proximo;
            if(c == pos)
            {
                novo->proximo = atual;
                anterior->proximo = novo;
                break;
            }
            c++;
        }while(atual != cabeca->proximo);

        printf("Informe um valor para inseri-lo na lista: ");
        scanf("%d", &novo->valor);
    }
    else
        inserir_final(cabeca);
    printf("\nNova lista\n");
    listar(cabeca);
    printf("\n");
    system("pause");
}

void excluir_item(No *cabeca)
{
    int pos, c;
    No *atual = cabeca->proximo;
    No *anterior;

    if(cabeca->proximo == NULL)
        listar(cabeca);
    else
    {
        printf("Lista atual\n");
        listar(cabeca);

        do
        {
            printf("\nInforme a posição [0 a %d]: ", tamanho_lista(cabeca)-1);
            scanf("%d", &pos);
            if(pos>=tamanho_lista(cabeca))
                printf("\nPosição inválida.\n");
        }while(pos>=tamanho_lista(cabeca));

        if((pos == 0) && (tamanho_lista(cabeca) == 1))
            cabeca->proximo = NULL;
        else if((pos == 0) && (tamanho_lista(cabeca) > 1))
        {
            cabeca->proximo = atual->proximo;
            atual = atual->proximo;
            do
            {
                anterior = atual;
                atual = atual->proximo;
                if(atual->proximo == cabeca->proximo)
                {
                    anterior->proximo = cabeca->proximo;
                    break;
                }
            }while(atual != cabeca->proximo);
        }
        else if((pos>0) && (pos<tamanho_lista(cabeca)-1))
        {
            c = 1;

            do
            {
                anterior = atual;
                atual = atual->proximo;
                if(c == pos)
                {
                    anterior->proximo = atual->proximo;
                    break;
                }
                c++;
            }while(atual != cabeca->proximo);
        }
        else
        {

            c = 1;

            do
            {
                anterior = atual;
                atual = atual->proximo;
                if(c == pos)
                {
                    anterior->proximo = cabeca->proximo;
                    break;
                }
                c++;
            }while(atual != cabeca->proximo);
        }
        printf("\nNova lista\n");
        listar(cabeca);
        printf("\n");
        system("pause");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
	int opt;
	No *cabeca = (No*) malloc(sizeof(No));

	cabeca->proximo = NULL;

	do
    {
        system("cls");
        //pequeno menu de opções
        printf("0. SAIR\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Inserir em  uma posição\n");
        printf("4. Listar tudo\n");
        printf("5. Excluir item\n");
        printf("6. Limpar\n");
        printf("7. Ver tamanho da lista\n");
        printf("8. Ver a lista a partir de uma posição\n");

        //pedir a opção
        printf("\nOpção: ");
        scanf("%d", &opt);

        printf("\n");
        //switch com as opções
        switch(opt)
        {
            case 0:
                break;
            case 1:
                printf("Lista atual\n");
                listar(cabeca);
                inserir_inicio(cabeca);
                printf("\nNova lista\n");
                listar(cabeca);
                printf("\n");
                system("pause");
                break;
            case 2:
                printf("Lista atual\n");
                listar(cabeca);
                inserir_final(cabeca);
                printf("\nNova lista\n");
                listar(cabeca);
                printf("\n");
                system("pause");
                break;
            case 3:
                inserir_pos(cabeca);
                break;
            case 4:
                listar(cabeca);
                printf("\n");
                system("pause");
                break;
            case 5:
                excluir_item(cabeca);
                break;
            case 6:
                cabeca->proximo = NULL;
                break;
            case 7:
                if(tamanho_lista(cabeca) == 0)
                    printf("\nLISTA VAZIA\n");
                else
                    printf("TAMANHO: %d\n", tamanho_lista(cabeca));
                system("pause");
                break;
            case 8:
                listar_pos(cabeca);
                break;
            default:
                printf("Opção inválida.\n");
                system("pause");
                break;
        }

    }while(opt!=0);

    getch();
    return 0;
}
