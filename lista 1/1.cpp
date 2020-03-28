#include <iostream>

using namespace std;

int main()
{
	int i = 40, wynik = 1;
	/*long int i = 40, wynik = 1;*/

	for (i = 1; i <= 40; ++i)
	{
		wynik = wynik * i;
		cout << wynik << endl;
	}
	return 0;
}

/* Błąd wynika z zakresu wartości typu int (-2147483648 ÷ 2147483647), który można wydłuzyć używając 'long int'*/
