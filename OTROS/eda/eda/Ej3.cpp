#include <iostream>
using namespace std;

const int MAX = 10000;

typedef int tArray[MAX];
bool particion(tArray array, int n, int p);


int main() {
	tArray array;
	int n=0,p=0,numCasos=0;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> n;
		cin >> p;
		for (int j = 0; j < n; j++) {
			cin >> array[j];
		}
		if (particion(array,n,p))cout << "SI" << endl;
		else cout << "NO" << endl;
	}

	system("pause");
	return 0;

}

bool particion(tArray array,int n,int p) {
	//0<n<10.000 y 0<=p<n;
	bool ok = true;
	int i = 0;

	while (i <= p && ok) {
	
		for (int j = p+1; j < n; j++) {
			if (array[i] >= array[j]) ok = false;
		}
		i++;
	}
	//q== b=forall u,w  0<=u<=p<w<n: a[u]<a[w];
	
	return ok;
}