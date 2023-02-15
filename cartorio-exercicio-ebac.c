#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de variáveis (alocar espaço na memória)
#include <locale.h> //biblioteca de alocação de texto (reconhece a língua e aceita acentos)
#include <stdbool.h> //biblioteca responsável por cuidar das variáveis booleanas
#include <string.h> //biblioteca responsável por cuidar das strings

int main(){
	int opcao = 0;
	bool selecionou_opcao = false;
	
	
	while (selecionou_opcao == false){

		setlocale (LC_ALL, "Portuguese"); //definição da linguagem para aceitar acentos
		
		system("cls");
		
		printf("### Seja bem-vindo(a) ao cartório da EBAC ###\n\n"); //início do menu
		printf("Qual das opções você deseja executar?\n\n");
		printf("\t1. Registrar nome\n");
		printf("\t2. Consultar nome\n");
		printf("\t3. Deletar nome\n");
		printf("\t4. Sair do sistema\n\n");
		printf("Opção: ");// fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
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
				printf("Você não selecionou nenhuma opção disponível. Digite 1, 2 ou 3.\n\n");
				system("pause");
			break;
		}
	}
}
	
int registrar_nomes(){ //função responsável por criação dos registros
	
	//criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Você selecionou a opção: 'Registrar nomes'\n");
	
	printf("Digite o CPF que será cadastrado: ");
	scanf("%s", cpf); //armazenando o cpf do usuário na variável cpf
	// %s refere-se a strings
	
	strcpy(arquivo, cpf); //coletando e armazenando o cpf na variável "cpf"
	
	FILE *file; //acessa a função FILE e cria "file"
	file = fopen(arquivo, "w"); //abrir um arquivo e "w" refere-se a escrever
	fprintf(file, cpf); //salva no arquivo a variável cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o objetivo é atualizar, por isso o "a"
	fprintf(file, ","); //atualiza o arquivo colocando uma vírgula entre os registros
	fclose(file);
	
	printf("Digite o nome que será cadastrado: ");
	scanf("%s", nome); //coletando e armazenando o nome na variável "nome"
	
	file = fopen(arquivo, "a"); //abrir o arquivo com o objetivo de atualizá-lo
	fprintf(file, nome); //acrescenta o nome que o usuário digitou
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome que será cadastrado: ");
	scanf("%s", sobrenome); //coletando e armazenando o sobrenome na variável "sobrenome"
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo que será cadastrado: ");
	scanf("%s", cargo); //coletando e armazenando o cargo na variável "cargo"
	
	file = fopen(arquivo, "a"); //abrindo o arquivo e o "a" de add/adicionar
	fprintf(file, cargo); //adicionando a variável cargo ao arquivo
	fclose(file); //fechamento do arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
}
	
int consultar_nomes(){ //função responsável por consultar um cpf já cadastrado
	char cpf[40];
	char conteudo[200];
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("Você selecionou a opção: 'Consultar nomes'\n");
	
	printf("Digite o CPF que você consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" é de read, somente para consultar

	if(file == NULL){ //se o "cpf" dentro de "file" for nulo, imprimirá a mensagem.
		printf("CPF não localizado. Registre seu CPF ou confira se você não errou na digitação.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");	
}

int deletar_nomes(){ //função criada para deletar algum cpf já cadastrado
	char cpf[40];
	
	printf("Você selecionou a opção: 'Deletar nomes'\n");
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Você digitou um CPF inválido ou ainda não registrado.\n");
		system("pause");
	} else{
		remove(cpf);
		printf("CPF do usuário deletado com sucesso!!\n\n");
		system("pause");
	}
}
