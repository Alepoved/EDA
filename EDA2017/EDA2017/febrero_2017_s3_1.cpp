#include <iostream>
using namespace std;

void eliminaImpares(int v[], int a, int b,int n) {
	
	if (b<=n) {
		if (v[a] % 2 == 0)eliminaImpares(v, a + 1, b + 1,n);
		else if (v[b] % 2 != 0)eliminaImpares(v, a, b + 1,n);
		else {
			int aux = v[a]; v[a] = v[b]; v[b] = aux;
			eliminaImpares(v, a + 1, b + 1,n);
		}
	}
	else {
		for (int i = a; i < n+1; i++)v[i] = -1;
	}

}


bool resuelve() {

	int v[10000], n;
	cin >> n;

	for (int i = 0; i < n; i++)cin >> v[i];

	eliminaImpares(v, 0, 1,n-1);

	for (int i = 0; i < n; i++) {
		if (v[i] == -1)cout << " ";
		else cout << v[i] << " ";
		
	}

	return true;

}
int main() {

	while (resuelve());


	system("pause");
	return 0;
}