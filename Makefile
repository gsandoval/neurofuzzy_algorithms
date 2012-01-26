CXX	    =	g++
CXXFLAGS    =	-g -c -Wall -std=c++0x
LDFLAGS	    =
SOURCES	    =	problem01.cpp math_utils.cpp euclidean_distance_classifier.cpp
OBJECTS	    =	$(SOURCES:.cpp=.o)
EXECUTABLE  =	problem01

all:    $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):  $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.o:
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -rf *.o $(EXECUTABLE)
