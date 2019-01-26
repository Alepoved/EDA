#include <iostream>
using namespace std;



int busquedaBin(int v[],int a,int b,int elemB) {
	int r;

	if (a == b + 1)r = b;
	else {
		int m = (a + b) / 2;
		if (v[m] <= elemB)r = busquedaBin(v, m + 1, b, elemB);
		else r = busquedaBin(v, a, m - 1, elemB);

	}


	return r;
}





int main() {

	int n;
	cin >> n;
	int elemB;
	cin >> elemB;
	int v[10000];
	for (int i = 0; i < n; i++)cin >> v[i];
	int r=busquedaBin(v,0,n,elemB);
	cout << r << endl;

	system("Pause");
	return 0;
}