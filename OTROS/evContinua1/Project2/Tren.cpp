#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>


#include "Complejo.h"

using namespace std;

ostream& operator << (ostream &salida, const Hora& h)
{
	h.mostrar(salida);
	return salida;
}


istream& operator >> (istream &entrada, Hora & h)
{
	h.leer(entrada);
	return entrada;
}



int calculaHora(const vector<Hora> &horario, int ini, int fin, const Hora& h)
{
	int pos;
	if (ini>fin) { pos = ini; }
	else if (ini == fin)
	{
		if (horario[ini]<h) { pos = ini + 1; }
		else { pos = ini; }
	}
	else
	{
		int m = (ini + fin) / 2;
		if (horario[m]<h) { pos = calculaHora(horario, m + 1, fin, h); }
		else { pos = calculaHora(horario, ini, m, h); }
	}

	return pos;
}



bool resuelveCaso()
{
	int numCasos;
	cin >> numCasos;
	if (numCasos == 0) { return false; }
	else{

		vector<Hora> array(3);
		for (int i = 0; i<numCasos; ++i) { cin >> array[i]; }

		
			try
			{
				Hora h;
				cin >> h;
				int pos = calculaHora(array, 0, array.size() - 1, h);
				if (pos == (int)array.size()) cout << "NO" << endl;
				else cout << array[pos] << endl;
			}
			catch (invalid_argument &ia)
			{
				cout << "ERROR" << endl;
			}
		


		return true;
	}
}



int main()
{
	while (resuelveCaso()) { cout << "---" << endl; }
	return 0;
}