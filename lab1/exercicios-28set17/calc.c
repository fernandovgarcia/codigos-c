#include <stdio.h>

int calculo(int n1, char o, int n2)
{
  int resultado;
  switch(o){
    case '+':
      resultado = n1 + n2;
      break;
    case '-':
      resultado = n1 - n2;
      break;
    case 'x':
      resultado = n1 * n2;
      break;
    case '/':
      resultado = n1 / n2;
      break;
  }
}

void main()
{
  int n1, n2;
  char o;	
  printf("Escreva um numero, a operacao e outro numero:\n");
  scanf("%d %c %d", &n1, &o, &n2);

  printf("= %d \n", calculo(n1, o, n2));
}