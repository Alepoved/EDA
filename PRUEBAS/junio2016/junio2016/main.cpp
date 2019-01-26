#include <iostream>
using namespace std;
#include <string>
#include "lista.h"






// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {

}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {

		mensaje.pon_final(12,'K');
		mensaje.pon_final(12, 'N');
		mensaje.pon_final(15, 'F');
		mensaje.pon_final(15, 'T');
		mensaje.pon_final(15, 'Z');
		mensaje.pon_final(16, 'A');
		mensaje.sumaUno('K');
	
}

void cosas() {
	/*Lista<char> l1;
	Lista<char> l2;
	
	l1.pon_final('A');
	l1.pon_final('B');
	l1.pon_final('C');
	l1.pon_final('D');

	l2.pon_final('Z');
	l2.pon_final('Y');
	l2.pon_final('M');
	l2.pon_final('N');
	l2.pon_final('T');
	l2.pon_final('H');
	l2.pon_final('L');
	l2.pon_final('J');

	l1.splice(l2, 'C', 'N', 'T');

	imprime(l1);
	imprime(l2);*/
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		//cosas();
		imprime(mensaje);
	}
	return 0;
}