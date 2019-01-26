#include <iostream>
using namespace std;


void calculaSoluciones(int v[],bool disponibles[],int solucion[],int &numSol ,int n, int etapa,int pos) {




	for (int i = 0; i < 2*n; i++) {
		if ((pos+i+1)<=2*(n)-1 && solucion[i]==0 && solucion[i+pos+1]==0) {
			solucion[i] = pos; solucion[i+pos+1] = pos;

			if (etapa ==n-1) {
				for (int i = 0; i < 2*n; i++) cout << solucion[i] << " ";
				cout << endl;
				numSol++;
				solucion[i] = 0; solucion[i + pos + 1] = 0;
			}
			else {
				calculaSoluciones(v, disponibles, solucion, numSol, n, etapa+1,pos+1);
				 solucion[i] = 0; solucion[i + pos + 1] = 0;
			}
		}
	}
	
}

void resuelve() {

	int n,numSol=0;
	int v[10000],solucion[1000];
	bool disponibles[1000];

	cin >> n;

	

	for (int i = 0; i < 2*n; i++) {
	
		solucion[i] = 0;
		disponibles[i] = true;

	}


	calculaSoluciones(v,disponibles,solucion,numSol, n, 0,1);
	
	cout << "SOLUCIONES: " << numSol << endl;
	cout << endl;
	
}
int main() {


	int num;

	cin >> num;

	for (int i = 0; i < num; i++)resuelve();


	system("pause");
	return 0;
}