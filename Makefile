CXX				=	g++
CXXFLAGS			=	-g -c -Wall -std=c++0x
LDFLAGS				=
SOURCES				=	math_utils.cpp euclidean_distance_classifier.cpp untrained_perceptron.cpp perceptron.cpp perceptron_test.cpp adaline.cpp
untrained_perceptron_obj	=	untrained_perceptron.o
problem01_obj			=	math_utils.o euclidean_distance_classifier.o problem01.o
perceptrons_obj			=	perceptron.o adaline.o perceptron_test.o
EXECUTABLES			=	untrained_perceptron problem01 perceptrons

all:    $(SOURCES) $(EXECUTABLES)

untrained_perceptron:  $(untrained_perceptron_obj)
	$(CXX) $(LDFLAGS) $(untrained_perceptron_obj) -o $@

problem01:	$(problem01_obj)
	$(CXX) $(LDFLAGS) $(problem01_obj) -o $@

perceptrons:	$(perceptrons_obj)
	$(CXX) $(LDFLAGS) $(perceptrons_obj) -o $@

.o:
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -rf *.o $(EXECUTABLES)
