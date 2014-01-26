#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int capacidade = 20;
int indice = 1; // Numero de garagem do Aeroporto
int posicaoAviao = 0; // Numero de Aviões no aeroporto 

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

int consulta (int indiceAviao, Aeroporto *l){
	
	//clockPorSegundo ini = clock(); //clock_t
	Aeroporto *verificador;
	verificador = l;
	if (l->prox == NULL) {
		return 0;
	} else {
		while (verificador->prox != NULL) {
			if (verificador->prox->aviao->posicao == indiceAviao){
				return verificador->prox->garagem;
			}else{
				verificador = verificador->prox;
			}
		}
		if (verificador == NULL){
			return 0;
		}
	}
	return 0;
	//printf("\nFuncao executou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

//OK
void insere (char letra, int numPassageiro, Aeroporto *l) {
	ListaAviao *novo;
	Aeroporto *garagemProx, *hangar;
	
	if (capacidade > 0) {
		novo = (ListaAviao*) malloc (sizeof(ListaAviao));
		novo->familia = letra;
		novo->passageiros = numPassageiro; 	
		novo->posicao = posicaoAviao + 1;
		posicaoAviao = novo->posicao;
		
		if (l->prox == NULL) { //Insercao Lista Vazia
			hangar = (Aeroporto*) malloc (sizeof(Aeroporto));
			hangar->garagem = indice;
			printf ("\nHangar: %d\n", hangar->garagem);
			hangar->aviao = novo;
			hangar->prox = NULL;
			l->prox = hangar;
			indice = hangar->garagem + 1;
			printf ("\nIndice: %d\n", indice);
			//TESTAR AQUI AS FUNCIONSALIDADE DAS ESTRUTURAS			
		} else {
			garagemProx = l; // Uma copia de l nada mais!!!
			while (garagemProx->prox != NULL) {			
				garagemProx = garagemProx->prox;
			}
			if (garagemProx != NULL && garagemProx->prox == NULL) { // Qual insercao eh essa???
				hangar = (Aeroporto*) malloc (sizeof(Aeroporto));
				hangar->garagem = indice; // adicionando o mesmo indice novamente?
				printf ("\nHangar: %d\n", hangar->garagem);
				hangar->aviao = novo; // apontando para o mesmo novo do outro hangar?
				hangar->prox = NULL;
				garagemProx->prox = hangar; //Criou novo Aeroporto com Aviao!
				indice = hangar->garagem + 1;
				printf ("\nIndice: %d\n", indice);
			}
		}
	capacidade--;
	} else {
		printf ("Lista Cheia!!! \n");
	}
	printf ("Inserido\n");
}

<<<<<<< HEAD

int remover (int indiceAviao, Aeroporto *l){
	Aeroporto *garagemRmv, *auxiliar, *k;
=======
int remover (int indiceRemover, Aeroporto *l){
	Aeroporto *garagemProx, *auxiliar, *k;
>>>>>>> e0890abb3f2e9468f9948baf334e22991f5e3300
	ListaAviao *aviaoRm; 
	int resposta;
	resposta = consulta (indiceRemover, l); 
	
	if (resposta != 0){
		garagemRmv = l;
		auxiliar = NULL;
<<<<<<< HEAD
		while (garagemRmv->prox != NULL) {
			if (garagemRmv->prox->garagem == resposta){	
				auxiliar = garagemRmv->prox; 
				if (auxiliar->garagem == 1){ //Primeiro elemento da lista
					l->prox = auxiliar->prox;
				aviaoRm = auxiliar->aviao;
				free (aviaoRm); 
				free (auxiliar);
				} else if(auxiliar->garagem !=1) {
				garagemRmv->prox=auxiliar->prox; 
				aviaoRm=auxiliar->aviao;
				free(aviaoRm); 
				free(auxiliar);
				}
				for (k = l->prox; k != NULL; k = k->prox){
					k->garagem = k->garagem-1; 
=======
		while (garagemProx->prox != NULL) {
			if (garagemProx->prox->garagem == resposta){	
				auxiliar = garagemProx->prox; 
				if (auxiliar->garagem == 1) //Primeiro elemento da lista
					l->prox = auxiliar->prox;
				aviaoRm = auxiliar->aviao;
				free (aviaoRm);
				k = auxiliar;
				while (k != NULL) {
				 	k->garagem = k->garagem - 1;
					k = k->prox;
>>>>>>> e0890abb3f2e9468f9948baf334e22991f5e3300
				}
				//for (k = auxiliar; k != NULL; k = k->prox)
					//	k->garagem = k->garagem - 1;
				free (auxiliar);
				printf ("\nAviao Removido!!!!!!!\n");
				return 1;
			} else {
			
				auxiliar = garagemRmv->prox;
				garagemRmv = garagemRmv->prox;
			}
		}
	}
	return 0;
}

/*int remover (int numPassageiro, Aeroporto *l){
	Aeroporto *garagemProx, *auxiliar, *k;
	ListaAviao *aviaoRm; 
	int resposta;
	resposta = consulta(indice, l); 
	
	if (resposta!=0){
		garagemRmv=l;
		auxiliar=NULL;
		while(garagemRmgaragemRmvv->prox!=NULL){
			if (garagemRmv->garagem==resposta){	
				auxiliar->prox=garagemRmv->prox; 
				aviaoRm=garagemRmv->aviao;
				free(aviaoRm); 
				free(garagemRmv);
				for(k=auxiliar->prox; k!=NULL; k=k->prox){
					k->garagem = k->garagem-1; 
				}
				return 1;
			}else{ 
				auxiliar = garagemRmv;
				garagemProx=garagemRmv->prox;
			}
		}//Fim While
	}
	return 0;
}
*/

//OK
void imprime (Aeroporto *l) {
	Aeroporto *listar;
	listar = l;

	if (l->prox == NULL)
		printf ("\n LISTA VAZIA\n");

	while (listar->prox != NULL) {
		printf ("\nAeroporto: %d Familia: %c Passageiros: %d Posicao Aviao: %d\n", listar->prox->garagem,  listar->prox->aviao->familia, listar->prox->aviao->passageiros, listar->prox->aviao->posicao);
		listar = listar->prox;
	}
	printf ("\nImprimido!!!!!\n");

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
	insere ('z', 5, &l);
	insere ('a', 6, &l);
	insere ('a', 7, &l);
	insere ('a', 8, &l);
	imprime (&l);
	remover (1, &l);
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
