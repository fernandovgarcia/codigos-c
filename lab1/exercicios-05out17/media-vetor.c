#include <stdio.h>

float media(float v[], int n)
{
  float aux = 0;
  for (int i = 0; i < 5; ++i)
  {
  	aux += v[i];
  } 
  return aux/n;
}
void main()
{
  float v[5];
  printf("Digite 5 numeros\n");
  for (int i = 0; i < 5; ++i)
  {
  	scanf("%f", &v[i]);
  }
  printf("A media deles e' %f\n", media(v, sizeof(v)/sizeof(v[0])));
}