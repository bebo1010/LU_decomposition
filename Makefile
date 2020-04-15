lu-decomposition: main.o LU_decom.o
	g++ -o lu-decomposition lu-decomposition.o LU_decom.o
lu-decomposition.o: lu-decomposition.cpp LU_decom.h
	g++ -c lu-decomposition.cpp
LU_decom.o: LU_decom.cpp LU_decom.h
	g++ -c LU_decom.cpp

clean:
	rm LU_decom *.o
