#include <iostream>
#include <chrono>

using namespace std;

// ZADANIE 3

void zad_3()
{
	unsigned int N = 60000;

	auto time = chrono::high_resolution_clock::now();

	for (unsigned int n = 1; n <= N; ++n)
	{
		int* p = new int[n];
		delete[] p;
	}

	auto time2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(time2 - time).count();

	cout << "new/delete operation took " << duration << " microseconds" << endl;

	int c = 0;

	auto time3 = chrono::high_resolution_clock::now();

	for (unsigned int n = 1; n <= N; ++n)
	{
		 c = c + 1;
	}

	auto time4 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::microseconds>(time4 - time3).count();

	cout << "adding int number operation took " << duration2 << " microseconds" << endl;

	float d = 0;

	auto time5 = chrono::high_resolution_clock::now();

	for (unsigned int n = 1; n <= N; ++n)
	{
		d = d + 1;
	}

	auto time6 = chrono::high_resolution_clock::now();
	auto duration3 = chrono::duration_cast<chrono::microseconds>(time6 - time5).count();

	cout << "adding float number operation took " << duration3 << " microseconds" << endl;

	double e = 0;

	auto time7 = chrono::high_resolution_clock::now();

	for (unsigned int n = 1; n <= N; ++n)
	{
		e = e + 1;
	}

	auto time8 = chrono::high_resolution_clock::now();
	auto duration4 = chrono::duration_cast<chrono::microseconds>(time8 - time7).count();

	cout << "adding double number operation took " << duration4 << " microseconds" << endl;


	/*
	  Przydzielanie pamiecie (tu operator new) jest czasochlonne poniewaz jest to zlozony proces i wymaga odwolania do menadzera pamieci;

	  sumowanie jest operacja prosta, zuzywajaca znacznie mniej czasu procesora;

	  nie ma wieliej roznicy pomiedzy sumowaniem liczb calkowitych (int) i rzeczywistych (float, double);
	  
	 */
	
}

void zad_4()
{
	double tab[10];
	double x;
	cout << &x << "\t" << &tab[-1] << "\n";

	/* 
	   tablica zostala zadeklarowana dla 10 elementow, uzycie indeksu -1 spowoduje odwolanie do obszaru pamieci lezacgo poza tablica. 
	   Moze to prowadzic do nieprzewidywalnego dzialania programu lub program moze zaliczyc "pad"
	*/ 
}

void zad_5()
{
	char haslo[8]; //tu bêdzie przechowywane has³o
	strcpy_s(haslo, "Ta.jnE!"); //kopiuje drugi argument w miejsce pierwszego
	
	for (;; ) {
		cout << "Podaj haslo: ";
		char tmp[8]; //zmienna tymczasowa na wczytanie has³a
		cin >> tmp;
		if (strcmp(tmp, haslo) == 0) { //czy teksty s¹ takie same?
			break;
		}
		cout << "przykro mi, haslo jest niepoprawne!\n";

		cout << "przestrzen miedzy tablicami " << (unsigned int)(haslo - &tmp[7] - 1) << endl;
	}
	cout << "witaj w systemie!\n";

	/*
		jesli kompilator umiesci w pamieci zmienne w kolejnosci tmp, haslo i nie bedzie kontroli dlugosci wprowadzonych danych (nieprzekraczajacych dlugosci tablicy tmp) to istnieje
		niebezpieczenstwo nadpisania danych w tablicy haslo 

		ten sposob zostal wykorzystany do wlamianiu sie do systemu. w prezentowanym programie kompilator umiescil zmienne w pamieci w kolejnosci tmp, haslo jedna po drugiej
		przy wpisywaniu hasla przz uzytkownika zostala wypelnona talica tmp oraz tablica haslo (wzorzec hasla zostal zmieniony)
		pierwszy obiet petli nie powiodl sie, poniewaz byly porownywane dwa lancuchy "123456781234567" oraz "1234567"
		przy kolejnym wpisaniu hasla uzykownik wpisal "1234567" czyli tablica tmp i haslo zawieraja takie same lacuchy
	
		Kompilator visual studio zostawia poiêdzy zmiennymi temp i haslo 8 bajtow wiec aby "wlamanie" bylo skuteczne nalezy 
		wpisac jako pierwszy np. ciag: 12345678123456781234567 

		Przy wyjsciu z funkcji zad_5 zglaszany jest wyjatek: "Run-Time Check Failure #2 - Stack around the variable 'haslo' was corrupted."
		co swiadczy o tym, ze niekontrolowane "nadpisywanie danych" nie zawsze jest "zdrpwe" dla programu.


	*/
}
int main()
{
	zad_3();
	zad_4();
	zad_5();
	return 0;
}

