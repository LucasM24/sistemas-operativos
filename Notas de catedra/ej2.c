
#include <xinu.h>

void leer_p(void);
void procesar_p(void);

char palindromo[80];
int n = 0;	/* cant de letras */

void es_palindromo(void)
{
	n = 0;
	control(CONSOLE, TC_MODER, 0, 0);
	resume(create(leer_p, 1024, 20, "leer palindromo", 0, NULL));
	receive();

	resume(create(procesar_p, 1024, 20, "procesar palindromo", 0, NULL));
	receive();
	control(CONSOLE, TC_MODEC, 0, 0);
}

void leer_p(void)
{
	int i;
	int c = 0;

	printf("Ingrese una palabra y presione ENTER: ");
	i = 0;
	while (c != 13) {
		c = getchar();
		if (c == 13) {
			palindromo[i] = '\0'; /* fin de linea */
			break;
		}
		palindromo[i] = c;
		i++;
	}
	n = i-1;
}

void procesar_p(void)
{
	int i;
	int hasta;
	int palindromo_ok;

	palindromo_ok = 1;
	hasta = n/2;
	for (i=0; i<=hasta; i++) {
		if (palindromo[i] != palindromo[n]) {
			palindromo_ok = 0;
			break;
		}
		n = n - 1;
	}
	if (palindromo_ok)
		printf("\n\rpalabra: %s es un palindromo\n\r", palindromo);
	else
		printf("\n\rpalabra: %s NO ES un palindromo\n\r", palindromo);
}

