#include <iostream>
using namespace std;
#include <string>
#include "lista.h"
#include "pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS


bool esVocal(const char letra) {
	return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');

}


void invierteSecuenciasNoVocales(Lista<char> &mensaje) {

	Pila<char> pila;
	Lista<char>::Iterator it = mensaje.begin();
	Lista<char>::Iterator itAux = mensaje.begin();
	
	if (mensaje.esVacia()) throw EListaVacia();//si la lista esta vacia lanzamos la excepcion 
	
	while (it != mensaje.end()) {
		if (!esVocal(it.elem()) ) {
			pila.apila(it.elem());
			it.next();
		}
		else {
			while (!pila.esVacia()) {
				itAux.set(pila.cima());
				pila.desapila();
				itAux.next();
			}
			it.next();
			itAux = it;
			
		}
		
	}
	while (!pila.esVacia()) {
		itAux.set(pila.cima());
		pila.desapila();
		itAux.next();
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
		//mensaje.enredar();
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