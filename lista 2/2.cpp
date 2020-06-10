#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zad2(vector<double> &vector)
{
    fill(vector.begin(), vector.end(), 0);
}


int main()
{
    vector<double> v = { 3.5, 2.5, 1.5, 5 };
    zad2(v);
            for (int i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
    return 0;
}
