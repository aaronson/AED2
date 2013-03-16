#ifndef __SECU_H__
#define __SECU_H__

#include <iostream>
#include <cassert>
using namespace std;

#include "defs.h"


template<class T>
class Secu {
private:
	struct Nodo;
public:

	Secu(); //Constructor vacia

    Secu(const Secu& otra);

    ~Secu();

	bool esta(const T& e) const;

	const T& prim() const;

	void fin();

	bool vacia() const; //No pusimos el ? porque no es soportado, la funcion original es vacia?

	void agregarAdelante (const T& e);

	void agregarAtras (const T& e);

	void mostrarSecu(ostream& out, bool interno = true) const;

	unsigned int tamanio () const;

	Secu<T>& operator=(const Secu<T>& s);


	class iterador {
	public:

		bool hayMas() const;
		T& actual();
		void avanzar();
		void agregarAtrasDeIt (const T& e);
		void agregarAdelanteDeIt(const T& e);
		void retrocederAlPrincipio ();
		void borrarActual();

	private:

		Nodo* posic;
		Secu<T>* sec;

		iterador(Secu<T>* s);

		friend iterador Secu<T>::crearIt();
	};

	class const_iterador {
	public:
		bool hayMas() const;
		const T& actual() const;
		void avanzar();
		void retrocederAlPrincipio();

	private:
		const Nodo* posic;
		const Secu<T>* sec;

		const_iterador(const Secu<T>* s);

		friend const_iterador Secu<T>::crearIt() const;
	};

	iterador crearIt();
	const_iterador crearIt() const;

private:

	struct Nodo {
        Nodo(const T &e) : dato(e) {};
        T dato;
        Nodo* prox;
        Nodo* ant;
    };

	Nodo* primero;
 	Nodo* ultimo;


};

template<class T>
Secu<T>::Secu(){
	this->primero = NULL;
	this->ultimo = NULL;

}

template<class T>
Secu<T>::Secu(const Secu& otra){
	this->primero=NULL;
    this->ultimo=NULL;
	iterador it(crearIt());
	typename Secu<T>::Nodo* temp;
	temp = otra.primero;
	while (temp != NULL){
		it.agregarAtrasDeIt(temp->dato);
		temp = temp->prox;
	}
}

template<class T>
Secu<T>::~Secu(){
	iterador it(crearIt());
	while (it.hayMas()){
		it.borrarActual();
	}
}

template<class T>
void Secu<T>::mostrarSecu(ostream& out, bool interno) const{
    if(interno) out << "[";
    unsigned int i=0;
    typename Secu<T>::Nodo* temp;
    temp= this->primero;
    unsigned int tam = tamanio();
    while (i < tam){
        out << temp->dato;
        if(i < tam-1) out << ",";
        temp = temp->prox;
        i++;
    }
    if(interno) out << "]";
}

template<class T>
ostream& operator<<(ostream& out, const Secu<T>& s) {
        //s.mostrarSecu(out, true);
        s.mostrarSecu(out);
        return out;
}

template<class T>
Secu<T>& Secu<T>::operator=(const Secu<T>& s) {
	if(this == &s) return *this;
	while(!vacia()) fin();

    typename Secu<T>::const_iterador it = s.crearIt();
    while(it.hayMas()) {
    	agregarAtras(it.actual());
    	it.avanzar();
	}
    return *this;
}

template<class T>
unsigned int Secu<T>::tamanio() const{
	unsigned int count=0;
	typename Secu<T>::Nodo* temp = this->primero;
	while(temp!=NULL){
		temp = temp->prox;
		count++;
	}

    return count;
}

template<class T>
bool Secu<T>::esta(const T& e) const {
	bool res = false;
	const_iterador it = crearIt();
	while (it.hayMas() && !(res)){
		res = (e == it.actual());
		it.avanzar();
	}
	return res;
}

template<class T>
const T& Secu<T>:: prim() const{
	return this->primero->dato;
}

template<class T>
void Secu<T>::fin(){
	typename Secu<T>::Nodo* temp = this->primero;
	this->primero = this->primero->prox;
	if (this->primero != NULL){
		this->primero->ant = NULL;
	}else{
		this->ultimo = NULL;
	}
	delete temp;
}

template<class T>
bool Secu<T>::vacia() const{
	return (this->primero == NULL);
}

template<class T>
void Secu<T>::agregarAdelante (const T& e){
	typename Secu<T>::Nodo* nuevo = new typename Secu<T>::Nodo(e);
	if (vacia()){
		nuevo->prox = this->primero;
		nuevo->ant = NULL;
		this->primero = nuevo;
		this->ultimo = nuevo;
	}else{
		this->primero->ant = nuevo;
		nuevo->prox = this->primero;
		nuevo->ant = NULL;
		this->primero = nuevo;
	}
}

template<class T>
void Secu<T>::agregarAtras (const T& e){
	typename Secu<T>::Nodo* nuevo = new typename Secu<T>::Nodo(e);
	if (vacia()){
		nuevo->prox = NULL;
		nuevo->ant = this->ultimo;
		this->ultimo = nuevo;
		this->primero = nuevo;
	}else{
		this->ultimo->prox = nuevo;
		nuevo->prox = NULL;
		nuevo->ant = this->ultimo;
		this->ultimo = nuevo;
	}
}

//ITERADOR

template<class T>
typename Secu<T>::iterador Secu<T>::crearIt() {
	return typename Secu<T>::iterador(this);
}

template<class T>
typename Secu<T>::const_iterador Secu<T>::crearIt() const {
	return typename Secu<T>::const_iterador(this);
}

template<class T>
T& Secu<T>::iterador::actual(){
	return this->posic->dato;
}


template<class T>
const T& Secu<T>::const_iterador::actual() const{
	return this->posic->dato;
}


template<class T>
bool Secu<T>::iterador::hayMas() const{
	return (this->posic != NULL);
}

template<class T>
bool Secu<T>::const_iterador::hayMas() const{
	return (this->posic != NULL);
}


template<class T>
void Secu<T>::iterador::avanzar(){
	this->posic = this->posic->prox;
}

template<class T>
void Secu<T>::const_iterador::avanzar(){
	this->posic = this->posic->prox;
}


template<class T>
void Secu<T>::iterador::agregarAtrasDeIt(const T& e){
	typename Secu<T>::Nodo* nuevo = new typename Secu<T>::Nodo(e);
	if (this->sec->primero == NULL){
		nuevo->prox = nuevo->ant = NULL;
		this->sec->primero = this->sec->ultimo = nuevo;
		this->posic = nuevo;
	}else if (this->posic == this->sec->ultimo){
		nuevo->ant = this->sec->ultimo;
		this->sec->ultimo->prox = nuevo;
		this->sec->ultimo = nuevo;
		nuevo->prox = NULL;
		this->posic = nuevo;
	}else{
		nuevo->prox = this->posic->prox;
		nuevo->ant = this->posic;
		nuevo->prox->ant = nuevo;
		nuevo->ant->prox = nuevo;
		this->posic = nuevo;
	}

}

template<class T>
void Secu<T>::iterador::agregarAdelanteDeIt(const T& e){
	typename Secu<T>::Nodo* nuevo = new typename Secu<T>::Nodo(e);
	if (this->sec->primero == NULL){
		nuevo->prox = nuevo->ant = NULL;
		this->sec->primero = this->sec->ultimo = nuevo;
		this->posic = nuevo;
	}else if (this->posic == this->sec->primero){
		nuevo->prox = this->sec->primero;
		this->sec->primero->ant = nuevo;
		this->sec->primero = nuevo;
		nuevo->ant = NULL;
		this->posic = nuevo;
	}else{
		nuevo->prox = this->posic;
		nuevo->ant = this->posic->ant;
		nuevo->prox->ant = nuevo;
		nuevo->ant->prox = nuevo;
		this->posic = nuevo;
	}

}

template<class T>
void Secu<T>::iterador::retrocederAlPrincipio (){
	this->posic = this->sec->primero;
}

template<class T>
void Secu<T>::const_iterador::retrocederAlPrincipio (){
	this->posic = this->sec->primero;
}


template<class T>
void Secu<T>::iterador::borrarActual (){
	if (this->sec->primero != NULL){
		typename Secu<T>::Nodo* borrador = this->posic;
		if (this->posic == this->sec->primero){
			this->sec->primero = this->posic->prox;
			if (this->sec->primero == NULL){
				this->posic = NULL;
				this->sec->ultimo = NULL;
			}else{
				this->posic->prox->ant = NULL;
				this->posic = this->posic->prox;
			}
		}else if(this->posic == this->sec->ultimo){
			this->sec->ultimo = this->posic->ant;
			this->posic->ant->prox = NULL;
			this->posic = NULL;
		}else{
			this->posic->prox->ant = this->posic->ant;
			this->posic->ant->prox = this->posic->prox;
			this->posic = this->posic->prox;
		}
	delete borrador;
	}
}


template<class T>
Secu<T>::iterador::iterador(Secu<T>* s) {
    posic = s->primero;
	this->sec = s;
}

template<class T>
Secu<T>::const_iterador::const_iterador(const Secu<T>* s) {
	posic = s->primero;
	this->sec = s;
}

//bool operator==(const actividad a, const actividad b){
	//return a.orden == b.orden && a.tarea == b.tarea;
//}

#endif
