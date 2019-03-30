ht.exe: hash_table.o main.o
	gcc -o ht.exe hash_table.o main.o
hash_table.o: hash_table.c hash_table.h
	gcc -c hash_table.c 
main.o: main.c hash_table.h
	gcc -c main.c 