
template <typename E>
class Nodo{
	private:
		E elemento;
		Nodo<E> *siguiente;
	public:
		Nodo(); //Constructor vacío
		Nodo(E elemento, Nodo<E> *sig); //Constructor: Inicializa el dato y a quien apunta
		Nodo<E> *getSiguiente(); //Regresa el siguiente al que apunta
		void setSiguiente(Nodo<E> *sig);
		E getElemento(); //Devuelve el elemento deseado;
};

//Constructor vacío
template <typename E>
Nodo<E>::Nodo(){
	siguiente=NULL;
}

//Constructor con carga de atributos
template <typename E>
Nodo<E>::Nodo(E ele, Nodo<E> *sig){
	elemento=ele;
	siguiente=sig;
}

template <typename E>
Nodo<E> *Nodo<E>::getSiguiente(){
	return siguiente;
}

template <typename E>
void Nodo<E>::setSiguiente(Nodo<E> *sig){
	siguiente=sig;
}

template <typename E>
E Nodo<E>::getElemento(){
	return elemento;
}

