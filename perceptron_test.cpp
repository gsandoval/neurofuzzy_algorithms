#include <iostream>
#include <vector>

#include "perceptron.h"
#include "adaline.h"

using namespace std;

int main(int argc, char * argv[])
{
    //nf::Perceptron p({1, 1}, 0.5);
    vector<double> fweights;
    vector<double> sweights;
    double fbias;

    nf::Perceptron p(2);
    sweights = p.GetWeights();
    cout << "******************" << endl;
    cout << "initial weights: ";
    for (unsigned int i = 0; i < sweights.size(); ++i) {
	cout << sweights[i] << (i != sweights.size() -1 ? ", " : "");
    }
    cout << endl;
    unsigned int epochs = p.Train({{-1, -1, -1}, {1, -1, -1}, {-1, 1, -1}, {1, 1, 1}});
    fweights = p.GetWeights();
    fbias = p.GetBias();
    cout << "finished in " << epochs << " epochs:" << endl;
    cout << "weights: ";
    for (unsigned int i = 0; i < fweights.size(); ++i) {
	cout << fweights[i] << ", ";
    }
    cout << "bias: " << fbias << endl;

    nf::Adaline a(0.1, 2);
    sweights = a.GetWeights();
    cout << "******************" << endl;
    cout << "initial weights: ";
    for (unsigned int i = 0; i < sweights.size(); ++i) {
	cout << sweights[i] << (i != sweights.size() -1 ? ", " : "");
    }
    cout << endl;
    epochs = a.Train({{-1, -1, -1}, {1, -1, -1}, {-1, 1, -1}, {1, 1, 1}});
    fweights = a.GetWeights();
    fbias = a.GetBias();
    double global_error = a.GetLastGlobalError();
    cout << "finished in " << epochs << " epochs:" << endl;
    cout << "weights: ";
    for (unsigned int i = 0; i < fweights.size(); ++i) {
	cout << fweights[i] << ", ";
    }
    cout << "bias: " << fbias << ", global error: " << global_error << endl;

    a = nf::Adaline(0.4, 3);
    sweights = a.GetWeights();
    cout << "******************" << endl;
    cout << "initial weights: ";
    for (unsigned int i = 0; i < sweights.size(); ++i) {
	cout << sweights[i] << (i != sweights.size() -1 ? ", " : "");
    }
    cout << endl;
    epochs = a.Train({{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 0, 2}, {0, 1, 1, 3}, {1, 0, 0, 4},
    {1, 0, 1, 5}, {1, 1, 0, 6}, {1, 1, 1, 7}});
    fweights = a.GetWeights();
    fbias = a.GetBias();
    global_error = a.GetLastGlobalError();
    cout << "finished in " << epochs << " epochs:" << endl;
    cout << "weights: ";
    for (unsigned int i = 0; i < fweights.size(); ++i) {
	cout << fweights[i] << ", ";
    }
    cout << "bias: " << fbias << ", global error: " << global_error << endl;
    return 0;
}
