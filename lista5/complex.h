#include <iostream>

using namespace std;

class Complex
{

public:

    double real, imag;

    Complex(); //domyslne argumenty = 0
    Complex(double r, double i); // zainicjowane
    Complex(Complex& c);

    Complex operator + (const Complex& c1);
    Complex operator - (const Complex& c1);
    Complex operator * (const Complex& c1);
    Complex operator / (const Complex& c1);

    friend ostream& operator << (ostream& out, const Complex& c1)
    {
        out << c1.real;
        out << " + " << c1.imag << "i" << endl;
        return out;
    }

    friend istream& operator >> (istream& in, Complex& c1)
    {
        cout << "Real part: ";
        in >> c1.real;
        cout << "Imaginary part: ";
        in >> c1.imag;
        return in;
    }

};


Complex::Complex() : real(0), imag(0)
{};
Complex::Complex(double r, double i) : real(r), imag(i)
{};
Complex::Complex(Complex& c) : real(c.real), imag(c.imag)
{};


Complex Complex::operator + (const Complex& c)
{
    Complex x;
    x.real = real + c.real;
    x.imag = imag + c.imag;
    return x;
};

Complex Complex::operator - (const Complex& d)
{
    Complex x;
    x.real = real - d.real;
    x.imag = imag - d.imag;
    return x;
};

Complex Complex::operator * (const Complex& c1)
{
    Complex x;
    x.real = real * c1.real - imag * c1.imag;
    x.imag = real * c1.imag + c1.real * imag;
    return x;
};

Complex Complex::operator / (const Complex& c1)
{
    Complex x;
    double p = real * real + c1.imag * c1.imag;
    x.real = (real * c1.real + imag * c1.imag) / p;
    x.imag = (imag * c1.real - real * c1.imag) / p;
    return x;
};
