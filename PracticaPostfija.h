/*
Practica 1. Estructuras de datos linelaes
Autor: Giovanny Alexis Reyes Vilchis
Matricula: 2163031812
*/

#ifndef PRACTICAPOSFIJA_H
#define PRACTICAPOSFIJA_H
#include <string>

#include "PilaDinamica.h"

using namespace std;

//Prototipos de las funcioes
std::string infijatoPosfija(std::string infija);
int evaluarPosfija(std::string posfija);
int precedencia(char c);
int convierteAentero(char c);

//Desarrollo e implementación

std::string infijatoPosfija(std::string infija){
	string cadenaSalida;	//Cadena de salida
	int longitud = infija.length();	//Se obtiene la longitud de la expresion de entrada
	PilaDinamica<char> pilaOperadores;	//Pila dinamica
	
	//Se imprime la pila y la cadena de salida en un inicio (vacias)
	cout<<"\nConvirtiendo de infija a posfija..."<<endl;
	cout<<"Inicio!!!"<<endl;
	cout<<"Pila operadores: "<<pilaOperadores.toString3()<<endl;
	cout<<"Cadena de salida: "<<cadenaSalida<<endl<<endl;
	
	//Se usa el codigo ASCII en todas las condiciones para comparar los caracteres
	char x;
	for(int i=0; i<longitud; i++){	//Se evalua de izquierda a derecha
		x = infija[i];	//Se extrae el caracter de la expersion de entrada
		if(x >= 48 && x <= 57 /*|| x >= 97 && x <= 122*/) //Usando el codigo ASCII se sacan los operandos de la pila entre 0 y 9
			cadenaSalida+=x;	//Si el caracter es un numero se concatena a la cadena de salida
		else if(x == 40){	//Si el caracter es un parentesis izquierdo
			pilaOperadores.push(x);	//Se hace push metiendo en la pila ese parentesis izquierdo
		}
		else if(x == 41){	//Si el caracter es un parentesis derecho
			while(pilaOperadores.getTope() != 40){	//Mientras no encontremos el parentesis izquierdo
				cadenaSalida+=pilaOperadores.getTope();	//Se concatena el tope de la pila en la cadena de salida o lo que es extraemos los operadores entre los parentesis
				pilaOperadores.pop();	//Se hace pop ya que guardamos el caracter
			}
			if(pilaOperadores.getTope() == 40){	//Si es que se encontrara el parentesis izquierdo
				pilaOperadores.pop();	//Se hace pop en la pila para eliminarlo ya que los parentesis no se utilizan en la expresion posfija
			}
		}
		else if(x == 42 || x == 47 || x == 43 || x == 45){	//Si el carcater es un operador de : * / + - y usando el codigo ASCII
			if(pilaOperadores.esVacia()){	//Si la pila estuviera vacia
				pilaOperadores.push(x);		//Solo se hace push del operador
			}
			else if(precedencia(pilaOperadores.getTope()) >= precedencia(x)){ 	//Si no es vacia se revisa si la prioridad del operador de la pila es mayor o igual que el que vamos a introducir
				cadenaSalida+=pilaOperadores.getTope();	//De ser asi se concatena el operador al final de la cadena de salida
				pilaOperadores.pop();	//Se hace pop para eliminar ese operador
				pilaOperadores.push(x);	//Y se hace push del nuevo operador a introducir
			}
			else{	//Si no es vacia y la prioridad del nuevo operador es mayor que el de la pila
				pilaOperadores.push(x);	//Solo se hace push metiendolo en la pila
			}
		}
		cout<<"Iteracion: "<<i+1<<endl;	//En todo momento se imprime la iteracion en que se va
		if(x == 32){	//Si el caracter es un espacio solo se ignora especifiando con un mensaje
			cout<<"El caracter es un espacio por lo tanto en esta iteracion solo se ignora"<<endl<<endl;
		}
		else{
			//Si no, se imprime la pila, el tope actual y la cadena de salida
			cout<<"Pila operadores: "<<pilaOperadores.toString3()<<endl;
			if(!pilaOperadores.esVacia()){
				cout<<"Tope actual: "<<pilaOperadores.getTope()<<endl;
			}
			cout<<"Cadena de salida: "<<cadenaSalida<<endl<<endl;
		}
	}
	//Despues de que se halla terminado de leer la cadena
	//Al final hay que verificar que no se quedo algun operador en la pila
	cout<<"Se termino de leer la cadena..."<<endl<<endl;
	while(!pilaOperadores.esVacia()){	//Mientras no este vacia
		if(pilaOperadores.getTope() != 40){	//Si es diferente de un parentesis izquierdo
			cadenaSalida+=pilaOperadores.getTope();	//Se concatena el caracter que se encuentre en el tope
			pilaOperadores.pop();	//Y se hace pop para eliminarlo
		}
		else{	//Si no entonces
			pilaOperadores.pop();	//Solo eliminamos el parentesis haciendo pop	
		}
		//Hasta que la pila se vacie se imprime la pila, el tope actual y la cadena de salida
		cout<<"Vaciando la pila: "<<endl;
		cout<<"Pila operadores: "<<pilaOperadores.toString3()<<endl;
		if(!pilaOperadores.esVacia()){
			cout<<"Tope actual: "<<pilaOperadores.getTope()<<endl;
		}
		cout<<"Cadena de salida: "<<cadenaSalida<<endl<<endl;
	}
	
	return cadenaSalida;	//Se regresa la cadena de salida o lo que es la notacion posfija
}

int evaluarPosfija(std::string posfija){
	PilaDinamica<int> pilaOperandos;	//Pila dinamica
	int longitud = posfija.length();	//Se obtiene la longitud de la expresion de entrada
	
	//Se imprime la pila en un inicio (vacia)
	cout<<"\n\nEvaluando la expresion posfija..."<<endl;
	cout<<"Inicio!!!"<<endl;
	cout<<"Pila operandos: "<<pilaOperandos.toString3()<<endl<<endl;
	
	//Se usa el codigo ASCII en todas las condiciones para comparar los caracteres
	char x;
	int a=0, b=0, res=0;	//Se inicializan tres variables para guardar el primer, segundo operador y el resultado
	for(int i=0; i<longitud; i++){	//Se evalua de izquierda a derecha
		x = posfija[i];	//Se extrae el carcater de la expresion de entrada
		if(x >= 48 && x <= 57){		//Usando el codigo ASCII se sacan los operandos de la pila entre 0 y 9
			pilaOperandos.push(convierteAentero(x));	//De ser asi se hace push del operando y se llama al metodo de convertir a entero para meter el valor como int
		}
		else{	//En caso de que sea un operador
			switch(x){	//Se realizo un switch para obtener el tipo de operador y en cada caso se evaluara la operacion correspondiente
				case 42:	//Caso en que se realiza la multiplicacion
					b = pilaOperandos.getTope();	//Se obtiene el segunbdo operando
					pilaOperandos.pop();	//Se hace pop en la pila para eliminar el elemento que acabamos de sacar
					a = pilaOperandos.getTope();	//Se obtiene el primer operando
					pilaOperandos.pop();	//De igual manera se realiza un pop para este operando
					res = a*b;	//Se realiza la operacion y se guarda el resultado
					pilaOperandos.push(res);	//Se hace push del resultado en la pila operandos
					break;
				case 47:	//Caso en que se realiza la division
					b = pilaOperandos.getTope();	//Se obtiene el segundo operando
					pilaOperandos.pop();	//Se hace pop en la pila para eliminar el elemento que acabamos de sacar
					a = pilaOperandos.getTope();	//Se obtiene el primer operando
					pilaOperandos.pop();	//De igual manera se realiza un pop para este operando
					res = a/b;	//Se realiza la operacion y se guarda el resultado
					pilaOperandos.push(res);	//Se hace push del resultado en la pila operandos
					break;
				case 43:	//Caso en que se realiza la suma
					b = pilaOperandos.getTope();	//Se obtiene el segunbdo operando
					pilaOperandos.pop();	//Se hace pop en la pila para eliminar el elemento que acabamos de sacar
					a = pilaOperandos.getTope();	//Se obtiene el primer operando
					pilaOperandos.pop();	//De igual manera se realiza un pop para este operando
					res = a+b;	//Se realiza la operacion y se guarda el resultado
					pilaOperandos.push(res);	//Se hace push del resultado en la pila operandos
					break;
				case 45:	//Caso en que se realiza la resta
					b = pilaOperandos.getTope();	//Se obtiene el segunbdo operando
					pilaOperandos.pop();	//Se hace pop en la pila para eliminar el elemento que acabamos de sacar
					a = pilaOperandos.getTope();	//Se obtiene el primer operando
					pilaOperandos.pop();	//De igual manera se realiza un pop para este operando
					res = a-b;	//Se realiza la operacion y se guarda el resultado
					pilaOperandos.push(res);	//Se hace push del resultado en la pila operandos
					break;
				default:
					break;
			}
			cout<<"Resultado de la operacion en esta iteracion: "<<res<<endl<<endl;	//Se imprime el resultado de la operacion que se realice en alguna iteracion
		}
		//En todo momento se imprime la iteracion en que se va, la pila, el tope actual
		cout<<"Iteracion: "<<i+1<<endl;
		cout<<"Pila operandos: "<<pilaOperandos.toString()<<endl;
		if(!pilaOperandos.esVacia()){
			cout<<"Tope actual: "<<pilaOperandos.toString()<<endl<<endl;
		}		
	}
	//Despues de terminar de evaluar la expresion
	int resFinal = pilaOperandos.getTope();	//Sacamos el resultado alojado en la pila
	pilaOperandos.pop();	//Y lo eliminamos
	
	return resFinal;	//Se regresa el resultado de la expresion posfija
}

int precedencia(char c){
	//Regresa el valor de prioridad más alta (2). Asumimos tenemos sólo dos jerarquías
	if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

int convierteAentero(char c){
	int convertido;
	convertido = (int)c - 48;
	
	return convertido;
}

#endif
