#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



int main()
{		//0<=n<letras.size;
		//coste bucle orden n^2
		//coste no lineal

	string letras = " ", aux = " ",aux2;
	bool repetido = false;

		cin >> letras;
		while(letras != "XXX") {
			for (int e = 0; e < letras.size() - 1; e++) {
				for (int q = 0; q<letras.size()-1; q++) {
					if (letras[q] == letras[q + 1])repetido = true;
				}
			}
			if (!repetido) {
				aux2 = "";
				aux2 = letras;

				for (int i = 0; i<letras.size() - 1; i++) {
					for (int j = 0; j < letras.size() - 1; j++) {
						if (letras[j]>letras[j + 1]) {
							aux[0] = letras[j];
							letras[j] = letras[j + 1];
							letras[j + 1] = aux[0];
						}
					}

				}

				if (aux2 == letras)cout << "SI" << endl;
				else cout << "NO" << endl;

			}
			else cout << "NO" << endl;

			cin >> letras;
			repetido = false;
		}
		

	//forall i,j: 0<=i<j<n : letras[i]<letras[j]
	


		system("pause");
	return 0;
}