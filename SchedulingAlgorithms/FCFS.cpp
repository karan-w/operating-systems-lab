#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process{
	public: 
		int processNumber;
		int cpuBurst;
		Process(int p, int c){
			this->processNumber = p;
			this->cpuBurst = c;
		}
		bool operator < (const Process &p2) const{
			return (cpuBurst < p2.cpuBurst);
	
	}
};
class FCFS{
	public: 
		int numberOfProcesses;
		vector <Process> processes;
		FCFS(){
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
		}
		void display(){
			for(int i = 0; i < numberOfProcesses; i++){
				cout << "Process " << processes[i].processNumber << " : " << processes[i].cpuBurst << endl; 
			}
		}
		void run(){
		
			for(int i = 0; i < processes.size(); i++){
				cout << "Executing process " << processes[i].processNumber << " of CPU burst = " << processes[i].cpuBurst << endl;
			}
		
		}
};

int main(){
	FCFS j1; 	
	cout << endl;
	j1.run();
	cout << endl;
	return 0;
}
