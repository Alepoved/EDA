#include "Racional.h"
#include <cmath>

//Metodos publicos

//**** COMPLETAR
//  Deben implementarse los metodos publicos de la clase
//****
Racional::Racional() {
	_numer = 0; _denom = 1;
}

Racional::Racional(long num, long den) {
	_numer = num; _denom = den;
	if(_denom==0)throw EDenominadorCero();
}

// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

// Metodos privados
void Racional::reduce() {
	// Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	// Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	// El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1);
	v2 = abs(v2);
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

Racional Racional::suma(Racional &otro) {
	long denominadorOp = (mcm(_denom, otro._denom));
	long numeradorOp = ((_numer*(denominadorOp) / _denom) + ((otro._numer*(denominadorOp) / otro._denom)));
	Racional res(numeradorOp, denominadorOp);
	res.reduce();
	return res;
}

Racional Racional::operator - (Racional &otro) {
	return resta(otro);
}
Racional Racional::resta(Racional &otro) {
	long denominadorOp = (mcm(_denom, otro._denom));
	long numeradorOp = ((_numer*(denominadorOp) / _denom) - ((otro._numer*(denominadorOp) / otro._denom)));
	Racional res(numeradorOp, denominadorOp);
	res.reduce();
	return res;
}

void Racional::operator *= (Racional &otro) {
	 multiplicaYActualiza(otro);
}
void Racional::multiplicaYActualiza(Racional &otro) {
	_numer = (_numer*otro._numer);
	_denom = (_denom*otro._denom);
	reduce();
}


void Racional::divideYActualiza(Racional &otro) {
	if (otro._denom==0 || otro._numer == 0)throw EDivisionPorCero();
	_denom = (_denom*otro._numer);
	_numer = (_numer*otro._denom);
	reduce();
}

bool Racional::operator == (Racional &otro) {
	reduce();
	otro.reduce();
	return ((_numer == otro._numer) && (_denom == otro._denom));
}

void Racional::operator / (Racional &otro) {
	return divideYActualiza(otro);
}


