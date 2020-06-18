#include <iostream>
#include <assert.h>


class Stos
{
	public:
		Stos(); //konstruktor domyslny
		Stos(Stos const&); //konstruktor kopiujacy
		~Stos(); //dekonstruktor

		void push(int i); // doklada liczbe na stos
		void pop(); // zdejmuje liczbe ze stosu
		int top() const; // udostepnia wartosc liczby na szczycie stosu
		int& top(); // udostepnia referencje liczby na szczycie stosu
		bool empty() const; // czy stos jest pusty?
		size_t size() const; // aktualny rozmiar (logiczny) stosu
		Stos& operator = (Stos const&); // operator przypisania
		
	private:
		enum { initial_capacity = 1}; // stala wyliczeniowa		
		size_t _capacity; // rzeczywisty = fizyczny rozmiar tablicy
		size_t _size; // pozorny = logiczny rozmiar tablicy
		int* _tab; // tablica z danymi

		void _grow(); // prywatna funkcja sluzaca do rozszerzenia stosu
		void _shrink();

};

inline Stos::Stos()
	: _capacity(initial_capacity),
	_size(0),
	_tab(new int[initial_capacity])
{
	assert(initial_capacity > 0);
};

inline Stos::~Stos() { delete[] _tab; };

inline void Stos::push(int n)
{
	if (_size == _capacity) //jesli nie ma wiecej miejsca na stosie
	{
		_grow();
	}

	_tab[_size] = n;
	_size++;
};

inline void Stos::pop()
{
	assert(!empty());
	_size--;

	if (_capacity == 4 * _size)
	{
		_shrink();
	}
};

inline int Stos::top() const
{
	assert(!empty());
	return _tab[_size - 1];
};

inline int& Stos::top()
{
	assert(!empty());
	return _tab[_size - 1];
};

inline bool Stos::empty() const { return _size == 0; };

inline size_t Stos::size() const { return _size; };