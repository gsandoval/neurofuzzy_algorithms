#include <cmath>
#include <iostream>

#include "adaline.h"

using namespace std;

namespace nf
{

Adaline::Adaline(double _learning_rate, unsigned int input_size) : Perceptron(input_size, Lineal),
    learning_rate(_learning_rate)
{
}

Adaline::Adaline(double _learning_rate, std::vector<double> weights, double bias) : Perceptron(weights, bias, Lineal),
    learning_rate(_learning_rate)
{
}

double Adaline::GetLastGlobalError()
{
    return last_global_error;
}

unsigned int Adaline::Train(vector<vector<double> > vv, unsigned int max_epochs)
{
    unsigned int epoch;
    double epoch_error;
    double error = 1 * pow(10, -3);
    for (epoch = 0; epoch < max_epochs; ++epoch) {
	epoch_error = 0;
	for (unsigned int i = 0; i < vv.size(); ++i) {
	    double d = Classify(vv[i]);
	    double expected = vv[i][vv[i].size() - 1];
	    for (unsigned int j = 0; j < vv[i].size() - 1; ++j) { // last value is the expected outcome
		weights[j] = weights[j] + learning_rate * (expected - d) * vv[i][j];
		epoch_error += pow(expected - d, 2);
	    }
	    bias = bias + learning_rate * (expected - d);
	}
	last_global_error = epoch_error;
	if (error > (epoch_error / 2)) {
	    break;
	}
    }
    return epoch;
}

}
