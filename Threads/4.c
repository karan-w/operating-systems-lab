#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int* a;

void * fibonacci_runner(void *arg){
	int n = *(int*)arg;
	printf("%d \n" , n);
	if(n == 1){
		a[0] = 0;
 	}else if(n == 2){
 		a[0] = 0;
 		a[1] = 1;
 	}else{
 		a[0] = 0;
 		a[1] = 1;
 		for(int i = 2; i < n; i++){
 			a[i] = a[i-1] + a[i-2];
 		}
 	}
 	pthread_exit(0);
}

int main(int argc, char* argv[]){
	if (argc < 2){
		fprintf(stderr, "Usage: %s number_of_fibonacci \n", argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t t;
	int i;
	a = malloc(n * sizeof(int));
	
	pthread_create(&t, &attr, fibonacci_runner, &n);
	
	pthread_join(t, NULL);
	
	for(i = 0; i < n; i++){
		printf("%d\n",a[i]);
	}
	
	return 0;
}
