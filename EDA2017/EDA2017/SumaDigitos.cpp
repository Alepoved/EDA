#include <iostream>
using namespace std;

typedef int tArray[15];

long long int sumar_dig(long long int n, tArray, long long int cont, int i);


int main() {

	int i = 0, it = 0;
	tArray array;
	long long int n;
	bool exito = false;

	cin >> n;

	int resultado;

	resultado = sumar_dig(n, array, 0, 0);

	cout << resultado << endl;

	while (!exito) {
		if (resultado > it * 10)it++;
		else {
			resultado = it * 10 - resultado;
			exito = true;
		}

	}

	cout << resultado << endl;


	system("pause");
	return 0;
}

long long int sumar_dig(long long int n, tArray array, long long int cont, int i)
{

	if (n == 0)      //caso base
		return cont;
	else {
		int dig = n % 10;
		cout << dig << endl;
		array[i] = dig;
		if (i % 2 == 0)cont += dig * 3;
		else cont += dig;
		return sumar_dig(n / 10, array, cont, i + 1);

	}


}

