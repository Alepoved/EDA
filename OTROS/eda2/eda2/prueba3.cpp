#include <iostream>
using namespace std;
typedef int tArray[100];
//KARAJAULAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
bool creciente(tArray array, int i,int tam,int iterador);
bool divertido(tArray array, int tam, int d);
int main() {

	tArray array;
	int tam,d;


	cout << "tamaño del vector "; cin >> tam;
	tam--;
	cout << "valor de d "; cin >> d;

	for (int i = 0; i <= tam; i++) {
		cin >> array[i];
	}

    bool exito=creciente(array,0,tam,0);
	bool exito2 = divertido(array, tam, d);



	//
	if (exito && exito2)cout << "SI" << endl;
	else cout << "NO" << endl;



	system("pause");
	return 0;
}

bool creciente(tArray array,int i, int tam,int iterador) {
	//apartado2
	bool exito = false;
	if (iterador == -1)exito = false;
	else {
		if (iterador >= tam)exito = true;
		else {
			if (array[i] <= array[tam] && array[tam] - array[i] <= tam) {
				exito = creciente(array, i + 1, tam, iterador);
				if (!exito)exito = creciente(array, i + 1, tam, iterador + 1);
				if (!exito)creciente(array, i + 1, tam, -1);
			}
	}
	
		

	}
	

	//aparatado1
	/*int aux = 0;
	bool exito = true;
	for (int i = 0; i <= tam; i++) {
		if (aux <= array[i] && array[i]-aux<=1)aux = array[i];
		else exito = false;
	}
	return exito;*/

	return exito;
}

//apartado1
bool divertido(tArray array, int tam, int d) {
	bool exito = false;
	int numR = 0;
	for (int i = 0; i <= tam && !exito; i++) {
		numR = 0;
		for(int j=0;j<=tam && !exito;j++){
			if (array[i] == array[j]) {
				numR++;
				if (numR > d)exito =true;
			}
		}
	}

	return !exito;
}