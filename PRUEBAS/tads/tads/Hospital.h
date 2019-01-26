#ifndef __HOSP_H
#define __HOSP_H

#include <fstream>
#include <cstddef>
#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;

enum gravedad {grave,normal,leve};

class InfoPaciente {
public: 
	string nombre;
	int edad;
	string sintomas;

	InfoPaciente(string n, int e, string s) :
		nombre(n), edad(e), sintomas(s) {}

};

template<class I>
class Hospital {
public:
	void anPaciente(int codigo, string nombre, int edad, string sintomas, gravedad g) {
		if (tablaPacientes.contiene(codigo))throw "Paciente duplicado";
		InfoPaciente paciente(nombre, edad, sintomas);
		tablaPacientes.inserta(codigo, paciente);
		Lista<int> lista;
		if (arbolGravedad.contiene(g))lista = arbolGravedad.valorPara(g);
		lista.pon_final(codigo);
		arbolGravedad.inserta(g, lista);
	}

	I infoPaciente(int codigo) {
		if (!tablaPacientes.contiene(codigo))throw "Paciente inexistente";
		return tablaPacientes.valorPara(codigo);
	}

	void siguiente() {
		if (tablaPacientes.esVacio())throw "No hay pacientes";
		Diccionario<gravedad, Lista<int>>::Iterator it = arbolGravedad.begin();
		Lista<int> lista = it.valor();
		int codigo = lista.primero();
		lista.eliminar(lista.begin());
		if (lista.esVacia())arbolGravedad.borra(it.clave());
		else arbolGravedad.inserta(it.clave(), lista);
		tablaPacientes.borra(codigo);
	}

	void elimina(int codigo) {
		
	}

	

private:
	Diccionario<gravedad, Lista<int>> arbolGravedad;
	DiccionarioHash<int, I> tablaPacientes;
};




#endif

