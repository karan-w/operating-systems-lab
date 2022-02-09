#include <iostream>
#include <queue>
#include <fstream>
#include <climits>

using namespace std;
class Page{
	public: 
		int pageId; 
		int timeOfUse;
		
		Page(int p, int t){
			pageId = p;
			timeOfUse = t;
		}
		Page(int p){
			pageId = p;
			timeOfUse = -1;
		}
	

};
class LRU{
	public:
		vector <Page *> frames;
		vector <Page> pages;
		int numberOfFrames;

		LRU(int numberOfFrames){
	
			this->numberOfFrames = numberOfFrames;

		}
		
		void printFrames(){
			for(int i = 0; i < frames.size(); i++){
				cout << frames[i]->pageId << endl;
			}
		}
		void printPages(){
			for(int i = 0; i < pages.size(); i++){
				cout << pages[i].pageId << " " << pages[i].timeOfUse << endl;
				
			}
		}
		Page* updatePage(int pageId, int time){
			for(int i = 0; i < pages.size(); i++){
				if(pages[i].pageId == pageId){
					pages[i].timeOfUse = time;
					return &pages[i];
				}
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
				if(isNewPage(page)){
					Page p(page);
					pages.push_back(p);
				}
				input.push_back(page);
				in >> page;
			}
			vector <int>::iterator it;
			int pageFaults = 0, time = 0;
			for(it = input.begin(); it != input.end(); it++){
				time++;
				if(frames.size() < numberOfFrames){
					frames.push_back(updatePage(*it, time));
					cout << "Page fault for " << *it << endl;
					pageFaults++;
					printFrames();
				}else{
					if(alreadyAlloted(*it)){
						updatePage(*it, time);	
						cout << *it << " is already alloted." << endl; 
					}else{
						cout << "Page fault for " << *it << endl;
						pageFaults++;
						int minTime = INT_MAX, frameIndex = -1;
						for(int i = 0; i < numberOfFrames; i++){
							if(frames[i]->timeOfUse < minTime){
								minTime = frames[i]->timeOfUse;
								frameIndex = i;	
							}
						}
						frames[frameIndex] = updatePage(*it, time);
						printFrames();
					}
				}

			}
			cout << "Page Faults - " << pageFaults << endl;

		}
		bool alreadyAlloted(int p){
			for(int i = 0; i < frames.size(); i++){
				if(frames[i]->pageId == p){
					return true;
				}
			}
			return false;
		}
		bool isNewPage(int p){
			for(int i = 0; i < pages.size(); i++){
				if(pages[i].pageId == p){
					return false;
				}
			}
			return true;
		}

};

int main(){
	LRU o(3);
	o.run();

}
