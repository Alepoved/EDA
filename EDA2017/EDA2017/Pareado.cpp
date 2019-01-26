#include<iostream>
using namespace std;


int contarPares(int v[], int a, int b) {
	int numPares = 0;

	for (int i = a; i < b; i++) {

		if (v[i]%2==0)numPares++;
	}



	return numPares;
}


bool pareado(int v[], int i, int j) {
	bool b=false;

	if (j <= i + 1)b = true;
	else
		b = abs((contarPares(v, i, (i+j)/2) - contarPares(v, (i+j)/2, j)) <= 1) && pareado(v, i, (i + j) / 2) && pareado(v, (i + j) / 2, j);

	return b;
}




bool resuelve(){
	int n;

	cin >> n;

	int v[10000];

	for (int i = 0; i < n; i++)cin >> v[i];

	bool resultado = pareado(v,0,n);

	cout << resultado << endl;



	return true;
}


int main() {

	while (resuelve()) {

	}


	system("pause");
	return 0;
}