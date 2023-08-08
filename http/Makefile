

ALL:testserver

testserver:testserver.cpp
	$(MAKE) -C../
	g++ testserver.cpp -o testserver -lmymuduo -lpthread

clean:
	$(MAKE) -C../ clean
	rm -f *.o


.PHONY:ALL clean