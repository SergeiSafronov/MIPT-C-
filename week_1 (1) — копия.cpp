#include <iostream>
#include <cmath>




#include <clocale> //for normal russian symbols


using namespace std;


int main()
{
	double X1, X2, A, B, C;
	
	setlocale(LC_CTYPE, "rus"); //for normal russian symbols

	cout << "\nУстановите значение A: ";
	cin >> A;
	cout << "\nУстановите значение B: ";
	cin >> B;
	cout << "\nУстановите значение C: ";
	cin >> C;

	double D; //дискриминант


	D = B * B - 4 * A * C;

	if (D >= 0) //Если дискриминант больше или равен 0
	{
		X1 = (-1 * B + sqrt(D)) / (2 * A);
		cout << "\nКорень 1 равен " << X1 << endl;
		X2 = (-1 * B - sqrt(D)) / (2 * A);
		cout << "\nКорень 2 равен " << X2 << endl;
	}

	return 0;
}