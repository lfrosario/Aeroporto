int main(int argc, char *argv[]) {

	FILE *arquivo;
	int linha, coluna, celula;
	int x, y;
	int **matriz;

	//BEGIN verificação dos argumentos)
	if (argc > 3)
	{
		printf("Numero de argumentos errado, por favor, digite o nome do arquivo e a quantidade de gerações ou deixe em brando para configuração padrão.\n");
		return EXIT_SUCCESS;
	}
	if (argc == 1){
		argv[1] = "default.txt";
		argv[2] = "3";
		printf("Assumindo arquivo padrao e quantidade de gerações padrão.\n");
	}
	if (argc == 2){
		argv[2] = "3";
		printf("Assumindo quantidade de gerações padrão.\n");
	}
	//END verificação dos argumentos


	//BEGIN abrir, ler e fechar arquivo

	if ((arquivo = fopen(argv[1], "r")) == NULL)
	{
		printf("Erro ao abrir o arquivo/n");
		return EXIT_SUCCESS;
	}
	//Le as dimensoes
	fscanf(arquivo, "%d", &linha);
	fscanf(arquivo, "%d", &coluna);
	//Aloca a Matriz
	matriz = alocaMatriz(linha, coluna);

	//Begin Atribuindo as celulas na matriz
	for(x = 0; x < linha; x++)
	{
		for(y = 0; y < coluna; y++)
		{
			fscanf(arquivo, "%d", &celula);
			matriz[x][y] = celula;
		}
	}
	//End atribuição das celulas na matriz
	
	//Begin Imprimindo e executando 
	int g = atoi(argv[2]);
	int z;
	for(z = 0; z < g ; z++)
	{
		printf("Geração numero %d\n",z);
		imprimiGeracao(linha, coluna, matriz);	
		geradorDeGeracao(linha,coluna, matriz);
	}
	//Desaloca a Matriz
	matriz = liberaMatriz(linha, coluna, matriz);

	fclose(arquivo);
	//END abrir, ler e fechar arquivo

	return EXIT_SUCCESS;
}