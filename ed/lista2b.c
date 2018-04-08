//Aluno: Fernando Vedoin Garcia
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct no{
  int valor;
  struct no *proximo;
  struct no *anterior;
};

struct l_descr{
  struct no *inicio;
  int cont;
};

void inicializa_lista(struct l_descr *lista) {
  lista->inicio=NULL;
  lista->cont=0;
}


void imprime_lista(struct l_descr *lista) 
{
  struct no *aux = lista->inicio;
  int i = 1;
  while(i<=lista->cont) {
    printf("%d\n",aux->valor);
    aux = aux->proximo;
    i++;
  }
}

int esta_vazia(struct l_descr *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

void insere_lista_nula(struct l_descr *lista, int val) {
  lista->inicio = malloc(sizeof(struct no));
  lista->inicio->anterior = NULL;
  lista->inicio->valor = val;
  lista->inicio->proximo = NULL;
  lista->cont = 1;
  lista->inicio->proximo = lista->inicio;
  lista->inicio->anterior = lista->inicio;
}

void insere_inicio(struct l_descr *lista,int val) {
  if (esta_vazia(lista)==1) {
    insere_lista_nula(lista,val);
  } else {
    struct no *novo = malloc(sizeof(struct no));
    struct no *aux = lista->inicio;
    novo->anterior = NULL;
    novo->valor = val;
    novo->proximo = NULL;

    aux->anterior->proximo = novo;
    novo->proximo = aux;
    novo->anterior = aux->anterior;
    aux->anterior = novo;
    lista->inicio = novo;
    lista->cont++;
  }
}

int copia_inv(struct l_descr *lista2, struct l_descr *lista1){
  if(lista1->inicio == NULL && lista2->inicio == NULL){
    printf("As listas estão vazias\n");
    return 0;
  }else{
    struct no *aux = lista2->inicio;
    int i = 1;
    while(i <= lista2->cont){
      insere_inicio(lista1, aux->valor);
      aux=aux->proximo;
      i++;
    }
  }
}

void remove_pares(struct l_descr *lista){
  if(esta_vazia(lista) == 1){
    printf("A lista está vazia\n");
  }else{
    struct no *aux = lista->inicio;
    struct no *aux2 = lista->inicio;
    int i = 1;
    int cnt = lista->cont;
    while(i <= cnt){
      aux2 = aux->proximo;
      if(i % 2 == 1){
        if(aux != lista->inicio){
          aux->anterior->proximo = aux->proximo;
          aux->proximo = aux->anterior;
          free(aux);
          lista->cont--;
        }else{
          lista->inicio = aux->proximo;
          aux->anterior->proximo = aux->proximo;
          aux->proximo = aux->anterior;
          free(aux);
          lista->cont--;
        }
      }
      aux = aux2;
      i++;
    }
  }
}

void intercala(struct l_descr *lista1, struct l_descr *lista2){

  if(esta_vazia(lista1) == 1 && esta_vazia(lista2) == 1){
    printf("As listas estao vazias\n");
    return;
  }

  if(esta_vazia(lista2) == 1){
    return;
  }

  struct no *aux1 = lista1->inicio;
  struct no *aux2 = lista2->inicio;
  struct no *inicio_lista1 = aux1;
  struct no *fim_lista2 = aux2->anterior;

  if(esta_vazia(lista1) == 1){
    lista1->inicio = aux2;
    lista1->inicio->proximo = aux2->proximo;
    lista1->inicio->anterior = fim_lista2;
    lista1->cont = lista2->cont;
    return;
  }

  int i = 0;
  while(i<lista2->cont){
    struct no *proximo2 = aux2->proximo;
    struct no *proximo1 = aux1->proximo;

    if(proximo1 == inicio_lista1){
      aux1->proximo = aux2;
      aux2->anterior = aux1;
      proximo1->anterior = fim_lista2;
      fim_lista2->proximo = inicio_lista1;
      break;
    }

    aux1->proximo = aux2;
    proximo1->anterior = aux2;
    aux2->anterior = aux1;
    aux2->proximo = proximo1;
    aux2 = proximo2;
    aux1 = proximo1;
    i++;
  }
  lista1->cont = lista1->cont + lista2->cont;
}

int main() {
  struct l_descr lista1;
  struct l_descr lista2;

  inicializa_lista(&lista1);
  inicializa_lista(&lista2);

  insere_inicio(&lista1, 10);
  insere_inicio(&lista1, 20);
  insere_inicio(&lista1, 30);

  insere_inicio(&lista2, 40);
  insere_inicio(&lista2, 50);
  insere_inicio(&lista2, 60);
  insere_inicio(&lista2, 70);
  insere_inicio(&lista2, 80);

  // copia_inv(&lista1, &lista2);
  // remove_pares(&lista1);
  printf("LISTA 1\n");
  imprime_lista(&lista1);  
  printf("LISTA 2\n");
  imprime_lista(&lista2);
  intercala(&lista1, &lista2);
  printf("LISTA 1 INTERCALADA\n");
  imprime_lista(&lista1);  
  return 0;
}
