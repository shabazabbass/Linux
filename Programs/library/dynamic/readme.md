This is the folder where you wil learn dynamic library

the first step is to create the object code  pic(position independent code)

gcc -c -fpic file1.c file2.c file3.c

gcc -shared -o -libmymath.so file1.o file2.o file3.o

export LD_LIBRARY_PATH=. 
gcc main.c -o main -L. -lmymath.so 
