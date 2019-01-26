#include <iostream>
using namespace std;



int sumaMiradores(int v[], int n) {
	int suma, i=n-1;


	suma = v[i];

	while (i > 0) {
		if (v[i - 1] > v[i])suma += v[i - 1];
		i--;
	}




	return suma;
}

bool resuelve() {

	int n;
	cin >> n;

	if (n==0)return false;

	int v[100000];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int suma = sumaMiradores(v, n);
	cout << suma << endl;


	return true;
}


int main() {



	while (resuelve());


	system("Pause");
	return 0;
}