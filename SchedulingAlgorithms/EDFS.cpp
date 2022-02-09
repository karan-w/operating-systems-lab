#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Process{
	public: 
		int processNumber;
		int cpuBurst;
		int processingTime;
		int period;
		Process(int processNumber, int cpuBurst, int period){
		
			this->processNumber = processNumber;
			this->cpuBurst = cpuBurst;
			this->period = period;
			this->processingTime = cpuBurst;
			
		}
		bool operator < (const Process &p2) const{
			return (period > p2.period);
		}
};

/* 
	Earliest Deadline First Scheduling - not complete
*/

class RMS{

	public: 
	
		int numberOfProcesses;
		vector <Process> processes;
		priority_queue <Process *> pq;
		
		RMS(){
			cout << "How many processes have to be executed?" << endl;	
			cin >> numberOfProcesses;
			int cb = -1, period = -1, processingTime = -1;
			for(int i = 0; i < numberOfProcesses; i++){
			
				cout << endl << "Enter the CPU burst for process " << i + 1 << endl;
				cin >> cb;
				 
				cout << endl << "Enter the period for process " << i + 1 << endl;
				cin >> period;
				
				Process p(i+1, cb, period);
				processes.push_back(p);
			}
			cout << endl;
		}
		
		void display(){
			
			for(int i = 0; i < numberOfProcesses; i++){
				cout << "Process " << processes[i].processNumber << endl;
				cout << "CPU Burst : " << processes[i].cpuBurst << endl;
				cout << "Period : " << processes[i].period << endl; 
				cout << endl;
			}
		}
		
		void run(){
		
			if(check()){
			
				sort(processes.begin(), processes.end());
			
			
				//clock
				for(int i = 0; i < 200; i++){
				
					//Add processes into the queue on the basis of the period
					for(int j = 0; j < processes.size(); j++){
						if(i == 0){
							this->pq.push(&processes[j]);
						}
						else if(i % processes[j].period == 0){
							processes[j].cpuBurst = processes[j].processingTime;
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
			
			}else{
			
				cout << "These processes can't be scheduled.\n";
			
			}
		}
		
		bool check(){
			float max = 2 * (pow(2, 1/float(numberOfProcesses)) - 1);
			float sum = 0;
			for(int i = 0; i < numberOfProcesses; i++){
				sum += float(processes[i].processingTime)/float(processes[i].period);
			
			}
			if(sum >= max){
				cout << "Max CPU Utilization Possible : " << max << endl << endl;
				cout << "Current CPU Utilization : " << sum << endl << endl;
				return false;
			}
			
			return true;
			
		}
};

int main(){
		
	
	RMS j1; 	
	cout << "Before scheduling.. \n\n";
	j1.display();
	cout << endl;
	j1.run();
	return 0;
}
