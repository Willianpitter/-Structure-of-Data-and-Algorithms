#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <math.h>


typedef struct Lista{
	int valor;
	double peso;
	struct Lista *prox;
}lista;

void InicializaArestas(double cidadeX[1000], double cidadeY[1000],int cidades,lista vet[100]){

	int i=0,j=0;
	double x1=0,x2=0,y1=0,y2=0,peso=0,p1=0,p2=0,cordenada1=0,cordenada2=0;
	lista *aux=NULL,*aux2=NULL,*l;

	for(i=0;i<cidades;i++){
		for(j=0;j<cidades;j++){
			x1 = cidadeX[i];
			y1 = cidadeY[i];
			x2 = cidadeX[j];
			y2 = cidadeY[j];
			
			//printf("x1 = %lf , y1 = %lf , x2 = %lf, y2 = %lf\n",x1,y1,x2,y2);
			cordenada1 = x1 - x2;
			cordenada2 = y1 - y2;
			//printf("Coordenada1 = %lf Coordenada2 = %lf\n",cordenada1,cordenada2 );
			p1 = pow(cordenada1,2);// TIRA O MODULA PARA A RAIDICIACAO
			p2 = pow(cordenada2,2);
			//printf("P1 = %lf e P2 = %lf\n",p1,p2);
			p1 = p1 + p2;
			peso = sqrt(p1);
			//printf("PESO de veti[%d] = %lf , p1 = %lf , p2 =  %lf, cordenada1 = %lf , cordenada2 = %lf\n",i,peso,p1,p2,cordenada1,cordenada2);
			aux = vet[i].prox; // Trata o primeiro parametro da aresta
										//printf("Que isso\n");
			if(aux != NULL){ // Poe no final da lista
				while(aux->prox != NULL){
					aux = aux->prox;
				}
			}
			if(aux == NULL){  //Aloca mais uma posicao,e poe o valor
				if(i != j){
					l = malloc(sizeof(lista));
					vet[i].prox = l;
					l->valor = j+1;
					l->peso = peso;
					l->prox = NULL;
				}
			}else{			
				if(i != j){
					l = malloc(sizeof(lista));
					l->valor = j+1;
					l->peso = peso;
					l->prox = NULL;
					aux->prox = l;
				}
			}		
		/*	aux2 = vet[j].prox;
			if(aux2 != NULL){
				while(aux2->prox != NULL){
				aux2 = aux2->prox;
				}
			}
			if(aux2 == NULL){
				l = malloc(sizeof(lista));
				vet[j].prox = l;
				l->valor = i+1;
				l->peso = peso;
				l->prox = NULL;
				printf("PASSA POR AQUI QUANTAS VEZEs\n");
			}else{
				l = malloc(sizeof(lista));
				aux2->prox = l;
				l->valor = i+1;
				l->peso = peso;
				l->prox = NULL;


			}*/
		}
	}
}


void printLista(int vertices,lista vet[100]){

	int i=0,j=0;
	lista *aux = NULL;

	for(i=0;i<vertices;i++){
		printf("V[%d] -> ",vet[i].valor);
		if(vet[i].prox == NULL){
			printf("NULL\n");
		}else{
			aux = &vet[i];
			aux = aux->prox;
			while(aux->prox != NULL){
				printf("%d (%lf) -> ",aux->valor,aux->peso);
				aux = aux->prox;
						}
			printf("%d (%lf) ->",aux->valor,aux->peso);
			printf("NULL\n");
		}


	}
}
int *f = NULL,*r = NULL; // Fila global
int fila = 0;

int Extract_min(int vertices,lista vet[100],double chave[vertices],int Q[vertices],int pai[vertices],double d[vertices]){
	int i=0,j,possuidor,k=0;
	lista *aux = NULL;
	double min = INT_MAX;
	printf("Q[%d] = %d\n",fila,Q[fila]);
	k = Q[fila]-1;
	aux = &vet[k];
	aux = aux->prox;
	// POE AS ARESTAS ADJACENTES NO VETOR CHAVE
	while(aux->prox != NULL){
		printf("aux-> valor %d,aux-> peso = %lf , chave[%d]\n",aux->valor,aux->peso,aux->valor-1);
		printf("aux-> peso  = %lf < chave[%d] = %lf?\n",aux->peso,aux->valor-1,chave[aux->valor]);
		if(aux->peso < chave[aux->valor-1]){ // Confere se o caminho eh menor antes de modificar
			chave[aux->valor-1] = aux->peso;
		}
			aux = aux->prox;
			i++;

	}
	printf("aux-> valor %d,aux-> peso = %lf , chave[%d]\n",aux->valor,aux->peso,aux->valor-1);
	printf("aux-> peso  = %lf < chave[%d] = %lf?\n",aux->peso,aux->valor-1,chave[aux->valor]);
	if(aux->peso < chave[aux->valor-1]){
		chave[aux->valor-1] = aux->peso;
	}
	i++;
		printf("aux-> valor %d,aux-> peso = %lf , chave[%d]\n",aux->valor,aux->peso,aux->valor-1);

	//PEGA A ARESTA DE MENOR PESO DO VETOR CHAVE
		for(j=0;j<vertices;j++){
			if(chave[j] < min){
				printf("Pai[%d] = %d ,  chave[%d] = %lf \n",j,pai[j],j,chave[j] );
				if(pai[j] == 0){
					printf("AQUIIII\n");
					min = chave[j];
				}
			}
		}
	for(i=0;i<vertices;i++){
		printf("Chave[%d] = %lf\n",i,chave[i]);
	}
	i=0;
	printf("MIN = %lf\n",min);
	printf("Chave[%d] = %lf`	 e pai[%d] = %d \n",i,chave[i],i,pai[i]);
	for(i=0;i<vertices;i++){   // Ve a primira chave minima cujo vertice ainda nao esta na arvore
		if(chave[i] == min){ 
			if(pai[i] == 0){
				break;
			}

		}
	}
	printf("Chave selecionada Chave[%d]\n",i);
	fila++;
	Q[fila] = i+1;
	printf("O proximo enfilado foi Q[%d] = %d\n",fila,i+1);
	printf("d[%d] = %lf	\n",i,min);
	d[i] = min;
	return i;
}
	
int Prim(int vertices,int arestas, lista vet[100],double chave[vertices],double d[vertices]){
	int i,q,min,sair = 0;
	int Q[vertices+1],pai[vertices];

	Q[fila] = 1;// Comeca sempre pelo vertice 1

	for(i=0;i<vertices;i++){
		chave[i] = INT_MAX;
	}	
	for(i=0;i<vertices;i++){
		pai[i] = 0;
	}

	pai[0] = INT_MAX; // Deixa o pai de 1 como infito para que na comparacao de ver se vertice ja esta na arvore, funcione
	f = &Q[0];
	q = 1;
	while(*f != 0){ 
		min = Extract_min(vertices,vet,chave,Q,pai,d);
		pai[min] = (*f); // m - 1 porque o vet[0] contem o vertice de numero 1;
		for(i=0;i<vertices;i++){
			printf("Pai[%d] = %d\n",i,pai[i]);
		}
		for(i=0;i<vertices;i++){
			printf("Distancia[%d] = %lf\n",i,d[i]);
		}
	for(i=0;i<vertices;i++){
		if(pai[i] != 0){
			sair++;
		} 
	}
	if(sair == vertices){
		fila = 0;
		for(i=0;i<vertices;i++){
			pai[i] = 0;
		}
		return 0;
	}
	sair = 0;
	f = &Q[fila];
	printf("O que Q que vai agora eh %d\n",*f);
	}




}


void FazArestas(){
	
}

void CalculandoArestas(){

}



int main(void){
	
	
	int i=0,j=0,cidades,arestas=0,vertices=0,resposta = 0;
	double	k=0,count = 1,peso=0,cidadeX[1000],cidadeY[1000],x1=0, y1=0, max = 0; // Count comeca com um porque o primeiro elemento nao tem pai
	lista vet[1000],*aux= NULL;
		
	for(;;){
		scanf("%d", &vertices);
		//scanf("%d %d %d",&vertices,&arestas,&peso);
		if(vertices == 0){
			exit(0);
		}
		if(vertices != 1){
			printf("Cidades = %d\n",vertices);
			if(vertices == 0 && arestas == 0){
				return 0;	
			}
			double chave[vertices],d[vertices];
			int fila[vertices],pi[vertices],cor[vertices]; //Cores : 0 branco, 1 cinza, 2 preto

			for(i=0;i<vertices;i++){
				vet[i].valor = i+1;
				vet[i].prox = NULL;
			}
			for(i=0;i<vertices;i++){
				scanf("%lf %lf", &x1, &y1);
				cidadeX[i] = x1;
				cidadeY[i] = y1;
			}
			//MUITA ATENCAO NA REPRESENTACAO NO VETOR, A POSICAO [0] GUARDA O NO [1]
			InicializaArestas(cidadeX,cidadeY,vertices,vet);
			printLista(vertices,vet);
			resposta = Prim(vertices,arestas,vet,chave,d);
			printf("--------------------------------\n");
			max = 0;
			for(i=0;i<vertices;i++){
				printf("d[%d] = %lf , max = %lf\n",i,d[i],max );
				if(d[i] > max){
					max = d[i];
				}
			}
			printf("%.4lf\n",max);
			for(i=0;i<vertices;i++){
				d[i] = 0;
			}
		}else{
			scanf("%lf %lf",&x1,&y1);
			printf("0.0000\n");
		}
	}
		//printLista(vertices	,vet);

		
	

}