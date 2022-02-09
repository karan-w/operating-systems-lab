#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Process{
	public: 
		int processNumber;
		int cpuBurst;
		int priority;
		int startTime;
		Process(int processNumber, int cpuBurst, int priority, int startTime){
			this->processNumber = processNumber;
			this->cpuBurst = cpuBurst;
			this->priority = priority;
			this->startTime = startTime;
		}
		bool operator < (const Process &p2) const{
			return (startTime < p2.startTime);
		}
};

/* 
	Priority Scheduling With Premption  
*/

class PS{

	public: 
	
		int numberOfProcesses;
		vector <Process> processes;
		priority_queue <Process *> pq;
		
		PS(){
			cout << "How many processes have to be executed?" << endl;	
			cin >> numberOfProcesses;
			int cb = -1, priority = -1, startTime = -1;
			for(int i = 0; i < numberOfProcesses; i++){
			
				cout << endl << "Enter the CPU burst for process " << i + 1 << endl;
				cin >> cb;
				 
				cout << endl << "Enter the priority for process " << i + 1 << endl;
				cin >> priority;
				
				cout << endl << "Enter the start time for process " << i + 1 << endl;
				cin >> startTime;
				
				Process p(i+1, cb, priority, startTime);
				processes.push_back(p);
			}
			cout << endl;
		}
		
		void display(){
			
			for(int i = 0; i < numberOfProcesses; i++){
				cout << "Process " << processes[i].processNumber << endl;
				cout << "CPU Burst : " << processes[i].cpuBurst << endl;
				cout << "Priority : " << processes[i].priority << endl; 
				cout << "Start Time : " << processes[i].startTime << endl; 
				cout << endl;
			}
		}
		
		void run(){
			sort(processes.begin(), processes.end());
			
			//clock
			for(int i = 0; i < 100; i++){
				
				//Add recently arrived processes into the queue based on start time
				for(int j = 0; j < processes.size(); j++){
				
					if(processes[j].startTime == i){
						this->pq.push(&processes[j]);
					}
					
				}
				
				if(this->pq.empty()){
					continue;
				}
				
				Process* currentProcess = this->pq.top();
				currentProcess->cpuBurst--;
				if(currentProcess->cpuBurst == 0){
					this->pq.pop();
				}
				cout << "Executing process number " << currentProcess->processNumber << " at time " << i << endl;
						
			}
		
		}
};

int main(){
		
	
	PS j1; 	cout << "Before scheduling.. \n\n";
	j1.display();
	cout << endl;
	j1.run();
	
	return 0;
}
