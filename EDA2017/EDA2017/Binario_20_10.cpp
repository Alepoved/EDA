#include <iostream>
using namespace std;

int calculaDecimal(int v[], int n) {

	int decimal = 0;
	int p = 1;

	for (int i = n-1; i >= 0; --i) {
		if (v[i] == 1) {
		//	decimal += pow(2, n-i-1);
			decimal += p;
		}
		p *= 2;
	}



	return decimal;
}

bool resuelve() {

	int n;
	cin >> n;
	if (!cin)return false;


	int v[100];
	for (int i =0; i < n; i++)
		cin >> v[i];

	int decimal = calculaDecimal(v, n);
	
	cout << decimal << endl;
	return true;
}





int main() {


	while (resuelve());

	system("Pause");

	return 0;
}