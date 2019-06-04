#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h> 

/* (struct do tipo participante)Para armazenar informacoes sobre os participantes*/
typedef struct{
	int lin;
	int col;
	char categoria[15];
	char nome[30];
	char curso[30];
	char email[30];
	int ticket;
}participante; 

/* (procedimento)Zera todos os lugares,deixando todos vagos*/
void zerando_lugares(int m[30][60]){
	int lin,col;
	
	for(lin=0;lin<30;lin++){
		for(col=0;col<60;col++){
			m[lin][col]=0;	
		}
	}
}

/* (procedimento)Tela de boas vindas\Com Informaçoes do estado e cidade,logo da unip e informaçoes do sistema.(TELA 1)*/
void tela_de_boas_vindas(){
    int i,j;
    
    printf("\nARARAQUARA - SP\n\n\n");
	printf("*------------------------------------------------------------*\n");
	printf("|   ****   ****   ********       ****   ****   ********      |\n");
	printf("|   ****   ****   **** ****      ****   ****   ***********   |\n");
	printf("|   ****   ****   ****  ****     ****   ****   ****   ****   |\n");
	printf("|   ****   ****   ****   ****    ****   ****   ****   ****   |\n");
	printf("|   ****   ****   ****    ****   ****   ****   ***********   |\n");
	printf("|   ****   ****   ****     ****  ****   ****   ********      |\n");
	printf("|    *********    ****      **** ****   ****   ****          |\n");
	printf("|     *******     ****       ********   ****   ****          |\n");
	printf("*------------------------------------------------------------*\n  ");
	printf("\n\n\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n\n");
	printf("\n  Carregando Sistema\n");
	
	for (i = 1; i <= 50; i++){
	      printf ("  %d %%\r", i*2);
	      
	      for (j = 0; j < i; j++){
	         if (!j)
	           printf("  ");
	
	         printf ("%|");
	         Sleep(6);
	      }
	}
   printf("\n\n\nUNIVERSIDADE PAULISTA - UNIP\n");
   system("Cls");
}

/* (procedimento)Tela de dicas de uso\Com Informaçoes de como o usuario(a) deve operar o sistema.(TELA 2)*/
void tela_dicas_de_uso(){
	printf("\n* Seja Bem Vindo ao Sistema *\n\n");
	printf("\n__________________________________________________________________\n");
	printf("\nPrezado(a) Usuario(a),\n\n");
	printf("Esse Sistema para um melhor funcionamento, necessita da ultilizacao\n");
	printf("do teclado numerico para a escolha das opcoes,escolha a opcao\n");
	printf("desejada informando com numeros, assim que o sistema pedir.");
	printf("\n__________________________________________________________________\n\n");
	printf("\nUNIVERSIDADE PAULISTA - UNIP\n");
	printf("\n\n<<<Pressione Enter>>> ");
	getch();
	system("cls");
}

/* (procedimento)Tela de informacoes\Informacoes do evento ou qualquer que seja a atividade para qual o sistema sera usado.(TELA 2)*/
void tela_informacoes(){
	
	printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
	printf("Eventos de Hoje: Palestra");
	printf("\n__________________________________________________________________\n\n");
    printf("\t\t\t<<<Informacoes>>> \n\n");
    printf("Data: ");system ( "date /t" );
    printf("Local: Teatro-Unip\n");
    printf("Tema: Direitos Humanos\n");
    printf("Palestrante: Importante membro da ONU no Brasil\n"); 
	printf("\n__________________________________________________________________\n\n");
	printf("\n\n\nUNIVERSIDADE PAULISTA - UNIP\n"); 
	printf("\n\n<<<Pressione Enter>>> ");
	getch();
	system("cls");  
}

/* (Funcao)Conta a quantidade de lugares ocupados, para poder ser usada durante o programa,
 na condicao para deixar lugares para portadores de necessidades especiais*/	
int quant_lugares_acessibilidade(int m[30][60]){
	int lin,col,quant=0;
	
	for(lin=0;lin<30;lin++){
		for(col=0;col<60;col++){
			if(m[lin][col]==1){
				quant++;
			}	
		}
	}
	return quant;
}
/* (procedimento)Para cadastro dos participantes*/
void cadastrar_participante(int m[30][60],participante *p,int *n_ticket){
	int opc,lin,col,i,opc2;
	
	*n_ticket=*n_ticket+1;
	if(*n_ticket<1801){
		
		i=*n_ticket;
		do{
			printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
			printf("\n__________________________________________________________________\n\n");
		    printf("Para o cadastro informe a opcao a seguir\n\n");
			printf("{ 1 } - Professor \n");
			printf("{ 2 } - Convidado\n");
			printf("{ 3 } - Aluno \n");
			printf("{ 4 } - Portadores de Necessidades Especiais\n");
			printf("\n__________________________________________________________________\n\n");
	        printf("\nDigite a opcao >>> ");
	        scanf("%d",&opc);
	    }while(opc<1 || opc>4);
	    system("cls");
	    if(quant_lugares_acessibilidade(m)<1710){
		    if(opc==1){
		    	printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
				printf("\nOla Professor\n");
				printf("___________________________________________________________________________________ __________________________\n");
			    printf("\nLembrete: As fileiras 1 e 2 foram reservadas para Professores e Convidados, cada fileira contem 60 cadeiras.\n");
		       	printf("______________________________________________________________________________________________________________\n");
				printf("\nInforme a fileira e a cadeira que deseja\n");
				do{
					do{
				      	printf("\n>Fileira que deseja :");
				    	scanf("%d",&lin);
						if(lin!=1 && lin!=2){
							printf("\nInforme a Fileira entre 1 e 2");
						}	
			    	}while(lin!=1 && lin!=2);
			    	do{
				   	 	printf("\n>Cadeira que deseja :");
				   	 	scanf("%d",&col);
						if(col<1 || col>60){
							printf("\nInforme a Cadeira entre 1 e 60");
						}		
			    	}while(col<1 || col>60);
			    	if(m[lin][col]==1){
			       		printf("\nEste lugar esta reservado, informe outro\n");
			    	}
					else{
						printf("\n_______________________________\n");
						printf("Este lugar esta disponivel");
						printf("\n_______________________________\n");
					}
				}while(m[lin][col]==1);
				printf("\n\n<<<Pressione Enter para o cadastro>>> ");
			    getch();
			    system("cls");
		       	printf("\n\tCadastro");
		       	printf("\n_______________________________\n");
				printf("\nPreencha seus Dados\n");
				fflush(stdin);
				(p+i)->lin=lin;
				(p+i)->col=col;
				strcpy((p+i)->categoria,"Professor");
				printf("\nInforme o seu Nome: ");
				gets((p+i)->nome);
				fflush(stdin);
				printf("Informe o Curso que Leciona: ");
				gets((p+i)->curso);
				fflush(stdin);
				printf("Informe seu e-mail: ");
				gets((p+i)->email);
				fflush(stdin);
				m[lin][col]=1;
				(p+i)->ticket=i;
				printf("\n_______________________________\n");
				printf("\n\n<<<Confira as informacoes e pressione enter >>> ");
			    getch();
				system("cls");
				printf("\n>>> Cadastro realizado com sucesso <<<\n");
				printf("\n____________________________________________________________________\n");
				printf("\n\t\t\tTicket n: %d",i);
				printf("\nParticipante: %s\n",(p+i)->categoria);
				printf("\nNome: %s ",(p+i)->nome);
			    printf("\nCurso que Leciona: %s ",(p+i)->curso);
				printf("\nE-mail: %s ",(p+i)->email);
				printf("\nfileira: %d",lin);
				printf("\nCadeira: %d",col);
				printf("\nData: ");system ( "date /t" );
		        printf("Horas: ");system ("time /t");
		        printf("\n____________________________________________________________________\n");    
			}  
			if(opc==2){
				printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
				printf("\nOla Convidado\n");
				printf("___________________________________________________________________________________ __________________________\n");
			    printf("\nLembrete: As fileiras 1 e 2 foram reservadas para Professores e Convidados, cada fileira contem 60 cadeiras.\n");
		       	printf("______________________________________________________________________________________________________________\n");
				printf("\nInforme a fileira e a cadeira que deseja\n");
				do{
					do{
				      	printf("\n>Fileira que deseja :");
				    	scanf("%d",&lin);
						if(lin!=1 && lin!=2){
							printf("\nInforme a Fileira entre 1 e 2");
						}	
			    	}while(lin!=1 && lin!=2);
			    	do{
				   	 	printf("\n>Cadeira que deseja :");
				   	 	scanf("%d",&col);
						if(col<1 || col>60){
							printf("\nInforme a Cadeira entre 1 e 60");
						}		
			    	}while(col<1 || col>60);
			    	if(m[lin][col]==1){
			       		printf("\nEste lugar esta reservado, informe outro\n");
			    	}
					else{
						printf("\n_______________________________\n");
						printf("Este lugar esta disponivel");
						printf("\n_______________________________\n");
					}
				}while(m[lin][col]==1);
				printf("\n\n<<<Pressione Enter para o cadastro>>> ");
			    getch();
			    system("cls");
		       	printf("\n\tCadastro");
		       	printf("\n_______________________________\n");
				printf("\nPreencha seus Dados\n");
				fflush(stdin);
				(p+i)->lin=lin;
				(p+i)->col=col;
				strcpy((p+i)->categoria,"Convidado");
				printf("\nInforme o seu Nome: ");
				gets((p+i)->nome);
				fflush(stdin);
				printf("Informe seu e-mail: ");
				gets((p+i)->email);
				fflush(stdin);
				m[lin][col]=1;
				(p+i)->ticket=i;
				printf("\n_______________________________\n");
				printf("\n\n<<<Confira as informacoes e pressione enter >>> ");
			    getch();
				system("cls");
				printf("\n>>> Cadastro realizado com sucesso <<<\n");
				printf("\n____________________________________________________________________\n");
				printf("\n\t\t\tTicket n: %d",i);
				printf("\nParticipante: %s\n",(p+i)->categoria);
				printf("\nNome: %s ",(p+i)->nome);
				printf("\nE-mail: %s ",(p+i)->email);
				printf("\nfileira: %d",lin);
				printf("\nCadeira: %d",col);
				printf("\nData: ");system ( "date /t" );
		        printf("Horas: ");system ("time /t");
		        printf("\n____________________________________________________________________\n");    
			}  	
			if(opc==3){
				printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
				printf("\nOla Aluno\n");
				printf("___________________________________________________________________________________ ___________________________________\n");
			    printf("\nLembrete: As fileiras 1 e 2 foram reservadas para Professores e Convidados, As fileiras entre 3 e 30 para os alunos .\n");
		       	printf("_______________________________________________________________________________________________________________________\n");
				printf("\nInforme a fileira e a cadeira que deseja\n");
				do{
					do{
				      	printf("\n>Fileira que deseja :");
				    	scanf("%d",&lin);
						if(lin<3 || lin>30){
							printf("\nInforme a Fileira entre 3 e 30");
						}	
			    	}while(lin<3 || lin>30);
			    	do{
				   	 	printf("\n>Cadeira que deseja :");
				   	 	scanf("%d",&col);
						if(col<1 || col>60){
							printf("\nInforme a Cadeira entre 1 e 60");
						}		
			    	}while(col<1 || col>60);
			    	if(m[lin][col]==1){
			       		printf("\nEste lugar esta reservado, informe outro\n");
			    	}
					else{
						printf("\n_______________________________\n");
						printf("Este lugar esta disponivel");
						printf("\n_______________________________\n");
					}
				}while(m[lin][col]==1);
				printf("\n\n<<<Pressione Enter para o cadastro>>> ");
			    getch();
			    system("cls");
		       	printf("\n\tCadastro");
		       	printf("\n_______________________________\n");
				printf("\nPreencha seus Dados\n");
				fflush(stdin);
				(p+i)->lin=lin;
				(p+i)->col=col;
				strcpy((p+i)->categoria,"Aluno");
				printf("\nInforme o seu Nome: ");
				gets((p+i)->nome);
				fflush(stdin);
				printf("Informe o seu  Curso: ");
				gets((p+i)->curso);
				fflush(stdin);
				printf("Informe seu e-mail: ");
				gets((p+i)->email);
				fflush(stdin);
				m[lin][col]=1;
				(p+i)->ticket=i;
				printf("\n_______________________________\n");
				printf("\n\n<<<Confira as informacoes e pressione enter >>> ");
			    getch();
				system("cls");
				printf("\n>>> Cadastro realizado com sucesso <<<\n");
				printf("\n____________________________________________________________________\n");
				printf("\n\t\t\tTicket n: %d",i);
				printf("\nParticipante: %s\n",(p+i)->categoria);
				printf("\nNome: %s ",(p+i)->nome);
			    printf("\nCurso: %s ",(p+i)->curso);
				printf("\nE-mail: %s ",(p+i)->email);
				printf("\nfileira: %d",lin);
				printf("\nCadeira: %d",col);
				printf("\nData: ");system ( "date /t" );
		        printf("Horas: ");system ("time /t");
		        printf("\n____________________________________________________________________\n");    
			}  		
        }
	        if(opc==4){
					printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
					printf("\nACESSIBILIDADE\n");
					printf("Escolha a opcao abaixo");
					printf("\n__________________________________________________________________\n");
					printf("{ 1 } - Professor \n");
					printf("{ 2 } - Convidado\n");
					printf("{ 3 } - Aluno \n");
					printf("__________________________________________________________________\n\n");
					printf("\nDigite a opcao >>> ");
					scanf("%d",&opc2);
					if(opc2==1){
					system("cls");
					printf("\nOla Professor\n");
					printf("___________________________________________________________________________________ ___________________________________\n");
				    printf("\nLembrete: As fileiras 1 e 2 foram reservadas para Professores e Convidados.\n");
			       	printf("_______________________________________________________________________________________________________________________\n");
					printf("\nInforme a fileira e a cadeira que deseja\n");
					do{
						do{
					      	printf("\n>Fileira que deseja :");
					    	scanf("%d",&lin);
							if(lin!=1 && lin!=2){
								printf("\nInforme a Fileira entre 3 e 30");
							}	
				    	}while(lin!=1 && lin!=2);
				    	do{
					   	 	printf("\n>Cadeira que deseja :");
					   	 	scanf("%d",&col);
							if(col<1 || col>60){
								printf("\nInforme a Cadeira entre 1 e 60");
							}		
				    	}while(col<1 || col>60);
				    	if(m[lin][col]==1){
				       		printf("\nEste lugar esta reservado, informe outro\n");
				    	}
						else{
							printf("\n_______________________________\n");
							printf("Este lugar esta disponivel");
							printf("\n_______________________________\n");
						}
					}while(m[lin][col]==1);
					printf("\n\n<<<Pressione Enter para o cadastro>>> ");
				    getch();
				    system("cls");
			       	printf("\n\tCadastro");
			       	printf("\n_______________________________\n");
					printf("\nPreencha seus Dados\n");
					fflush(stdin);
					(p+i)->lin=lin;
					(p+i)->col=col;
					strcpy((p+i)->categoria,"Professor");
					printf("\nInforme o seu Nome: ");
					gets((p+i)->nome);
					fflush(stdin);
					printf("Informe o Curso que Leciona: ");
					gets((p+i)->curso);
					fflush(stdin);
					printf("Informe seu e-mail: ");
					gets((p+i)->email);
					fflush(stdin);
					m[lin][col]=1;
					(p+i)->ticket=i;
					printf("\n_______________________________\n");
					printf("\n\n<<<Confira as informacoes e pressione enter >>> ");
				    getch();
					system("cls");
					printf("\n>>> Cadastro realizado com sucesso <<<\n");
					printf("\n____________________________________________________________________\n");
					printf("\n\t\t\tTicket n: %d",i);
					printf("\nParticipante: %s\n",(p+i)->categoria);
					printf("\nNome: %s ",(p+i)->nome);
				    printf("\nCurso que Leciona: %s ",(p+i)->curso);
					printf("\nE-mail: %s ",(p+i)->email);
					printf("\nfileira: %d",lin);
					printf("\nCadeira: %d",col);
					printf("\nData: ");system ( "date /t" );
			        printf("Horas: ");system ("time /t");
			        printf("\n____________________________________________________________________\n");    
				} 
				if(opc2==2){
					system("cls");
					printf("\nOla Convidado\n");
					printf("___________________________________________________________________________________ ___________________________________\n");
				    printf("\nLembrete: As fileiras 1 e 2 foram reservadas para Professores e Convidados.\n");
			       	printf("_______________________________________________________________________________________________________________________\n");
					printf("\nInforme a fileira e a cadeira que deseja\n");
					do{
						do{
					      	printf("\n>Fileira que deseja :");
					    	scanf("%d",&lin);
							if(lin!=1 && lin!=2){
								printf("\nInforme a Fileira entre 3 e 30");
							}	
				    	}while(lin!=1 && lin!=2);
				    	do{
					   	 	printf("\n>Cadeira que deseja :");
					   	 	scanf("%d",&col);
							if(col<1 || col>60){
								printf("\nInforme a Cadeira entre 1 e 60");
							}		
				    	}while(col<1 || col>60);
				    	if(m[lin][col]==1){
				       		printf("\nEste lugar esta reservado, informe outro\n");
				    	}
						else{
							printf("\n_______________________________\n");
							printf("Este lugar esta disponivel");
							printf("\n_______________________________\n");
						}
					}while(m[lin][col]==1);
					printf("\n\n<<<Pressione Enter para o cadastro>>> ");
				    getch();
				    system("cls");
			       	printf("\n\tCadastro");
			       	printf("\n_______________________________\n");
					printf("\nPreencha seus Dados\n");
					fflush(stdin);
					(p+i)->lin=lin;
					(p+i)->col=col;
					strcpy((p+i)->categoria,"Convidado");
					printf("\nInforme o seu Nome: ");
					gets((p+i)->nome);
					fflush(stdin);
					printf("Informe seu e-mail: ");
					gets((p+i)->email);
					fflush(stdin);
					m[lin][col]=1;
					(p+i)->ticket=i;
					printf("\n_______________________________\n");
					printf("\n\n<<<Confira as informacoes e pressione enter >>> ");
				    getch();
					system("cls");
					printf("\n>>> Cadastro realizado com sucesso <<<\n");
					printf("\n____________________________________________________________________\n");
					printf("\n\t\t\tTicket n: %d",i);
					printf("\nParticipante: %s\n",(p+i)->categoria);
					printf("\nNome: %s ",(p+i)->nome);
					printf("\nE-mail: %s ",(p+i)->email);
					printf("\nfileira: %d",lin);
					printf("\nCadeira: %d",col);
					printf("\nData: ");system ( "date /t" );
			        printf("Horas: ");system ("time /t");
			        printf("\n____________________________________________________________________\n");    
				} 
				if(opc2==3){
					system("cls");
					printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
				printf("\nOla Aluno\n");
				printf("___________________________________________________________________________________ ___________________________________\n");
			    printf("\nLembrete: As fileiras 1 e 2 foram reservadas para Professores e Convidados, As fileiras entre 3 e 30 para os alunos .\n");
		       	printf("_______________________________________________________________________________________________________________________\n");
				printf("\nInforme a fileira e a cadeira que deseja\n");
				do{
					do{
				      	printf("\n>Fileira que deseja :");
				    	scanf("%d",&lin);
						if(lin<3 || lin>30){
							printf("\nInforme a Fileira entre 3 e 30");
						}	
			    	}while(lin<3 || lin>30);
			    	do{
				   	 	printf("\n>Cadeira que deseja :");
				   	 	scanf("%d",&col);
						if(col<1 || col>60){
							printf("\nInforme a Cadeira entre 1 e 60");
						}		
			    	}while(col<1 || col>60);
			    	if(m[lin][col]==1){
			       		printf("\nEste lugar esta reservado, informe outro\n");
			    	}
					else{
						printf("\n_______________________________\n");
						printf("Este lugar esta disponivel");
						printf("\n_______________________________\n");
					}
				}while(m[lin][col]==1);
				printf("\n\n<<<Pressione Enter para o cadastro>>> ");
			    getch();
			    system("cls");
		       	printf("\n\tCadastro");
		       	printf("\n_______________________________\n");
				printf("\nPreencha seus Dados\n");
				fflush(stdin);
				(p+i)->lin=lin;
				(p+i)->col=col;
				strcpy((p+i)->categoria,"Aluno");
				printf("\nInforme o seu Nome: ");
				gets((p+i)->nome);
				fflush(stdin);
				printf("Informe o seu  Curso: ");
				gets((p+i)->curso);
				fflush(stdin);
				printf("Informe seu e-mail: ");
				gets((p+i)->email);
				fflush(stdin);
				m[lin][col]=1;
				(p+i)->ticket=i;
				printf("\n_______________________________\n");
				printf("\n\n<<<Confira as informacoes e pressione enter >>> ");
			    getch();
				system("cls");
				printf("\n>>> Cadastro realizado com sucesso <<<\n");
				printf("\n____________________________________________________________________\n");
				printf("\n\t\t\tTicket n: %d",i);
				printf("\nParticipante: %s\n",(p+i)->categoria);
				printf("\nNome: %s ",(p+i)->nome);
			    printf("\nCurso: %s ",(p+i)->curso);
				printf("\nE-mail: %s ",(p+i)->email);
				printf("\nfileira: %d",lin);
				printf("\nCadeira: %d",col);
				printf("\nData: ");system ( "date /t" );
		        printf("Horas: ");system ("time /t");
		        printf("\n____________________________________________________________________\n");        
				}  		 		 		
            }
   }
   else{printf("\nLotacao Maxima");}
}
/*(procedimento)Realiza o sorteio entre os participantes,de tal modo que os convidados dos participantes nao participe.*/
void sorteio(participante *p,int *n_ticket){
	int i,n,sorteio;
	if(*n_ticket>0){
		printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
		printf("\n>>>>>>Sorteio<<<<<<\n");
		printf("\n\nDeseja Realizar quantos sorteios:");
		scanf("%d",&n);
		srand(time(NULL));
		for(i=1;i<=n;i++){
	   	    sorteio=1+( rand() % *n_ticket );
	   	    if(strcmp((p+sorteio)->categoria,"Convidado")==0)
			{
				n=n+1;
			}
			else{
				printf("\nOs Sorteados sao:");
				printf("\n*********************\n");        
				printf("\n>> %s",(p+sorteio)->categoria);
				printf("\nNome: %s",(p+sorteio)->nome);
				printf("\nE-mail: %s",(p+sorteio)->email);
				printf("\n*********************\n");        
			}
	    }
    }
    else{
    	printf("\nOps!!!\n\n");
    	printf(">>>Para o sorteio ser realizado faca o cadastro dos participantes primeiro<<<");
	}	
}
/*(procedimento)Gera um arquivo txt com o nome e email dos participantes.*/
void arquivo_emails(participante *p,int *n_ticket,FILE *arquivo){
	int i;
	
	if(*n_ticket>0){
		arquivo=fopen("Lista_email_participantes.txt","wt");
		if(!arquivo){
		    	printf("\nErro na abertura do arquivo");
			    getch();
			    exit(1);
	    }
	    fprintf(arquivo,"\nLista com e-mails dos participantes\n\n");
	    for(i=1;i<=*n_ticket;i++){
	    	fprintf(arquivo, "\n(%d)- Nome: %s     E-mail: %s\n",i,(p+i)->nome,(p+i)->email); 
		}
		fprintf(arquivo,"\n\n\nUNIVERSIDADE PAULISTA - UNIP\n");
		fclose(arquivo);
		
		printf("\nArquivo gerado com sucesso,para acessa lo entre na raiz onde se encontra o executavel desse sistema.");
		printf("\n\n\nUNIVERSIDADE PAULISTA - UNIP\n"); 
    }
     else{
    	printf("\nOps!!!\n\n");
    	printf(">>>Para o arquivo ser gerado faca o cadastro dos participantes primeiro<<<");
	}	
    
}
void main(){
	
	FILE *arquivo;
    participante *p;
	int n_ticket=0,op,m[30][60];
	
	zerando_lugares(m);
	tela_de_boas_vindas();
	tela_dicas_de_uso();
	tela_informacoes();
	
	p = malloc(1800*sizeof(participante));
	do{
		printf("\n\n\t\t[ SISTEMA DE CONTROLE DE ENTRADA ]\n\n\n");
		printf("\t\t\tMENU DE OPCOES\n");
		printf(" ___________________________________________________________________\n");
		printf("|                                                                   |\n");
		printf("| { 1 } - Cadastrar Participantes                                   |\n");
		printf("| { 2 } - Realizar Sorteio                                          |\n");
		printf("| { 3 } - Gerar lista de e-mails dos participantes                  |\n");
		printf("| { 0 } - Sair                                                      |\n");
		printf("|___________________________________________________________________|\n\n\n");
        printf("Digite a opcao >>> ");
        scanf("%d",&op);
        system("cls"); 
		switch (op){
			case 1: cadastrar_participante(m,p,&n_ticket);
					break;
			case 2: sorteio(p,&n_ticket);
					break;
			case 3: arquivo_emails(p,&n_ticket,arquivo);
					break;
			case 0: printf("Programa finalizado! \n");
					break;
			default: printf("Opcao invalida! Tente novamente \n");
		}
		
		printf("\n\n\nUNIVERSIDADE PAULISTA - UNIP\n"); 
		system("pause");
		system("cls");	
	}while (op != 0);
	free(p);
}
