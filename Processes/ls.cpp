#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <iomanip>
#define GetCurrentDir getcwd

using namespace std;

int ls(int argc, char*argv[]){
	if(argc < 2){
		char currentPath[100] = "/proc\0";
		/*if(!GetCurrentDir(currentPath, sizeof(currentPath))){
			cout << "Could not get the working directory." << endl;
		}*/
		cout << currentPath << endl;
		DIR* presentDir = opendir(currentPath);
		dirent* dp;
		while((dp = readdir(presentDir)) != NULL){
			cout << dp->d_name << endl;
			//cout << setw(10) << std::left << dp->d_name;
		}
		cout << endl;
		closedir(presentDir);
	}else{
		DIR* presentDir = opendir(argv[1]);
		dirent* dp;
		while((dp = readdir(presentDir)) != NULL){
			cout << dp->d_name << endl;
		}
		closedir(presentDir);
	}
	return 1;
}

int main(int argc, char*argv[]){
	ls(argc, argv);
	return 0;	
}
