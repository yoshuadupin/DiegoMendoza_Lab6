#include "Polinomio.h"

void Polinomio::setGrado(int grado){
	this->grado = grado;
}

void Polinomio::setCoeficientes(vector<int> coeficientes){
	this->coeficientes = coeficientes;
}

int Polinomio::getGrado(){
	return this->grado;
}

int Polinomio::getCoeficiente(int pos){
	return this->coeficientes[pos];
}

vector<int> Polinomio::getCoeficientes(){
	return this->coeficientes;
}

//Constructores
Polinomio::Polinomio(vector<int> coeficientes , int grado){
	this->coeficientes = coeficientes ; 
	this->grado = grado;	
}

Polinomio::~Polinomio(){
	this->coeficientes.clear();
}

//Sobrecarga de suma
Polinomio Polinomio::operator+(Polinomio poli){
		//Sacamos los grados para poder crear los vectores
	int gradoMenor = 0;
	int gradoMayor = 0;
		//Condicion para sacar el grado
	if (this->grado <= poli.getGrado()){
		gradoMenor = this->grado;
		gradoMayor = poli.getGrado();			
	}else{
		gradoMenor = poli.getGrado();
		gradoMayor = this->grado;
	}

	vector<int>suma(gradoMayor+1 , 0);
		//sumar polinomios del mismo grado
	for (int i = 0; i <= gradoMayor; ++i){
		if(i<=gradoMenor){
			suma[i] = (this->getCoeficientes()[i] + poli.getCoeficientes()[i]);
		}else{
				//Elige quien es el que tiene el grado menor y hace es el que introduce los valores siguientes
			if(this->getGrado() == gradoMayor){
				suma[i] =this->getCoeficiente(i);
			}else{
				suma[i] = poli.getCoeficiente(i);
			} 
		}
	}

	return Polinomio(suma , gradoMayor);
}
	//TODO:Cambiar para la resta
Polinomio Polinomio::operator-(Polinomio poli){
			//Sacamos los grados para poder crear los vectores
	int gradoMenor = 0;
	int gradoMayor = 0;
		//Condicion para sacar el grado
	if (this->grado <= poli.getGrado()){
		gradoMenor = this->grado;
		gradoMayor = poli.getGrado();			
	}else{
		gradoMenor = poli.getGrado();
		gradoMayor = this->grado;
	}

	vector<int>resta(gradoMayor+1 , 0);
		//restar polinomios del mismo grado
	for (int i = 0; i <= gradoMayor; ++i){
		if(i<=gradoMenor){
			resta[i] = (this->getCoeficientes()[i] - poli.getCoeficientes()[i]);
		}else{
				//Elige quien es el que tiene el grado menor y hace es el que introduce los valores siguientes
			if(this->getGrado() == gradoMayor){
				resta[i] =this->getCoeficiente(i);
			}else{
				resta[i] = poli.getCoeficiente(i);
			} 
		}
	}

	return Polinomio(resta , gradoMayor);

}

Polinomio Polinomio::operator*(Polinomio poli){

	vector<Polinomio>polinomios;

	int grado = this ->getGrado()+poli.getGrado();
	vector<int>vectorVacio(grado+1 , 0);
	Polinomio productoPoli = Polinomio(vectorVacio ,grado);
	vector<vector<int> > multiplicaciones;
	vector<int>multi;

	int gradoMenor = 0;
	int gradoMayor = 0;
		//Condicion para sacar el grado
	if (this->grado <= poli.getGrado()){
		gradoMenor = this->grado;
		gradoMayor = poli.getGrado();			
	}else{
		gradoMenor = poli.getGrado();
		gradoMayor = this->grado;
	}
	for (int i = 0; i < this->getCoeficientes().size(); ++i){
		cout<<"Vector: "<<i<<endl;
		for (int j = 0; j <=gradoMayor; ++j){

			if(gradoMenor >= j){
				multi.push_back(this->getCoeficiente(i)*poli.getCoeficiente(j)); 

			}else{
				multi.push_back(0);
			}

		}

		multiplicaciones.push_back(multi);
		polinomios.push_back(Polinomio(multiplicaciones[multiplicaciones.size()-1] , multi.size()+1));
		imprimir(polinomios[polinomios.size()-1]);

		if(gradoMenor>=gradoMayor){
			gradoMayor=gradoMayor-1	;
		}

		multi.clear();
	}


	cout<<endl;



		//Probando

	cout<<endl;
	for (int i = 0; i < polinomios.size(); ++i){
		imprimir(productoPoli);
		productoPoli =productoPoli+polinomios[i];
	}

	return productoPoli;

}
	//Sobrecarga para igual
bool Polinomio::operator==(Polinomio poli){
	bool grados = false;
	bool elementosIguales = false;
	if(this->getGrado()==poli.getGrado()){
		grados = true;
		for (int i = 0; i < this->getCoeficientes().size(); ++i)
		{	
			if(this->getCoeficiente(i) == poli.getCoeficiente(i)){
				elementosIguales = true;	
			}else{
				elementosIguales = false;
				break;
			}
		}
	}else{
		grados = false;
	}

	if(grados && elementosIguales){
		return true;
	}else{
		return false;
	}

}

bool Polinomio::operator!=(Polinomio poli){
	bool grados = false;
	bool elementosIguales = false;
	if(this->getGrado()==poli.getGrado()){
		grados = true;
		for (int i = 0; i < this->getCoeficientes().size(); ++i)
		{	
			if(this->getCoeficiente(i) == poli.getCoeficiente(i)){
				elementosIguales = true;	
			}else{
				elementosIguales = false;
				break;
			}
		}
	}else{
		grados = false;
	}

	if(grados && elementosIguales){
		return false;
	}else{
		return true;
	}

}

int Polinomio::operator()(){

	int menor = this->getCoeficiente(0);
	for (int i = 0; i < this->getCoeficientes().size(); ++i){
		if(this->getCoeficiente(i)<=menor){
			menor = this->getCoeficiente(i);
		}
	}
	for (int i = 0; i < this->getCoeficientes().size(); ++i){
		if(this->getCoeficiente(i)%menor!= 0){
			return 1;
		}
	}

	return menor;



}






string Polinomio::toString(){
	stringstream ss;
	int grado = this->getGrado();
	for (int i = 0; i < this->coeficientes.size(); ++i){
		ss<<this->coeficientes.at(i)<<"x^"<<i<<"+";
	}
	return ss.str();

} 	


void Polinomio::imprimir(Polinomio vec){
	cout<<"Imprimiendo"<<endl;
	for (int i = 0; i < vec.getCoeficientes().size(); ++i){
		cout<<vec.getCoeficiente(i)<<" , ";	
	}
	cout<<endl;
}
