#include <iostream>
using namespace std;


int suma(int solucion[], int etapa) {
	int suma = 0;

	for (int i = 0; i <= etapa; i++) {
		suma += solucion[i];

	}
	
	return suma;
}

void ordenar(int v[], int solucion[], bool disponibles[], int etapa, int n,int objetivo) {
	
	
	
	
	for (int i = 0; i < n; i++) {

		if (disponibles[i] && suma(solucion,etapa - 1) <= objetivo) {
			disponibles[i] = false;
			solucion[etapa] = v[i];
			if (suma(solucion, etapa) == objetivo) {
				cout << "---------" << endl;
				for (int j = 0; j <= etapa; j++)cout << solucion[j] << " ";
				cout << endl;
			}
			else {
				ordenar(v, solucion, disponibles, etapa + 1, n, objetivo);
				disponibles[i] = true;
			}

		}
	}

	

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

	ordenar(v, solucion, disponibles, 0, n,/*objetivo*/5);

	//for (int j = 0; j < n; j++)cout << solucion[j] << " ";


	return true;
}







int main() {


	while (resuelve());

	system("pause");
	return 0;
}

