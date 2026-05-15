#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void sum_dig(int);

void main(void) {
  int pid1, pid2;
  int x = 0;
  char c;
  
  system ("/bin/stty raw");

  pid1 = fork();

  if (pid1 == 0) {
    sum_dig(1);
  } else {
    pid2 = fork();

    if (pid2 == 0) {
      sum_dig(2);
    } else {
      while (1) {
        printf("a.Suspender al hijo 2, ejecutar el hijo 1.\n");
        printf("b.Suspender al hijo 1, ejecutar el hijo 2.\n");
        printf("c.Dejar ejecutando ambos hijos.\n");
        printf("d.Finalizar ambos hijos y finalizar la ejecución.\n");
        printf("Ingrese una opción: %d", c);
        c = getchar();

        if (c == 'a') {
          kill(pid2, SIGSTOP);
        }
        if (c == 'b') {
          kill(pid1, SIGSTOP);
        }
        if (c == 'c') {
          kill(pid1, SIGCONT);
          kill(pid2, SIGCONT);
        }
        if (c == 'd') {
          kill(pid1, SIGKILL);
          kill(pid2, SIGKILL);
          system ("/bin/stty sane erase ^H");
        }
      }

    }
  }
}

void sum_dig(int id) {
    int tmp;
    int n, acc = 0;

    while(1) {
      tmp = n;

      while(tmp > 9) {
        acc += tmp % 10;
        tmp = tmp / 10;
      }

      acc += tmp;
      printf("\rHijo %d. La suma de todos los digitos de %d = %d\n", id, n, acc);
      acc = 0;
      n++;
    }

}
