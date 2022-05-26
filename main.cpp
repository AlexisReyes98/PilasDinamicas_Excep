#include <iostream>
#include <string.h>

#include "PracticaPostfija.h"

int main(){
	try{
		string expresion="";
		cout<<"Bienvenid@!!!"<<endl;
		cout<<"Practica 1: Alicaciones de pilas"<<endl;
		cout<<"Conversion de una notacion infija a posfija..."<<endl;
		cout<<"Escribe tu expresion sin espacios, ej. 2-3+4-(3*5)+8 : ";
		getline(cin,expresion);	//Se lee la expresion introducida
		
		string salida = infijatoPosfija(expresion);
		
		cout<<"     Notacion postfija: "<<salida;
		
		int res = evaluarPosfija(salida);
		cout<<"		El resultado de la expresion es: "<<res;
	}
	catch (ExcepcionEjecucion& e){
		cout<<e.getError()<<endl;
	}
	
	return 0;
}

