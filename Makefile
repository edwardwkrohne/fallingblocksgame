test:
<<<<<<< HEAD
	g++ -g test.cpp block.cpp piece.cpp -lcppunit  -o run_tests
=======
	g++ -g test.cpp block.cpp gamegrid.cpp -lcppunit -o run_tests
>>>>>>> 922517db91270b85f5cddb31320af15f63b33fc1
	./run_tests

clean:
	rm -f *.o run_tests a.out
