gcc -Wall -g -c main.c -o main.o
gcc -Wall -g -c util.c -o util.o
gcc -Wall -g -c ArvoreBinaria.c -o ArvoreBinaria.o
gcc -Wall -g -o main.exe main.o util.o ArvoreBinaria.o -lm
