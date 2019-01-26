#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


const long MAX = 100000;

typedef int tArray[MAX];
void contarMaximos(const tArray array, const long numValores);


int main()
{	
	long numCasos,numValores;
	
	tArray array;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> numValores;

		for (int j = 0; j < numValores; j++) {
			cin >> array[j];
		}

		contarMaximos(array,numValores);
	}

	

	system("pause");
	return 0;
}

void contarMaximos(const tArray array, const long numValores) {
	//0<=max<long
	//0<=numMax<numValores

	long max = 0,numMax=0;
	for (int i = 0; i < numValores; i++) {
		if (array[i] > max) max = array[i];
		if (array[i] == max)numMax++;
	}


	// #q=(exits i: 0<=i<array.length => forall j: 0<=j<array.length array[i]>array[j])

	cout << max << " " << numMax << endl;
}