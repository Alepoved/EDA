#ifndef __CONS_H
#define __CONS_H

#include <fstream>
#include <cstddef>
#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;

class Fecha {
public:
	int año, mes, dia;

	Fecha(int a, int m, int d) :
		año(a), mes(m), dia(d) {}

	bool operator == (const Fecha & f)const {
		return dia == f.dia && mes == f.mes && año == f.año;
 }

	bool operator < (Fecha & f)const {
		if (año < f.año)return true;
		else if (año == f.año) {
			if (mes < f.mes) return true;
			else if (mes == f.mes) {
				if (dia < f.dia)return true;
			}
		}
		return false;
	}

};

template <class A,class B>
class Consultorio {

public:

	Consultorio() {}

	void nuevoMedico(string nombreM) {
		if (!tablaMedicos.contiene(nombreM)) {
			Diccionario<Fecha,string> arbol;
			tablaMedicos.inserta(nombreM,arbol);
		}
	}

	void pideConsulta(string paciente, string medico, Fecha fecha) {
		if (!tablaMedicos.contiene(medico))throw "El medico no existe";
		Diccionario<Fecha,string> arbol = tablaMedicos.valorPara(medico);
		if (arbol.contiene(fecha))throw "Fecha ocupada";
		arbol.inserta(fecha, paciente);
		tablaMedicos.inserta(medico, arbol);
	}

	string siguientePaciente(string medico) {
		if (!tablaMedicos.contiene(medico))throw "Medico no existente";
		Diccionario<Fecha,string> arbol = tablaMedicos.valorPara(medico);
		if (arbol.esVacio())throw "No hay pacientes";
		Diccionario<Fecha, string>::Iterator it = arbol.begin();//La menor fecha es la raiz
		Fecha fecha = it.clave();
		string paciente = arbol.valorPara(fecha);
		return paciente;
	}

	void atiendeConsulta(string medico) {
		if (!tablaMedicos.contiene(medico))throw "Medico no existente";
		Diccionario<Fecha, string> arbol = tablaMedicos.valorPara(medico);
		if (arbol.esVacio())throw "No hay pacientes";
		Diccionario<Fecha, string>::Iterator it = arbol.begin();//La menor fecha es la raiz
		Fecha fecha = it.clave();
		arbol.borra(fecha);
		tablaMedicos.inserta(medico, arbol);
	}

	Lista<string> listaPacientes(string medico) {
		if (!tablaMedicos.contiene(medico))throw "Medico no existente";
		Diccionario<Fecha, string> arbol = tablaMedicos.valorPara(medico);
		Diccionario<Fecha, string>::ConstIterator it = arbol.cbegin();
		Lista<string> lista;
		while (it != arbol.cend()) {
			lista.pon_final(it.valor());
			it.next();
		}
		return lista;
	}
private:
	DiccionarioHash<A, B> tablaMedicos;

};





#endif // __DICCIO2_H
