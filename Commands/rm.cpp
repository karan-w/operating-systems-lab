#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

#define GetCurrentDir getcwd

using namespace std;

void recursivelyDeleteDirectory(char* directoryName){
	cout << "Folder " << directoryName << endl;
	DIR* presentDir = opendir(directoryName);
	dirent* dp;
	while((dp = readdir(presentDir)) != NULL){
		if(remove(dp->d_name) != 0){
			//recursivelyDeleteDirectory(directoryName + "/" + dp->name);
		}else{
			cout << dp->d_name;
			cout << " successfully deleted." << endl;
		}
	}
	cout << endl;
	closedir(presentDir);	
}

int rm (int argc, char* argv[]){

	if(argc == 1){
		cout << "Error - No filename given to delete." << endl;
		return 0;
	}else{
		if(argv[1] == "-r"){
			
		}
		for(int i = 1; i < argc; i++){
			if(remove(argv[i]) != 0){
				cout << " couldn't be deleted." << endl;
				cout << "Is it a non empty folder? [y/N]" << endl;
				string response;
				cin >> response;
				if(response == "y"){
					char currentPath[100];
					if(!GetCurrentDir(currentPath, sizeof(currentPath))){
						cout << "Could not get the working directory." << endl;
					}
					c
					//recursivelyDeleteDirectory(currentPath + "/" + argv[i]);	
				}else if (response == "N"){
					cout << "Sorry, there seems to be some error." << endl;
				}
			}else{
				cout << argv[i];
				cout << " successfully deleted." << endl;
			}
		}
	
	}
	return 1;
}

int main(int argc, char* argv[]){

	rm(argc, argv);
	
	return 0;
}
