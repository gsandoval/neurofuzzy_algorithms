#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "euclidean_distance_classifier.h"

using namespace std;

map<string, string> parseOpts(int argc, char* argv[])
{
    map<string, string> options;
    string key;
    for (int i = 1; i < argc; ++i) {
	string param(argv[i]);
	if (param[0] == '-') {
	    while (param[0] == '-') param = param.substr(1);
	    if (!key.empty()) {
		options[key] = key;
	    }
	    key = param;
	} else {
	    if (key.empty()) {
		key = param;
	    }
	    options[key] = param;
	    key = "";
	}
    }
    if (!key.empty()) {
	options[key] = key;
    }
    return options;
}

int main(int argc, char* argv[])
{
    map<string, string> opts = parseOpts(argc, argv);

    int samples_per_class;
    istringstream iss(opts["t"]);
    iss >> samples_per_class;
    int characteristics;
    iss.clear();
    iss.str(opts["c"]);
    iss >> characteristics;
    string filename = opts["f"];
    bool verbose = opts.find("v") != opts.end();
    bool veryverbose = opts.find("vv") != opts.end();
	bool first_on_list = opts.find("l") != opts.end();
	int samples_taken = 0;
    if (veryverbose) {
	verbose = true;
    }
    fstream file(filename);

    map<string, vector<vector<double> > > universe;
	map<string, vector<vector<double> > > sample_data;

    while (!file.eof()) {
	string name;
	file >> name;
	if (name.empty()) {
	    break;
	}
	if (universe.find(name) == universe.end()) {
	    universe[name] = vector<vector<double> >();
	}
	if (first_on_list && sample_data.find(name) == sample_data.end()) {
		sample_data[name] = vector<vector<double> >();
	}
	vector<vector<double> > *identity_set = &universe[name];
	vector<double> curr_vector;
	double curr_value;
	for (int j = 0; j < characteristics; ++j) {
	    file >> curr_value;
	    curr_vector.push_back(curr_value);
	}
	identity_set->push_back(curr_vector);
	if (first_on_list && samples_taken < samples_per_class) {
	samples_taken++;
	sample_data[name].push_back(curr_vector);
	}
    }
	
	if (!first_on_list) {
    cout << "Picking sample data. Lazily taking the first " << samples_per_class << " of each class." << endl;
    for (auto it = universe.begin(); it != universe.end(); ++it) {
	vector<vector<double> > s;
	for (int i = 0; i < samples_per_class; ++i) {
	    s.push_back(it->second[i]);
	}
	sample_data[it->first] = s;
    }
	}
    cout << "Performing training using " << samples_per_class << " samples per class." << endl;
    nf::EuclideanDistanceClassifier classifier;
    classifier.Train(sample_data);
    cout << "Testing..." << endl;
    int successCount = 0, failureCount = 0;
    for (auto it = universe.begin(); it != universe.end(); ++it) {
	int classSuccess = 0, classFailure = 0;
	for (unsigned int i = 0; i < it->second.size(); ++i) {
	    string c = classifier.Classify(it->second[i]);
	    if (c== it->first) {
		successCount++;
		classSuccess++;
		if (veryverbose) {
		    cout << "Vector of class " << it->first << " correctly identified as " << c << u8" \u2713" << endl;
		}
	    } else {
		failureCount++;
		classFailure++;
		if (veryverbose) {
		    cout << "Vector of class " << it->first << " incorrectly identified as " << c << u8" \u2715" << endl;
		}
	    }
	}
	if (verbose) {
	    cout << "Class " << it->first << " reported ";
	    cout << classSuccess << "/" << it->second.size() << " success and ";
	    cout << classFailure << "/" << it->second.size() << " failure." << endl;
	}
    }

    cout << "Summary: ";
    cout << successCount << "/" << (successCount + failureCount) << " success. ";
    cout << failureCount << "/" << (successCount + failureCount) << " failure." << endl;
    return 0;
}
