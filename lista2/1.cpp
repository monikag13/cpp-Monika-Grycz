#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int zad1(vector<int> vector) {
    if (vector.empty())
    {
        return INT_MIN;
    }

    else {
        int min = *min_element(vector.begin(), vector.end());
        return min;
    }

}

int main()
{
    vector<int> v = { 3,2,1 };
    cout << zad1(v) << endl;
	return 0;
}