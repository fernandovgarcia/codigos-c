#include <stdio.h>
#include <stdlib.h>

struct no{
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
}

void insere_lista_nula(struct l_descr *lista, int val) {
  lista->inicio = malloc(sizeof(struct no));
  lista->inicio->val = val;
  lista->inicio->proximo = NULL;
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
    lista->inicio = novo;
    lista->cnt++;
  }
}

void main(){
    struct l_descr lista;
    inicializa(&lista);
    insere_inicio(&lista, 1);
    insere_inicio(&lista, 2);
    insere_inicio(&lista, 3);
    imprime_lista(lista.inicio);
}