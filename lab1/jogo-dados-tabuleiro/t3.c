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
int imprimeTab(int tabuleiro[10])
{
  for (int j = 0; j < 10; j++) {
    printf("Valor na posicao %d: %d\n", j+1, tabuleiro[j]);
  }
}
bool verifica(int tabuleiro[10], int dado)
{
  int ok[10];
  int aux = 0;
  int i, j, cont = 0;
  for (int j = 0; j < 10; j++){
    ok[j] = 0;
  }
  for (i = 0; i < 10; i++){
    if (tabuleiro[i] != 0){
      ok[i] = 1;
    }else{
      for (j = i-1; j >= 0 ; j--){
        if(dado < tabuleiro[j] && tabuleiro[j] > 0){
          ok[i] = 1;
        }
      }
      if (ok[i] == 0) {
        for (j = i+1; j < 10; j++){
          if(dado > tabuleiro[j] && tabuleiro[j] > 0){
            ok[i] = 1;
          }
        }
      }
    }
  }
  for (i = 0; i < 10; ++i){
    if (ok[i] != 0) {
      cont++;
    }
  }
  if (cont < 10){
    return true;
  }else{
    return false;
  }	
}
int main()
{
  
}