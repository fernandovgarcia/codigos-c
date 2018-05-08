#include <stdio.h>
#include <stdlib.h>

struct no{
    struct no *anterior;
    int valor;
    struct no *proximo;
};

struct l_descr{
    struct no *inicio;
    int cnt;
    struct no *fim;
};

void inicializa_lista(struct l_descr *lista){
    lista->inicio=NULL;
    lista->cnt=0;
    lista->fim=NULL;
}

int esta_vazia(struct l_descr *lista){
    if(lista->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

void imprime_lista(struct l_descr *lista){
    struct no *aux = lista->inicio;
    while(aux != NULL){
        printf("valor: %d\n", aux->valor);
        aux = aux->proximo;
    }
}

void insere_lista_nula(struct l_descr *lista, int valor){
    lista->inicio = malloc(sizeof(struct no));
    lista->inicio->proximo = NULL;
    lista->inicio->anterior = NULL;
    lista->inicio->valor = valor;
    lista->fim = lista->inicio;
    lista->cnt = 1;
}

void insere_inicio(struct l_descr *lista, int valor){
    if(esta_vazia(lista) == 1){
        insere_lista_nula(lista, valor);
    }else{
        struct no *novo = malloc(sizeof(struct no));
        novo->valor = valor;
        novo->proximo = lista->inicio;
        novo->anterior = NULL;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        lista->cnt++;
    }
}

void insere_fim(struct l_descr *lista, int valor){
    if(esta_vazia(lista) == 1){
        insere_lista_nula(lista, valor);
    }else{
        struct no *novo = malloc(sizeof(struct no));
        novo->valor = valor;
        novo->proximo = NULL;
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
        lista->cnt++;
    }
}

void insere_ordenado(struct l_descr *lista, int valor){
    if(esta_vazia(lista) == 1){
        insere_inicio(lista, valor);
        return;
    }
    if(valor <= lista->inicio->valor){
        insere_inicio(lista, valor);
        return;
    }
    if(valor >= lista->fim->valor){
        insere_fim(lista, valor);
        return;
    }
    struct no *aux = lista->fim;
    while(aux->valor >= valor){
        aux = aux->anterior;
    }
    struct no *novo = malloc(sizeof(struct no));
    novo->valor = valor;
    novo->proximo = aux->proximo;
    novo->anterior = aux;
    aux->proximo->anterior = novo;
    aux->proximo = novo;
    lista->cnt++;
}

void remove_ultimo(struct l_descr *lista){
    struct no *penultimo = lista->fim->anterior;
    struct no *ultimo = lista->fim;
    penultimo->proximo = NULL;
    free(ultimo);
    lista->fim = penultimo;
    lista->cnt--;
}

void remove_primeiro(struct l_descr *lista){
    struct no *segundo = lista->inicio->proximo;
    struct no *primeiro = lista->inicio;
    segundo->anterior = NULL;
    free(primeiro);
    lista->inicio = segundo;
    lista->cnt--;
}

void remove_indice(struct l_descr *lista, int indice){
    if(esta_vazia(lista) == 1){
        printf("A lista esta vazia");
        return;
    }
    if(indice >= lista->cnt || indice < 0){
        printf("Nenhum elemento nessa posicao");
    }
    if(indice == lista->cnt-1){
        remove_ultimo(lista);
        return;
    }
    if(indice == 0){
        remove_primeiro(lista);
        return;
    }
    int i = 0;
    struct no *aux = lista->inicio;
    while(i != indice){
        i++;
        aux=aux->proximo;
    }
    
    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;
    free(aux);
    lista->cnt--;
}
void main(){
    struct l_descr l1;
    inicializa_lista(&l1);

    insere_inicio(&l1, 3);
    insere_inicio(&l1, 1);
    insere_ordenado(&l1, 2);
    insere_ordenado(&l1, 4);
    remove_indice(&l1, 1);
    imprime_lista(&l1);
}