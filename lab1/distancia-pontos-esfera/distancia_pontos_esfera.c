//Aluno: Fernando Vedoin Garcia
#include <stdio.h>
#include <math.h>

void main( )
{
  //Declaração de variáveis
  float lat1, lat2, long1, long2;
  float distancia; 
  int raioTerra = 6500;

  //Entrada de dados
  printf("Digite as coordenadas do primeiro ponto (latitude e longitude)\n");
  scanf("%f", &lat1);
  scanf("%f", &long1);
  printf("Digite as coordenadas do segundo ponto (latitude e longitude)\n");
  scanf("%f", &lat2);
  scanf("%f", &long2);

  //Conversão de graus para rad
  lat1 = lat1 * M_PI/180;
  lat2 = lat2 * M_PI/180;
  long1 = long1 * M_PI/180;
  long2 = long2 * M_PI/180;

  //Calcula a distância entre os pontos em km
  distancia = sqrt((pow(raioTerra, 2) + pow(raioTerra, 2)) - ((2 * raioTerra * raioTerra) * (cos(lat1) * cos(lat2) * cos(long1 - long2) + (sin(lat1) * sin(lat2)))));

  //Imprime a distância em metros
  printf("A distancia em metros entre os pontos e' %f\n", distancia * 1000);
}