MeanGreenEagleLift: main.o Pass.o Ride.o Driver.o Passes.o Rides.o Drivers.o Util.o
	g++ -o MeanGreenEagleLift main.o Pass.o Ride.o Driver.o Passes.o Rides.o Drivers.o Util.o

main.o: main.cpp Pass.h Ride.h Driver.h Passes.h Rides.h Drivers.h Util.h
	g++ -c main.cpp

Pass.o: Pass.cpp Pass.h Defs.h
	g++ -c Pass.cpp

Ride.o: Ride.cpp Ride.h Defs.h
	g++ -c Ride.cpp

Driver.o: Driver.cpp Driver.h Defs.h
	g++ -c Driver.cpp

Passes.o: Passes.cpp Util.h Pass.h
	g++ -c Passes.cpp

Rides.o: Rides.cpp Util.h Ride.h
	g++ -c Rides.cpp

Drivers.o: Drivers.cpp Util.h Driver.h
	g++ -c Drivers.cpp

Util.o: Util.cpp Pass.h Ride.h Driver.h Passes.h Rides.h Drivers.h Util.h Defs.h
	g++ -c Util.cpp

clean:
	rm MeanGreenEagleLift main.o Pass.o Ride.o Driver.o Passes.o Rides.o Drivers.o

run:
	make && ./MeanGreenEagleLift