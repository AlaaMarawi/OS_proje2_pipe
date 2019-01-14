CC=gcc
CFLAGS=-c -Wall
all: determinant3x3 kofakhesap2x2 satsutsec
determinant3x3: determinant3x3.c
	$(CC) determinant3x3.c -o determinant3x3
kofakhesap2x2: Kofakhesap2x2.c
	$(CC) Kofakhesap2x2.c -o kofakhesap2x2 -lm
satsutsec: satsutsec.c
	$(CC) satsutsec.c -o satsutsec						
clean: rm -rf *o determinant3x3		
