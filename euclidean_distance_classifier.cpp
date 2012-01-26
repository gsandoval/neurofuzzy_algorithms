#include "euclidean_distance_classifier.h"
#include "math_utils.h"

using namespace std;

namespace nf
{

void EuclideanDistanceClassifier::Train(map<string, vector<vector<double> > > training_vectors)
{
    for (auto it = training_vectors.begin(); it != training_vectors.end(); ++it) {
	average_vectors[it->first] = MathUtils::CalculateAverageVector(it->second);
    }
}

string EuclideanDistanceClassifier::Classify(vector<double> input)
{
    double min_dist = 1 << 30;
    string vector_class = "";
    for (auto it = average_vectors.begin(); it != average_vectors.end(); ++it) {
	double dist = MathUtils::CalculateEuclideanDistance(it->second, input);
	if (min_dist > dist) {
	    min_dist = dist;
	    vector_class = it->first;
	}
    }
    return vector_class;
}

}
