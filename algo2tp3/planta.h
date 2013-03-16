#ifndef __PLANTA_H__
#define __PLANTA_H__

#include <iostream>
#include <cassert>
using namespace std;

#include "secu.h"
#include "conj.h"
#include "mconj.h"
#include "defs.h"
#include "cola.h"
#include "workflow.h"
#include "usorecursos.h"



typedef Mconj<unsigned int> recursos;

class Planta{
public:

	~Planta();
	Planta(const Workflow& w, const recursos& r); //Este es el generador crear del TPD
	Workflow verWorkflow () const; //Modificado el nombre para que no entre
	// en conflicto, nombre original: workflow
	recursos verRecursos () const; //Modificado el nombre para que no entre
	// en conflicto, nombre original: recursos
	Cola enEspera() const;
	Conj<actividad> enEjecucion() const;
	Conj<actividad> finalizadas() const;
	void agOrden(unsigned int o);
	void terminar(actividad a);
	Conj<actividad> actividades() const;
	Conj<unsigned int> verOrdenes() const; //Modificado el nombre para que no entre
	// en conflicto, nombre original: ordenes
	Conj<unsigned int> ordenesFinalizadas() const;
	recursos disponibles() const;
	unsigned int consumoDeRecurso (unsigned int r) const;
	unsigned int menorConsumo() const;

	struct estado{
		bool termino;
		unsigned int predPendientes;
	};


	struct ordtars{
		unsigned int orden;
		estado* tareas;
	};


private:
	struct priotar;

	void heapifyP (priotar ap[], int i, unsigned int n) const; //Modificado el nombre para que no entre
	// en conflicto, nombre original: heapifysssss
	unsigned int* recursosAArreglo () const ;
	bool mconjIncluidoEnArreglo(unsigned int r[], const recursos& mcj) const;
	void actualizarArreglo(unsigned int r[], const recursos& mcj, bool sumar) const;
	bool terminoOrden (const estado* at, unsigned int n) const;


	Usorecursos recs;
	Workflow wkf;
	Secu<ordtars> terminadas;
	Cola esperando;
	Secu<unsigned int>* sucesores;

	struct priotar{
		unsigned int tarea;
		unsigned int prioridad;
	};

};











#endif
