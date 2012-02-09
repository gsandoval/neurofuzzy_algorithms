#include <iostream>
#include <vector>

using namespace std;

enum PerceptronType {
    AND, OR
};

class Perceptron
{
private:
    vector<double> weights;
    double bias;
    double StepActivationFunction(double v) {
	double res = 1;
	if (v < 0) {
	    res = 0;
	}
	return res;
    }
public:
    Perceptron(PerceptronType type) {
	if (type == AND) {
	    weights.push_back(0.5);
	    weights.push_back(0.5);
	    bias = -1;
	} else if (type == OR) {
	    weights.push_back(0.5);
	    weights.push_back(0.5);
	    bias = -0.4;
	}
    }
    double Classify(vector<double> values) {
	double sum = 0;
	for (unsigned int i = 0; i < values.size(); ++i) {
	    sum += values[i] * weights[i];
	}
	return StepActivationFunction(sum + bias);
    }
};

int main(int argc, char* argv[])
{
    Perceptron and_perceptron(AND);
    Perceptron or_perceptron(OR);
    vector<double> v1 = {0, 0};
    vector<double> v2 = {1, 0};
    vector<double> v3 = {0, 1};
    vector<double> v4 = {1, 1};
    cout << "0 & 0 = " << and_perceptron.Classify(v1) << endl;
    cout << "1 & 0 = " << and_perceptron.Classify(v2) << endl;
    cout << "0 & 1 = " << and_perceptron.Classify(v3) << endl;
    cout << "1 & 1 = " << and_perceptron.Classify(v4) << endl;
    cout << "0 | 0 = " << or_perceptron.Classify(v1) << endl;
    cout << "1 | 0 = " << or_perceptron.Classify(v2) << endl;
    cout << "0 | 1 = " << or_perceptron.Classify(v3) << endl;
    cout << "1 | 1 = " << or_perceptron.Classify(v4) << endl;
    return 0;
}

