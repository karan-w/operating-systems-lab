#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

class Process{
	public: 
		int processNumber;
		int cpuBurst;
		int type; 
		Process(int p, int c, int type){
			this->processNumber = p;
			this->cpuBurst = c;
			this->type = type;
		}
		bool operator < (const Process &p2) const{
			return (cpuBurst < p2.cpuBurst);
	
		}
};


class SJF{
	public: 
		int numberOfProcesses;
		vector <Process> processes;
		SJF(){
		/*
			cout << "How many processes have to be executed?" << endl;	
			cin >> numberOfProcesses;
			int cb = -1;
			for(int i = 0; i < numberOfProcesses; i++){
				cout << endl << "Enter the CPU burst for process " << i + 1 << endl;
				cin >> cb;
				Process p(i+1, cb);
				processes.push_back(p);
			}
			cout << endl;
		*/
		}
		void display(){
			for(int i = 0; i < numberOfProcesses; i++){
				cout << "Process " << processes[i].processNumber << " : " << processes[i].cpuBurst << endl; 
			}
		}
		void run(){
			
			sort(processes.begin(), processes.end());
		
		}
};


class MLQ{
	public: 
		int numberOfProcesses;
		vector < queue <Process> > queues;
		int types;
		vector <int> priorities;
		MLQ(){
			cout << "How many types of processes have to be executed?" << endl;
			cin >> types;
			int priority;
			for(int i = 0; i < types; i++){
				cout << "What's the priority of the queue of type " << i + 1 << "?" << endl;  
				cin >> priority;
				priorities.push_back(priority);
			}
			cout << "Priorities " << endl; 
			for(int i = 0; i < priorities.size(); i++){
				cout << "Type " << i + 1 << " - Priority  " << priorities[i] << endl;
			}
			cout << "How many processes have to be executed?" << endl;	
			cin >> numberOfProcesses;
			vector < queue <Process> > q(types);
			int cb = -1, type = -1;
			for(int i = 0; i < numberOfProcesses; i++){
				cout << endl << "Enter the type of process " << i + 1 << endl;
				cin >> type;
				cout << endl << "Enter the CPU burst for process " << i + 1 << endl;
				cin >> cb;
				Process p(i+1, cb, type);
				q[type-1].push(p);
			}
			cout << endl;
			this->queues = q;
		}
		
		void display(){
			for(int i = 0; i < types; i++){
				queue <Process> temp;
				cout << "Type of Processes : " << i + 1 << endl; 
				while(!queues[i].empty()){
					
					Process p = queues[i].front();
					cout << "Process " << p.processNumber << endl;
					cout << "CPU Burst : " << p.cpuBurst << endl;
					temp.push(p);
					queues[i].pop();
					
				}
				
				while(!temp.empty()){
				
					queues[i].push(temp.front());
					temp.pop();
				
				}
				cout << endl;
			}
		}
		
		
		void run(){
			
			queue< queue <Process> > queue_of_queues;
			vector <int> sortedPriorityIndex;
			for(int i = 0; i < types; i++){
				int min = INT_MAX, minIndex = -1;
				for(int j = 0; j < types; j++){
					if(priorities[j] < min){
						minIndex = j;
						min = priorities[j];
					}
				}
				priorities[minIndex] = INT_MAX;
				sortedPriorityIndex.push_back(minIndex);
			}
			for(int i = 0; i < types; i++){
				queue_of_queues.push(queues[sortedPriorityIndex[i]]);
			}
			for(int i = 0; i < types; i++){
				queue <Process> q;
				q = queue_of_queues.front();
				cout << "Type " << i+1 << endl << endl;
				SJF j;
				while(!q.empty()){
					j.processes.push_back(q.front());
					q.pop();
				}
				j.numberOfProcesses = j.processes.size();
				cout << "Before internal scheduling of queue " << endl;
				j.display();
				j.run();
				cout << "After internal scheduling of queue " << endl;
				j.display();
				queue_of_queues.pop();
				cout << endl;
			}
		}
		
};

int main(){
	MLQ j1;
	j1.display(); 
	j1.run();
	/*
	
	cout << "Before scheduling.. " << endl;
	j1.display();
	cout << endl;
	j1.run();
	cout << "After scheduling.. " << endl;
	j1.display();
	
	*/
	return 0;
	
}

