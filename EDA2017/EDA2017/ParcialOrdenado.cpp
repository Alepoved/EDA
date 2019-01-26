#include <iostream>
using namespace std;


/*void esOrdenado(int v[], int a, int b, int &min, int &max, bool &ordenado) {
	
	if (a - b == 0) { min = v[a]; max = v[a]; ordenado = true; }

	else {
		int minIz, maxIz;
		int minDr, maxDr;
		bool ordenadoIz, ordenadoDr;
		int m = (a + b) / 2;

		esOrdenado(v, a, m, minIz, maxIz, ordenadoIz);
		esOrdenado(v, m + 1, b, minDr, maxDr, ordenadoDr);
		ordenado = ordenadoIz && ordenadoDr && (minIz <= minDr) && (maxDr >= maxIz);
		max = maxDr;
		min = minIz;

	}

}*/

void esOrdenado(int v[], int a, int b, int &min, int &max, bool &ordenado) {

	if (a == b) { min = v[a]; max = v[a]; }
	else {
		int minIz, maxIz, maxDe, minDe;
		int m = (a + b) / 2;
		esOrdenado(v, a, m, minIz, maxIz, ordenado);
		esOrdenado(v, m + 1, b, minDe, maxDe, ordenado);
		ordenado = (minIz <= minDe) && (maxDe >= maxIz);
		max = maxDe;
		min = minIz;
	}


}



bool casoDePrueba() {
	int v[100000];
	int n, minimo, maximo;
	int i = 1;
	bool isOrder;
	cin >> n;

	if (n == 0)
		return false;
	else {
		
		v[0] = n;
		cin >> n;

		while (n != 0) {

			v[i] = n;
			i++;
			cin >> n;

		}
		esOrdenado(v, 0, i - 1, minimo, maximo, isOrder);
		
		if (isOrder) cout << "SI" << endl;
		else cout << "NO" << endl;


		return true;
	}
} 
int main() {

	while (casoDePrueba());

	return 0;
}

/*#include <iostream>
using namespace std;



bool resuelve(int v[],int max,int min,int a,int b,bool r){

if (a>=b)r = true;
else {
if (v[a]<=max && v[b]>=min)r = resuelve(v, max, min, a + 1, b - 1, r);
}

return r;
}

int buscamax(int v[], int i){
int max = 0;
int m = i / 2;

while (m < i){
if (max < v[m]) max = v[m];
else ++m;
}

return max;
}

int buscamin(int v[], int i){
int m =( i / 2)-1;
int min = v[m];

while (m >= 0){
if (min > v[m]) min = v[m];
else m--;
}

return min;
}

bool casodeprueba(){
int v[1000];
int num, i = 0;

cin >> num;
if (num == 0) return false;

else{
while (num != 0){
v[i] = num;
cin >> num;
++i;
}

int max = buscamax(v, i);
int min = buscamin(v, i);

bool cierto = resuelve(v,max,min,0,i-1,false);


if (cierto) cout << "SI" << endl;
else cout << "NO" << endl;
return true;
}
}


int main(){

while (casodeprueba());

return 0;
}

*/
