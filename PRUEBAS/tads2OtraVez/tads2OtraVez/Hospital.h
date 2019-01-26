#ifndef HOS_H
#define HOS_H

#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"


enum gravedad{grave,normal,leve};

class InfoPaciente {
public:
	string nombre;
	int edad;
	gravedad g;
	Lista<int>::Iterator it;

	InfoPaciente(string n,int e,gravedad g, Lista<int>::Iterator it):
		nombre(n),edad(e),g(g),it(it) {}
};

template<class I>
class Hospital {

public:

	void anPaciente(int codigo, string nombre, int edad, gravedad g) {
		if (tablaPacientes.contiene(codigo))throw "Paciente duplicado";
		Lista<int> listaPacientes;
		if (arbolGravedad.contiene(g))listaPacientes = arbolGravedad.valorPara(g);
		listaPacientes.pon_ppio(codigo);
		Lista<int>::Iterator it = listaPacientes.begin();
		I paciente(nombre, edad, g,it);
		arbolGravedad.inserta(g, listaPacientes);//log nGravedades
		tablaPacientes.inserta(codigo, paciente);

	}

	string infoPaciente(int codigo) {
		if (!tablaPacientes.contiene(codigo))throw "Paciente inexistente";
			I paciente = tablaPacientes.valorPara(codigo);
		return paciente.nombre;
	}

	void siguiente() {
		if (tablaPacientes.esVacio())throw "No hay pacientes";
		Diccionario<gravedad, Lista<int>>::Iterator it = arbolGravedad.begin();
		gravedad g = it.clave();
		Lista<int> lista = it.valor();
		int codigo = lista.ultimo();
		lista.quita_final();
		if (lista.esVacia())arbolGravedad.borra(g);
		else arbolGravedad.inserta(g, lista);
		tablaPacientes.borra(codigo);

	}

	bool hayPacientes() {
		return !tablaPacientes.esVacio();
	}

	void elimina(int codigo) {
		if (tablaPacientes.contiene(codigo)) {
			I paciente = tablaPacientes.valorPara(codigo);
			gravedad g = paciente.g;
			Lista<int> lista = arbolGravedad.valorPara(g);
			lista.eliminar(paciente.it);
			if (lista.esVacia())arbolGravedad.borra(g);
			else arbolGravedad.inserta(g, lista);
			tablaPacientes.borra(codigo);
		}
	}



private:
	
	Diccionario<gravedad, Lista<int>> arbolGravedad;
	Diccionario<int, I> tablaPacientes;

};


#endif