#include <stdio.h>
#include <stdlib.h>

struct no{
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

void imprime_lista(struct no *aux){
    while (aux!=NULL){
        printf("%i \n", aux->valor);
        aux = aux->proximo;
    }
}

int conta_elementos(struct no *lista){
    int cont=0;
    while (lista!=NULL){
        cont++;
        lista = lista->proximo;
    }
    return cont;
}


int posicao(struct no *lista, int valor){
    int pos=0;
    struct no *aux=lista;
    while(aux!=NULL){
        if(aux->valor==valor){ // valor foi encontrado
            return pos;
        }
        else{
            pos++;
            aux=aux->proximo;
        }
    }
    return -1;
}

void insere(struct l_descr *lista, int valor){
    struct no *aux;
    // Insere o primeiro elemento na lista
    if (lista->inicio == NULL){
        lista->inicio=malloc(sizeof(struct no));
        aux=lista->inicio;
        aux->valor=valor;
        aux->proximo=NULL;
        lista->cnt=1;
        lista->fim=lista->inicio;
        return;
    }
    aux=lista->fim;
    aux->proximo=malloc(sizeof(struct no));
    aux->proximo->valor=valor;
    aux->proximo->proximo=NULL;
    lista->cnt++;
    lista->fim=aux->proximo;
}

int main(){
    struct l_descr lista1;
    
    inicializa_lista(&lista1);
/*    // Aloca o primeiro elemento da lista
    inicio=malloc(sizeof(struct no)); 
    // Atribui o valor para o primeiro elemento
    inicio->valor=10; 
    inicio->proximo=NULL;
*/
    insere(&lista1,20);
    insere(&lista1,30);
    insere(&lista1,40);
    insere(&lista1,50);

    printf("posicao = %d\n", posicao(lista1.inicio, 130)); 

    // Imprimir os elementos da lista
    imprime_lista(lista1.inicio);

}
