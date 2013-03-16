#include "workflow.h"


Workflow::Workflow(){}	


Workflow::Workflow(unsigned int p, const recursos& r){
	tuplaTarea* tp = new tuplaTarea;
	tp->prioridad = p;
	tp->recs = r;                    //estamos copiando
	tp->cantPred = 0;
	//tp,preds se inicializo en vacio
	tareas.agregarAtras(tp);
}


Workflow::~Workflow(){
	for(unsigned int i = 0; i < tareas.tamanio(); ++i) {
		delete tareas[i];	
		tareas[i] = NULL;
	}
}

Conj<unsigned int> Workflow::dametareas() const{
	Conj<unsigned int> res;
	unsigned int ct = tareas.tamanio();
	for(unsigned int n = 0; n < ct; ++n){
		res.agregar(n);
	}
	return res;
}

const recursos& Workflow::consumo(unsigned int t) const{
	return tareas[t]->recs;
}

unsigned int Workflow::prioridad(unsigned int  t) const{
	return tareas[t]->prioridad;

}

const Conj<unsigned int>& Workflow::predecesoras(unsigned int  t) const{
	return tareas[t]->preds;

}

void Workflow::agTarea(unsigned int p, const recursos& r, const Conj<unsigned int>& ps){
	tuplaTarea* tp = new tuplaTarea;
	tp->prioridad = p;
	tp->preds = ps;
	tp->cantPred = ps.cardinal();
	tp->recs = r;
	tareas.agregarAtras(tp);
}

unsigned int Workflow::cantPredecesoras(unsigned int t) const{
	return tareas[t]->cantPred;
}


unsigned int Workflow::cantidadTareas() const{
	return tareas.tamanio(); 
}

Workflow& Workflow::operator=(const Workflow& w){
	tareas = w.tareas;
	return *this;
}
