//Willian Pitter
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void main(){

	int i=0,pdi = 0,a,j,a1=0,a2=0,i2  = 0 ;
	FILE *b,*b2 = NULL;
	int vet[100],vet2[100],*ponteiro = NULL;
	b = fopen("buffer.txt","r");
	for(i=0;i<10;i++){
		fscanf(b,"%d",&vet[i]);
	}
	ponteiro = &a1;
	fclose(b);
	pdi = fork();

	if(pdi == 0){ // O produtor eh o filho
	for(;;){	
		srand(time(NULL));
		for(;;){
				
				if(*ponteiro == 0){
					a1 = 1;
					b2 = fopen("buffer.txt.lock","w");

					b = fopen("buffer.txt","a");
							if(b == NULL){
								printf("Falha ao abrir aquivo\n");
							}
							while(fscanf(b,"%d",&vet[i]) == 1){
								i++;
							}
						a = rand()%3 + 1;
						sleep(a);
						a = rand()%100;
						vet[i] = a;
						fclose(b);
						b = fopen("buffer.txt","w");
						printf("Na hora de produzir, o ponteiro b2 aponta par %p\n",b2);
			
						for(j=0;j<i+1;j++){
								fprintf(b,"%d\n",vet[j]);
						}
						printf("Produtor produziu o numero %d\n",a);
						fclose(b);
						fclose(b2);
						b2 = NULL;
						break;
					
				}else{
					for(;;){
						if(*ponteiro == 0){
							break;
						}else{
							printf("Congestionado,processo filho usando\n");
							usleep(50000);
						}
					}
				}
			a1 = 0;
			usleep(5000);
			}

		}
	}else{
	for(;;){	
		srand(time(NULL));

			usleep(5000);
			printf("O ponteiro b2 aponta para %p\n",b2);
			if(*ponteiro == 0){
				a1 = 1;
				b2 = fopen("buffer.txt.lock","w");
				if(b == NULL){
				printf("Falha ao abrir aquivo\n");
				}

				b = fopen("buffer.txt","r");
				while(fscanf(b,"%d",&vet[i2]) == 1){
					i2++;
				}
				fclose(b);
					a = rand()%3 + 1;
					sleep(a);
						b = fopen("buffer.txt","w");
						printf("Na hora de produzir, o ponteiro b2 aponta para %p\n",b2);
						for(j=1;j<i2;j++){
							fprintf(b,"%d\n",vet[j]);
						}
						printf("Consumidor consumiu o numero %d\n",vet[0]);
					i2 = 0;
					fclose(b);
					fclose(b2);
					b2 = NULL;
			}else{
				for(;;){
					printf("Entra auqi??\n");
					if(*ponteiro == 0){
						break;
					}else{
						printf("Congestionado,processo pai usando\n");
						usleep(50000);
					}
				}
			}
		a1 = 0;	
		usleep(5000);
		}
			
	}
}
