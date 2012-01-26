#ifndef MATH_UTILS_H_
#define MATH_UTILS_H_

#include <vector>

namespace nf
{

class MathUtils
{
public:
    static std::vector<double> CalculateAverageVector(std::vector<std::vector<double> > input);
    static double CalculateEuclideanDistance(std::vector<double> a, std::vector<double> b);
};

}

#endif
