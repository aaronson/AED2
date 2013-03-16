#include "planta.h"



Planta::Planta(const Workflow& w, const recursos& r){
	Usorecursos recu(r);
	this->recs = recu;
	this->wkf = w;
	int i = 0;
	unsigned int n = this->wkf.cantidadTareas();
	priotar* ap = new priotar[n];
	
	while (i < n){
		ap[i].tarea = i;
		ap[i].prioridad = this->wkf.prioridad(i);
		i++;
	}
	i = n/2 -1;
	//cout << i << endl << n << endl;
	while (i >= 0){
		heapifyP(ap, i, n);
		i--;
	}
	i = 0;
	Secu<priotar> s;
	Secu<priotar>::iterador it = s.crearIt();
	while (i < n){
		it.agregarAtrasDeIt(ap[0]);
		ap[0].prioridad = 0;
		heapifyP(ap, 0, n);
		i++;
	}
	it.retrocederAlPrincipio();
	Secu<unsigned int>* asuc = new Secu<unsigned int>[n];
	
	while (it.hayMas()){
		i = it.actual().tarea;
		Conj<unsigned int>::const_iterador itpred = this->wkf.predecesoras(i).crearIt();
		while (itpred.hayMas()){
			asuc[itpred.actual()].agregarAtras(i);
			//cout << itpred.actual() << " " << asuc[itpred.actual()] << endl;
			itpred.avanzar();
		}
		it.avanzar();
	}
	this->sucesores = asuc;
	delete [] ap;
}

Planta::~Planta(){
	ordtars o;
	while (!terminadas.vacia()){
		o = terminadas.prim();
		delete [] o.tareas;
		terminadas.fin();
	}
	//for (unsigned int i = 0; i < n; i++){
		////delete [] sucesores[i];
		//sucesores[i] = NULL;
	//}
	
	delete [] sucesores;
	
	//delete [] sucesores;
	//}
}

void Planta::heapifyP (priotar ap[], int i, unsigned int n) const{
	if (n > i*2+1){ //cambiado del TP, me aseguro que no entre a posiciones del arreglo invalidas
		if (n > i*2+2){ //cambiado del TP, me aseguro que no entre a posiciones del arreglo invalidas
			if (ap[2*i+1].prioridad > ap[i].prioridad || ap[2*i+2].prioridad > ap[i].prioridad){
				 if (ap[2*i+1].prioridad > ap[2*i+2].prioridad){
					if (ap[i*2+1].prioridad > 0){
						swap (ap[i], ap [i*2+1]);
						heapifyP (ap, i*2+1, n);
					}
				}else{
					if (ap[i*2+2].prioridad > 0){
						swap(ap[i], ap[i*2+2]);
						heapifyP (ap, i*2+2, n);	
					}
				}
			}
		}else{
			if (ap[i*2+1].prioridad > ap[i].prioridad){
				swap (ap[i], ap[i*2+1]);
			}
		}
	}
}


Workflow Planta::verWorkflow () const{
	return this->wkf;
}

recursos Planta::verRecursos () const{
	return this->recs.multiconjuntizar();
}

Cola Planta::enEspera() const{
	return this->esperando;
}

Conj<actividad> Planta::enEjecucion() const{
	Conj<actividad> res;
	Secu<ordtars>::const_iterador it = this->terminadas.crearIt();
	unsigned int i = 0;
	unsigned int n = this->wkf.cantidadTareas();
	actividad act;
	while (it.hayMas()){
		i = 0;
		while (i < n){
			if (!it.actual().tareas[i].termino && it.actual().tareas[i].predPendientes == 0){
				act.orden = it.actual().orden;
				act.tarea = i;
				if (!this->esperando.estaActiv(act)){
					res.agregar(act);
				}
			}
			i++;
		}
		it.avanzar();
	}
	return res;
}

Conj<actividad> Planta::finalizadas() const{
	Conj<actividad> res;
	Secu<ordtars>::const_iterador it = this->terminadas.crearIt();
	unsigned int i = 0;
	unsigned int n = this->wkf.cantidadTareas();
	actividad act;
	while (it.hayMas()){
		i = 0;
		while (i < n){
			if (it.actual().tareas[i].termino){
				act.orden = it.actual().orden;
				act.tarea = i;
				res.agregar(act);
			}
			i++;
		}
		it.avanzar();
	}
	return res;
}


void Planta::agOrden(unsigned int o){
	unsigned int n = this->wkf.cantidadTareas();
	unsigned int i = 0;
	estado* at = new estado[n];
	while (i < n){
		at[i].termino = false;
		at[i].predPendientes = this->wkf.cantPredecesoras(i);
		i++;
	}
	if (this->recs.alcanzanLosRecursos(this->wkf.consumo(0))){
		//cout << this->wkf.consumo(0) << endl;
		this->recs.actualizarConsumo(this->wkf.consumo(0));
	}else{
		this->esperando.encolar(0, o, this->wkf.prioridad(0));
	}
	ordtars ords;
	ords.orden = o;
	ords.tareas = at;
	this->terminadas.agregarAtras(ords);
}

void Planta::terminar(actividad a){
	unsigned int* rec = recursosAArreglo();
	Secu<ordtars>::iterador it = this->terminadas.crearIt();
	while (it.actual().orden != a.orden){
		it.avanzar();
	}
	it.actual().tareas[a.tarea].termino = true;
	recursos mulrec;
	mulrec = this->wkf.consumo(a.tarea);
	actualizarArreglo(rec, mulrec, true);
	Secu<unsigned int> suc = this->sucesores[a.tarea];
	Secu<activpriorizada> aencolar;
	activpriorizada actp;
	actividad activ;
	Secu<unsigned int>::iterador itsuc = suc.crearIt();
	while (itsuc.hayMas()){
		it.actual().tareas[itsuc.actual()].predPendientes -= 1;
		if (it.actual().tareas[itsuc.actual()].predPendientes == 0){
			activ.orden = it.actual().orden;
			activ.tarea = itsuc.actual();
			actp.act = activ;
			actp.prioridad = this->wkf.prioridad(itsuc.actual());
			aencolar.agregarAtras(actp);
		}
		itsuc.avanzar();
	}
	this->esperando.encolarSecuOrdenada(aencolar);
	Cola::iterador itEspera = this->esperando.crearIt();
	while (itEspera.hayMas()){
		mulrec = this->wkf.consumo(itEspera.actual().tarea);
		if (mconjIncluidoEnArreglo(rec, mulrec)){
			Secu<unsigned int>::iterador itOrden = itEspera.actual().ordenes.crearIt();
			while (itOrden.hayMas() && mconjIncluidoEnArreglo(rec, mulrec)){
			//while (!itEspera.actual().ordenes.vacia() && mconjIncluidoEnArreglo(rec, mulrec){
				itOrden.borrarActual();
				//itEspera.actual().ordenes.fin
				actualizarArreglo(rec, mulrec, false);
			}
			if (itEspera.actual().ordenes.vacia()){
				itEspera.borrarActual();
			}
		}else {
			if (itEspera.hayMas()){
				itEspera.avanzar();
			}
		}
	}
	this->recs.actualizarUso(rec);	
	delete [] rec;
}

unsigned int* Planta::recursosAArreglo () const{
	unsigned int n = this->recs.tiposDeRecurso();
	unsigned int* ar = new unsigned int[n];
	for (unsigned int i = 0; i < n; i++){
		ar[i] = this->recs.disponibilidad(i);
	}
	return ar;
}

bool Planta::mconjIncluidoEnArreglo(unsigned int r[], const recursos& mcj) const{
	recursos temp(mcj);
	bool res = true;
	recursos::iterador it(temp.crearIt());
	unsigned int n;
	while (it.hayMas() && res){
		n = it.actual();
		res = (r[n] >= temp.cardinal(n));
		it.borrarActual();
	}
	return res;
}

void Planta::actualizarArreglo(unsigned int r[], const recursos& mcj, bool sumar) const{
	unsigned int i = 0;
	recursos temp(mcj);
	recursos::iterador it(temp.crearIt());
	if (sumar){
		while (it.hayMas()){
			i = it.actual();
			r[i] += temp.cardinal(i);
			it.borrarActual();
		}
	}else{
		while (it.hayMas()){
			i = it.actual();
			r[i] -= temp.cardinal(i);
			it.borrarActual();
		}
	}
}


Conj<actividad> Planta::actividades() const{
	Conj<actividad> res;
	unsigned int i = 0;
	unsigned int n = this->wkf.cantidadTareas();
	actividad act;
	Secu<ordtars>::const_iterador it = this->terminadas.crearIt();
	while (it.hayMas()){
		while (i < n){
			act.orden = it.actual().orden;
			act.tarea = i;
			res.agregar(act);
			i++;
		}
		it.avanzar();
	}
	return res;
}

Conj<unsigned int> Planta::verOrdenes() const{
	Conj<unsigned int> res;
	Secu<ordtars>::const_iterador it = this->terminadas.crearIt();
	while (it.hayMas()){
		res.agregar(it.actual().orden);
		it.avanzar();
	}
	return res;
}

Conj<unsigned int> Planta::ordenesFinalizadas() const{
	Conj<unsigned int> res;
	Secu<ordtars>::const_iterador it = this->terminadas.crearIt();
	while (it.hayMas()){
		if (terminoOrden(it.actual().tareas, this->wkf.cantidadTareas())){
			res.agregar(it.actual().orden);
		}
		it.avanzar();
	}
	return res;
}

bool Planta::terminoOrden (const estado* at, unsigned int n) const{
	bool res = true;
	unsigned int i = 0;
	while (i < n && res){
		if (!at[i].termino){
			res = false;
		}
		i++;
	}
	return res;
}

recursos Planta::disponibles() const{
	return this->recs.disponiblesEnMulticonj();
}

unsigned int Planta::consumoDeRecurso (unsigned int r) const{
	return (this->recs.verTotal(r) - this->recs.disponibilidad(r));
}

unsigned int Planta::menorConsumo() const{
	return (this->recs.menorConsumo());
}





			


