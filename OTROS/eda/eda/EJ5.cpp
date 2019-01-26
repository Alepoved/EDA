#include <iostream>
using namespace std;

const int MAX = 10000;

typedef int tArray[MAX];
void paresImpares(const tArray array, const int numElems);


int main() {
	tArray array;
	int numElems = 0, numCasos = 0;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> numElems;
		for (int j = 0; j < numElems; j++) {
			cin >> array[j];
		}

		paresImpares(array, numElems);

	}

	system("pause");
	return 0;

}

void paresImpares(const tArray array, const int numElems) {

	//0<=n<array.length
	//0<=pos<=numElems

	bool encontrado = false;
	int i = 0, pos = -1, j = 0;


	//caso pares-impares
	while (i < numElems && !encontrado) {
		if (array[i] % 2 != 0) {
			encontrado = true;
			pos = i;
		}
		else i++;
	}
	encontrado = false;
	j = pos;
	while (j<numElems && !encontrado) {
		if (array[j] % 2 == 0) {
			encontrado = true;
		}
		else j++;
	}

	if (encontrado == true) {
		cout << "NO" << " " << endl;
	}
	else {
		cout << "SI" << " " << pos << endl;
	}
	//existe = (∃q : 0 ≤ q ≤ n : pares(v, 0, q) ∧ impares(v, q, n))∧
	//existe →(0 ≤ p ≤ n ∧ pares(v, 0, p) ∧ impares(v, p, n));
}