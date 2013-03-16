#include <iostream>

//#include "secu.h"
//#include "conj.h"
//#include "mconj.h"
//#include "defs.h"
//#include "cola.h"
//#include "workflow.h"
//#include "usorecursos.h"

#include "planta.h"



int main(){
	Secu<unsigned int> st;
	cout << st << endl;
	st.agregarAdelante(3);
	cout << st << endl;
	st.agregarAdelante(4);
	cout << st << endl;
	st.agregarAdelante(5);
	cout << st << endl;
	st.agregarAdelante(6);
	cout << st << endl;
	st.agregarAdelante(7);
	cout << st << endl;
	st.agregarAdelante(8);
	cout << st << endl;
	st.agregarAtras(1);
	cout << st << endl;
	st.agregarAtras(2);
	cout << st << endl;
	st.fin();
	cout << st << st.tamanio() << endl;
	st.fin();
	cout << st << st.tamanio() << endl;
	st.fin();
	cout << st << st.tamanio() << endl;
	st.fin();
	cout << st << st.tamanio() << endl;
	Secu<unsigned int>::iterador it(st.crearIt());
	unsigned int i = 10;
	while (i>0){
		it.agregarAdelanteDeIt(i);
		i--;
		//it.avanzar();
	}
	cout << st << st.tamanio() << endl;
	cout << it.actual()<<endl;
	it.avanzar();
	cout << it.actual()<<endl;
	it.borrarActual();
	cout << st << st.tamanio() << endl;
	Secu<unsigned int> st2(st);
	cout << st2 << st2.tamanio() << endl;
	cout << st.esta(9) << st.esta(11) << endl;
	
	
	Conj<unsigned int> ct;
	Conj<unsigned int> ct2(ct);
	cout << ct2 << endl;
	i = 0;
	while (i < 5){
		ct2.agregar(i);
		i++;
	}
	cout << "este es ct2" << ct2 << endl;
	i= 3;
	while (i < 7){
		ct.agregar(i);
		i++;
	}
	Conj<unsigned int> ct3(ct2);

	cout << "este es ct3" << ct3 << endl;
	cout << ct.pertenece(3)<< endl;
	ct.sacar(4);
	cout << ct << endl;
	ct2.agregar(9);
	cout << ct2 << endl;
	ct2.unir(ct);
	cout << ct2 << endl;
	Conj<unsigned int>::iterador itc(ct2.crearIt());
	cout << itc.actual()<< endl;
	itc.avanzar();
	itc.borrarActual();
	cout << "hola" << ct2 << endl;
	while (itc.hayMas()){
		cout << ct2 << endl;
		itc.borrarActual();
	}
	cout << ct2 << endl;
	Mconj<unsigned int> mcjt;
	mcjt.agregar(1);
	cout << mcjt.cardinal(1) <<endl;
	mcjt.agregar(1);
	mcjt.agregar(1);
	mcjt.agregar(2);
	mcjt.agregar(13);
	mcjt.agregar(4);
	mcjt.agregar(4);
	mcjt.agregar(1);
	mcjt.agregar(2);
	cout << mcjt << mcjt.cantElemDistintos() <<endl;
	Mconj<unsigned int>::iterador itm(mcjt.crearIt());
	cout<< "llegue aca" << endl;
	itm.avanzar();
	cout<< "llegue aca" << endl;
	itm.borrarActual();
	cout<< "llegue aca" << endl;
	cout << mcjt << mcjt.cantElemDistintos() <<endl;
	Mconj<unsigned int> mct2(mcjt);
	cout << "este es mct2 "<< mct2 <<endl;
	Cola co;
	co.encolar(5,6,23);
	co.encolar(5,4,23);
	cout << co << co.proxima().tarea << "," << co.proxima().orden << ";" << co.ordenes(5) << endl;
	co.encolar(1,1,10);
	cout << co << co.proxima().tarea << "," <<co.proxima().orden << endl;
	co.encolar(8,1,1);
	cout << co << co.proxima().tarea << "," <<co.proxima().orden << endl;
	co.sacarOrden(5,6);
	cout << co << co.proxima().tarea << "," << co.proxima().orden << ";" << co.ordenes(5) << endl;
	co.sacarOrden(5,4);
	cout << co << co.proxima().tarea << "," << co.proxima().orden << endl;
	co.sacarOrden(1,1);
	cout << co << co.proxima().tarea << "," << co.proxima().orden << endl;
	Secu<activpriorizada> sav;
	activpriorizada ap;
	ap.prioridad = 50;
	ap.act.orden = 1;
	ap.act.tarea = 9;
	sav.agregarAtras(ap);
	ap.prioridad = 18;
	ap.act.orden = 5;
	ap.act.tarea = 7;
	sav.agregarAtras(ap);
	ap.prioridad = 0;
	ap.act.orden = 5;
	ap.act.tarea = 2;
	sav.agregarAtras(ap);
	co.encolarSecuOrdenada(sav);
	cout << co << endl;
	Secu<unsigned int> sst;
	st.agregarAtras(2);
	st.agregarAtras(2);
	st.agregarAtras(6);
	st.agregarAtras(3);
	st.agregarAtras(2);
	cout << st << endl;
	sst = st;
	cout << st << "==" << sst << endl;
	Conj<unsigned int> ct4;
	ct4 = ct2;
	cout << ct4 << "==" << ct2 << endl;
	SecuIndexable<int> sit;
	SecuIndexable<int> sit2;
	sit.agregarAtras(1);
	sit.agregarAtras(4);
	sit.agregarAtras(5);
	sit.agregarAtras(2);
	sit2 = sit;
	cout << sit2[0] <<  sit2[1] <<  sit2[2] <<  sit2[3] << endl << endl << endl;


	Conj<unsigned int> c1;
	Conj<unsigned int> c2;
	Conj<unsigned int> c3;
	Conj<unsigned int> c4;
	c1.agregar(0);
	c2.agregar(1);
	c3.agregar(1);
	c4.agregar(2);
	c4.agregar(3);
	recursos r0;
	recursos r1;
	recursos r2;
	recursos r3;
	recursos r4;
	r0.agregar(0);
	r0.agregar(0);
	r0.agregar(1);
	r1.agregar(0);
	r1.agregar(2);
	r2.agregar(1);
	r2.agregar(1);
	r3.agregar(0);
	r3.agregar(0);
	r3.agregar(2);
	r4.agregar(1);
	r4.agregar(1);
	r4.agregar(1);
	Workflow w(100,r0);
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 0: " << w.prioridad(0) << ". Estas son las predecesoras de la tarea 0: " << w.predecesoras(0) << ". Este es el consumo de la tarea 0: " << w.consumo(0) << endl;
	w.agTarea(10, r1, c1);
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 1: " << w.prioridad(1) << ". Estas son las predecesoras de la tarea 1: " << w.predecesoras(1) << ". Este es el consumo de la tarea 1: " << w.consumo(1) << endl;
	w.agTarea(43, r2, c2);
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 2: " << w.prioridad(2) << ". Estas son las predecesoras de la tarea 2: " << w.predecesoras(2) << ". Este es el consumo de la tarea 2: " << w.consumo(2) << endl;
	w.agTarea(46, r3, c3);	
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 3: " << w.prioridad(3) << ". Estas son las predecesoras de la tarea 3: " << w.predecesoras(3) << ". Este es el consumo de la tarea 3: " << w.consumo(3) << endl;
	w.agTarea(58, r4, c4);	
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 4: " << w.prioridad(4) << ". Estas son las predecesoras de la tarea 4: " << w.predecesoras(4) << ". Este es el consumo de la tarea 4: " << w.consumo(4) << endl;
	recursos rt;
	rt.agregar(0);
	rt.agregar(0);
	rt.agregar(0);
	rt.agregar(1);
	rt.agregar(1);
	rt.agregar(1);
	rt.agregar(2);
	rt.agregar(2);
	cout << "Estos son los recursos que vamos a agregar a la planta: " << rt << endl;
	Planta p(w, rt);
	cout << "Estos son los recursos de la planta: " << p.verRecursos() << endl;
	cout << "Agrego la orden 0" << endl;
	p.agOrden(0);
	Conj<actividad> cej;
	actividad act;
	cej = p.enEjecucion();
	cout << "Las actividades en ejecucion son: ";
		while (cej.cardinal() > 0){	
		actividad act = cej.dameuno();
		cout << "<" << act.orden << "," << act.tarea << ">";
	}
	cout << endl;
	cout << "Ordenes: " << p.verOrdenes() << endl;
	cout << "Ordenes Finalizadas: " << p.ordenesFinalizadas() << endl;
	act.orden = 0;
	act.tarea = 0;
	p.terminar(act);
	cout << "Termino la tarea 0 de la orden 0" << endl;
	cej = p.enEjecucion();
	cout << "Las actividades en ejecucion son: ";
	while (cej.cardinal() > 0){	
		actividad act = cej.dameuno();
		cout << "<" << act.orden << "," << act.tarea << ">";
	}
	cout << endl;
	act.orden = 0;
	act.tarea = 1;
	p.terminar(act);
	cout << "Termino la tarea 1 de la orden 0" << endl;

	cej = p.enEjecucion();
	cout << "Las actividades en ejecucion son: ";
		while (cej.cardinal() > 0){	
		actividad act = cej.dameuno();
		cout << "<" << act.orden << "," << act.tarea << ">";
	}
	cout << endl;
	cout << "Estas son las actividades que estan en espera: " << p.enEspera() << endl;
	cout << "Estos son los recursos disponibles: " << p.disponibles() << endl;
	cout << "Agrego la orden 2" << endl;
	p.agOrden(2);
	cej = p.enEjecucion();
	cout << "Las actividades en ejecucion son: ";
		while (cej.cardinal() > 0){	
		actividad act = cej.dameuno();
		cout << "<" << act.orden << "," << act.tarea << ">";
	}
	cout << endl;
	cout << "Ordenes: " << p.verOrdenes() << endl;
	cout << "Ordenes Finalizadas: " << p.ordenesFinalizadas() << endl;
	cout << "Estas son las actividades que estan en espera: " << p.enEspera() << endl;
	cout << "Estos son los recursos disponibles: " << p.disponibles() << endl;

	

	






	return 0;
}
