#include <iostream>
#include "complex.h"

int main()
{
    Complex c1(1, 1);
    Complex c2(1, -1);
    Complex c3;

    cout << c1 + c2 << "\n";
    cout << c1 - c2 << "\n";
    cout << c1 * c2 << "\n";
    cout << c1 / c2 << "\n";

    cin >> c3;

    cout << c1 + c3 << "\n";

} 