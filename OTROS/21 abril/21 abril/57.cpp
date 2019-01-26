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

	Stack<	Arbin<	T	>	>	p;
	List<T>	l;
	p.push(a);
	while (!p.empty()) {
		Arbin<T>	b = p.top();
		p.pop();
		if (!b.esVacio() && b.hijoIz().esVacio() && b.hijoDr().esVacio())
			l.push_back(b.raiz());
		else	if (!b.esVacio()) {
			p.push(Arbin<T>(b.raiz()));
			p.push(b.hijoDr());
			p.push(b.hijoIz());
		}
	}
	return	l;
}


template <class T>
void nodHojaAlt(const Arbin<T> &a, List<T>	l) {
	int nod = 0, hoj = 0, alt = 0;

	if (!a.esVacio())
		genealogico(nod, hoj, alt, a, 0,l);

	if (hoj + 1 == alt)cout << "YES " << alt << endl;
	else cout << "NO" << endl;
}

template <class T>
void nHARec(int&nodos, int &hojas, int &altura, const Arbin<T> &a, int prof) {

	prof++;
	nodos++;

	if (altura < prof) altura = prof;

	if (!a.hijoIz().esVacio())
		nHARec(nodos, hojas, altura, a.hijoIz(), prof);
	if (!a.hijoDr().esVacio())
		nHARec(nodos, hojas, altura, a.hijoDr(), prof);
	if (a.hijoIz().esVacio() && a.hijoDr().esVacio())
		hojas++;

}

template <class T>
void genealogico(int&nodos, int &hojas, int &altura, const Arbin<T> &a, int prof, List<T> l) {
	
	prof++;
	nodos++;

	if (altura < prof) altura = prof;


	if (!(a.hijoIz().esVacio()) && !(a.hijoDr().esVacio())) {
		int padre = l.back(); l.pop_back();
		int hijoDr = l.back(); l.pop_back();
		int hijoIz = l.back(); 

		
		if ((hijoIz + hijoDr + 24 <= padre * 2) && (hijoIz >= hijoDr + 2))
			hojas++;
		genealogico(nodos, hojas, altura, a.hijoIz(), prof,l);
	}

	if (!a.hijoIz().esVacio() && a.hijoDr().esVacio()) {
		int padre = l.back(); l.pop_back();
		int hijoIz = l.back();

		if ((hijoIz +12 <= padre))
			hojas++;
		genealogico(nodos, hojas, altura, a.hijoIz(), prof, l);
	}
	

}

void resolver(const char Caso) {


	
		Arbin<int> arbol = leerArbol(-1);
		List<int> list = PostOrdenNoRecursivo(arbol);
		int tam = list.size();
		for (int i = 0; i < tam; i++) {
				cout << list.front() << endl;
			list.pop_front();
		}
		nodHojaAlt(arbol,list);
	
		
		
		list.~List();
		arbol.~Arbin();

}

	







int main() {
	char Caso;
	bool encontrado = false;
	cin >> Caso;

	while (!encontrado) {
		resolver(Caso);
	}




	system("pause");
	return 0;
}