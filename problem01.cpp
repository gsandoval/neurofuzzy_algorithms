#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	map<string, vector<vector<double> > > training;
	map<vector<double>, string> average;
	int samples = 50;
	int characteristics = 7;
	for (int i = 0; i < samples; i++) {
		string name;
		cin >> name;
		if (training.find(name) == training.end()) {
			training[name] = vector<vector<double> >();
		}
		vector<vector<double> > *identity_set = &training[name];
		vector<double> curr_vector;
		double curr_value;
		for (int j = 0; j < characteristics; j++) {
			cin >> curr_value;
			curr_vector.push_back(curr_value);
		}
		identity_set->push_back(curr_vector);
		
		cout << i << " -> " << name << " -> " << training[name].size() << endl;
	}
	
	return 0;
}
