#include <stdio.h>
#include <math.h>

void main( )
{
  //Declaração de variáveis
  int ano; 
  
  //Entrada de dados
  printf("Informe o ano\n");
  scanf("%d", &ano);
  
  //Verifica se é bissexto
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
    printf("E' bissexto\n");
  }else{
    printf("Nao e' bissexto\n");
  }
}