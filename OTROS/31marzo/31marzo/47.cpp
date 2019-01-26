#include <iostream>
#include <string>
#include <cstdlib>
#include "List.h"
#include <sstream>
using std::noskipws;
using namespace std;




int main() {

	List<int> lista;
	List<int> res;
	int numCasos, num, suma = 0, numVeces = 0;
	
	bool fin = false;
	char aux;
	cin >> numCasos;
	cin.get(aux);

	for (int i = 0; i < numCasos; i++) {
		
		cin.get(aux);
		
		
		while (aux!='\n') {
			cin.putback(aux);
			cin >> num;
			lista.push_back(num);
			cin.get(aux);
			
		}


		int cont = lista.size();
		//suma= lista.at(i);
		for (int j = 0; j <cont ; j++) {
		//	cout << lista.at(0) << endl;
			if (suma == lista.at(0)) {
				res.push_back(suma);
				numVeces++;
			}
			
			suma += lista.at(0);
			//cout << lista.at(0);
			res.push_back(lista.at(0));
			lista.pop_front();
			
		}
		int cont2 = res.size();
		cout << numVeces << ": ";
		for (int i = 0; i < cont2; i++) {
			cout <<res.at(0) << " ";
			res.pop_front();
		}
		cout << endl;
		
		lista.~List();
		res.~List();
		numVeces = 0;
		suma = 0;
	}



	system("pause");
	return 0;
}