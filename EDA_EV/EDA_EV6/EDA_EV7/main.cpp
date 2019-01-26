#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*int calcularTramos(const Arbin<int> &arbol, bool principio, int&esNaveg) {
	
	int aguaNodo = 0;

	if (!arbol.hijoDer().esVacio() || !arbol.hijoIz().esVacio()) { //Si no es una hoja

		if (arbol.hijoIz().esVacio()) { //Si unicamente existe hijo derecho
			aguaNodo += calcularTramos(arbol.hijoDer(), false, esNaveg);
		}
		else if (arbol.hijoDer().esVacio()) {//Si unicamente existe hijo izquierdo
			aguaNodo += calcularTramos(arbol.hijoIz(), false, esNaveg);
		}
		else { //Existen ambos hijos
			aguaNodo += calcularTramos(arbol.hijoIz(), false, esNaveg);
			aguaNodo += calcularTramos(arbol.hijoDer(), false, esNaveg);
		}

		if (arbol.raiz() != 0) aguaNodo += arbol.raiz();
		if (aguaNodo < 0) aguaNodo = 0;
	}

	else aguaNodo = 1; //Es una hoja y el caudal es 1

	if (!principio && aguaNodo >= 3) ++esNaveg; //Si no estamos en la raiz del arbol y el caudal es mayor que 3, tramo navegable

	return aguaNodo;
}*/


//Un tramo de rio es navegable si tiene un caudal >= 3
//Mirar por filas.
/*int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int esNaveg = 0;
	calcularTramos(cuenca, true, esNaveg);
	return esNaveg;
}*/

void esBusqueda(Arbin<int> arbol,bool &cierto) {
	

	if ((!arbol.hijoIz().esVacio() || !arbol.hijoIz().esVacio()) && cierto) {
		int raiz = arbol.raiz();
		if (arbol.hijoDer().esVacio()) {
			if (raiz < arbol.hijoIz().raiz())cierto = false;
			esBusqueda(arbol.hijoIz(), cierto);
		}
		else if (arbol.hijoIz().esVacio()) {
			if (raiz < arbol.hijoDer().raiz())cierto = false;
			esBusqueda(arbol.hijoDer(), cierto);
		}
		else {
			if (raiz < arbol.hijoIz().raiz())cierto = false;
			esBusqueda(arbol.hijoIz(), cierto);
			if (raiz > arbol.hijoDer().raiz())cierto = false;
			esBusqueda(arbol.hijoDer(), cierto);
		}



	}


	
}


Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF) {

		/*cout << numeroTramosNavegables(leeArbol(cin));*/
		bool cierto = true;
		esBusqueda(leeArbol(cin), cierto);
		string restoLinea;
		getline(cin, restoLinea);
		if (cierto)cout << "Siiii";
		else cout << "Noooooo";
		
		if (cin.peek() != EOF) cout << endl;
	}
	system("pause");
	return 0;
}