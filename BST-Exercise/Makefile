BST.exe: binsearchtree.a 
	gcc -o BST.exe  -L. -lbinsearchtree 
binsearchtree.a: BST.o main.o
	ar rcs libbinsearchtree.a BST.o main.o 
BST.o: BST.c BST.h
	gcc -c BST.c -Wall	
main.o: main.c BST.h
	gcc -c main.c -Wall
clear:	 
	rm *.o *.a BST.exe

