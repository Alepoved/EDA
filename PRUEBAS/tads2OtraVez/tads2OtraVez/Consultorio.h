#ifndef CONS_H
#define CONS_H

#include"diccionario.h"
#include "DiccionarioHash.h"
#include"lista.h"




class Consultorio{

public:

	void nuevoMedico(string medico) {//constante
		if (tablaMedicos.contiene(medico))throw "Medico duplicado";
		Diccionario<int, string> arbol;
		tablaMedicos.inserta(medico, arbol);
	}

	void pideConsulta(string paciente, string medico, int fecha) {//log n de fechas para un medico
		if (!tablaMedicos.contiene(medico))throw "Medico inexistente";
		Diccionario<int, string> arbol = tablaMedicos.valorPara(medico);
		if (arbol.contiene(fecha))throw "Fecha ocupada";
		arbol.inserta(fecha, paciente);
		tablaMedicos.inserta(medico, arbol);
	}

	string siguientePaciente(string medico) {//constante
		if (!tablaMedicos.contiene(medico))throw "Medico inexistente";
		Diccionario<int, string> arbol = tablaMedicos.valorPara(medico);
		Diccionario<int, string>::Iterator it = arbol.begin();
		return it.valor();
	}

	void atiendeConsulta(string medico) {//log n pacientes
		if (!tablaMedicos.contiene(medico))throw "Medico inexistente";
		Diccionario<int, string> arbol = tablaMedicos.valorPara(medico);
		Diccionario<int, string>::Iterator it = arbol.begin();
		int fecha = it.clave();
		arbol.borra(fecha);
		tablaMedicos.inserta(medico, arbol);
	}

	Lista<string> listaPacientes(string medico) {//log n pacientes dado un medico
		if (!tablaMedicos.contiene(medico))throw "Medico inexistente";
		Diccionario<int, string> arbol = tablaMedicos.valorPara(medico);
		Diccionario<int, string>::Iterator it = arbol.begin();
		Lista<string> lista;
		while (it != arbol.end()) {
			lista.pon_final(it.valor());
			it.next();
		}
		return lista;
	}

	
	

private:
	
	DiccionarioHash<string, Diccionario<int, string>> tablaMedicos;



};


#endif