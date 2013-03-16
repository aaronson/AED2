#include "usorecursos.h"

Usorecursos::Usorecursos(){
}


Usorecursos::Usorecursos(recursos r){
	unsigned int n = r.cantElemDistintos();
	recursos::iterador it(r.crearIt());
	rec* ar = new rec[n];
	//cout << r.cardinal(0)<< endl;
	unsigned int temp = 0;
	while (it.hayMas()){
		temp = it.actual();
		ar[temp].total = r.cardinal(temp);
		//cout << ar[0].total << endl;
		ar[temp].disponible = ar[temp].total;
		//cout << ar[0].disponible << endl;

		it.borrarActual();
	}
	record* ao = new record[n];
	for (unsigned int j = 0; j < n; j++){
		ao[j].recurso = j;
		ao[j].disponible = ar[j].disponible;
		ar[j].orden = j;
	}
	int i = (n/2) -1;
	while (i >= 0){
		heapify(ao, i, ar, n);
		i--;
	}

	//cout << ar[0].total << endl;
	//cout << ar[0].disponible << endl;

	this->status = ar;
	this->ordenesConsumo = ao;
	this->cantRecursos = n;


}

Usorecursos::~Usorecursos(){
	delete status;
	delete ordenesConsumo;
}

void Usorecursos::heapify(record ao[], int i, rec ar[], unsigned int n){
	if (n > i*2+1){ //cambiado del TP, me aseguro que no entre a posiciones del arreglo invalidas
		if (n > i*2+2){ //cambiado del TP, me aseguro que no entre a posiciones del arreglo invalidas
			if (ao[2*i+1].disponible > ao[i].disponible || ao[2*i+2].disponible > ao[i].disponible){
				 if (ao[2*i+1].disponible > ao[2*i+2].disponible){
				 	swap (ao[i], ao [i*2+1]);
				 	ar[ao[i].recurso].orden = i;
				 	ar[ao[i*2+1].recurso].orden = i*2+1;
				 	heapify (ao, i*2+2, ar, n);
				}
			}
		}else{
			if (ao[i*2+1].disponible > ao[i].disponible){
				swap (ao[i], ao[i*2+1]);
				ar[ao[i].recurso].orden = i;
				ar[ao[i*2+1].recurso].orden = i*2+1;
			}
		}
	}
}

unsigned int Usorecursos::tiposDeRecurso() const{
	return this->cantRecursos;
}

unsigned int Usorecursos::verTotal(unsigned int r) const{
	return this->status[r].total;
}

unsigned int Usorecursos::disponibilidad(unsigned int r) const{
	return this->status[r].disponible;
}

void Usorecursos::nuevoConsumo (unsigned int r, unsigned int n){
	this->status[r].disponible = n;
	this->ordenesConsumo[this->status[r].orden].disponible = n;
	this->status[r].orden = n;
	int i = n;
	while (i>0){
		heapify (this->ordenesConsumo, i, this->status, this->cantRecursos);
		i = i/2 -1;
	}
}

unsigned int Usorecursos::menorConsumo () const{
	unsigned int n = this->ordenesConsumo[0].recurso;
	return (this->status[n].total - this->status[n].disponible);
}

void Usorecursos::actualizarConsumo (recursos r){
	unsigned int n = this->cantRecursos;
	//unsigned int i = 0;
	unsigned int rtemp;
	recursos::iterador it(r.crearIt());
	while (it.hayMas()){
		rtemp = it.actual();
		this->status[rtemp].disponible -= r.cardinal(rtemp);
		this->ordenesConsumo[this->status[rtemp].orden].disponible += r.cardinal(rtemp);
		heapify (this->ordenesConsumo, rtemp, this->status, n);
		it.borrarActual();
	}
}

void Usorecursos::actualizarUso(unsigned int* ar){
	unsigned int n = this->cantRecursos;
	int i = 0;
	while (i< n){
		this->status[i].disponible = ar[i];
		this->ordenesConsumo[this->status[i].orden].disponible = ar[i];
		i++;
	}
	i = n/2 -1;
	while (i >= 0){
		heapify (this->ordenesConsumo, i, this->status, n);
		i--;
	}
}

bool Usorecursos::alcanzanLosRecursos (recursos r) const{
	bool res = true;
	//unsigned int n = this->cantRecursos;
	//unsigned int i = 0;
	unsigned int rtemp;
	recursos::iterador it(r.crearIt());
	while (it.hayMas() && res){
		rtemp = it.actual();
		res = (status[rtemp].disponible >= r.cardinal(rtemp));
		it.borrarActual();
	}
	return res;
}

recursos Usorecursos::multiconjuntizar() const{
	recursos res;
	unsigned int n = this->cantRecursos;
	unsigned int cant;
	for (unsigned int i = 0; i < n; i++){
		cant = this->status[i].total;
		while (cant > 0){
			res.agregar(i);
			cant--;
		}
	}
	return res;
}

recursos Usorecursos::disponiblesEnMulticonj() const{
	recursos res;
	unsigned int n = this->cantRecursos;
	unsigned int cant;
	for (unsigned int i = 0; i < n; i++){
		cant = this->status[i].disponible;
		while (cant > 0){
			res.agregar(i);
			cant--;
		}
	}
	return res;
}

Usorecursos& Usorecursos::operator=( Usorecursos& u){
	//delete [] status;
	//delete [] ordenesConsumo;
	status = u.status;
	ordenesConsumo = u.ordenesConsumo;
	cantRecursos = u.cantRecursos;

	u.status = NULL;
	u.ordenesConsumo = NULL;
	return *this;
}

