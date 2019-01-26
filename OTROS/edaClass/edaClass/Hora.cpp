#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "Hora.h"

using namespace std;


Hora::Hora(int h, int m, int s) {
	if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59)
		throw invalid_argument("Hora invalida");
	else
		_hora = h; _minuto = m; _segundo = s;
}

void Hora::mostrar(ostream& salida) const
{
	salida << setfill('0') << setw(2) << _hora << ':'
		<< setfill('0') << setw(2) << _minuto << ':'
		<< setfill('0') << setw(2) << _segundo;

}

void Hora::leer(istream & entrada)
{
	char aux; int h, m, s;
	entrada >> h >> aux >> m >> aux >> s;
	if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59)
		throw invalid_argument("Hora invalida");
	else
		_hora = h; _minuto = m; _segundo = s;
}


bool Hora::operator< (const Hora &h) const
{
	return (_hora<h._hora) || ((_hora == h._hora) && (_minuto<h._minuto))
		|| ((_hora == h._hora) && (_minuto == h._minuto) && (_segundo<h._segundo));


}