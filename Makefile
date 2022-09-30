
CFLAG=-std=c++20

test: testAll.o 
	g++ $(CFLAG) testAll.o -lgtest -lgtest_main -pthread -o testAll
testAll.o: test/testAll.cpp testNode.o testTrunk.o
	g++ $(CFLAG) -c test/testAll.cpp -pthread
testNode.o: test/testNode.cpp
	g++ $(CFLAG) -c test/testNode.cpp -pthread
testTrunk.o: test/testTrunk.cpp
	g++ $(CFLAG) -c test/testTrunk.cpp -pthread

clean:
	rm *.o testAll