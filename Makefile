test: test
	g++ --coverage -g -O0 -o test src/TestMain.cpp src/Course.cpp src/Student.cpp src/TestStudent.cpp -lcppunit
	./test
	gcovr

clean:
	rm test *.gcda *.gcno