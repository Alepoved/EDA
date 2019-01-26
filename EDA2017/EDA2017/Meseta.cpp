#include <iostream>

using namespace std;



void calculaMeseta(int v[], int n, int &ini, int &fin) {
	bool masLarga = true;
	ini = 0; fin = 0;
	int i = 0, aMax = 0, frec = 1, frecAux = 1, j = 1,nueva;

	while (i < n) {
	
			nueva = v[i];
			while ( nueva == v[j]) {
				j++; frecAux++;
			}
			if (frecAux >= frec) {
				ini = i;
				fin = j-1;
				frec = frecAux;
				frecAux = 1;
				i = j-1;
			}
			i++;
			j++;
}

	

}


bool resuelve() {
	
	int n, ini, fin;
	cin >> n;
	if (n == 0)
		return false;

	
	int v[100000];
	for (int i = 0; i<n; ++i)
		cin >> v[i];

	calculaMeseta(v, n, ini, fin);

	cout << ini << " " << fin << endl;
	
	return true;
}

int main() {

	while (resuelve())
		;

	return 0;
}
