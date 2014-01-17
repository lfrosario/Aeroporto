#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Aeroporto{
struct ListaAviao *aviao;
struct Aeroporto *prox;
int garagem;
}Aeroporto;

typedef struct ListaAviao{
char familia;
int passageiros;
int indice;
} ListaAviao;

int main () {
	return 0;
}
