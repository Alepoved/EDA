#include <iostream>
using namespace std;


typedef int tArray[10000];
void contar(const tArray array);


int main() {

	tArray array;

	for (int i = 0; i < 5; i++) {
		cin >> array[i];
	}

	contar(array);


	


	system("pause");
	return 0;
}

void contar(const tArray array) {
	int numP=0, numI=0;

	for (int i = 0; i < 5; i++) {
		if (array[i] % 2 == 0)numP++;
		else numI++;
	}

	int r = std::fmin(numP, numI);
	cout << " el numero de pares e impares es " << r << endl;
	cout << "pares " << numP << endl;
	cout << "impares " << numI << endl;
}