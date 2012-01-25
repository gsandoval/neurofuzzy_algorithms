#include "math_utils.h"

#include <algorithm>
#include <cmath>

using namespace std;

namespace snd
{

vector<double> MathUtils::CalculateAverageVector(vector<vector<double> > input)
{
    vector<double> average;
    for (unsigned int i = 0; i < input.size(); ++i) {
	average.push_back(0);
	for (unsigned int j = 0; j < input[i].size(); ++j) {
	    average[i] += input[i][j];
	}
    }
    for_each(average.begin(), average.end(), [&input](double v) -> double { return v / input.size(); });
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
