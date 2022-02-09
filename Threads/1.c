#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


#define NUM_THREADS 3

int maximum = -9999, minimum = 99999;
float average = 0;

void * average_runner(void *arg){
	char ** arguments = (char **) arg;  
	int n = atoi(arguments[1]);
	int i;
	for(i = n + 1; i > 1; i--){
		average += atoi(arguments[i]);
	}
	average /= atoi(arguments[1]);
	pthread_exit(0);
}
void * minimum_runner(void *arg){
	char ** arguments = (char **) arg;  
	int n = atoi(arguments[1]);
	int i;
	for(i = n + 1; i > 1; i--){
		if(atoi(arguments[i]) < minimum){
			minimum = atoi(arguments[i]);
		}
	}

	pthread_exit(0);
}

void * maximum_runner(void *arg){
	char ** arguments = (char **) arg;  
	int n = atoi(arguments[1]);
	int i;
	for(i = n + 1; i > 1; i--){
		if(atoi(arguments[i]) > maximum){
			maximum = atoi(arguments[i]);
		}
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
	pthread_t WORKERS[NUM_THREADS];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&WORKERS[0], &attr, average_runner, argv);
	pthread_create(&WORKERS[1], &attr, minimum_runner, argv);
	pthread_create(&WORKERS[2], &attr, maximum_runner, argv);
	int i;
	for(i = 0; i < NUM_THREADS; i++){
		pthread_join(WORKERS[i], NULL);
	}
	printf("Maximum: %d \n",maximum);
	printf("Average: %f \n", average);
	printf("Minimum: %d \n", minimum);
	return 0;
}
