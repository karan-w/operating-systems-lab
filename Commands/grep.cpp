#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//Returns 1 if pattern is in the string, else 0
bool checkPattern(string pattern, string buffer){
	if(buffer.find(pattern) != string::npos){
		return 1;
	}
	return 0;
}

void grep(int argc, char* argv[]){
	if(argc == 1){
		cout << "Please enter a pattern." << endl;
		return;
	}
	else if(argc == 2){
	//Pattern given but no file
		string pattern(argv[1]);
	 	string buffer;
	 	while(cin >> buffer){
	 		if(checkPattern(pattern, buffer)){
	 			cout << buffer << endl;
	 		}
	 	}
	}
	else if(argc == 3){
	//Pattern and file given
		ifstream in;
		in.open(argv[2] ,ios::in);
		string pattern(argv[1]);
	 	string buffer;
		while(getline(in, buffer) != NULL){
			if(checkPattern(pattern, buffer)){
	 			cout << buffer << endl;
	 		}
		}
	}
	return;
}

int main(int argc, char*argv[]){
	grep(argc, argv);
	return 0;
	
}
