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
  struct no *fim;
};

void inicializa_lista(struct l_descr *lista) {
  lista->inicio=NULL;
  lista->cont=0;
  lista->fim=NULL;
}


void imprime_lista(struct l_descr *lista) 
{
  struct no *aux = lista->inicio;
  while(aux!=NULL) {
    printf("%d\n",aux->valor);
    aux = aux->proximo;
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
  lista->fim = lista->inicio;
}

void insere_inicio(struct l_descr *lista,int val) {
  if (esta_vazia(lista)==1) {
    insere_lista_nula(lista,val);
  } else {
    struct no *novo = malloc(sizeof(struct no));
    novo->anterior = NULL;
    novo->valor = val;
    novo->proximo = lista->inicio;
    lista->inicio->anterior = novo;
    lista->inicio = novo;
    lista->cont++;
  }
}

int remove_valor(struct l_descr *lista, int val){
  if(lista->inicio == NULL){
    return 0;
  }
  if(lista->cont != 1){
    if(lista->inicio->valor == val){
      lista->inicio = lista->inicio->proximo;
      free(lista->inicio->anterior);
      lista->inicio->anterior = NULL;
      lista->cont--;
      return 1;
    }else if(lista->fim->valor == val){
      lista->fim = lista->fim->anterior;
      free(lista->fim->proximo);
      lista->fim->proximo = NULL;
      lista->cont--;
      return 1;
    }else{
      struct no *aux = lista->inicio;
      while(aux->valor != val){
        if(aux->proximo == NULL){
          return 0;
        }
        aux = aux->proximo;
      }
      aux->anterior->proximo = aux->proximo;
      aux->proximo->anterior = aux->anterior;
      free(aux);
      lista->cont--;
      return 1;
    }
  }else{
    if(lista->inicio->valor == val){
      free(lista->inicio);
      lista->inicio =  NULL;
      lista->fim = NULL;
      lista->cont = 0;
      return 1;
    }
  }
}

int sao_iguais(struct l_descr *lista1, struct l_descr *lista2){
  if(lista1->cont == lista2->cont){
    struct no *aux1 = lista1->inicio;
    struct no *aux2 = lista2->inicio;
    int i = 0;
    if(esta_vazia(lista1) && esta_vazia(lista2)){
      return 1;
    }
    while(aux1->proximo != NULL && aux2->proximo != NULL){
      if(aux1->valor == aux2->valor){
        i++;
      }else{
        return 0;
      }
      aux1 = aux1->proximo;
      aux2 = aux2->proximo;
    }
    if(i == lista1->cont-1 && i == lista2->cont-1 && lista1->fim->valor == lista2->fim->valor){
      return 1;
    }
  }
  return 0;
}

int copiar(struct l_descr *lista1, struct l_descr *lista2){
  if(lista1->inicio == NULL && lista2->inicio == NULL){
    printf("As listas estão vazias\n");
    return 0;
  }else{
    struct no *aux = lista1->fim;
    while(aux != NULL){
      insere_inicio(lista2, aux->valor);
      aux=aux->anterior;
    }
  }
}

bool esta_na_lista(struct l_descr *lista, int val){
    struct no *aux1 = lista->fim;
    int i = 0;
    if(esta_vazia(lista) == 1){
      return false;
    }else{
      while(aux1 != NULL){
        if(aux1->valor == val){
          return true;
        }
        aux1 = aux1->anterior;
      }
    }
    return false;
}

void diferenca(struct l_descr *lista_diferenca, struct l_descr *lista1, struct l_descr *lista2){
  struct no *aux1 = lista1->fim;
  // struct no *aux2 = lista2->inicio;
  if(esta_vazia(lista2) == 1){
    copiar(lista1, lista_diferenca);
  }else{
    while(aux1 != NULL){
      if(!esta_na_lista(lista2, aux1->valor)){
        if(!esta_na_lista(lista_diferenca, aux1->valor)){
          insere_inicio(lista_diferenca, aux1->valor);
        }
      }
      aux1 = aux1->anterior;
    }
  }
}

void diferenca_ordenada(struct l_descr *lista_diferenca, struct l_descr *lista1, struct l_descr *lista2){
  struct no *aux1 = lista1->fim;
  struct no *aux2 = lista2->fim;
  int cont = 0;
  int i = 0;
  if(esta_vazia(lista2) == 1){
    copiar(lista1, lista_diferenca);
  }else{
    while(aux1 != NULL){
      cont = 0;
      aux2 = lista2->fim;
      if(aux1->valor > aux2->valor){
        insere_inicio(lista_diferenca, aux1->valor);
      }
      while(aux2->valor <= aux1->valor){
        if(aux1->valor = aux2->valor){
          cont++;
        }
        if(aux2->anterior == NULL){
          break;
        }
        aux2 = aux2->anterior;
      }
      if(cont == 0){
        if(!esta_na_lista(lista_diferenca, aux1->valor)){
          insere_inicio(lista_diferenca, aux1->valor);
        }
      }
      i++;
      aux1 = aux1->anterior;
    }
  }
}

int comuns(struct l_descr *lista1, struct l_descr *lista2){
  struct no *aux1 = lista1->fim;
  int i = 0;
  if(esta_vazia(lista1) == 1 || esta_vazia(lista2) == 1){
      return i;
  }else{
    while(aux1 != NULL){
      if(esta_na_lista(lista2, aux1->valor)){
        i++;
      }
      aux1 = aux1->anterior;
    }
  }
  return i;
}

int conta_elementos(struct l_descr *lista){
  struct no *aux1 = lista->fim;
  int i = 0;
  if(esta_vazia(lista)){
    return i;
  }else{
    while(aux1 != NULL){
      i++;
      aux1 = aux1->anterior;
    }
  }
  return i;
}

int eh_inversa(struct l_descr *lista1, struct l_descr *lista2){
  int n1 = conta_elementos(lista1);
  int n2 = conta_elementos(lista2);
  int i = 0;
  if(n1 == n2){
    if(n1 ==0 && n2 == 0){
      printf("As listas estão vazias\n");
      return 0;
    }else{
      struct no *aux1 = lista1->inicio;
      struct no *aux2 = lista2->fim;
      while(aux1 != NULL){
        if(aux1->valor == aux2->valor){
          i++;
        }
        aux1 = aux1->proximo;
        aux2 = aux2->anterior;
      }
      if(i == n1 && i == n2){
        return 1;
      }else{
        return 0;
      }
    }
  }else if(conta_elementos(lista1) < conta_elementos(lista2)){
    return -1;
  }else if(conta_elementos(lista1) > conta_elementos(lista2)){
    return -2;
  }
}

void remove_impares(struct l_descr *lista){
  if(esta_vazia(lista) == 1){
    printf("A lista está vazia\n");
  }else{
    struct no *aux = lista->inicio;
    struct no *aux2 = lista->inicio;
    int i = 1;
    while(aux != NULL){
      aux2 = aux->proximo;
      if(i % 2 == 1){
        remove_valor(lista, aux->valor);
      }
      aux = aux2;
      i++;
    }
  }
}

void destroi(struct l_descr *l){
  if(esta_vazia(l) == 1){
    printf("A lista está vazia\n");
  }else{
    struct no *aux = l->inicio;
    struct no *aux2 = l->inicio;
    int i = 1;
    while(aux != NULL){
      aux2 = aux->proximo;
      remove_valor(l, aux->valor);
      aux = aux2;
    }
  }
}

int main() {
  struct l_descr lista1;
  struct l_descr lista2;
  struct l_descr lista_diferenca;

  inicializa_lista(&lista1);
  inicializa_lista(&lista2);
  inicializa_lista(&lista_diferenca);
  insere_inicio(&lista1,7);
  insere_inicio(&lista1,6);
  insere_inicio(&lista1,5);
  insere_inicio(&lista1,3);
  insere_inicio(&lista1,1);
  insere_inicio(&lista2,5);
  insere_inicio(&lista2,4);
  insere_inicio(&lista2, 2);
  // copiar(&lista1, &lista2);
  printf("LISTA 1\n");
  imprime_lista(&lista1);
  printf("LISTA 2\n");
  imprime_lista(&lista2);

  diferenca_ordenada(&lista_diferenca, &lista1, &lista2);
  printf("LISTA DIFERENCA ORDENADA\n");
  imprime_lista(&lista_diferenca);

  // printf("tem %d numero(s) em comum nas listas 1 e 2\n", comuns(&lista1, &lista2));

  // printf("RETORNO DA FUNCAO EH_INVERSA\n");
  // printf("%d\n", eh_inversa(&lista1, &lista2));

  // printf("LISTA 1 COM OS IMPARES REMOVIDOS\n");
  // remove_impares(&lista1);
  // imprime_lista(&lista1);

  // printf("LISTA L REMOVIDA\n");
  // destroi(&lista_diferenca);
  // imprime_lista(&lista_diferenca);
  return 0;
}
