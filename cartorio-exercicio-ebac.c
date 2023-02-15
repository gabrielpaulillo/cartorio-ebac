#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de vari�veis (alocar espa�o na mem�ria)
#include <locale.h> //biblioteca de aloca��o de texto (reconhece a l�ngua e aceita acentos)
#include <stdbool.h> //biblioteca respons�vel por cuidar das vari�veis booleanas
#include <string.h> //biblioteca respons�vel por cuidar das strings

int main(){
	int opcao = 0;
	bool selecionou_opcao = false;
	
	
	while (selecionou_opcao == false){

		setlocale (LC_ALL, "Portuguese"); //defini��o da linguagem para aceitar acentos
		
		system("cls");
		
		printf("### Seja bem-vindo(a) ao cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Qual das op��es voc� deseja executar?\n\n");
		printf("\t1. Registrar nome\n");
		printf("\t2. Consultar nome\n");
		printf("\t3. Deletar nome\n");
		printf("\t4. Sair do sistema\n\n");
		printf("Op��o: ");// fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //vem incluir na "stdlib.h" utilizado para LIMPAR a output
		
		switch (opcao) {
			case 1:
			registrar_nomes();
			break;
			
			case 2:
			consultar_nomes();
			break;
			
			case 3:
			deletar_nomes();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.");
			return 0;
			break;
			
			default:
				printf("Voc� n�o selecionou nenhuma op��o dispon�vel. Digite 1, 2 ou 3.\n\n");
				system("pause");
			break;
		}
	}
}
	
int registrar_nomes(){ //fun��o respons�vel por cria��o dos registros
	
	//cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Voc� selecionou a op��o: 'Registrar nomes'\n");
	
	printf("Digite o CPF que ser� cadastrado: ");
	scanf("%s", cpf); //armazenando o cpf do usu�rio na vari�vel cpf
	// %s refere-se a strings
	
	strcpy(arquivo, cpf); //coletando e armazenando o cpf na vari�vel "cpf"
	
	FILE *file; //acessa a fun��o FILE e cria "file"
	file = fopen(arquivo, "w"); //abrir um arquivo e "w" refere-se a escrever
	fprintf(file, cpf); //salva no arquivo a vari�vel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o objetivo � atualizar, por isso o "a"
	fprintf(file, ","); //atualiza o arquivo colocando uma v�rgula entre os registros
	fclose(file);
	
	printf("Digite o nome que ser� cadastrado: ");
	scanf("%s", nome); //coletando e armazenando o nome na vari�vel "nome"
	
	file = fopen(arquivo, "a"); //abrir o arquivo com o objetivo de atualiz�-lo
	fprintf(file, nome); //acrescenta o nome que o usu�rio digitou
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome que ser� cadastrado: ");
	scanf("%s", sobrenome); //coletando e armazenando o sobrenome na vari�vel "sobrenome"
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo que ser� cadastrado: ");
	scanf("%s", cargo); //coletando e armazenando o cargo na vari�vel "cargo"
	
	file = fopen(arquivo, "a"); //abrindo o arquivo e o "a" de add/adicionar
	fprintf(file, cargo); //adicionando a vari�vel cargo ao arquivo
	fclose(file); //fechamento do arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
}
	
int consultar_nomes(){ //fun��o respons�vel por consultar um cpf j� cadastrado
	char cpf[40];
	char conteudo[200];
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("Voc� selecionou a op��o: 'Consultar nomes'\n");
	
	printf("Digite o CPF que voc� consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" � de read, somente para consultar

	if(file == NULL){ //se o "cpf" dentro de "file" for nulo, imprimir� a mensagem.
		printf("CPF n�o localizado. Registre seu CPF ou confira se voc� n�o errou na digita��o.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");	
}

int deletar_nomes(){ //fun��o criada para deletar algum cpf j� cadastrado
	char cpf[40];
	
	printf("Voc� selecionou a op��o: 'Deletar nomes'\n");
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Voc� digitou um CPF inv�lido ou ainda n�o registrado.\n");
		system("pause");
	} else{
		remove(cpf);
		printf("CPF do usu�rio deletado com sucesso!!\n\n");
		system("pause");
	}
}
