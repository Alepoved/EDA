#ifndef __IPUD_H
#define __IPUD_H

#include <fstream>
#include <cstddef>
#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;


class InfoSong {
public:
	string artista;
	int duracionC;
	bool reproducida;
	bool reproduccion;

	InfoSong(string a, int d) :
		artista(a), duracionC(d), reproducida(false), reproduccion(false) {}

};

class Ipud {
public:

	void addSong(string nombre, string artista, int duracionC) {
		if (tablaCanciones.contiene(nombre))throw "Cancion ya existente";
		InfoSong song(artista, duracionC);
		tablaCanciones.inserta(nombre, song);
		

	}

	void addToPlayList(string s) {
		if (!tablaCanciones.contiene(s))throw "Cancion no existe";
		InfoSong song = tablaCanciones.valorPara(s);
		if (!song.reproduccion) listaReproduccion.pon_final(s);
		song.reproduccion = true;
		duracion += song.duracionC;
		tablaCanciones.inserta(s, song);
		
		
	}

	void deleteSong(string s) {
		if (!tablaCanciones.contiene(s))throw "Cancion no existe";
		InfoSong song = tablaCanciones.valorPara(s);
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
		
		tablaCanciones.borra(s);


	}

	void play() {
		string s =listaReproduccion.primero();
		InfoSong song = tablaCanciones.valorPara(s);
		listaReproduccion.eliminar(listaReproduccion.begin());
		listaReproducidas.pon_final(s);
		song.reproducida = true;
		song.reproduccion = false;
		tablaCanciones.inserta(s, song);

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

	




private:
	DiccionarioHash<string,InfoSong> tablaCanciones;
	Lista<string> listaReproducidas;
	Lista<string> listaReproduccion;
	int duracion;



};



#endif // __DICCIO2_H
