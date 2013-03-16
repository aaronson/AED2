#include <iostream>

#include "planta.h"

int main(){
	Conj<unsigned int> c1;
	Conj<unsigned int> c2;
	Conj<unsigned int> c3;
	Conj<unsigned int> c4;
	Conj<unsigned int> c5;
	Conj<unsigned int> c6;
	Conj<unsigned int> c7;

	c1.agregar(0);
	c2.agregar(1);
	c3.agregar(1);
	c4.agregar(1);
	c5.agregar(2);
	c5.agregar(4);
	c6.agregar(3);
	c7.agregar(5);	
	c7.agregar(6);

	recursos r0;
	recursos r1;
	recursos r2;
	recursos r3;
	recursos r4;
	recursos r5;
	recursos r6;
	recursos r7;
	
	r0.agregar(0);
	r1.agregar(2);
	r2.agregar(1);
	r2.agregar(1);
	r3.agregar(1);
	r3.agregar(2);
	r4.agregar(0);
	r4.agregar(1);
	r5.agregar(1);
	r6.agregar(1);
	r6.agregar(0);
	r6.agregar(0);
	r6.agregar(2);
	r7.agregar(1);


	Workflow w(100,r0);
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 0: " << w.prioridad(0) << ". Estas son las predecesoras de la tarea 0: " << w.predecesoras(0) << ". Este es el consumo de la tarea 0: " << w.consumo(0) << endl;
	w.agTarea(10, r1, c1);
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 1: " << w.prioridad(1) << ". Estas son las predecesoras de la tarea 1: " << w.predecesoras(1) << ". Este es el consumo de la tarea 1: " << w.consumo(1) << endl;
	w.agTarea(50, r2, c2);
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 2: " << w.prioridad(2) << ". Estas son las predecesoras de la tarea 2: " << w.predecesoras(2) << ". Este es el consumo de la tarea 2: " << w.consumo(2) << endl;
	w.agTarea(68, r3, c3);	
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 3: " << w.prioridad(3) << ". Estas son las predecesoras de la tarea 3: " << w.predecesoras(3) << ". Este es el consumo de la tarea 3: " << w.consumo(3) << endl;
	w.agTarea(24, r4, c4);	
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 4: " << w.prioridad(4) << ". Estas son las predecesoras de la tarea 4: " << w.predecesoras(4) << ". Este es el consumo de la tarea 4: " << w.consumo(4) << endl;
	w.agTarea(45, r5, c5);	
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 5: " << w.prioridad(5) << ". Estas son las predecesoras de la tarea 5: " << w.predecesoras(5) << ". Este es el consumo de la tarea 5: " << w.consumo(5) << endl;
	w.agTarea(70, r6, c6);	
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 6: " << w.prioridad(6) << ". Estas son las predecesoras de la tarea 6: " << w.predecesoras(6) << ". Este es el consumo de la tarea 6: " << w.consumo(6) << endl;
	w.agTarea(90, r7, c7);	
	cout << "Estas son las tareas" << w.dametareas() << ". Esta es la prioridad de la tarea 7: " << w.prioridad(7) << ". Estas son las predecesoras de la tarea 7: " << w.predecesoras(7) << ". Este es el consumo de la tarea 7: " << w.consumo(7) << endl;
	
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
	
	cout << "Agrego la orden 1" << endl;
	p.agOrden(1);
	
	cej = p.enEjecucion();
	cout << "Las actividades en ejecucion son: ";
		while (cej.cardinal() > 0){	
		actividad act = cej.dameuno();
		cout << "<" << act.orden << "," << act.tarea << ">";
	}
	cout << endl;
	cout << "Ordenes: " << p.verOrdenes() << endl;
	cout << "Ordenes Finalizadas: " << p.ordenesFinalizadas() << endl;
	
	act.orden = 1;
	act.tarea = 0;
	p.terminar(act);
	cout << "Termino la tarea 0 de la orden 1" << endl;
	
	cej = p.enEjecucion();
	cout << "Las actividades en ejecucion son: ";
	while (cej.cardinal() > 0){	
		actividad act = cej.dameuno();
		cout << "<" << act.orden << "," << act.tarea << ">";
	}
	cout << endl;
	cout << "Estas son las actividades que estan en espera: " << p.enEspera() << endl;
	cout << "Estos son los recursos disponibles: " << p.disponibles() << endl;	
	
	act.orden = 1;
	act.tarea = 1;
	p.terminar(act);
	cout << "Termino la tarea 1 de la orden 1" << endl;
	
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
	
	cout << "Agrego la orden 4" << endl;
	p.agOrden(4);
	
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
	
	cout << "Agrego la orden 3" << endl;
	p.agOrden(3);
	
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
	
	act.orden = 4;
	act.tarea = 0;
	p.terminar(act);
	cout << "Termino la tarea 0 de la orden 4" << endl;
	
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
	
	act.orden = 4;
	act.tarea = 1;
	p.terminar(act);
	cout << "Termino la tarea 1 de la orden 4" << endl;
	
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
	
	act.orden = 2;
	act.tarea = 0;
	p.terminar(act);
	cout << "Termino la tarea 0 de la orden 2" << endl;
	
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
	cout << "Ordenes: " << p.verOrdenes() << endl;
	cout << "Ordenes Finalizadas: " << p.ordenesFinalizadas() << endl;
	cout << "Estas son las actividades que estan en espera: " << p.enEspera() << endl;
	cout << "Estos son los recursos disponibles: " << p.disponibles() << endl;	
	
	act.orden = 2;
	act.tarea = 1;
	p.terminar(act);
	cout << "Termino la tarea 1 de la orden 2" << endl;
	
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
	
	act.orden = 1;
	act.tarea = 3;
	p.terminar(act);
	cout << "Termino la tarea 3 de la orden 1" << endl;
	
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
	
	act.orden = 1;
	act.tarea = 6;
	p.terminar(act);
	cout << "Termino la tarea 6 de la orden 1" << endl;
	
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
	
	act.orden = 1;
	act.tarea = 2;
	p.terminar(act);
	cout << "Termino la tarea 2 de la orden 1" << endl;
	
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
	
	act.orden = 4;
	act.tarea = 3;
	p.terminar(act);
	cout << "Termino la tarea 3 de la orden 4" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;

	
	act.orden = 4;
	act.tarea = 6;
	p.terminar(act);
	cout << "Termino la tarea 6 de la orden 4" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;
	
	act.orden = 4;
	act.tarea = 2;
	p.terminar(act);
	cout << "Termino la tarea 2 de la orden 4" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;
	
	act.orden = 2;
	act.tarea = 3;
	p.terminar(act);
	cout << "Termino la tarea 6 de la orden 4" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;
	
	act.orden = 2;
	act.tarea = 6;
	p.terminar(act);
	cout << "Termino la tarea 6 de la orden 2" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;	
	
	act.orden = 1;
	act.tarea = 4;
	p.terminar(act);
	cout << "Termino la tarea 4 de la orden 1" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;
	
	act.orden = 1;
	act.tarea = 5;
	p.terminar(act);
	cout << "Termino la tarea 5 de la orden 1" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;	
		
		
	act.orden = 1;
	act.tarea = 7;
	p.terminar(act);
	cout << "Termino la tarea 7 de la orden 1" << endl;
	
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
	cout << "La cantidad menos usada de un recurso es: " << p.menorConsumo() << endl;	
	
	return 0;
}
