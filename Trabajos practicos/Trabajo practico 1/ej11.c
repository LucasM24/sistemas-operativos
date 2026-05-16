#include<stdio.h>

void ejercicioA() {
  int a, b;
  float r;

  a = 5;
  b = 2;
  r = (float) a / b;

  printf("Valor de r: %f \n", r);
}

void ejercicioB() {
  int a, b, d;
  float c;
  a = 1;
  b = 2;
  c = (float) a / b;
  d = a / c;

  printf("Valor de c: %f \n", c);
  printf("Valor de d: %d \n", d);
}

void ejercicioC() {
  printf(" %d\n", 20/3); /* Salida: 6*/
  printf(" %f\n", 20/3); /* Salida: Error espera un float recibe un int*/
  printf(" %f\n", 20/3.); /* Salida: 6.666666*/
  printf(" %d\n", 10%3); /* Salida: 1*/
  printf(" %d\n", 3.1416); /* Salida 3*/
  printf(" %f\n", (double)20/3); /* Salida: Error espera un float recibe un double*/
  printf(" %f\n", (int)3.1416); /* Salida: 3.000000*/
  printf(" %d\n", (int)3.1416); /* Salida: 3*/

}

int main(){
  /*ejercicioA();*/
  /*ejercicioB();*/
  ejercicioC();
}

