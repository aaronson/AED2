#ifndef __MCONJ_H__
#define __MCONJ_H__

#include <iostream>
#include <cassert>
using namespace std;

#include "secu.h"
#include "defs.h"



template<class T>
class Mconj {
private:
    struct tuplamcj;  //forward declaration

public:

	Mconj();

	Mconj (const Mconj& otro);

	~Mconj(){};

	unsigned int cardinal (const T& e) const;

	bool vacio () const;

	void agregar(const T& e);  //aca van a hacer una copia.

	unsigned int cantElemDistintos() const;

	void mostrarMconj(ostream& out) const;

	Mconj<T>& operator=(const Mconj& mc);



	class iterador { //adaptado al iterador de secuencia
	public:

		bool hayMas() const;
		T& actual();
		void avanzar();
		void borrarActual();

	private:

		typename Secu<tuplamcj>::iterador it;
		iterador(Mconj<T>* c);
		friend iterador Mconj<T>::crearIt();
	};

	class const_iterador {
	public:

		bool hayMas() const;
		const T& actual() const;
		void avanzar();

	private:

		typename Secu<tuplamcj>::const_iterador it;
		const_iterador(const Mconj<T>* c);
		friend iterador Mconj<T>::crearIt() const;
	};

	iterador crearIt();
	const_iterador crearIt() const;

private:

    struct tuplamcj {
	    unsigned int cant;
	    T elem;
    };

	Secu<tuplamcj> sec;
};

template<class T>
Mconj<T>::Mconj(){}

template<class T>
Mconj<T>::Mconj(const Mconj& otro){
	typename Secu<tuplamcj>::const_iterador it = otro.sec.crearIt();
	while (it.hayMas()){
		this->sec.agregarAtras(it.actual());
		it.avanzar();
	}
}


template<class T>
Mconj<T>& Mconj<T>::operator=(const Mconj& mc){
    //typename Secu<tuplamcj>::const_iterador it = mc.sec.crearIt();
	//while (it.hayMas()){
		//this->sec.agregarAtras(it.actual());
		//it.avanzar();
	//}
	sec = mc.sec;
	return *this;
}


template<class T>
void Mconj<T>::mostrarMconj(ostream& out) const {
	out << "{";
	typename Secu<tuplamcj>::const_iterador it = this->sec.crearIt();
	//unsigned int i;
	while (it.hayMas()){
		out << "<" << it.actual().elem << "," << it.actual().cant << ">";
		it.avanzar();
	}
	out << "}";
}

template<class T>
ostream& operator<<(ostream& out, const Mconj<T>& c) {
        c.mostrarMconj(out);
        return out;
}

template<class T>
unsigned int Mconj<T>::cardinal(const T& e) const{
	typename Secu<tuplamcj>::const_iterador it = this->sec.crearIt();
	bool noencontro = true;
	unsigned int res = 0;
	while (it.hayMas() && noencontro){
		if ((it.actual().elem) == e){
			res = (it.actual().cant);
			noencontro = false;
		}
		it.avanzar();
	}
	return res;
}

template<class T>
bool Mconj<T>::vacio() const{
	return this->sec.vacia();
}

template<class T>
void Mconj<T>::agregar(const T& e){
	typename Secu<tuplamcj>::iterador it(this->sec.crearIt());
	bool noencontro = true;
	while (it.hayMas() && noencontro){
		if ((it.actual()).elem == e){
			(it.actual()).cant++;
			noencontro = false;
		}else{
		it.avanzar();
		}
	}
	if (noencontro){
		tuplamcj temp;
		temp.cant = 1;
		temp.elem = e;
		this->sec.agregarAtras(temp);
	}
}

template<class T>
unsigned int Mconj<T>::cantElemDistintos() const{
	typename Secu<tuplamcj>::const_iterador it = this->sec.crearIt();
	unsigned int res = 0;
	while (it.hayMas()){
		res++;
		it.avanzar();
	}
	return res;
}

template<class T>
typename Mconj<T>::iterador Mconj<T>::crearIt() {
	return typename Mconj<T>::iterador(this);
}

template<class T>
typename Mconj<T>::const_iterador Mconj<T>::crearIt() const {
	return typename Mconj<T>::const_iterador(this);
}

template<class T>
Mconj<T>::iterador::iterador(Mconj<T>* mcj) : it(mcj->sec.crearIt()) {
}

template<class T>
Mconj<T>::const_iterador::const_iterador(const Mconj<T>* mcj) : it(mcj->sec.crearIt()) {
}


template<class T>
T& Mconj<T>::iterador::actual(){
	return this->it.actual().elem;
}


template<class T>
const T& Mconj<T>::const_iterador::actual() const{
	return this->it.actual();
}

template<class T>
void Mconj<T>::iterador::avanzar(){
	this->it.avanzar();
}

template<class T>
void Mconj<T>::const_iterador::avanzar(){
	this->it.avanzar();
}

template<class T>
bool Mconj<T>::iterador::hayMas() const {
	return this->it.hayMas();
}

template<class T>
bool Mconj<T>::const_iterador::hayMas() const {
	return this->it.hayMas();
}
template<class T>
void Mconj<T>::iterador::borrarActual(){
	this->it.borrarActual();
}


#endif
