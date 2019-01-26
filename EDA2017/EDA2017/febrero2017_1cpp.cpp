#include <iostream>
using namespace std;

int ordenaPivote(int v[],int pivote, int a, int b) {
	int pos,aux;
	if (a == b) {
		pos = a;
	}
	else {
		if (v[a] >= 0)pos = ordenaPivote(v, pivote, a + 1, b);
		else if (v[b] < 0)pos = ordenaPivote(v, pivote, a, b - 1);
		else {
			aux = v[a]; v[a] = v[b]; v[b] = aux;
			pos = ordenaPivote(v, pivote, a + 1, b - 1);
		}
	}

	return pos;
}

void resuelve() {

	int n, p = 0, k = 0;
	int v[10000];

	cin >> n;

	for (int i = 0; i < n; i++)cin >> v[i];

	int resultado = ordenaPivote(v, 0, 0, n - 1);

	cout << resultado << endl;

	for (int i = 0; i<n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "-------------------" << endl;
}
int main() {


	int num;

	cin >> num;

	for (int i = 0; i < num; i++)resuelve();
	

	system("pause");
	return 0;
}