#include <cmath>
#include <algorithm>

#include "math_utils.h"

using namespace std;

namespace nf
{

vector<double> MathUtils::CalculateAverageVector(vector<vector<double> > input)
{
    if (input.empty()) {
	return vector<double>();
    }
    vector<double> average(input[0].size());
    fill(average.begin(), average.begin() + input[0].size(), 0);
    for (unsigned int i = 0; i < input.size(); ++i) {
	for (unsigned int j = 0; j < input[i].size(); ++j) {
	    average[j] += input[i][j];
	}
    }
    for (unsigned int i = 0; i < average.size(); ++i) {
	average[i] /= input.size();
    }
    return average;
}

double MathUtils::CalculateEuclideanDistance(vector<double> a, vector<double> b)
{
    double distance = 0;
    for (unsigned int i = 0; i < a.size(); ++i) {
	distance += pow(a[i] - b[i], 2);
    }
    return sqrt(distance);
}

}
