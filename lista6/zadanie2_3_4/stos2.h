#ifndef __STOS2_H__
#define __STOS2_H__

#include <ostream>


class CStack
{
	private:
		struct SItem
		{
			SItem* mNext;
			int mValue;
			SItem(SItem* next, int value);
		} *mTop;

		size_t mSize;

		void push(SItem* item);
		
	public:
		CStack();
		CStack(const CStack& stack);
		~CStack();

		void clear();
		bool empty() const { return mTop == 0; };  // lub mSize == 0
		void push(int value);
		void push(const CStack& stack);
		int pop(void);

		// zadanie 4
		void reverse();
		
		size_t size() const { return mSize; };
		int top() const;
		int& top();

		CStack& operator = (CStack const& stack);

		// zadanie 3
		friend std::ostream& operator << (std::ostream& stream, const CStack& stack);	
};


#endif