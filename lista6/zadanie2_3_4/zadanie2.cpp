// Zadanie2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "stos2.h"


int main()
{
    
    CStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    
    std::cout << "stos 1: " << stack << std::endl;

    CStack stack2 = stack;
    stack2.push(5);
    std::cout << "stos 2: " << stack2 << std::endl;
    
    CStack stack3; 
    // odlozenie stosu na stosie
    stack3.push(stack);
    stack3.push(stack2);
    stack3.push(6);
    std::cout << "stos 3: " << stack3 << std::endl;

    stack3.reverse();
    std::cout << "stos 3: " << stack3 << std::endl;


    // zdjecie elementow ze stosu
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

      // wyczyszczenie stosu
      stack2.clear();

    // elementy stosu zostana usuniete w destruktorze
//    stack3.clear();
    
}
