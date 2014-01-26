#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

typedef struct Aeroporto {
	struct ListaAviao *aviao;
	struct Aeroporto *prox;
	int garagem;  //Idenficador da Garagem
}Aeroporto;

typedef struct ListaAviao {
	char familia;
	int passageiros;
	int posicao;  //Identificação do avião conforme ordem de pouso
}ListaAviao;


void inicializarAeroporto (Aeroporto *l);
char funcaoASCII (int x);
int consulta (int indiceAviao, Aeroporto *l);
void insere (char letra, int numPassageiro, Aeroporto *l);
int remover (int indiceRemover, Aeroporto *l);
void imprime (Aeroporto *l) ;
int ordenacao(Aeroporto *l);
