#include <string.h>
#include <stdbool.h>
#include "../yacc/compilador.tab.h"

bool atribucaoValida(char *tipoDeDados) {
	return strcmp(tipoDeDados, TiposDeDados) == 0;
}

char *intToAscii(int numero) {
	static char buffer[50];
	snprintf(buffer, sizeof(buffer), "%d", numero);
	return buffer;
}

char *floatToAscii(float numero) {
	static char buffer[50];
	snprintf(buffer, sizeof(buffer), "%f", numero);
	return buffer;
}

char *charToAscii(char caractere) {
	static char buffer[50];
	snprintf(buffer, sizeof(buffer), "%c", caractere);
	return buffer;
}
