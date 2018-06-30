CC  = gcc -static
CCL = gcc -static 
INCLUDE = -I.
DST = test.exe
MODULE = dllist.o

$(DST): $(MODULE) test.o
	$(CC) test.o $(MODULE) -o $(DST) $(INCLUDE)

test.o: test.c
	$(CC) -c test.c -o test.o -O2 $(INCLUDE)

dllist.o: dllist.c
	$(CC) -c dllist.c -o dllist.o $(INCLUDE) -O2