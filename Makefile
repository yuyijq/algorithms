LinkedListTests: LinkedList.o LinkedListTests.o
	gcc -o target/LinkedListTests target/LinkedList.o target/LinkedListTests.o

LinkedList.o: src/main/LinkedList.c src/main/LinkedList.h src/main/Common.h
	gcc -c -o target/LinkedList.o src/main/LinkedList.c

LinkedListTests.o: src/test/LinkedListTests.c src/main/LinkedList.h
	gcc -c -I src/main -o target/LinkedListTests.o src/test/LinkedListTests.c