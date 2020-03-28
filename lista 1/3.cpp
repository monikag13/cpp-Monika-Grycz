#include <iostream>

using namespace std;


int main()
{
	int x = 1;
	int y = x++;
	int z = --y + x;
	int v = z += 2;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	cout << "v: " << v << endl;

}