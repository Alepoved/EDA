#include <iostream>
#include <math.h>


using namespace std;

typedef int tArray[13];

// Lo que hacemos es ir dividiendo el número entre 10, entre 100, entre 1000... Hasta que el número y el resto den lo mismo.
int cuantasCifras(long long int numero) {
	long long int divisor = 10;
	long long int residuo = 0;
	long long int cifras_aux = 0;

	while (residuo != numero) {
		residuo = numero % divisor;
		divisor = divisor * 10;
		cifras_aux++;
	}
	cifras_aux--;
	return cifras_aux;
}

void dividir_en_digitos(long long int numero, long long int cifras) {

	tArray array;
	long long int divisor = 10;
	long long int residuo = 0;
	long long int digito = 0;
	long long int i = 0;
	long long int cifras_aux = cifras;


	//Se eleva el divisor de forma que tenga el mismo número de cifras que nuestro número inicial
	divisor = pow(divisor, (cifras_aux));
	cout << "divisor: " << divisor << endl;

	while (cifras_aux >= 0) {
		//El cociente son Digitos de izquiera a derecha
		digito = numero / divisor;

		//El residuo se convierte en el numero
		residuo = numero % divisor;
		numero = residuo;

		//El divisor disminuye
		divisor = divisor / 10;
		cout << "digito: " << digito << endl;
		if (digito % 2 == 0)i += digito * 3;
	    else i += digito * 1;

		cifras_aux--;
	}

	cout << i << endl;
}



int main() {

	long long int num;
	cout << "Ingrese un numero para mostrarlo separado en digitos: " << endl;
	cin >> num;

	dividir_en_digitos(num,13 /*cuantasCifras(num)*/);

	system("PAUSE");
	return 0;

}