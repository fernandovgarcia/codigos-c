#include <stdio.h>

void main(){
	float raio;
	float pi;
	float area;
	printf("Informe o raio do circulo\n");
	scanf("%f", &raio);
	pi = 3.1415;
	area = pi * raio * raio; 
	printf("A área do circulo é %f\n", area);
}