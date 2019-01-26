#include <iostream>
using namespace std;



bool ordenar(int v[], int solucion[], bool disponibles[], int etapa, int n) {

	bool exito = false;
	for (int i = 0; i < n && !exito; i++) {
		if (disponibles[i]) {
			if (!(etapa>0 && solucion[etapa - 1]>v[i])) {
				disponibles[i] = false;
				solucion[etapa] = v[i];
				if (etapa == n-1)exito = true;
				else {
					exito = ordenar(v, solucion, disponibles, etapa + 1,n);
					if (!exito) disponibles[i] = true;
				}

			}
		}
	}

	return exito;

}


bool resuelve() {


	int n;
	cin >> n;

	int  v[100000];
	bool disponibles[100000];
	int solucion[100000];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		disponibles[i] = true;
	}

	ordenar(v, solucion, disponibles, 0, n);

	for (int j = 0; j < n; j++)cout << solucion[j] << " ";


	return true;
}







int main() {


	while (resuelve());

	system("pause");
	return 0;
}




