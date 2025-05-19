
#include <stdio.h>
#include <stdlib.h>	/* para las funciones system y exit */

int main() {

	int i, c, n;      /* c: letra, n: cant de letras */
	char palindromo[80];
	int hasta, palindromo_ok;

	/* Decirle al sistema que el modo input es RAW */
	system ("/bin/stty raw");

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

	/* verificar si es palindromo */
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
		printf("\n\r palabra: %s es un palindromo\n\r", palindromo);
	else
		printf("\n\r palabra: %s NO ES un palindromo\n\r", palindromo);

	system ("/bin/stty sane erase ^H");
}

