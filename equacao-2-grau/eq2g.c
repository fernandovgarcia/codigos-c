#include <stdio.h>
#include <math.h>

void main()
{
  float a, b, c;
  float r1, delta;
  float y1, y2;

  printf("Digite a, b e c\n");
  scanf("%f%f%f", &a, &b, &c);
  delta = (b*b)-(4*a*c);
  printf("O valor do delta e': %g\n", delta);

  if(delta > 0){
    float r2;
    r1 = (-b + sqrt(delta))/(2*a);
    r2 = (-b - sqrt(delta))/(2*a);
    printf("As raizes sao: %f e %f\n", r1, r2);
    y1=a*r1*r1+b*r1+c;
    y2=a*r2*r2+b*r2+c;

    printf("Valor de y para primeira raiz: %f\n", y1);
    printf("Valor de y para segunda raiz: %f\n", y2);
  }else if(delta == 0){
    r1 = (-b + sqrt(delta))/(2*a);
    printf("A unica raíz e': %f\n", r1);
    y1=a*r1*r1+b*r1+c;
    
    printf("Valor de y para raiz: %f\n", y1);
  }else{
    float r2;
    r1 = -b/(2*a); 
    r2 = sqrt(-delta)/(2*a);
  
    float y2;
    y1 = a*((r1*r1) +2*(r1*r2) - (r2*r2)) + (b*r1)+(b*r2) + c;
    y2 = a*((r1*r1) -2*(r1*r2) - (r2*r2)) + (b*r1)+(b*-r2) + c;

    printf("As raizes imaginarias da equacao sao (%.2f - %.2fi) e (%.2f + %.2fi)\n",r1,r2,r1,r2);
    printf("Os valores de y sao %.2f e %.2f\n", y1, y2); 
  }
}