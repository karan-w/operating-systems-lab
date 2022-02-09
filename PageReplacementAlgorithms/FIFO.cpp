#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
	
class FIFO{

	public:
		vector <int> frames;
		int numberOfFrames;
		
		FIFO(int numberOfFrames){
			
			this->numberOfFrames = numberOfFrames;
		
		}

		void printQueue(){
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
				
					if(inQueue(*it)){
						continue;
					}else{
						frames[pos % numberOfFrames] = *it;
						pos++;	
						cout << "Page fault for " << *it << endl;
						pageFaults++;
					}
				}
				printQueue();
			}
			cout << "Page Faults - " << pageFaults << endl;
		}
		bool inQueue(int page){
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

	FIFO q(3);
	q.run();
	return 0;
}
