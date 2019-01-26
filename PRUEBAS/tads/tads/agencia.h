#ifndef __AGEN_H
#define __AGEN_H

#include <fstream>
#include <cstddef>
#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;

class Cliente {
public:
	string nombre;
	int edad;

	bool operator !=(Cliente &c) const {
		return nombre != c.nombre;
	}
	bool operator==(const Cliente & c)const {
		return nombre == c.nombre;
	}
	bool operator<(const Cliente & c)const {
		return nombre < c.nombre;
	}

	Cliente(string nombre, int edad) :
		nombre(nombre), edad(edad) {}
};


class Hotel {
public:
	string nombre;

	bool operator <(Hotel &h) const {
		return nombre < h.nombre;
	}

	bool operator==(const Hotel &h) const {
		return nombre == h.nombre;
	}

	Hotel(string nombre) :
		nombre(nombre) {}
};


template <class C, class H>
class Agencia {
public:

	Agencia() {}



	void aloja(C &c, H &h) {

		if (tablaClientes.contiene(c)) {
			H hotelAnt = tablaClientes.valorPara(c);
			Lista<C> listaClientes = arbolHoteles.valorPara(hotelAnt);
			Lista<C>::Iterator it = listaClientes.begin();
			while (it.elem() != c)it.next();
			listaClientes.eliminar(it);
			arbolHoteles.inserta(hotelAnt, listaClientes);

		}
		Lista<C> listaClientes2;
		if (arbolHoteles.contiene(h)) listaClientes2 = arbolHoteles.valorPara(h);
		listaClientes2.pon_ppio(c);
		arbolHoteles.inserta(h, listaClientes2);
		tablaClientes.inserta(c, h);


	}


	void desaloja(C &c) {
		if (tablaClientes.contiene(c)) {
			H hotelAnt = tablaClientes.valorPara(c);
			Lista<C> listaClientes = arbolHoteles.valorPara(hotelAnt);
			Lista<C>::Iterator it = listaClientes.begin();
			while (it.elem() != c)it.next();
			listaClientes.eliminar(it);
			arbolHoteles.inserta(hotelAnt, listaClientes);
			tablaClientes.borra(c);
		}
	}

	H alojamiento(C &c) {
		if (!tablaClientes.contiene(c))throw "Cliente no esta";
		return tablaClientes.valorPara(c);
	}

	Lista <H> Lhoteles() {
		Lista<H> listaHoteles;
		Diccionario<H, Lista<C>>::Iterator it = arbolHoteles.begin();
		while (it != arbolHoteles.end()) {
			listaHoteles.pon_ppio(it.elem());
			it.next();
		}
		return listaHoteles;

	}

	Lista <C> huespedes(H &h) {
		if (arbolHoteles.contiene(h))
			return arbolHoteles.valorPara(h);

	}

private:
	Diccionario<Hotel,Lista<C>> arbolHoteles;
	DiccionarioHash<C, H> tablaClientes;



};






#endif // __DICCIO2_H

