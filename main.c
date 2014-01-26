#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int capacidade = 20;
int indice = 0;
int posicaoAviao = 0;  

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

void inicializarAeroporto (Aeroporto *l) {
	l->prox = NULL;
	l->aviao=NULL;
	l->garagem=0;
}

/*char funcaoASCII(int x){ //Função que gera uma letra da tabela ASCII
	char letra;
	if(x < 78){
		if(x < 72){
			if(x==65){
				letra='A';
				return letra;
			}else if(x==66){
				letra='B';
				return letra;
			}else if(x==67){
				letra='C';
				return letra;
			}else if(x==68){
				letra='D';
				return letra;
			}else if(x==69){
				letra='E';
				return letra;
			}else if(x==70){
				letra='F';
				return letra;
			}else if(x==71){
				letra='G';
				return letra;
			}
		}else{
			if(x==72){
				letra='H';
				return letra;
			}else if(x==73){
				letra='I';
				return letra;
			}else if(x==74){
				letra='J';
				return letra;
			}else if(x==75){
				letra='K';
				return letra;
			}else if(x==76){
				letra='L';
				return letra;
			}else if(x==77){
				letra='M';
				return letra;
			}
			}
		}else{
			if(x < 85){
				if(x==78){
					letra='N';
					return letra;
				}else if(x==79){
					letra='O';
					return letra;
				}else if(x==80){
					letra='P';
					return letra;
				}else if(x==81){
					letra='Q';
					return letra;
				}else if(x==82){
					letra='R';
					return letra;
				}else if(x==83){
					letra='S';
					return letra;
				}else if(x==84){
					letra='T';
					return letra;
				}
			}else{
				if(x==85){
					letra='U';
					return letra;
				}else if(x==86){
					letra='V';
					return letra;
				}else if(x==87){
					letra='W';
					return letra;
				}else if(x==88){
					letra='X';
					return letra;
				}else if(x==89){
					letra='Y';
					return letra;
				}else if(x==90){
					letra='Z';
					return letra;
				}
			}
	}
} */

int consulta(int indice, Aeroporto *l){
	
	//clockPorSegundo ini = clock(); //clock_t
	Aeroporto *verificador;
	verificador=l;
	if(l==NULL){
		return 0;
	}else{
		while(verificador!=NULL){
			if(verificador->aviao->posicao==indice){
				return verificador->garagem;
			}else{
				verificador=verificador->prox;
			}
		}
		if(verificador==NULL){
			return 0;
		}
	}
	return 0;
	//printf("\nFuncao executou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

//OK
void insere (char letra, int numPassageiro, Aeroporto *l){
	ListaAviao *novo;
	Aeroporto *garagemProx, *hangar;
	int resposta;
	
	//resposta = consulta (letra, numPassageiro, l);
	//printf ("Consultado\n");
	
	if (/*resposta == 0 && */capacidade > 0) {
		novo = (ListaAviao*) malloc (sizeof(ListaAviao));
		novo->familia = letra;
		novo->passageiros = numPassageiro; 	
		novo->posicao = indice + 1; 
		indice = novo->posicao;
		
		if (l->prox == NULL) { //Insercao Lista Vazia
			hangar = (Aeroporto*) malloc (sizeof(Aeroporto));
			hangar->garagem = indice;
			hangar->aviao = novo;
			hangar->prox = NULL;
			l->prox = hangar;
			//TESTAR AQUI AS FUNCIONSALIDADE DAS ESTRUTURAS			
		} else {
			garagemProx = l; // Uma copia de l nada mais!!!
			while (garagemProx->prox != NULL) {			
				garagemProx = garagemProx->prox;
			}
			if (garagemProx != NULL && garagemProx->prox == NULL) { // Qual insercao eh essa???
				hangar = (Aeroporto*) malloc (sizeof(Aeroporto));
				hangar->garagem = indice; // adicionando o mesmo indice novamente?
				hangar->aviao = novo; // apontando para o mesmo novo do outro hangar?
				hangar->prox = NULL;
				garagemProx->prox = hangar; //Criou novo Aeroporto com Aviao!
			}
		}
	capacidade--;			
	} else {
		printf ("Lista Cheia!!! \n");
	}
	printf ("Inserido\n");
}

int remover (int numPassageiro, Aeroporto *l){
	Aeroporto *garagemProx, *auxiliar, *k;
	ListaAviao *aviaoRm; 
	int resposta;
	resposta = consulta(indice, l); 
	
	if (resposta!=0){
		garagemProx=l;
		auxiliar=NULL;
		while(garagemProx->prox!=NULL){
			if (garagemProx->garagem==resposta){	
				auxiliar->prox=garagemProx->prox; 
				if (auxiliar == NULL) //Primeiro elemento da lista
					l->prox=auxiliar->prox;
				aviaoRm=garagemProx->aviao;
				free(aviaoRm); 
				free(garagemProx);
				for(k=auxiliar->prox; k!=NULL; k=k->prox){
					k->garagem = k->garagem-1; 
				}
				return 1;
			}else{ 
				auxiliar = garagemProx;
				garagemProx=garagemProx->prox;
			}
		}
	}
	return 0;
}

//OK
void imprime (Aeroporto *l) {
	Aeroporto *listar;
	listar = l;

	if (l->prox == NULL)
		printf ("\n LISTA VAZIA\n");

	while (listar->prox != NULL) {
		printf ("\nAeroporto: %d Familia: %c Passageiros: %d \n", listar->garagem,  listar->prox->aviao->familia, listar->prox->aviao->passageiros);
		listar = listar->prox;
	}

}

//OK
int ordenacao(Aeroporto *l){
	Aeroporto *prim, *seg, *ult;
	ListaAviao *avi1, *avi2;
	
	prim = seg = ult = NULL;
	avi1 = avi2= NULL;
	
	if (l->prox == NULL) {
		printf ("Aeroporto Vazio \n");
		return 0;
	} else {
		ult = l;
		while (ult->prox != NULL)
			ult = ult->prox;
		prim = l;
		while (prim->prox != ult) {
			seg = prim->prox;
			avi1 = prim->prox->aviao;
			avi2 = seg->prox->aviao;
			if (avi1->familia == avi2->familia && avi1->passageiros <= avi2->passageiros) { // São da mesma familia e comportam a mesma quantidade de passageiros
				prim = prim->prox;
			} else if (avi1->familia == avi2->familia && avi1->passageiros > avi2->passageiros) {  // São da mesma familia e AV1 suporta mais passageiros do que AV2
						prim->aviao = avi2;
						seg->aviao = avi1;
						prim = l;
			} else if (avi1->familia < avi2->familia) { // São de familias diferente, sendo AV1  com letra menor que AV2
						prim = prim->prox;
			} else if (avi1->familia > avi2->familia) {  // São de familias diferente, sendo AV1  com letra maior que AV2
						prim->prox->aviao = avi2;
						seg->prox->aviao = avi1;
						prim = l;
			}
		}
	}
	printf ("\nAeroporto Ordenado!!!!!!\n");
	return 1;
}

int main(){
	Aeroporto l;
	//char letra;
	//int letra_num=0; // recebe um numero decimal e transforma em letra atraves da tabela ascII
	//int indiceRemover; // recebe o indice que será removido
	//int numPassageiro;
	inicializarAeroporto(&l);
	insere ('c', 3, &l);
	insere ('b', 4, &l);
	insere ('a', 5, &l);
	ordenacao (&l);
	imprime (&l);
	//
	//imprime (&l);
/*	while(true){ 
		if(l.prox!=NULL){
		printf("AQUI 2");
		indiceRemover=rand()%+1;
		remover(indiceRemover,&l);
		}
		printf("AQUI 3");
		imprime(&l);
		letra_num=rand()%36+65;
		letra=funcaoASCII(letra_num);
		numPassageiro=rand()%800;
		insere(letra,numPassageiro,&l);
		ordenacao(&l);
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
		
	}*/
return 0;
}
