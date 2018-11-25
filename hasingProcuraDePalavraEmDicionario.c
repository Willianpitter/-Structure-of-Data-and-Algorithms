// Willian Pitter Cardoso Lima
//Eng. de computacao CEFET/RJ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;
typedef struct Lista{
	char nome[30];
	struct Lista *prox;
}lista; 


typedef struct arvore{
	struct arvore *le;
	struct arvore *ld;
	char palavra[20];
	int tamanho;



}arvore;

void libera(arvore *p){
	if(p!=NULL){
		libera(p->ld);
		libera(p->le);
		free(p);

	}


}

void poenoarquivo(arvore *p){
	if(p!=NULL){
		poenoarquivo(p->ld);
		fprintf(arq,"%s\n",p->palavra);
		poenoarquivo(p->le);
	}



}


lista* fazlista(lista *str,arvore *p){
	lista *aux,*aux2 = str;	
	
	if(p != NULL){
		fazlista(str,p->le);
		if(str == NULL){
			str = (lista *) malloc(sizeof(lista));
			strcpy(str->nome,p->palavra);
		}else{
			aux = (lista *)malloc(sizeof(lista));
			str->prox = aux;
			str = aux;
			strcpy(str->nome,p->palavra);
		}
	fazlista(str,p->ld);
	}
	return aux2;
}

void inordem(arvore *p){
	if(p!=NULL){
		inordem(p->ld);
		printf("%s\n",p->palavra);
		inordem(p->le);
	}
}

void menor(arvore *p,char nome2[30]){
	
	if(p!=NULL){
		menor(p->le,nome2);
		if(strcmp(p->palavra,nome2) == -1){
			
			strcpy(nome2,p->palavra);
		}
	}
}

void maiorarvore(arvore *p,char nome3[30]){
		if(p!=NULL){
			maiorarvore(p->ld,nome3);
			if(strcmp(p->palavra,nome3) == 1){
				strcpy(nome3,p->palavra);
			}
		}


}

int buscar(arvore *p,char nome[30],int h,int *controle){
	if(p!=NULL){
		buscar(p->le,nome,h,controle);
		if(strcmp(p->palavra,nome) == 0){
			*controle = 1;
		}
		buscar(p->ld,nome,h,controle);
	}
}


void adicionar(int h,int k,char nome[30],int M,arvore *vet[M]){
	
	arvore *raiz,*point,*aux;

	if(vet[h] == NULL){
			raiz = (arvore *)malloc(sizeof(arvore));
			vet[h] = raiz;
			strcpy(raiz->palavra,nome);
			raiz->tamanho = k;
			aux = raiz;
		}else{
			aux = vet[h];
			point = (arvore *)malloc(sizeof(arvore));
			strcpy(point->palavra,nome);
			point->tamanho = k;
			for(;;){		
				if(strcmp(point->palavra,aux->palavra) == 1){
					if(aux->ld == NULL){				
						aux->ld = point;
						break;
					}else{
						aux = aux->ld;					
					}
				}else{
					if(aux->le == NULL){
						aux->le = point;
						break;
					}else{
						aux = aux->le;
					}
				}
			}
		}

}
void montartabela (int M,int p,int a,int b,arvore *vet[M]){

	FILE *arq;
	char nome[30],auxv[30];
	int k,h,i;
	arvore *raiz,*point,*aux;

	for(i=0;i<M;i++){
			vet[i] = NULL;
		}
	arq = fopen("lista.txt","r");	
	while(fscanf(arq,"%s",nome) == 1){
		strcpy(auxv,nome);
		k = valordapalavra(nome);		
		strcpy(nome,auxv);
		h = (((a*k + b) % p) % M);

		// A ARVORE ABB
		if(vet[h] == NULL){
			raiz = (arvore *)malloc(sizeof(arvore));
			vet[h] = raiz;
			strcpy(raiz->palavra,nome);
			raiz->tamanho = k;
			aux = raiz;
		}else{
			aux = vet[h];
			point = (arvore *)malloc(sizeof(arvore));
			strcpy(point->palavra,nome);
			point->tamanho = k;
			for(;;){		
				if(strcmp(point->palavra,aux->palavra) == 1){
					if(aux->ld == NULL){				
						aux->ld = point;
						break;
					}else{
						aux = aux->ld;					
					}
				}else{
					if(aux->le == NULL){
						aux->le = point;
						break;
					}else{
						aux = aux->le;
					}
				}
			}
		}
	}
}


int valordapalavra(char nome[20]){
		int soma = 0,i,a;
		a = strlen(nome);
		for(i=0;i<a;i++){
			if(nome[i] == 'A'){
				soma = soma + 1;
			}else if(nome[i] == 'B'){
				soma = soma + 2;
			}else if(nome[i] == 'C'){
				soma = soma + 3;
			}else if(nome[i] == 'D'){
				soma = soma + 4;
			}else if(nome[i] == 'E'){
				soma = soma + 5;
			}else if(nome[i] == 'F'){
				soma = soma + 6;
			}else if(nome[i] == 'G'){
				soma = soma + 7;
			}else if(nome[i] == 'H'){
				soma = soma + 8;
			}else if(nome[i] == 'I'){
				soma = soma + 9;
			}else if(nome[i] == 'J'){
				soma = soma + 10;
			}else if(nome[i] == 'K'){
				soma = soma + 11;
			}else if(nome[i] == 'L'){
				soma = soma + 12;
			}else if(nome[i] == 'M'){
				soma = soma + 13;
			}else if(nome[i] == 'N'){
				soma = soma + 14;
			}
			
			if(nome[i] = 'O'){
				soma = soma + 15;
			}else if(nome[i] == 'P'){
				soma = soma + 16;
			}else if(nome[i] == 'Q'){
				soma = soma + 17;
			}else if(nome[i] == 'R'){
				soma = soma + 18;
			}else if(nome[i] == 'S'){
				soma = soma + 19;
			}else if(nome[i] == 'T'){
				soma = soma + 20;
			}else if(nome[i] == 'U'){
				soma = soma + 21;
			}else if(nome[i] == 'V'){
				soma = soma + 22;
			}else if(nome[i] == 'W'){
				soma = soma + 23;
			}else if(nome[i] == 'X'){
				soma = soma + 24;
			}else if(nome[i] == 'Y'){
				soma = soma + 25;
			}else if(nome[i] == 'Z'){
				soma = soma + 26;
			}
		}

	return soma;		
}

int primo(int m){ //Produra o primeiro primo depois de um dado numero.
	int i,p,a,b,aux,j = 0;

	p = m + 1;
	i = 2;

	for(;;){
		while(p != i ){
			aux = (p % i);
			if(aux == 0){
				j=1;
			}
		i++;
		}
		if(j == 0){ // Se quando sair do loop, o P for primo,para o for.
			return(p);	
		}
		p++;
		j = 0;
		i = 2;
	}
}


void main(){
	int i=0,a,b,p,k,h,maior = 0,M,op,controle = 0,posicao;
	float carga,m,N=0;
	char nome[30],auxn[30],auxn3[30],nome2[30],auxn2[30],nome3[30],nome4[30],nome5[30],nome6[30];
	lista *str;
	for(;;){
		printf("Digite o valor de M\n");
		scanf("%f",&m);

		M = m;
		if((M % 2) == 0 ){
			M = M + 1;
		}
		m = M;
		
		int vet[M];
		arvore *veta[M],*pontaux;

		for(i=0;i<m;i++){
			vet[i] = 0;

		}

		p = primo(m);
		srand(time(NULL));
		
		a = rand() % p + 1; //Nao pode ser zero
		b = rand() % p;
		for(i=0;i<m;i++){
			vet[i] = 0;
		}
		arq = fopen("lista.txt","r");
		while(fscanf(arq,"%s",nome) == 1){
			k = valordapalavra(nome);	
			h = (((a*k + b) % p) % M);
			vet[h] = vet[h] + 1;
		}
		for(i=0;i<m;i++){
			printf("Colisoes na %d casa %d\n",i,vet[i]);
			if(vet[i] > maior){
				maior = vet[i];

			}
		}

		N = 0;
		for(i=0;i<m;i++){
			if(vet[i] != 0){
				N++;
			}
		}
		printf("\n");
		carga = N/m;
		printf("O fator de carga eh %f\n",carga);
		printf("O maior quantidade de colisoes foi %d\n",maior);
		printf("\n\nDeseja utiluzar esse Valor de M?\n1-Sim\n2-Nao\n");
		op = 0;
		scanf("%d",&op);
		if(op == 1){
			fclose(arq);
			montartabela(m,p,a,b,veta);
			for(;;){
				printf("------------------------------Menu------------------------\n1- Buscar palavra\n2- Editar palavra\n3- Inserir palavra\n4- Excluir palavra\n5- Mostrar maior e menor palavra\n6- Imprimir sinonimos ordenados de forma decrescente\n7- Sair\n-----------------------------------------------------------\n");
				scanf("%d",&op);
				system("clear");
				switch(op){

				case 1:
					printf("Digite a palavra que deseja procurar (em capslock)\n");
					scanf("%s",nome);
					strcpy(auxn,nome);
					k = valordapalavra(nome);
					strcpy(nome,auxn);
					strcpy(nome4,nome);
					h = (((a*k + b) % p) % M);
					buscar(veta[h],nome,h,&controle);
					printf("\n\n\n");
	
					if(controle == 0){
						printf("Palavra inexistente\n");

					}else{	
						printf("Essa palavra existe na posicao %d\n",h);
					}					
					controle = 0;
					printf("\n\n\n");

					break;

				case 2:
					printf("Digite a palavra que deseja editar:\n");
					scanf("%s",nome);
					strcpy(auxn,nome);
					k = valordapalavra(nome);
					strcpy(nome,auxn);
					h = (((a*k + b) % p) % M);
					buscar(veta[h],nome,h,&controle);
					printf("\n\n\n");
	
					if(controle == 0){
						printf("Nao foi possivel editar,palavra inexistente\n");

					}else{	
						controle = 0;
						//Confere se a palavra nova ja esta no programa
						printf("Digite a palavra nova:\n");
						scanf("%s",nome4);
						strcpy(auxn3,nome4);
						k = valordapalavra(nome4);
						strcpy(nome4,auxn3);
						h = (((a*k + b) % p) % M);
						buscar(veta[h],nome4,h,&controle);
						printf("\n\n\n"); 
		
						if(controle == 0){
							adicionar(h,k,nome4,M,veta);
							k = valordapalavra(nome);
							strcpy(nome,auxn);

							h = (((a*k + b) % p) % M);
							pontaux = veta[h];
							veta[h] = NULL;
							str = (lista *)malloc(sizeof (lista));
							str = fazlista(str,pontaux);
							str = str->prox;

							while(str->prox != NULL){
								if(strcmp(nome,str->nome) != 0){
									strcpy(nome5,str->nome);
									k = valordapalavra(str->nome);
									strcpy(str->nome,nome5);
									h = (((a*k + b) % p) % M);
									adicionar(h,k,str->nome,M,veta);
									str = str->prox;
								}else{
									str = str->prox;

								}
							}
						k = valordapalavra(nome4);
						h = (((a*k + b) % p) % M);
						printf("\nPalavra insedira com sucesso na posicao %d\n",h);
						}else{	
							printf("Impossivel editar, essa palavra ja exise.\n");
						}					
						controle = 0;
						printf("\n\n\n");

						}					
					break;

				case 3:
					printf("Digite a palavra que deseja inserir (em capslock)\n");
					scanf("%s",nome);
					strcpy(auxn,nome);
					k = valordapalavra(nome);
					strcpy(nome,auxn);
					h = (((a*k + b) % p) % M);
					buscar(veta[h],nome,h,&controle);	
					if(controle == 0){
						adicionar(h,k,nome,M,veta);			
						printf("\nPalavra insedira com sucesso na posicao %d\n",h);
			
					}else{
						printf("Não foi possível inserir a nova palavra desejada,palavra já	existente\n");
					}
					controle = 0;
				break;
				printf("\n\n\n");

				case 4:	
					printf("Digite a palaVra que deseja excluir:\n");
					scanf("%s",nome);
					strcpy(auxn,nome);
					k = valordapalavra(nome);
					strcpy(nome,auxn);
					h = (((a*k + b) % p) % M);
					buscar(veta[h],nome,h,&controle);
					if(controle == 0){
						printf("Nao foi possivel excluir a palavra,palavra inexistente\n");

					}else{	
						pontaux = veta[h];
						veta[h] = NULL;
						str = (lista *)malloc(sizeof (lista));
						str = fazlista(str,pontaux);
						str = str->prox;

						while(str->prox != NULL){
							if(strcmp(nome,str->nome) != 0){
								adicionar(h,k,str->nome,M,veta);
								str = str->prox;
							}else{
								str = str->prox;

							}
						}
						if(strcmp(nome,str->nome) != 0){
							adicionar(h,k,str->nome,M,veta);
						}
						printf("A palavra excluida com sucesso da posicao %d\n",h);

					}					
					controle = 0;

					break;
				case 5:
					strcpy(nome2,"Z");
					strcpy(nome3,"A");
					for(i=0;i<M;i++){
						pontaux = veta[i];
						maiorarvore(pontaux,nome3);
						pontaux = veta[i];
						menor(pontaux,nome2);
					}
					printf("Menor : %s , Maior : %s\n",nome2,nome3);
					break;
				case 6:
					printf("Digite o numero da posicao que deseja imprimir as palavras\n");
					scanf("%d",&posicao);
					pontaux = veta[posicao];
					if(posicao >= 0 && posicao < M ){
						if(veta[posicao] != NULL){
							inordem(pontaux);

						}else{
							printf("Posicao nula, ABB nao vinculada\n");
						}
						printf("\n\n\n");
					}else{
						printf("Numero fora do limite do vetor (maior que o vetor)\n");
					}
					break;

				case 7: // NAO ESQUECE DE DESALOGAR TUDOOOOOO
					arq = fopen("lista.txt","w");

					for(i=0;i<M;i++){
						pontaux = veta[i];
						poenoarquivo(pontaux);
					}
					fclose(arq);
					
					for(i=0;i<M;i++){
						pontaux = veta[i];
						libera(pontaux);
					}
					printf("Lista salva, programa encerrado\n");
					exit(0);
				default:
					printf("Escolha uma opcao valida\n");	
				}
			}
		}
	}
}
