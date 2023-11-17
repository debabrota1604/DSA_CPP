CXX = g++
CXXFLAGS = -std=c++11
EXEC = "vehicleLibrary.a"

EXEC: car.o bike.o
	ar ru $(EXEC) car.o bike.o
	rm *.o

car.o: car.cpp vehicle.cpp
	$(CXX) $(CXXFLAGS) -c car.cpp

bike.o: bike.cpp vehicle.cpp
	$(CXX) $(CXXFLAGS) -c bike.cpp

clean:
	rm $(EXEC) 