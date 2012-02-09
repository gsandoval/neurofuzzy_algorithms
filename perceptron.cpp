#include <vector>
#include <cmath>
#include <random>
#include <functional>
#include <ctime>

#include "perceptron.h"

using namespace std;

namespace nf
{

double Perceptron::StepActivationFunction(double v)
{
    return v >= 0 ? 1 : -1;
}

double Perceptron::LinearActivationFunction(double v)
{
    return v;
}

Perceptron::Perceptron(std::vector<double> _weights, double _bias, ActivationFunction _af) : bias(_bias), weights(_weights),
    af(_af)
{
}

Perceptron::Perceptron(unsigned int input_size, ActivationFunction _af) : af(_af)
{
    uniform_real_distribution<double> distribution(-1, 1);
    mt19937 engine;
    auto random = bind(distribution, engine);
    //srand(time(NULL));
    for (unsigned int i = 0; i < input_size; ++i) {
	this->weights.push_back(random());
	//this->weights.push_back(1.0 / (rand() % 1000));
    }
    bias = random();
    //bias = 1.0 / (rand() % 1000);
}

vector<double> Perceptron::GetWeights()
{
    return weights;
}

double Perceptron::GetBias()
{
    return bias;
}

Perceptron::~Perceptron()
{
}

double Perceptron::Classify(vector<double> v)
{
    double d = 0;
    for (unsigned int i = 0; i < weights.size(); ++i) {
	d += weights[i] * v[i];
    }
    if (af == Linear) {
	d = LinearActivationFunction(d + bias);
    } else if (af == Step) {
	d = StepActivationFunction(d + bias);
    }
    return d;
}

unsigned int Perceptron::Train(vector<vector<double> > vv, unsigned int max_epochs)
{
    unsigned int epoch;
    bool errord = true;
    double error = 1 * pow(10, -3);
    for (epoch = 0; epoch < max_epochs && errord; ++epoch) {
	errord = false;
	for (unsigned int i = 0; i < vv.size(); ++i) {
	    double d = Classify(vv[i]);
	    double expected = vv[i][vv[i].size() - 1];
	    if (abs(d - expected) > error) {
		for (unsigned int j = 0; j < vv[i].size() - 1; ++j) { // last value is the expected outcome
		    weights[j] = weights[j] + vv[i][j] * expected;
		}
		bias = bias + expected;
		errord = true;
	    }
	}
    }
    return epoch;
}

}
