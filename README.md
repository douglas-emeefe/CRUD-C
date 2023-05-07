# DESENVOLVIMENTO DE UM CRUD EM C
O projeto é proposta de trabalho da materia de PROGRAMAÇÃO DE SOFTWARE BÁSICO EM C, que tem como objetivo criar um CRUD usando a linguagem de programação C, integrado com o Banco de Dados MySQL. O programa tem as funcionalidades de cadastrar, atualizar, deletar e consultar dados de um usuário no BD. 
  
### Configuração do ambiente de desenvolvimento  

1º Certifique que tem instalado na sua máquina os Programas:
  - Dev-C++
  - MySQL Workbench
  
2º Deve ser criado o banco de dados com as seguintes especificações:
  - nome do banco: "crud_c"
  - usuário: "root"
  - senha: "123"
  - Tabela com os campos: id, nome, email (sendo id primary_key e auto_increment)
  
3º No Dev-C++:
  - Criar o projeto (Console Aplication) / projeto C
  - Abrir as opções do projeto no menu PROJETO / Opções do Projeto ou 'Crtl + H'
  - Ir para aba Arquivos/Diretório
  - Na aba de baixo Diretório das Bibliotecas:
    * Adicionar: 'C:\Program Files\MySQL\MySQL Server 8.0\lib' sem as aspas simples
  - Na aba Diretório de Include:
	  * Adicionar: 'C:\Program Files\MySQL\MySQL Server 8.0\include' sem as aspas simples
	  *	Adicionar: 'C:\Program Files\MySQL\MySQL Server 8.0\include\mysql' sem as aspas simples
  - Na aba de cima Parâmetros:
		* Adicionar nas 'opções de linha adicionais' no campo 'Linker'
		* Adicionar a escrita: '-lmysql' sem as aspas simples
  - Salvar apertando Ok
  - Dentro da pasta 'C:\Program Files\MySQL\MySQL Server 8.0\lib":
		* Copiar o arquivo de nome: 'libmysql.dll'
		* Colar dentro da pasta do projeto criado no DEV-C
    
	 #### Ambiente Configurado!
   
   
   
   #### FALE COMIGO
   - Celular: (92) 99304-6020
   - Email: douglasoliveira.trabalho@gmail.com
   #### Invista em novos projetos com uma doação voluntária via PIX
   - CPF: 04784486275
   
   
   #### DESENVOLVIDO POR: Douglas Oliveira
