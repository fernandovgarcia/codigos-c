#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *proximo;
};

int main(){
    struct no *inicio;
    
    // Aloca o primeiro elemento da lista
    inicio=malloc(sizeof(struct no)); 
    // Atribui o valor para o primeiro elemento
    inicio->valor=10; 
    
    // Aloca o segundo elemento e atribui o valor para ele
    inicio->proximo=malloc(sizeof(struct no)); 
    inicio->proximo->valor=20;
    
    // Aloca o terceiro elemento e atribui o valor para ele
    inicio->proximo->proximo=malloc(sizeof(struct no)); 
    inicio->proximo->proximo->valor=30; 
    
    // Fim da lista = NULL
    inicio->proximo->proximo->proximo=NULL; 

    // Imprimir os elementos da lista
    struct no *aux = inicio;
    while (aux!=NULL){
        printf("%i \n", aux->valor);
        aux = aux->proximo;
    }
}
