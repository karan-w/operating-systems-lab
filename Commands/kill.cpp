#include <iostream>
#include <fstream>
#include <string.h>
#include <signal.h>
#include <string.h>
#include <cstdlib>
using namespace std;

void killProcess (int argc, char* argv[]){
	int signal = 0; //SIGKILL
	if(argc == 1){
		cout << "Please provide the process ID of the process you want to kill." << endl;
		return;
	}
	for(int i = 1; i < argc; i++){
		kill(atoi(argv[i]), SIGKILL);				
	}

}

int main(int argc, char* argv[]){

	killProcess(argc, argv);
	
	return 0;
}
