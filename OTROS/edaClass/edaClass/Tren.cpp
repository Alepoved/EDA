#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>


#include "Hora.h"

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
	int trenes, numHoras;

cin >> trenes >> numHoras;
	if (trenes == 0) { return false; }
	else {

		vector<Hora> horario(trenes);
		for (int i = 0; i<trenes; ++i) { cin >> horario[i]; }

		for (int i = 0; i<numHoras; ++i)
		{
			try
			{
				Hora h;
				cin >> h;
				int pos = calculaHora(horario, 0, horario.size() - 1, h);
				if (pos == (int)horario.size()) cout << "NO" << endl;
				else cout << horario[pos] << endl;
			}
			catch (invalid_argument &ia)
			{
				cout << "ERROR" << endl;
			}
		}


		return true;
	}
}



int main()
{
	while (resuelveCaso()) { cout << "---" << endl; }
	return 0;
}