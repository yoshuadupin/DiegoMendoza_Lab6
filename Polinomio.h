
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#ifndef POLINOMIO_H
#define POLINOMIO_H

class Polinomio
{
private:
	int grado;
	//El primer coeficiente es el del mayor grado
	vector<int> coeficientes;
public:
	Polinomio();
	Polinomio(vector<int> , int);
	~Polinomio();
	
	void setGrado(int);
	void setCoeficientes(vector<int>);

	int getGrado();
	int getCoeficiente(int);
	vector<int> getCoeficientes();

	
	Polinomio operator+(Polinomio);
	Polinomio operator*(Polinomio);
	Polinomio operator-(Polinomio);
	bool operator==(Polinomio);
	bool operator!=(Polinomio);
	int operator()();
	string toString();
	void imprimir(Polinomio);

	friend ostream& operator <<(ostream& o , Polinomio poli){
	o<<poli.toString();
	return o;
}

};	



#endif