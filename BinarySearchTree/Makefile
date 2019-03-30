BST.exe: drzewo_main.o drzewoBST.a
	gcc -o BST.exe drzewo_main.o -L. -ldrzewoBST
drzewoBST.a: drzewoBST.o 
	ar rcs libdrzewoBST.a drzewoBST.o
drzewoBST.o : drzewoBST.c drzewoBST.h
	gcc -c drzewoBST.c
drzewo_main.o: drzewo_main.c drzewoBST.h
	gcc -c drzewo_main.c
clear: 
	-rm *.o BST.exe