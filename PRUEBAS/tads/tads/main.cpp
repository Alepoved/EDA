#include <iostream>
#include <string>
#include "agencia.h"
#include "Reader.h"
//#include "Ipud.h"
#include "Hospital.h"
#include "Ipud2.h"
#include "Consultorio.h"
using namespace std;






int main() {
	
	
/*	Cliente c1("c1", 1);
	Cliente c2("c2", 2);
	Cliente c3("c3", 2);
	Cliente c4("c4", 2);
	Cliente c5("c5", 2);

	Hotel h1("hotel1");
	Hotel h2("hotel2");

	Agencia<Cliente,Hotel> ag;
	ag.aloja(c1, h1);
	ag.aloja(c2, h1);
	ag.aloja(c3, h1);
	ag.aloja(c4, h2);
	ag.aloja(c5, h2);

	Lista<Cliente> lista= ag.huespedes(h1);
	Lista<Cliente>::Iterator it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}

	cout<<endl;

	ag.desaloja(c1);

	lista = ag.huespedes(h1);
	it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}

	cout << endl;

	ag.aloja(c2, h2);

	lista = ag.huespedes(h2);
	it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}*/

/*Libro l1("libro1");
	Libro l2("libro2");
	Libro l3("libro3");
	Libro l4("libro4");
	Libro l5("libro5");

	Reader<Libro> reader;

	reader.ponerLibro(l1, 2);
	reader.ponerLibro(l2, 2);
	reader.ponerLibro(l3, 3);
	reader.ponerLibro(l4, 4);
	reader.ponerLibro(l5, 5);

	
	reader.abrir(l1);
	reader.abrir(l3);
	reader.abrir(l1);

	reader.avanzaPagina();


	cout << reader.pagLibro(l1)<<endl;

	Lista<Libro> lista = reader.recientes(2);
	Lista<Libro>::Iterator it = lista.begin();

	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}

	cout << endl;
	reader.eliminaLibro(l1);

	lista = reader.recientes(2);
	it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}
	*/

/*Ipud ip;

	ip.addSong("ca1", "ar1", 1);
	ip.addSong("ca2", "ar2", 2);
	ip.addSong("ca3", "ar3", 3);
	ip.addSong("ca4", "ar4", 4);

	ip.addToPlayList("ca1");
	ip.addToPlayList("ca2");
	ip.addToPlayList("ca3");

	ip.play();
	ip.play();

	cout << ip.totalTime() << endl;

	Lista<string> lista=ip.recent(3);
	Lista<string>::Iterator it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem() << " ";
		it.next();
	}
	cout << endl;
	cout << ip.current() << endl;

	ip.deleteSong("ca1");

	lista = ip.recent(3);
	 it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem() << " ";
		it.next();
	}*/

/*Ipud2 ip;

ip.addSong("ca1", "ar1", 1);
ip.addSong("ca2", "ar2", 2);
ip.addSong("ca3", "ar2", 3);
ip.addSong("ca4", "ar2", 4);

ip.addToPlayList("ca1");
ip.addToPlayList("ca2");
ip.addToPlayList("ca3");

ip.play();
ip.play();

cout << ip.totalTime() << endl;

Lista<string> lista = ip.recent(3);
Lista<string>::Iterator it = lista.begin();
while (it != lista.end()) {
	cout << it.elem() << " ";
	it.next();
}
cout << endl;
cout << ip.current() << endl;

ip.deleteSong("ca1");

lista = ip.recent(3);
it = lista.begin();
while (it != lista.end()) {
	cout << it.elem() << " ";
	it.next();
}
cout << endl;
lista = ip.generateArtistList("ar2");
it = lista.begin();
while (it != lista.end()) {
	cout << it.elem() << " ";
	it.next();
}*/

/*Consultorio<string, Diccionario<Fecha, string>> con;

Fecha f1(1, 2, 1990);
Fecha f2(2, 1, 1990);
Fecha f3(3, 1, 1990);
Fecha f4(1, 1, 1990);

con.nuevoMedico("me1");
con.pideConsulta("pa1", "me1", f1);
con.pideConsulta("pa2", "me1", f2);
con.pideConsulta("pa3", "me1", f3);
con.pideConsulta("pa4", "me1", f4);
cout <<"Siguiente Paciente:" <<con.siguientePaciente("me1") << endl;

con.nuevoMedico("me1");

con.listaPacientes("me1");*/

Hospital<InfoPaciente> ho;

ho.anPaciente(1, "pa1", 39, "sin1", leve);
ho.anPaciente(2, "pa2", 39, "sin2", grave);
ho.anPaciente(3, "pa3", 39, "sin2", normal);
ho.anPaciente(4, "pa4", 39, "sin2", grave);

InfoPaciente p = ho.infoPaciente(2);
cout << p.nombre << endl;

ho.siguiente();


ho.siguiente();
ho.siguiente();

ho.siguiente();
ho.siguiente();

	system("pause");
	return 0;
}