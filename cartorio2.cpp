#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das vari�veis 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a strings (escanear strings)
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");//abre o arquivo e "w" significa write(escrever um novo conte�do)
	fprintf(file,cpf);// salva o valor da vari�vel (cpf)
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo,"a"); //abre o arquivo e diz que � para atualizar informa��es
	fprintf(file,","); //adciona a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//pede as informa��es do usu�rio
	scanf("%s", nome);//salva as informa��es do usu�rio
	
	file = fopen(arquivo,"a");//abrir arquivo, "a" quer dizer ir� atualizar as inform. do arquivo
	fprintf(file,nome);//adicionar na vari�vel "nome" 
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");//adiciona a virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobre nome a ser cadastrado: ");//pede ao usu�rio suas informa��es 
	scanf("%s", sobrenome);//salva as informa��es do usu�rio
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,sobrenome);//adiciona o sobrenome 
	fclose(file);//fecha o arquivo 
	
	file= fopen (arquivo,"a");//abre o arquivo
	fprintf(file,",");//adiciona o sobrenome 
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//pede as informa��es do usu�rio
	scanf("%s", cargo);//salva as informa��es do usu�rio 
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file, cargo);//adiciona o cargo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,".");//adiciona o ponto
	fclose(file);//fecha o arquivo
		
	
}

int consultar()//fun��o respons�vel por consultar os usu�rios do sistema 
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
	//inicio da cria��o das strings
	char cpf[40];
	char conteudo[200];
	//final da cria��o das strings
	
	printf("Digite o CPF a ser consultado: ");//coleta informa��es do usu�rio
	scanf("%s", cpf);//escaneia as informa��es
	
	FILE *file;//criando arquivo
	file = fopen(cpf,"r");//lendo o arquivo
	
	if (file == NULL);//ordem para se o arquivo for igual a nulo, avisar que n�o foi possivel abrir
	{	
		system("cls");//limpa a tela 
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");//informa que ao usu�rio
		
	}
	
	while(fgets(conteudo, 200,file) != NULL)//busca as informa��es para passao ao usu�rio
	{	
		system("cls");
		printf("Aqui est�o as informa��es do usu�rio: ");//manda as informa��es para o usu�rio
		printf("%s",conteudo);//manda as informa��es para o usu�rio
		printf("\n\n");
		fclose(file);//fecha o arquivo 
	}
	
	system("pause");//pausa o sistema
	
	
	
}

int deletar()//fun��o0 respons�vel por deletar os usu�rios do sistema
{
	char cpf[40];//cria a string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletar escolha do usu�rio
	scanf("%s",cpf);//escanear e salvar na string a escolha do usus�rio
	
	remove(cpf);//remover o conte�do
	
	FILE *file;
	file = fopen(cpf, "r");//abrir o arquivo, "r" significa ler
	
	
	if(file == NULL)//o que fazer caso a escolha do usu�rio for nula
	{
		system("cls");//limpa a tela
		printf("O usu�rio n�o se encontra no sistema!.\n");//informa ao usu�rio
		system("pause");//pausa a tela
	}
	
	fclose(file);//fecha o arquivo
	
	
}

int main ()
{	
	setlocale (LC_ALL, "Portuguese");//definindo linguagem
	
	int opcao=0; //vari�vel da escolha do usu�rio
	int laco=1; //vari�vel do la�o

	
		for(laco=1;laco=1;) //Come�o do la�o
		{	
		
			system("cls"); //limpar a tela na volta do la�o
		
			setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
			printf("\t Bem-vindo ao cart�rio da EBAC\n\n"); //Come�o do painel de escolha
			printf("Escolha a op��o desejada:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("Op��o: ");
	
			scanf("%d", &opcao); //armazenamento da escolha do usu�rio
	
			system("cls"); //limpar a tela 
	
			switch(opcao) //inicio da sele��o
			{
				case 1:
				registrar();//chamada da fun��o
				break;
	
				case 2:
				consultar();//chamada da fun��o
				break;
		
				case 3:
				deletar();//chamada da fun��o
				break;
			
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		
			} // final da sele��o
		
		} // final do la�o
   
}//final da main
