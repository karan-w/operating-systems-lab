#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int wc (int argc, char* argv[]){
	string buffer;
	int spaces = 0, newlines = 0, words = 0, chars = 0;
	int tspaces = 0, tnewlines = 0, twords = 0, tchars = 0;
	char prev = ' ';
	if(argc == 1){
		while(getline(cin, buffer)){
			spaces = 0, newlines = 0, words = 0, chars = buffer.length();
			prev = ' ';
			buffer.push_back(' ');
			for(string::iterator it = buffer.begin(); it != buffer.end(); it++){

				if(*it == ' ' || *it == '\n'){
					if(*it == ' ')
						spaces++;
					while(*(it + 1) == ' '){
						it++;
						spaces++;
					}
					if(prev != ' '){
						words++;
					}
				}else{
					prev = *it;
				}
			}
			spaces--;
			newlines++;
			cout << endl;
			cout << "Spaces : " << spaces << endl;
			cout << "Lines : " << newlines << endl;
			cout << "Words : " << words << endl;
			cout << "Chars : " << chars << endl;
			cout << endl;
	}
	}else{
		for(int i = 1; i < argc; i++){
			ifstream in;
			in.open(argv[i] ,ios::in);
			if(!in.is_open()){
				cout << "Couldn't open file " << argv[i] << endl;
				return -1;
			}else{
				cout << endl << "File - " << argv[i] << endl << endl;
			}
			while(getline(in, buffer) != NULL){
				spaces = 0, newlines = 0, words = 0, chars = buffer.length();
				prev = ' ';
				buffer.push_back(' ');
				cout << buffer << endl;
				for(string::iterator it = buffer.begin(); it != buffer.end(); it++){

					if(*it == ' ' || *it == '\n'){
						if(*it == ' ')
							spaces++;
						while(*(it + 1) == ' '){
							it++;
							spaces++;
						}
						if(prev != ' '){
							words++;
						}
					}else{
						prev = *it;
					}
				}
				spaces--;
				newlines++;
				cout << "Spaces : " << spaces << endl;
				cout << "Lines : " << newlines << endl;
				cout << "Words : " << words << endl;
				cout << "Chars : " << chars << endl;
				cout << endl;
				tspaces += spaces;
				tnewlines += newlines;
				twords += words;
				tchars += chars;
				}
			
			in.close();
		}
		cout << "TSpaces : " << tspaces << endl;
		cout << "TLines : " << tnewlines << endl;
		cout << "TWords : " << twords << endl;
		cout << "TChars : " << tchars << endl;
	}
	
	return 0;
}

int main(int argc, char* argv[]){
	return wc(argc, argv);
}
