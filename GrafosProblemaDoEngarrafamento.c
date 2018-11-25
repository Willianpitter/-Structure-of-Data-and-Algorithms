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

void InicializaArestas(int arestas,int vertices,lista vet[99999]){

	int i=0,a1=0,a2=0,peso=0;
	lista *aux=NULL,*l;

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
	}
}


void Relax(int atual,int vertices,int valor[vertices],int d[vertices],int pi[vertices],lista vet[99999],int fila[vertices],int distancia[vertices]){
	
	//O vetor d verifica se o vértice já foi enfilado
	int auxinicio; // Auxinicio é o ponteiro que fica no inicio da lista;
	lista *aux;
	aux = &vet[atual];
	auxinicio = distancia[aux->valor-1];
	while(aux->prox != NULL){
		aux = aux->prox;
		  auxinicio = distancia[atual] + aux->peso;
		if(distancia[aux->valor-1] > auxinicio){  // Caso a soma seja menor que o vetor que já está lá
			pi[aux->valor-1] = atual+1;		// -1 porque o vetice 2 está na posição 1 do vetor.
			distancia[aux->valor-1] = auxinicio;
		}
		if(distancia[aux->valor-1] != INT_MAX && d[aux->valor-1] == 0){
			fila[FilaCount] = aux->valor;
			FilaCount++;
			d[aux->valor-1] = 1;  // Para saber se ja foi enfilado
	   	}
	
	}
	if(aux != NULL){
		auxinicio = distancia[aux->valor];
		auxinicio =  aux->peso + distancia[atual];
		
		if(distancia[aux->valor-1] > auxinicio){  // Caso a soma seja menor que o vetor que já está lá
				pi[aux->valor-1] = atual+1;		// -1 porque o vetice 2 está na posição 1 do vetor.
				distancia[aux->valor-1] = auxinicio;
		}
		if(distancia[aux->valor-1] != INT_MAX && d[aux->valor-1] == 0){
			fila[FilaCount] = aux->valor;
			FilaCount++;
			d[aux->valor-1] = 1;
		}
	}


	ondefila++;

}

int main(void){		
	
	
		int i=0,j=0,arestas=0,atualfixo=0,destinofixo=0,vertices=0,atual=0,destino=0; // Count comeca com um porque o primeiro elemento nao tem pai
		lista vet[99999];
		for(;;){

			scanf("%d %d",&vertices,&arestas);
			if(vertices == 0 && arestas == 0){
				return 0;	
			}
			int fila[vertices],distancia[vertices],d[vertices],pi[vertices],valor[vertices]; //Cores : 0 branco, 1 cinza, 2 preto

			FilaCount = 1;
			ondefila = 0;
			for(i=0;i<1001;i++){
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
			
			scanf("%d",&atual);
			scanf("%d",&destino);
			destino--;
			atual--;
			destinofixo = destino;
			atualfixo = atual;
			distancia[atual] = 0;
		for(j=0;j<4;j++){
			atual = atualfixo;
			destino = destinofixo;

			d[atual] = 1; // Já foi enfilado
			i = 0;
			while(vet[i].valor != 0){
				Relax(atual,vertices,valor,d,pi,vet,fila,distancia);
				if(fila[ondefila] == 0){
					break;
				}
				atual = fila[ondefila];
				atual--;
				i++;		
			}

			FilaCount = 1;
			ondefila = 0;
		}
		 if(distancia[destino] != INT_MAX){
				printf("%d\n", distancia[destino]);
			}else{
				printf("-1\n");
			}
	}

}