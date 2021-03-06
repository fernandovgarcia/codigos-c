#include <stdio.h>
#include <stdlib.h>

struct no{
    struct no *anterior;
    int val;
    struct no *proximo;
};

struct l_descr{
    struct no *inicio;
    int cnt;
    struct no *fim;
};

void inicializa(struct l_descr *lista){
    lista->inicio = NULL;
    lista->cnt = 0;
    lista->fim = NULL;
}

void imprime_lista(struct no *elemento){
    if(elemento != NULL){
        printf("%d ", elemento->val);
        imprime_lista(elemento->proximo);
    }
    printf("\n");
}

void insere_lista_nula(struct l_descr *lista, int val) {
  lista->inicio = malloc(sizeof(struct no));
  lista->inicio->val = val;
  lista->inicio->proximo = NULL;
  lista->inicio->anterior = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
}

void insere_inicio(struct l_descr *lista,int val) {
  if (lista->inicio == NULL) {
    insere_lista_nula(lista,val);
  } else {
    struct no *novo = malloc(sizeof(struct no));
    novo->val = val;
    novo->proximo = lista->inicio;
    lista->inicio->anterior = novo;
    lista->inicio = novo;
    lista->cnt++;
  }
}

void zera_lista(struct l_descr *lista){
    struct no *aux = lista->fim;
    while(aux != NULL){
        aux->val = 0;
        aux = aux->anterior;
    }
}
void incrementa_cont(struct l_descr *lista){
    struct no *aux = lista->fim;
    int i = 0;
    if(aux == NULL){
        insere_inicio(lista, 1);
    }
    while(aux != NULL){
        if(aux->val == 1 && aux == lista->inicio){
            zera_lista(lista);
            insere_inicio(lista, 1);
            break;
        }
        if(aux->val == 1){
            aux->val = 0;
            i = 1;
        }
        if(aux->val == 0 && i == 0){
            aux->val = 1;
            break;
        }
        i = 0;
        aux = aux->anterior;
    }
    lista->cnt++;
}

void main(){
    struct l_descr lista;
    inicializa(&lista);
    incrementa_cont(&lista);
    imprime_lista(lista.inicio);

    incrementa_cont(&lista);
    imprime_lista(lista.inicio);
    incrementa_cont(&lista);
    imprime_lista(lista.inicio);
    incrementa_cont(&lista);
    incrementa_cont(&lista);
    incrementa_cont(&lista);
    incrementa_cont(&lista);
    incrementa_cont(&lista);
    imprime_lista(lista.inicio);
    incrementa_cont(&lista);
    imprime_lista(lista.inicio);
}