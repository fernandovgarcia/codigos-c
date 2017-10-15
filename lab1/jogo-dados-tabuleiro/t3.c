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
  int i, j, tabuleiro[10], posicao, dado, resultado = 0, jc = 0, g = 0;
  bool v;
  for (j = 0; j < 10; j++){
    tabuleiro[j] = 0;
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
    v = verifica(tabuleiro, dado);
    if(v == true){
      printf("Em qual posicao voce deseja colocar esse valor?\n");
      scanf("%d", &posicao);
      if(tabuleiro[posicao-1] != 0){
        printf("PERDEU\nVoce nao pode colocar esse numero nessa posicao\n");
        break;
      }
      for(j = 0; j < posicao-1; j++){
        if (tabuleiro[j] > dado) {
          jc++;
        }
      } 
      if (jc == 0) {
        tabuleiro[posicao-1] = dado;
      }else{
        printf("PERDEU\nVoce nao pode colocar esse numero nessa posicao\n");
        break;
      }
      jc = 0;
      for (j = posicao; j < 10; j++){
        if (tabuleiro[j] < dado && tabuleiro[j] != 0) {
          jc++;
        }
      }
      if (jc == 0) {
        tabuleiro[posicao-1] = dado;
      }else{
        printf("PERDEU\nVoce nao pode colocar esse numero nessa posicao\n");
        break;
      }
      for (i = 0; i < 10; i++){
        if(tabuleiro[i] != 0){
          g++;
        }
      }
      if (g == 10){
        imprimeTab(tabuleiro);
        printf("PARABENS, VOCE GANHOU!!!\n");
        break;
      }
      o++;
    }else{
      printf("PERDEU\nNao ha mais movimentos possiveis\n");
      break;
    }
  }
}