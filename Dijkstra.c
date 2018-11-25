#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>


int FilaCount = 1;
int ondefila = 0;
int *f = NULL,*r = NULL; // Fila global


typedef struct Lista{
	int valor;
	int peso;
	struct Lista *prox;
}lista;

void InicializaArestas(int arestas,int vertices,lista vet[100]){

	int i=0,j=0,a1=0,a2=0,peso=0;
	lista *aux=NULL,*aux2=NULL,*l;

	for(i=0;i<arestas;i++){
		scanf("%d",&a1);
		if(a1 == 0){
			exit(0);
		}
		scanf("%d %d",&a2,&peso);
		a1--;
		a2--;
		aux = vet[a1].prox; // Trata o primeiro parametro da aresta
									//printf("Que isso\n");
		if(aux != NULL){ // Poe no final da lista
			while(aux->prox != NULL){
				aux = aux->prox;
			}
		}
		if(aux == NULL){ // Aloca mais uma posicao,e poe o valor
			l = malloc(sizeof(lista));
			vet[a1].prox = l;
			l->valor = a2+1;
			l->peso = peso;
			l->prox = NULL;
		}else{			
			l = malloc(sizeof(lista));

			l->valor = a2+1;
			l->peso = peso;
			l->prox = NULL;
			aux->prox = l;
		}		
		/*aux2 = vet[a2].prox;
		if(aux2 != NULL){
			while(aux2->prox != NULL){
			aux2 = aux2->prox;
			}
		}
		if(aux2 == NULL){
			l = malloc(sizeof(lista));
			vet[a2].prox = l;
			l->valor = a1+1;
			l->peso = peso;
			l->prox = NULL;
		}else{
			l = malloc(sizeof(lista));
			aux2->prox = l;
			l->valor = a1+1;
			l->peso = peso;
			l->prox = NULL;


		}
		*/
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
				printf("%d (%d) -> ",aux->valor,aux->peso);
				aux = aux->prox;
						}
			printf("%d (%d) ->",aux->valor,aux->peso);
			printf("NULL\n");
		}


	}
}



void Relax(int atual,int vertices,int valor[vertices],int d[vertices],int pi[vertices],lista vet[100],int fila[vertices],int distancia[vertices]){
	
	//O vetor d verifica se o vértice já foi enfilado
	int i=0,v,relaxado[vertices],auxinicio; // Auxinicio é o ponteiro que fica no inicio da lista;
	lista *aux;
	aux = &vet[atual];
	//aux = aux->prox;
	auxinicio = distancia[aux->valor-1];
	while(aux->prox != NULL){
		aux = aux->prox;
		//	printf("DISTANCIA DE 1  = %d\n",distancia[0]);
		//printf("AUX->VALOR = %d\n",aux->valor);
		//printf("distancia[%d] = %d *aux inicio = %d aux->peso = %d, distancia[valor+1] = %d\n",aux->valor-1,distancia[aux->valor-1],auxinicio,aux->peso,distancia[aux->valor-1]);
		//printf("Distancia[%d] = %d e Distancia[%d] = %d\n",aux->valor,distancia[aux->valor],atual,distancia[atual]);
		//printf("AUX->PESO = %d, distanciaAtual[%d] = %d, aux->valor = %d\n",aux->peso,atual,distancia[atual],aux->valor);

		  auxinicio = distancia[atual] + aux->peso;
		 // distancia[atual+1] = *auxinicio;
		//printf("distancia[%d] antes = %d *auxinicio = %d aux->peso = %d, distancia[%d] = %d\n",aux->valor-1,distancia[aux->valor-1],auxinicio,aux->peso,atual+1,distancia[aux->valor-1]);
	
		//printf("d[%d] = %d\n",aux->valor-1,d[aux->valor-1]);
		if(distancia[aux->valor-1] > auxinicio){  // Caso a soma seja menor que o vetor que já está lá
			pi[aux->valor-1] = aux->valor-1;		// -1 porque o vetice 2 está na posição 1 do vetor.
			distancia[aux->valor-1] = auxinicio;
		}
		if(distancia[aux->valor-1] != INT_MAX && d[aux->valor-1] == 0){
			fila[FilaCount] = aux->valor;
			FilaCount++;
			d[aux->valor-1] = 1;  // Para saber se ja foi enfilado
	   	}
		//printf("distancia[%d] depois = %d auxinicio = %d aux->peso = %d, distancia[%d] = %d, pi[%d] = %d\n",aux->valor-1,distancia[aux->valor-1],auxinicio,aux->peso,atual+1,distancia[aux->valor-1],aux->valor-1,atual+1);
		//printf(	"distanciaAtual[%d] = %d\n",atual,distancia[atual]);
	//aux = aux->prox;
	}
	if(aux != NULL){
		auxinicio = distancia[aux->valor];
		auxinicio =  aux->peso + distancia[atual];
	//	printf("AUX->PESO = %d, distanciaAtual[%d] = %d, aux->valor = %d, AuxInicio = %d\n",aux->peso,atual,distancia[atual],aux->valor,auxinicio);
		
		if(distancia[aux->valor-1] > auxinicio){  // Caso a soma seja menor que o vetor que já está lá
				pi[aux->valor-1] = aux->valor-1;		// -1 porque o vetice 2 está na posição 1 do vetor.
				distancia[aux->valor-1] = auxinicio;
		}
		//printf("d[%d] = %d\n",aux->valor-1,d[aux->valor-1]);
		if(distancia[aux->valor-1] != INT_MAX && d[aux->valor-1] == 0){
			fila[FilaCount] = aux->valor;
			FilaCount++;
			d[aux->valor-1] = 1;
		}
	}

	

  // 	printf("MINHA FILA ESTA:\n");
	//   	for(i=0;i<FilaCount;i++){
	  // 		printf("Fila[%d] = %d\n",i,fila[i]);
	   	//}
		//printf("distancia[%d] = %d *auxinicio = %d aux->peso = %d, distancia[%d] = %d, pi[%d] = %d\n",aux->valor-1,distancia[aux->valor-1],*auxinicio,aux->peso,aux->valor-1,distancia[aux->valor-1],aux->valor-1,atual+1);

	ondefila++;

}

int main(void){		
	
	int testes = 1;
	
		char c;
		int i=0,j=0,arestas=0,auxatual,vertices=0,k=0,count = 1,atual=0,peso=0,destino; // Count comeca com um porque o primeiro elemento nao tem pai
		lista vet[10001],*aux= NULL;
		aux = &vet[0];
		for(;;){

			scanf("%d %d",&vertices,&arestas);
			if(vertices == 0 && arestas == 0){
				return 0;	
			}
			int chave[arestas];
			int fila[vertices],distancia[vertices],d[vertices],pi[vertices],cor[vertices],valor[vertices]; //Cores : 0 branco, 1 cinza, 2 preto

			FilaCount = 1;
			ondefila = 0;
			for(i=0;i<100;i++){
				vet[i].valor = 0;	
			}

			for(i=0;i<vertices;i++){
				distancia[i] = INT_MAX;
				fila[i] = 0;
			}

			for(i=0;i<vertices;i++){
				vet[i].valor = i+1;
				vet[i].prox = NULL;
			}

			for(i=0;i<vertices;i++){
				d[i] = 0;
				pi[i] = 0;
				valor[i] = INT_MAX;
			}

			
			//MUITA ATENCAO NA REPRESENTACAO NO VETOR, A POSICAO [0] GUARDA O NO [1]
			InicializaArestas(arestas,vertices,vet);
			//printLista(vertices,vet);
			
			scanf("%d",&atual);
			scanf("%d",&destino);
			destino--;
			atual--;
			distancia[atual] = 0;

			auxatual = atual;  // Auxatual mantem o valor do no escolhi ate o final do programa
		  //  printf("Atual = %d\n",atual);
			d[atual] = 1; // Já foi enfilado
			//printf("\n PASSA \n");
			i = 0;
			while(vet[i].valor != 0){
				Relax(atual,vertices,valor,d,pi,vet,fila,distancia);
				if(fila[ondefila] == 0){
					break;
				}
				atual = fila[ondefila];
				atual--;
				//printf("Aux->prox = %d\n",aux->valor);
				//printf("Atual = %d \n",atual);
				i++;
			}
			//printf("Distancia de %d para os outros vertices\n",auxatual+1);
			//for(i=0;i<vertices;i++){
				//printf("distancia[%d] = %d\n",i,distancia[i]);
			//}
			if(distancia[destino] != INT_MAX){
				printf("%d\n", distancia[destino]);
			}else{
				printf("-1\n");
			}
		}

		

}