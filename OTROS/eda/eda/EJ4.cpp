#include <iostream>
using namespace std;

const int MAX = 100000;

typedef int tArray[MAX];
void ordenado(const tArray array, const int numElems);


int main() {
	tArray array;
	int numElems=0, numCasos = 0;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> numElems;
		for (int j = 0; j < numElems; j++) {
			cin >> array[j];
		}

		ordenado(array,numElems);
	
	}

	system("pause");
	return 0;

}

void ordenado(const tArray array,const int numElems) {
	//0<=n<array.length
	//0<=numColados<n
	int numColados = 0;
	int i = 0;
	
		for (int j = 1; j < numElems; j++) {
			if (array[i] >= array[j]) {
				numColados++;
				i = j;
			}
			else i++;

		}
		
	

	cout << numColados << endl;
	


	//q== numColados=(i#: 0<=i<n y forall j: i<j<n array[i]>=array[j]);

}