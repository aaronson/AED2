#ifndef __CONJ_H__
#define __CONJ_H__
#include "secu.h"
#include "defs.h"
#include <iostream>
#include <cassert>
using namespace std;



template<class T>
class Conj {
public:

	Conj();

	Conj (const Conj& otro);

	~Conj();

	bool pertenece (const T& e) const;

	bool vacio () const;

	unsigned int cardinal() const; //agregada para ayudar el manejo de conjuntos

	void agregar(const T& e);

	void sacar(const T& e);

	void unir (Conj& otro); //cambiado el nombre, funcion original: union

	void mostrarConj(ostream& out) const;

	Conj<T>& operator=(const Conj& c);

	const T& dameuno (); /*Esta funcion no esta en el TP de diseño, ni esta pensada para ser usada,
	la agregamos simplemente para ayudarnos a mostrar conjuntos de templates que no tienen definidos
	un ostream particular */


	class iterador { //adaptado al iterador de secuencia
	public:

		bool hayMas() const;
		T& actual();
		void avanzar();
		void borrarActual();


	private:

		typename Secu<T>::iterador it;

		iterador(Conj<T>* c);

		friend iterador Conj<T>::crearIt();
	};

	class const_iterador {
	public:

		bool hayMas() const;
		const T& actual() const;
		void avanzar();

	private:

		typename Secu<T>::const_iterador it;

		const_iterador(const Conj<T>* c);

		friend const_iterador Conj<T>::crearIt() const;
	};

	const_iterador crearIt() const;
	iterador crearIt();

private:

	Secu<T> sec;

};

template<class T>
Conj<T>::Conj(){}

template<class T>
Conj<T>::Conj(const Conj& otro){
	typename Secu<T>::const_iterador it = otro.sec.crearIt();
	while (it.hayMas()){
		this->sec.agregarAtras(it.actual());
		it.avanzar();
	}
}

template<class T>
Conj<T>& Conj<T>::operator=(const Conj& c) {
    //typename Secu<T>::const_iterador it = c.sec.crearIt();
	//while (it.hayMas()){
		//this->sec.agregarAtras(it.actual());
		//it.avanzar();
	//}
	sec = c.sec;
	return *this;
}



template<class T>
Conj<T>::~Conj(){}

template<class T>
void Conj<T>::mostrarConj(ostream& out) const{
	out << "{";
	this->sec.mostrarSecu(out, false);
	out << "}";
}

template<class T>
ostream& operator<<(ostream& out, const Conj<T>& c) {
        c.mostrarConj(out);
        return out;
}

template<class T>
bool Conj<T>::pertenece(const T& e) const{
	return this->sec.esta(e);
}

template<class T>
bool Conj<T>::vacio() const{
	return this->sec.vacia();
}

template<class T>
unsigned int Conj<T>::cardinal() const{
	return this->sec.tamanio();
}

template<class T>
void Conj<T>::agregar(const T& e){
	if (!pertenece(e)){
		this->sec.agregarAdelante(e);
	}
}

template<class T>
void Conj<T>::sacar(const T& e){
	typename Secu<T>::iterador it(this->sec.crearIt());
	bool queda = true;
	while (it.hayMas() && queda){
		if (it.actual() == e){
			it.borrarActual();
			queda = false;
		}
		it.avanzar();
	}
}

template<class T>
void Conj<T>::unir (Conj& otro){
	typename Secu<T>::iterador it(otro.sec.crearIt());
	while (it.hayMas()){
		if (!this->sec.esta(it.actual())){
			this->sec.agregarAdelante(it.actual());
		}
		it.avanzar();
	}
}

template<class T>
typename Conj<T>::iterador Conj<T>::crearIt() {
	return typename Conj<T>::iterador(this);
}

template<class T>
typename Conj<T>::const_iterador Conj<T>::crearIt() const {
	return typename Conj<T>::const_iterador(this);
}


template<class T>
Conj<T>::iterador::iterador(Conj<T>* cj):it(cj->sec.crearIt()){
}

template<class T>
Conj<T>::const_iterador::const_iterador(const Conj<T>* cj):it(cj->sec.crearIt()) {
}

template<class T>
T& Conj<T>::iterador::actual(){
	return this->it.actual();
}

template<class T>
const T& Conj<T>::const_iterador::actual() const{
	return this->it.actual();
}

template<class T>
void Conj<T>::iterador::avanzar(){
	this->it.avanzar();
}

template<class T>
void Conj<T>::const_iterador::avanzar(){
	this->it.avanzar();
}

template<class T>
bool Conj<T>::iterador::hayMas() const{
	return this->it.hayMas();
}

template<class T>
bool Conj<T>::const_iterador::hayMas() const{
	return this->it.hayMas();
}


template<class T>
void Conj<T>::iterador::borrarActual(){
	this->it.borrarActual();
}

template<class T>
const T& Conj<T>::dameuno (){
	T temp = sec.prim();
	sec.fin();
	return temp;
}

#endif
