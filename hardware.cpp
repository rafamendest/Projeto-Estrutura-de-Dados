#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main (void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	FILE *file;
	DIR *dir;
    struct dirent *lsdir;

    dir = opendir("C:\\Users\\User01\\Desktop\\Hardware 1.3");
	int op;
	char nome[30];
	char tipo[30];
	char fabricante[30];
	float preco;
	int continuar = 1;
	char info[1000];
	int menu = 1;
	int ret;
	char nomesalva[100];
	char nomeler[100];
	char nomedeleta[100];
	
	
	while (menu == 1) {
	
	printf("\n\nControle de estoque.\n");
	
	printf("\nSelecione uma das opções a seguir.\n");
	printf("1 - Inserir\n");
	printf("2 - Procurar\n");
	printf("3 - Alterar arquivos\n");
	printf("4 - Deletar produtos arquivados\n");
	printf("5 - Sair do programa\n");
	
	scanf("%i", &op);
	
	
	
	if (continuar == 2) {
		continuar = 1;
	}
	
	switch(op) {
		
		case 1:
			
			
			
			while (continuar == 1) {
				
				printf("\nDigite um nome para o arquivo: \n");
				scanf("%s", &nomesalva);
				file = fopen(nomesalva, "a");
				printf("Digite o tipo do produto: \n");
				scanf("%s", &tipo);
				fprintf(file, "\n\nTipo do produto: %s", tipo);
			
				printf("Digite o fabricante do produto: \n");
				scanf("%s", &fabricante);
				fprintf(file, "\nFabricante do produto: %s", fabricante);
			
				printf("Digite o nome do produto: \n");
				scanf("%s", &nome);
				fprintf(file, "\nNome do produto: %s", nome);
				
				printf("Digite o preço do produto: \n");
				scanf("%f", &preco);
				fprintf(file, "\nPreço do produto: R$%.2f", preco);
				fprintf(file, "\n\n-----------------------------------------------------------");
			
				printf("\nAdicionando...");
				sleep(2);
				printf("\nProduto adicionado!\n");
				fclose(file);
				printf("\nDeseja adicionar mais produtos? 1 - Sim! 2 - Não!\n");
				scanf("%i", &continuar);
		}
		break;
		
		case 2:
			if (file != NULL) {
			/* print all the files and directories within directory */
			printf("Você tem esses produtos");
    		while ( ( lsdir = readdir(dir) ) != NULL )  {			
       		printf ("%s\n", lsdir->d_name);
    	}
    		closedir(dir);
			printf("\nQual deseja abrir? ");
			scanf("%s", nomeler);
			printf("Carregando arquivo...");
			sleep(3);
			file = fopen(nomeler,"r");	
  			while( (fgets(info, sizeof(info), file))!=NULL ) {
   			printf("%s", info);
   		}
   			} if (file == NULL) {
   		printf("\nArquivo corrompido ou não criado.");
	   }
   			
 			fclose(file);
		break;
		
		case 3:
				printf("\nDigite o nome do arquivo que deseja alterar: \n");
				scanf("%s", &nomesalva);
				file = fopen(nomesalva, "w");
				printf("Digite o novo tipo do produto: \n");
				scanf("%s", &tipo);
				fprintf(file, "\n\nTipo do produto: %s", tipo);
			
				printf("Digite o novo fabricante do produto: \n");
				scanf("%s", &fabricante);
				fprintf(file, "\nFabricante do produto: %s", fabricante);
			
				printf("Digite o novo nome do produto: \n");
				scanf("%s", &nome);
				fprintf(file, "\nNome do produto: %s", nome);
				
				printf("Digite o novo preço do produto: \n");
				scanf("%f", &preco);
				fprintf(file, "\nPreço do produto: R$%.2f", preco);
				fprintf(file, "\n\n-----------------------------------------------------------");
			
				printf("\nAlterando...");
				sleep(2);
				printf("\nProduto alterado!\n");
				fclose(file);
		
		break;
		
		case 4:
				/* print all the files and directories within directory */
			printf("Você tem esses produtos");
    		while ( ( lsdir = readdir(dir) ) != NULL )  {			
       		printf ("%s\n", lsdir->d_name);
    	}
    		closedir(dir);
			printf("\nQual nome do arquivo que deseja deletar? ");
			scanf("%s", &nomedeleta);
			printf("Deletando... aguarde!");
			sleep(3);
			ret = remove(nomedeleta);
			printf("\nDeletado com sucesso!");
		break;
		
		case 5:
			printf("Saindo do programa...");
			sleep(2);
			menu = 2;
		break;
		
		default:
			printf("Opção inválida!");
		}
		if (menu == 1) {
			printf("\n\nDeseja voltar para o menu? 1 - Sim! 2 - Não!\n");
			scanf("%i", &menu);
		} 
	}
	printf("\nFim do programa.\n");

	system("pause");
	return 0;
}



