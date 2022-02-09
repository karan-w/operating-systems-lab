
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

void * prime_runner(void *arg){
	int* n = (int *) arg;
	float square_root = sqrt(*n);  
	int prime = 1;
	int i;
	for(i = 2; i <= square_root; i++){
		if(*n % i == 0){
			prime = 0;
			break;
		}
	}
	if(prime){
		printf("Prime : %d\n", *n);
	}
	pthread_exit(0);
}

int main(int argc, char* argv[]){
	if (argc < 2){
		fprintf(stderr, "Usage: %s number_of_integers integer integer integer ...\n", argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);
	printf("%d \n" , n);
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t WORKERS[n+1];
	int i;
	int a[n+1];
	for(i = 0; i < n + 1; i++){
		a[i] = i;
	}
	for(i = 2; i <= n; i++){
		//printf("%d\n", a[i]);
		pthread_create(&WORKERS[i], &attr, prime_runner, &a[i]);
	}
	
	
	for(i = 0; i < n+1; i++){
		pthread_join(WORKERS[i], NULL);
	}
	
	return 0;
}
