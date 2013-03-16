#ifndef __WORKFLOW_H__
#define __WORKFLOW_H__

#include <iostream>
#include <cassert>
using namespace std;

#include "secu.h"
#include "conj.h"
#include "mconj.h"
#include "secuIndexable.h"

typedef Mconj<unsigned int> recursos;

struct tuplaTarea{
	unsigned int prioridad;
	Conj<unsigned int> preds;
	unsigned int cantPred;
	recursos recs;
};


class Workflow{

public:

	Workflow(); //Este constructor solo lo ponemos para que no de error al construir una planta por
	//default

	Workflow(unsigned int p, const recursos& r); //Este es el generador nuevo

	~Workflow();

	Conj<unsigned int> dametareas() const; //Modificado el nombre para que no entre en conflicto
	//nombre original: tareas

	const recursos& consumo(unsigned int t) const;

	const Conj<unsigned int>& predecesoras(unsigned int t) const;

	unsigned int prioridad(unsigned int t) const;

	void agTarea(unsigned int p, const recursos& r, const Conj<unsigned int>& ps);
	// modularizada con Francisco

	//Conj<unsigned int> finales() const; Sacadas por correccion en el TP (no eran necesarias)

	//Conj<unsigned int> sucesoras() const;

	unsigned int cantPredecesoras(unsigned int t) const;

	unsigned int cantidadTareas() const;  //Modificado el nombre para que no entre en conflicto

	Workflow& operator=(const Workflow& w);


private:

	SecuIndexable<tuplaTarea*> tareas;
};

#endif
