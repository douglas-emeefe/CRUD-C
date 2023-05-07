#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <locale.h>

// Definindo a estrutura de dados
struct pessoa{
   int id;
   char nome[50];
   char email[50];
};

//Fun��o para inserir uma pessoa no Banco de Dados
void inserirPessoa(){
	char nome[50];
	char email[50];
	char query[100] = " ";
	
	MYSQL *conexao;
	conexao = mysql_init(NULL);	//Retorna o endere�o de uma estrutura mysql
	
	//Estrutura que faz a conex�o com um servido MySQL e inseri uma nova pessoa no Banco de Dados
	//Parametros(variavel de conexao, endere�o do BD, nome usu�rio, senha, nome do BD, porta, NULL e 0 padr�o
	if(mysql_real_connect(conexao, "localhost", "root", "123", "crud_c", 3306, NULL, 0)){	
		printf("\n Conectado ao banco de dados! \n\n");		//Mostra na tela messagem de conex�o com o banco
		printf(" Digite seu nome de usuario: ");
		scanf("%s",&nome);		//ler o dado digitado pelo usu�rio e atribui a variavel nome
		printf(" Digite seu email: ");
		scanf("%s",&email);		//ler o dado digitado pelo usu�rio e atribui a variavel email
		
		//Comando MySQL que insere os dados no Banco de Dados
		sprintf(query, "INSERT INTO usuarios(nome, email) values ('%s', '%s');", nome, email);	
		
		//Estrutura de execu��o da query
		if(!mysql_query(conexao, query)){
			printf("\n Usu�rio inserido\n");
		}else{
			printf("\n Usu�rio n�o inserido!\n");
		}
	}else{	
		printf("\n Erro ao conecta-se com o banco de dados \n\n");		//Mostra na tela messagem de erro ao conectar com o BD
	}
	mysql_close(conexao);
	system("pause");
	system("cls");
	menu();
}

//Fun��o para mostra todos os dados da tabela
struct pessoa* mostrarDados(){
    char query[100] = "";
    struct pessoa *p;

    MYSQL *conexao;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    
    conexao = mysql_init(NULL);
    
    p = (struct pessoa*) malloc(sizeof(struct pessoa));
	
	//Estrutura que faz a conex�o com o Banco de dados e mostra todos os dados da tabela usuarios
    if(mysql_real_connect(conexao, "localhost", "root", "123", "crud_c", 3306, NULL, 0)){
        printf("\n  *Conectado ao banco de dados! \n\n");
                
    	//Comando MySQL que mostrar todos os dados da tabela usu�rios
    	sprintf(query, "SELECT * FROM usuarios");
    
    	//Estrutura de execu��o da query
    	if(!mysql_query(conexao, query)){
        	resposta = mysql_store_result(conexao);		//Recebe o resultado da query
        
        	printf("  ----------------------------------------------\n");  
        	printf("  |ID|NOME           |EMAIL                    |\n");
        	printf("  ----------------------------------------------\n");
			
			//Estrutura que ler todas as linhas e impreme os dados da tabela usu�rios
        	while ((linhas = mysql_fetch_row(resposta))) {
            	p->id = atoi (linhas[0]);
            	strcpy(p->nome, linhas[1]);
            	strcpy(p->email, linhas[2]);
            	printf("  |%-2d|", p->id);
            	printf("%-15s|", p->nome);
            	printf("%-25s|\n", p->email);
        	}
        	printf("  ----------------------------------------------\n");
    	}else{    
        	printf("Erro ao buscar dados da tabela");	//Messagem de erro caso n�o encontre os dados
    	}
	}else{	
		printf("\n Erro ao conecta-se com o banco de dados \n\n");		//Mostra na tela messagem de erro ao conectar com o BD
	}
    mysql_close(conexao);
    system("pause");
	system("cls");
	menu();
}

struct pessoa* buscarNome(){
	char nome[50];
	char query[100];
	int resultados;
	struct pessoa* p;
	
	MYSQL *conexao;
	MYSQL_RES *resposta;
	MYSQL_ROW linhas;
	
	conexao = mysql_init(NULL);
	
	p = (struct pessoa*) malloc(sizeof(struct pessoa));
	
	//Estrutura que faz a conex�o com o Banco de dados e mostra o dados da tabela usuarios
	if(mysql_real_connect(conexao, "localhost", "root", "123", "crud_c", 3306, NULL, 0)){
    	printf("  Digite o nome do usu�rio: ");
    	scanf("%s", nome);
        
		//Comando MySQL que mostra os dados da tabela usu�rios com a sele��o do nome
    	sprintf(query, "SELECT * FROM usuarios WHERE nome LIKE '%s'", nome);
    
    	//Estrutura de execu��o da query
    	if(!mysql_query(conexao, query)){
    		resposta = mysql_store_result(conexao);		//Recebe o resultado da query
        	resultados = mysql_num_rows(resposta);		//Recebe a quantidade de usu�rio encontrados
	
			//Verifica se algum usu�rio foi encontrado
        	if(resultados < 1){
            	printf("\nO usuario: %s nao foi encontrado", nome);
        	}else{
            	printf("  ----------------------------------------------\n");  
        		printf("  |ID|NOME           |EMAIL                    |\n");
        		printf("  ----------------------------------------------\n");
			
			//Estrutura que ler todas as linhas e impreme os dados da tabela usu�rios
            while((linhas = mysql_fetch_row(resposta))){
            	p->id = atoi (linhas[0]);
            	strcpy(p->nome, linhas[1]);
            	strcpy(p->email, linhas[2]);
            	printf("  |%-2d|", p->id);
            	printf("%-15s|", p->nome);
            	printf("%-25s|\n", p->email);
        	}
        	printf("  ----------------------------------------------\n");
            printf("\n  %d RESULTADOS ENCONTRADOS", resultados);		//Mostra a quantidade de usu�rio que foram encontrados
        	}   
    	}else{    
        	printf("Erro ao buscar dados da tabela");	//Messagem de erro caso n�o encontre os dados
    	}
	}else{    
        printf("\n Erro ao conecta-se com o banco de dados \n\n");		//Mostra na tela messagem de erro ao conectar com o BD
    }
    mysql_close(conexao);
}

struct pessoa* buscarId(){
	int id;
	char query[100];
	int resultados;
	struct pessoa* p;
	
	MYSQL *conexao;
	MYSQL_RES *resposta;
	MYSQL_ROW linhas;
	
	conexao = mysql_init(NULL);
	
	p = (struct pessoa*) malloc(sizeof(struct pessoa));
	
	//Estrutura que faz a conex�o com o Banco de dados e mostra o dados da tabela usuarios
	if(mysql_real_connect(conexao, "localhost", "root", "123", "crud_c", 3306, NULL, 0)){
    	printf("  Digite o ID do usu�rio: ");
    	scanf("%d", &id);
        
		//Comando MySQL que mostra os dados da tabela usu�rios com a sele��o do ID
    	sprintf(query, "SELECT * FROM usuarios WHERE id = '%d'", id);
    
    	//Estrutura de execu��o da query
    	if(!mysql_query(conexao, query)){
    		resposta = mysql_store_result(conexao);		//Recebe o resultado da query
        	resultados = mysql_num_rows(resposta);		//Recebe a quantidade de usu�rio encontrados
			
			//Verifica se foi encontrado algum usu�rio
        	if(resultados < 1){
            	printf("\nO ID: %d n�o foi encontrado", id);
        	}else{
            	printf("  ----------------------------------------------\n");  
        		printf("  |ID|NOME           |EMAIL                    |\n");
        		printf("  ----------------------------------------------\n");
			
			//Estrutura que ler todas as linhas e impreme os dados da tabela usu�rios
            while((linhas = mysql_fetch_row(resposta))){
            	p->id = atoi (linhas[0]);
            	strcpy(p->nome, linhas[1]);
            	strcpy(p->email, linhas[2]);
            	printf("  |%-2d|", p->id);
            	printf("%-15s|", p->nome);
            	printf("%-25s|\n", p->email);
        	}
        	printf("  ----------------------------------------------\n");
        	}   
    	}else{    
        	printf("Erro ao buscar dados da tabela");	//Messagem de erro caso n�o encontre os dados
    	}
	}else{    
        printf("\n Erro ao conecta-se com o banco de dados \n\n");		//Mostra na tela messagem de erro ao conectar com o BD
    }
    mysql_close(conexao);
}

void menuBuscar(){
	
	int opcao;
	
	printf("  \n  1 - ID\n  2 - NOME\n  Escolha a op��o de busca:");    
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			system("cls");
			buscarId();
			break;
		case 2:
			system("cls");
			buscarNome();
			break;
		default:
			system("cls");
			menuBuscar();		
	}
	system("pause");
	system("cls");
	menu();
}

void atualizarCadastro(){
	int id;
	int opcao;
	char nome[50];
	char email[50];
	char query[100];
	struct pessoa* p;
	
	MYSQL *conexao;
	conexao = mysql_init(NULL);
	
	p = (struct pessoa*) malloc(sizeof(struct pessoa));
	
	//Estrutura que faz a conex�o com o Banco de dados e mostra o dados da tabela usuarios
	if(mysql_real_connect(conexao, "localhost", "root", "123", "crud_c", 3306, NULL, 0)){
		printf("  1 - Atualizar NOME\n  2 - Atualizar EMAIL\n  Digite a op��o: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 1:
				printf("  Digite o id do usuario a ser editado: ");
    			scanf("%d", &id);
    		
				printf("  Digite o novo nome do usu�rio: ");
    			scanf("%s", &nome);
    		
    			p->id = id;
    			strcpy(p->nome, nome);
    		
    			//Comando MySQL que atualiza o dado nome de um usu�rio
    			sprintf(query, "UPDATE usuarios SET nome = '%s' WHERE id = %d", p->nome, p->id);
				break;
			case 2:
				printf("  Digite o id do usuario a ser editado: ");
    			scanf("%d", &id);
    		
				printf("  Digite o novo email do usu�rio: ");
    			scanf("%s", &email);
    		
    			p->id = id;
    			strcpy(p->email, email);
    		
    			//Comando MySQL que atualiza o dado nome de um usu�rio
    			sprintf(query, "UPDATE usuarios SET email = '%s' WHERE id = %d", p->email, p->id);
				break;
			default:
				system("cls");
				atualizarCadastro();
				break;
		}
		//Estrutura de execu��o da query
		if(!mysql_query(conexao, query)){
    		printf("\n  Usu�rio alterado com sucesso!\n");
		}
	}else{    
        printf("\n  Erro ao conecta-se com o banco de dados \n\n");		//Mostra na tela messagem de erro ao conectar com o BD
    }
    mysql_close(conexao);
    system("pause");
	system("cls");
	menu();
}

void deletarCadastro(){
	int id;
	char query[100];
	
	MYSQL *conexao;
	conexao = mysql_init(NULL);
	
	if(mysql_real_connect(conexao, "localhost", "root", "123", "crud_c", 3306, NULL, 0)){	
		printf(" Digite o ID do usuario a ser deletado: ");
		scanf("%d",&id);		//ler o dado digitado pelo usu�rio e atribui a variavel id
				
		//Comando MySQL que deleta os dados no Banco de Dados
		sprintf(query, "DELETE FROM usuarios WHERE id = '%d'", id);	
		
		//Estrutura de execu��o da query
		if(!mysql_query(conexao, query)){
			printf("\n Usu�rio deletado com sucesso\n");
		}else{
			printf("\n Erro ao deletar usu�io!\n");
		}
	}else{	
		printf("\n Erro ao conecta-se com o banco de dados \n\n");		//Mostra na tela messagem de erro ao conectar com o BD
	}
	mysql_close(conexao);
	system("pause");
	system("cls");
	menu();
}

void menu(){
	int opcao;
	
	printf("  ################################################################\n");
	printf("  ----------------------------------------------------------------\n");
	printf("  |              CRUD EM C COM BANCO DE DADOS MYSQL              |\n");
	printf("  ----------------------------------------------------------------\n");
	printf("  ################################################################\n\n");
	
	printf("  1 - CADASTRAR USU�RIO\n");
	printf("  2 - ALTERAR USU�RIO\n");
	printf("  3 - DELETAR USU�RIO\n");
	printf("  4 - LISTAR USU�RIOS\n");
	printf("  5 - BUSCAR USU�RIO\n");
	printf("  0 - FECHAR PROGRAMA\n");
	printf("  Selecione uma op��o: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 0:
            system("exit");
            printf("\n  Finalizando...\n\n");
			break;
		case 1:
			system("cls");
			inserirPessoa();
			break;
		case 2:
			system("cls");
			atualizarCadastro();
			break;
		case 3:
			system("cls");
			deletarCadastro();
			break;	
		case 4:
			system("cls");
			mostrarDados();
			break;
		case 5:
			system("cls");
			menuBuscar();
			break;	
		default:
			system("cls");
			menu();	
			break;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	menu();	
	
    return 0;
}
