#include "Lista.h"
#include <iostream>
#include <string>
using namespace std;

/**
Este programa lee por la entrada est�ndar l�neas con el siguiente formato:
- Una secuencia de enteros (excluido el -1), que se interpreta como una
cola.
- El -1 (centinela que marca el final de la cola)
- Una posici�n (entero >= 0)
Entonces, ejecuta la operaci�n 'llevarAlPrincipio' sobre la cola indicada, y escribe
por pantalla el resultado (o POSICION_INVALIDA en caso de que la posici�n no sea v�lida)


*/

// Imprime la lista por la salida estandar
void imprime(const Lista<int>& l) {
	l.print();
	cout << endl;
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const int num, Lista<int>& mensaje) {
		mensaje.pon_final();
		mensaje.pon_final();
		mensaje.pon_final();
		mensaje.pon_final();
}

int main() {
	int num; Lista<int> mensaje;
	cin >> num;
	while (num!=-1) {
		
		construyeMensaje(num, mensaje);
		cin >> num;
		
	}
	mensaje.CambiarPosiciones();
	imprime(mensaje);
	system("pause");
	return 0;
}
