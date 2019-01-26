#include <iostream>
using namespace std;

typedef int Array[20][20];
typedef bool disponibles[20][20];
typedef int solucion[20];

void ordenar(Array array, disponibles disponibles, solucion  solucion, int etapa,int numF,int numC);
bool ordenarAux(Array array, disponibles disponibles, solucion solucion, int etapa,int numF, int numC);

int main() {
	int numCasos,numF,numC;
	solucion solucion;
	Array array;
	disponibles disponibles;
	cin >> numCasos;
	
	for (int i = 0; i < numCasos; i++) {
		cin >> numF; cin >> numC;

		for (int i = 0; i < numF; i++) {
			for (int j = 0; j < numC; j++) {
				cin >> array[i][j];
			}
		}
		ordenar(array, disponibles, solucion, 0,numF,numC);

	}
	

	system("pause");
	return 0;
}

void ordenar(Array array, disponibles disponibles, solucion  solucion, int etapa,int numF,int numC) {
	
	int resultado = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			disponibles[i][j] = true;
			
		}
	}



	bool exito = ordenarAux(array, disponibles, solucion, etapa,numF,numC);

	for (int i = 0; i < numC; i++) {
		resultado += solucion[i];
	}

	if (exito)cout << resultado << endl;
	else cout << "NADA" << endl;
}

bool ordenarAux(Array array, disponibles disponibles, solucion solucion, int etapa,int numF,int numC) {
	bool exito = false;
	
	for(int j = 0; j < numF && !exito; j++) {
		for (int i = 0; i < numC && !exito; i++) {
			if (disponibles[i][j]) {
				if (!(etapa < 0 && solucion[etapa-1]>array[i][j])){
					disponibles[i][j] = false;
					solucion[etapa] = array[i][j];
					if (etapa == numC)exito = true;
					else {
						exito = ordenarAux(array, disponibles, solucion, etapa + 1,numF,numC);
						if (!exito)disponibles[i][j] = true;
					}
				}

			}
		}

		
	}

	return exito;
}


