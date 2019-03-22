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

char *obterTipoDeDados(char *);

bool existeId(char *);

char *obterIdentificador(char *);

void salvarIdentificador(char *, char *);

void salvarIdentificadorEValor(char *, char *, char *);

void atualizarValor(char *, char *);

char *obterValor(char *);

void erroAtribuicao(char *, char *);

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

char *obterTipoDeDados(char *id) {
	int i;
	for (i = 0; i < noDeIdentificadores; i++) {
		if (strcmp(id, identificadores[i].id) == 0) {
			break;
		}
	}
	return identificadores[i].tipoDeDados;
}

bool existeId(char *id) {
	for (int i = 0; i < noDeIdentificadores; i++) {
		if (strcmp(id, identificadores[i].id) == 0) {
			return true;
		}
	}
	return false;
}

void salvarIdentificador(char *id, char *tipoDeDadosDoIdentificador) {
	identificadores[noDeIdentificadores].id = id;
	identificadores[noDeIdentificadores].tipoDeDados = tipoDeDadosDoIdentificador;
	
	noDeIdentificadores++;
}

void salvarIdentificadorEValor(char *id, char *tipoDeDadosDoIdentificador, char *valor) {
	identificadores[noDeIdentificadores].id = id;
	identificadores[noDeIdentificadores].tipoDeDados = tipoDeDadosDoIdentificador;
	identificadores[noDeIdentificadores].valor = valor;
	
	noDeIdentificadores++;
}

void atualizarValor(char *id, char *valor) {
	int i;
	for (i = 0; i < noDeIdentificadores; i++) {
		if (strcmp(id, identificadores[i].id) == 0) {
			break;
		}
		if (i == noDeIdentificadores-1 && strcmp(id, identificadores[i].id) != 0) {
			erroIdentificadorInexistente(id);
			return;
		}
	}
	identificadores[i].valor = valor;
}

char *obterValor(char *id) {
	int i;
	for (i = 0; i < noDeIdentificadores; i++) {
		if (strcmp(id, identificadores[i].id) == 0) {
			break;
		}
		if (i == noDeIdentificadores-1 && strcmp(id, identificadores[i].id) != 0) {
			erroIdentificadorInexistente(id);
		}
	}
	return identificadores[i].valor;
}

void erroAtribuicao(char *tipoEsperado, char *tipoDeclarado) {
	printf("\nERRO NA LINHA %d : \nAtribuicao invalida! O tipo esperado eh '%s', mas o valor encontrado eh do tipo '%s' \n", yylineno, tipoEsperado, tipoDeclarado);
}

void erroIdentificadorInexistente(char *id) {
	printf("\nERRO NA LINHA %d : \nIdentificador '%s' nao existe.\n", yylineno, id);
}

void erroIdentificadorDuplicado(char *id) {
	printf("\nnERRO NA LINHA %d : \nIdentificador '%s' ja existente.\n", yylineno, id);
}