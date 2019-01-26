#include <iostream>
using namespace std;

#ifndef COMPLEJO_H
#define COMPLEJO_H


class Hora{
public:
	Hora(double real = 0, double imag = 0, int n = 0,char op=' ');
	
	void mostrar(ostream & salida) const;
	double raizCuadrada() const;
	void leer(istream& entrada);
	bool operator< (const Hora& h) const;
	Hora operator+ (const Hora& h) const;
	Hora operator*(const Hora&h) const;

private:
	double _real;
	double _imag;
	int _n;
};
#endif