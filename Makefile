CC=g++

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
medianmap: MedianBuilder.cpp MedianMap.o main.cpp
	$(CC) -o MedianMap MedianBuilder.cpp MedianMap.o main.cpp -D MEDIANMAP
	
medianmapv2: MedianBuilder.cpp MedianMapV2.o main.cpp
	$(CC) -o MedianMapV2 MedianBuilder.cpp MedianMapV2.o main.cpp -D MEDIANMAPV2

all: medianmap medianmapv2
	
test: MedianMap.o MedianMapV2.o MedianTest.o test.o
	$(CC) -o test MedianMap.o MedianMapV2.o MedianTest.o test.o -lcppunit
	
clean:
	$(RM) *.o $(EXEC)