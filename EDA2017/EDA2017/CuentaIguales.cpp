#include <iostream>
using namespace std;




int cuentaIguales(int v[], int n, int i, int sumaIz, int sumaDe) {
	int resultado;
	sumaDe = v[i];
	if (i == n - 1)resultado = 0;
	else {
		resultado = cuentaIguales(v, n, i + 1, sumaIz + v[i], sumaDe);
		if (sumaIz == sumaDe)resultado++;
		sumaIz + v[i];
	}


	return resultado;
}


bool resuelve() {

	int n;
	int sumaDe;
	cin >> n;
	if (n == 0)return false;

	int v[10000];
	for (int i = 0; i < n; i++)cin >> v[i];
	
	int resultado = cuentaIguales(v, n, 1, 0, 0);



	return true;

}






int main() {


	while (resuelve());

	return 0;
}