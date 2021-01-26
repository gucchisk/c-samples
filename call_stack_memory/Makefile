main: main.s
	gcc main.s -std=c99 -o main

main.s: main.c
	gcc -S main.c

clean:
	rm main main.s
