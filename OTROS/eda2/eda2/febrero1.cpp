#include <iostream>
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

	ordenar(v,disponibles,solucion);
	


	system("pause");

	return 0;
}

void ordenar(v v,disponibles disponibles,solucion solucion) {
	for (int i = 0; i < 10; i++) {
		disponibles[i] = true;
	}

	for (int i = 0; i < 10; i++) {
		cin >> v[i];
	}
	bool ok = ordenarAux(v, solucion, disponibles, 0);
	if (!ok)cout << "No se puede ordenar" << endl;
	else
		for (int i = 0; i < 10; i++) {
			cout << solucion[i]<<endl;
		}


}

bool ordenarAux(v v, solucion solucion, disponibles disponibles, int etapa) {

	bool exito = false;
	for (int i = 0; i < 10 && !exito; i++) {
		if (disponibles[i]) {
			if (!(etapa<0 && solucion[etapa - 1]>v[i])) {
				disponibles[i] = false;
				solucion[etapa] = v[i];
				if (etapa == 9)exito = true;
				else {
					exito = ordenarAux(v, solucion, disponibles, etapa+1);
					if (!exito) disponibles[i] = true;
				}

			}
		}
	}
	
	return exito;
}