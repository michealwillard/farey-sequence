CPPFLAGS+= -g -Wall
LDLIBS+= -lstdc++

fareyTest.o: fareySequence.h fareySequence.cpp fareyTest.cpp
	g++ -std=c++0x $(CPPFLAGS) fareySequence.cpp fareyTest.cpp -o fareyTest

runfareytest: fareyTest.o
	rm -f fareyTest.out
	./fareyTest &> fareyTest.out
	# gcov -b -f fareySequence.cpp >> fareyTest.out
	# cat fareySequence.cpp.gcov >> fareyTest.out

clean:
	rm -f *.o *.out fareyTest
