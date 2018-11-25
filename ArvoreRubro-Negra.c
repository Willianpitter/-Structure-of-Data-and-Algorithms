#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore{
	struct arvore *le;
	struct arvore *ld;
	struct arvore *pai;
	char palavra[20];
	int idade;
	char cor[6];
}arvore;

void inordem(arvore *p){
	if(p!=NULL){
		inordem(p->ld);
		if(strcmp(p->cor,"black")){
			printf("\33[31m%d\033[0m\n",p->idade);
		}else{
			printf("%d\n",p->idade);
		}
		inordem(p->le);


	}
}
typedef struct Lista{
	arvore *enfilaavore;
	struct Lista *prox;
}lista; 

arvore* Verificaraiz(arvore *p){
	if(p != NULL){
		if(p->pai == NULL){
			printf("A nova raiz seria %d\n",p->idade);
			return p;
	}
			Verificaraiz(p->pai);

}




}

void emnivel(arvore *T){
	arvore *auxv;
	lista *aux,*cab,*aux3,*l,*aux2,*alturainicio,*alturafinal;
	int i = 0,altura=0,j=0,k=0,nos=1,nosaux = 0 ;
	auxv = T;
	// A raiz vira a cabeca da lista
	l = (lista*)malloc(sizeof(lista));
	l->enfilaavore = T;
	aux = l;
	cab = l;
	aux2 = cab;
	printf("h=%d: ",i);
	printf("%d\n",l->enfilaavore->idade);
	i++;

	while(l != NULL){
		altura = 1;
		for(j=0;j<i;j++){
			altura = 2*altura;
		}

		// Pega o no da esquerda
		for(j=1;j<altura;j++){		
			//printf("Endereco de T : %p\n",T);
			if(T != NULL){
				printf("Ta coisando o da esquerda de %d\n",T->idade);
				//printf("O coisado foi %d\n",T->le->idade);
				l = (lista*)malloc(sizeof(lista));
				l->enfilaavore = T->le;
				aux->prox = l;
				aux = l;
				printf("Endereco %p\n",l->enfilaavore);
				//printf("Adicionado na lista : %d\n",l->enfilaavore->idade);
			// Pega o no da direita
			}else{
				printf("Ta coisando o da esquerda, mas eh NULL\n");
				l = (lista*)malloc(sizeof(lista));
				l->enfilaavore = NULL;
				aux->prox = l;
				aux = l;
			}
			if(T != NULL){
				printf("Ta coisando o da direita\n");
				l = (lista*)malloc(sizeof(lista));
				l->enfilaavore = T->ld;
				aux->prox = l;
				aux = l;
				printf("Endereco %p\n",l->enfilaavore);
			}else{
								printf("Ta coisando o da direita, mas eh NULL\n");

				l = (lista*)malloc(sizeof(lista));
				l->enfilaavore = NULL;
				aux->prox = l;
				aux = l;
			}
						//printf("Adicionado na lista : %d\n",l->enfilaavore->idade);
			//printf("T atual = %d, T.prox = %d\n",T->idade,aux2->prox->enfilaavore->idade);
			T = aux2->prox->enfilaavore;
			aux2 = aux2->prox;

		}	
	cab = cab->prox;
	aux2 = cab;
	T = cab->enfilaavore;
	//printf("O cabeca eh %d\n",cab->enfilaavore->idade);

	//printf("Antigo cabeca %d\n",cab->enfilaavore->idade);
	aux3 = cab;
	aux = cab;
	//printf("Novo cabeca eh %d\n",cab->enfilaavore->idade);
	printf("Lista completa\n");
	k = altura;
	while(k != 0){
		printf("%p \n",aux3->enfilaavore);
		alturafinal = aux3;
		if(aux3 != NULL){
				printf("Endereco de aux3 : %p\n",aux3->enfilaavore);

			aux3 = aux3->prox;
		}
		k--;
	}
	//alturafinal = alturafinal->prox;
	nos = 1;
	for(j=1;j<i+1;j++){
		nos = nos*2;
	}
	nosaux = nos;
		printf("A variavel no no final eh %d\n",nos);

	//printf("Alturafinal = %p\n",alturafinal->enfilaavore->idade);
	while(aux != alturafinal){
		if(aux->enfilaavore == NULL){
				printf("ONDE TA ISSO?\n");

			nos = nos - 1;
		}
		aux = aux->prox;
	}
			printf("Ta aqui??\n");

	if(alturafinal->enfilaavore == NULL){ // Se a folha for null
		nos--;

	}
	printf("A variavel no no final eh %d\n",nos);

	if(nos == 0){
		exit(0);
	}
	nos = nosaux;
	//alturafinal = cab;
	//				printf("Ta aqui??\n");
	
	//aux = aux3;
	aux = cab;

	printf("h=%d: ",i);

	//printf("Aux = %d e Alturafinal = %d\n",aux->enfilaavore->idade,alturafinal->enfilaavore->idade);

	while(aux != alturafinal){
		if(aux->enfilaavore == NULL){
			printf(" []");
			aux = aux->prox;
		}else if(strcmp(aux->enfilaavore->cor,"red") == 0){
			printf(" \33[31m%d\033[0m",aux->enfilaavore->idade);
			aux= aux->prox;
		}else{
			printf(" %d",aux->enfilaavore->idade);
			aux = aux->prox;

		}
	}
	//printf("Altura final = %d\n",alturafinal->enfilaavore->idade);
	if(alturafinal->enfilaavore == NULL){
			printf(" []");
	}else if(strcmp(alturafinal->enfilaavore->cor,"red") == 0){
			printf(" \33[31m%d\033[0m",alturafinal->enfilaavore->idade);
		}else{
			printf(" %d",alturafinal->enfilaavore->idade);

	}
	cab = alturafinal;
	aux = cab;
	printf("\n");
	i++;
}
}

void RR(arvore *no){
	arvore *aux;
	
	aux = no->le;
	aux->le->pai = no;
	no->le = aux->ld;
	aux->ld = no;
	aux->pai = no->pai;
	if(no->pai != NULL){ // Se o no for raiz, deixa de comparar o ld de null
		no->pai->le = aux;
	}
													printf("Dando aqui RR\n");

	no->pai = aux;
	no = aux; 
	no->le->pai = no;
	no->ld->pai = no;
	printf("O pai dos dois eh %d , filho da esqueda eh %d %s, filho da direita eh %d,Pai do da esquerda eh %d %s\n",no->idade,no->le->idade,no->le->cor,no->ld->idade,no->le->pai->idade,no->le->cor);


}
/*v o i d LL ( noAVL ∗d ) {
noAVL ∗au x .
au x = d− >d i r ;
aux− >e sq− >p a i = d ;
d− >d i r = aux− >e s q ;
aux− >e s q = d ;
aux− >p a i = d− >p a i ;
d− >p a i = au x ;
d = au x ;
}*/
void LL(arvore *no){ // Caso o pai seja vermelho e o tio seja preto
	arvore *aux;

	aux = no->ld;
	//printf("%d le = %p\n",aux->idade,aux->le);
	aux->ld->pai = no;
	no->ld = aux->le;
	aux->le = no;
	//printf("Aux->le = %p\n",aux->le->ld);
	aux->pai = no->pai;
	if(no->pai != NULL){ // Se o no for raiz, deixa de comparar o ld de null
		no->pai->ld = aux;
	}
	no->pai = aux;
	no = aux;
	no->le->pai = no;
	no->ld->pai = no;
	//printf("Rodou pra esqueda\n");
	printf("O pai dos dois eh %d , filho da esqueda eh %d %s, filho da direita eh %d %s\n",no->idade,no->le->idade,no->le->cor,no->ld->idade,no->ld->cor);
}
void LR(arvore *no){
	arvore *aux;

	aux = no->ld;
	aux->le->pai = no;
	no->ld = aux->le;
	aux->le->ld = aux;


			printf("Onde ta essa porra\n");

	aux->pai = no->ld;
	aux->le = aux->le->le;

	printf("O pai dos dois eh %d , filho eh %d %s, Neto eh %d\n",no->idade,no->ld->idade,no->ld->cor,no->ld->ld->idade);

	LL(no);

}

void RL(arvore *no){
	arvore *aux;

	aux = no->le;
	aux->ld->pai = no;
	no->le = aux->ld;

	aux->ld->le = aux;
	aux->pai = no->le;
			printf("Bora achar\n");

	aux->ld = aux->ld->ld;
	printf("O pai dos dois eh %d , filho eh %d %s, Neto eh %d\n, Pai do %d eh %d - %s E o pai do %d eh %d\n" ,no->idade,no->le->idade,no->le->cor,no->le->le->idade,no->le->idade,no->le->pai->idade,no->le->pai->cor,no->le->le->idade,no->le->le->pai->idade);

	RR(no);

}

void redred(arvore *pai,arvore *tio,arvore *avo){ // Pai vermelhor e tio vermelho
	printf("Chega aqui\n");
	strcpy(pai->cor,"black");
	strcpy(tio->cor,"black");
	strcpy(avo->cor,"red");
	printf("%d agora eh preto, %d agora eh preto, %d agora eh vermelho\n",pai->idade,tio->idade,avo->idade);
}

int casos(arvore *filho,int *nos,arvore *raiz){
	printf("filho eh %d = %s e o pai eh %d = %s\n",filho->idade,filho->cor,filho->pai->idade,filho->pai->cor);
	printf("Era pra entrar aqui\n");
	if (strcmp(filho->cor,"black") == 0 && strcmp(filho->pai->cor,"red") == 0 ){
		printf("Por que n entrou?\n");
		return 0;
	}
	if(filho->pai != raiz){ // Para de comparar quando o pai eh raiz para nao acessar ponteiro invalido (o pai da raiz)

		if(*nos >= 4){ // Teste do caso de pai vermelho e tio vermelho


			if(filho->pai->pai->ld != NULL && filho->pai->pai->le != NULL){
				if(filho->pai->idade == filho->pai->pai->le->idade){
					if(strcmp(filho->pai->cor,"red") == 0 && strcmp(filho->pai->pai->ld->cor,"red") == 0){ //Caso de pai vermelho e tio vermelho
						redred(filho->pai,filho->pai->pai->ld,filho->pai->pai);
						return 0;
					}

				}else if(filho->pai->idade == filho->pai->pai->ld->idade){ // Verifica se esta comparando nos diferentes
				 	if(strcmp(filho->pai->cor,"red") == 0 && strcmp(filho->pai->pai->le->cor,"red") == 0 ){ // Caso de pai vermelho e tio vermelhor
						redred(filho->pai,filho->pai->pai->le,filho->pai->pai); 
						return 0;
					}
				}
			}
			
		}
	// Casos das rotacoies
		if(*nos >= 3){
			if(filho->pai->pai->ld == NULL || filho->pai->idade == filho->pai->pai->ld->idade){
				if(strcmp(filho->pai->cor,"red") == 0){					//printf("O tio eh %s\n",filho->pai->pai->ld->cor);
					if(filho->pai->pai->le == NULL || strcmp(filho->pai->pai->le->cor,"black") == 0){
						if(filho->pai->pai->ld != NULL && filho->pai->pai->ld->idade == filho->pai->idade){ // Pai do lado direito do avo
							if(filho->pai->ld != NULL && filho->pai->ld->idade == filho->idade){ // Filho no lado direito do pai
								strcpy(filho->pai->pai->cor,"red");
								//printf("%d agora eh %s",filho->pai->pai->idade,filho->pai->pai->cor);
								printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->pai->idade,filho->pai->pai->cor,filho->pai->pai->le,filho->pai->pai->ld);
								strcpy(filho->pai->cor,"black");
								printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->idade,filho->pai->cor,filho->pai->le,filho->pai->ld);
								LL(filho->pai->pai); // Os nos estao direito-direita, entao 
								return 0;							
							}
						 if(filho->pai->le != NULL && filho->pai->le->idade == filho->idade){ // Pai do lado esquerdo do avo
								strcpy(filho->pai->pai->cor,"red");
								//printf("%d agora eh %s",filho->pai->pai->idade,filho->pai->pai->cor);
								printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->pai->idade,filho->pai->pai->cor,filho->pai->pai->le,filho->pai->pai->ld);
								strcpy(filho->cor,"black");
								printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->idade,filho->pai->cor,filho->pai->le,filho->pai->ld);
								LR(filho->pai->pai);
								return 0;				

							}
						}	
					}
				
				}
			}

			if(filho->pai->pai->le == NULL || filho->pai->idade == filho->pai->pai->le->idade){
				if(strcmp(filho->pai->cor,"red") == 0){
					if(filho->pai->pai->ld == NULL || strcmp(filho->pai->pai->ld->cor,"black") == 0){
						if(filho->pai->pai->le != NULL && filho->pai->pai->le->idade == filho->pai->idade){ // Pai do lado esquerdi do avo
							if(filho->pai->le != NULL && filho->pai->le->idade == filho->idade){ // Filho no lado esquerdo do pai
								strcpy(filho->pai->pai->cor,"red");
								//printf("%d agora eh %s",filho->pai->pai->idade,filho->pai->pai->cor);
								printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->pai->idade,filho->pai->pai->cor,filho->pai->pai->le,filho->pai->pai->ld);
								strcpy(filho->pai->cor,"black");
								printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->idade,filho->pai->cor,filho->pai->le,filho->pai->ld);

								RR(filho->pai->pai); // Os nos estao direito-direita, entao 
								return 0;
							}

							if(filho->pai->ld != NULL && filho->pai->ld->idade == filho->idade){// Filho do lado direito do pai
								strcpy(filho->pai->pai->cor,"red");

								printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->pai->idade,filho->pai->pai->cor,filho->pai->pai->ld,filho->pai->pai->le);
								strcpy(filho->cor,"black");

									printf("Mudando %d , %s , le = %p, ld = %p\n", filho->pai->idade,filho->pai->cor,filho->pai->ld,filho->pai->le);

																										printf("Vem aqui essa porra?\n");

								RL(filho->pai->pai);
								return 0;

							}
						}
					}
				}
			}
		}
	}
}


arvore* adicionar(char nome[40],int idade,arvore *T){

	arvore *raiz=NULL,*point=NULL,*aux=NULL;
			
			aux = T;
			point = (arvore *)malloc(sizeof(arvore));
			strcpy(point->palavra,nome);
			strcpy(point->cor,"red"); // Cria um novo no vermelho
			point->idade = idade;
			point->pai = NULL;
			point->ld = NULL;
			point->le = NULL;
			for(;;){
				if(point->idade > aux->idade){
					if(aux->ld == NULL){
						point->pai = aux;
						aux->ld = point;
						return point;

					}else{
						aux = aux->ld;
					}
				}else{
					if(aux->le == NULL){
						point->pai = aux;
						aux->le = point;
						return point;

					}else{
						aux = aux->le;
					}
				}
			}
}

void main() {
//Printar vermelho printf("\33[31mHello, world!\033[0m");
	int i=0,j=0,k=0,idade=0,nos = 0,auxint=0;
	char c;
	char nome[40],numero[20],nomepessoa[20];
	arvore *T = NULL,*raiz = NULL,*pontaux = NULL,*raizaux = NULL;
	lista *l;
	printf("Digite a idade nome\n");
	gets(nome);
	if (strcmp(nome,"0")== 0){
		printf("h=0: []\n");
		exit(0);
	}
	//Separa o numero da string
	while(c != ' '){
		c = nome[i];
		numero[i] = nome[i];
		i++;	
	}
	idade = atoi(numero);
	j = 0;
	while(c != '\0'){
		c = nome[i];

		nomepessoa[j] = nome[i];
		j++;
		i++;
	}
	//Separa o numero da string (codigo a cima)
	// Aloca a raiz da arvore		
		T = (arvore *)malloc(sizeof(arvore));
		raiz = T;
		pontaux = raiz;
		strcpy(raiz->palavra,nome);
		strcpy(raiz->cor,"black"); //Cria uma raiz preta
		raiz->pai == NULL;
		raiz->idade = idade;
		nos = 1;
		raiz->ld = NULL;
		raiz->le = NULL;
	//Por na arvore
	i = 0;
	j = 0;
	/*gets(nome);
	while(c != ' '){
		c = nome[i];
		numero[i] = nome[i];
		i++;	
	}
	while(c != '\0'){
		c = nome[i];
		nomepessoa[j] = nome[i];
		j++;
		i++;
	}
	idade = atoi(numero);*/
	while(idade != 0){
		printf("Proximo\n");
		gets(nome);
		i = 0;
		j = 0;
		while(c != ' '){
			c = nome[i];
			numero[i] = nome[i];
			i++;	
		}
		while(c != '\0'){
			c = nome[i];
			nomepessoa[j] = nome[i];
			j++;
			i++;
		}
		idade = atoi(numero);
		if(idade == 0){
			break;
		}
		pontaux = adicionar(nome,idade,T);
		nos++;
		while(pontaux != raiz){
			auxint = casos(pontaux,&nos,raiz);
			printf("Aqui?\n");
			raiz = Verificaraiz(pontaux);
			strcpy(raiz->cor,"black");
						printf("pont = %d , raiz = %d",pontaux->idade,raiz->idade);

			printf("Raiz %d eh %s\n",raiz->idade,raiz->cor);
			if(pontaux != raiz){
				pontaux = pontaux->pai;
			}
			T = raiz;
		}
		if(idade == 0){
			break;	
		}
	}	
	//inordem(raiz);
	emnivel(raiz);
	//nordem(pontaux,&nos); //Conta os nos da arvore

}

