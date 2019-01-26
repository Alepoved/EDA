#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int max = 10000;
const int max2 = 20;

typedef enum{filas,columnas,cruz,rotarF,rotarC};

typedef int tArray[max][max2];
typedef int tArray2[max];


int main() {
	tArray array;
	tArray2 aux;
	int numF, numC, numP, a, b, c;
	string instr;


	cin >> numF;
	cin >> numC;

	for (int i = 0; i < numF; i++) {
		for (int j = 0; j < numC; j++) {
			cin >> array[i][j];
		}
	}
	//	cin >> numP;
		//cin.ignore();
		//getline(cin, instr);
	cin >> instr;



	if (instr == "filas") {
		cin >> a; cin >> b;

		for (int i = 0; i < numC; i++) {
			aux[i] = array[a][i];
			array[a][i] = array[b][i];
			array[b][i] = aux[i];
		}
	}
	else if (instr == "rotar") {
		cin >> a;
		b = array[a][0];
		for (int i = 0; i < numC-1; i++) {
			
			array[a][i] = array[a][i+1];
		
		}
		array[a][numC-1] = b;
	}

	
	
		

	
	for (int i = 0; i < numF; i++) {
		for (int j = 0; j < numC; j++) {
			cout << array[i][j];
		}
		cout << endl;
	}
	


	system("pause");
	return 0;
}