#include <iostream>
using namespace std;


void imagenEspecular(int num,int etapa) {
	
	int solucion;
	if (num <= 10)cout << num;
	else {

		cout << num % 10;
		num /= 10;
		imagenEspecular(num, etapa + 1);

	}


	
}





int main() {

	int v[100];
	int n;
	int num;
	cin >> num;


	imagenEspecular(num,0);
	

	system("pause");
	return 0;
}