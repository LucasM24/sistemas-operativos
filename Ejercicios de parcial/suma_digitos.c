#include <stdio.h>

void main(void) {
    /* declaramos un arreglo para que contenga valores enteros */
    int cant[10];

    int n = 10;
    int i;

    for (i=0; i<n; i++) {
	    cant[i] = i;
	    printf("Valor: %d \n", cant[i]);
    }
}
