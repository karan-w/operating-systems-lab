#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t childid = fork();
	if(childid > 0){
		sleep(50);
	}
	else{
		exit(0);
	}
	return 0;
}
