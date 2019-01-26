#ifndef _RACIONAL_H
#define _RACIONAL_H

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class Racional {
public:
      //Excepcion que se lanza cuando se trata de crear
	  //una fraccion con denominador 0
	class EDenominadorCero {};
      //Excepcion que se lanza cuando se produce una division
      //por 0
	class EDivisionPorCero {};

	 // Constructora por defecto: crea la fraccion 0/1
	Racional();

   	  // Constructora para crear la fraccion num / denom
	  // Si denom es 0, levanta una excepcion de tipo 
	  // EDenominadorCero.
	Racional(T num, T denom);
	
	//destruye
//	void ~Destructor();

	  // La fraccion mas 'r' 
	Racional suma(const Racional<T> &r) const;
	
	  // La fraccion menos 'r'
	Racional operator-(const Racional<T> &r) const;
	
	  // Actualiza la fraccion al resultado de multiplicar por  'r'
	void operator*=(const Racional<T> &r);
	
	  // Actualiza la fraccion al resultado de dividirla por 'r'.
	  // Si r es 0, levanta una excepcion EDivisionPorCero.
	void divideYActualiza(const Racional<T> &r);
	
	  // Funcion de equivalencia
	bool operator ==(const Racional<T> &r) const;
	
	  // Funcion que permite escribir una fraccion en un 'stream'
	friend ostream& operator<< (ostream& out, const Racional<T>& f) {
  	   out << *(f._numer) << "/" << *(f._denom);
  	   return out;
    }	  
private:
	T *_numer;     // El numerador
	T *_denom;     // El denominador 
	void reduce();   // Transforma la fraccion en una equivalente irreducible (es decir, una en la que
	                 // el denominador es siempre positivo, y el unico divisor comun del numerador y el 
					 // denominador es 1)	
	static T mcm(T v1, T v2);     // Minimo comun multiplo de v1 y v2
	static T mcd(T v1, T v2);     // Maximo comun divisor de v1 y v2 
};



  //Metodos publicos
  
template <class T>
Racional<T>::Racional() {
	//_numer = 0;
	//_denom = 1;
	_numer = new T(0);
	_denom = new T(1);
}

template <class T>
Racional<T>::Racional(T num, T denom) {
	if (denom == 0) throw EDenominadorCero();
	 _numer = new T(num);
	 _denom = new T(denom);
	//_numer = num;
	//_denom = denom;
	reduce();
}

//template <class T>
//void Racional<T>::~Destructor() { delete _numer; delete _denom; }

template <class T>
Racional<T> Racional<T>::suma(const Racional<T> &r) const {
	if (*_denom == *(r._denom)) { //importante
			return  Racional<T>(*_numer + *(r._numer), *_denom);
		
	}
	else {
		T ndenom = mcm(*_denom, *(r._denom));
		return Racional(*_numer*(ndenom / *_denom) + *(r._numer)*(ndenom / *(r._denom)),
			ndenom); 
	
	}
}

template <class T>
Racional<T> Racional<T>::operator-(const Racional<T> &r) const {
	if (*_denom == *(r._denom)) {
		return Racional(*_numer - *(r._numer),*_denom);
	}
	else {
		T ndenom = mcm(*_denom, *(r._denom));
		return Racional(*_numer*(ndenom / *_denom)-*(r._numer)*(ndenom / *(r._denom)),
		                ndenom);
	}
}

template <class T>
void Racional<T>::operator*=(const Racional<T> &r) {
    *_numer =*_numer **(r._numer);
    *_denom =*_denom **(r._denom);
    reduce();
}

template <class T>
void Racional<T>::divideYActualiza(const Racional<T> &r) {
	if (*(r._numer) == 0) throw EDivisionPorCero();	   
	*_numer =  *_numer **(r._denom);
	*_denom = *_denom **(r._numer);
	reduce();
}

template <class T>
bool Racional<T>::operator ==(const Racional<T> &r) const {
	return *_numer == *(r._numer) && *_denom == *(r._denom);
}

 // Metodos privados
 
template <class T>
void Racional<T>::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (*_denom < 0) {
		*_numer = -*_numer;
		*_denom = -*_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	T fsimp = mcd(*_numer, *_denom);
	*_numer /= fsimp;
	*_denom /= fsimp;
}

template <class T>
T Racional<T>::mcd(T v1, T v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	if (v1 < v2) {
		T tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		T nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return abs(v1);
}

template <class T>
T Racional<T>::mcm(T v1, T v2) {
	return v1*v2 / mcd(v1, v2);
}




#endif