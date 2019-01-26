#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/*void tesoro(Arbin<int> arbol, int numDrag,int &nodoSol,int &menorDrag) {//preorden
	if (!arbol.hijoIz().esVacio() || !arbol.hijoDer().esVacio()) {
		if (arbol.raiz() == 1)numDrag++;
		if (!arbol.hijoIz().esVacio())tesoro(arbol.hijoIz(), numDrag, nodoSol, menorDrag);
		if (!arbol.hijoDer().esVacio())tesoro(arbol.hijoDer(), numDrag, nodoSol, menorDrag);
	}
	else{//estoy en una hoja
		if (menorDrag == -1) {
			nodoSol = arbol.raiz();
			menorDrag = numDrag;
		}
		else if (numDrag < menorDrag) {
			nodoSol = arbol.raiz();
			menorDrag = numDrag;
		}
	}

}*/

/*int navegables(Arbin<int> arbol,int &numTramos) {//postorden

	int aguaNodo = 0;
	if (!arbol.hijoIz().esVacio() || !arbol.hijoDer().esVacio()) {
		if (!arbol.hijoIz().esVacio())
			aguaNodo+=navegables(arbol.hijoIz(), numTramos);
		if (!arbol.hijoDer().esVacio())
			aguaNodo+=navegables(arbol.hijoDer(), numTramos);
		if (arbol.raiz() != 0)aguaNodo += arbol.raiz();
	}
	else {
		aguaNodo = 1;
	}

	if (aguaNodo >= 3)numTramos++;

	return aguaNodo;

}*/

/*void genealogico(Arbin<int> arbol, int &numGen, bool &correcto) {//preorden

	if ((!arbol.hijoIz().esVacio() || !arbol.hijoDer().esVacio()) && correcto) {
		if (!arbol.hijoIz().esVacio()) {
			if (arbol.raiz() >= arbol.hijoIz().raiz() + 18) {
				if (!arbol.hijoDer().esVacio()) {
					if (arbol.hijoIz().raiz() >= arbol.hijoDer().raiz() + 2) {
						
						genealogico(arbol.hijoIz(), numGen, correcto);
						numGen++;
						genealogico(arbol.hijoDer(), numGen, correcto);
					}
					else correcto = false;
				}
				else { genealogico(arbol.hijoIz(), numGen, correcto); numGen++; }
			}
			else correcto = false;
		}
	}
}
*/

/*void montaña(Arbin<int> arbol, int &tiempo,int tiempoP) {//postorden

	if (!arbol.hijoIz().esVacio() || !arbol.hijoDer().esVacio()) {
		
		if (!arbol.hijoIz().esVacio()) {
			montaña(arbol.hijoIz(), tiempo,tiempoP+1);
		}
		if (!arbol.hijoDer().esVacio()) {
			 montaña(arbol.hijoDer(), tiempo,tiempoP+1);
		}
	}
	if (arbol.raiz() == 1) {
		tiempo += tiempoP * 2;
	}

}*/

/*int rescata(Arbin<int> arbol, int &numEquipos, int &mayorTramo) {

	int iz = 0, de = 0;
	if (!arbol.hijoIz().esVacio() || !arbol.hijoDer().esVacio()) {
		if (!arbol.hijoIz().esVacio())iz += rescata(arbol.hijoIz(), numEquipos, mayorTramo);
		if (!arbol.hijoDer().esVacio())de += rescata(arbol.hijoDer(), numEquipos, mayorTramo);
	}
	if (iz == 0 && de == 0 && arbol.raiz() != 0)numEquipos++;
	
	if (arbol.raiz() != 0) {
		if ((iz + arbol.raiz()) > mayorTramo)mayorTramo = iz+ arbol.raiz();
		if ((de + arbol.raiz()) > mayorTramo)mayorTramo = de+ arbol.raiz();
	}

	return arbol.raiz()+iz+de;
}*/

/*int singulares(Arbin<int> arbol, int &numS,int &sumaAnt) {

	int sumaPost = 0;
	if (!arbol.hijoIz().esVacio() || !arbol.hijoDer().esVacio()) {

		sumaAnt += arbol.raiz();
		if (!arbol.hijoIz().esVacio())
			sumaPost += singulares(arbol.hijoIz(), numS, sumaAnt);
		if (!arbol.hijoDer().esVacio())
			sumaPost += singulares(arbol.hijoDer(), numS, sumaAnt);
		sumaAnt -= arbol.raiz();
	}

	if (sumaPost == sumaAnt)numS++;

	return sumaPost + arbol.raiz();


}*/




int procesa(Arbin<int> arbol) {

	/*dragones:int numDrag = 0, nodoSol = -1, menorDrag = -1;
	tesoro(arbol, numDrag,nodoSol,menorDrag);
	return nodoSol;*/

	/*navegables:int numTramos = 0;
	int a=navegables(arbol,numTramos);
	if (a >= 3)numTramos--;
	return numTramos;*/
	
	/*genealogico 2014int numGen = 0; bool correcto = true;
	genealogico(arbol, numGen,correcto);
	return correcto;*/
	
	/*montañaint tiempo = 0;
	montaña(arbol, tiempo,0);
	return tiempo;*/

	/*int numEquipos = 0, mayorTramo = -1;
	rescata(arbol, numEquipos, mayorTramo);
	cout << "numE: " << numEquipos << " mayorD: " << mayorTramo;
	return -1;*/

	/*int numS = 0, sumaAnt = 0;
	singulares(arbol, numS,sumaAnt);
	
	return numS;*/

	

}

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
	while (cin.peek() != EOF) {
		cout << procesa(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}