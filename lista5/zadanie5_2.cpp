#include <iostream>

using namespace std;


class Samochod
{
public:
	Samochod(int n)
		//: _kola(n), _sruby(4 * _kola)
	{
		_kola = n;
		_sruby = 4 * _kola;

		cout << "samochod z " << _kola << " kolami i "
			<< _sruby << " srubami\n";
	}

private:
	int _sruby;
	int _kola;
};

int main()
{
	Samochod s4(4);
	Samochod s12(12);
	return 0;
}

