#include <iostream>
#include <string>
#include "Stack.h"


using namespace std;
int main(){
	Stack<int> pila;
	int numeroEntero, elemento;
	int suma;
	cin >> numeroEntero;
	while (numeroEntero != -1){
		suma = 0;
		elemento = numeroEntero % 10;
		numeroEntero = numeroEntero / 10;
		while (numeroEntero != 0 || elemento != 0){				
			pila.push(elemento);				// Coste constante el añadir un elemento.
			elemento = numeroEntero % 10;
			numeroEntero = numeroEntero / 10;
		}
		while (pila.size() > 0){				// Coste del orden del tamaño de la pila.
			cout << pila.top();
			suma = suma + pila.top();
			pila.pop();
			if (pila.size()) cout << " + ";
		}
		cout << " = " << suma << "\n";
		cin >> numeroEntero;
	}

	system("pause");
	return 0;
}