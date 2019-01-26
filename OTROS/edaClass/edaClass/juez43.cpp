#include <iostream>
#include "juez43.h"
#include <string>


void recursion(std::string numeros);

/*

int main() {
	std::string numeros;
	float real, imaginario;
	int iteraciones;
	Juez43<float> Juez43Zn(0, 0);
	getline(std::cin,numeros);
	while (numeros != "-1") {
		recursion(numeros);

	}
		
	
	return 0;
}

/**/
void recursion(std::string numeros) {
	//Complejo<float> resul;
	int resultado = 0;

	for (int i = 0; i < numeros.length(); i++) {
		std::cout << numeros[i] << " + ";
		resultado += numeros[i];
	}
	;
	std::cout << " = " << resultado << "\n";

}




