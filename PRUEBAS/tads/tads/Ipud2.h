#ifndef __IPUD2_H
#define __IPUD2_H

#include <fstream>
#include <cstddef>
#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;


class InfoSong {
public:
	
	string nombreC;
	int duracionC;
	bool reproducida;
	bool reproduccion;

	InfoSong(string nombreC, int d) :
		 nombreC(nombreC),duracionC(d), reproducida(false), reproduccion(false) {}

};

class Ipud2 {
public:

	void addSong(string nombre, string artista, int duracionC) {
		
		if (tablaCanciones.contiene(nombre))throw "La cancion ya existe";
		tablaCanciones.inserta(nombre, artista);
		InfoSong song(nombre, duracionC);
		Lista<InfoSong> lista;
		if (tablaArtistas.contiene(artista)) {
			lista = tablaArtistas.valorPara(artista);
		}
		lista.pon_ppio(song);
		tablaArtistas.inserta(artista, lista);
	}

	void addToPlayList(string s) {

		if (!tablaCanciones.contiene(s)) throw "Cancion no existente";
			string artista = tablaCanciones.valorPara(s);
			Lista<InfoSong> lista = tablaArtistas.valorPara(artista);
			Lista<InfoSong>::Iterator it = lista.begin();

			while (it.elem().nombreC != s) it.next();
			InfoSong song = it.elem();
			if (!song.reproduccion) {
				listaReproduccion.pon_final(song.nombreC);
			}
			song.reproduccion = true;
			it.set(song);
			tablaArtistas.inserta(artista, lista);
			duracion += song.duracionC;

	}

	void deleteSong(string s) {
		
		if (!tablaCanciones.contiene(s))throw "Cancion no existente";
		string artista = tablaCanciones.valorPara(s);
		Lista<InfoSong> lista = tablaArtistas.valorPara(artista);
		Lista<InfoSong>::Iterator it = lista.begin();
		while (it.elem().nombreC != s) it.next();
		InfoSong song = it.elem();
		lista.eliminar(it);
		tablaArtistas.inserta(artista, lista);
		tablaCanciones.borra(s);

		if (song.reproduccion) {
			Lista<string>::Iterator it = listaReproduccion.begin();
			while (it.elem() != s) {
				it.next();
			}
			listaReproduccion.eliminar(it);
			duracion -= song.duracionC;
		}
		if (song.reproducida) {
			Lista<string>::Iterator it = listaReproducidas.begin();
			while (it.elem() != s) {
				it.next();
			}
			listaReproducidas.eliminar(it);

		}

	}

	void play() {
		if (!listaReproduccion.esVacia()) {
			string cancion=listaReproduccion.primero();
			listaReproduccion.eliminar(listaReproduccion.begin());
			string artista = tablaCanciones.valorPara(cancion);
			Lista<InfoSong> lista = tablaArtistas.valorPara(artista);
			Lista<InfoSong>::Iterator it = lista.begin();
			while (it.elem().nombreC != cancion)it.next();
			InfoSong song = it.elem();
			song.reproduccion = false;
			song.reproducida = true;
			listaReproducidas.pon_ppio(cancion);
			it.set(song);
			tablaArtistas.inserta(artista, lista);
		}

	}

	string current() {
		if (listaReproduccion.esVacia())throw "Lista vacia";
		return listaReproduccion.primero();
	}

	int totalTime() {
		return duracion;
	}

	Lista<string> recent(int n) {
		Lista<string> lista;
		Lista<string>::Iterator it = listaReproducidas.begin();
		int cont = 0;
		while ((cont < n) && it != listaReproducidas.end()) {
			lista.pon_ppio(it.elem());
			it.next();
		}
		return lista;
	
	}

	//NUEVO

	void saveCurrentList(string nombre) {
		
	}

	Lista<string> generateArtistList(string artista) {
		Lista<string> lista;
		Lista<InfoSong> listaSong = tablaArtistas.valorPara(artista);
		Lista<InfoSong>::Iterator it = listaSong.begin();
		while (it != listaSong.end()) {
			lista.pon_final(it.elem().nombreC);
			it.next();
		}

		return lista;

	}

	void setPlayList() {

	}

	Lista<string> allList() {

	}
	




private:
	
	DiccionarioHash<string, Lista<InfoSong>> tablaArtistas;
	DiccionarioHash<string, string> tablaCanciones;
	DiccionarioHash<string, Lista<string>> tablaListas;
	Lista<string> listaReproducidas;
	Lista<string> listaReproduccion;
	int duracion;



};



#endif // __DICCIO2_H
