#ifndef AGEN_H
#define AGEN_H



#include"diccionario.h"
#include "DiccionarioHash.h"
#include"lista.h"



class Hotel {
public:
	string nombre;
	

	Hotel(string n) :
		nombre(n) {}

	bool operator == (const Hotel hotel) {
		return nombre == hotel.nombre;
	}

	bool operator < (const Hotel hotel) const{
		return nombre < hotel.nombre;
	}

};

class Cliente {
public: 
	string nombre;
	int edad;

	Cliente(string nombre, int edad) :
		nombre(nombre), edad(edad) {}

	bool operator == (const Cliente cliente) {
		return nombre == cliente.nombre;
	}

	bool operator < (const Cliente cliente) {
		return nombre < cliente.nombre;
	}

	bool operator != (const Cliente cliente)const {
		return nombre != cliente.nombre;
	}
};


template<class C,class H>

class Agencia {

public:
	void aloja(C c, H h) {
		if (tablaClientes.contiene(c)) {// si existe cliente
			H hotel = tablaClientes.valorPara(c);
			Lista<C> listaClientes = arbolHoteles.valorPara(hotel);
			Lista<C>::Iterator it = listaClientes.begin();
			while (it.elem() != c) it.next();
			listaClientes.eliminar(it);
			arbolHoteles.inserta(hotel, listaClientes);
			tablaClientes.borra(c);
		}
		Lista<C> listaClientes;
		if (arbolHoteles.contiene(h)) {// hotel dado de alta
			listaClientes = arbolHoteles.valorPara(h);
		}
		
		listaClientes.pon_ppio(c);
		arbolHoteles.inserta(h, listaClientes);
		tablaClientes.inserta(c, h);
	}

	void desaloja(C c) {
		if (tablaClientes.contiene(c)) {
			H hotel = tablaClientes.valorPara(c);
			Lista<C> listaClientes = arbolHoteles.valorPara(hotel);
			Lista<C>::Iterator it = listaClientes.begin();
			while (it.elem() != c) it.next();
			listaClientes.eliminar(it);
			arbolHoteles.inserta(hotel, listaClientes);
			tablaClientes.borra(c);
		}
	}

	string alojamiento(C c) {
		if (!tablaClientes.contiene(c))throw "Cliente inexistente";
		H hotel = tablaClientes.valorPara(c);
		return hotel.nombre,
	}

	Lista<string> listadoHoteles() {
		Diccionario<H, Lista<C>>::Iterator it = arbolHoteles.begin();
		Lista<string> listaHoteles;
		while (it != arbolHoteles.end()) {
			listaHoteles.pon_ppio(it.elem().nombre);
			it.next();
		}
		return listaHoteles;
	}

	Lista<C> listadoHuespedes(H h) {
		Lista<C> listaHuespedes;
		if (arbolHoteles.contiene(h)) {
			listaHuespedes = arbolHoteles.valorPara(h);
		}
		return listaHuespedes;
	}

private:
	Diccionario<H, Lista<C>> arbolHoteles;
	DiccionarioHash<C, H> tablaClientes;




};


#endif