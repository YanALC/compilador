#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char TiposDeDados[100];
int noDeIdentificadores = 0;

extern int yylineno;

void listarIdentificadores();

void limparTiposDeDados();

void salvarTipoDeDados(const char *);

char *obterTiposDeDados();

bool duplicado(char *);

char *obterIdentificador(char *);

void salvarIdentificador(char *, char *);

void salvarIdentificador(char *, char *, char *);

void atualizarValor(char *, char *);

char *obterValor(char *);

void erroAtribuicao(char *);

void erroIdentificadorInexistente(char *);

void erroIdentificadorDuplicado(char *);

struct Identificador {
	char *id;
	char *tipoDeDados;
	char *valor;
} identificadores[100];

void listarIdentificadores() {
	for (int i = 0; i < noDeIdentificadores; i++) {
		printf("%s\n", identificadores[i].id);
	}
}

void limparTiposDeDados() {
	for (int i = 0; TiposDeDados[i] != '\0'; i++) {
		TiposDeDados[i] = '\0';
	}
}

void salvarTipoDeDados(const char *tiposDeDados) {
	for (int i = 0; tiposDeDados[i] != '\0'; i++) {
		TiposDeDados[i] = tiposDeDados[i];
	}
}

char *obterTiposDeDados() {
	return TiposDeDados;
}

bool duplicado(char *id) {
	for (int i = 0; i < noDeIdentificadores; i++) {
		if (strcmp(id, identificadores[i].id) == 0) {
			return true;
		}
	}
	return false;
}

/*
char *obterIdentificador(char *identificadorDeVetor) {
    char *identificadorExtraido;
    int i = 0;

    while (identificadorDeVetor[i] != '[') {
        identificadorExtraido[i] = identificadorDeVetor[i];
        i++;
    }
    identificadorExtraido[i] = '\0';

    return identificadorExtraido;
}
*/
void salvarIdentificador(char *id, char *tipoDeDadosDoIdentificador) {
	identificadores[noDeIdentificadores].id = id;
	identificadores[noDeIdentificadores].tipoDeDados = tipoDeDadosDoIdentificador;
	
	noDeIdentificadores++;
}

void salvarIdentificador(char *id, char *tipoDeDadosDoIdentificador, char *valor) {
	identificadores[noDeIdentificadores].id = id;
	identificadores[noDeIdentificadores].tipoDeDados = tipoDeDadosDoIdentificador;
	identificadores[noDeIdentificadores].valor = valor;
	
	noDeIdentificadores++;
}

void atualizarValor(char *id, char *valor) {
	int idx;
	for (idx = 0; idx < sizeof(identificadores); idx++) {
		if (identificadores[idx].id == id) {
			return;
		}
		if (idx == sizeof(identificadores) - 1 && identificadores[idx].id != id) {
			erroIdentificadorInexistente(id);
		}
	}
	identificadores[idx].valor = valor;
}

char *obterValor(char *id) {
	int idx;
	for (idx = 0; idx < sizeof(identificadores); idx++) {
		if (identificadores[idx].id == id) {
			return;
		}
		if (idx == sizeof(identificadores) - 1 && identificadores[idx].id != id) {
			erroIdentificadorInexistente(id);
		}
	}
	return identificadores[idx].valor;
}

void erroAtribuicao(char *tipoDeDados) {
	printf("\nERRO NA LINHA %d : \nAtribuição inválida! O esperado era '%s', mas foi encontrado %s \n", yylineno, TiposDeDados, tipoDeDados);
	exit(0);
}

void erroIdentificadorInexistente(char *id) {
	printf("\nERRO NA LINHA %d : \nO identificador não existe %s \n", yylineno, id);
	exit(0);
}

void erroIdentificadorDuplicado(char *id) {
	printf("\nnERRO NA LINHA %d : \nIdentificador duplicado '%s' encontrado.\n", yylineno, id);
	exit(0);
}