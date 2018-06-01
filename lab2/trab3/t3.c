#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct carro{
  char placa[10];
  char marca[50];
  int ano;
};

struct no{
  struct carro *carro;
  struct no *proximo;
};

struct l_descr{
  struct no *inicio;
  int cnt;
  struct no *fim;
};

struct no_marca {
  struct carro *carro;
  struct no_marca *esq;
  struct no_marca *dir;
};

struct no_ano {
  struct carro *carro;
  struct no_ano *esq;
  struct no_ano *dir;
};

typedef struct carro obj;
typedef struct no_marca arv_marca;
typedef struct no_ano arv_ano ;

arv_marca  *cria_arv_marca_vazia();
arv_marca  *cria_arv_marca (struct carro *carro, arv_marca  *sae, arv_marca  *sad);
bool esta_vazia_marca(arv_marca  *a);
arv_marca  *desaloca_arv_marca (arv_marca  *a);
int existe_valor_marca(struct carro *carro, arv_marca  *a);
void imprime_marca(arv_marca  *a);
int conta_nos_marca(arv_marca  *arv_marca );
int sao_iguais_marca(arv_marca  *a, arv_marca  *b);
arv_marca  *insere_marca_ordenado(struct carro *carro, arv_marca  *a);

arv_ano  *cria_arv_ano_vazia();
arv_ano  *cria_arv_ano (struct carro *carro, arv_ano  *sae, arv_ano  *sad);
bool esta_vazia_ano(arv_ano  *a);
arv_ano  *desaloca_arv_ano (arv_ano  *a);
int existe_valor_ano(struct carro *carro, arv_ano  *a);
void imprime_ano(arv_ano  *a);
int conta_nos_ano(arv_ano  *arv_ano );
int sao_iguais_ano(arv_ano  *a, arv_ano  *b);
arv_ano  *insere_ano_ordenado(struct carro *carro, arv_ano  *a);

void tira_enter_do_final(char s[]){
  int p = strlen(s)-1;
  if (s[p] == '\n'){
    s[p] = '\0';
  }
}

//FUNÇOES PARA ARVORE DE MARCA
arv_marca  *cria_arv_marca_vazia(){
  return NULL;
}

bool esta_vazia_marca(arv_marca  *a){
  return a==NULL;
}

void imprime_marca(arv_marca  *a){
  if (!esta_vazia_marca(a)){
    imprime_marca(a->esq);
    printf("%s\n", a->carro->marca);
    imprime_marca(a->dir);
  }
}

arv_marca  *cria_arv_marca (struct carro *carro, arv_marca  *sae, arv_marca  *sad){
	arv_marca  *novo = malloc(sizeof(arv_marca ));
	novo->carro = carro;
	novo->esq = sae;
	novo->dir = sad;
	return novo;
}

arv_marca  *desaloca_arv_marca (arv_marca  *a){
	if (!esta_vazia_marca(a)){
    	desaloca_arv_marca (a->esq);
    	desaloca_arv_marca (a->dir);
  		free(a);
  	}
	return NULL;
}

int existe_valor_marca(struct carro *carro, arv_marca  *a){
	int aux;
	if (!esta_vazia_marca(a)){
		if(strcmp(a->carro->marca, carro->marca) == 0){
			return 1;
		}
    	if(existe_valor_marca(carro, a->esq) == 1){
    		return 1;
    	}
    	return existe_valor_marca(carro, a->dir);
  	}
  	return 0;
}

int conta_nos_marca(arv_marca  *a){
  int cont = 0;
  if (!esta_vazia_marca(a)){
    cont += 1;
    cont += conta_nos_marca(a->esq);
    cont += conta_nos_marca(a->dir);  
  }else{
    return cont;
  }
  return cont;
}

int sao_iguais_marca(arv_marca  *a, arv_marca  *b){
  if(esta_vazia_marca(a) && esta_vazia_marca(b)){
    return 1;
  }
  if(esta_vazia_marca(a) && !esta_vazia_marca(b)){
    return 0;
  }
  if(!esta_vazia_marca(a) && esta_vazia_marca(b)){
    return 0;
  }
  int cont = 0;
  if(a->carro->marca == b->carro->marca){
    cont += 1;
  }
  cont += sao_iguais_marca(a->esq, b->esq); 
  cont += sao_iguais_marca(a->dir, b->dir);  
  if(cont == 3){
    return 1;
  }
  return 0;
}

arv_marca  *insere_marca_ordenado(struct carro *carro, arv_marca  *a){
  if (a == NULL) {
    a = cria_arv_marca(carro, NULL, NULL);
  }else{
    if (strcmp(carro->marca, a->carro->marca) < 0) {
        a->esq = insere_marca_ordenado(carro, a->esq);
    } else {
        a->dir = insere_marca_ordenado(carro, a->dir);
    }    
  }
  return a;
}

arv_marca *liberar_marca(arv_marca *a){
   if (!(a)){
      liberar_marca(a->esq);
      liberar_marca(a->dir);
      free(a);
   }        
   return NULL;
}
/////////////////////////////

//FUNCOES PARA ARVORE DE ANO
arv_ano  *cria_arv_ano_vazia(){
  return NULL;
}

bool esta_vazia_ano(arv_ano  *a){
  return a==NULL;
}

void imprime_ano(arv_ano  *a){
  if (!esta_vazia_ano(a)){
    imprime_ano(a->esq);
    printf("%i\n", a->carro->ano);
    imprime_ano(a->dir);
  }
}

arv_ano  *cria_arv_ano (struct carro *carro, arv_ano  *sae, arv_ano  *sad){
	arv_ano  *novo = malloc(sizeof(arv_ano ));
	novo->carro = carro;
	novo->esq = sae;
	novo->dir = sad;
	return novo;
}

arv_ano  *desaloca_arv_ano (arv_ano  *a){
	if (!esta_vazia_ano(a)){
    	desaloca_arv_ano (a->esq);
    	desaloca_arv_ano (a->dir);
  		free(a);
  	}
	return NULL;
}

int existe_valor_ano(struct carro *carro, arv_ano  *a){
	int aux;
	if (!esta_vazia_ano(a)){
		if(a->carro->ano == carro->ano){
			return 1;
		}
    	if(existe_valor_ano(carro, a->esq) == 1){
    		return 1;
    	}
    	return existe_valor_ano(carro, a->dir);
  	}
  	return 0;
}

int conta_nos_ano(arv_ano  *a){
  int cont = 0;
  if (!esta_vazia_ano(a)){
    cont += 1;
    cont += conta_nos_ano(a->esq);
    cont += conta_nos_ano(a->dir);  
  }else{
    return cont;
  }
  return cont;
}

int sao_iguais_ano(arv_ano  *a, arv_ano  *b){
  if(esta_vazia_ano(a) && esta_vazia_ano(b)){
    return 1;
  }
  if(esta_vazia_ano(a) && !esta_vazia_ano(b)){
    return 0;
  }
  if(!esta_vazia_ano(a) && esta_vazia_ano(b)){
    return 0;
  }
  int cont = 0;
  if(a->carro == b->carro){
    cont += 1;
  }
  cont += sao_iguais_ano(a->esq, b->esq); 
  cont += sao_iguais_ano(a->dir, b->dir);  
  if(cont == 3){
    return 1;
  }
  return 0;
}

arv_ano  *insere_ano_ordenado(struct carro *carro, arv_ano *a){
    if (a == NULL) {
      a = cria_arv_ano(carro, NULL, NULL);
    }else{
      if (carro->ano < a->carro->ano) {
          a->esq = insere_ano_ordenado(carro, a->esq);
      } else {
          a->dir = insere_ano_ordenado(carro, a->dir);
      }    
    }
    return a;
}
/////////////////////////////

void inicializa_lista(struct l_descr *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

void imprime_lista(struct l_descr *lista) {
  struct no *aux = lista->inicio;
  while(aux!=NULL) {
    printf("%s\n",aux->carro->placa);
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

obj *insere_lista_nula(struct l_descr *lista, int ano, char placa[], char marca[]) {
  lista->inicio = malloc(sizeof(struct no));
  lista->inicio->carro = malloc(sizeof(struct carro));
  lista->inicio->carro->ano = ano;
  strcpy(lista->inicio->carro->placa, placa);
  strcpy(lista->inicio->carro->marca, marca);
  lista->inicio->proximo = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
  return lista->inicio->carro;
}

obj *insere_inicio(struct l_descr *lista, int ano, char placa[], char marca[]) {
  if (esta_vazia(lista)==1) {
    return insere_lista_nula(lista, ano, placa, marca);
  } else {
    struct no *novo = malloc(sizeof(struct no));
    novo->carro = malloc(sizeof(struct carro));
    novo->carro->ano = ano;
    strcpy(novo->carro->placa, placa);
    strcpy(novo->carro->marca, marca);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->cnt++;
    return novo->carro;
  }
}

obj *insere_fim(struct l_descr *lista, int ano, char placa[], char marca[]) {
  if (esta_vazia(lista) == 1) {
    insere_lista_nula(lista, ano, placa, marca);
  } else {
    if (lista->fim->proximo == NULL) {
      lista->fim->proximo = malloc(sizeof(struct no));
      lista->fim->proximo->carro = malloc(sizeof(struct carro));
      lista->fim->proximo->carro->ano = ano;
      strcpy(lista->fim->proximo->carro->placa, placa);
      strcpy(lista->fim->proximo->carro->marca, marca);
      lista->fim->proximo->proximo = NULL;
      lista->fim = lista->fim->proximo;
      lista->cnt++;
      return lista->fim->carro;
    }
  }
}

obj *insere_ind(struct l_descr *lista, int ano, char placa[], char marca[], int indice) {
  if (esta_vazia(lista) == 1) {
    return insere_lista_nula(lista, ano, placa, marca);
  } else {
    if (lista->cnt>indice) {
      struct no *novo = malloc(sizeof(struct no));
      novo->carro = malloc(sizeof(struct carro));
      if (indice <= 0) {
        return insere_inicio(lista, ano, placa, marca);
      }
      int i = 0;
      struct no *anterior = lista->inicio;
      while (i!=indice-1) {
        anterior = anterior->proximo;
        i++;
      }
      struct no *seguinte = anterior->proximo;
      anterior->proximo = malloc(sizeof(struct no));
      anterior->proximo->carro = malloc(sizeof(struct carro));
      anterior->proximo->carro->ano = ano;
      strcpy(anterior->proximo->carro->placa, placa);
      strcpy(anterior->proximo->carro->marca, marca);
      anterior->proximo->proximo = seguinte;
      lista->cnt++;
      return anterior->proximo->carro;
    } else {
      return insere_fim(lista, ano, placa, marca);
    }
  }
}

obj *insere_ordenado(struct l_descr *lista, int ano, char placa[], char marca[]) {
  if (esta_vazia(lista) == 1) {
    return insere_lista_nula(lista, ano, placa, marca);
  } else {
    struct no *anterior = lista->inicio;
    int i = 0;
    while (strcmp(anterior->carro->placa, placa) < 0) {
      anterior = anterior->proximo;
      i++;
      if (anterior == NULL) {
        return insere_fim(lista, ano, placa, marca);
      }
    }
    return insere_ind(lista, ano, placa, marca,i);
  }
  return NULL;
}

obj *le_carros(struct l_descr *lista){
  char marca[50], placa[10];
  int ano;
  printf("Ano do veiculo: ");
  scanf("%d", &ano);
  getchar();
  printf("Marca do veiculo: ");
  fgets(marca, 50, stdin);
  tira_enter_do_final(marca);
  printf("Placa do veiculo: ");
  fgets(placa, 10, stdin);
  tira_enter_do_final(placa);
  return insere_ordenado(lista, ano, placa, marca);
}

bool remove_primeiro(struct l_descr *lista) {
  if (esta_vazia(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return true;
    } else {
      struct no *segundo = lista->inicio->proximo;
      free(lista->inicio);
      lista->inicio = segundo;
      lista->cnt--;
      return true;
    }
  }
  return false;
}

bool remove_ultimo(struct l_descr *lista) {
  if (esta_vazia(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return true;
    } else {
      struct no *penultimo = lista->inicio;
      struct no *ultimo = lista->fim;
      while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
      }
      penultimo->proximo = NULL;
      lista->fim = penultimo;
      free(ultimo);
      lista->cnt--;
      return true;
    }
  }
  return false;
}

bool remove_indice(struct l_descr *lista, int indice) {
  if (esta_vazia(lista) == 1) {
    printf("A lista esta vazia\n");
    return false;
  } else {
    if (indice>=lista->cnt || indice<0) {
      printf("A lista nao possui valor nesse indice\n");
      return false;
    } else {
      if (indice==0) {
        return remove_primeiro(lista);
      } else if (indice==lista->cnt-1) {
        return remove_ultimo(lista);
      }
      struct no *valor = lista->inicio;
      int cont=1;
      while(cont<indice){
        valor = valor->proximo;
        cont++;
      }
      struct no *proximo = valor->proximo->proximo;
      free(valor->proximo);
      valor->proximo = proximo;
      lista->cnt--;
      return true;
    }
  }
  return false;
}

int menu(){
  printf("----- MENU ----\n");
  printf("1 - Inserir carro\n");
  printf("2 - Listar carros\n");
  printf("3 - Buscar carro\n");
  int op;
  scanf("%d", &op);
  while(op > 4 && op <= 0){
    scanf("%d", &op);
  }
  return op;
}

int menu_listar(){
  printf("----- MENU ----\n");
  printf("1 - placa (lista)\n");
  printf("2 - marca (arvore)\n");
  printf("3 - ano (arvore)\n");
  int op;
  scanf("%d", &op);
  while(op > 4 && op <= 0){
    scanf("%d", &op);
  }
  return op;
}
void main(){
    arv_marca *raiz_marca = NULL;
    arv_ano *raiz_ano = NULL;
    struct l_descr l_carros;
    inicializa_lista(&l_carros);
    struct carro *jc;
    int op = menu();
    int op2;
    while(op != 4){
      switch(op){
        case 1:
          jc = le_carros(&l_carros);
          raiz_marca = insere_marca_ordenado(jc,raiz_marca);
          raiz_ano = insere_ano_ordenado(jc,raiz_ano);
          printf("Veiculo cadastrado com sucesso!\n");
          op = menu();
        break;
        case 2:
          op2 = menu_listar();
          switch(op2){
            case 1:
              imprime_lista(&l_carros);
              op = menu();
            break;
            case 2:
              imprime_marca(raiz_marca);
              op = menu();
            break;
            case 3:
              imprime_ano(raiz_ano);
              op = menu();
            break;
          }
        break;
        case 3:
          op = menu();
        break;
      }
    }
    
  
    imprime_lista(&l_carros);
    remove_indice(&l_carros, 2);
    imprime_lista(&l_carros);
}

