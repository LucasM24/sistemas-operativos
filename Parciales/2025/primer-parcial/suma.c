#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>

void sumar_digitos(int n, int id) {
  int resultado = 0;
  int dividendo = n;

  if(dividendo >= 10) {
    while(dividendo >= 10) {
      resultado += dividendo % 10;
      dividendo /= 10;
    }

    resultado += dividendo;
  } else {
    resultado = dividendo;
  }

  printf("\rHijo %d, La suma de todos los dígitos de %d es: %d\n", id,n, resultado);

}

int main(void) {
  int pid;
  int pid2;
  int x = 1;
  int y = 1;
  char opcion;

  system ("/bin/stty raw");
  pid = fork();

  if(pid == 0) {
    //printf("Es es hijo 1 pid: %d\n",pid);
    while(1){
      sumar_digitos(x, 1);
      x++;
    }
  } else {

    pid2 = fork();

    if (pid2 == 0) {
     // printf("Es es hijo 2 pid: %d\n",pid2);
      while(1){
        sumar_digitos(y, 2);
        y++;
      }
    } else {
      while(1) {
        printf("\r%c\n", opcion);
        opcion = getchar();

        if(opcion == 'a') {
          kill(pid2, SIGSTOP); 
          kill(pid, SIGCONT); 
        }
        if(opcion == 'b'){
          kill(pid, SIGSTOP); 
          kill(pid2, SIGCONT); 
        }
        if(opcion == 'c'){
          kill(pid, SIGCONT); 
          kill(pid2, SIGCONT); 
        }
        if(opcion == 'q'){
          kill(pid, SIGKILL); 
          kill(pid2, SIGKILL); 
          system ("/bin/stty sane erase ^H");
          printf("\n");
          break;
        }
      } 
    }
  }

  return 0;
}
