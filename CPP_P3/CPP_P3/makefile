all: runMain

runMain: main.o Student.o SortedList.o
	g++ main.o Student.o SortedList.o -o -m32

main.o: main.cpp
	g++ -c main.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

SortedList.o: SortedList.cpp
	g++ -c SortedList.cpp

clean:
	rm *o runMain