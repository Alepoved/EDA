#include <iostream>
using namespace std;

long long int suma(long long int isbn, int& ndigitos) {
	
	int r;

	if (isbn <= 9) {
		r = isbn;
		ndigitos = 1;
	}
	else {
		r = suma(isbn / 10, ndigitos);
		if (ndigitos % 2 == 1)r += isbn % 10 * 3;
		else r += isbn % 10;
		ndigitos++;
	}
	return r;
}
//mi version
void sumaDigitos(int num, int &suma, int n, int etapa) {

	if (etapa == n) {
		suma = num * 1;
	}
	else {
		sumaDigitos(num / 10, suma, n, etapa + 1);
		if (etapa % 2 == 0)suma += num % 10 * 3;
		else suma += num % 10 * 1;
	}

}

long long int sumaFinal(long long int isbn, int ndigitos,int sumaP,int sumaI) {

	int r;

	if (isbn <= 9) {
		r = sumaP*3 + sumaI+isbn;
	}
	else {
		if (ndigitos % 2 == 0)r = sumaFinal(isbn / 10, ndigitos + 1, sumaP+isbn % 10, sumaI);
		else r = sumaFinal(isbn / 10, ndigitos + 1,sumaP , sumaI+isbn % 10);
	}




	return r;
}


int main() {

	long long int isbn;
	int nDigitos=12;

	cin >> isbn;

	//long long int resultado = suma(isbn, nDigitos);
	long long int resultado2 = sumaFinal(isbn, nDigitos, 0, 0);
	//cout << resultado << endl;

	cout << resultado2 << endl;

	system("pause");
	return 0;
}