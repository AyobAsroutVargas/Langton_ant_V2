CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

main: main.o universe.o world.o ant.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp world.h ant.h universe.h
	$(CXX) -c main.cpp

universe.o: universe.cpp world.h ant.h
	$(CXX) -c universe.cpp

world.o: world.cpp world.h
	$(CXX) -c world.cpp

ant.o: ant.cpp ant.h
	$(CXX) -c ant.cpp

clean:
	rm main *.o