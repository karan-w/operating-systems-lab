#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

string buffer;

int cat(int argc, char*argv[]){

	int fd, count;
	if(argc == 1){
		while(true){
			getline(cin, buffer);
	    	cout << buffer << endl;
	    }
	}
	for(int i = 1; i < argc; i++){
		ifstream in;
		if(strcmp(argv[i], "-") == 0){
	        while(getline(cin, buffer)){
				cout << buffer << endl;
	    	}
	    }
	    else{
	        in.open(argv[i], ios::in);
	        if(in.is_open()){
	        	while(getline(in, buffer)){
	        		cout << buffer << endl;
	        	}
	        }
	        else{
	        	cout << "Error: Opening file : " << argv[i] << endl;
	        }
	        in.close();
	    }
	
	}
	return 0;
}

int main(int argc, char *argv[]){
	return cat(argc, argv);
}

	


