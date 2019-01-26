#include <iostream>
using namespace std;

/*bool compruebaOrdenados(int v[], int solucion[],bool disponibles[], int pivote, int n,int etapa) {

	bool exito = false;

	for (int i = 0; i < pivote && !exito; i++) {

		if (disponibles[i] && v[etapa - 1] < v[i]) {
			disponibles[i] = false;
			solucion[etapa] = v[i];
			if (pivote == etapa)exito = true;
			else {
				exito = compruebaOrdenados(v, solucion, disponibles, pivote, n, etapa + 1);
				if (!exito)disponibles[i] = true;
			}
		}

	}

	return exito;

}*/


bool creciente(int v[], int a, int b,bool inicio) {

	if (!inicio) {
		if ((v[b] - v[a]) <= (b - a))return true;
		else return false;
	}
	inicio = false;
	bool iz, de, end=true;
	int mitad = (a + b) / 2;
	iz = creciente(v, a, mitad, inicio);
	de = creciente(v, mitad + 1, b, inicio);
	if ((v[mitad + 1] - v[mitad]) > 1)end = false;

	return iz && de && end;

}


int main() {

	int v[1000], n;
	while (1) {
		cin >> n;

		for (int i = 0; i < n; i++)cin >> v[i];

		bool cond = creciente(v, 0, n - 1, true);

		if (cond)cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}