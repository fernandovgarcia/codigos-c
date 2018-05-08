//Aluno: Fernando Vedoin Garcia
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//DECLARAÇÃO DAS ESTRUTURAS
struct no_alunos{
  int matricula;
  char nome[50];
  char curso[50];
  struct no_alunos *proximo;
};

struct lista_alunos{
	struct no_alunos *inicio;
	int cnt;
	struct no_alunos *fim;
};

struct no_profs{
  int siape;
  char nome[50];
  char area[50];
  char titulacao[50];
  struct no_profs *proximo;
};

struct lista_profs{
  struct no_profs *inicio;
  int cnt;
  struct no_profs *fim;
};

struct no_discs{
  int codigo;
  int ch;
  char curso[50];
  char nome[50];
  char pre_requisito[50];
  struct no_discs *proximo;
};

struct lista_discs{
  struct no_discs *inicio;
  int cnt;
  struct no_discs *fim;
};

struct no_cursos{
  int codigo;
  char nome[50];
  struct no_cursos *proximo;
};

struct lista_cursos{
  struct no_cursos *inicio;
  int cnt;
  struct no_cursos *fim;
};

struct no_aluno_turma{
  int matricula;
  struct no_aluno_turma *proximo_aluno;
};

struct no_prof_turma{
  int siape;
  struct no_prof_turma *proximo_prof;
};

struct no_turmas{
  struct no_aluno_turma *primeiro_aluno;
  struct no_prof_turma *primeiro_prof;
  int codigo;
  int n_alunos;
  int n_prof;
  int disc;
  struct no_turmas *proximo;
  struct no_aluno_turma *ultimo_aluno;
  struct no_prof_turma *ultimo_prof;
};

struct lista_turmas{
  struct no_turmas *inicio;
  int cnt;
  struct no_turmas *fim;
};

struct no_avaliacoes{ 
  int matricula; 
  int turma;
  float nota1; 
  float nota2; 
  struct no_avaliacoes *proximo; 
}; 
 
struct lista_avaliacoes{ 
  struct no_avaliacoes *inicio; 
  int cnt; 
  struct no_avaliacoes *fim; 
}; 

struct no_faltas{
  int matricula;
  struct no_faltas *proximo;
};

struct no_aulas{
  struct no_faltas *primeira_falta;
  int id;
  int dia;
  int mes;
  int ano;
  int turma;
  int cod_disc;
  char conteudo[200];
  struct no_aulas *proximo;
  struct no_faltas *ultima_falta;
};

struct lista_aulas{
  struct no_aulas *inicio;
  int cnt;
  struct no_aulas *fim;
};

//INICIALIZA LISTAS
void inicializa_lista_aluno(struct lista_alunos *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

void inicializa_lista_prof(struct lista_profs *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

void inicializa_lista_disc(struct lista_discs *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

void inicializa_lista_curso(struct lista_cursos *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

void inicializa_lista_turma(struct lista_turmas *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

void inicializa_lista_avaliacao(struct lista_avaliacoes *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

void inicializa_lista_aula(struct lista_aulas *lista) {
  lista->inicio=NULL;
  lista->cnt=0;
  lista->fim=NULL;
}

//VERIFICA SE LISTAS ESTÃO VAZIAS
int esta_vazia_aluno(struct lista_alunos *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

int esta_vazia_prof(struct lista_profs *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

int esta_vazia_disc(struct lista_discs *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

int esta_vazia_curso(struct lista_cursos *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

int esta_vazia_turma(struct lista_turmas *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

int esta_vazia_avaliacao(struct lista_avaliacoes *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

int esta_vazia_aula(struct lista_aulas *lista) {
  if (lista->inicio==NULL) {
    return 1;
  } else {
    return 0;
  }
}

//TIRA ENTER DO FINAL DA STRING
void tira_enter_do_final(char s[]){
  int p = strlen(s)-1;
  if (s[p] == '\n'){
    s[p] = '\0';
  }
}

//IMPRIME LISTAS
void imprime_lista_aluno(struct lista_alunos *lista) {
  struct no_alunos *aux = lista->inicio;
  while(aux!=NULL) {
    printf("Aluno: %s   Matricula: %d   Curso: %s\n", aux->nome, aux->matricula, aux->curso);
    aux = aux->proximo;
  }
}



void imprime_lista_prof(struct lista_profs *lista) {
  struct no_profs *aux = lista->inicio;
  while(aux!=NULL) {
    printf("Prof: %s   siape: %d   Area: %s   Titulacao: %s\n", aux->nome, aux->siape, aux->area, aux->titulacao);
    aux = aux->proximo;
  }
}

void imprime_lista_disc(struct lista_discs *lista) {
  struct no_discs *aux = lista->inicio;
  while(aux!=NULL) {
    printf("codigo: %d   ch: %d   curso: %s   nome: %s   pre_requisito: %s\n", aux->codigo, aux->ch, aux->curso, aux->nome, aux->pre_requisito);
    aux = aux->proximo;
  }
}

void imprime_lista_curso(struct lista_cursos *lista) {
  struct no_cursos *aux = lista->inicio;
  while(aux!=NULL) {
    printf("curso: %s   codigo: %d\n", aux->nome, aux->codigo);
    aux = aux->proximo;
  }
}

void imprime_lista_turma(struct lista_turmas *lista) {
  struct no_turmas *aux = lista->inicio;
  struct no_aluno_turma *aluno;
  struct no_prof_turma *prof;
  while(aux!=NULL) {
    aluno = aux->primeiro_aluno;
    prof = aux->primeiro_prof;
    printf("CODIGO: %d   N ALUNOS: %d   N PROFS: %d\n", aux->codigo, aux->n_alunos, aux->n_prof);
    if(aluno == NULL){
      printf("  A turma nao tem alunos\n");
    }
    while(aluno != NULL){
      printf("  matricula: %d\n", aluno->matricula);
      aluno = aluno->proximo_aluno;
    }
    if(prof == NULL){
      printf("  A turma nao tem professores\n");
    }
    while(prof != NULL){
      printf("  siape: %d\n", prof->siape);
      prof = prof->proximo_prof;
    }
    aux = aux->proximo;
  }
}

void imprime_lista_avaliacao(struct lista_avaliacoes *lista) {
  struct no_avaliacoes *aux = lista->inicio;
  while(aux!=NULL) {
    printf("Matricula: %d   Nota1: %f   Nota2: %f\n", aux->matricula, aux->nota1, aux->nota2);
    aux = aux->proximo;
  }
}

void imprime_lista_aula(struct lista_aulas *lista) {
  struct no_aulas *aux = lista->inicio;
  struct no_faltas *aux2;
  if(aux == NULL){
    printf("NAO TEM AULAS\n");
    return;
  }
  while(aux!=NULL) {
    printf("ID: %d  Turma: %d  Conteudo: %s  Data: %d/%d/%d  Disc: %d\n", aux->id, aux->turma, aux->conteudo, aux->dia, aux->mes, aux->ano, aux->cod_disc);
    aux2 = aux->primeira_falta;
    if(aux2 == NULL){
      printf("NAO TEM FALTAS\n");
    }else{
      while(aux2 != NULL){
        printf("  Matricula do aluno ausente: %d\n", aux2->matricula);
        if(aux2 == aux->ultima_falta){
          break;
        }
        aux2 = aux2->proximo;
      }
    }
    aux = aux->proximo;
  }
}

//REMOVE ALUNOS
int remove_aluno_primeiro(struct lista_alunos *lista) {
  if (esta_vazia_aluno(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->matricula;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      int valor = lista->inicio->matricula;
      struct no_alunos *segundo = lista->inicio->proximo;
      free(lista->inicio);
      lista->inicio = segundo;
      lista->cnt--;
      return valor;
    }
  }
  return -1;
}

int remove_aluno_ultimo(struct lista_alunos *lista) {
  if (esta_vazia_aluno(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->matricula;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      struct no_alunos *penultimo = lista->inicio;
      struct no_alunos *ultimo = lista->fim;
      int valor_ultimo = lista->fim->matricula;
      while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
      }
      penultimo->proximo = NULL;
      lista->fim = penultimo;
      free(ultimo);
      lista->cnt--;
      return valor_ultimo;
    }
  }
  return -1;
}

int remove_aluno_indice(struct lista_alunos *lista,int indice) {
  if (esta_vazia_aluno(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (indice>=lista->cnt || indice<0) {
      printf("A lista nao possui valor nesse indice\n");
      return -1;
    } else {
      if (indice==0) {
        return remove_aluno_primeiro(lista);
      } else if (indice==lista->cnt-1) {
        return remove_aluno_ultimo(lista);
      }
      struct no_alunos *valor = lista->inicio;
      int cont=1;
      while(cont<indice){
        valor = valor->proximo;
        cont++;
      }
      struct no_alunos *proximo = valor->proximo->proximo;
      int valor_elemento = valor->proximo->matricula;
      free(valor->proximo);
      valor->proximo = proximo;
      lista->cnt--;
      return valor_elemento;
    }
  }
  return -1;
}

//REMOVE PROFESSORES
int remove_prof_primeiro(struct lista_profs *lista) {
  if (esta_vazia_prof(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->siape;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      int valor = lista->inicio->siape;
      struct no_profs *segundo = lista->inicio->proximo;
      free(lista->inicio);
      lista->inicio = segundo;
      lista->cnt--;
      return valor;
    }
  }
  return -1;
}

int remove_prof_ultimo(struct lista_profs *lista) {
  if (esta_vazia_prof(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->siape;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      struct no_profs *penultimo = lista->inicio;
      struct no_profs *ultimo = lista->fim;
      int valor_ultimo = lista->fim->siape;
      while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
      }
      penultimo->proximo = NULL;
      lista->fim = penultimo;
      free(ultimo);
      lista->cnt--;
      return valor_ultimo;
    }
  }
  return -1;
}

int remove_prof_indice(struct lista_profs *lista,int indice) {
  if (esta_vazia_prof(lista) == 1) {
    printf("A lista esta vazia\n");
    return -1;
  } else {
    if (indice>=lista->cnt || indice<0) {
      printf("A lista nao possui valor nesse indice\n");
      return -1;
    } else {
      if (indice==0) {
        return remove_prof_primeiro(lista);
      } else if (indice==lista->cnt-1) {
        return remove_prof_ultimo(lista);
      }
      struct no_profs *valor = lista->inicio;
      int cont=1;
      while(cont<indice){
        valor = valor->proximo;
        cont++;
      }
      struct no_profs *proximo = valor->proximo->proximo;
      int valor_elemento = valor->proximo->siape;
      free(valor->proximo);
      valor->proximo = proximo;
      lista->cnt--;
      return valor_elemento;
    }
  }
  return -1;
}

//REMOVE TURMAS
int remove_turma_primeiro(struct lista_turmas *lista) {
  if (esta_vazia_turma(lista) == 1) {
    printf("A lista de turmas esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->codigo;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      int valor = lista->inicio->codigo;
      struct no_turmas *segundo = lista->inicio->proximo;
      free(lista->inicio);
      lista->inicio = segundo;
      lista->cnt--;
      return valor;
    }
  }
  return -1;
}

int remove_turma_ultimo(struct lista_turmas *lista) {
  if (esta_vazia_turma(lista) == 1) {
    printf("A lista de turmas esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->codigo;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      struct no_turmas *penultimo = lista->inicio;
      struct no_turmas *ultimo = lista->fim;
      int valor_ultimo = lista->fim->codigo;
      while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
      }
      penultimo->proximo = NULL;
      lista->fim = penultimo;
      free(ultimo);
      lista->cnt--;
      return valor_ultimo;
    }
  }
  return -1;
}

int remove_turma_indice(struct lista_turmas *lista,int indice) {
  if (esta_vazia_turma(lista) == 1) {
    printf("A lista de turmas esta vazia\n");
    return -1;
  } else {
    if (indice>=lista->cnt || indice<0) {
      printf("A lista nao possui valor nesse indice\n");
      return -1;
    } else {
      if (indice==0) {
        return remove_turma_primeiro(lista);
      } else if (indice==lista->cnt-1) {
        return remove_turma_ultimo(lista);
      }
      struct no_turmas *valor = lista->inicio;
      int cont=1;
      while(cont<indice){
        valor = valor->proximo;
        cont++;
      }
      struct no_turmas *proximo = valor->proximo->proximo;
      int valor_elemento = valor->proximo->codigo;
      free(valor->proximo);
      valor->proximo = proximo;
      lista->cnt--;
      return valor_elemento;
    }
  }
  return -1;
}

//REMOVE DISCIPLINAS
int remove_disc_primeiro(struct lista_discs *lista) {
  if (esta_vazia_disc(lista) == 1) {
    printf("A lista de disciplinas esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->codigo;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      int valor = lista->inicio->codigo;
      struct no_discs *segundo = lista->inicio->proximo;
      free(lista->inicio);
      lista->inicio = segundo;
      lista->cnt--;
      return valor;
    }
  }
  return -1;
}

int remove_disc_ultimo(struct lista_discs *lista) {
  if (esta_vazia_disc(lista) == 1) {
    printf("A lista de disciplinas esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->codigo;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      struct no_discs *penultimo = lista->inicio;
      struct no_discs *ultimo = lista->fim;
      int valor_ultimo = lista->fim->codigo;
      while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
      }
      penultimo->proximo = NULL;
      lista->fim = penultimo;
      free(ultimo);
      lista->cnt--;
      return valor_ultimo;
    }
  }
  return -1;
}

int remove_disc_indice(struct lista_discs *lista, int indice) {
  if (esta_vazia_disc(lista) == 1) {
    printf("A lista de disciplinas esta vazia\n");
    return -1;
  } else {
    if (indice >= lista->cnt || indice < 0) {
      printf("A lista nao possui valor nesse indice\n");
      return -1;
    } else {
      printf("indice: %d", indice);
      if (indice == 0) {
        return remove_disc_primeiro(lista);
      } else if (indice == lista->cnt-1) {
        return remove_disc_ultimo(lista);
      }
      struct no_discs *valor = lista->inicio;
      int cont=1;
      while(cont<indice){
        valor = valor->proximo;
        cont++;
      }
      struct no_discs *proximo = valor->proximo->proximo;
      int valor_elemento = valor->proximo->codigo;
      free(valor->proximo);
      valor->proximo = proximo;
      lista->cnt--;
      return valor_elemento;
    }
  }
  return -1;
}

//REMOVE CURSOS
int remove_curso_primeiro(struct lista_cursos *lista) {
  if (esta_vazia_curso(lista) == 1) {
    printf("A lista de cursos esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->codigo;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      int valor = lista->inicio->codigo;
      struct no_cursos *segundo = lista->inicio->proximo;
      free(lista->inicio);
      lista->inicio = segundo;
      lista->cnt--;
      return valor;
    }
  }
  return -1;
}

int remove_curso_ultimo(struct lista_cursos *lista) {
  if (esta_vazia_curso(lista) == 1) {
    printf("A lista de cursos esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->codigo;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      struct no_cursos *penultimo = lista->inicio;
      struct no_cursos *ultimo = lista->fim;
      int valor_ultimo = lista->fim->codigo;
      while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
      }
      penultimo->proximo = NULL;
      lista->fim = penultimo;
      free(ultimo);
      lista->cnt--;
      return valor_ultimo;
    }
  }
  return -1;
}

int remove_curso_indice(struct lista_cursos *lista,int indice) {
  if (esta_vazia_curso(lista) == 1) {
    printf("A lista de cursos esta vazia\n");
    return -1;
  } else {
    if (indice>=lista->cnt || indice<0) {
      printf("A lista nao possui valor nesse indice\n");
      return -1;
    } else {
      if (indice==0) {
        return remove_curso_primeiro(lista);
      } else if (indice==lista->cnt-1) {
        return remove_curso_ultimo(lista);
      }
      struct no_cursos *valor = lista->inicio;
      int cont=1;
      while(cont<indice){
        valor = valor->proximo;
        cont++;
      }
      struct no_cursos *proximo = valor->proximo->proximo;
      int valor_elemento = valor->proximo->codigo;
      free(valor->proximo);
      valor->proximo = proximo;
      lista->cnt--;
      return valor_elemento;
    }
  }
  return -1;
}

//REMOVE AVALIACOES
int remove_avaliacao_primeiro(struct lista_avaliacoes *lista) {
  if (esta_vazia_avaliacao(lista) == 1) {
    printf("A lista de avaliacoes esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->matricula;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      int valor = lista->inicio->matricula;
      struct no_avaliacoes *segundo = lista->inicio->proximo;
      free(lista->inicio);
      lista->inicio = segundo;
      lista->cnt--;
      return valor;
    }
  }
  return -1;
}

int remove_avaliacao_ultimo(struct lista_avaliacoes *lista) {
  if (esta_vazia_avaliacao(lista) == 1) {
    printf("A lista de avaliacoes esta vazia\n");
    return -1;
  } else {
    if (lista->inicio->proximo == NULL) {
      int valor = lista->inicio->matricula;
      free(lista->inicio);
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->cnt = 0;
      return valor;
    } else {
      struct no_avaliacoes *penultimo = lista->inicio;
      struct no_avaliacoes *ultimo = lista->fim;
      int valor_ultimo = lista->fim->matricula;
      while (penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
      }
      penultimo->proximo = NULL;
      lista->fim = penultimo;
      free(ultimo);
      lista->cnt--;
      return valor_ultimo;
    }
  }
  return -1;
}

int remove_avaliacao_indice(struct lista_avaliacoes *lista,int indice) {
  if (esta_vazia_avaliacao(lista) == 1) {
    printf("A lista de avaliacoes esta vazia\n");
    return -1;
  } else {
    if (indice>=lista->cnt || indice<0) {
      printf("A lista nao possui valor nesse indice\n");
      return -1;
    } else {
      if (indice==0) {
        return remove_avaliacao_primeiro(lista);
      } else if (indice==lista->cnt-1) {
        return remove_avaliacao_ultimo(lista);
      }
      struct no_avaliacoes *valor = lista->inicio;
      int cont=1;
      while(cont<indice){
        valor = valor->proximo;
        cont++;
      }
      struct no_avaliacoes *proximo = valor->proximo->proximo;
      int valor_elemento = valor->proximo->matricula;
      free(valor->proximo);
      valor->proximo = proximo;
      lista->cnt--;
      return valor_elemento;
    }
  }
  return -1;
}

int exclui_avaliacao_aluno(struct lista_avaliacoes *lista, int matricula){
  struct no_avaliacoes *aux = lista->inicio;
  int i = 0;
  while(aux != NULL){
    if(aux->matricula == matricula){
      remove_avaliacao_indice(lista, i);
    }
    aux = aux->proximo;
    i++;
  }
}

int desmatricula_primeiro_aluno(struct lista_turmas *lista, int turma){
  struct no_turmas *aux = lista->inicio;
  while(aux != NULL){
    if(aux->codigo == turma){
      break;
    }
    aux = aux->proximo;
  }
  if (aux->primeiro_aluno->proximo_aluno == NULL) {
    int valor = aux->primeiro_aluno->matricula;
    free(aux->primeiro_aluno);
    aux->primeiro_aluno = NULL;
    aux->ultimo_aluno = NULL;
    aux->n_alunos = 0;
    return valor;
  } else {
    int valor = aux->primeiro_aluno->matricula;
    struct no_aluno_turma *segundo = aux->primeiro_aluno->proximo_aluno;
    free(aux->primeiro_aluno);
    aux->primeiro_aluno = segundo;
    aux->n_alunos--;
    return valor;
  }
}

int desmatricula_ultimo_aluno(struct lista_turmas *lista, int turma){
  struct no_turmas *aux = lista->inicio;
  while(aux != NULL){
    if(aux->codigo == turma){
      break;
    }
    aux = aux->proximo;
  }
  if (aux->primeiro_aluno->proximo_aluno == NULL) {
    int valor = aux->primeiro_aluno->matricula;
    free(aux->primeiro_aluno);
    aux->primeiro_aluno = NULL;
    aux->ultimo_aluno = NULL;
    aux->n_alunos = 0;
    return valor;
  } else {
    struct no_aluno_turma *penultimo = aux->primeiro_aluno;
    struct no_aluno_turma *ultimo = aux->ultimo_aluno;
    int valor_ultimo = aux->ultimo_aluno->matricula;
    while (penultimo->proximo_aluno->proximo_aluno != NULL) {
      penultimo = penultimo->proximo_aluno;
    }
    penultimo->proximo_aluno = NULL;
    aux->ultimo_aluno = penultimo;
    free(ultimo);
    aux->n_alunos--;
    return valor_ultimo;
  }
}

int desmatricula_aluno(struct lista_turmas *lista, int matricula, int turma){
  struct no_turmas *aux = lista->inicio;
  struct no_aluno_turma *aux2;
  int valor_elemento;
  while(aux != NULL){
    if(aux->primeiro_aluno != NULL){
      if(aux->codigo == turma){
        aux2 = aux->primeiro_aluno;
        if(aux->primeiro_aluno->matricula == matricula){
          desmatricula_primeiro_aluno(lista, turma);
        }else if(aux->ultimo_aluno->matricula == matricula){
          desmatricula_ultimo_aluno(lista, turma);
        }else{
          if(aux->n_alunos > 1){
            while(aux2->proximo_aluno->matricula != matricula){
              aux2 = aux2->proximo_aluno;
            }
            struct no_aluno_turma *proximo = aux2->proximo_aluno->proximo_aluno;
            free(aux2->proximo_aluno);
            aux2->proximo_aluno = proximo;
            aux->n_alunos--;
            return 1; 
          }
        }      
      }
    }    
    aux = aux->proximo;
  }
  return 0;
}

int desmatricula_primeiro_prof(struct lista_turmas *lista, int turma){
  struct no_turmas *aux = lista->inicio;
  while(aux != NULL){
    if(aux->codigo == turma){
      break;
    }
    aux = aux->proximo;
  }
  if (aux->primeiro_prof->proximo_prof == NULL) {
    int valor = aux->primeiro_prof->siape;
    free(aux->primeiro_prof);
    aux->primeiro_prof = NULL;
    aux->primeiro_prof = NULL;
    aux->n_prof--;
    return valor;
  } else {
    int valor = aux->primeiro_prof->siape;
    struct no_prof_turma *segundo = aux->primeiro_prof->proximo_prof;
    free(aux->primeiro_prof);
    aux->primeiro_prof = segundo;
    aux->n_prof--;
    return valor;
  }
}

int desmatricula_ultimo_prof(struct lista_turmas *lista, int turma){
  struct no_turmas *aux = lista->inicio;
  while(aux != NULL){
    if(aux->codigo == turma){
      break;
    }
    aux = aux->proximo;
  }
  if (aux->primeiro_prof->proximo_prof == NULL) {
    int valor = aux->primeiro_prof->siape;
    free(aux->primeiro_prof);
    aux->primeiro_prof = NULL;
    aux->ultimo_prof = NULL;
    aux->n_prof = 0;
    return valor;
  } else {
    struct no_prof_turma *penultimo = aux->primeiro_prof;
    struct no_prof_turma *ultimo = aux->ultimo_prof;
    int valor_ultimo = aux->ultimo_prof->siape;
    while (penultimo->proximo_prof->proximo_prof != NULL) {
      penultimo = penultimo->proximo_prof;
    }
    penultimo->proximo_prof = NULL;
    aux->ultimo_prof = penultimo;
    free(ultimo);
    aux->n_prof--;
    return valor_ultimo;
  }
}

int desmatricula_prof(struct lista_turmas *lista, int siape, int turma){
  struct no_turmas *aux = lista->inicio;
  struct no_prof_turma *aux2;
  int valor_elemento;
  while(aux != NULL){
    if(aux->codigo == turma){
      aux2 = aux->primeiro_prof;
      if(aux->primeiro_prof->siape == siape){
        desmatricula_primeiro_prof(lista, turma);
      }else if(aux->ultimo_prof->siape == siape){
        desmatricula_ultimo_prof(lista, turma);
      }else{
        if(aux->n_prof > 1){
          while(aux2->proximo_prof->siape != siape){
            aux2 = aux2->proximo_prof;
          }
          struct no_prof_turma *proximo = aux2->proximo_prof->proximo_prof;
          free(aux2->proximo_prof);
          aux2->proximo_prof = proximo;
          aux->n_prof--;
          return 1; 
        }
      }      
    }
    aux = aux->proximo;
  }
  return 0;
}

//VERIFICA SE EXISTE
int existe_aluno(struct lista_alunos *lista, int matricula){
  if(lista->inicio == NULL){
    return 0;
  }
  if(lista->inicio->matricula == matricula){
    return 1;
  }else if(lista->fim->matricula == matricula){
    return 1;
  }else{
    struct no_alunos *aux = lista->inicio;
    while(aux != NULL){
      if(aux->matricula == matricula){
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
  return 0;
}

int existe_profs(struct lista_profs *lista, int siape){
  if(lista->inicio == NULL){
    return 0;
  }
  if(lista->inicio->siape == siape){
    return 1;
  }else if(lista->fim->siape == siape){
    return 1;
  }else{
    struct no_profs *aux = lista->inicio;
    while(aux != NULL){
      if(aux->siape == siape){
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
  return 0;
}

int existe_curso(struct lista_cursos *lista, char nome[]){
  if(lista->inicio == NULL){
    return 0;
  }
  if(strcmp(lista->inicio->nome,nome) == 0){
    return 1;
  }else if(strcmp(lista->fim->nome, nome) == 0){
    return 1;
  }else{
    struct no_cursos *aux = lista->inicio;
    while(aux != NULL){
      if(strcmp(aux->nome,nome) == 0){
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
  return 0;
}

int existe_curso_id(struct lista_cursos *lista, int cod){
  if(lista->inicio == NULL){
    return 0;
  }
  if(lista->inicio->codigo == cod){
    return 1;
  }else if(lista->fim->codigo == cod){
    return 1;
  }else{
    struct no_cursos *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == cod){
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
  return 0;
}

int existe_aula(struct lista_aulas *lista, int id){
  if(lista->inicio == NULL){
    return 0;
  }
  if(lista->inicio->id == id){
    return 1;
  }else if(lista->fim->id == id){
    return 1;
  }else{
    struct no_aulas *aux = lista->inicio;
    while(aux != NULL){
      if(aux->id == id){
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
  return 0;
}

int existe_disc(struct lista_discs *lista, int id){
  if(lista->inicio == NULL){
    return 0;
  }
  if(lista->inicio->codigo == id){
    return 1;
  }else if(lista->fim->codigo == id){
    return 1;
  }else{
    struct no_discs *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == id){
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
  return 0;
}

int existe_turma(struct lista_turmas *lista, int id){
  if(lista->inicio == NULL){
    return 0;
  }
  if(lista->inicio->codigo == id){
    return 1;
  }else if(lista->fim->codigo == id){
    return 1;
  }else{
    struct no_turmas *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == id){
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
  return 0;
}

int aluno_turma(struct lista_turmas *lista, int matricula){
  struct no_turmas *aux = lista->inicio;
  struct no_aluno_turma *aux2;
  while(aux != NULL){
    aux2 = aux->primeiro_aluno;
    while(aux2 != NULL){
      if(aux2->matricula == matricula){
        return aux->codigo;
      }
      aux2 = aux2->proximo_aluno;
    }
    aux = aux->proximo;
  }
  return 0;
}

int aluno_turma2(struct lista_turmas *lista, int matricula, int turma){
  struct no_turmas *aux = lista->inicio;
  struct no_aluno_turma *aux2;
  while(aux != NULL){
    if(aux->codigo == turma){
      aux2 = aux->primeiro_aluno;
      while(aux2 != NULL){
        if(aux2->matricula == matricula){
          return aux->codigo;
        }
        aux2 = aux2->proximo_aluno;
      }
    }
    aux = aux->proximo;
  }
  return 0;
}

int verifica_prof_turma(struct lista_turmas *lista, int siape){
  struct no_turmas *aux = lista->inicio;
  struct no_prof_turma *aux2;
  while(aux != NULL){
    aux2 = aux->primeiro_prof;
    while(aux2 != NULL){
      if(aux2->siape == siape){
        return aux->codigo;
      }
      aux2 = aux2->proximo_prof;
    }
    aux = aux->proximo;
  }
  return 0;
}

//VERIFICA SE O ALUNO FOI APROVADO POR NOTA
bool verifica_aprovacao(struct lista_avaliacoes *lista, int matricula){
  float notas;
  struct no_avaliacoes *aux = lista->inicio;
  while(aux!=NULL) {
    if(aux->matricula == matricula){
      notas = aux->nota1 + aux->nota2;
    }
    aux = aux->proximo;
  }
  float media = notas/2.0;
  if(media >= 7){
    printf("Aluno aprovado\n");
    return true;
  }else{
    printf("Aluno reprovado\n");
    return false;
  }
}

//INSERE ALUNOS
void insere_alunos_lista_nula(struct lista_alunos *lista, char curso[], char nome[], int matricula) {
  lista->inicio = malloc(sizeof(struct no_alunos));
  strcpy(lista->inicio->nome, nome);
  strcpy(lista->inicio->curso, curso);
  lista->inicio->matricula = matricula;
  lista->inicio->proximo = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
}

void insere_alunos_inicio(struct lista_alunos *lista, char curso[], char nome[], int matricula) {
  if (esta_vazia_aluno(lista)==1) {
    insere_alunos_lista_nula(lista, curso, nome, matricula);
  } else {
    struct no_alunos *novo = malloc(sizeof(struct no_alunos));
    strcpy(novo->nome, nome);
    strcpy(novo->curso, curso);
    novo->matricula = matricula;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->cnt++;
  }
}

//INSERE PROFESSORES
void insere_profs_lista_nula(struct lista_profs *lista, char titulacao[], char area[], char nome[], int siape) {
  lista->inicio = malloc(sizeof(struct no_profs));
  strcpy(lista->inicio->nome, nome);
  strcpy(lista->inicio->area, area);
  strcpy(lista->inicio->titulacao, titulacao);
  lista->inicio->siape = siape;
  lista->inicio->proximo = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
}

void insere_profs_inicio(struct lista_profs *lista, char titulacao[], char area[], char nome[], int siape) {
  if (esta_vazia_prof(lista)==1) {
    insere_profs_lista_nula(lista, titulacao, area, nome, siape);
  } else {
    struct no_profs *novo = malloc(sizeof(struct no_profs));
    strcpy(novo->nome, nome);
    strcpy(novo->area, area);  
    strcpy(novo->titulacao, titulacao);
    novo->siape = siape;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->cnt++;
  }
}

//INSERE DISCIPLINAS
void insere_discs_lista_nula(struct lista_discs *lista, char pre_requisito[], char curso[], char nome[], int codigo, int ch) {
  lista->inicio = malloc(sizeof(struct no_discs));
  strcpy(lista->inicio->nome, nome);
  strcpy(lista->inicio->curso, curso);
  strcpy(lista->inicio->pre_requisito, pre_requisito);
  lista->inicio->codigo = codigo;
  lista->inicio->ch = ch;
  lista->inicio->proximo = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
}

void insere_discs_inicio(struct lista_discs *lista, char curso[], char pre_requisito[], char nome[], int codigo, int ch) {
  if (esta_vazia_disc(lista)==1) {
    insere_discs_lista_nula(lista, pre_requisito, curso, nome, codigo, ch);
  } else {
    struct no_discs *novo = malloc(sizeof(struct no_discs));
    strcpy(novo->nome, nome);
    strcpy(novo->curso, curso);  
    strcpy(novo->pre_requisito, pre_requisito);
    novo->codigo = codigo;
    novo->ch = ch;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->cnt++;
  }
}

//INSERE CURSOS
void insere_cursos_lista_nula(struct lista_cursos *lista, char nome[], int codigo) {
  lista->inicio = malloc(sizeof(struct no_cursos));
  strcpy(lista->inicio->nome, nome);
  lista->inicio->codigo = codigo;
  lista->inicio->proximo = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
}

void insere_cursos_inicio(struct lista_cursos *lista, char nome[], int codigo) {
  if (esta_vazia_curso(lista)==1) {
    insere_cursos_lista_nula(lista, nome, codigo);
  } else {
    struct no_cursos *novo = malloc(sizeof(struct no_cursos));
    strcpy(novo->nome, nome);
    novo->codigo = codigo;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->cnt++;
  }
}

//INSERE TURMAS
void insere_turmas_lista_nula(struct lista_turmas *lista, int codigo, int disc) {
  lista->inicio = malloc(sizeof(struct no_turmas));
  lista->inicio->codigo = codigo;
  lista->inicio->disc = disc;
  lista->inicio->n_alunos = 0;
  lista->inicio->n_prof = 0;
  lista->inicio->proximo = NULL;
  lista->inicio->primeiro_aluno = NULL;
  lista->inicio->ultimo_aluno = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
}

void insere_turmas_inicio(struct lista_turmas *lista, int codigo, int disc) {
  if (esta_vazia_turma(lista)==1) {
    insere_turmas_lista_nula(lista, codigo, disc);
  } else {
    struct no_turmas *novo = malloc(sizeof(struct no_turmas));
    novo->codigo = codigo;
    novo->n_alunos = 0;
    novo->n_prof = 0;
    novo->disc = disc;
    novo->primeiro_aluno = NULL;
    novo->ultimo_aluno = NULL;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->cnt++;
  }
}

//INSERE AVALIACOES
void insere_avaliacoes_lista_nula(struct lista_avaliacoes *lista, int matricula, float nota1, float nota2, int turma) {
  lista->inicio = malloc(sizeof(struct no_avaliacoes));
  lista->inicio->matricula = matricula;
  lista->inicio->nota1 = nota1;
  lista->inicio->nota2 = nota2;
  lista->inicio->turma = turma;
  lista->inicio->proximo = NULL;
  lista->cnt = 1;
  lista->fim = lista->inicio;
}

void insere_avaliacoes_inicio(struct lista_avaliacoes *lista, int matricula, float nota1, float nota2, int turma) {
  if (esta_vazia_avaliacao(lista)==1) {
    insere_avaliacoes_lista_nula(lista, matricula, nota1, nota2, turma);
  } else {
    struct no_avaliacoes *novo = malloc(sizeof(struct no_avaliacoes));
    novo->matricula = matricula;
    novo->nota1 = nota1;
    novo->nota2 = nota2;
    novo->turma = turma;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->cnt++;
  }
}

//INSERE ALUNO NA TURMA
void insere_aluno_turmas_lista_nula(struct lista_turmas *lista, int matricula, int turma) {
  struct no_turmas *aux = lista->inicio;
  int cont = 0;
  while(aux!=NULL) {
    if(aux->codigo == turma){
      cont++;
      break;
    }
    aux = aux->proximo;
  }
  if(cont > 0){
    aux->primeiro_aluno = malloc(sizeof(struct no_aluno_turma));
    aux->primeiro_aluno->matricula = matricula;
    aux->ultimo_aluno = NULL;
    aux->n_alunos = 1;
    aux->ultimo_aluno = aux->primeiro_aluno;
  }else{
    printf("Turma nao existe\n");
  }
  printf("O aluno %d foi adicionado na turma %d que tem %d aluno\n", aux->primeiro_aluno->matricula, aux->codigo, aux->n_alunos);
}

void insere_aluno_turmas_inicio(struct lista_turmas *lista, int matricula, int turma) {
  struct no_turmas *aux = lista->inicio;
  int cont = 0;
  while(aux!=NULL) {
    if(aux->codigo == turma){
      cont++;
      break;
    }
    aux = aux->proximo;
  }
  if(cont > 0){
    if(aux->primeiro_aluno == NULL){
      insere_aluno_turmas_lista_nula(lista, matricula, turma);
    }else{
      if(aux->n_alunos+1 <= 50){
        struct no_aluno_turma *novo = malloc(sizeof(struct no_aluno_turma));
        novo->matricula = matricula;
        novo->proximo_aluno = aux->primeiro_aluno;
        aux->primeiro_aluno = novo;
        aux->n_alunos++;
        printf("O aluno %d foi adicionado na turma %d que tem %d alunos\n", aux->primeiro_aluno->matricula, aux->codigo, aux->n_alunos);
      }else{
        printf("A turma pode ter, no maximo, 50 alunos\n");
      }
    }    
  }else{
    printf("A turma nao existe\n");
  }
}

//INSERE PROF NA TURMA
void insere_prof_turmas_lista_nula(struct lista_turmas *lista, int siape, int turma) {
  struct no_turmas *aux = lista->inicio;
  int cont = 0;
  while(aux!=NULL) {
    if(aux->codigo == turma){
      cont++;
      break;
    }
    aux = aux->proximo;
  }
  if(cont > 0){
    aux->primeiro_prof = malloc(sizeof(struct no_prof_turma));
    aux->primeiro_prof->siape = siape;
    aux->ultimo_prof = NULL;
    aux->ultimo_prof = aux->primeiro_prof;
    aux->n_prof = 1;
  }else{
    printf("Turma nao existe\n");
  }
  printf("O prof %d foi adicionado na turma %d\n", aux->primeiro_prof->siape, aux->codigo);
}

void insere_prof_turmas_inicio(struct lista_turmas *lista, int siape, int turma) {
  struct no_turmas *aux = lista->inicio;
  int cont = 0;
  while(aux!=NULL) {
    if(aux->codigo == turma){
      cont++;
      break;
    }
    aux = aux->proximo;
  }
  if(cont > 0){
    if(aux->primeiro_prof == NULL){
      insere_prof_turmas_lista_nula(lista, siape, turma);
    }else{
      if(aux->n_alunos+1 <= 50){
        struct no_prof_turma *novo = malloc(sizeof(struct no_prof_turma));
        novo->siape = siape;
        novo->proximo_prof = aux->primeiro_prof;
        aux->primeiro_prof = novo;
        aux->n_prof++;
        printf("O prof %d foi adicionado na turma %d\n", aux->primeiro_prof->siape, aux->codigo);
      }else{
        printf("A turma pode ter, no maximo, 50 alunos\n");
      }
    }    
  }else{
    printf("A turma nao existe\n");
  }
}

//INSERE AULAS
void insere_aulas_lista_nula(struct lista_aulas *lista, char conteudo[], int turma, int cod_disc, int dia, int mes, int ano) {
  lista->inicio = malloc(sizeof(struct no_aulas));
  strcpy(lista->inicio->conteudo, conteudo);
  lista->inicio->turma = turma;
  lista->inicio->cod_disc = cod_disc;
  lista->inicio->dia = dia;
  lista->inicio->mes = mes;
  lista->inicio->ano = ano;
  lista->inicio->id = 1;
  lista->inicio->proximo = NULL;
  lista->inicio->primeira_falta = NULL;
  lista->inicio->ultima_falta = NULL; 
  lista->cnt = 1;
  lista->fim = lista->inicio;
  printf("Aula inserida com id 1\n");
}

void insere_aulas_inicio(struct lista_aulas *lista, char conteudo[], int turma, int cod_disc, int dia, int mes, int ano) {
  if (esta_vazia_aula(lista)==1) {
    insere_aulas_lista_nula(lista, conteudo, turma, cod_disc, dia, mes, ano);
  } else {
    int id;
    id = lista->inicio->id;
    struct no_aulas *novo = malloc(sizeof(struct no_aulas));
    strcpy(novo->conteudo, conteudo);
    novo->turma = turma;
    novo->cod_disc = cod_disc;
    novo->dia = dia;
    novo->mes = mes;
    novo->ano = ano;
    novo->id = id+1;
    novo->proximo = lista->inicio;
    novo->primeira_falta = NULL;
    novo->ultima_falta = NULL; 
    lista->inicio = novo;
    lista->cnt++;
    printf("Aula inserida com id %d\n", id+1);
  }
}

//INSERE FALTA NAS AULAS
void insere_falta_aulas_lista_nula(struct lista_aulas *lista, int matricula, int id) {
  struct no_aulas *aux = lista->inicio;
  int cont = 0;
  while(aux!=NULL) {
    if(aux->id == id){
      cont++;
      break;
    }
    aux = aux->proximo;
  }
  if(cont > 0){
    aux->primeira_falta = malloc(sizeof(struct no_faltas));
    aux->primeira_falta->matricula = matricula;
    aux->ultima_falta = aux->primeira_falta;
  }else{
    printf("Turma nao existe\n");
  }
  printf("O aluno %d ganhou falta\n", aux->primeira_falta->matricula);
}

void insere_falta_aulas_inicio(struct lista_aulas *lista, int matricula, int id) {
  struct no_aulas *aux = lista->inicio;
  int cont = 0;
  while(aux!=NULL) {
    if(aux->id == id){
      cont++;
      break;
    }
    aux = aux->proximo;
  }
  if(cont > 0){
    if(aux->primeira_falta == NULL){
      insere_falta_aulas_lista_nula(lista, matricula, id);
    }else{
      struct no_faltas *novo = malloc(sizeof(struct no_faltas));
      novo->matricula = matricula;   
      novo->proximo = aux->primeira_falta;
      aux->primeira_falta = novo;     
    }    
  }else{
    printf("A turma nao existe\n");
  }
}

//ENTRADA DE DADOS
void le_cursos(struct lista_cursos *lista){
  char nome[50];
  int codigo;
  printf("Codigo do curso: ");
  scanf("%d", &codigo);
  getchar();
  printf("Nome do curso: ");
  fgets(nome, 50, stdin);
  tira_enter_do_final(nome);
  if(existe_curso_id(lista, codigo) == 1){
    printf("Um curso ja foi cadastrado com esse codigo\n");
    return;
  }
  insere_cursos_inicio(lista, nome, codigo);
  printf("Curso cadastrado com sucesso!\n");
}

void le_alunos(struct lista_alunos *lista, struct lista_cursos *l_cursos){
  char nome[50], curso[50];
  int matricula;
  printf("Matricula do aluno: ");
  scanf("%d", &matricula);
  getchar();
  printf("Nome do aluno: ");
  fgets(nome, 50, stdin);
  tira_enter_do_final(nome);
  if(esta_vazia_curso(l_cursos) == 1){
    printf("Nao tem nenhum curso cadastrado. Cadastre um curso:\n");
    le_cursos(l_cursos);
  }
  printf("Curso do aluno: ");
  fgets(curso, 50, stdin);
  tira_enter_do_final(curso);
  if(existe_aluno(lista, matricula)){
    printf("Matricula ja cadastrada\n");
    return;
  }
  if(existe_curso(l_cursos, curso) == 0){
    printf("Curso nao existe\n");
    return;
  }
  insere_alunos_inicio(lista, curso, nome, matricula);
  printf("Aluno cadastrado com sucesso!\n");
}

void le_profs(struct lista_profs *lista){
  char nome[50], titulacao[50], area[50];
  int siape;
  printf("Matricula SIAPE: ");
  scanf("%d", &siape);
  getchar();
  printf("Nome do professor: ");
  fgets(nome, 50, stdin);
  tira_enter_do_final(nome);
  printf("Titulacao do professor: ");
  fgets(titulacao, 50, stdin);
  tira_enter_do_final(titulacao);
  printf("Area de atuacao do professor: ");
  fgets(area, 50, stdin);
  tira_enter_do_final(area);
  if(existe_profs(lista, siape) == 1){
    printf("Siape ja cadastrado\n");
    return;
  }
  insere_profs_inicio(lista, titulacao, area, nome, siape);
  printf("Professor cadastrado com sucesso!\n");
}

void le_discs(struct lista_discs *lista, struct lista_cursos *l_cursos){
  char nome[50], curso[50], pre_requisito[50];
  int codigo, ch;
  printf("Codigo da disciplina: ");
  scanf("%d", &codigo);
  printf("Carga horaria: ");
  scanf("%d", &ch);
  printf("Nome da disciplina: ");
  getchar();
  fgets(nome, 50, stdin);
  tira_enter_do_final(nome);
  printf("Pre requisito da disciplina: ");
  fgets(pre_requisito, 50, stdin);
  tira_enter_do_final(pre_requisito);
  printf("Curso da disciplina: ");
  fgets(curso, 50, stdin);
  tira_enter_do_final(curso);
  if(existe_disc(lista, codigo) == 1){
    printf("Uma disciplina ja foi cadastrada com esse codigo\n");
    return;
  }
  if(existe_curso(l_cursos, curso) == 0){
    printf("Curso nao existe\n");
    return;
  }
  insere_discs_inicio(lista, curso, pre_requisito, nome, codigo, ch);
  printf("Disciplina cadastrada com sucesso\n");
}

void le_turmas(struct lista_turmas *lista, struct lista_discs *l_discs){
  int codigo, disc;
  printf("Codigo da turma: ");
  scanf("%d", &codigo);
  printf("Codigo da disciplina: ");
  scanf("%d", &disc);
  if(existe_turma(lista, codigo) == 1){
    printf("Turma ja cadastrada com esse codigo\n");
    return;
  }
  if(existe_disc(l_discs, disc) == 0){
    printf("Disciplina nao existe\n");
    return;
  }
  insere_turmas_inicio(lista, codigo, disc);
  printf("Turma cadastrada com sucesso\n");
}

void le_avaliacoes(struct lista_avaliacoes *lista, struct lista_turmas *l_turmas){
  float nota1, nota2;
  int matricula, turma;
  printf("Matricula do aluno: ");
  scanf("%d", &matricula);
  printf("Turma que a avaliacao foi aplicada: ");
  scanf("%d", &turma);
  printf("Primeira nota tirada: ");
  scanf("%f", &nota1);
  printf("Segunda nota tirada: ");
  scanf("%f", &nota2);
  if(aluno_turma(l_turmas, matricula) == 0){
    printf("O aluno nao esta matriculado em nenhuma turma\n");
  }else{
    if(aluno_turma2(l_turmas, matricula, turma) == turma){
      insere_avaliacoes_inicio(lista, matricula, nota1, nota2, turma);
    }else{
      printf("O aluno nao esta nessa turma\n");
    }
  }
}

void le_aulas(struct lista_aulas *lista, struct lista_turmas *l_turma, struct lista_discs *l_disc){
  char conteudo[200];
  int turma, cod_disc, dia, mes, ano;
  printf("Turma que a aula foi dada: ");
  scanf("%d", &turma);
  printf("Codigo da disciplina dada: ");
  scanf("%d", &cod_disc);
  printf("Dia: ");
  scanf("%d", &dia);
  printf("Mes: ");
  scanf("%d", &mes);
  printf("Ano: ");
  scanf("%d", &ano);
  getchar();
  printf("Conteudo dado: ");
  fgets(conteudo, 200, stdin);
  tira_enter_do_final(conteudo);
  if(existe_turma(l_turma, turma) == 0){
    printf("A turma nao existe\n");
    return;
  }
  if(existe_disc(l_disc, cod_disc) == 0){
    printf("A disciplina nao existe\n");
    return;
  }
  insere_aulas_inicio(lista, conteudo, turma, cod_disc, dia, mes, ano);
}

void le_faltas(struct lista_aulas *lista, struct lista_alunos *l_alunos){
  int matricula, id, outra = 1;
  while(outra == 1){
    printf("Id da aula que voce quer lancar faltas: ");
    scanf("%d", &id);
    printf("Matricula do aluno ausente: ");
    scanf("%d", &matricula);
    if(existe_aula(lista, id) == 0){
      printf("Aula nao cadastrada");
      return;
    }
    if(existe_aluno(l_alunos, matricula) == 0){
      printf("Aluno nao cadastrado");
      return;
    }
    insere_falta_aulas_inicio(lista, matricula, id);
    printf("Deseja lancar outra falta? 1-Sim 2-Nao\n");
    scanf("%d", &outra);
  }
}

void matricula_aluno(struct lista_turmas *lista, struct lista_alunos *l_alunos){
  struct no_turmas *aux = lista->inicio;
  struct no_aluno_turma *aux2;
  int codigo, matricula;
  printf("Codigo da turma: ");
  scanf("%d", &codigo);
  printf("Matricula do aluno: ");
  scanf("%d", &matricula);
  if(existe_aluno(l_alunos, matricula) == 0){
    printf("Aluno nao cadastrado");
    return;
  }
  while(aux != NULL){
    if(aux->codigo == codigo){
      aux2 = aux->primeiro_aluno;
      while(aux2 != NULL){
        if(aux2->matricula == matricula){
          printf("O aluno ja esta na turma");
          return;
        }
        aux2 = aux2->proximo_aluno;
      }
    }
    aux = aux->proximo;
  }
  insere_aluno_turmas_inicio(lista, matricula, codigo);
}

void prof_turma(struct lista_turmas *lista, struct lista_profs *l_profs){
  int codigo, siape;
  printf("Codigo da turma: ");
  scanf("%d", &codigo);
  printf("Siape do professor: ");
  scanf("%d", &siape);
  if(existe_profs(l_profs, siape) == 0){
    printf("Porfessor nao cadastrado\n");
    return;
  }
  insere_prof_turmas_inicio(lista, siape, codigo);
}

//BUSCAS
int busca_aluno(struct lista_alunos *lista){
  int matricula;
  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);
  int i = 0;
  if(lista->inicio == NULL){
    return -1;
  }
  if(lista->inicio->matricula == matricula){
    return i;
  }else{
    struct no_alunos *aux = lista->inicio;
    while(aux != NULL){
      if(aux->matricula == matricula){
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

void busca_aluno_imprime(struct lista_alunos *lista){
  int matricula;
  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);
  int i = 0;
  if(lista->inicio == NULL){
    printf("Nenhum aluno cadastrado\n");
    return;
  }
  if(lista->inicio->matricula == matricula){
    printf("Matricula: %d  Nome: %s  Curso: %s\n", lista->inicio->matricula, lista->inicio->nome, lista->inicio->curso);
    i = 1;
  }else{
    struct no_alunos *aux = lista->inicio;
    while(aux != NULL){
      if(aux->matricula == matricula){
        printf("Matricula: %d  Nome: %s  Curso: %s\n", aux->matricula, aux->nome, aux->curso);
        i = 1;
        break;
      }
      aux = aux->proximo;
    }
    if(i == 0){
      printf("Aluno nao existe\n");
    }
  }
}

int busca_prof(struct lista_profs *lista){
  int siape;
  printf("Digite o siape do professor: ");
  scanf("%d", &siape);
  int i = 0;
  if(lista->inicio == NULL){
    return -1;
  }
  if(lista->inicio->siape == siape){
    return i;
  }else{
    struct no_profs *aux = lista->inicio;
    while(aux != NULL){
      if(aux->siape == siape){
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

void busca_prof_imprime(struct lista_profs *lista){
  int siape;
  printf("Digite o siape do professor: ");
  scanf("%d", &siape);
  int i = 0;
  if(lista->inicio == NULL){
    printf("Nenhum professor cadastrado\n");
    return;
  }
  if(lista->inicio->siape == siape){
    printf("Siape: %d  Nome: %s  Area: %s  Titulacao: %s\n", lista->inicio->siape, lista->inicio->nome, lista->inicio->area, lista->inicio->titulacao);
    i = 1;
  }else{
    struct no_profs *aux = lista->inicio;
    while(aux != NULL){
      if(aux->siape == siape){
        printf("Siape: %d  Nome: %s  Area: %s  Titulacao: %s\n", aux->siape, aux->nome, aux->area, aux->titulacao);
        i = 1;
        break;
      }
      aux = aux->proximo;
    }
    if(i == 0){
      printf("Professor nao existe\n");
    }
  }
}

int busca_turma(struct lista_turmas *lista){
  int codigo;
  printf("Digite o codigo da turma: ");
  scanf("%d", &codigo);
  int i = 0;
  if(lista->inicio == NULL){
    return -1;
  }
  if(lista->inicio->codigo == codigo){
    return i;
  }else{
    struct no_turmas *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == codigo){
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

void busca_turma_imprime(struct lista_turmas *lista){
  int codigo;
  printf("Digite o codigo da turma: ");
  scanf("%d", &codigo);
  int i = 0;
  if(lista->inicio == NULL){
    printf("Nenhuma turma cadastrada\n");
    return;
  }
  if(lista->inicio->codigo == codigo){
    printf("Codigo: %d  Numero de alunos: %d  Disciplina: %d\n", lista->inicio->codigo, lista->inicio->n_alunos, lista->inicio->disc);
    i = 1;
  }else{
    struct no_turmas *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == codigo){
        printf("Codigo: %d  Numero de alunos: %d  Disciplina: %d\n", aux->codigo, aux->n_alunos, aux->disc);
        i = 1;
        break;
      }
      aux = aux->proximo;
    }
    if(i == 0){
      printf("Turma nao existe\n");
    }
  }
}

int busca_disc(struct lista_discs *lista, struct lista_turmas *l_turmas){
  int codigo;
  printf("Digite o codigo da disciplina: ");
  scanf("%d", &codigo);
  int i = 0, ct = 0;
  if(lista->inicio == NULL){
    return -1;
  }
  struct no_turmas *turma = l_turmas->inicio; 
  if(lista->inicio->codigo == codigo){
    while(turma != NULL){
      printf("TURMA DA DISC: %d", turma->disc);
      if(codigo = turma->disc){
        remove_turma_indice(l_turmas, ct);
        ct--;
      }
      ct++;
      turma = turma->proximo;
    }
    return i;
  }else{
    struct no_discs *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == codigo){
        while(turma != NULL){
          printf("TURMA DA DISC: %d", turma->disc);
          if(codigo = turma->disc){
            remove_turma_indice(l_turmas, ct);
            ct--;
          }
          ct++;
          turma = turma->proximo;
        }
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

int busca_disc_codigo(struct lista_discs *lista, struct lista_turmas *l_turmas, int codigo){
  int i = 0, ct = 0;
  if(lista->inicio == NULL){
    return -1;
  }
  struct no_turmas *turma = l_turmas->inicio; 
  if(lista->inicio->codigo == codigo){
    while(turma != NULL){
      if(codigo = turma->disc){
        remove_turma_indice(l_turmas, ct);
        ct--;
      }
      ct++;
      turma = turma->proximo;
    }
    return i;
  }else{
    struct no_discs *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == codigo){
        while(turma != NULL){
          if(codigo = turma->disc){
            remove_turma_indice(l_turmas, ct);
            ct--;
          }
          ct++;
          turma = turma->proximo;
        }
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

void busca_disc_imprime(struct lista_discs *lista){
  int codigo;
  printf("Digite o codigo da disciplina: ");
  scanf("%d", &codigo);
  int i = 0;
  if(lista->inicio == NULL){
    printf("Nenhuma disciplina cadastrada\n");
    return;
  }
  if(lista->inicio->codigo == codigo){
    printf("Codigo: %d  Nome: %s  Carga horaria: %d  Pre-requisito: %s  Curso: %s\n", lista->inicio->codigo, lista->inicio->nome, lista->inicio->ch, lista->inicio->pre_requisito, lista->inicio->curso);
    i = 1;
  }else{
    struct no_discs *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == codigo){
        printf("Codigo: %d  Nome: %s  Carga horaria: %d  Pre-requisito: %s  Curso: %s\n", aux->codigo, aux->nome, aux->ch, aux->pre_requisito, aux->curso);
        i = 1;
        break;
      }
      aux = aux->proximo;
    }
    if(i == 0){
      printf("Turma nao existe\n");
    }
  }
}

int busca_turma_disc(struct lista_turmas *lista, int disc){
  int i = 0;
  if(lista->inicio == NULL){
    return -1;
  }
  if(lista->inicio->disc == disc){
    return i;
  }else{
    struct no_turmas *aux = lista->inicio;
    while(aux != NULL){
      if(aux->disc == disc){
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

int busca_curso(struct lista_cursos *lista, struct lista_alunos *l_alunos, struct lista_discs *l_disc, struct lista_turmas *l_turma){
  int codigo;
  printf("Digite o codigo do curso: ");
  scanf("%d", &codigo);
  int i = 0, ca = 0, cd = 0;
  struct no_alunos *aluno = l_alunos->inicio;
  struct no_alunos *proxa;
  struct no_discs *disc = l_disc->inicio;
  struct no_discs *prox;
  if(lista->inicio == NULL){
    return -1;
  }
  if(lista->inicio->codigo == codigo){
    while(aluno != NULL){
      proxa = aluno->proximo;
      if(strcmp(lista->inicio->nome, aluno->curso) == 0){
        remove_aluno_indice(l_alunos, ca);
        ca--;
      }
      ca++;
      aluno = proxa;
    }
    while(disc != NULL){
      prox = disc->proximo;
      if(strcmp(lista->inicio->nome, disc->curso) == 0){
        cd = busca_disc_codigo(l_disc, l_turma, disc->codigo);
        remove_disc_indice(l_disc,cd);
      }
      disc = prox;
    }
    return i;
  }else{
    struct no_cursos *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == codigo){
        while(aluno != NULL){
          proxa = aluno->proximo;
          if(strcmp(aux->nome, aluno->curso) == 0){
            remove_aluno_indice(l_alunos, ca);
            ca--;
          }
          ca++;
          aluno = proxa;
        }
        while(disc != NULL){
          prox = disc->proximo;
          if(strcmp(aux->nome, disc->curso) == 0){
            cd = busca_disc_codigo(l_disc, l_turma, disc->codigo);
            remove_disc_indice(l_disc, cd);
          }
          disc = prox;
        }
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

int exclui_falta_aluno(struct lista_aulas *lista, int matricula){
  struct no_aulas *aula = lista->inicio;
  struct no_faltas *falta;
  while(aula != NULL){
    if(aula->primeira_falta != NULL){
      if(aula->primeira_falta->matricula == matricula){
        if (aula->primeira_falta->proximo == NULL) {
          free(aula->primeira_falta);
          aula->primeira_falta = NULL;
          aula->ultima_falta = NULL;
          return 1;
        } else {
          struct no_faltas *segundo = aula->primeira_falta->proximo;
          free(aula->primeira_falta);
          aula->primeira_falta = segundo;
          return 1;
        }
      }else if(aula->ultima_falta->matricula == matricula){
        struct no_faltas *penultimo = aula->primeira_falta;
        struct no_faltas *ultimo = aula->ultima_falta;
        while (penultimo->proximo->proximo != NULL) {
          penultimo = penultimo->proximo;
        }
        penultimo->proximo = NULL;
        aula->ultima_falta = penultimo;
        free(ultimo);
        return 1;
      }else{
        falta = aula->primeira_falta;
        while(falta != NULL){
          if(falta->proximo->matricula == matricula){
            struct no_faltas *proximo = falta->proximo->proximo;
            free(falta->proximo);
            falta->proximo = proximo;
            return 1;
          }
        }
      }
    }
    aula = aula->proximo;
  }
  return 0;
}

void busca_curso_imprime(struct lista_cursos *lista){
  int codigo;
  printf("Digite o codigo do curso: ");
  scanf("%d", &codigo);
  int i = 0;
  if(lista->inicio == NULL){
    printf("Nenhum curso cadastrado\n");
    return;
  }
  if(lista->inicio->codigo == codigo){
    printf("Codigo: %d  Nome: %s\n", lista->inicio->codigo, lista->inicio->nome);
    i = 1;
  }else{
    struct no_cursos *aux = lista->inicio;
    while(aux != NULL){
      if(aux->codigo == codigo){
        printf("Codigo: %d  Nome: %s\n", aux->codigo, aux->nome);
        i = 1;
        break;
      }
      aux = aux->proximo;
    }
    if(i == 0){
      printf("Curso nao existe\n");
    }
  }
}

int busca_avaliacao(struct lista_avaliacoes *lista){
  int matricula;
  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);
  int i = 0;
  if(lista->inicio == NULL){
    return -1;
  }
  if(lista->inicio->matricula == matricula){
    return i;
  }else{
    struct no_avaliacoes *aux = lista->inicio;
    while(aux != NULL){
      if(aux->matricula == matricula){
        return i;
      }
      i++;
      aux = aux->proximo;
    }
    return -1;
  }
}

int busca_avaliacao_by_turma_by_aluno(struct lista_avaliacoes *lista, int matricula, int turma){
  int i = 0;
  struct no_avaliacoes *aux = lista->inicio;
  while(aux != NULL){
    if(aux->matricula == matricula && aux->turma == turma){
      printf("     Nota 1: %f  Nota 2: %f\n", aux->nota1, aux->nota2);
      if((aux->nota1+aux->nota2)/2.0 >= 7.0){
        printf("     Situacao: aprovado por nota\n");     
        return 1;     
      }else{
        printf("     Situacao: reprovado por nota\n");
        return 1;
      }
    }
    i++;
    aux = aux->proximo;
  }
  return -1;
}

void gera_relatorio(struct lista_avaliacoes *l_avaliacoes, struct lista_turmas *l_turmas, struct lista_alunos *l_alunos, struct lista_aulas *l_aulas, struct lista_discs *l_discs){
  struct no_avaliacoes *aux_avaliacao = l_avaliacoes->inicio;
  struct no_turmas *aux_turma = l_turmas->inicio;
  struct no_aulas *aux_aula = l_aulas->inicio;
  struct no_discs *aux_disc = l_discs->inicio;
  struct no_aluno_turma *aux_aluno;
  struct no_faltas *aux_falta;
  int cont_faltas = 0;
  if(esta_vazia_turma(l_turmas) == 1){
    printf("Nenhuma turma cadastrada\n");
  }else{
    while(aux_turma != NULL){
      //IMPRIME A TURMA
      printf("TURMA %d\n", aux_turma->codigo);
      aux_aluno = aux_turma->primeiro_aluno; 
      if(aux_aluno == NULL){
        printf("  A turma nao tem alunos matriculados.\n");
      }else{
        //PERCORRE ALUNOS
        while(aux_aluno != NULL){
          cont_faltas = 0;
          printf("  Aluno: %d\n", aux_aluno->matricula);
          //PERCORRE AULA
          aux_aula = l_aulas->inicio;
          while(aux_aula != NULL){
            if(aux_aula->turma == aux_turma->codigo){
              aux_falta = aux_aula->primeira_falta;
              while(aux_falta != NULL){
                if(aux_falta->matricula == aux_aluno->matricula){
                  cont_faltas++;
                }
                aux_falta = aux_falta->proximo;
              }
            }
            aux_aula = aux_aula->proximo;
          }
          while(aux_disc != NULL){
            if(aux_disc->codigo == aux_turma->disc){
              printf("     Carga horaria: %d   faltas: %d\n", aux_disc->ch, cont_faltas);
              if(aux_disc->ch*0.3 > cont_faltas){
                printf("     O aluno tem as presencas necessarias\n");
              }else{
                printf("     Aluno reprovado por frequencia\n");
              }
            }
            aux_disc = aux_disc->proximo;
          }
          busca_avaliacao_by_turma_by_aluno(l_avaliacoes, aux_aluno->matricula, aux_turma->codigo);
          aux_disc = l_discs->inicio;
          aux_aula = l_aulas->inicio;
          aux_aluno = aux_aluno->proximo_aluno;
        }
      }
      aux_turma = aux_turma->proximo;
    }
  }
}

int menu(){
  printf("Digite a operacao:\n");
  printf("1 - Cadastrar\n");
  printf("2 - Excluir\n");
  printf("3 - Buscar\n");
  printf("4 - Lancar notas e avaliacoes\n");
  printf("5 - Matricular aluno em uma turma\n");
  printf("6 - Inserir professor em uma turma\n");
  printf("7 - Lancar aulas e faltas\n");
  printf("8 - Gerar relatorio geral\n");
  printf("9 - Sair\n");

  int op;
  scanf("%d", &op);
  while(op < 1 && op > 9){
    printf("Operacao invalida, tente novamente:\n");
    scanf("%d", &op);
  }
  return op;
}

int menu_cadastro(){
  printf("Digite o que voce quer cadastrar:\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Turma\n");
  printf("4 - Disciplina\n");
  printf("5 - Curso\n");

  int op;
  scanf("%d", &op);
  while(op < 1 && op > 5){
    printf("Operacao invalida, tente novamente:\n");
    scanf("%d", &op);
  }
  return op;
}

int menu_delete(){
  printf("Digite o que voce quer excluir:\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Turma\n");
  printf("4 - Disciplina\n");
  printf("5 - Curso\n");
  printf("6 - Avaliacoes\n");

  int op;
  scanf("%d", &op);
  while(op < 1 && op > 6){
    printf("Operacao invalida, tente novamente:\n");
    scanf("%d", &op);
  }
  return op;
}

int menu_busca(){
  printf("Digite o que voce quer buscar:\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Turma\n");
  printf("4 - Disciplina\n");
  printf("5 - Curso\n");
  printf("6 - Avaliacoes\n");

  int op;
  scanf("%d", &op);
  while(op < 1 && op > 6){
    printf("Operacao invalida, tente novamente:\n");
    scanf("%d", &op);
  }
  return op;
}

int main() {
  
  struct lista_alunos l_alunos;
  struct lista_cursos l_cursos;
  struct lista_turmas l_turmas;
  struct lista_discs l_discs;
  struct lista_profs l_profs;
  struct lista_avaliacoes l_avaliacoes;
  struct lista_aulas l_aulas;

  inicializa_lista_prof(&l_profs);
  inicializa_lista_disc(&l_discs);
  inicializa_lista_turma(&l_turmas);
  inicializa_lista_aluno(&l_alunos);
  inicializa_lista_curso(&l_cursos);
  inicializa_lista_avaliacao(&l_avaliacoes);
  inicializa_lista_aula(&l_aulas);

  int op = menu();
  int cadastro, delete, indice_delete, busca, matricula, siape, cod_turma, falta, ef = 1, em = 1;
  while(op != 10){
    switch(op){
      case 1:
        cadastro = menu_cadastro();
        switch(cadastro){
          case 1:
            le_alunos(&l_alunos, &l_cursos);
          break;
          case 2:
            le_profs(&l_profs);
          break;
          case 3:
            le_turmas(&l_turmas, &l_discs);
          break;
          case 4:
            le_discs(&l_discs, &l_cursos);
          break;
          case 5:
            le_cursos(&l_cursos);
          break;
        }
        op = menu();
      break;
      case 2:
        delete = menu_delete();
        switch(delete){
          case 1:
            indice_delete = busca_aluno(&l_alunos);
            if(indice_delete >= 0){
              matricula = remove_aluno_indice(&l_alunos, indice_delete); 
              cod_turma = aluno_turma(&l_turmas, matricula);
              while(cod_turma != 0){
                desmatricula_aluno(&l_turmas, matricula, cod_turma);
                cod_turma = aluno_turma(&l_turmas, matricula);
              } 
              exclui_avaliacao_aluno(&l_avaliacoes, matricula);
              ef = 1;
              while(ef != 0){
                ef = exclui_falta_aluno(&l_aulas, matricula);
              }
              printf("Aluno removido com sucesso!\n");
            }else{
              printf("Aluno nao cadastrado\n");
            }
          break;
          case 2:
            indice_delete = busca_prof(&l_profs);
            if(indice_delete >= 0){
              siape = remove_prof_indice(&l_profs, indice_delete);
              cod_turma = verifica_prof_turma(&l_turmas, siape);
              while(cod_turma != 0){
                desmatricula_prof(&l_turmas, siape, cod_turma);
                cod_turma = verifica_prof_turma(&l_turmas, siape);
              } 
              printf("Professor removido com sucesso!\n");   
            }else{
              printf("Professor nao cadastrado\n");
            }
          break;
          case 3:
            indice_delete = busca_turma(&l_turmas);
            if(indice_delete >= 0){
              remove_turma_indice(&l_turmas, indice_delete);  
              printf("Turma removida com sucesso!\n");              
            }else{
              printf("Turma nao cadastrada\n");
            }
          break;
          case 4:
            indice_delete = busca_disc(&l_discs, &l_turmas);
            if(indice_delete >= 0){
              remove_disc_indice(&l_discs, indice_delete);  
              printf("Disciplina removida com sucesso!\n");
            }else{
              printf("Disciplina nao cadastrada\n");
            }
          break;
          case 5:
            indice_delete = busca_curso(&l_cursos, &l_alunos, &l_discs, &l_turmas);
            if(indice_delete >= 0){
              remove_curso_indice(&l_cursos, indice_delete);  
              printf("Curso removido com sucesso!\n");
            }else{
              printf("Curso nao cadastrado\n");
            }
          break;
          case 6:
            indice_delete = busca_avaliacao(&l_avaliacoes);
            if(indice_delete >= 0){
              remove_avaliacao_indice(&l_avaliacoes, indice_delete);  
              printf("Avaliacao removida com sucesso!\n");
            }else{
              printf("Avaliacao nao cadastrado\n");
            }
          break;
        }
        op = menu();
      break;
      case 3:
        busca = menu_busca();
        switch(busca){
          case 1:
            busca_aluno_imprime(&l_alunos);
          break;
          case 2:
            busca_prof_imprime(&l_profs);
          break;
          case 3:
            busca_turma_imprime(&l_turmas);
          break;
          case 4:
            busca_disc_imprime(&l_discs);
          break;
          case 5:
            busca_curso_imprime(&l_cursos);
          break;
          case 6:
            busca_avaliacao(&l_avaliacoes);
          break;
        }
        op = menu();
      break;
      case 4:
        le_avaliacoes(&l_avaliacoes, &l_turmas);
        op = menu();
      break;
      case 5:
        matricula_aluno(&l_turmas, &l_alunos);
        op = menu();
      break;
      case 6:
        prof_turma(&l_turmas, &l_profs);
        op = menu();
      break;
      case 7:
        le_aulas(&l_aulas, &l_turmas, &l_discs);
        printf("Lancar faltas? 1-Sim 2-Nao: \n");
        scanf("%d", &falta);
        if(falta == 1){
          le_faltas(&l_aulas, &l_alunos);
        }
        op = menu();
      break;
      case 8:
        gera_relatorio(&l_avaliacoes, &l_turmas, &l_alunos, &l_aulas, &l_discs); 
        op = menu();
      break;
      case 9:
        printf("LISTA ALUNOS\n");
        imprime_lista_aluno(&l_alunos);
        printf("LISTA PROFS\n");
        imprime_lista_prof(&l_profs);
        printf("LISTA DISCS\n");
        imprime_lista_disc(&l_discs);
        printf("LISTA TURMAS\n");
        imprime_lista_turma(&l_turmas);
        printf("LISTA AVALIACOES\n");
        imprime_lista_avaliacao(&l_avaliacoes);
        printf("LISTA AULAS\n");
        imprime_lista_aula(&l_aulas);
        op = menu();
      break;
    }
  }
  return 0;
}