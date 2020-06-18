#include "stos2.h"
#include <assert.h>

CStack::SItem::SItem(SItem* next, int value) : mNext(next), mValue(value)
{};


CStack::CStack() : mTop(0), mSize(0)
{
}


CStack::CStack(const CStack& stack) : mTop(0), mSize(0)
{
	push(stack.mTop);
}


CStack::~CStack()
{
	clear(); // usuniecie elementow ze stosu gdyby cos pozostalo
}


// metod zdejmuje wszystkie wartosci ze stosu (czysci stos)
void CStack::clear()
{
	while (mTop)
		pop();
};

// metoda kopiuje liste na stos, jest to (prywatna poniewaz struktura SItem jest prywatna)
void CStack::push(SItem* item)
{
	if (item)  
	{
		if (item->mNext)      
			push(item->mNext);
		push(item->mValue);
	}
};


// metoda odklada element na stosie
void CStack::push(int value)
{
	mSize++;
	mTop = new SItem(mTop, value);
};


// metoda umozliwia polozenie na stosie innego stosu, zachowana jest kolejnosc
void CStack::push(const CStack& stack)
{
	push(stack.mTop);
};

int CStack::pop(void)
{
		// mRoot nie moze miec wartosci NULL
	assert(mTop);

	mSize--;
	int value = mTop->mValue;
	SItem* item = mTop->mNext;
	delete mTop;
	mTop = item;
	return value;
};

// metoda odwraca elementy na stosie
// odwrocenie odbywa sie poprzez utworzenie nowego stosu oraz umieszczeniu na nim elementow w odwrotnej kolejnosci
// a nastepnie zamianie list
void CStack::reverse()
{
	CStack stack;
	SItem* item = mTop;

	while (item)
	{
		stack.push(item->mValue);
		item = item->mNext;
	}
	// zamian list dla stosow
	SItem* tmp = mTop;
	mTop = stack.mTop;
	stack.mTop = tmp;

};


// metoda zwraca wartosc z wierzcholka stosu
int CStack::top() const
{
	assert(mTop);
	return mTop->mValue;
}

int& CStack::top()
{
	assert(mTop);
	return mTop->mValue;
}


CStack& CStack::operator = (CStack const& stack)
{
	if (this == &stack)
		return *this;

	push(stack.mTop);
	return *this;
}


std::ostream& operator << (std::ostream& stream, const CStack& stack)
{
	CStack::SItem* item = stack.mTop;

	while (item)
	{
		stream << item->mValue;
		if (item->mNext)
		{
			stream << ", ";
		}
		item = item->mNext;
	}
	return stream;
}

