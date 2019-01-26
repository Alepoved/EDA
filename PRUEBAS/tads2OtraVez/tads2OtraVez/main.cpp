#include <iostream>
#include <string>
#include "Agencia.h"
#include "Hospital.h"
#include "Ipud.h"
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

	Agencia<Cliente, Hotel> ag;
	ag.aloja(c1, h1);
	ag.aloja(c2, h1);
	ag.aloja(c3, h1);
	ag.aloja(c4, h2);
	ag.aloja(c5, h2);

	Lista<Cliente> lista = ag.listadoHuespedes(h1);
	Lista<Cliente>::Iterator it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}

	cout << endl;

	ag.desaloja(c1);

	lista = ag.listadoHuespedes(h1);
	it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}

	cout << endl;

	ag.aloja(c2, h2);

	lista = ag.listadoHuespedes(h2);
	it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem().nombre << " ";
		it.next();
	}*/


/*Hospital<InfoPaciente> ho;


	ho.anPaciente(1, "pa1", 39, leve);
	ho.anPaciente(2, "pa2", 39, grave);
	ho.anPaciente(3, "pa3", 39, normal);
	ho.anPaciente(4, "pa4", 39, grave);

	string p = ho.infoPaciente(2);
	cout << p << endl;

	ho.siguiente();


	ho.siguiente();
	ho.siguiente();

	ho.siguiente();*/
	
	Ipud ip;
	ip.addSong("ca1", "ar1", 1);
	ip.addSong("ca2", "ar2", 2);
	ip.addSong("ca3", "ar3", 3);
	ip.addSong("ca4", "ar4", 4);

	ip.addToPlayList("ca1");
	ip.addToPlayList("ca2");
	ip.addToPlayList("ca3");

	ip.play();
	ip.play();

	cout << endl;

	Lista<string> lista = ip.recent(3);
	Lista<string>::Iterator it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem() << " ";
		it.next();
	}

	cout << endl;
	ip.deleteSong("ca1");

	lista = ip.recent(3);
	it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem() << " ";
		it.next();
	}

	cout << endl;
	
	/*ip.addSong("ca12", "ar1", 1);
	ip.addSong("ca11", "ar1", 1);
	ip.generateArtistList("ar1");

	ip.setPlayList("ar1");

	ip.play();
	ip.play();
	lista = ip.recent(3);
	it = lista.begin();
	while (it != lista.end()) {
		cout << it.elem() << " ";
		it.next();
	}*/


/*Consultorio con;
con.nuevoMedico("me1");
con.pideConsulta("pa1", "me1", 1);
con.pideConsulta("pa2", "me1", 2);
con.pideConsulta("pa3", "me1", 3);
con.pideConsulta("pa4", "me1", 0);
cout << "Siguiente Paciente:" << con.siguientePaciente("me1") << endl;

con.atiendeConsulta("me1");

con.listaPacientes("me1");*/
	system("pause");
	return 0;
}