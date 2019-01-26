#ifndef TEL_H
#define TEL_H

#include"diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"


class Hora {
public:
	int hora, min;

	Hora(int h, int m) :
		hora(h), min(m) {}


	bool operator == (const Hora &h)const {
		return (hora == h.hora && min == h.min);
	}

	bool operator < (const Hora &h)const {
		if (hora < h.hora)return true;
		else if (hora == h.hora) {
			if (min < h.min)return true;
		}
		return false;
	}
};

class Fecha {
public:
	int dia, mes;
	Hora hora;

	Fecha(int d, int m,Hora h) :
		dia(d), mes(m),hora(h) {}

	bool operator == (const Fecha &f)const {
		return (dia == f.dia && mes == f.mes && hora == f.hora);
	}

	

	Hora operator + (int &h) {
		hora.min += h;
		if ((hora.min) > 60) {
			hora.min -= 60; hora.hora++;
		}
		if (hora.hora > 24)
			dia++; hora.hora -= 24;
	}

};

class InfoGrabacion {
public:
	int duracion;
	Fecha fecha;

	InfoGrabacion(int d, Fecha f) :
		duracion(d), fecha(f) {}

};



class Television {
public:

	void grabar(string nombre, Fecha fecha,int duracion) {
		if (tablaGrabadas.contiene(nombre)) {
			InfoGrabacion grabacion = tablaGrabadas.valorPara(nombre);
			if (grabacion.fecha == fecha)
				tablaGrabadas.borra(nombre);
		}
		else {
			InfoGrabacion grabacion(duracion, fecha);
			tablaGrabadas.inserta(nombre, grabacion);
		}
	}

	void programar(string nombre, Fecha fecha, int duracion) {
		if (!tablaGrabadas.contiene(nombre))throw "Grabacion ya existe";
		if (arbolProgramadas.contiene(fecha.dia)) {
			Diccionario<Hora, string> arbol = arbolProgramadas.valorPara(fecha.dia);
			arbol.inserta(fecha.hora, nombre);
			Diccionario<Hora, string>::Iterator it = arbol.busca(fecha.hora);
			it.next();
			Hora horaSig = it.clave();
			if (fecha + duracion < horaSig)
				arbolProgramadas.inserta(fecha.dia, arbol);
		}
	}


private:

	Diccionario<int, Diccionario<Hora,string>> arbolProgramadas;
	DiccionarioHash<string, InfoGrabacion> tablaGrabadas;
	
};



#endif