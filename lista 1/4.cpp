#include <iostream>
#include <cmath>

using namespace std;

void a()
{
    double t0 = 1 / sqrt(3);
    double ti = t0;
    double pi;

    for (int i = 0; i <= 30; i++) {
        ti = (sqrt(pow(ti, 2) + 1) - 1) / ti;
        pi = 6 * pow(2, i) * ti;
        cout << i << " : " << pi * 2 << endl;
    }
}

void b()
{
    double t0 = 1 / sqrt(3);
    double ti = t0;
    double pi;

    for (int i = 0; i <= 30; i++) {
        ti = ti / (sqrt(pow(ti, 2) + 1) + 1);
        pi = 6 * pow(2, i) * ti;
        cout << i << " : " << pi * 2 << endl;
    }
}


int main()
{
    a(); /// b³¹d wzrasta
    b(); /// b³¹d maleje

    return 0;
}