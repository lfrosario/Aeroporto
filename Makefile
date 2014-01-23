.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	ListaVetor \
		ListaVetorDinamico \
		ListaEncadeadaVetor \
		ListaEncadeadaVetorDinamico \
		ListaEncadeadaDinamica

ListaVetor:  ListaVetor.o
	gcc -o $@ $^

ListaVetorDinamico:  ListaVetorDinamico.o
	gcc -o $@ $^

ListaEncadeadaVetor:  ListaEncadeadaVetor.o
	gcc -o $@ $^

ListaEncadeadaVetorDinamico:  ListaEncadeadaVetorDinamico.o
	gcc -o $@ $^

ListaEncadeadaDinamica:  ListaEncadeadaDinamica.o
	gcc -o $@ $^

clean:
	rm *.o *.*~ ListaVetor \
		ListaVetorDinamico \
		ListaEncadeadaVetor \
		ListaEncadeadaVetorDinamico \
		ListaEncadeadaDinamica
