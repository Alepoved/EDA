#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include "Complejo.h"

using namespace std;




Hora::Hora(double real, double imag, int n,char op){
	if (real < -2 || real>2 || imag < -2 || imag>2 || n < 100 || n>500)
		throw invalid_argument("Valores no validos");
	else
		if (op == ' ')_real = real; _imag = imag; _n = n;
	if (op == '+')_real = real + _real; _imag = imag + _imag; _n = n + _n;
	if (op == '*')_real = real * _real-imag*_imag; _imag = _real * imag+real+_imag; _n = n * _n;
	
}

void Hora::mostrar(ostream& salida) const
{
	salida << setfill('0') << setw(2) << _real << ':'
		<< setfill('0') << setw(2) << _imag << ':'
		<< setfill('0') << setw(2) << _n;

}

void Hora::leer(istream & entrada)
{
	char aux; int real, imag, n;
	entrada >> real>> aux >> imag >> aux >> n;
	if (real < -2 || real>2 || imag < -2 || imag>2 || n < 100 || n>500)
		throw invalid_argument("Valores no validos");
	else
		_real = real; _imag = imag;_n = n;
}


bool Hora::operator< (const Hora &h) const
{
	/*return (_hora<h._hora) || ((_hora == h._hora) && (_minuto<h._minuto))
		|| ((_hora == h._hora) && (_minuto == h._minuto) && (_segundo<h._segundo));
		*/
}

Hora Hora::operator+ (const Hora &h) const{
	return Hora(h._real, h._imag, h._n,'+');
}

Hora Hora::operator* (const Hora &h) const{
	return Hora(h._real, h._imag, h._n,'*');
}

double Hora::raizCuadrada()const{
	double a = pow(_real, 2);
	double b = pow(_imag, 2);
	return sqrt(a+b);
}




