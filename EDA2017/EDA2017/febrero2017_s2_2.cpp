#include <iostream>
using namespace std;


int hallaDiferente(int v[],int a, int b,int n) {
	int pos, mitad;
	mitad = (a + b) / 2;
	if (a +1== mitad) {
		if (v[a] == v[mitad])pos = b;
		else pos = a;
	}
	else {
		if ((n - mitad) % 2 == 0) {
			if (v[mitad] == v[mitad - 1])pos = hallaDiferente(v, a, mitad, n);
			else pos = hallaDiferente(v, mitad, b, n);
		}
		
		
		else {
			if ( v[mitad] != v[mitad - 1])pos = hallaDiferente(v, a, mitad-1, n);
			else pos = hallaDiferente(v, mitad + 1, b, n);
		}
		
		
	}




	return pos;

}

void resuelve() {


	int n;
	int v[1000];
	cin >> n;

	for (int i = 0; i < n; i++)cin >> v[i];

	int sol=hallaDiferente(v,0, n - 1,n-1);
	cout << sol << endl;

}
int main() {

	int tam;

	cin >> tam;
	for (int i = 0; i < tam; i++)resuelve();

	system("pause");
	return 0;
}