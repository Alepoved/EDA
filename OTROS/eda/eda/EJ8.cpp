#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


typedef int tArray[100000];


void contar(const tArray array, const int numElems);


int main()
{
	tArray array;

	int numCasos,numElems;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		cin >> numElems;
		for (int j = 0; j < numElems; j++) {
			cin >> array[j];
		}
		contar(array, numElems);
	}

	system("pause");
	return 0;
}


void contar(const tArray array, const int numElems) {
	int i = 0,aux1=0,aux2=0,posI=0,posF=0,j;

	while (i < numElems) {
		if (array[i] % 2 == 0) {
			aux1 = i;
			j = i + 1;
			while (array[j] % 2 == 0) {
				j++;
			}
			aux2 = j-1;
			
			if (posF - posI < aux2 - aux1) {
				posF = aux2;
				posI = aux1;
		}

			i = aux2;
		}
		else i++;

		

	}
	
	if (posF == 0 && posI == 0)cout << "Vacio" << endl;
	else cout << posF - posI << " => " << "[" << posI << "," << posF << ")" << endl;
	


	
	
}