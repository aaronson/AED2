#ifndef __COLA_H__
#define __COLA_H__

#include <iostream>
#include <cassert>
using namespace std;


#include "secu.h"
#include "defs.h"




class Cola {
public:
    struct prioract;  //forward declaration
    class iterador;
    class const_iterador;

	Cola();
	
	Cola (const Cola& otro);
	
	~Cola(){};
	
	bool vacia() const;
	
	actividad proxima() const;
	
	unsigned int prioridad() const;
	
	Secu<unsigned int> ordenes(unsigned int t) const;
	
	bool esta(unsigned int t ) const;
	
	bool estaActiv (actividad a) const; //modificado del TP
	
	void sacarOrden (unsigned int t, unsigned int o);
	
	void encolar (unsigned int t, unsigned int o, unsigned int p); 
	
	void encolarSecuOrdenada (const Secu<activpriorizada>& s);
		
	iterador crearIt();
	const_iterador crearIt() const;
	
	void mostrarCola(ostream& out) const;


		class iterador {
	public:

		bool hayMas() const;
		prioract& actual();
		void avanzar();
		void borrarActual();

	private:
	
		Secu<prioract>::iterador it;
		iterador(Cola* c);
		friend Cola::iterador Cola::crearIt();
	};
	
	class const_iterador {
	public:

		bool hayMas() const;
		const prioract& actual() const;
		void avanzar();

	private:

		Secu<prioract>::const_iterador it;
		const_iterador(const Cola* c);
		friend Cola::const_iterador Cola::crearIt() const;
	};


	struct prioract{
		unsigned int tarea;
		unsigned int prioridad;
		Secu<unsigned int> ordenes;
	};

private:
	
	Secu<prioract> sec;
	
};

ostream& operator<<(ostream& out, const Cola& c);



#endif
