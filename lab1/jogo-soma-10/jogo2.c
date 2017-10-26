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
int limpalinha(int l, int tabuleiro[6][6]){
  for (int i = 0; i < 6; i++){
    tabuleiro[l][i] = 0;
  }
  return tabuleiro[6][6];
}
int limpacoluna(int c, int tabuleiro[6][6]){
  for (int i = 0; i < 6; i++){
    tabuleiro[i][c] = 0;
  }
  return tabuleiro[6][6];
}
bool pontol(int l, int tabuleiro[6][6]){
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
bool pontoc(int c, int tabuleiro[6][6]){
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
int main()
{
  int i, j, tabuleiro[6][6], l, c, dado, resultado = 0, jc = 0, g = 0;
  bool v;
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
    printf("O tabuleiro esta assim:\n");
    imprimeTab(tabuleiro);
    printf("O resultado do dado foi: %d\n", dado);
    printf("Em qual posicao deseja colocar esse valor? ");
    scanf("%d %d", &l, &c);
    tabuleiro[l-1][c-1] = dado;
  }
}