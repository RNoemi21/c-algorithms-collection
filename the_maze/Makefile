build:
	gcc main.c biblioteca.c -g -o main

run: build
	./main

check: build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
	
gdb: build
	gdb ./main

clean:
	rm -f a.out main
