#include <iostream>
using namespace std;



int base6(int num) {

	int r;

	if (num < 6)r = num;
	else {
		r = base6(num / 6) * 10 + num % 6;
	}

	return r;

}


bool resuelve() {

	int num;
	cin >> num;
	int r=base6(num);
	cout << r << endl;

	return true;
}

int main() {

	while (resuelve());
	system("pause");
	return 0;
}