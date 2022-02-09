#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process{
	public: 
		int processNumber;
		int cpuBurst;
		int priority;
		Process(int processNumber, int cpuBurst, int priority){
			this->processNumber = processNumber;
			this->cpuBurst = cpuBurst;
			this->priority = priority;
		}
		bool operator < (const Process &p2) const{
			return (priority < p2.priority);
		}
};

/* 
	Priority Scheduling Without Premption  
*/

class PS{
	public: 
		int numberOfProcesses;
		vector <Process> processes;
		PS(){
			cout << "How many processes have to be executed?" << endl;	
			cin >> numberOfProcesses;
			int cb = -1, priority = -1;
			for(int i = 0; i < numberOfProcesses; i++){
				cout << endl << "Enter the CPU burst for process " << i + 1 << endl;
				cin >> cb;
				cout << endl << "Enter the priority for process " << i + 1 << endl;
				cin >> priority;
				Process p(i+1, cb, priority);
				processes.push_back(p);
			}
			cout << endl;
		}
		void display(){
			
			for(int i = 0; i < numberOfProcesses; i++){
				cout << "Process " << processes[i].processNumber << endl;
				cout << "CPU Burst : " << processes[i].cpuBurst << endl;
				cout << "Priority : " << processes[i].priority << endl; 
				cout << endl;
			}
		}
		void run(){
		
			sort(processes.begin(), processes.end());
		
		}
};

int main(){
	PS j1; 	cout << "Before scheduling.. \n\n";
	j1.display();
	cout << endl;
	j1.run();
	cout << "After scheduling.. \n\n";
	j1.display();
	return 0;
}
