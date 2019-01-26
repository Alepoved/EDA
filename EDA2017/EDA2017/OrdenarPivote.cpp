#include <iostream>
using namespace std;

void particion(int v[], int a, int b, int pivote, int &p, int &q) {
	
	int aux,k;
	p = a; k = a; q = b;

	while (k <= q){
		if (v[k] == pivote)k++;
		else if(v[k]<pivote){
			aux = v[p]; v[p] = v[k]; v[k] = aux;
			k++; p++;

		}
		else {
			aux = v[q]; v[q] = v[k]; v[k] = aux;
			q--;
		}
	}
	
}


int main() {

	int v[1000],n=0,pivote=0;
	int p, q;

	cin >> n >> pivote;

	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	
	particion(v, 0, n-1, pivote, p, q);

	for (int i = 0; i<n; i++) {
		cout << v[i] << " ";
	}


	system("pause");
	return 0;


}