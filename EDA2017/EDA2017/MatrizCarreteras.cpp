#include <iostream>
using namespace std;

const int n = 3;


/*bool esFactible(int f, int c,int xo,int yo) {
	

	return ( f < n && c < n && (((f==xo-1) && (c==yo))|| ((f == xo) && (c == yo-1)) || ((f==xo) && (c == yo+1)) || ((f == xo + 1) && (c == yo)))) ;


}*/

/*void calculaDistancia(int v[10][10],int solucion[10][10],bool disponibles[10][10], int xo, int yo, int xd, int yd, int &distancia,int distanciaAux, int etapa) {
	

	for (int f = 0; f < 3 ; f++) {
		for (int c = 0; c < 3 ; c++) {
			
			if (esFactible(f,c,xo,yo) && disponibles[f][c] && (v[xo][yo]-v[f][c])<=2) {
				cout << "it:"<<etapa<<" "<< v[xo][yo] << "->" << v[f][c] << endl;
				
				disponibles[f][c] = false;
				solucion[xo][yo] = v[f][c];
			//	cout << solucion[xo][yo] << " ";
				xo = f;
				yo = c;
				if (xo == xd && yo == yd /*&& distanciaAux<distancia*//*) {
					distancia = etapa;
					//distanciaAux = 0;
					cout << "----distancia----" << endl;
					cout << etapa<< endl;
					disponibles[xo][yo] = true;

				}
				else {
					calculaDistancia(v,solucion, disponibles, xo, yo, xd, yd, distancia, distanciaAux + 1, etapa + 1);
					disponibles[f][c] = true;
				
				}
			}
		}
	}

}

*/

bool esFactible(int f,int c,int xo,int yo) {
	//return (f < n && c < n && (((f == xo - 1) && (c == yo)) || ((f == xo) && (c == yo - 1)) || ((f == xo) && (c == yo + 1)) || ((f == xo + 1) && (c == yo))));
	return ((f==xo &&(c==yo-1 ||c==yo+1))|| (f==xo-1 && c==yo) || (f==xo+1 && c==yo));
}


void calculaDistancia(int v[10][10], int solucion[10][10], bool disponibles[10][10], int xo, int yo, int xd, int yd, int distancia, int distanciaAux, int etapa) {
		
	for (int f = 0; f < 3; f++) {
		for (int c = 0; c < 3; c++) {
			
			if (disponibles[f][c] && esFactible(f,c,xo,yo) && ((v[xo][yo] - v[f][c]) <= 2)) {
				//disponibles[xo][yo] = false;
				cout << xo << ", " << yo << " -> " << f << ", " << c << endl;
				disponibles[f][c] = false;
				//xo = f; yo = c;
				if (f == xd && c == yd) {
					cout << "Destino encontrado, distancia: " << distancia << endl;
					disponibles[f][c] = true;
				}
				else {
					disponibles[xo][yo] = false;//inutil?
					
					calculaDistancia(v, solucion, disponibles, f, c, xd, yd, distancia + 1, distanciaAux, etapa + 1);
					disponibles[f][c] = true;
					disponibles[xo][yo]=true; //inutil??
				}
			}



		}
	}




}

int main() {

	int v[10][10];
	int max, xo, yo, xd, yd;
	int distancia=2;
	bool disponibles[10][10];
	int solucion[10][10];

	for (int f = 0; f < 3; f++) {
		for (int c = 0; c < 3; c++) {
			cin >> v[f][c];
			disponibles[f][c] = true;
		}
	}

	for (int f = 0; f < 3; f++) {
		for (int c = 0; c < 3; c++) {
			cout<< v[f][c]<<" ";
			
		}
		cout << endl;
	}

	
	cout << " xo yo xd yd" << endl;
	cin >> xo >> yo >> xd >> yd;
	disponibles[xo][yo] = false;

	calculaDistancia(v, solucion,disponibles, xo, yo, xd, yd, distancia, 0, 1);


		
	system("pause");
	return 0;


}