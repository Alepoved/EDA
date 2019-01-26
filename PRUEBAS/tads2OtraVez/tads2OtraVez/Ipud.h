#ifndef IPUD_H
#define IPUD_H


#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"


class InfoCancion {
public:
	string artista;
	int duracionC;
	Lista<string>::Iterator it;
	Lista<string>::Iterator itReda;
	Lista<string>::Iterator itReon;

	InfoCancion(string a, int d,Lista<string>::Iterator &i, Lista<string>::Iterator itReda,
	Lista<string>::Iterator itReon) :
		artista(a), duracionC(d),it(i),itReda(itReda),itReon(itReon) {}
};

class Ipud {
public:

	void addSong(string nombre, string artista, int duracionC) {//constante
		if (tablaCanciones.contiene(nombre))throw "Cancion duplicada";
		Lista<string> lista;
		if (tablaArtistas.contiene(artista))
			lista = tablaArtistas.valorPara(artista);
		lista.pon_ppio(nombre);
		Lista<string>::Iterator it = lista.begin();
		string a =it.elem();
		InfoCancion cancion(artista, duracionC,it,reproducidas.end(),reproduccion.end());
		tablaArtistas.inserta(artista, lista);
		tablaCanciones.inserta(nombre, cancion);
	}

	void addToPlayList(string nombre){//constante
		if (tablaCanciones.contiene(nombre)) {
			InfoCancion cancion = tablaCanciones.valorPara(nombre);
			if (cancion.itReon == reproduccion.end()) {
				reproduccion.pon_ppio(nombre);
				cancion.itReon = reproduccion.begin();
				tablaCanciones.inserta(nombre, cancion);
				duracion += cancion.duracionC;
			}
		}
	}


	void deleteSong(string nombre) {//constante
		if (tablaCanciones.contiene(nombre)) {
			InfoCancion cancion = tablaCanciones.valorPara(nombre);
			if (cancion.itReda != reproducidas.end()) {
				reproducidas.eliminar(cancion.itReda);
			}
			if (cancion.itReon != reproduccion.end()) {
				reproduccion.eliminar(cancion.itReon);
				duracion -= cancion.duracionC;
			}
			Lista<string> lista = tablaArtistas.valorPara(cancion.artista);
			lista.eliminar(cancion.it);//falla el puntero no se por que
			if (lista.esVacia())tablaArtistas.borra(cancion.artista);
			else tablaArtistas.inserta(cancion.artista, lista);
			tablaCanciones.borra(nombre);
		}
	}

	void play() {
		if (!reproduccion.esVacia()) {
			string nombre = reproduccion.ultimo();
			reproduccion.quita_final();
			InfoCancion cancion = tablaCanciones.valorPara(nombre);
			cancion.itReon = reproduccion.end();
			reproducidas.pon_ppio(nombre);
			cancion.itReda = reproducidas.begin();
			tablaCanciones.inserta(nombre, cancion);
			duracion -= cancion.duracionC;
		}
	}

	string current() {
		if (!reproduccion.esVacia()) {
			return reproduccion.ultimo();
		}
	}

	int totalTime() {
		return duracion;
	}

	Lista<string> recent(int n) {//lineal con num canciones reproducidas
		Lista<string> lista;
		if (!reproducidas.esVacia()) {
			 int cont = 0;
			Lista<string>::Iterator it = reproducidas.begin();
			while (cont < n && it != reproducidas.end()) {
				lista.pon_ppio(it.elem());
				it.next();
			}
		}
		return lista;
	}

	void saveCurrentList(string nombreL) {//constante
		tablaListas.inserta(nombreL, reproduccion);
	}

	void generateArtistList(string artista) {
		tablaListas.inserta(artista, tablaArtistas.valorPara(artista));
	}

	void setPlayList(string nombreL) {//lineal, max (num canciones reproduccion,num can lista)
		if (tablaListas.contiene(nombreL)) {
			Lista<string>::Iterator it = reproduccion.begin();
			while (!reproduccion.esVacia()) {
				InfoCancion cancion = tablaCanciones.valorPara(it.elem());
				cancion.itReon = reproduccion.end();
				tablaCanciones.inserta(it.elem(), cancion);
				reproduccion.quita_ppio();
				it.next();
			}
			Lista<string> lista = tablaListas.valorPara(nombreL);
			it = lista.begin();
			while (it != lista.end()) {
				InfoCancion cancion = tablaCanciones.valorPara(it.elem());
				reproduccion.pon_ppio(it.elem());
				cancion.itReon = reproduccion.begin();
				tablaCanciones.inserta(it.elem(), cancion);
				it.next();
			}
		}
			
	}

/*void addSong(string nombre, string artista, int duracion) {//constante
	if (tablaCanciones.contiene(nombre))throw "Cancion duplicada";
	Lista<string> lista;
	if (tablaArtistas.contiene(artista))
		lista = tablaArtistas.valorPara(artista);
	lista.pon_ppio(nombre);
	Lista<string>::Iterator it = lista.begin();
	tablaArtistas.inserta(artista, lista);
	InfoCancion cancion(artista, duracion,it, reproducidas.end(), reproduccion.end());
	tablaCanciones.inserta(nombre, cancion);
	}

void addToPlayList(string nombre) {
	if (!tablaCanciones.contiene(nombre))throw "Cancion inexistente";
	InfoCancion cancion = tablaCanciones.valorPara(nombre);
	if (cancion.itReon == reproduccion.end()) {
		reproduccion.pon_ppio(nombre);
		cancion.itReon = reproduccion.begin();
		duracion += cancion.duracionC;
		tablaCanciones.inserta(nombre, cancion);
	}
}

void deleteSong(string nombre) {
	if (!tablaCanciones.contiene(nombre))throw "Cancion inexistente";
	InfoCancion cancion = tablaCanciones.valorPara(nombre);
	if (cancion.itReon != reproduccion.end()) {
		reproduccion.eliminar(cancion.itReon);
		duracion -= cancion.duracionC;
	}
	if (cancion.itReda != reproducidas.end()) {
		reproducidas.eliminar(cancion.itReda);
	}
	Lista<string> lista = tablaArtistas.valorPara(cancion.artista);
	if (lista.begin() == cancion.itA) {
		lista.quita_ppio();
	}
	//lista.eliminar(cancion.itA);
	if (lista.esVacia())tablaArtistas.borra(cancion.artista);
	else tablaArtistas.inserta(cancion.artista, lista);
	tablaCanciones.borra(nombre);
}

void play() {
	if (!reproduccion.esVacia()) {
		string nombre = reproduccion.ultimo();
		reproduccion.quita_final();
		reproducidas.pon_ppio(nombre);
		InfoCancion cancion = tablaCanciones.valorPara(nombre);
		cancion.itReon = reproduccion.end();
		cancion.itReda = reproducidas.begin();
		duracion -= cancion.duracionC;
		tablaCanciones.inserta(nombre, cancion);
	}
}

Lista<string> recent(int n) {//lineal con num canciones reproducidas
	Lista<string> lista;
	if (!reproducidas.esVacia()) {
		int cont = 0;
		Lista<string>::Iterator it = reproducidas.begin();
		while (cont < n && it != reproducidas.end()) {
			lista.pon_ppio(it.elem());
			it.next();
		}
	}
	return lista;
}
*/


private:
	DiccionarioHash<string, InfoCancion> tablaCanciones;
	DiccionarioHash<string, Lista<string>> tablaArtistas;
	DiccionarioHash<string, Lista<string>> tablaListas;

	Lista<string> reproducidas;
	Lista<string> reproduccion;

	int duracion;
	


};


#endif