#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#define MAX 100

//Struct usada para armazenar informa��es sobre a identifica��o do jogo
typedef struct{
	int numjogo;
	char abtp[MAX];//String de caracteres para o nome do �rbitro principal
	char abta[MAX];//String de caracteres para o nome do �rbitro auxiliar
	char data[MAX];
	char competicao[MAX];
	char grupo[MAX];
	char fase[MAX];
	char local[MAX];
	char cidade[MAX];
	char uf[MAX];
	char horinip1[MAX];//String de caracteres para a hora de in�cio do primeiro per�odo
	char horinip2[MAX];//String de caracteres para a hora de in�cio do segundo per�odo
	char horfimp1[MAX];//String de caracteres para a hora do fim do primeiro per�odo
	char horfimp2[MAX];//String de caracteres para a hora do fim do segundo per�odo 
}Identi;

//Struct usada para armazenar informa��es sobre os gols da partida
typedef struct{
	int numg;//String de caracteres para o n�mero do gol da equipe
	int numj;//String de caracteres para o n�mero do jogador que fez o gol
	char min[MAX];//String de caracteres para a minutagem em que aconteceu o gol
}Gols;

//Struct usada para armazenar informa��es de cada jogador
typedef struct{
	int numero;
	char ca[MAX];//String de caracteres para minutagem de cart�es amarelos
	char cv[MAX];//String de caracteres para minutagem de cart�es vermelhos
	char nome[MAX];
	char registro[MAX];
}Jogadores;

//Struct usada para armazenar informa��es de cada equipe(as structs "Gols" e "Jogadores" est�o contidas dentro dessa struct)
typedef struct{
	Jogadores jogador[MAX];//Declara��o de uma vari�vel do tipo "Jogadores" contida dentro da struct da Equipe
	Gols goleqp[MAX];//Declara��o de uma vari�vel do tipo "Gols" contida dentro da struct da Equipe
	char nome[MAX];
	char tecnico[MAX];
	char capitao[MAX];
	char tempp1[MAX];//String de caracteres para a minutagem em que foi pedido o tempo t�cnico no primeiro per�odo
	char tempp2[MAX];//String de caracteres para a minutagem em que foi pedido o tempo t�cnico no segundo per�odo
	int golsp1;//Inteiro para a contagem de gols do primeiro per�odo
	int golsp2;//Inteiro para a contagem de gols do segundo per�odo
	int faltasp1;//Inteiro para a contagem de faltas do primeiro per�odo
	int faltasp2;//Inteiro para a contagem de faltas do segundo per�odo
}Equipe;


int main(){
	setlocale(LC_ALL, "Portuguese");
	Identi I;//Declar��o de uma vari�vel do tipo Identi
	Equipe eqp1,eqp2;//Declara��o de duas variav�is do tipo Equipe, uma para cada equipe
	int op1,op2=1,num1,num2,num3,num4,num5,n,n1,n2,qtd1,qtd2,cont,cont1,cont2;
	eqp1.faltasp1=0;
	eqp1.faltasp2=0;
	eqp2.faltasp1=0;
	eqp2.faltasp2=0;

	//Preenchimento de informa��es que deve acontecer aantes do in�nio da partida 
	//S�rie de leitura de variav�is usadas para armazenar as informa��es de identifica��o da partida
	//Os espa�os e os seguintes caracteres "[^\n]" foram utilizados no decorrer do c�digo para evitar erro de buffer e ler a string at� que seja pressionado o "Enter", respectivamente
	puts ("----------------------- PR�-PARTIDA -----------------------\n");
	puts ("------------------ IDENTIFICA��O DO JOGO ------------------\n");
	printf("Informe o n�mero da partida:\n");
	scanf("%d", &I.numjogo);
	printf("Informe qual a data da partida:\n");
	scanf(" %[^\n]s", &I.data);	
	printf("Informe � qual competi��o a partida pertence:\n");
	scanf(" %[^\n]s", &I.competicao);
	printf("Informe � qual o grupo a partida faz parte:\n");
	scanf(" %s[^\n]", &I.grupo);	
	printf("Informe � qual fase a partida corresponde:\n");
	scanf(" %[^\n]s", &I.fase);	
	printf("Informe qual o local em que a partida ser� realizada:\n");
	scanf(" %[^\n]s", &I.local);
	printf("Informe em qual cidade a partida ser� realizada:\n");
	scanf(" %[^\n]s", &I.cidade);
	printf("Informe em qual unidade federativa a partida ser� realizada:\n");
	scanf(" %[^\n]s", &I.uf);
	system("clear||cls");
	
	//Leitura de variav�is usadas para armazenar os nomes dos �rbitros da partida
	puts ("-------------------- PR�-PARTIDA --------------------\n");	
	puts ("---------------- EQUIPE DE ARBITRAGEM ---------------\n");
	printf("Informe o nome do �rbitro principal da partida:\n");
	scanf(" %[^\n]s", &I.abtp);		
	printf("Informe o nome do �rbitro auxiliar da partida:\n");
	scanf(" %[^\n]s", &I.abta);
	system("clear||cls");

	//S�rie de leitura de variav�is usadas para armazenar as informa��es sobre a equipe 1
	puts ("----------------------- PR�-PARTIDA -----------------------\n");
	puts ("------------------------ EQUIPE-1 -------------------------\n");	
	printf("Informe o nome do time que ser� considerado como equipe 1:\n");
	scanf(" %[^\n]s", &eqp1.nome);
	printf("Informe o nome do t�cnico da equipe 1:\n");
	scanf(" %[^\n]s", &eqp1.tecnico);
	printf("Informe o nome do capit�o da equipe 1:\n");
	scanf(" %[^\n]s", &eqp1.capitao);
	system("clear||cls");
	puts ("----------------------- PR�-PARTIDA ----------------------\n");
	puts ("------------------------ EQUIPE-1 ------------------------\n");
	puts ("-------------------- INSERIR-JOGADORES -------------------\n");
	for (cont1=1;cont1<17 && cont1!=0;cont1++){//For usado para permitir que sejam inseridas informa��es de at� 16 jogadores e que seja inserado caso o usu�rio digite 0
		printf("Digite 0(no campo destinado ao n�mero do jogador) caso tenha terminado de inserir os jogadores\n");
		printf("Informe o n�mero do jogador:\n");
		scanf(" %d", &n);
		if(n==0){//If usado para caso o usu�rio queira encerrar o preenchimento das informa��es(digitou 0)
			cont1=-1;//Vari�vel declarada como "-1" para que ao final, com a soma de uma unidade ao seu valor como programado no for, ela se torne 0 e assim pule para a pr�xima etapa
			system("clear||cls");
		}
		else{
			eqp1.jogador[n].numero=n;//A vari�vel que armazena o n�mero do jogador na Struct recebe o valor da vari�vel intermedi�ria usada para guardar o n�mero
			printf("Informe o nome do jogador(N�:%d):\n", n);
			scanf(" %[^\n]s", &eqp1.jogador[n].nome);
			printf("Informe o registro do jogador(N�:%d):\n", n);
			scanf(" %[^\n]s", &eqp1.jogador[n].registro);
			system("clear||cls");
		}
	}
	
	//S�rie de leitura de variav�is usadas para armazenar as informa��es sobre a equipe 1
	//Coment�rios feitos na parte correspondente a equipe 1 tamb�m se aplicam a equipe 2
	puts ("----------------------- PR�-PARTIDA -----------------------\n");
	puts ("------------------------ EQUIPE 2 -------------------------\n");
	printf("Informe o nome do time que ser� considerado como equipe 2:\n");
	scanf(" %[^\n]s", &eqp2.nome);
	printf("Informe o nome do t�cnico da equipe 2:\n");
	scanf(" %[^\n]s", &eqp2.tecnico);
	printf("Informe o nome do capit�o da equipe 2:\n");
	scanf(" %[^\n]s", &eqp2.capitao);
	system("clear||cls");
	puts ("---------------------- PR�-PARTIDA ------------------------\n");
	puts ("------------------------ EQUIPE 2 -------------------------\n");
	puts ("-------------------- INSERIR-JOGADORES --------------------\n");
	for(cont2=1;cont2<17 && cont2!=0;cont2++){
		printf("Digite 0 caso tenha terminado de inserir os jogadores\n");
		printf("Informe o n�mero do jogador:\n");
		scanf(" %d", &n);
		if(n==0){
			cont2=-1;
			system("clear||cls");
		}
		else{
		eqp2.jogador[n].numero=n;
		printf("Informe o nome do jogador(N�:%d):\n", n);
		scanf(" %[^\n]s", &eqp2.jogador[n].nome);
		printf("Informe o registro do jogador(N�:%d):\n", n);
		scanf(" %[^\n]s", &eqp2.jogador[n].registro);
		system("clear||cls");
		}
	}
	
	//Preenchimento de informa��es sobre os eventos que ocorrem no decorrer da partida
	do{//Do while usado para que a possibilidade de inserir eventos seja possiv�l at� que o usu�rio deseje ir para a pr�xima etapa
	puts ("------------------------------- DURANTE-PARTIDA -------------------------------\n");
	//Printf usado para orientar o usu�rio sobre o n�mero correspondente a cada op��o de preenchimento
	printf("Digite 0 caso tenha terminado de inserir as informa��es no decorrer da partida\nDigite 1 para inserir um gol na s�mula\nDigite 2 para inserir um cart�o amarelo na s�mula\nDigite 3 para inserir um cart�o vermelho na s�mula\nDigite 4 para inserir uma falta\nDigite 5 para inserir um pedido de tempo t�cnico\nInforme a op��o escolhida:\n");
	scanf("%d", &op1);
	switch(op1)//Switch case usado para dividir as possibilidades de preenchimento,
	{	
		case 0://Caso usado para passar para a pr�xima etapa caso o usu�rio deseje  
			op2=1;//Vari�vel declarada como "1" para que o la�o seja encerrado
			system("clear||cls");
		break;
		case 1://Caso usado para armazenar informa��es sobre os gols da partida
			printf("Informe o n�mero da equipe(de acordo com o preeenchimento anterior) que fez o gol:\n");
			scanf("%d", &num1);
			if(num1==1){//If usado para caso o gol seja da equipe 1
				printf("N�mero do gol da Equipe(Primeiro Gol:Digite 1,Segundo gol:Digite 2) :\n");
				scanf(" %d", &qtd1);
				eqp1.goleqp[qtd1].numg = qtd1;//A vari�vel que armazena o n�mero do gol na Struct recebe o valor da vari�vel intermedi�ria usada para guardar o n�mero
				printf("Informe o n�mero do jogador que fez o gol:\n");
				scanf(" %d", &eqp1.goleqp[qtd1].numj);
				printf("Informe a minutagem em que aconteceu o gol:\n");
				scanf(" %[^\n]s", &eqp1.goleqp[qtd1].min);
			}
			if(num1==2){//If usado para caso o gol seja da equipe 2
				printf("N�mero do gol da Equipe(Primeiro Gol:Digite 1,Segundo gol:Digite 2) :\n");
				scanf(" %d", &qtd2);
				eqp2.goleqp[qtd2].numg = qtd2;//A vari�vel que armazena o n�mero do gol na Struct recebe o valor da vari�vel intermedi�ria usada para guardar o n�mero
				printf("Informe o n�mero do jogador que fez o gol:\n");
				scanf(" %d", &eqp2.goleqp[qtd2].numj);
				printf("Informe a minutagem em que aconteceu o gol:\n");
				scanf(" %[^\n]s", &eqp2.goleqp[qtd2].min);
			}
			op2=0;//Vari�vel declarada como "0" para que ao final, o la�o se repita(coment�rio se aplica aos demais comandos iguais a este nos ooutros cases)
			op1=10;//Vari�vel declarada como "10" para que ao final, a vari�vel esteja com uma op��o que n�o est� contida nos cases, sendo assim, evitando um la�o infinito e permitindo que seja solicitado novamente ao usu�rio a escolha da op��o(coment�rio se aplica aos demais comandos iguais a este nos ooutros cases)
			system("clear||cls");
		break;
		case 2://Caso usado para armazenar informa��es sobre os cart�es amarelos da partida
			printf("Informe o n�mero da equipe(de acordo com o preeenchimento anterior) que o cart�o amarelo foi aplicado:\n");
			scanf(" %d", &num2);
			if(num2==1){//If usado para caso o cart�o amarelo seja da equipe 1
				printf("Informe qual o n�mero do jogador em que o cart�o amarelo foi aplicado:\n");
				scanf(" %d", &n1);
				printf("Informe a minutagem em que o cart�o amarelo foi aplicado:\n");
				scanf(" %[^\n]s", &eqp1.jogador[n1].ca);
			}
			else{
				if(num2==2){//If usado para caso o cart�o amarelo seja da equipe 2
					printf("Informe qual o n�mero do jogador em que o cart�o amarelo foi aplicado:\n");
					scanf("%d", &n1);
					printf("Informe a minutagem em que o cart�o amarelo foi aplicado:\n");
					scanf(" %[^\n]s", &eqp2.jogador[n1].ca);
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		case 3://Caso usado para armazenar informa��es sobre os cart�es vermelhos da partida
			printf("Informe o n�mero da equipe(de acordo com o preeenchimento anterior) que o cart�o vermelho foi aplicado:\n");
			scanf(" %d", &num3);
			if(num3==1){//If usado para caso o cart�o vermelho seja da equipe 1
				printf("Informe qual o n�mero do jogador em que o cart�o vermelho foi aplicado:\n");
				scanf(" %d", &n1);
				printf("Informe a minutagem em que o cart�o vermelho foi aplicado:\n");
				scanf(" %[^\n]s", &eqp1.jogador[n1].cv);
			}
			else{
				if(num3==2){//If usado para caso o cart�o vermelho seja da equipe 2
					printf("Informe qual o n�mero do jogador em que o cart�o vermelho foi aplicado:\n");
					scanf(" %d", &n1);
					printf("Informe a minutagem em que o cart�o vermelho foi aplicado:\n");
					scanf(" %[^\n]s", &eqp2.jogador[n1].cv);
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		case 4://Caso usado para determinar o valor das variav�is de contagem de faltas da partida
			//Declara��es feitas para que o n�mero inicial de faltas seja 0
			printf("Informe o n�mero da equipe(de acordo com o preeenchimento anterior) que realizou a falta:\n");
			scanf("%d", &num4);
			printf("Informe em qual per�odo a falta ocorreu:\n");
			scanf("%d", &n1);
			if(num4==1){//If usado para ser executado quando a falta tenha sido cometida pela equipe 1
				if(n1==1){
					eqp1.faltasp1++;//If usado para ser executado quando a falta ocorrer no primeiro per�odo
				}else{
					if(n1==2){
						eqp1.faltasp2++;//If usado para ser executado quando a falta ocorrer no segundo per�odo
					}
				}
			}
			if(num4==2){//If usado para ser executado quando a falta tenha sido cometida pela equipe 2
				if(n1==1){
					eqp2.faltasp1++;//If usado para ser executado quando a falta ocorrer no primeiro per�odo
				}else{
					if(n1==2){
						eqp2.faltasp2++;//If usado para ser executado quando a falta ocorrer no segundo per�odo
					}
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		case 5://Caso usado para armazenar informa��es sobre os pedidos de tempo t�cnico da partida
			printf("Informe o n�mero da equipe(de acordo com o preeenchimento anterior) que realizou o pedido de teempo t�cnico:\n");
			scanf(" %d", &num5);
			printf("Informe em qual per�odo o pedido de tempo t�cnico ocorreu:\n");
			scanf(" %d", &n1);
			if(num5==1){//If usado para ser executado quando o tempo t�cnico tenha sido solicitado pela equipe 1
				if(n1==1){//If usado para ser executado caso o pedido de tempo tenha ocorrido no primeiro per�odo
					printf("Informe a minutagem em que o pedido de tempo t�nico foi realizado:\n");
					scanf(" %[^\n]s", &eqp1.tempp1);
				}else{
					if(n1==2){//If usado para ser executado caso o pedido de tempo tenha ocorrido no segundo per�odo
						printf("Informe a minutagem em que o pedido de tempo t�nico foi realizado:\n");
						scanf(" %[^\n]s", &eqp1.tempp2);
					}
				}
			}else{
				if(num5==2){//If usado para ser executado quando o tempo t�cnico tenha sido solicitado pela equipe 2
					if(n1==1){//If usado para ser executado caso o pedido de tempo tenha ocorrido no primeiro per�odo
						printf("Informe a minutagem em que o pedido de tempo t�nico foi realizado:\n");
						scanf(" %[^\n]s", &eqp2.tempp1);
					}else{
						if(n1==2){//If usado para ser executado caso o pedido de tempo tenha ocorrido no segundo per�odo
							printf("Informe a minutagem em que o pedido de tempo t�nico foi realizado:\n");
							scanf(" %[^\n]s", &eqp2.tempp2);
						}
					}
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		default://Default para caso o usu�rio digitar uma op��o que n�o esteja nas orienta��es iniciais, voltando o la�o e informando que a op��o escolhida n�o � v�lida
			printf("Nenhuma op��o v�lida foi escolhida\n");
			op2=0;
	}
	}while(op2==0);
	
	
	//Preenchimento de informa��es sobre as informa��es gerais da partida
	//Leitura de variav�is usadas para armazenar o n�mero de gols de cada per�odo, que ser�o usadas para fazer a contagem do placar da partida
	puts ("------------------------ P�S-PARTIDA -------------------------\n");
	puts ("------------------------- CONTAGEM ---------------------------\n");
	printf("Informe a quantidade de gols da equipe 1 no primeiro per�odo:\n");
	scanf(" %d", &eqp1.golsp1);
	printf("Informe a quantidade de gols da equipe 1 no segundo per�odo:\n");
	scanf(" %d", &eqp1.golsp2);
	printf("Informe a quantidade de gols da equipe 2 no primeiro per�odo:\n");
	scanf(" %d", &eqp2.golsp1);
	printf("Informe a quantidade de gols da equipe 2 no segundo per�odo:\n");
	scanf(" %d", &eqp2.golsp2);
	system("clear||cls");
	
	//Leitura de variav�is usadas para armazenar os hor�rios do in�cio e fim de cada per�odo
	puts ("------------------ P�S-PARTIDA -------------------\n");
	puts ("-------------------- HOR�RIO ---------------------\n");
	printf("Informe o hor�rio de in�cio do primeiro per�odo:\n");
	scanf(" %[^\n]s", &I.horinip1);
	printf("Informe o hor�rio do t�rmino do primeiro per�odo:\n");
	scanf(" %[^\n]s", &I.horfimp1);
	printf("Informe o hor�rio de in�cio do segundo per�odo:\n");
	scanf(" %[^\n]s", &I.horinip2);
	printf("Informe o hor�rio do t�rmino do segundo per�odo:\n");
	scanf(" %[^\n]s", &I.horfimp2);
	system("clear||cls");
	
	//Parte do c�digo destinada a nomea��o e salvamento de um arquivo de texto gerado a partir do resultado
	puts ("----------------------------- P�S-PARTIDA -------------------------------\n");
	puts ("------------------------- SALVAR-ARQUIVO-S�MULA -------------------------");
	char nomearq[MAX];//String de caracteres declarada para armazenar nome do arquivo
	printf("Digite o nome do arquivo que ser� salvo(obs: o arquivo ser� salvo em .txt):\n");
    scanf(" %[^\n]s", &nomearq);//Scanf usado para realizar a leitura da string at� que seja pressionado o "ENTER"
    FILE *arq;//Ponteiro especial para arquivos, usado para manipular o arquivo 
    arq = fopen(nomearq,"w");//Comando que abre o arquivo com o nome inserido anterior, o segundo argumento do comando corresponde ao tipo do arquivo que ser� criado(Neste exemplo, o arquivo � do tipo .txt)
    if (arq==NULL){//If usado para emitir uma mensagem caso tenha ocorrido algum erro no processo de abertura do arquivo
         printf("Erro ao abrir o arquivo\n");
	} 
	else {//Else usado para caso o arquivo tenha sido aberto normalmente
		//S�rie de fprints usados para impress�o do resultado da s�mula eletr�nica no arquivo criado anteriormente
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\tEQUIPE 1: %s | %d | X | %d | EQUIPE 2: %s\t\t\t\t\t\t\n", eqp1.nome,eqp1.golsp1+eqp1.golsp2,eqp2.golsp1+eqp2.golsp2,eqp2.nome);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\tEQUIPE 1 | T�cnico: %s     | Capit�o: %s\n", eqp1.tecnico, eqp1.capitao);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," Registro |\t\t\tJogadores\t\t|\tN�\t|\tCA\t|\tCV\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		for(cont=1;cont<=16;cont++){
			fprintf(arq,"%s | \t\t%s\t\t | %d | %s | %s |\n", eqp1.jogador[cont].registro, eqp1.jogador[cont].nome, eqp1.jogador[cont].numero, eqp1.jogador[cont].ca, eqp1.jogador[cont].cv);
			fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		}
		fprintf(arq," Pedidos de Tempo | 1� Per�odo: %s | 2� Per�odo: %s | Faltas | 1� Per�odo: %d | 2� Per�odo: %d \n", eqp1.tempp1, eqp1.tempp2, eqp1.faltasp1, eqp1.faltasp2);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		for(cont=1;cont<=20;cont++){
			if(cont<10){
				if(eqp1.goleqp[cont].numj<10){
					fprintf(arq,"| 0%d | 0%d |", eqp1.goleqp[cont].numg, eqp1.goleqp[cont].numj);
				}
				else{
					fprintf(arq,"| 0%d | %d |", eqp1.goleqp[cont].numg, eqp1.goleqp[cont].numj);
				}
			}
			else{
				if(eqp1.goleqp[cont].numj<10){
					fprintf(arq,"| %d | 0%d |", eqp1.goleqp[cont].numg, eqp1.goleqp[cont].numj);
				}
				else{
					fprintf(arq,"| %d | %d |", eqp1.goleqp[cont].numg, eqp1.goleqp[cont].numj);
				}
			}
		}
		fprintf(arq,"\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		for(cont1=1;cont1<=20;cont1++){
			fprintf(arq,"|  %s \t |", eqp1.goleqp[cont1].min);
		}
		fprintf(arq,"\n");
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\tEQUIPE 2 | T�cnico: %s     | Capit�o: %s\n", eqp2.tecnico, eqp2.capitao);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," Registro |\t\t\tJogadores\t\t|\tN�\t|\tCA\t|\tCV\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		for(cont=1;cont<=16;cont++){
			fprintf(arq,"%s | \t\t%s\t\t | %d | %s | %s |\n", eqp2.jogador[cont].registro, eqp2.jogador[cont].nome, eqp2.jogador[cont].numero, eqp2.jogador[cont].ca, eqp2.jogador[cont].cv);
			fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		}
		fprintf(arq," Pedidos de Tempo | 1� Per�odo: %s | 2� Per�odo: %s | Faltas | 1� Per�odo: %d | 2� Per�odo: %d \n", eqp2.tempp1, eqp2.tempp2, eqp2.faltasp1, eqp2.faltasp2);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		for(cont=1;cont<=20;cont++){
			if(cont<10){
				if(eqp1.goleqp[cont].numj<10){
					fprintf(arq,"| 0%d | 0%d |", eqp2.goleqp[cont].numg, eqp2.goleqp[cont].numj);
				}
				else{
					fprintf(arq,"| 0%d | %d |", eqp2.goleqp[cont].numg, eqp2.goleqp[cont].numj);
				}
			}
			else{
				if(eqp1.goleqp[cont].numj<10){
					fprintf(arq,"| %d | 0%d |", eqp2.goleqp[cont].numg, eqp2.goleqp[cont].numj);
				}
				else{
					fprintf(arq,"| %d | %d |", eqp2.goleqp[cont].numg, eqp2.goleqp[cont].numj);
				}
			}
		}
		fprintf(arq,"\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		for(cont1=1;cont1<=20;cont1++){
			fprintf(arq,"|  %s \t |", eqp2.goleqp[cont1].min);
		}
		fprintf(arq,"\n");
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\t\t\tIDENTIFICA��O DO JOGO:\t\t\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"Competi��o: \t%s\n", I.competicao);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"N� Jogo: %d \t| Grupo: %s \t| Fase: %s \t| Data: %s \t|\n", I.numjogo, I.grupo, I.fase, I.data);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"Local: %s \t| Cidade: %s \t| UF: %s\n", I.local, I.cidade, I.uf);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\tHOR�RIO | IN�CIO | T�RMINO \n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 1� Per�odo | %s | %s |\n", I.horinip1, I.horfimp1);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 2� Per�odo | %s | %s |\n", I.horinip2, I.horfimp2);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\t\t\tEQUIPE DE ARBITRAGEM\t\t\t\t\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"�rbitro Principal: %s\n", I.abtp);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"�rbitro Auxiliar: %s\n", I.abta);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\tCONTAGEM\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 1� Per�odo | %d | X | %d |\n", eqp1.golsp1, eqp2.golsp2);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 2� Per�odo | %d | X | %d |\n", eqp1.golsp2, eqp2.golsp2);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"   FINAL    | %d | X | %d |\n", eqp1.golsp1+eqp1.golsp2,eqp2.golsp1+eqp2.golsp2);
		fprintf(arq,"________________________________________________________________________________________________________\n");
	}
	
	return 0;
}

