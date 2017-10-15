#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nAleatorio()
{
  int n;
  n = ((rand() % 6) + 1);
  return n;
}
int imprimeTab(int tabuleiro[10])
{
  for (int j = 0; j < 10; j++) {
    printf("Valor na posicao %d: %d\n", j+1, tabuleiro[j]);
  }
}
int main(){

}