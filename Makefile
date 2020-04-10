main: main.o LU_decom.o
	g++ -o main main.o LU_decom.o
main.o: main.cpp LU_decom.h
	g++ -c main.cpp
LU_decom.o: LU_decom.cpp LU_decom.h
	g++ -c LU_decom.cpp

clean:
	rm LU_decom *.o
