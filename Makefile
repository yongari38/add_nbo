all: main.c
	gcc -o add-nbo main.c

clean:
	rm add-nbo