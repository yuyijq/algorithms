target/LinkedList.o: src/main/LinkedList.c src/main/LinkedList.h src/main/Common.h
	gcc -c -o target/LinkedList.o src/main/LinkedList.c

clean:
	rm -r target

test:
	gcc -c -I src/main -o target/LinkedListTests.o src/test/LinkedListTests.c
	gcc -o target/LinkedListTests target/LinkedListTests.o target/LinkedList.o
	./target/LinkedListTests