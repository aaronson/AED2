#include "cola.h"

Cola::Cola(){}

Cola::Cola(const Cola& otro) : sec(otro.sec) {}  //MODIFICADO DEL TP

bool Cola::vacia() const{
	return this->sec.vacia();
}

actividad Cola::proxima() const{
	actividad act;
	act.tarea = this->sec.prim().tarea;
	act.orden = this->sec.prim().ordenes.prim();
	return act;
}

unsigned int Cola::prioridad() const{
	return this->sec.prim().prioridad;
}



Secu<unsigned int> Cola::ordenes(unsigned int t) const{
	Secu<prioract>::const_iterador it = this->sec.crearIt();
	bool noencontro = true;
	while (it.hayMas() && noencontro){
		if (it.actual().tarea == t){
			break;
		}
		it.avanzar();
	}
	return it.actual().ordenes;
}

bool Cola::esta(unsigned int t) const{
	Secu<prioract>::const_iterador it = this->sec.crearIt();
	bool res = false;
	while (it.hayMas() && !res){
		if (it.actual().tarea == t){
			res = true;
		}
		it.avanzar();
	}
	return res;
}

bool Cola::estaActiv(actividad a) const{
	Secu<prioract>::const_iterador it = this->sec.crearIt();
	bool res = false;
	while (it.hayMas() && !res){
		if (it.actual().tarea == a.tarea){
			res = it.actual().ordenes.esta(a.orden);
			break;
		}
		it.avanzar();
	}
	return res;
}


void Cola::sacarOrden (unsigned int t, unsigned int o){
	Secu<prioract>::iterador it = this->sec.crearIt();
	while (it.actual().tarea != t){
		it.avanzar();
	}
	Secu<unsigned int>::iterador itord = it.actual().ordenes.crearIt();
	while (itord.actual() != o){
		itord.avanzar();
	}
	itord.borrarActual();
	if (it.actual().ordenes.vacia()){
		it.borrarActual();
	}
}

void Cola::encolar (unsigned int t, unsigned int o, unsigned int p){
	Secu<prioract>::iterador it = this->sec.crearIt();
	while (it.hayMas() && it.actual().prioridad > p){
		it.avanzar();
	}
	if (it.hayMas() && it.actual().prioridad == p){
		it.actual().ordenes.agregarAtras(o);
	}else if (it.hayMas()){
		prioract nuevo;
		nuevo.tarea = t;
		nuevo.ordenes.agregarAtras(o);
		nuevo.prioridad = p;
		it.agregarAdelanteDeIt(nuevo);
	}else{ //modificado del TP
		prioract nuevo;
		nuevo.tarea = t;
		nuevo.ordenes.agregarAtras(o);
		nuevo.prioridad = p;
		this->sec.agregarAtras(nuevo);	
	}
}

void Cola::encolarSecuOrdenada (const Secu<activpriorizada>& s){
	Secu<activpriorizada>::const_iterador itsecu = s.crearIt();
	Secu<prioract>::iterador itcola = this->sec.crearIt();
	while (itsecu.hayMas()){
		while (itcola.hayMas() && itcola.actual().prioridad > itsecu.actual().prioridad){
			itcola.avanzar();
		}
		if (itcola.hayMas() && itcola.actual().prioridad == itsecu.actual().prioridad){
			itcola.actual().ordenes.agregarAtras(itsecu.actual().act.orden);
		}else if (itcola.hayMas()){
			prioract nuevo;
			nuevo.tarea = itsecu.actual().act.tarea;
			nuevo.ordenes.agregarAtras(itsecu.actual().act.orden);
			nuevo.prioridad = itsecu.actual().prioridad;
			itcola.agregarAdelanteDeIt(nuevo);
		}else{ //modificado del TP
			prioract nuevo;
			nuevo.tarea = itsecu.actual().act.tarea;
			nuevo.ordenes.agregarAtras(itsecu.actual().act.orden);
			nuevo.prioridad = itsecu.actual().prioridad;
			this->sec.agregarAtras(nuevo);	
		}
		itsecu.avanzar();
	}
}

void Cola::mostrarCola(ostream& out) const {
	out << "{";
	Secu<prioract>::const_iterador it = this->sec.crearIt();
	//unsigned int i;
	while (it.hayMas()){
		out << "(Tarea: " << it.actual().tarea << ", Prioridad: " << it.actual().prioridad << ", Ordenes: " << it.actual().ordenes << ")";
		it.avanzar();
	}
	out << "}";
}

ostream& operator<<(ostream& out, const Cola& c) {
        c.mostrarCola(out);
        return out;
}



Cola::iterador Cola::crearIt() {
	return Cola::iterador(this);
}


Cola::const_iterador Cola::crearIt() const {
	return const_iterador(this);
}


Cola::iterador::iterador(Cola* co) : it(co->sec.crearIt()) {
}


Cola::const_iterador::const_iterador(const Cola* co) : it(co->sec.crearIt()) {
}



Cola::prioract& Cola::iterador::actual(){
	return this->it.actual();
}



const Cola::prioract& Cola::const_iterador::actual() const{
	return this->it.actual();
}


void Cola::iterador::avanzar(){
	this->it.avanzar();
}


void Cola::const_iterador::avanzar(){
	this->it.avanzar();
}


bool Cola::iterador::hayMas() const {
	return this->it.hayMas();
}


bool Cola::const_iterador::hayMas() const {
	return this->it.hayMas();
}

void Cola::iterador::borrarActual(){
	this->it.borrarActual();
}
