test:
	g++ -g test.cpp block.cpp gamegrid.cpp -lcppunit  -o run_tests
	./run_tests

clean:
	rm -f *.o run_tests a.out
