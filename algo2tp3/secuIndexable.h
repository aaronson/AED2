
/**
 * Cambio en el TP. Modularizamos el arreglo redimensionable con Francisco
 **/

#ifndef SECUINDEXABLE_H
#define SECUINDEXABLE_H

//REQUIERE que T tenga:
// operator=
// constructor por default.
template<class T>
class SecuIndexable {
	public:
		//Crea una secuencia indexable vacia
		SecuIndexable();
		~SecuIndexable();

		SecuIndexable(const SecuIndexable<T>&);
		SecuIndexable<T>& operator=(const SecuIndexable<T>&);
		
		void agregarAtras(const T& elem);
		
		const T& operator[](unsigned int i) const;
		T& operator[](unsigned int i);
		
		unsigned int tamanio() const;
	
	private:
		T* arreglo;
		unsigned int espacio;
		unsigned int ultimo;
};

template<class T>
SecuIndexable<T>::SecuIndexable() {
	arreglo = NULL;
	espacio = ultimo = 0;
}
		
template<class T>
SecuIndexable<T>::~SecuIndexable() {
	delete [] arreglo;	
}

template<class T>		
SecuIndexable<T>::SecuIndexable(const SecuIndexable<T>& other) {
	arreglo = NULL;
	*this = other;
}

template<class T>		
SecuIndexable<T>& SecuIndexable<T>::operator=(const SecuIndexable<T>& other) {
	if(this == &other) return *this;
	
	delete [] arreglo;
	arreglo = NULL;
	espacio = ultimo = 0;
	//unsigned int n = other.tamanio();
	for(unsigned int i = 0; i < other.tamanio(); ++i) {
		agregarAtras(other.arreglo[i]);
	}
	return *this;
}


template<class T>		
void SecuIndexable<T>::agregarAtras(const T& elem) {
	if(ultimo == espacio) {
		T* old_arreglo = arreglo;
		if(espacio == 0) espacio = 1; else espacio *= 2;
		arreglo = new T[espacio];
		for(unsigned int i = 0; i < ultimo; ++i) {
			arreglo[i] = old_arreglo[i];
		}
		delete [] old_arreglo;
	}
	arreglo[ultimo] = elem;
	++ultimo;
}

template<class T>	
const T& SecuIndexable<T>::operator[](unsigned int i) const {
	return arreglo[i];
}

template<class T>
T& SecuIndexable<T>::operator[](unsigned int i) {
	return arreglo[i];
}
		
template<class T>		
unsigned int SecuIndexable<T>::tamanio() const {
	return ultimo;
}

#endif //SECUINDEXABLE_H
