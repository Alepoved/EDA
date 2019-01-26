#include <iostream>
using namespace std;


int cuentaDistintos(int v[], int a, int b, bool inicio, int &count, int &pivote) {

	int mitad = (a + b) / 2;

	if (!inicio) {
		if ((v[b] - v[a]) == 0) {
			if (pivote != v[b]) {
				pivote = v[b]; return count + 1;
			}
			else return count;
		}
	}
	inicio = false;
	int iz = cuentaDistintos(v, a, mitad, inicio, count, pivote);
	int de = cuentaDistintos(v, mitad + 1, b, inicio, count, pivote);

	return iz + de;
}

bool resuelve() {

	int v[10000], n, count = 0, pivote = 0;

	cin >> n;

	for (int i = 0; i < n; i++)cin >> v[i];


	int num = cuentaDistintos(v, 0, n - 1, true, count, pivote);

	cout << num << endl;


	return true;
}
int main() {


	while (resuelve());


	system("pause");
	return 0;
}