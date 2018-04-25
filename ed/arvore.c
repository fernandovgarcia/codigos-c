#include <stdio.h>
#include <stdlib.h>

struct no {
  int valor;
  struct no* esq;
  struct no* dir;
};

typedef struct no arvore;

arvore *cria_vazia();
arvore *cria_arvore(int valor, arvore *sae, arvore *sad);
int esta_vazia(arvore *a);
arvore *desaloca_arvore(arvore *a);
int existe_valor(int valor, arvore *a);
void imprime(arvore *a);

arvore *cria_vazia(){
  return NULL;
}

int esta_vazia(arvore *a){
  return a==NULL;
}

void imprime(arvore *a){
  if (!esta_vazia(a)){
     printf("%i\n", a->valor);
     imprime(a->esq);
     imprime(a->dir);
  }
}

arvore *cria_arvore(int valor, arvore *sae, arvore *sad){
	arvore *novo = malloc(sizeof(arvore));
	novo->valor = valor;
	novo->esq = sae;
	novo->dir = sad;
	return novo;
}

arvore *desaloca_arvore(arvore *a){
	if (!esta_vazia(a)){
    	desaloca_arvore(a->esq);
    	desaloca_arvore(a->dir);
  		free(a);
  	}
	return NULL;
}

int existe_valor2(int valor, arvore *a){
	if (esta_vazia(a))
		return 0;
	else 
		return valor==a->valor||existe_valor2(valor,a->esq)||existe_valor2(valor,a->dir);
}

int existe_valor(int valor, arvore *a){
	int aux;
	if (!esta_vazia(a)){
		if(a->valor == valor){
			return 1;
		}
    	if(existe_valor(valor, a->esq) == 1){
    		return 1;
    	}
    	return existe_valor(valor, a->dir);
  	}
  	return 0;
}


void main(){
  arvore *raiz=cria_arvore(5, cria_vazia(), cria_vazia());
  imprime(raiz); printf("\n");

  raiz->esq = cria_arvore(35, 
                     cria_arvore(40, cria_vazia(), cria_vazia()),
                     cria_arvore(42, cria_vazia(), cria_vazia()));
  raiz->dir = cria_arvore(85, 
                     cria_arvore(70, cria_vazia(), cria_vazia()),
                     cria_arvore(92, cria_vazia(), cria_vazia()));
  imprime(raiz); printf("\n");

  // desaloca_arvore(raiz);
  // imprime(raiz); printf("\n");
  printf("O VALOR TA NA LISTA? %d\n", existe_valor2(92, raiz));
  raiz = desaloca_arvore(raiz);
  imprime(raiz); printf("\n"); 

}