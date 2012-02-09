#ifndef ADALINE_H
#define ADALINE_H

#include <vector>

#include "perceptron.h"

namespace nf
{

class Adaline : public Perceptron
{
private:
    double learning_rate;
    double last_global_error;
public:
    Adaline(double learning_rate, unsigned int input_size);
    Adaline(double learning_rate, std::vector<double> weights, double bias);
    unsigned int Train(std::vector<std::vector<double> > vv, unsigned int max_epochs = 10000);
    double GetLastGlobalError();
};

}

#endif // ADALINE_H
