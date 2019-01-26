/*#include<iostream>
using namespace std;

typedef int tArray[100];
typedef int tR[100];
int calcular(tArray array, int m, int iterador, int resultado, tR solucion,int cont);

int main() {
	tArray array;
	tR solucion;
	int m = 0,aux=0;

	for (int i = 0; i < 10; i++) {
		cin >> array[i];
	}
	cout << "m:" << endl;
	cin >> m;

	calcular(array, m,0,0,solucion,0);
	
	for (int i = 0; i < 10; i++) {
		if (aux < solucion[i])aux = solucion[i];
	}

	

	cout << "solucion es" << aux << endl;
	system("pause");
	return 0;
}

int calcular(tArray array, int m,int iterador,int resultado,tR solucion,int cont) {
	if (iterador ==9)return resultado;
	for (int i = cont+1; i < m+cont; i++) {
		resultado += array[iterador] + array[i];
	}
	solucion[iterador] = resultado-(array[iterador]);
	 calcular(array, m, iterador + 1, 0,solucion,cont+1);
}*/
/*
#include<iostream>
using namespace std;

typedef int tArray[100];

int calcular(tArray array, int  iterador, int cont, int  resultado);

int main() {

	tArray array;

	for (int i = 0; i < 4; i++) {
		cin >> array[i];
	}

	

	int resultado=calcular(array, 0, 0, 0);

	cout << resultado << endl;

	system("pause");
	return 0;
}


int calcular(tArray array, int  iterador, int cont, int  resultado) {
	if (cont == 3)return resultado;
	else {
		for (int i = cont + 1; i < 4; i++) {
			resultado += array[cont] * array[i];
		}
		return calcular(array, iterador + 1, cont + 1, resultado);
	}
}
*/
