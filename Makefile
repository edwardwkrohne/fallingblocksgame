test:
	g++ -g test.cpp block.cpp -lcppunit -o run_tests
	./run_tests

clean:
	rm *.o run_tests a.out
