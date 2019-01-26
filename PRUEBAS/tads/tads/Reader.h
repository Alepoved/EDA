#ifndef __READER_H
#define __READER_H

#include <fstream>
#include <cstddef>
#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;

class Libro {
public:
	string nombre;

	bool operator !=(const Libro &l)const {
		return nombre != l.nombre;
	}

	bool operator ==(const Libro &l)const {
		return nombre == l.nombre;
	}


	Libro(string n) :
		nombre(n) {}
};

class InfoLibro {
public:
	
	int numPag;
	int pagAct;
	/*bool abierto = false;*/

	Lista<Libro>::Iterator it;

	InfoLibro(int p, Lista<Libro>::Iterator it) : numPag(p), it(it),pagAct(1) {}

	/*InfoLibro(int p) : 
		numPag(p),pagAct(1),abierto(false) {}*/


};



template<class L>
class Reader {
public:

	Reader(){}

	void ponerLibro(L & l,int numPaginas) {
		if (!tablaLibros.contiene(l)) {
			/*InfoLibro libro( numPaginas);*/
			InfoLibro libro(numPaginas, librosAbiertos.end());
			tablaLibros.inserta(l, libro);
			cantidad++;
		}
	}
	
	void abrir(L & l) {
		if (!tablaLibros.contiene(l))throw "libro no esta en el reader";
		InfoLibro libro = tablaLibros.valorPara(l);
		/*if (libro.abierto) {
			Lista<L>::Iterator it = librosAbiertos.begin();
			while (it.elem() != l)it.next();
			librosAbiertos.eliminar(it);
		}*/
		if (libro.it != librosAbiertos.end()) {
			librosAbiertos.eliminar(libro.it);
		}
		/*else {
			libro.abierto = true;
			tablaLibros.inserta(l, libro);
		}*/
	
			librosAbiertos.pon_ppio(l);//estaba antes tambien
			libro.it = librosAbiertos.begin();
			tablaLibros.inserta(l, libro);

		//librosAbiertos.pon_ppio(l);//estaba antes tambien
		

	}

	void avanzaPagina() {
		if (librosAbiertos.esVacia())throw "no hay ningun libro abierto";
		L l = librosAbiertos.primero();
		InfoLibro libro= tablaLibros.valorPara(l);
		if (libro.pagAct == libro.numPag)libro.pagAct = 1;
		else libro.pagAct++;
		tablaLibros.inserta(l, libro);

	}

	L abierto() {
		if (listaAbiertos.esVacia())throw "no hay ningun libro abierto";
		return listaAbiertos.primero();
	}

	int pagLibro(L & l) {
		if (!tablaLibros.contiene(l))throw "no esta el libro";
		InfoLibro libro = tablaLibros.valorPara(l);
		return libro.pagAct;
	}

	void eliminaLibro(L & l) {
		if (tablaLibros.contiene(l)) {
			InfoLibro libro = tablaLibros.valorPara(l);
			/*if (libro.abierto) {
				Lista<L>::Iterator it = librosAbiertos.begin();
				while (it.elem() != l) it.next();
				librosAbiertos.eliminar(it);
			}*/

			if (libro.it != librosAbiertos.end()) {
				librosAbiertos.eliminar(libro.it);
			}

			tablaLibros.borra(l);
			cantidad--;
		}
	}

	Lista<L> recientes(int n) {
		Lista<L> lista;
		Lista<L>::Iterator it = librosAbiertos.begin();
		int cont = 0;
		while ((cont < n) && it != librosAbiertos.end()) {
			lista.pon_final(it.elem());
			it.next();
		}
		return lista;
	}

private:
	DiccionarioHash<L, InfoLibro> tablaLibros;
	Lista<L> librosAbiertos;
		int cantidad;
};




#endif // __DICCIO2_H
