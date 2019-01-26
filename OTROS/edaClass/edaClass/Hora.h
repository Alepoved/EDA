#include <iostream>
using namespace std;

#ifndef HORA_H
#define HORA_H


class Hora {
public:
	Hora(int h = 0, int m = 0, int s = 0);
	void mostrar(ostream & salida) const;
	void leer(istream& entrada);
	bool operator< (const Hora& h) const;

private:
	int _hora;
	int _minuto;
	int _segundo;
};

#endif