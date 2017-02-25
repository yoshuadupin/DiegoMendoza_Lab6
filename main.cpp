#include "Polinomio.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<Polinomio> resultados;
	int opcion;



	do{
		cout<<"Ingrese la operacion:1.Suma 2.Resta 3.factor comun 4.Igualdad 5.Diferencia 6.multiplicacion"<<endl;		
		cin>>opcion;
		vector<int> polinomio1;
		vector<int> polinomio2;
		int grado1;
		int grado2;
		cout<<"Ingrese el grado del polinomio 1:"<<endl;
		cin>>grado1;
		for (int i = 0; i < grado1+1; ++i){
			int coef;
			cin>>coef;
			polinomio1.push_back(coef);
		}


		cout<<"Ingrese el grado del polinomio 2:"<<endl;
		cin>>grado2;
		for (int i = 0; i < grado2+1; ++i){
			int coef;
			cin>>coef;
			polinomio2.push_back(coef);
		}
		Polinomio funcion1 = Polinomio(polinomio1 , grado1);
		Polinomio funcion2 = Polinomio(polinomio2 , grado2);
		cout<<"Funcion 1:"<<funcion1<<endl;
		cout<<"Funcion 2:"<<funcion2<<endl;
		cout<<endl;
		if(opcion == 1){
			cout<<"La suma es"<<endl;
			Polinomio resultado = funcion1+funcion1;
			cout<<resultado;	
		}else if(opcion ==2){
			cout<<"La resta es"<<endl;
			Polinomio resultado = funcion1-funcion1;
			cout<<resultado;
		}else if(opcion == 3){
			cout<<"La factor comun del primero es:"<<endl;
			cout<<funcion1();
		}
		else if(opcion == 4){
			cout<<"Verificar si son iguales"<<endl;
			if (funcion1 == funcion2)
			{
				cout<<"Son iguales"<<endl;
			}
			
		}else if(opcion == 5){
			cout<<"Verificar si son diferentes"<<endl;
			if (funcion1 == funcion2)
			{
				cout<<"Son diferentes"<<endl;
			}

		}else if(opcion == 6){
			cout<<"La multiplicacion es"<<endl;
			Polinomio resultado = funcion1*funcion1;
			cout<<resultado;
		}

	}while(opcion != 9);

	return 0;
}