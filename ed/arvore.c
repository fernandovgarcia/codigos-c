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
int conta_nos(arvore *arvore);
int sao_iguais(arvore *a, arvore *b);
arvore *insere_ordenado(int valor, arvore *a);

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

int conta_nos(arvore *a){
  int cont = 0;
  if (!esta_vazia(a)){
    cont += 1;
    cont += conta_nos(a->esq);
    cont += conta_nos(a->dir);  
  }else{
    return cont;
  }
  return cont;
}

int sao_iguais(arvore *a, arvore *b){
  if(esta_vazia(a) && esta_vazia(b)){
    return 1;
  }
  if(esta_vazia(a) && !esta_vazia(b)){
    return 0;
  }
  if(!esta_vazia(a) && esta_vazia(b)){
    return 0;
  }
  int cont = 0;
  if(a->valor == b->valor){
    cont += 1;
  }
  cont += sao_iguais(a->esq, b->esq); 
  cont += sao_iguais(a->dir, b->dir);  
  if(cont == 3){
    return 1;
  }
  return 0;
}

arvore *insere_ordenado(int valor, arvore *a){
  // while(a != NULL){
    if(valor < a->valor){
      if(a->esq == NULL){
        arvore *novo = malloc(sizeof(arvore));
        a->esq = novo;
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
      }else{
        return insere_ordenado(valor, a->esq);
      }
    }else if(valor > a->valor){
      if(a->dir == NULL){
        arvore *novo = malloc(sizeof(arvore));
        a->dir = novo;
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
      }else{
        return insere_ordenado(valor, a->dir);
      }
    }
  // }
}

void main(){
  arvore *raiz1=cria_arvore(30, cria_vazia(), cria_vazia());
  // imprime(raiz1); printf("\n");

  raiz1->esq = cria_arvore(9, 
                     cria_arvore(4, cria_vazia(), cria_vazia()),
                     cria_arvore(15, cria_vazia(), cria_vazia()));
  raiz1->dir = cria_arvore(40, 
                     cria_vazia(),
                     cria_arvore(31, cria_vazia(), cria_vazia()));
  imprime(raiz1); printf("\n");

  arvore *raiz2=cria_arvore(5, cria_vazia(), cria_vazia());
  // imprime(raiz2); printf("\n");

  // raiz2->esq = cria_arvore(35, 
  //                    cria_arvore(40, cria_vazia(), cria_vazia()),
  //                    cria_arvore(42, cria_vazia(), cria_vazia()));
  // raiz2->dir = cria_arvore(85, 
  //                    cria_arvore(70, cria_vazia(), cria_vazia()),
  //                    cria_arvore(92, cria_vazia(), cria_vazia()));
  // imprime(raiz2); printf("\n");

  // desaloca_arvore(raiz);
  // imprime(raiz); printf("\n");
  printf("O VALOR TA NA LISTA? %d\n", existe_valor2(92, raiz1));
  // raiz = desaloca_arvore(raiz);
  // imprime(raiz); printf("\n"); 

  // printf("%d\n", sao_iguais(raiz1, raiz2));

  insere_ordenado(16, raiz1);

  imprime(raiz1); printf("\n");

}