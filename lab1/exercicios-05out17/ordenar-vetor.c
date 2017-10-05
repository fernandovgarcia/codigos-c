#include <stdio.h>

float ordenar(float v[], int t)
{
  float aux;
  int i;
  for (i = 0; i < t-1; i++)
  {
    for (int j = i+1; j < t; j++)
    {
      if (v[i] > v[j])
      {
        aux = v[j];
        v[j] = v[i];
        v[i] = aux;
      }
    }
  }
  printf("O vetor em ordem crescente e'\n");
  for(i = 0; i < t; i++)
  {
    printf("%f\n", v[i]);
  }
}
void main()
{
  float v[5];
  printf("Digite 5 numeros\n");
  for (int i = 0; i < 5; ++i)
  {
    scanf("%f", &v[i]);
  }
  ordenar(v, sizeof(v)/sizeof(v[0]));
  
}