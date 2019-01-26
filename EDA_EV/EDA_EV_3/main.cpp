#include <iostream>
#include <string>
#include "pila.h"


using namespace std;



bool esEquilibrada(const string& cadena) {
	bool fallo = true;
	Pila<char> pila;

	int i = 0;

	while (i < cadena.length() && fallo) {
		if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') pila.apila(cadena[i]);

		else {
			if (cadena[i] == ')') {
				if (pila.esVacia() || pila.cima() != '(')fallo = false;
				else pila.desapila();
			}
		
			if (cadena[i] == '}') {
				if (pila.esVacia() || pila.cima() != '{')fallo = false;
				else pila.desapila();
			}
				
		
			if (cadena[i] == ']') {
				if (pila.esVacia() || pila.cima() != '[')fallo = false;
				else pila.desapila();
			}
				
	
		}
		i++;
	}
	
	if (!pila.esVacia()) fallo = false;
	pila.~Pila();

	return fallo;
}


int main() {
	string cadena;
	while (getline(cin, cadena)) {
		if (esEquilibrada(cadena))
			cout << "EQUILIBRADA" << endl;
		else
			cout << "NO_EQUILIBRADA" << endl;
	}
	return 0;
}
