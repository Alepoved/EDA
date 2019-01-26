
#include <iostream>

using namespace std;


int calculaModa(int v[], int n) {
	int moda = 0, i = 1,modaAux=1;

	while (i < n) {
		if (v[i] == v[i - 1])modaAux++;
		else {
			if (modaAux > moda)moda = modaAux;
			modaAux = 1;
		}
		
		i++;
	}

	return moda;
}

bool resuelve() {
	
	int n;
	cin >> n;
	if (!cin)
		return false;

	int v[100000];
	for (int i = 0; i<n; ++i)
		cin >> v[i];

	int moda = calculaModa(v,n);
	cout << moda << endl;
	return true;
}

int main() {

	while (resuelve());

	return 0;
}
