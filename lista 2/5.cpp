#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <cstdlib>


using namespace std;

int fibo1(int n)
{
    if (n == 0 || n == 1)
        return n; 
    
    return fibo1(n - 1) + fibo1(n - 2);
}


int fibo2(int n)
{
    return (1 / sqrt(5)) * (pow((2 / (sqrt(5) - 1)), n) - pow((-2 / (sqrt(5) + 1)), n));
}


static vector<int> v = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };

int fibo3(int n)
{
    return v[n];
}

clock_t start, stop;
double czas;

// podpunkt d)
void d1(int x)
{
    for (int i = 0; i <= x; i++)
    {
        cout << i << " wyraz ciagu: " << fibo1(i) << "\n";
    }

}

void d2(int y)
{
    for (int i = 0; i <= y; i++)
    {
        cout << i << " wyraz ciagu: " << fibo2(i) << "\n";
    }

}

int main()
{
    start = clock();
    cout << "a) " << fibo1(10) << "\n"; // 10 wyraz ciagu = 45
    cout << "b) " << fibo2(10) << "\n"; // 10 wyraz ciagu = 44 (poniewaz liczba jest zaokraglana)
    cout << "c) " << fibo3(10) << "\n";// 10 wyraz ciagu = 45
    
	clock_t start = clock();
    d1(30);
    printf("Czas wykonywania: %lu ms\n", clock() - start);

    clock_t start2 = clock();
    d2(30);
    printf("Czas wykonywania: %lu ms\n", clock() - start2);
}
