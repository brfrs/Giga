CXX=g++
INCLUDE=-I include
CPPFLAGS=-std=c++11 -O3 -Wall
PROJ_NAME=libGiga.a
OBJECTS= build/InputPin.o build/OutputPin.o build/Pin.o build/Utils.o

AR=ar
ARFLAGS=rcs

all: $(OBJECTS)
	$(AR) $(ARFLAGS) $(PROJ_NAME) $(OBJECTS)

build/InputPin.o: src/InputPin.cpp include/InputPin.h include/Pin.h include/Utils.h
	$(CXX) $(INCLUDE) $(CPPFLAGS) -c -o $@ $<

build/OutputPin.o: src/OutputPin.cpp include/OutputPin.h include/Pin.h include/Utils.h
	$(CXX) $(INCLUDE) $(CPPFLAGS) -c -o $@ $<

build/Pin.o: src/Pin.cpp include/Pin.h include/Utils.h include/GPIOError.h
	$(CXX) $(INCLUDE) $(CPPFLAGS) -c -o $@ $<

build/Utils.o: src/Utils.cpp include/Utils.h
	$(CXX) $(INCLUDE) $(CPPFLAGS) -c -o $@ $<

.PHONY : clean
clean:
	rm -f build/*.o