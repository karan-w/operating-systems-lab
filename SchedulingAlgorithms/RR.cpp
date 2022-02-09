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
class RR{
	public: 
		int numberOfProcesses;
		vector <Process> processes;
		int time_quantum;
		RR(){
			cout << "How many processes have to be executed?" << endl;	
			cin >> numberOfProcesses;
			cout << "Please enter the time quantum." << endl;	
			cin >> time_quantum;
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
			while(notDone()){
			
				for(int i = 0; i < processes.size(); i++){
					if(processes[i].cpuBurst < time_quantum && processes[i].cpuBurst > 0){
						cout << "Process " << processes[i].processNumber << " ran for " << processes[i].cpuBurst << " seconds." << endl;
						processes[i].cpuBurst = 0;
					}
					else if (processes[i].cpuBurst >= time_quantum){
						processes[i].cpuBurst -= time_quantum;
						cout << "Process " << processes[i].processNumber << " ran for " << time_quantum << " seconds." << endl;
					}
				}
			}
		}
		bool notDone(){
			
			for(int i = 0; i < processes.size(); i++){
			
				if(processes[i].cpuBurst){
				
					return true;
					
				}
				
			}
			
			return false;
			
		}
};

int main(){
	RR j1; 	
	cout << endl;
	j1.display();
	cout << endl;
	j1.run();
	cout << endl;
	return 0;
}
