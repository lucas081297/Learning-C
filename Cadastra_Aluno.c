#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define MAX_LINHA 1024
#define SEPARADOR ";"

int menu_opcoes(),n,h,a=0,qtd;  
void imprime_lista(); 
void cont_no();
void remoc();
void mod();
void lercsv();
void loadingBar();
  
struct descritor{
		int n;
		struct aluno *i,*f;
	};
	struct descritor *d;
	
	struct tm nasc,tm;
	
	struct aluno{
		struct tm nasc;
		int mat;
		struct aluno *prox;
		char comp1[15];
		char comp2[15];
		char comp3[15];
	};
	struct aluno *p, *q, *r;
	int i,sn=1,option,cont=1,x,op1,l,j;
	
	char dt[11];
	
int main (void)
{
	
	printf("-----------------------------\n");
	printf("CRIA ALUNOS v2.5 \t\t\t\t\t\t\t\t\t Por: Lucas Rodrigues\n");
	printf("-----------------------------\n");
	FILE *fp;
	printf("Como quer comecar?\n1 - Abrir Arquivo\n2 - Novo arquivo?\n");
	scanf("%d",&op1);
	if(op1==1){
		fp=fopen ("Lista.csv","r");
		if(fp!=NULL){
			printf("Arquivo encontrado!\n");
			loadingBar();
			lercsv();
			setlocale(LC_ALL,"");
		}else
		{
			printf("Arquivo não existe! ou Opção Inválida\nUm novo arquivo será criado...\n\n");
			setlocale(LC_ALL,"");
			cria_no();
		}
	}	
    else{
    	fp=fopen ("Lista.csv","w"); 
		cria_no();
	}
    do{
        switch (menu_opcoes()){
            case 1:
				 {
            	   imprime_lista();
                   break;
                 }
            case 2:
                 {
                   cont_no();
                   break;
                 }
            case 3:
                 {
                   remoc();
                   break;
                 }
            case 4:
                 {
            	   mod();
                   break;
                 }
           case 5:
           		 {
		           	p = d->i;
		           	fprintf(fp,"Data de Nascimento;Matrícula;Competência 1;Competência 2;Compêtencia 3\n");
					while(p!= NULL){
						fprintf(fp,"%d/%d/%d;%d;%s;%s;%s\n",p->nasc.tm_mday,p->nasc.tm_mon,p->nasc.tm_year,p->mat,p->comp1,p->comp2,p->comp3);
						p = p->prox;
					}
					fclose(fp);
					return 0;
				 }
			}
		}
		while (option != 5);
		system("PAUSE");
		return 0;
	}
int menu_opcoes()
{
    option=0;
   do
   {
      printf ("\nOpcoes: \n\t [1] - Consultar lista \n\t [2] - Cadastrar mais aluno \n\t [3] - Remover alunos \n\t [4] - Modificar alunos \n\t [5] - Sair \n\n\tDigite sua opcao:  ");
      scanf ("%i",&option);
      if((option<1)||(option>5))
      printf("\n\nOpcao invalida, tente novamente\n\n");
   }while((option > 5)||(option<1));    
  return option;  
}
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}
cria_no(){
	struct tm tm={0};
	d = malloc(sizeof(struct descritor));
	d->n = 0;
	d->i = NULL;
	d->f = NULL;
	char data[11];
	int x,inc=1,day,month,year;
	char *m,*y;
	time_t mytime;
    mytime = time(NULL);
    struct tm gt= *localtime(&mytime);
	printf("Quantos alunos quer cadastrar?\n");
	scanf(" %d",&qtd);
	for (x=0; x<qtd; x++){
		inc=1;
		p = malloc(sizeof(struct aluno));
		p->prox = NULL;
		while(inc==1){ 
			printf("Informe a data de nascimento (No formato dd/mm/aaaa)\n");
			scanf(" %d/%d/%d", &p->nasc.tm_mday,&p->nasc.tm_mon,&p->nasc.tm_year);
			if(p->nasc.tm_mday<1||p->nasc.tm_mday>31){
				printf("Dia inválido!\n");
				day=0;
			}
			else{
				day=1;
			}
			if(p->nasc.tm_mon<1||p->nasc.tm_mon>12){
				printf("Mes inválido!\n");
				month=0;
			}
			else{
				month=1;
			}
			if(p->nasc.tm_year>(gt.tm_year+1900)){
				printf("Ano inválido!\n");
				year=0;
			}
			else{
				year=1;
			}
			if(day==1&&month==1&&year==1){
				inc=0;
			}
		}
		printf("Informe a matrícula\n");
		scanf("%d", &p->mat);
		printf("Informe a competência 1\n");
		scanf(" %s",p->comp1);
		flush_in();
		printf("Informe a competência 2\n");
		scanf(" %s", p->comp2);
		flush_in();
		printf("Informe a competência 3\n");
		scanf(" %s", p->comp3);
		flush_in();
		if(d->n == 0){ 
			d->n = 1;
			d->i = p;
			d->f =p;
		}
		else{   
			d->f->prox = p;
			d->f=p;
			d->n++;
		}
		printf("\n");
	}
}
void cont_no(){
	struct tm tm={0};
	char data[11];
	int x,inc=1,day,month,year;
	char *m,*y;
	time_t mytime;
    mytime = time(NULL);
    struct tm gt= *localtime(&mytime);
	printf("Quantos alunos quer cadastrar?\n");
	scanf(" %d",&qtd);
	for (x=0; x<qtd; x++){
		p = malloc(sizeof(struct aluno));
		p->prox = NULL;
		while(inc==1){ 
			printf("Informe a data de nascimento (No formato dd/mm/aaaa)\n");
			scanf(" %d/%d/%d", &p->nasc.tm_mday,&p->nasc.tm_mon,&p->nasc.tm_year);
			if(p->nasc.tm_mday<1||p->nasc.tm_mday>31){
				printf("Dia inválido!\n");
				day=0;
			}
			else{
				day=1;
			}
			if(p->nasc.tm_mon<1||p->nasc.tm_mon>12){
				printf("Mes inválido!\n");
				month=0;
			}
			else{
				month=1;
			}
			if(p->nasc.tm_year>(gt.tm_year+1900)){
				printf("Ano inválido!\n");
				year=0;
			}
			else{
				year=1;
			}
			if(day==1&&month==1&&year==1){
				inc=0;
			}
		}
		printf("Informe a matrícula\n");
		scanf("%d",&p->mat);
		printf("Informe a competência 1\n");
		scanf("%s",p->comp1);
		printf("Informe a competência 2\n");
		scanf("%s",&p->comp2);
		printf("Informe a competência 3\n");
		scanf("%s",&p->comp3);   
		if(d->n == 0){ 
			d->n = 1;
			d->i = p;
			d->f =p;
		}
		else{   
			d->f->prox = p;
			d->f=p;
			d->n++;
		}
		printf("\n");
	}
}
void remoc(){
	int sk, posicao;
	int w = 1;
    	if(d->n==0){
			printf("\n A fila está vazia");
		}
	    else 
		{
		   printf("\n Qual posição você quer remover?: ");
           scanf("%d",&posicao);
           posicao;
	    if(posicao == 1)
		{
   	   	d->n--;
   		d->i = d->i->prox;
		}
	  	else{
		  	p = d->i;
		  	while(p!= NULL)
			  {
		  		w++;
		  		if(w!=posicao)
				  {;
		  			p=p->prox;
		  		}
		  		else{
		  			p->prox = p->prox->prox;
			  		d->n--;
				}
			}
		}
	}
 printf("\n Aluno removido");
}
	
void imprime_lista(){
	p = d->i;
	printf("\n Sua lista tem %d alunos \n", d->n);
	int pos_list=1;
	while(p!= NULL){
		printf(" [%d] ", pos_list);
		printf("%d/%d/%d ",p->nasc.tm_mday,p->nasc.tm_mon,p->nasc.tm_year);
		printf("%d  ",p->mat);
		printf( "%s ",p->comp1);
		printf("%s ",p->comp2);
		printf("%s ",p->comp3);
		printf("\n");
		p = p->prox;
		pos_list++;
	}
}

void mod(){
	int pos_mod,inc2;
	struct tm tm={0};
	char data[11];
	int x,inc=1,day,month,year;
	char *m,*y;
	time_t mytime;
    mytime = time(NULL);
    struct tm gt= *localtime(&mytime);
    while(inc2==0){
		printf("Qual posição quer modificar?\n");
		imprime_lista();
		printf("\n");
		scanf("%d",&pos_mod);
		if((pos_mod>d->n)||(pos_mod<=0)){
			printf("Posição inválida!!");	
		}
		else{
			inc2=1;
		}
	}
	r=d->i;
	for (i=1;i<pos_mod;i++){
		r=r->prox;
	}
	while(inc==1){ 
			printf("Informe a data de nascimento (No formato dd/mm/aaaa)\n");
			scanf(" %d/%d/%d", &p->nasc.tm_mday,&p->nasc.tm_mon,&p->nasc.tm_year);
			if(p->nasc.tm_mday<1||p->nasc.tm_mday>31){
				printf("Dia invalido!\n");
				day=0;
			}
			else{
				day=1;
			}
			if(p->nasc.tm_mon<1||p->nasc.tm_mon>12){
				printf("Mês inválido!\n");
				month=0;
			}
			else{
				month=1;
			}
			if(p->nasc.tm_year>(gt.tm_year+1900)){
				printf("Ano inválido!\n");
				year=0;
			}
			else{
				year=1;
			}
			if(day==1&&month==1&&year==1){
				inc=0;
			}
		}
			printf("Informe a matrícula\n");
			scanf("%d",&r->mat);
			printf("Informe a competência 1\n");
			scanf("%s",&r->comp1);
			printf("Informe a competência 2\n");
			scanf("%s",&r->comp2);
			printf("Informe a competência 3\n");
			scanf("%s",&r->comp3);
}
void lercsv(){
	d = malloc(sizeof(struct descritor));
	d->n = 0;
	d->i = NULL;
	d->f = NULL;
	time_t mytime;
    mytime = time(NULL);
    struct tm gt= *localtime(&mytime);
	char linha[200];
	struct tm tm={0};
	FILE *fp;
	l=0;
	fp=fopen("Lista.csv","r");
	while(fgets(linha,sizeof(linha),fp)){
		char *tok;
		i=1;
		p=malloc(sizeof(struct aluno));
		p->prox=NULL;
		tok = strtok(linha,";");
		while(tok!=NULL){
			if(l<5){
				tok=strtok(NULL,";");
				l++;
			}
			else{
				if(i==1){
					strcpy(dt,tok);
					sscanf(dt,"%d/%d/%d",&p->nasc.tm_mday,&p->nasc.tm_mon,&p->nasc.tm_year);
					//printf("%d/%d/%d",p->nasc.tm_mday,p->nasc.tm_mon,p->nasc.tm_year);
				}
				if(i==2){
					p->mat=atoi(tok);
					//printf("%d\n",p->mat);
				}
				if(i==3){
					strcpy(p->comp1,tok);
					//printf("%s\n",p->comp1);	
				}
				if(i==4){
					strcpy(p->comp2,tok);
					//printf("%s\n",p->comp2);
				}
				if(i==5){
					strcpy(p->comp3,tok);
					//printf("%s\n",p->comp3);	
				}
				tok=strtok(NULL,";");
				i++;
				//printf("\n");
				}
			}
			if(d->n == 0){ 
				d->n = 1;
				d->i = p;
				d->f = p;
			}
			else{   
				d->f->prox = p;
				d->f=p;
				d->n++;
		}
	}
	p = d->i;
	d->i=p->prox;
	free(p);
	d->n--;
	p=d->i;
	fclose(fp);
}
void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0F");
  
    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;
    printf("\n\n\n\n\t\t\t\t\t Carregando...\n\n");
    printf("\t\t\t\t\t");
  
    // Print initial loading bar
    for (i = 0; i < 26; i++)
        printf("%c", a);
  
    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");
  
    // Print loading bar progress
    for (i = 0; i < 26; i++) {
        printf("%c", b);
  
        // Sleep for 1 second
        Sleep(50);
    }
}
