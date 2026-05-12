#include <xinu.h>

int ahorcado(void) {

	char palabra[] = "kernel", mascara[] = "******"; 
	int c, intentos = 3, aciertos = 0, i = 0, coincidencia = 0;
	int longitudPalabra = sizeof(palabra) - 1, repetido = 0;

	/* Decirle al sistema que el modo input es RAW */
	control(CONSOLE, TC_MODER, 0, 0);

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
				printf("\r %d \n", i);
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

	control(CONSOLE, TC_MODEC, 0, 0);
}
