#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

class OPR{
	public:
		vector <int> frames;
		int numberOfFrames;

		OPR(int numberOfFrames){
	
			this->numberOfFrames = numberOfFrames;

		}
		
		void printFrames(){
			for(int i = 0; i < frames.size(); i++){
				cout << frames[i] << endl;
			}
		
		}
	
		void run(){
			vector <int> input;
			ifstream in("input.txt");
			if(!in.is_open()){

				cout << "Input file couldn't be opened.\n";
				return;

			}
			int page;
			in >> page;
			while(!in.eof()){
				input.push_back(page);
				in >> page;
			}
			/*
			vector <int>::iterator it;
			for(it = input.begin(); it != input.end(); it++){
				cout << *it << endl;
			}
			*/
			int pageFaults = 0;
			vector <int>::iterator it;
			int pos = 0;
			for(it = input.begin(); it != input.end(); it++){
				if(frames.size() < numberOfFrames){
					frames.push_back(*it);
					cout << "Page fault for " << *it << endl;
					pageFaults++;
				}else{
				
					if(alreadyAlloted(*it)){
						cout << *it << " is already alloted." << endl; 
						continue;
					}else{
						cout << "Page fault for " << *it << endl;
						pageFaults++;
						vector <int>::iterator iterators[numberOfFrames];
						vector <int> difference;
						for(int i = 0; i < numberOfFrames; i++){
							for(iterators[i] = it; iterators[i] != input.end(); iterators[i]++){
								if(*iterators[i] == frames[i]){
									break;
								}
							}
							difference.push_back(iterators[i] - it);
						}
						int max = -1, differenceIndex = -1;
						for(int i = 0; i < numberOfFrames; i++){
							if(difference[i] > max){
								max = difference[i];
								differenceIndex = i;
							}
						}
						int pageToBeReplaced = frames[differenceIndex];
						for(int i = 0; i < numberOfFrames; i++){
							if(frames[i] == pageToBeReplaced){
								frames[i] = *it;
								break;
							}
						}
					}
				}
				printFrames();
			}
			cout << "Page Faults - " << pageFaults << endl;
		}
		
		bool alreadyAlloted(int page){
			vector <int>::iterator it;
			for(it = this->frames.begin(); it != this->frames.end(); it++){
				if(*it == page){
					return true;
				}
			}
			return false;
		}
		

};

int main(){
	OPR o(3);
	o.run();

}
