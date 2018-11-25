//Willian Pitter Cardoso Lima
#include<stdlib.h>
#include<stdio.h>

int quicksort(char *vet, int e,int d){
	int pivo,i,j;
	char aux,piv;

	i = e;
	j = d;
	pivo = (int) rand() % (i+j); // Pivo elegido aleatoriamente
	piv = vet[pivo];
	while(i<=j){
		while(vet[i] < piv){
			i++;
		}
		while(vet[j] > piv){
			j--;
		}
		if(i<=j){
			aux=vet[i];
			vet[i] = vet[j];
			vet[j] = aux;			
			i++;
			j--;

		}
	}
		if(e<j){
			quicksort(vet,e,j);
		}
		if(i<d){
			quicksort(vet,i,d);
		}
}



void main(){

	int i,j,e=0,d,n;
	

	printf("Digite qual o tamanho da string\n");
	scanf("%d",&n);
	char vet[n];
	d = n-1; 
	printf("Digite a string\n");
	scanf("%s",vet);
	if(n==1){
		printf("%s\n",vet);
		exit(0);
	}

	
	quicksort(vet,e,d);

	for(i=0;i<n;i++){
		printf("%c",vet[i]);	

	}
	printf("\n");
}
