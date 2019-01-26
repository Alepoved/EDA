/**
Este programa lee árboles de la entrada estándar,
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con
v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
con I la codificación del hijo izquierdo,
v el valor de la raíz, y D la codificación
del hijo derecho.
Para cada árbol leído, escribe en la salida estándar
el número de nodos singulares de dicho árbol.

Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el árbol vacío. Al no tener nodos,
un árbol vacío tiene 0 nodos sigulares.
-El segundo representa un árbol con un único nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0.
-El tercero representa otro árbol con un único nodo, cuyo
valor es 5. Por la misma razón que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente árbol:

1
/  \
3  -4
/ \
4  -3

Este árbol tiene 2 nodos sigulares: la raíz, y la raíz del hijo
izquierdo.

Por tanto, la salida del programa para estos casos será:

0
1
1
2

*/
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/**
COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de
esta función
La complejidad es lineal porque el algoritmo recorre todos los nodos una unica vez.

*/
unsigned int calculaSingulares(Arbin<int> a, int &sumaAnt,int &singular) {
	
	int sumaPos = 0;//suma Pos= contine la suma de los nodos posteriores al actual

		 if (!a.hijoDer().esVacio() || !a.hijoIz().esVacio()) {//si no es hoja
			 sumaAnt += a.raiz();//sumaAnt es igual a la suma anterior mas el nodo raiz
			if (a.hijoIz().esVacio()) {//si el hijo iz es vacio, vamos al hijo dr
				sumaPos += calculaSingulares(a.hijoDer(), sumaAnt, singular);
			}
			else if (a.hijoDer().esVacio()) {//si el hijo dr es vacio, vamos al hijo iz
				sumaPos += calculaSingulares(a.hijoIz(), sumaAnt, singular);
			}
			else {
				sumaPos += calculaSingulares(a.hijoIz(), sumaAnt, singular);
				sumaPos += calculaSingulares(a.hijoDer(), sumaAnt, singular);
			}
			sumaAnt -= a.raiz();//Cuando volvemos atras restamos el nodo actual a la suma ya que estamos en el actual
			
		}

	 if (sumaPos == sumaAnt)singular++;//si la suma posterior y anterior al nodo actual son iguales=>singular++
	return a.raiz()+sumaPos;// devolvemos el valor del nodo mas la suma de los valores de los nodos posteriores*/
	
}

unsigned int numero_singulares(Arbin<int> a) {
	
	int sumaAnt = 0, singular=0;//suma Ant= suma de los nodos anteriores al actual

	if (!a.esVacio()) {//devolvemos un 0
		if (a.hijoDer().esVacio() && a.hijoIz().esVacio())singular = 1;//tiene un unico elemento(raiz)
		else {
		calculaSingulares(a, sumaAnt, singular);
		}
	}
	
	return singular;

}


Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
