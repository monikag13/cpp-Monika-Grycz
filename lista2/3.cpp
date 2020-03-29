#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double operator *(vector<double> v, vector<double> w) 
{
    if (v.size() != w.size())
    {
        cout << "wektory musza byc jednakowej dlugosci!" << endl;
        return 0;
    }

    else
    {
        double wynik = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            wynik += v[i] * w[i];
        }
        return wynik;
    }


}

int main()
{
    vector<double> v = { 1,2,3 };
    vector<double> w = { 3,2,1 };
    cout << v * w << endl;
    return 0;
}