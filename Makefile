Calculadora:	Polinomio.o main.o
	g++ Polinomio.o main.o -o Calculadora

Polinomio.o: Polinomio.h Polinomio.cpp
	g++ -c Polinomio.cpp 

main.o:	main.cpp
	g++ -c main.cpp

clean:
	rm *.o	Calculadora	