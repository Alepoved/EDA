#include <iostream>

using namespace std;


bool calculaTriangular(int v[100][100], int n) {
	bool triangular = true;

	for (int i = 0; i < n && triangular; i++) {
		for (int j =i+1; j < n &&triangular; j++) {
			if (v[j][i] != 0)triangular = false;
		}
	}



	return triangular;


}



void resuelve() {
	
	int n;
	cin >> n;

	int v[100][100];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	bool triangular = calculaTriangular(v, n);
	if (triangular)cout << "si" << endl;
	else cout << "no" << endl;

}

int main() {

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelve();
	}



	system("Pause");
	return 0;
}