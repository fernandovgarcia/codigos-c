//Aluno: Fernando Vedoin Garcia
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

struct no_arv {
  struct carro *carro;
  struct no_arv *esq;
  struct no_arv *dir;
};

typedef struct carro obj;
typedef struct no_arv arv;

bool esta_vazia_arv(arv  *a);
void imprime_arv(arv  *a);
arv  *cria_arv_vazia();

arv  *cria_arv_marca (struct carro *carro, arv  *sae, arv  *sad);
int existe_valor_marca(struct carro *carro, arv  *a);
arv  *insere_marca_ordenado(struct carro *carro, arv  *a);

arv  *cria_arv_ano (struct carro *carro, arv  *sae, arv  *sad);
int existe_valor_ano(struct carro *carro, arv  *a);
arv  *insere_ano_ordenado(struct carro *carro, arv  *a);

arv  *cria_arv_placa (struct carro *carro, arv  *sae, arv  *sad);
int existe_valor_placa(struct carro *carro, arv  *a);
arv  *insere_placa_ordenado(struct carro *carro, arv  *a);

void tira_enter_do_final(char s[]){
  int p = strlen(s)-1;
  if (s[p] == '\n'){
    s[p] = '\0';
  }
}

arv  *cria_arv_vazia(){
  return NULL;
}

bool esta_vazia_arv(arv  *a){
  return a==NULL;
}

void imprime_arv(arv  *a){
  if (!esta_vazia_arv(a)){
    imprime_arv(a->esq);
    printf("%s   %s   %i\n",a->carro->placa, a->carro->marca, a->carro->ano);
    imprime_arv(a->dir);
  }
}

arv *liberar_arv(arv *a){
   if (!(a)){
      liberar_arv(a->esq);
      liberar_arv(a->dir);
      free(a);
   }        
   return NULL;
}

//FUNÇOES PARA ARVORE DE MARCA
arv  *cria_arv_marca (struct carro *carro, arv  *sae, arv  *sad){
	arv *novo = malloc(sizeof(arv));
	novo->carro = carro;
	novo->esq = sae;
	novo->dir = sad;
	return novo;
}

int existe_valor_marca(struct carro *carro, arv  *a){
	int aux;
	if (!esta_vazia_arv(a)){
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

arv  *insere_marca_ordenado(struct carro *carro, arv  *a){
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

arv *remove_marca(arv *a, struct carro *carro){
    if (esta_vazia_arv(a)) 
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
            arv* t = a;
            a = a->dir;
            free(t);           
         } else
         if (a->dir == NULL){
            arv* t = a;
            a = a->esq;
            free(t);           
         } else {
            arv* f = a->esq;
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
arv *cria_arv_ano (struct carro *carro, arv  *sae, arv  *sad){
	arv *novo = malloc(sizeof(arv));
	novo->carro = carro;
	novo->esq = sae;
	novo->dir = sad;
	return novo;
}

int existe_valor_ano(struct carro *carro, arv  *a){
	int aux;
	if (!esta_vazia_arv(a)){
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

arv  *insere_ano_ordenado(struct carro *carro, arv *a){
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

arv *remove_ano(arv *a, struct carro *carro){
    if (esta_vazia_arv(a)) 
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
            arv *t = a;
            a = a->dir;
            free(t);           
         } else
         if (a->dir == NULL){
            arv *t = a;
            a = a->esq;
            free(t);           
         } else {
            arv *f = a->esq;
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
arv *cria_arv_placa (struct carro *carro, arv  *sae, arv  *sad){
	arv *novo = malloc(sizeof(arv));
	novo->carro = carro;
	novo->esq = sae;
	novo->dir = sad;
	return novo;
}

int existe_valor_placa(struct carro *carro, arv  *a){
	int aux;
	if (!esta_vazia_arv(a)){
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

int existe_valor_placa_busca(char placa[], arv *a){
	int aux;
	if (!esta_vazia_arv(a)){
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

void busca_valor_placa(arv *a){
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

bool busca_valor_placa2(arv *a, char placa[]){
  if(existe_valor_placa_busca(placa, a) == 0){
    return false;
  }
  return true;
}


int conta_nos_placa(arv  *a){
  int cont = 0;
  if (!esta_vazia_arv(a)){
    cont += 1;
    cont += conta_nos_placa(a->esq);
    cont += conta_nos_placa(a->dir);  
  }else{
    return cont;
  }
  return cont;
}

arv  *insere_placa_ordenado(struct carro *carro, arv  *a){
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

arv *remove_placa(arv *a, struct carro *carro){
    if (esta_vazia_arv(a)) 
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
            arv* t = a;
            a = a->dir;
            free(t);           
         } else
         if (a->dir == NULL){
            arv* t = a;
            a = a->esq;
            free(t);           
         } else {
            arv* f = a->esq;
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
    printf("%s   %s   %d\n",aux->carro->placa, aux->carro->marca, aux->carro->ano);
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

obj *le_carros(struct l_descr *lista, arv *a){
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
  if(!busca_valor_placa2(a, placa)){
    return insere_ordenado(lista, ano, placa, marca);
  }
  printf("O carro acima foi cadastrado com essa placa\n");
  return NULL;
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

obj *placa_busca_excluir(char placa[], arv *a){
	int aux;
	if (!esta_vazia_arv(a)){
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

obj *busca_excluir(arv *a){
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
  printf("1 - Inserir veiculo\n");
  printf("2 - Listar veiculos\n");
  printf("3 - Buscar veiculo\n");
  printf("4 - Remover veiculo\n");
  printf("5 - Sair\n");
  int op;
  scanf("%d", &op);
  while(op > 5 || op <= 0){
    printf("Operacao invalida, tente novamente\n");
    scanf("%d", &op);
  }
  return op;
}

int menu_listar(){
  printf("----- SUBMENU ----\n");
  printf("1 - placa (lista)\n");
  printf("2 - marca (arvore)\n");
  printf("3 - ano (arvore)\n");
  int op;
  scanf("%d", &op);
  while(op > 3 || op <= 0){
    printf("Operacao invalida, tente novamente\n");
    scanf("%d", &op);
  }
  return op;
}

void main(){
  arv *raiz_marca = cria_arv_vazia();
  arv *raiz_ano = cria_arv_vazia();
  arv *raiz_placa = cria_arv_vazia();
  struct l_descr l_carros;
  inicializa_lista(&l_carros);
  struct carro *jc;
  obj *carro = NULL;
  int op = menu();
  int op2;
  int indice;
  while(op <= 5){
    switch(op){
      case 1:
        jc = le_carros(&l_carros, raiz_placa);
        if (jc == NULL){
          op = menu();
          break;
        }
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
            printf("---- LISTA ORDENADA POR PLACA ----\n");
            imprime_lista(&l_carros);
            op = menu();
          break;
          case 2:
            printf("---- LISTA ORDENADA POR MARCA ----\n");
            imprime_arv(raiz_marca);
            op = menu();
          break;
          case 3:
            printf("---- LISTA ORDENADA POR ANO ----\n");
            imprime_arv(raiz_ano);
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
          remove_indice(&l_carros, indice);
          remove_placa(raiz_placa, carro);
          remove_marca(raiz_marca, carro);
          remove_ano(raiz_ano, carro);
          free(carro);
        }          
        op = menu();
      break;
      case 5:
        raiz_marca = liberar_arv(raiz_marca);
        raiz_ano = liberar_arv(raiz_ano);
        raiz_placa = liberar_arv(raiz_placa);
        int indice_delete = l_carros.cnt - 1;
        while(indice_delete >= 0){
            remove_indice(&l_carros, indice_delete);
            indice_delete--;
        }
        return;
      break;
    }
  }
}

