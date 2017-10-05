#include <stdio.h>

int menor(float v[], int n1, int n2)
{
  if (v[n1] > v[n2]){
    return n2+1;
  }else{
    return n1+1;
  }
}
void main()
{
  float v[5];
  int n1, n2;
  printf("Digite 5 numeros\n");
  for (int i = 0; i < 5; ++i)
  {
  	scanf("%f", &v[i]);
  }
  printf("Escreva dois indices desse vetor\n");
  scanf("%d", &n1);
  scanf("%d", &n2);
  printf("O menor entre os dois indices e' o indice %d\n", menor(v, n1-1, n2-1));
}