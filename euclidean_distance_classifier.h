#ifndef EUCLIDEAN_DISTANCE_CLASSIFIER_H_
#define EUCLIDEAN_DISTANCE_CLASSIFIER_H_

#include <map>
#include <string>
#include <vector>

namespace snd
{

class EuclideanDistanceClassifier
{
public:
    void Train(std::map<std::string, std::vector<std::vector<double> > > training_vectors);
    std::string Classify(std::vector<double>);
private:
    std::map<std::string, std::vector<double> > average_vectors;
};

}

#endif
