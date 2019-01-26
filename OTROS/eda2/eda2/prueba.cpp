/*#include <iostream>
using namespace std;

typedef int v[10];
typedef bool disponibles[10];
typedef int solucion[10];



bool ordenarAux(v v, solucion solucion, disponibles disponibles, int etapa);
void ordenar(v v, disponibles disponibles, solucion solucion);

int main() {

	v v;
	disponibles disponibles;
	solucion solucion;

	ordenar(v, disponibles, solucion);



	system("pause");

	return 0;
}

void ordenar(v v, disponibles disponibles, solucion solucion) {
	for (int i = 0; i < 5; i++) {
		disponibles[i] = true;
		cin >> v[i];
	}

	bool exito = ordenarAux(v, solucion, disponibles, 0);
	for (int i = 0; i < 5; i++) {
		cout << solucion[i] << " ";
	}

}

bool ordenarAux(v v, solucion solucion, disponibles disponibles, int etapa) {
	bool exito = false;
	for (int i = 0; i < 5 && !exito; i++) {
		if (disponibles[i]){
			if (!(etapa > 0 && solucion[etapa - 1] > v[i])) {
				disponibles[i] = false;
				solucion[etapa] = v[i];
				if (etapa == 4) exito = true;
				else {
					exito = ordenarAux(v, solucion, disponibles, etapa + 1);
					if (!exito)disponibles[i] = true;
				}
			}
		}
	}

	return exito;
	
}*/

/*
#include <iostream>
using namespace std;

typedef int tArray[100];

int calcular(int numero,tArray array, int iteracion,int i);


int  main() {

	tArray array;
	int numero = 0;
	cin >> numero;

	numero = calcular(numero,array, 0, 0);



	cout << "numero de cifras "<<numero << endl;
	for (int i = 0; i < numero; i++) {
		cout << array[i];
	}


	system("pause");
	return 0;
}

int calcular(int numero,tArray array,int iteracion,int i) {
	if (numero == 0)return i;
	else {
		int dig = numero % 10;
		cout << dig << endl;
		array[i] = dig;
		return calcular(numero / 10, array, iteracion + 1, i + 1);

	}

}*/
/*
#include <iostream>
using namespace std;

typedef int tArray[100];

int calcular(tArray array, int cont, int resultado);


int  main() {
	
	tArray array;
	int resultado = 0;

	for (int i = 0; i < 4; i++) {
		cin >> array[i];
	}

	resultado=calcular(array,0,0);

	cout << resultado << endl;


	system("pause");
	return 0;
}

int calcular(tArray array,int cont,int resultado) {
	if (cont == 3)return resultado;
	else {
		for (int i = cont+1; i < 4; i++) {
			resultado += array[cont] * array[i];
		}
		 calcular(array, cont + 1, resultado);
	}
	
}

*/

