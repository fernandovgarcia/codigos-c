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
};

void inicializa_lista(struct l_descr *lista){
    lista->inicio=NULL;
    lista->cnt=0;
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
    int i = 0;
    while(i < lista->cnt){
        printf("valor: %d\n", aux->valor);
        aux = aux->proximo;
        i++;
    }
}

void insere_lista_nula(struct l_descr *lista, int valor){
    lista->inicio = malloc(sizeof(struct no));
    lista->inicio->proximo = NULL;
    lista->inicio->anterior = NULL;
    lista->inicio->valor = valor;
    lista->inicio->proximo = lista->inicio;
    lista->inicio->anterior = lista->inicio;
    lista->cnt = 1;
}

void insere_inicio(struct l_descr *lista, int valor){
    if(esta_vazia(lista) == 1){
        insere_lista_nula(lista, valor);
    }else{
        struct no *novo = malloc(sizeof(struct no));
        novo->valor = valor;
        novo->proximo = lista->inicio;
        novo->anterior = lista->inicio->anterior;
        lista->inicio->anterior->proximo = novo;
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
        lista->inicio->anterior->proximo = novo;
        novo->anterior = lista->inicio->anterior;
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->cnt++;
    }
}

void insere_ordenado(struct l_descr *lista, int valor){
    if(esta_vazia(lista) == 1){
        insere_lista_nula(lista, valor);
        return;
    }
    if(valor <= lista->inicio->valor){
        insere_inicio(lista, valor);
        return;
    }
    if(valor >= lista->inicio->anterior->valor){
        insere_fim(lista, valor);
        return;
    }
    struct no *aux = lista->inicio;
    while(valor > aux->valor){
        aux = aux->proximo;
    }
    struct no *novo = malloc(sizeof(struct no));
    aux->anterior->proximo = novo;
    novo->anterior = aux->anterior;
    aux->anterior = novo;
    novo->proximo = aux;
    novo->valor = valor;
    lista->cnt++;
}

void remove_primeiro(struct l_descr *lista){
    struct no *primeiro = lista->inicio;
    primeiro->anterior->proximo = lista->inicio->proximo;
    primeiro->proximo->anterior = lista->inicio->anterior;
    lista->inicio = primeiro->proximo;
    free(primeiro);
    lista->cnt--;
}

void remove_ultimo(struct l_descr *lista){
    struct no *ultimo = lista->inicio->anterior;
    struct no *penultimo = ultimo->anterior;
    penultimo->proximo = lista->inicio;
    lista->inicio->anterior = penultimo;
    free(ultimo);
    lista->cnt--;
}

void remove_indice(struct l_descr *lista, int indice){
    if(esta_vazia(lista) == 1){
        printf("A lista esta vazia\n");
        return;
    }
    if(indice >= lista->cnt || indice < 0){
        printf("Nenhum elemento nessa posicao\n");
        return;
    }
    if(indice == 0){
        remove_primeiro(lista);
        return;
    }
    if(indice == lista->cnt-1){
        remove_ultimo(lista);
        return;
    }
    int i = 0;
    struct no *aux = lista->inicio;
    while(i != indice){
        aux = aux->proximo;
        i++;
    }
    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;
    free(aux);
    lista->cnt--;
}

int main(){
    struct l_descr l1;
    inicializa_lista(&l1);
    insere_inicio(&l1, 4);
    insere_inicio(&l1, 1);
    insere_ordenado(&l1, 2);
    insere_ordenado(&l1, 3);
    remove_indice(&l1, 4);
    imprime_lista(&l1);
}