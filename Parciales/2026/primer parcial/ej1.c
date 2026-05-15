#include<stdio.h>
#include<stdlib.h>

int main() {
  int n = 6;
  int intentos = 6;
  int palabra_correcta = 0;
  int aciertos = 0;
  char palabra_secreta[6];
  char palabra_ingresada[6];
  char resultado[6];

  system ("/bin/stty raw");
  palabra_secreta[5] = '\0';
  palabra_ingresada[5] = '\0';
  resultado[5] = '\0';
  printf("\rIngrese palabra oculta: ");

  for(int i = 0; i < 5; i++) {
    palabra_secreta[i] = getchar();
    resultado[i] = '-';
  }

  printf("\n\n\r");
  int k = 1;

  while(!palabra_correcta && k <= intentos) {
    printf("\rIntento %d: ", k);

    for(int j = 0; j < 5; j++) {
      palabra_ingresada[j] = getchar();
    }

    for(int l = 0; l < 5; l++) {
      for(int m = 0; m < 5; m++) {
        if(65 <= palabra_ingresada[l] && palabra_ingresada[l] <= 90) {
          palabra_ingresada[l] = palabra_ingresada[l] + 32;
        }

        if(palabra_ingresada[l] == palabra_secreta[m]) {
          if(resultado[l] == '-') {
            if(l == m) {
              resultado[m] = palabra_ingresada[l] - 32;
              aciertos++;
            } else {
              resultado[l] = palabra_ingresada[l];
            }
          }
        }
      }
    }

    printf("\n");
    printf("\rResultado: %s", resultado);
    printf("\n");
    printf("\n");

    if(aciertos == 5) {
      palabra_correcta = 1;
    } else {
      aciertos = 0;
      k++;

      for(int j = 0; j < 5; j++) {
        resultado[j] = '-';
      }
    }
  }

  if (palabra_correcta) {
    printf("\n\r¡Juego terminado! Palabra adivinada en %d intentos\n\r", k);
  } else {
    printf("\n\r¡Juego terminado! Has agotado los %d intentos. La palabra era %s \n", intentos, palabra_secreta);
  }

  system ("/bin/stty sane erase ^H");

  return 0;
}
