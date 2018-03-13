#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *proximo;
};

void imprime_lista(struct no *aux){
    while (aux!=NULL){
        printf("%i \n", aux->valor);
        aux = aux->proximo;
    }
}

void insere(struct no **lista, int valor){
    struct no *aux;

    // Insere o primeiro elemento na lista
    if (*lista == NULL){
        *lista=malloc(sizeof(struct no));
        aux=*lista;
        aux->valor=valor;
        aux->proximo=NULL;
        return;
    }
    aux=*lista;
    // Encontrar o ultimo elemento da lista
    while(aux->proximo != NULL){
        aux=aux->proximo;
    }
    aux->proximo=malloc(sizeof(struct no));
    aux->proximo->valor=valor;
    aux->proximo->proximo=NULL;
}

int main(){
    struct no *inicio=NULL;
    
/*    // Aloca o primeiro elemento da lista
    inicio=malloc(sizeof(struct no)); 
    // Atribui o valor para o primeiro elemento
    inicio->valor=10; 
    inicio->proximo=NULL;
*/
    insere(&inicio,20);
    insere(&inicio,30);
    insere(&inicio,40);
    insere(&inicio,50);


    // Imprimir os elementos da lista
    imprime_lista(inicio);

}
