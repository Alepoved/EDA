#include <iostream>
using namespace std;

const int MAX = 100000000;

typedef int tArray[MAX];

void contar(tArray array, int numTemp);

int main() {
	tArray array;
	int numCasos = 0,numTemp=0;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> numTemp;
		for (int j = 0; j < numTemp; j++) {
			cin >> array[j];
		}
		contar(array,numTemp);
	}

	system("pause");
	return 0;

}

void contar(tArray array,int numTemp) {
	int picos = 0, valles = 0;
	for (int i = 1; i < numTemp-1; i++) {
		if (array[i] < array[i - 1] && array[i] < array[i + 1])valles++;
		else if (array[i] > array[i - 1] && array[i] > array[i + 1])picos++;
	}
	cout << picos << " " << valles << endl;
}