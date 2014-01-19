#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int capacidade = 20;
int indice = 0;

typedef struct Aeroporto {
	struct ListaAviao *aviao;
	struct Aeroporto *prox;
	int garagem;
}Aeroporto;

typedef struct ListaAviao {
	char familia;
	int passageiros;
	int posicao;
}ListaAviao;

void inicializarAeroporto (Aeroporto *l) {
	l = NULL;	
}
int consulta(char letra, int numPassageiro, Aeroporto *l){
	Aeroporto *verificador;
	verificador=l;
	if(l==NULL){
		return 0;
	}else{
		while(verificador!=NULL){
			if(verificador->aviao->familia==letra){
				if(verificador->aviao->passageiros==numPassageiro){
					return verificador->garagem;
				}
			}else{
				verificador=verificador->prox;
			}
		}
		if(verificador==NULL){
			return 0;
		}
	}
	return 0;
}
void insere (char letra, int numPassageiro, Aeroporto *l){
	ListaAviao *novo;
	Aeroporto *garagemProx, *hangar;
	int resposta;
	resposta = consulta(letra,numPassageiro,l);
	if (resposta == 0 && capacidade > 0){
		novo = (ListaAviao*)malloc(sizeof(ListaAviao));
		novo->familia=letra;
		novo->passageiros=numPassageiro; 	
		novo->posicao=indice +1; 
		indice=novo->posicao;
		if (l==NULL){
			hangar = (Aeroporto*)malloc(sizeof(Aeroporto));
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
				hangar = (Aeroporto*)malloc(sizeof(Aeroporto));
				hangar->garagem=indice;
				hangar->aviao=novo;
				hangar->prox=NULL;
				garagemProx->prox=hangar;
			}
		}
	capacidade--;			
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


void imprime (Aeroporto l) {
	Aeroporto *listar;
	listar = l;

	if (l == NULL)
		printf ("\n LISTA VAZIA\n");

	while (listar != NULL)
		printf ("\nAeroporto: %d Familia: %c Passageiros: %d \n", listar->garagem,  listar->aviao->familia, listar->aviao->passageiros);

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
