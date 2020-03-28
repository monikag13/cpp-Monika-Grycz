#include <iostream>

int main()
{
  int n = 68, wynik = 1;

  for(int i=1; i<=n; i++)
     {
       wynik = wynik * i;
       std::cout << wynik << std::endl;
     }
/* Zakres liczb int jest ograniczony (od -32768 do 32767), po pewnym czasie przeskakuje na minimalne wartosci (ujemne, następie 0).
Mozna wydluzyc zakres dajac zmienną na long int. */
  
return 0;
}
