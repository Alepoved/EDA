#include <iostream>
using namespace std;



int calculaFuncion(int v[], int n) {

	int suma=0, aux=0,aux2;
	aux = v[n - 1];
	aux2 = v[n-1];
	for (int i = n-1; i >=0; i--) {
	if(i!=1)aux2 = v[i-1] + aux2;
		suma += v[i-1]*aux;
		aux = aux2;
	}




	return suma;
}

int main(){

	int v[100];
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++)cin >> v[i];

	int suma=calculaFuncion(v, n);

	cout << suma << endl;

	system("pause");
	return 0;
}