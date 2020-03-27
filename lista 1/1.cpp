#include <iostream>

int main()
{
    long int n = 68, wynik = 1;
  //int n(40), wynik(1);
  for(int i=1; i<=n; i++)
     {
       wynik = wynik * i;
       std::cout << wynik << std::endl;
     }
/* Zakres liczb int jest ograniczony po jakims przeskakuje
   na minimalne wartosc ( najpierw ujemne potem na 0 )
   Mozna wydluzyc zakres dajac zmienne long int 
*/
return 0;
}
