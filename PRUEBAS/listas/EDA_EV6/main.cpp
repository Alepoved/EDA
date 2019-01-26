#include <iostream>
using namespace std;
#include <string>
#include "lista.h"
#include "pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS


bool esVocal(char letra) {
	return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {

	Lista<char>::Iterator it = mensaje.begin();
	Lista<char>::Iterator it2 = mensaje.begin();
	Pila<char> pila;

	while (it2 != mensaje.end()) {
		if (!esVocal(it2.elem())) {
			pila.apila(it2.elem());
			it2.next();
		}
		else {
			while (!pila.esVacia()) {
				it.set(pila.cima());
				it.next();
				pila.desapila();
			}
			it2.next();
			it = it2;

		}
	}

	while (!pila.esVacia()) {
		it.set(pila.cima());
		it.next();
		pila.desapila();
	}

}


// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	try {
		invierteSecuenciasNoVocales(mensaje);
		mensaje.enredar();
	}
	catch (EListaVacia) {}
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for (unsigned int i = 0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		codifica(mensaje);
		imprime(mensaje);
	}
	return 0;
}