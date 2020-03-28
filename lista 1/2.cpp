#include <iostream>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main()
{
	int n = 1000000;
	double wynik, wynik2, suma = 0, iloczyn = 1, pi = acos(-1), wynik3, suma2 = 0;
	

	for (int j = 1; j <= n; ++j)
	{
		wynik = (pow(-1, j + 1) / (2.0 * j - 1));
		suma = suma + wynik;
	}
	cout << "a): " << suma * 4 << endl;

	for (int x = 1; x <= n; x++)
	{
		wynik2 = (4.0 * x * x) / ((4.0 * x * x) - 1);
		iloczyn = (iloczyn * wynik2);
	}
	cout << "b): " << iloczyn * 2 << endl;


	for (int y = 1; y <= n; ++y)
	{
		wynik3 = 1 / pow(2 * y - 1, 2);
		suma2 = suma2 + wynik3;
	}
	cout << "c): " << sqrt(8*suma2) << endl;
	return 0;
}

