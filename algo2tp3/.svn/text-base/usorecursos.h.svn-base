#ifndef __USOREC_H__
#define __USOREC_H__

#include <iostream>
#include <cassert>
using namespace std;

#include "mconj.h"
#include "conj.h"


typedef Mconj<unsigned int> recursos;


class Usorecursos{

public:

	struct record;
	struct rec;

	Usorecursos(); //Este constructor solo lo ponemos para que no de error al construir una planta por
	//default

	~Usorecursos();

	Usorecursos(recursos rs); //Este es el generador "generar" del TP

	unsigned int tiposDeRecurso() const;

	unsigned int verTotal (unsigned int r) const;

	unsigned int disponibilidad (unsigned int r) const; //Modificado el nombre para que no entre
	// en conflicto, nombre original: disponible

	void nuevoConsumo (unsigned int r, unsigned int n);

	unsigned int menorConsumo () const;

	void actualizarConsumo (recursos r);

	void actualizarUso (unsigned int* ar);

	bool alcanzanLosRecursos (recursos r) const;

	recursos multiconjuntizar() const;

	recursos disponiblesEnMulticonj() const;

	Usorecursos& operator=(Usorecursos& u);



	struct rec{
		unsigned int total;
		unsigned int disponible;
		unsigned int orden;
	};

	struct record{
		unsigned int recurso;
		unsigned int disponible;
	};

private:

	void heapify(record ao[], int i, rec ar[], unsigned int n);


	rec* status;
	record* ordenesConsumo;
	unsigned int cantRecursos;
};




#endif
