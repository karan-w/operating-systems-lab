#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void displayVector(const vector <int> &v){
	int size = v.size();
	for(int i = 0; i < size; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

vector <int> subtractVectors(vector <int> &vector1, vector <int> &vector2){
	if(vector1.size() == vector2.size()){
		vector <int> vector3;
		for(int i = 0; i < vector1.size(); i++){
		
			vector3.push_back(vector1[i] - vector2[i]);
			
		}
		
		return vector3;
	
	}else{
	
		cout << "Sizes of the vector are different." << endl;
		vector <int> empty;
		return empty;
	}

}

vector <int> addVectors(vector <int> &vector1, vector <int> &vector2){
	if(vector1.size() == vector2.size()){
		vector <int> vector3;
		for(int i = 0; i < vector1.size(); i++){
		
			vector3.push_back(vector1[i] + vector2[i]);
			
		}
		
		return vector3;
	
	}else{
	
		cout << "Sizes of the vector are different." << endl;
		vector <int> empty;
		return empty;
	}

}

class BankersAlgorithm{
	public:
		int numberOfProcesses, numberOfResources;
		vector <int> available;
		vector < vector <int> > max;
		vector < vector <int> > allocation;
		vector < vector <int> > need;
		
		bool isLessThanOrEqualTo(const vector <int> &vector1, const vector <int> &vector2){
			int size = vector1.size();
			for(int i = 0; i < size; i++){
				if(vector1[i] > vector2[i]){
					return false;
				}
			}
			return true;
		}
		
		BankersAlgorithm(const vector <int> &available, const vector < vector <int> > &max, const vector < vector <int> > &allocation, const vector < vector <int> > &need, int numberOfProcesses, int numberOfResources){
		
			this->available = available;
			this->max = max;
			this->allocation = allocation;
			this->need = need;
			this->numberOfProcesses = numberOfProcesses;
			this->numberOfResources = numberOfResources;
			
		}
		
		bool isSafe(){
			vector <bool> finish(numberOfProcesses, false);
			vector <int> work = available;
			for(int i = 0; i < numberOfProcesses; i++){
				if(finish[i] == false && isLessThanOrEqualTo(this->need[i], work)){
					work = addVectors(work, this->allocation[i]);
					finish[i] = true;
					i = -1; //start checking for all processes again
				}
			}
			for(int i = 0; i < numberOfProcesses; i++){
				if(finish[i] == false){
					return false;
				}
			}
			return true;
		}
		
		//0 indexed processID
		
		bool requestResource(int processID, vector <int> request){
			if(isLessThanOrEqualTo(request, need[processID])){
				if(isLessThanOrEqualTo(request, available)){
					//save previous state
					vector <int> oldAvailable = this->available;
					vector < vector <int> > oldMax = this->max;
					vector < vector <int> > oldAllocation = this->allocation;
					vector < vector <int> > oldNeed = this->need;
					this->available = subtractVectors(available, request);
					this->allocation[processID] = addVectors(allocation[processID], request);
					this->need[processID] = subtractVectors(need[processID], request);
					
					if(isSafe()){
						cout << "Resource request successfully executed.\n";
						return true;
					}else{
						cout << "New state is unsafe. Restoring old state.\n";
						this->available = oldAvailable;
						this->max = oldMax;
						this->allocation = oldAllocation;
						this->need = oldNeed;
						return false;
					}
				}
				else{
					cout << "Process " << processID << " must wait since the resources are not available.\n";
					return false;
				}
			}else{
				cout << "Process " << processID << " has exceeded it's maximum claim.\n";
				return false;
			}
			
		}
};

int main(){

	ifstream in("BankersAlgorithmInput.txt");\
	
	if(!in.is_open()){
		cout << "Couldn't open the input file." << endl;
		return -1;
	}
	
	int numberOfProcesses, numberOfResources, instancesOfResource, value; \
	
	in >> numberOfProcesses;
	in >> numberOfResources;
	
	vector <int> available;
	
	for(int i = 0; i < numberOfResources; i++){
		in >> instancesOfResource;
		available.push_back(instancesOfResource);
	}
	
	vector < vector <int> > max;
	
	for(int i = 0; i < numberOfProcesses; i++){
		vector <int> maxVector;
		for(int j = 0; j < numberOfResources; j++){
			in >> value;
			maxVector.push_back(value);
		}
		max.push_back(maxVector);
	}
	
	vector < vector <int> > allocation;
	
	for(int i = 0; i < numberOfProcesses; i++){
		vector <int> allocationVector;
		for(int j = 0; j < numberOfResources; j++){
			in >> value;
			allocationVector.push_back(value);
		}
		allocation.push_back(allocationVector);
	}
	
	vector < vector <int> > need;
	
	for(int i = 0; i < numberOfProcesses; i++){
		need.push_back(subtractVectors(max[i], allocation[i]));
	}
	
	
	BankersAlgorithm b(available, max, allocation, need, numberOfProcesses, numberOfResources);
	if(b.isSafe()){
	
		cout << "This state is safe." << endl;
	 
	}else {
	
		
		cout << "This state is not safe." << endl;
	
	}
	
	vector <int> request(3);
	request[0] = 1;
	request[1] = 0;
	request[2] = 2;
	
	if(b.requestResource(1, request)){
	
		cout << "Request successful." << endl;
		
	}else{
	
		cout << "Request failed." << endl;
	
	}
	
	request[0] = 0;
	request[1] = 2;
	request[2] = 0;
	
	if(b.requestResource(0, request)){
	
		cout << "Request successful." << endl;
		
	}else{
	
		cout << "Request failed." << endl;
	
	}
	
	/*
	if(b.isSafe()){
	
		cout << "This state is safe." << endl;
	 
	}else {
	
		
		cout << "This state is not safe." << endl;
	
	}
	*/

	return 0;
}
