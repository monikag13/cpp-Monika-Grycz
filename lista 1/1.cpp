#include <iostream>

using namespace std;

int main()
{
	int n = 68, wynik = 1;

	for (int i = 1; i <= n; ++i)
	{
		wynik = wynik * i;
		cout << wynik << endl;
	}
	return 0;
}

/* Błąd wynika z zakresu wartości typu int (od -32768 do 32767), który można wydłuzyć używając 'long int'*/
