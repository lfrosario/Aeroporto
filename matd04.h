#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

void inicializarAeroporto (Aeroporto *l);
char funcaoASCII (int x);
int consulta (int indiceAviao, Aeroporto *l);
void insere (char letra, int numPassageiro, Aeroporto *l);
int remover (int indiceRemover, Aeroporto *l);
void imprime (Aeroporto *l) ;
int ordenacao(Aeroporto *l);
