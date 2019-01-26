#include <iostream>
#include "Arbin.h"
#include "Stack.h"
using namespace std;

//Problema 51 del juez Arboles Binarios Victor Ramos y Alejandro Povedano A07


//La funcion leerArbol facilitada a través del campus virtual
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
T raiz;	cin >> raiz;
if (raiz == vacio)	return Arbin<T>();
Arbin<T> a1 = leerArbol(vacio);
Arbin<T> a2 = leerArbol(vacio);
return Arbin<T>(a1, raiz, a2);
}

template	<class	T>
List<T>	PostOrdenNoRecursivo(Arbin<T>	const&	a) {
	Stack<Arbin<T>>	p;
	List<T>	l;
	p.push(a);
	while (!p.empty()) {
		Arbin<T>	b = p.top();
		p.pop();
		if (!b.esVacio() && b.hijoIz().esVacio() && b.hijoDr().esVacio())
			l.push_back(b.raiz());
		else if (!b.esVacio()) {
			p.push(Arbin<T>(b.raiz()));
			p.push(b.hijoDr());
			p.push(b.hijoIz());
		}
	}
	return	l;
}


template <class T>
void nodHojaAlt(const Arbin<T> &a) {
int nod = 0, hoj = 0, alt = 0;

if (!a.esVacio())
nHARec(nod, hoj, alt, a, 0);

cout << nod << " " << hoj << " " << alt << endl;
}

template <class T>
void nHARec(int&nodos, int &hojas, int &altura, const Arbin<T> &a, int prof) {

prof++;
nodos++;

if (altura < prof ) altura = prof;

if (!a.hijoIz().esVacio())
nHARec(nodos, hojas, altura, a.hijoIz(), prof);
if (!a.hijoDr().esVacio())
nHARec(nodos, hojas, altura, a.hijoDr(), prof);
if (a.hijoIz().esVacio() && a.hijoDr().esVacio())
hojas++;

}

void resolver() {

	Arbin<int> arbol = leerArbol(-1);
	List<int> list = PostOrdenNoRecursivo(arbol);
	int tam = list.size();
	
}









int main() {
int Caso;
bool encontrado = false;
cin >> Caso;

for(int i=0;i<Caso;i++){
	resolver();
}




system("pause");
return 0;
}