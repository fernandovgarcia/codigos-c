#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int nAleatorio()
{
  int n;
  n = ((rand() % 6) + 1);
  return n;
}
int imprimeTab(int tabuleiro[6][6])
{
  for (int i = 0; i < 6; i++) {
    for(int j = 0; j < 6; j++){
      printf("[%d, %d]: %d ", i+1, j+1, tabuleiro[i][j]);
      if (j == 5){
        printf("\n");
      }
    }
  }
}
int limpalinha(int l, int tabuleiro[6][6])
{
  for (int i = 0; i < 6; i++){
    tabuleiro[l][i] = 0;
  }
  return tabuleiro[6][6];
}
int limpacoluna(int c, int tabuleiro[6][6])
{
  for (int i = 0; i < 6; i++){
    tabuleiro[i][c] = 0;
  }
  return tabuleiro[6][6];
}
bool pontol(int l, int tabuleiro[6][6])
{
  int sl = 0;
  for (int i = 0; i < 6; i++){
    sl = sl + tabuleiro[l][i];
  }
  if(sl == 10){
    return true;
  }else{
    return false;
  }
}
bool pontoc(int c, int tabuleiro[6][6])
{
  int sc = 0;
  for (int i = 0; i < 6; i++){
    sc = sc + tabuleiro[i][c];
  }
  if(sc == 10){
    return true;
  }else{
    return false;
  }
}
int somac(int c, int tabuleiro[6][6]){
  int sc = 0;
  for (int i = 0; i < 6; i++){
    sc = sc + tabuleiro[i][c];
  }
  return sc;
}
int somal(int l, int tabuleiro[6][6]){
  int sl = 0;
  for (int j = 0; j < 6; j++){
    sl = sl + tabuleiro[l][j];
  }  
  return sl;
  
}
bool verifica(int l, int c, int tabuleiro[6][6], int dado)
{
  int sl = dado;
  int sc = dado;
  for (int j = 0; j < 6; j++){
    sl = sl + tabuleiro[l][j];
  }
  for (int i = 0; i < 6; i++){
    sc = sc + tabuleiro[i][c];
  }
  if (sl > 10 || sc > 10){
    return false;
  }else{
    return true;
  }
}
int main()
{
  int i, j, tabuleiro[6][6], l, c, dado, pontuacao = 0,resultado = 0, jc = 0, g = 0;
  bool v, vc, pl, pc, jp = false;
  for (i = 0; i < 6; i++){
    for (j = 0; j < 6; j++){
      tabuleiro[i][j] = 0;
    }
  }
  int o = 1;
  srand(time(NULL));
  while(o > 0) {
    g = 0;
    printf("-----RODADA %d-----\n", o);
    dado = nAleatorio();
    for (i = 0; i < 6; i++){
      printf("Soma da linha %d e' %d\n", i+1, somal(i, tabuleiro));
      printf("Soma da coluna %d e' %d\n", i+1, somac(i, tabuleiro));
    }
    printf("O tabuleiro esta assim:\n");
    printf("Voce esta com %d pontos\n", pontuacao);
    imprimeTab(tabuleiro);
    
    printf("O resultado do dado foi: %d\n", dado);
    for (i = 0; i < 6; i++){
      for (j = 0; j < 6; j++){
        if (tabuleiro[i][j] == 0) {
          jp = verifica(i, j, tabuleiro, dado);
          if (jp == true) {
            break;
          }
        }
      }
    }
    if (jp == true){
      printf("Em qual posicao deseja colocar esse valor (exemplo: 1 1)? ");
      scanf("%d %d", &l, &c);
      while (!(l-1 >= 0 && l-1 <= 5) || !(c-1 >= 0 && c-1 <= 6)) {
        printf("Posicao invalida, tente novamente: ");
        scanf("%d %d", &l, &c);
      }
      while(tabuleiro[l-1][c-1] != 0){
        printf("Posicao invalida, tente novamente: ");
        scanf("%d %d", &l, &c);
      }
      v = verifica(l-1, c-1, tabuleiro, dado);
      while (v == false){
        printf("Posicao invalida, tente novamente: ");
        scanf("%d %d", &l, &c);
        v = verifica(l-1, c-1, tabuleiro, dado);
      }
      tabuleiro[l-1][c-1] = dado;
      pl = pontol(l-1, tabuleiro);
      pc = pontoc(c-1, tabuleiro);
      if(pl == true && pc == true){
        pontuacao = pontuacao + 31;
        tabuleiro[6][6] = limpalinha(l-1, tabuleiro);
        tabuleiro[6][6] = limpacoluna(c-1, tabuleiro);
      } else if (pl == true){
        pontuacao = pontuacao + 10;
        tabuleiro[6][6] = limpalinha(l-1, tabuleiro);
      }else if(pc == true){
        pontuacao = pontuacao + 10;
        tabuleiro[6][6] = limpacoluna(c-1, tabuleiro);
      }
    }else{
      break;
    }
    o++;
  }
}