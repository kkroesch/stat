#
# Makefile
#

# Compiler settings
CC=c++

statistik: statistik.o
	$(CC) -o statistik statistik.o -lm

statistik.o: statistik.cpp
	$(CC) -g -c statistik.cpp

run: statistik
	./statistik students.data

clean:
	rm *.o statistik
