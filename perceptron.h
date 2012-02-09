#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

namespace nf
{

class Perceptron
{
public:
    enum ActivationFunction {
	Step, Lineal
    };
protected:
    double bias;
    std::vector<double> weights;
    ActivationFunction af;
    double StepActivationFunction(double v);
    double LinealActivationFunction(double v);
public:
    Perceptron(unsigned int input_size, ActivationFunction af = Step);
    Perceptron(std::vector<double> weights, double bias, ActivationFunction af = Step);
    virtual ~Perceptron();
    virtual unsigned int Train(std::vector<std::vector<double> > vv, unsigned int max_epochs = 10000);
    double Classify(std::vector<double> v);
    std::vector<double> GetWeights();
    double GetBias();
};

}

#endif // PERCEPTRON_H
