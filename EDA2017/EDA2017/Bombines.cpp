#include <iostream>
#include <stdlib.h>

using namespace std;

int bombines(int v[], int n) {
	int dia = 0, i = 0,j=0,k=0;
	int acumD = 0, acumI = 0,acumF=100;

	while (i < n) {
	
		j = i;
		while (j >= 0) {
			acumI += abs(v[j]);
				j--;
		}
		k = i+1;
		while (k < n) {
			acumD += abs(v[k]);
			k++;
		}


		if (acumD >= acumI && acumD - acumI < acumF) {
			acumF = acumD - acumI;
			dia = i + 1;
		}
		if (acumD < acumI && acumI - acumD < acumF) {
			acumF = acumI - acumD;
			dia = i + 1;
		}

		acumI = 0;
		acumD = 0;
		i++;


	}






	return dia;
}



bool resuelve() {

	int n, resultado;
	cin >> n;
	if (n == 0)
		return false;


	int v[100000];
	for (int i = 0; i<n; ++i)
		cin >> v[i];

	resultado = bombines(v, n);

	cout << resultado << endl;

	return true;
}

int main() {

	while (resuelve())
		;

	return 0;
}
