main: main.s
	gcc main.s -o main

main.s: main.c
	gcc -S main.c -std=c99

clean:
	rm main main.s
