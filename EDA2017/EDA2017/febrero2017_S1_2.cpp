#include <iostream>
using namespace std;

bool creciente(int v[],int a,int b,bool inicio) {
	int mitad = (a + b) / 2;

	if (!inicio && (b-a ==1)) {
		if ((v[b] - v[a]) <= (b - a))return true;
		else return false;
	}
	inicio = false;
	bool iz=true, de=true, fin=true;
	iz = creciente(v, a, mitad,inicio);
	if (iz) { 
		de = creciente(v, mitad, b, inicio);
	}
	return iz && de;
}


bool resuelve() {


	if (!cin)return false;

	int n;
	int v[10000];
	cin >> n;

	for (int i = 0; i < n; i++)cin >> v[i];

	bool parte1 = creciente(v,0,n-1,true);
	

	if (parte1)cout << "SI" << endl;
	else cout << "NO" << endl;



	return true;


}

int main() {

	while (resuelve());

	system("pause");
	return 0;
}