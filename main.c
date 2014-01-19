#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int capacidade=20;
int indice=0;
typedef struct Listanome *aeroporto;
typedef struct Listanome *listaaviao;
typedef struct Aeroporto {
	struct ListaAviao *aviao;
	struct Aeroporto *prox;
	int garagem;
} Aeroporto;

typedef struct ListaAviao{
char familia;
int passageiros;
int posicao;
} ListaAviao;
void inicializarAeroporto(Aeroporto *l){
l=NULL;	
}

void insere (char letra, int numPassageiro, Aeroporto *l){
	ListaAviao *novo;
	Aeroporto *garagemProx, *hangar;
	int resposta;
	//resposta = consulta(l);
	if (resposta==0){
		novo = (listaaviao)malloc(sizeof(ListaAviao));
		novo->familia=letra;
		novo->passageiros=numPassageiro; 	
		novo->posicao=indice +1; 
		indice=novo->posicao; 
		if (l==NULL){
			hangar = (aeroporto)malloc(sizeof(Aeroporto));
			hangar->garagem=indice;
			hangar->aviao=novo;
			hangar->prox=NULL;
			l=hangar;
		}else{
			garagemProx=l;
			while(garagemProx->prox!=NULL){
				garagemProx=garagemProx->prox;
			}
			if(garagemProx!=NULL && garagemProx->prox==NULL){
				hangar = (aeroporto)malloc(sizeof(Aeroporto));
				hangar->garagem=indice;
				hangar->aviao=novo;
				hangar->prox=NULL;
				garagemProx->prox=hangar;
			}
		}
			
	}
}

void remove (char letra, int numPassageiro, Aeroporto *l){
	Aeroporto *garagemProx, *hangar;
	int resposta;
	int garagem;
	char = chaveFamilia;
	int = chavePassageiros;
	
	if ((l!=NULL) && (consulta!=0))
		garagemProx->prox=hangar->prox;
		free
}

int main(){
	Aeroporto l;
	char letra;
	int numPassageiro;	
	inicializarAeroporto(&l);
	while(true){
		//letra=rand()%36+65;
		//numPassageiro=rand()%800;
		//remove();
		//letra=rand()%36+65;
		//numPassageiro=rand()%800;
		//insere();
		//ordena();
		sleep(5);
		//remove();
		//insere();
		//ordena();
		sleep(5);
		//remove();
		//insere();
		//insere();
		//insere();
		//insere();
		//ordena();
		
	}	
return 0;
}
