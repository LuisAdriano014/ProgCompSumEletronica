#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#define MAX 100

//Struct usada para armazenar informações sobre a identificação do jogo
typedef struct{
	int numjogo;
	char abtp[MAX];//String de caracteres para o nome do árbitro principal
	char abta[MAX];//String de caracteres para o nome do árbitro auxiliar
	char data[MAX];
	char competicao[MAX];
	char grupo[MAX];
	char fase[MAX];
	char local[MAX];
	char cidade[MAX];
	char uf[MAX];
	char horinip1[MAX];//String de caracteres para a hora de início do primeiro período
	char horinip2[MAX];//String de caracteres para a hora de início do segundo período
	char horfimp1[MAX];//String de caracteres para a hora do fim do primeiro período
	char horfimp2[MAX];//String de caracteres para a hora do fim do segundo período 
}Identi;

//Struct usada para armazenar informações sobre os gols da partida
typedef struct{
	int numg;//String de caracteres para o número do gol da equipe
	int numj;//String de caracteres para o número do jogador que fez o gol
	char min[MAX];//String de caracteres para a minutagem em que aconteceu o gol
}Gols;

//Struct usada para armazenar informações de cada jogador
typedef struct{
	int numero;
	char ca[MAX];//String de caracteres para minutagem de cartões amarelos
	char cv[MAX];//String de caracteres para minutagem de cartões vermelhos
	char nome[MAX];
	char registro[MAX];
}Jogadores;

//Struct usada para armazenar informações de cada equipe(as structs "Gols" e "Jogadores" estão contidas dentro dessa struct)
typedef struct{
	Jogadores jogador[MAX];//Declaração de uma variável do tipo "Jogadores" contida dentro da struct da Equipe
	Gols goleqp[MAX];//Declaração de uma variável do tipo "Gols" contida dentro da struct da Equipe
	char nome[MAX];
	char tecnico[MAX];
	char capitao[MAX];
	char tempp1[MAX];//String de caracteres para a minutagem em que foi pedido o tempo técnico no primeiro período
	char tempp2[MAX];//String de caracteres para a minutagem em que foi pedido o tempo técnico no segundo período
	int golsp1;//Inteiro para a contagem de gols do primeiro período
	int golsp2;//Inteiro para a contagem de gols do segundo período
	int faltasp1;//Inteiro para a contagem de faltas do primeiro período
	int faltasp2;//Inteiro para a contagem de faltas do segundo período
}Equipe;


int main(){
	setlocale(LC_ALL, "Portuguese");
	Identi I;//Declarção de uma variável do tipo Identi
	Equipe eqp1,eqp2;//Declaração de duas variavéis do tipo Equipe, uma para cada equipe
	int op1,op2=1,num1,num2,num3,num4,num5,n,n1,n2,qtd1,qtd2,cont,cont1,cont2;
	eqp1.faltasp1=0;
	eqp1.faltasp2=0;
	eqp2.faltasp1=0;
	eqp2.faltasp2=0;

	//Preenchimento de informações que deve acontecer aantes do inínio da partida 
	//Série de leitura de variavéis usadas para armazenar as informações de identificação da partida
	//Os espaços e os seguintes caracteres "[^\n]" foram utilizados no decorrer do código para evitar erro de buffer e ler a string até que seja pressionado o "Enter", respectivamente
	puts ("----------------------- PRÉ-PARTIDA -----------------------\n");
	puts ("------------------ IDENTIFICAÇÃO DO JOGO ------------------\n");
	printf("Informe o número da partida:\n");
	scanf("%d", &I.numjogo);
	printf("Informe qual a data da partida:\n");
	scanf(" %[^\n]s", &I.data);	
	printf("Informe à qual competição a partida pertence:\n");
	scanf(" %[^\n]s", &I.competicao);
	printf("Informe à qual o grupo a partida faz parte:\n");
	scanf(" %s[^\n]", &I.grupo);	
	printf("Informe à qual fase a partida corresponde:\n");
	scanf(" %[^\n]s", &I.fase);	
	printf("Informe qual o local em que a partida será realizada:\n");
	scanf(" %[^\n]s", &I.local);
	printf("Informe em qual cidade a partida será realizada:\n");
	scanf(" %[^\n]s", &I.cidade);
	printf("Informe em qual unidade federativa a partida será realizada:\n");
	scanf(" %[^\n]s", &I.uf);
	system("clear||cls");
	
	//Leitura de variavéis usadas para armazenar os nomes dos árbitros da partida
	puts ("-------------------- PRÉ-PARTIDA --------------------\n");	
	puts ("---------------- EQUIPE DE ARBITRAGEM ---------------\n");
	printf("Informe o nome do árbitro principal da partida:\n");
	scanf(" %[^\n]s", &I.abtp);		
	printf("Informe o nome do árbitro auxiliar da partida:\n");
	scanf(" %[^\n]s", &I.abta);
	system("clear||cls");

	//Série de leitura de variavéis usadas para armazenar as informações sobre a equipe 1
	puts ("----------------------- PRÉ-PARTIDA -----------------------\n");
	puts ("------------------------ EQUIPE-1 -------------------------\n");	
	printf("Informe o nome do time que será considerado como equipe 1:\n");
	scanf(" %[^\n]s", &eqp1.nome);
	printf("Informe o nome do técnico da equipe 1:\n");
	scanf(" %[^\n]s", &eqp1.tecnico);
	printf("Informe o nome do capitão da equipe 1:\n");
	scanf(" %[^\n]s", &eqp1.capitao);
	system("clear||cls");
	puts ("----------------------- PRÉ-PARTIDA ----------------------\n");
	puts ("------------------------ EQUIPE-1 ------------------------\n");
	puts ("-------------------- INSERIR-JOGADORES -------------------\n");
	for (cont1=1;cont1<17 && cont1!=0;cont1++){//For usado para permitir que sejam inseridas informações de até 16 jogadores e que seja inserado caso o usuário digite 0
		printf("Digite 0(no campo destinado ao número do jogador) caso tenha terminado de inserir os jogadores\n");
		printf("Informe o número do jogador:\n");
		scanf(" %d", &n);
		if(n==0){//If usado para caso o usuário queira encerrar o preenchimento das informações(digitou 0)
			cont1=-1;//Variável declarada como "-1" para que ao final, com a soma de uma unidade ao seu valor como programado no for, ela se torne 0 e assim pule para a próxima etapa
			system("clear||cls");
		}
		else{
			eqp1.jogador[n].numero=n;//A variável que armazena o número do jogador na Struct recebe o valor da variável intermediária usada para guardar o número
			printf("Informe o nome do jogador(Nº:%d):\n", n);
			scanf(" %[^\n]s", &eqp1.jogador[n].nome);
			printf("Informe o registro do jogador(Nº:%d):\n", n);
			scanf(" %[^\n]s", &eqp1.jogador[n].registro);
			system("clear||cls");
		}
	}
	
	//Série de leitura de variavéis usadas para armazenar as informações sobre a equipe 1
	//Comentários feitos na parte correspondente a equipe 1 também se aplicam a equipe 2
	puts ("----------------------- PRÉ-PARTIDA -----------------------\n");
	puts ("------------------------ EQUIPE 2 -------------------------\n");
	printf("Informe o nome do time que será considerado como equipe 2:\n");
	scanf(" %[^\n]s", &eqp2.nome);
	printf("Informe o nome do técnico da equipe 2:\n");
	scanf(" %[^\n]s", &eqp2.tecnico);
	printf("Informe o nome do capitão da equipe 2:\n");
	scanf(" %[^\n]s", &eqp2.capitao);
	system("clear||cls");
	puts ("---------------------- PRÉ-PARTIDA ------------------------\n");
	puts ("------------------------ EQUIPE 2 -------------------------\n");
	puts ("-------------------- INSERIR-JOGADORES --------------------\n");
	for(cont2=1;cont2<17 && cont2!=0;cont2++){
		printf("Digite 0 caso tenha terminado de inserir os jogadores\n");
		printf("Informe o número do jogador:\n");
		scanf(" %d", &n);
		if(n==0){
			cont2=-1;
			system("clear||cls");
		}
		else{
		eqp2.jogador[n].numero=n;
		printf("Informe o nome do jogador(Nº:%d):\n", n);
		scanf(" %[^\n]s", &eqp2.jogador[n].nome);
		printf("Informe o registro do jogador(Nº:%d):\n", n);
		scanf(" %[^\n]s", &eqp2.jogador[n].registro);
		system("clear||cls");
		}
	}
	
	//Preenchimento de informações sobre os eventos que ocorrem no decorrer da partida
	do{//Do while usado para que a possibilidade de inserir eventos seja possivél até que o usuário deseje ir para a próxima etapa
	puts ("------------------------------- DURANTE-PARTIDA -------------------------------\n");
	//Printf usado para orientar o usuário sobre o número correspondente a cada opção de preenchimento
	printf("Digite 0 caso tenha terminado de inserir as informações no decorrer da partida\nDigite 1 para inserir um gol na súmula\nDigite 2 para inserir um cartão amarelo na súmula\nDigite 3 para inserir um cartão vermelho na súmula\nDigite 4 para inserir uma falta\nDigite 5 para inserir um pedido de tempo técnico\nInforme a opção escolhida:\n");
	scanf("%d", &op1);
	switch(op1)//Switch case usado para dividir as possibilidades de preenchimento,
	{	
		case 0://Caso usado para passar para a próxima etapa caso o usuário deseje  
			op2=1;//Variável declarada como "1" para que o laço seja encerrado
			system("clear||cls");
		break;
		case 1://Caso usado para armazenar informações sobre os gols da partida
			printf("Informe o número da equipe(de acordo com o preeenchimento anterior) que fez o gol:\n");
			scanf("%d", &num1);
			if(num1==1){//If usado para caso o gol seja da equipe 1
				printf("Número do gol da Equipe(Primeiro Gol:Digite 1,Segundo gol:Digite 2) :\n");
				scanf(" %d", &qtd1);
				eqp1.goleqp[qtd1].numg = qtd1;//A variável que armazena o número do gol na Struct recebe o valor da variável intermediária usada para guardar o número
				printf("Informe o número do jogador que fez o gol:\n");
				scanf(" %d", &eqp1.goleqp[qtd1].numj);
				printf("Informe a minutagem em que aconteceu o gol:\n");
				scanf(" %[^\n]s", &eqp1.goleqp[qtd1].min);
			}
			if(num1==2){//If usado para caso o gol seja da equipe 2
				printf("Número do gol da Equipe(Primeiro Gol:Digite 1,Segundo gol:Digite 2) :\n");
				scanf(" %d", &qtd2);
				eqp2.goleqp[qtd2].numg = qtd2;//A variável que armazena o número do gol na Struct recebe o valor da variável intermediária usada para guardar o número
				printf("Informe o número do jogador que fez o gol:\n");
				scanf(" %d", &eqp2.goleqp[qtd2].numj);
				printf("Informe a minutagem em que aconteceu o gol:\n");
				scanf(" %[^\n]s", &eqp2.goleqp[qtd2].min);
			}
			op2=0;//Variável declarada como "0" para que ao final, o laço se repita(comentário se aplica aos demais comandos iguais a este nos ooutros cases)
			op1=10;//Variável declarada como "10" para que ao final, a variável esteja com uma opção que não está contida nos cases, sendo assim, evitando um laço infinito e permitindo que seja solicitado novamente ao usuário a escolha da opção(comentário se aplica aos demais comandos iguais a este nos ooutros cases)
			system("clear||cls");
		break;
		case 2://Caso usado para armazenar informações sobre os cartões amarelos da partida
			printf("Informe o número da equipe(de acordo com o preeenchimento anterior) que o cartão amarelo foi aplicado:\n");
			scanf(" %d", &num2);
			if(num2==1){//If usado para caso o cartão amarelo seja da equipe 1
				printf("Informe qual o número do jogador em que o cartão amarelo foi aplicado:\n");
				scanf(" %d", &n1);
				printf("Informe a minutagem em que o cartão amarelo foi aplicado:\n");
				scanf(" %[^\n]s", &eqp1.jogador[n1].ca);
			}
			else{
				if(num2==2){//If usado para caso o cartão amarelo seja da equipe 2
					printf("Informe qual o número do jogador em que o cartão amarelo foi aplicado:\n");
					scanf("%d", &n1);
					printf("Informe a minutagem em que o cartão amarelo foi aplicado:\n");
					scanf(" %[^\n]s", &eqp2.jogador[n1].ca);
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		case 3://Caso usado para armazenar informações sobre os cartões vermelhos da partida
			printf("Informe o número da equipe(de acordo com o preeenchimento anterior) que o cartão vermelho foi aplicado:\n");
			scanf(" %d", &num3);
			if(num3==1){//If usado para caso o cartão vermelho seja da equipe 1
				printf("Informe qual o número do jogador em que o cartão vermelho foi aplicado:\n");
				scanf(" %d", &n1);
				printf("Informe a minutagem em que o cartão vermelho foi aplicado:\n");
				scanf(" %[^\n]s", &eqp1.jogador[n1].cv);
			}
			else{
				if(num3==2){//If usado para caso o cartão vermelho seja da equipe 2
					printf("Informe qual o número do jogador em que o cartão vermelho foi aplicado:\n");
					scanf(" %d", &n1);
					printf("Informe a minutagem em que o cartão vermelho foi aplicado:\n");
					scanf(" %[^\n]s", &eqp2.jogador[n1].cv);
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		case 4://Caso usado para determinar o valor das variavéis de contagem de faltas da partida
			//Declarações feitas para que o número inicial de faltas seja 0
			printf("Informe o número da equipe(de acordo com o preeenchimento anterior) que realizou a falta:\n");
			scanf("%d", &num4);
			printf("Informe em qual período a falta ocorreu:\n");
			scanf("%d", &n1);
			if(num4==1){//If usado para ser executado quando a falta tenha sido cometida pela equipe 1
				if(n1==1){
					eqp1.faltasp1++;//If usado para ser executado quando a falta ocorrer no primeiro período
				}else{
					if(n1==2){
						eqp1.faltasp2++;//If usado para ser executado quando a falta ocorrer no segundo período
					}
				}
			}
			if(num4==2){//If usado para ser executado quando a falta tenha sido cometida pela equipe 2
				if(n1==1){
					eqp2.faltasp1++;//If usado para ser executado quando a falta ocorrer no primeiro período
				}else{
					if(n1==2){
						eqp2.faltasp2++;//If usado para ser executado quando a falta ocorrer no segundo período
					}
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		case 5://Caso usado para armazenar informações sobre os pedidos de tempo técnico da partida
			printf("Informe o número da equipe(de acordo com o preeenchimento anterior) que realizou o pedido de teempo técnico:\n");
			scanf(" %d", &num5);
			printf("Informe em qual período o pedido de tempo técnico ocorreu:\n");
			scanf(" %d", &n1);
			if(num5==1){//If usado para ser executado quando o tempo técnico tenha sido solicitado pela equipe 1
				if(n1==1){//If usado para ser executado caso o pedido de tempo tenha ocorrido no primeiro período
					printf("Informe a minutagem em que o pedido de tempo ténico foi realizado:\n");
					scanf(" %[^\n]s", &eqp1.tempp1);
				}else{
					if(n1==2){//If usado para ser executado caso o pedido de tempo tenha ocorrido no segundo período
						printf("Informe a minutagem em que o pedido de tempo ténico foi realizado:\n");
						scanf(" %[^\n]s", &eqp1.tempp2);
					}
				}
			}else{
				if(num5==2){//If usado para ser executado quando o tempo técnico tenha sido solicitado pela equipe 2
					if(n1==1){//If usado para ser executado caso o pedido de tempo tenha ocorrido no primeiro período
						printf("Informe a minutagem em que o pedido de tempo ténico foi realizado:\n");
						scanf(" %[^\n]s", &eqp2.tempp1);
					}else{
						if(n1==2){//If usado para ser executado caso o pedido de tempo tenha ocorrido no segundo período
							printf("Informe a minutagem em que o pedido de tempo ténico foi realizado:\n");
							scanf(" %[^\n]s", &eqp2.tempp2);
						}
					}
				}
			}
			op2=0;
			op1=10;
			system("clear||cls");
		break;
		default://Default para caso o usuário digitar uma opção que não esteja nas orientações iniciais, voltando o laço e informando que a opção escolhida não é válida
			printf("Nenhuma opção válida foi escolhida\n");
			op2=0;
	}
	}while(op2==0);
	
	
	//Preenchimento de informações sobre as informações gerais da partida
	//Leitura de variavéis usadas para armazenar o número de gols de cada período, que serão usadas para fazer a contagem do placar da partida
	puts ("------------------------ PÓS-PARTIDA -------------------------\n");
	puts ("------------------------- CONTAGEM ---------------------------\n");
	printf("Informe a quantidade de gols da equipe 1 no primeiro período:\n");
	scanf(" %d", &eqp1.golsp1);
	printf("Informe a quantidade de gols da equipe 1 no segundo período:\n");
	scanf(" %d", &eqp1.golsp2);
	printf("Informe a quantidade de gols da equipe 2 no primeiro período:\n");
	scanf(" %d", &eqp2.golsp1);
	printf("Informe a quantidade de gols da equipe 2 no segundo período:\n");
	scanf(" %d", &eqp2.golsp2);
	system("clear||cls");
	
	//Leitura de variavéis usadas para armazenar os horários do início e fim de cada período
	puts ("------------------ PÓS-PARTIDA -------------------\n");
	puts ("-------------------- HORÁRIO ---------------------\n");
	printf("Informe o horário de início do primeiro período:\n");
	scanf(" %[^\n]s", &I.horinip1);
	printf("Informe o horário do término do primeiro período:\n");
	scanf(" %[^\n]s", &I.horfimp1);
	printf("Informe o horário de início do segundo período:\n");
	scanf(" %[^\n]s", &I.horinip2);
	printf("Informe o horário do término do segundo período:\n");
	scanf(" %[^\n]s", &I.horfimp2);
	system("clear||cls");
	
	//Parte do código destinada a nomeação e salvamento de um arquivo de texto gerado a partir do resultado
	puts ("----------------------------- PÓS-PARTIDA -------------------------------\n");
	puts ("------------------------- SALVAR-ARQUIVO-SÚMULA -------------------------");
	char nomearq[MAX];//String de caracteres declarada para armazenar nome do arquivo
	printf("Digite o nome do arquivo que será salvo(obs: o arquivo será salvo em .txt):\n");
    scanf(" %[^\n]s", &nomearq);//Scanf usado para realizar a leitura da string até que seja pressionado o "ENTER"
    FILE *arq;//Ponteiro especial para arquivos, usado para manipular o arquivo 
    arq = fopen(nomearq,"w");//Comando que abre o arquivo com o nome inserido anterior, o segundo argumento do comando corresponde ao tipo do arquivo que será criado(Neste exemplo, o arquivo é do tipo .txt)
    if (arq==NULL){//If usado para emitir uma mensagem caso tenha ocorrido algum erro no processo de abertura do arquivo
         printf("Erro ao abrir o arquivo\n");
	} 
	else {//Else usado para caso o arquivo tenha sido aberto normalmente
		//Série de fprints usados para impressão do resultado da súmula eletrônica no arquivo criado anteriormente
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\tEQUIPE 1: %s | %d | X | %d | EQUIPE 2: %s\t\t\t\t\t\t\n", eqp1.nome,eqp1.golsp1+eqp1.golsp2,eqp2.golsp1+eqp2.golsp2,eqp2.nome);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\tEQUIPE 1 | Técnico: %s     | Capitão: %s\n", eqp1.tecnico, eqp1.capitao);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," Registro |\t\t\tJogadores\t\t|\tN°\t|\tCA\t|\tCV\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		for(cont=1;cont<=16;cont++){
			fprintf(arq,"%s | \t\t%s\t\t | %d | %s | %s |\n", eqp1.jogador[cont].registro, eqp1.jogador[cont].nome, eqp1.jogador[cont].numero, eqp1.jogador[cont].ca, eqp1.jogador[cont].cv);
			fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		}
		fprintf(arq," Pedidos de Tempo | 1° Período: %s | 2° Período: %s | Faltas | 1° Período: %d | 2° Período: %d \n", eqp1.tempp1, eqp1.tempp2, eqp1.faltasp1, eqp1.faltasp2);
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
		fprintf(arq,"\t\t\tEQUIPE 2 | Técnico: %s     | Capitão: %s\n", eqp2.tecnico, eqp2.capitao);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," Registro |\t\t\tJogadores\t\t|\tN°\t|\tCA\t|\tCV\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		for(cont=1;cont<=16;cont++){
			fprintf(arq,"%s | \t\t%s\t\t | %d | %s | %s |\n", eqp2.jogador[cont].registro, eqp2.jogador[cont].nome, eqp2.jogador[cont].numero, eqp2.jogador[cont].ca, eqp2.jogador[cont].cv);
			fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		}
		fprintf(arq," Pedidos de Tempo | 1° Período: %s | 2° Período: %s | Faltas | 1° Período: %d | 2° Período: %d \n", eqp2.tempp1, eqp2.tempp2, eqp2.faltasp1, eqp2.faltasp2);
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
		fprintf(arq,"\t\t\t\t\tIDENTIFICAÇÃO DO JOGO:\t\t\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"Competição: \t%s\n", I.competicao);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"N° Jogo: %d \t| Grupo: %s \t| Fase: %s \t| Data: %s \t|\n", I.numjogo, I.grupo, I.fase, I.data);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"Local: %s \t| Cidade: %s \t| UF: %s\n", I.local, I.cidade, I.uf);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\tHORÁRIO | INÍCIO | TÉRMINO \n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 1° Período | %s | %s |\n", I.horinip1, I.horfimp1);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 2° Período | %s | %s |\n", I.horinip2, I.horfimp2);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\t\t\t\tEQUIPE DE ARBITRAGEM\t\t\t\t\t\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"Árbitro Principal: %s\n", I.abtp);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"Árbitro Auxiliar: %s\n", I.abta);
		fprintf(arq,"________________________________________________________________________________________________________\n");
		
		fprintf(arq,"\n________________________________________________________________________________________________________\n");
		fprintf(arq,"\t\tCONTAGEM\n");
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 1° Período | %d | X | %d |\n", eqp1.golsp1, eqp2.golsp2);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq," 2° Período | %d | X | %d |\n", eqp1.golsp2, eqp2.golsp2);
		fprintf(arq,"--------------------------------------------------------------------------------------------------------\n");
		fprintf(arq,"   FINAL    | %d | X | %d |\n", eqp1.golsp1+eqp1.golsp2,eqp2.golsp1+eqp2.golsp2);
		fprintf(arq,"________________________________________________________________________________________________________\n");
	}
	
	return 0;
}

