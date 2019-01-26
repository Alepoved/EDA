#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>
#include "lista.h"

using namespace std;

/*sep 2015*/
void calculaLista(Arbin<int> arbol, Lista<int> lista,bool &cumple,Lista<int>::ConstIterator &it) {

	if (!arbol.esVacio() && cumple) {
		if (arbol.raiz() != it.elem())cumple = false;
		it.next();
		calculaLista(arbol.hijoIz(),lista,cumple,it);
		calculaLista(arbol.hijoDer(), lista, cumple, it);
	}

}


bool calcula(Arbin<int> arbol, Lista<int> lista) {


	Lista<int>::ConstIterator it = lista.cbegin();
	bool cumple = true;

	calculaLista(arbol, lista, cumple, it);

	return cumple;
}

//




Arbin<int> leeArbol(istream& in) {
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
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	Lista<int> lista;
	bool coinciden = true;
	lista.pon_final(1);lista.pon_final(3); lista.pon_final(4); lista.pon_final(-3); lista.pon_final(-4);
	while (cin.peek() != EOF) {
		Arbin<int> a=leeArbol(cin);
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}