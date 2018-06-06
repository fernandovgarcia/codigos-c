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

struct no_placa {
  struct carro *carro;
  struct no_placa *esq;
  struct no_placa *dir;
};

typedef struct carro obj;
typedef struct no_marca arv_marca;
typedef struct no_ano arv_ano ;
typedef struct no_placa arv_placa;

arv_marca  *cria_arv_marca_vazia();
arv_marca  *cria_arv_marca (struct carro *carro, arv_marca  *sae, arv_marca  *sad);
bool esta_vazia_marca(arv_marca  *a);
arv_marca  *desaloca_arv_marca (arv_marca  *a);
int existe_valor_marca(struct carro *carro, arv_marca  *a);
void imprime_marca(arv_marca  *a);
arv_marca  *insere_marca_ordenado(struct carro *carro, arv_marca  *a);

arv_ano  *cria_arv_ano_vazia();
arv_ano  *cria_arv_ano (struct carro *carro, arv_ano  *sae, arv_ano  *sad);
bool esta_vazia_ano(arv_ano  *a);
arv_ano  *desaloca_arv_ano (arv_ano  *a);
int existe_valor_ano(struct carro *carro, arv_ano  *a);
void imprime_ano(arv_ano  *a);
arv_ano  *insere_ano_ordenado(struct carro *carro, arv_ano  *a);

arv_placa  *cria_arv_placa_vazia();
arv_placa  *cria_arv_placa (struct carro *carro, arv_placa  *sae, arv_placa  *sad);
bool esta_vazia_placa(arv_placa  *a);
arv_placa  *desaloca_arv_placa (arv_placa  *a);
int existe_valor_placa(struct carro *carro, arv_placa  *a);
void imprime_placa(arv_placa  *a);
arv_placa  *insere_placa_ordenado(struct carro *carro, arv_placa  *a);

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

arv_marca *remove_marca(arv_marca *a, struct carro *carro){
    if (esta_vazia_marca(a)) 
       return NULL;
    if (strcmp(carro->marca, a->carro->marca) < 0)
       a->esq = remove_marca(a->esq, carro);
    else if (strcmp(carro->placa, a->carro->placa) > 0)
       a->dir = remove_marca(a->dir, carro);
    else{
         if ((a->esq == NULL) && (a->dir == NULL)){
            free(a);
            a = NULL;
         } else
         if (a->esq == NULL){
            arv_marca* t = a;
            a = a->dir;
            free(t);           
         } else
         if (a->dir == NULL){
            arv_marca* t = a;
            a = a->esq;
            free(t);           
         } else {
            arv_marca* f = a->esq;
            while (f->dir != NULL)
               f = f->dir;
            a->carro = f->carro;
            f->carro = carro;
            a->esq = remove_marca(a->esq, carro);
         }
    }
    return a; 
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

arv_ano *remove_ano(arv_ano *a, struct carro *carro){
    if (esta_vazia_ano(a)) 
       return NULL;
    if (carro->ano < a->carro->ano)
       a->esq = remove_ano(a->esq, carro);
    else if (carro->ano > a->carro->ano)
       a->dir = remove_ano(a->dir, carro);
    else{
         if ((a->esq == NULL) && (a->dir == NULL)){
            free(a);
            a = NULL;
         } else
         if (a->esq == NULL){
            arv_ano *t = a;
            a = a->dir;
            free(t);           
         } else
         if (a->dir == NULL){
            arv_ano *t = a;
            a = a->esq;
            free(t);           
         } else {
            arv_ano *f = a->esq;
            while (f->dir != NULL)
               f = f->dir;
            a->carro = f->carro;
            f->carro = carro;
            a->esq = remove_ano(a->esq, carro);
         }
    }
    return a; 
}
/////////////////////////////

//FUNÇOES PARA ARVORE DE PLACA
arv_placa  *cria_arv_placa_vazia(){
  return NULL;
}

bool esta_vazia_placa(arv_placa  *a){
  return a==NULL;
}

void imprime_placa(arv_placa  *a){
  if (!esta_vazia_placa(a)){
    imprime_placa(a->esq);
    printf("%s\n", a->carro->placa);
    imprime_placa(a->dir);
  }
}

arv_placa  *cria_arv_placa (struct carro *carro, arv_placa  *sae, arv_placa  *sad){
	arv_placa  *novo = malloc(sizeof(arv_placa ));
	novo->carro = carro;
	novo->esq = sae;
	novo->dir = sad;
	return novo;
}

arv_placa  *desaloca_arv_placa (arv_placa  *a){
	if (!esta_vazia_placa(a)){
    	desaloca_arv_placa (a->esq);
    	desaloca_arv_placa (a->dir);
  		free(a);
  	}
	return NULL;
}

int existe_valor_placa(struct carro *carro, arv_placa  *a){
	int aux;
	if (!esta_vazia_placa(a)){
		if(strcmp(a->carro->placa, carro->placa) == 0){
			return 1;
		}
   	if(existe_valor_placa(carro, a->esq) == 1){
   		return 1;
   	}
   	return existe_valor_placa(carro, a->dir);
  }
  return 0;
}

int existe_valor_placa_busca(char placa[], arv_placa *a){
	int aux;
	if (!esta_vazia_placa(a)){
		if(strcmp(a->carro->placa, placa) == 0){
      printf("Placa: %s   Marca: %s   Ano: %i \n", a->carro->placa, a->carro->marca, a->carro->ano);
			return 1;
		}
    if(existe_valor_placa_busca(placa, a->esq) == 1){
      return 1;
    }
    return existe_valor_placa_busca(placa, a->dir);
  }
  return 0;
}

void busca_valor_placa(arv_placa *a){
	int aux;
  char placa[10];
  getchar();
  printf("Digite a placa do carro que voce busca:");
  fgets(placa, 10, stdin);
  tira_enter_do_final(placa);
  if(existe_valor_placa_busca(placa, a) == 0){
    printf("Carro nao cadastrado\n");
  }
}

int conta_nos_placa(arv_placa  *a){
  int cont = 0;
  if (!esta_vazia_placa(a)){
    cont += 1;
    cont += conta_nos_placa(a->esq);
    cont += conta_nos_placa(a->dir);  
  }else{
    return cont;
  }
  return cont;
}

arv_placa  *insere_placa_ordenado(struct carro *carro, arv_placa  *a){
  if (a == NULL) {
    a = cria_arv_placa(carro, NULL, NULL);
  }else{
    if (strcmp(carro->placa, a->carro->placa) < 0) {
        a->esq = insere_placa_ordenado(carro, a->esq);
    } else {
        a->dir = insere_placa_ordenado(carro, a->dir);
    }    
  }
  return a;
}

arv_placa *liberar_placa(arv_placa *a){
   if (!(a)){
      liberar_placa(a->esq);
      liberar_placa(a->dir);
      free(a);
   }        
   return NULL;
}

arv_placa *remove_placa(arv_placa *a, struct carro *carro){
    if (esta_vazia_placa(a)) 
       return NULL;
    if (strcmp(carro->placa, a->carro->placa) < 0)
       a->esq = remove_placa(a->esq, carro);
    else if (strcmp(carro->placa, a->carro->placa) > 0)
       a->dir = remove_placa(a->dir, carro);
    else{
         if ((a->esq == NULL) && (a->dir == NULL)){
            free(a);
            a = NULL;
         } else
         if (a->esq == NULL){
            arv_placa* t = a;
            a = a->dir;
            free(t);           
         } else
         if (a->dir == NULL){
            arv_placa* t = a;
            a = a->esq;
            free(t);           
         } else {
            arv_placa* f = a->esq;
            while (f->dir != NULL)
               f = f->dir;
            a->carro = f->carro;
            f->carro = carro;
            a->esq = remove_placa(a->esq, carro);
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

int busca_indice_lista(struct l_descr *lista, obj *carro) {
  if (esta_vazia(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    int cont = 0;
    struct no *aux = lista->inicio;
    while(aux != NULL){
      if(aux->carro == carro){
        return cont;
      }
      cont++;
      aux = aux->proximo;
    }
  }
  return -1;
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

obj *placa_busca_excluir(char placa[], arv_placa *a){
	int aux;
	if (!esta_vazia_placa(a)){
		if(strcmp(a->carro->placa, placa) == 0){
      return a->carro;
		}
    if(placa_busca_excluir(placa, a->esq) != NULL){
      return a->esq->carro;
    }
    return placa_busca_excluir(placa, a->dir);
  }
  return NULL;
}

obj *busca_excluir(arv_placa *a){
  char placa[10];
  printf("Digite a placa do veículo a ser excluido: ");
  getchar();
  fgets(placa, 10, stdin);
  tira_enter_do_final(placa);
  obj *carro = placa_busca_excluir(placa, a);
  if(carro == NULL){
    printf("Placa nao cadastrada");
  }
  return carro;
}

int menu(){
  printf("----- MENU ----\n");
  printf("1 - Inserir carro\n");
  printf("2 - Listar carros\n");
  printf("3 - Buscar carro\n");
  printf("4 - Excluir carro\n");
  int op;
  scanf("%d", &op);
  while(op > 5 && op <= 0){
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
    arv_placa *raiz_placa = NULL;
    struct l_descr l_carros;
    inicializa_lista(&l_carros);
    struct carro *jc;
    obj *carro = NULL;
    int op = menu();
    int op2;
    int indice;
    while(op != 5){
      switch(op){
        case 1:
          jc = le_carros(&l_carros);
          raiz_marca = insere_marca_ordenado(jc,raiz_marca);
          raiz_ano = insere_ano_ordenado(jc,raiz_ano);
          raiz_placa = insere_placa_ordenado(jc,raiz_placa);
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
          busca_valor_placa(raiz_placa);
          op = menu();
        break;
        case 4:
          carro = busca_excluir(raiz_placa);
          if(carro != NULL){
            indice = busca_indice_lista(&l_carros, carro);
            printf("O INDICE É %d", indice);
            remove_indice(&l_carros, indice);
            remove_placa(raiz_placa, carro);
            remove_marca(raiz_marca, carro);
            remove_ano(raiz_ano, carro);
            free(carro);
          }          
          op = menu();
        break;
      }
    }
}

