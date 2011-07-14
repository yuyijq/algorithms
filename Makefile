target/LinkedList.o: src/main/LinkedList.c src/main/LinkedList.h src/main/Common.h
	gcc -c -o target/LinkedList.o src/main/LinkedList.c

target/LinkedListTests.o: src/test/LinkedListTests.c src/main/LinkedList.h src/main/Common.h
	gcc -c -I src/main -o target/LinkedListTests.o src/test/LinkedListTests.c

target/binary_search_tree.o: src/main/binary_search_tree.c src/main/binary_search_tree.h src/main/Common.h
	gcc -c -o target/binary_search_tree.o src/main/binary_search_tree.c

target/binary_search_tree_tests.o: src/test/binary_search_tree_tests.c src/main/binary_search_tree.h src/main/Common.h
	gcc -c -I src/main -o target/binary_search_tree_tests.o src/test/binary_search_tree_tests.c

clean:
	rm -r target

test:
	gcc -o target/LinkedListTests target/LinkedListTests.o target/LinkedList.o
	./target/LinkedListTests
	gcc -o target/binary_search_tree_tests target/binary_search_tree_tests.o target/binary_search_tree.o
	./target/binary_search_tree_tests