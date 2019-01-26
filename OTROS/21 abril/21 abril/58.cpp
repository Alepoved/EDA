#include <iostream>
#include "Arbin.h"
using namespace std;

struct solucion { bool ok; int sumaNodos; int numNodos; int id; int dragones=0; };


template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}

template <class T>
void mostrarRama(int max, Arbin<T> a) {
	bool encontrado = false;
	for (int i = 3; i < 100 && !encontrado; i++) {
		if (a.raiz() == i) {
			encontrado = true;
			cout << "hoja con valor " << i << " ";
		}
	}
	cout << "Numero de unos encontrado: " << max << endl;
}
template <class T>
solucion valioso(Arbin<T> &a,int &max) {
	/*solucion actual, aux;
	int suma = 0;

	if (!a.hijoIz().esVacio()) {
		
		actual = valioso(a.hijoIz());
		//actual.numNodos = aux.numNodos;
		//actual.sumaNodos = aux.sumaNodos;
		//actual.ok = aux.ok;
	}
	else {
		actual.numNodos = 0;
		actual.sumaNodos = 0;
		actual.ok = true;
	}
	if (!a.hijoDr().esVacio()) {
		aux = valioso(a.hijoDr());
		actual.numNodos += aux.numNodos;
		actual.sumaNodos += aux.sumaNodos;
		actual.ok = (actual.ok&&aux.ok);
	}
	actual.numNodos++;
	cout << actual.sumaNodos << " ";
	actual.sumaNodos += a.raiz();

	cout << actual.sumaNodos << " ";
	
	if (actual.sumaNodos < actual.numNodos)
		actual.ok = false;
	
	return actual;*/
	
	solucion actual, aux;

			
				if (!a.hijoIz().esVacio()) {
					if (a.raiz() == 1) { 
						max++; 
					//	actual.dragones++;
					}
					
					actual = valioso(a.hijoIz(), max);
					actual.dragones += aux.dragones;
					//cout << actual.dragones;
				}
				else {
					actual.dragones = 0;
				}
				
				if (!a.hijoDr().esVacio()) {
					if (a.raiz() == 1) {
						max++;
						//actual.dragones++;
					}
					
					aux=valioso(a.hijoDr(),max);
					actual.dragones += aux.dragones;
					if (a.raiz() == 1) {
						actual.dragones++;
					}
					//cout << actual.dragones;
				}

				if (a.hijoDr().esVacio() && a.hijoIz().esVacio()) {
				
					bool encontrado = false;
					for (int i = 3; i < 100 && !encontrado; i++) {
						if (a.raiz() == i) {
							encontrado = true;
							cout << "hoja con valor " << i << " ";
						}
					}
					cout << "Numero de unos encontrado: " << max << endl;
					max = 0;
				}
				
				
				
		
		
	
	return actual;
}

int main() {
	int n;
	solucion sol;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Arbin<int> a = leerArbol(-1);
		if (!a.esVacio()) {
			int cero = 0;
			sol = valioso(a,cero);
			if (sol.ok)
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "SI" << endl;

	}
	return 0;
}