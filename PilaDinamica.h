#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

class ExcepcionEjecucion{
	private:
		std::string mensajeError;
	public:
		ExcepcionEjecucion(const std::string& err){
			mensajeError="El error es: "+err+"\n"; //Se crea un mensaje de error + es para concatenar
		}
		std:: string getError() const {
			return mensajeError;
		}
};

class ExcepcionPilaVacia: public ExcepcionEjecucion{
	public:
		ExcepcionPilaVacia(const std::string& err) 
		: ExcepcionEjecucion(err){}
};

class ExcepcionPilaLlena: public ExcepcionEjecucion{
	public:
		ExcepcionPilaLlena(const std::string& err) 
		: ExcepcionEjecucion(err){}
};

template <typename E>
class PilaDinamica{
	private:
		Nodo<E> *tope;
		int numElementos;
	public:
		PilaDinamica(); //Constructor
		~PilaDinamica(); //Destructor
		void push(E x) throw (ExcepcionPilaLlena); //Ingresa elementos en el tope de la pila
		void pop() throw (ExcepcionPilaVacia) ;
		E getTope() const throw (ExcepcionPilaVacia);
		bool esVacia() const;
		int getTamanio() const;
		std::string toString() const;
		std::string toString2() const;
		std::string toString3() const;
};

//Constructor: Inicializa por primera vez la Pila
template <typename E>
PilaDinamica<E>::PilaDinamica(){
	tope=NULL;
	numElementos=0;
}

template <typename E>
PilaDinamica<E>::~PilaDinamica(){
	while(!esVacia()){
		pop();
	}
}

template <typename E>
void PilaDinamica<E>::push(E elemento) throw (ExcepcionPilaLlena) {
	//Crear un nuevo nodo en memoria
	//Nodo<E> *nuevo = new Nodo<E>(elemen, NULL ) //Si está vacía
	Nodo<E> *nuevo = new Nodo<E>(elemento,tope); //Si ya hay al menos un elemento, se crea el nodo y el siguient
	//es el tope actual
	tope=nuevo;
	numElementos++; //numElementos=numElementos+1;
}

template <typename E>
void PilaDinamica<E>:: pop() throw (ExcepcionPilaVacia){
	if(esVacia()){
		throw ExcepcionPilaVacia("Eliminando de una pila vacia");
	}
		Nodo<E> *aux=tope;
		tope=tope->getSiguiente();
		//Faltan dos cosas
		delete aux;
		numElementos--;
}

template <typename E>
E PilaDinamica<E> :: getTope() const throw (ExcepcionPilaVacia){
	if(esVacia()){
		throw ExcepcionPilaVacia("Regresando elemento de una pila vacia");
	}
	return tope->getElemento();
}

template <typename E>
bool PilaDinamica<E>::esVacia() const {
	bool vacia=false;
	if(numElementos==0)
		vacia=true;
	return vacia;
	//return (numElementos == 0);
}

template <typename E>
int PilaDinamica<E>::getTamanio() const{
	return numElementos;
}

template <typename E>
std::string PilaDinamica<E>::toString() const{
	std:string salida ="[";
	Nodo<E> *p= tope;
	while(p != NULL){
		if(p->getSiguiente() ==NULL){
		salida +=std::to_string(p->getElemento());
		}
		else{
		  salida +=std::to_string(p->getElemento())+", ";
		}
		p=p->getSiguiente();
	}
	salida+="]";
	
	return salida;
}

template <typename E>
std::string PilaDinamica<E>::toString2() const{
	std:string salida ="[";
	Nodo<E> *p= tope;
	while(p != NULL){
		salida +=std::to_string(p->getElemento())+", ";
	  	p=p->getSiguiente();
	}
	if(!esVacia()){
		//Quitamos la última coma
		salida.pop_back();
		salida.pop_back();
	}
	salida+="]";
	
	return salida;
}

template <typename E>
std::string PilaDinamica<E>::toString3() const{
	std:string salida ="[";
	Nodo<E> *p= tope;
	while(p != NULL){
		if(p->getSiguiente() ==NULL){
			salida += p->getElemento();
		}
		else{
		  salida += p->getElemento();
		  salida += ",";
		}
		p=p->getSiguiente();
	}
	salida+="]";
	
	return salida;
}

