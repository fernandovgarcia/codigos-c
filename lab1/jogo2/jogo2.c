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