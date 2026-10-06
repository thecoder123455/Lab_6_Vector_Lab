CC = gcc
CFLAGS = -Wall -Wextra

lab5: lab5.o vectArray.o vectParse.o vectorCalc.o
	$(CC) $(CFLAGS) -o lab5 lab5.o vectArray.o vectParse.o vectorCalc.o

lab5.o: lab5.c vect.h vectParse.h vectArray.h vectorCalc.h
	$(CC) $(CFLAGS) -c lab5.c

vectArray.o: vectArray.c vect.h vectParse.h vectArray.h vectorCalc.h
	$(CC) $(CFLAGS) -c vectArray.c

vectParse.o: vectParse.c vect.h vectParse.h vectArray.h vectorCalc.h
	$(CC) $(CFLAGS) -c vectParse.c

vectorCalc.o: vectorCalc.c vect.h vectParse.h vectArray.h vectorCalc.h
	$(CC) $(CFLAGS) -c vectorCalc.c

clean:
	rm -f *.o lab5