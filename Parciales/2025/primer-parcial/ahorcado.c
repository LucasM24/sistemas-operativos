#include <stdio.h>
#include <stdlib.h>	/* para las funciones system y exit */

int main() {

	char palabra[] = "kernel", mascara[] = "******"; 
	int c, intentos = 3, aciertos = 0, i = 0, coincidencia = 0;
	int longitudPalabra = sizeof(palabra) - 1, repetido = 0;

	/* Decirle al sistema que el modo input es RAW */
	system ("/bin/stty raw");

	while(1) {

		if (aciertos == longitudPalabra) { 
			printf("\r Ganaste! \n");
			break;
		}

		if (intentos < 1) {
			printf("\r Perdiste! \n");
			break;
		}

		printf("\r                                                          ");
		printf("\n");
		printf("\r Cantidad de intentos: %d \n", intentos);
		printf("\r Palabra %s \n", mascara);
		printf("\r c = %c ingrese una letra (0 para salir): ", c);
		c = getchar();
		printf("\r\n");

		if (c == '0')
			break;

		for(i = 0; i < longitudPalabra; i++) {
			if (mascara[i] == c && c != '*') {
				repetido = 1;
				break;
			} 		
		}

		if (!repetido) {
			for(i = 0; i < longitudPalabra; i++) {
				if (palabra[i] == c && mascara[i]) {
					mascara[i] = c;
					coincidencia = 1;
					aciertos++;
				} 		
			}

			if (!coincidencia) {
				intentos--;
			}
		}

		coincidencia = 0;
		repetido = 0;
	}

	system ("/bin/stty sane erase ^H");
}
