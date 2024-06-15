#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar()//Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação das variáveis 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação das variáveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a strings (escanear strings)
	
	strcpy(arquivo, cpf);//responsável por copiar os valores
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");//abre o arquivo e "w" significa write(escrever um novo conteúdo)
	fprintf(file,cpf);// salva o valor da variável (cpf)
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo,"a"); //abre o arquivo e diz que é para atualizar informações
	fprintf(file,","); //adciona a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//pede as informações do usuário
	scanf("%s", nome);//salva as informações do usuário
	
	file = fopen(arquivo,"a");//abrir arquivo, "a" quer dizer irá atualizar as inform. do arquivo
	fprintf(file,nome);//adicionar na variável "nome" 
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");//adiciona a virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobre nome a ser cadastrado: ");//pede ao usuário suas informações 
	scanf("%s", sobrenome);//salva as informações do usuário
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,sobrenome);//adiciona o sobrenome 
	fclose(file);//fecha o arquivo 
	
	file= fopen (arquivo,"a");//abre o arquivo
	fprintf(file,",");//adiciona o sobrenome 
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//pede as informações do usuário
	scanf("%s", cargo);//salva as informações do usuário 
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file, cargo);//adiciona o cargo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,".");//adiciona o ponto
	fclose(file);//fecha o arquivo
		
	
}

int consultar()//função responsável por consultar os usuários do sistema 
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
	//inicio da criação das strings
	char cpf[40];
	char conteudo[200];
	//final da criação das strings
	
	printf("Digite o CPF a ser consultado: ");//coleta informações do usuário
	scanf("%s", cpf);//escaneia as informações
	
	FILE *file;//criando arquivo
	file = fopen(cpf,"r");//lendo o arquivo
	
	if (file == NULL);//ordem para se o arquivo for igual a nulo, avisar que não foi possivel abrir
	{	
		system("cls");//limpa a tela 
		printf("Não foi possível abrir o arquivo, não localizado!\n\n");//informa que ao usuário
		
	}
	
	while(fgets(conteudo, 200,file) != NULL)//busca as informações para passao ao usuário
	{	
		system("cls");
		printf("Aqui estão as informações do usuário: ");//manda as informações para o usuário
		printf("%s",conteudo);//manda as informações para o usuário
		printf("\n\n");
		fclose(file);//fecha o arquivo 
	}
	
	system("pause");//pausa o sistema
	
	
	
}

int deletar()//função0 responsável por deletar os usuários do sistema
{
	char cpf[40];//cria a string
	
	printf("Digite o CPF do usuário a ser deletado: ");//coletar escolha do usuário
	scanf("%s",cpf);//escanear e salvar na string a escolha do ususário
	
	remove(cpf);//remover o conteúdo
	
	FILE *file;
	file = fopen(cpf, "r");//abrir o arquivo, "r" significa ler
	
	
	if(file == NULL)//o que fazer caso a escolha do usuário for nula
	{
		system("cls");//limpa a tela
		printf("O usuário não se encontra no sistema!.\n");//informa ao usuário
		system("pause");//pausa a tela
	}
	
	fclose(file);//fecha o arquivo
	
	
}

int main ()
{	
	setlocale (LC_ALL, "Portuguese");//definindo linguagem
	
	int opcao=0; //variável da escolha do usuário
	int laco=1; //variável do laço

	
		for(laco=1;laco=1;) //Começo do laço
		{	
		
			system("cls"); //limpar a tela na volta do laço
		
			setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
			printf("\t Bem-vindo ao cartório da EBAC\n\n"); //Começo do painel de escolha
			printf("Escolha a opção desejada:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("Opção: ");
	
			scanf("%d", &opcao); //armazenamento da escolha do usuário
	
			system("cls"); //limpar a tela 
	
			switch(opcao) //inicio da seleção
			{
				case 1:
				registrar();//chamada da função
				break;
	
				case 2:
				consultar();//chamada da função
				break;
		
				case 3:
				deletar();//chamada da função
				break;
			
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
		
			} // final da seleção
		
		} // final do laço
   
}//final da main
