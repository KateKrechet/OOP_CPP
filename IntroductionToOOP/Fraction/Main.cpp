#include<iostream>
using namespace std;

int nod(int a, int b);

class Fraction
{
	int integer;//Целая часть
	int numerator;//Числитель
	int denominator;//Знаменатель

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	//Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{//Single-argument constructor - Конструктор с 1 параметром
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Contractor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor^\t" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}
	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*(const Fraction& other)
	{
		this->to_improper();
		numerator = numerator * (other.get_integer() * other.get_denominator() + other.get_numerator());
		denominator = denominator * other.get_denominator();
		this->to_proper();
		reduce();
		return *this;
	}
	Fraction& operator/(const Fraction& other)
	{
		this->to_improper();
		numerator = numerator * other.get_denominator();
		denominator = denominator * (other.get_integer() * other.get_denominator() + other.get_numerator());
		reduce();
		this->to_proper();
		return *this;
	}

	Fraction& operator+(const Fraction& other)
	{
		this->to_improper();
		if (denominator == other.get_denominator())
		{
			numerator = numerator + (other.get_integer() * other.get_denominator() + other.get_numerator());
			denominator = other.get_denominator();
		}
		else
		{
			numerator = numerator * other.get_denominator() + (other.get_integer() * other.get_denominator() + other.get_numerator()) * denominator;
			denominator = denominator * other.get_denominator();
		}
		this->to_proper();
		reduce();
		return *this;
	}
	Fraction& operator-(const Fraction& other)
	{
		this->to_improper();
		if (denominator == other.get_denominator())
		{
			numerator = numerator - (other.get_integer() * other.get_denominator() + other.get_numerator());
			denominator = other.get_denominator();
		}
		else
		{
			numerator = numerator * other.get_denominator() - (other.get_integer() * other.get_denominator() + other.get_numerator()) * denominator;
			denominator = denominator * other.get_denominator();
		}
		//this->to_proper();
		//reduce();
		return *this;
	}
	//Methods
	void to_proper()
	{
		//переводит дробь в правильную
		integer += numerator / denominator;
		integer>0?numerator %= denominator:abs(numerator %= denominator);
	}
	void to_improper()
	{
		//переводит дробь в неправильную
		numerator += integer * denominator;
		integer = 0;
	}
	void reduce()
	{
		//сокращает дробь
		int x = nod(numerator, denominator);
		numerator = numerator / x;
		denominator = denominator / x;

	}
	void print()
	{
		/* (integer > 0 && numerator > 0 && denominator > 0) cout << integer << "(" << numerator << "/" << denominator << ")"<<endl;
		if (integer == 0 && numerator > 0 && denominator > 0) cout <<  numerator << "/" << denominator << endl;
		if (integer > 0 && numerator == 0 && denominator == 0) cout << numerator <<  endl;
		if (integer== 0 && numerator == 0 && denominator == 0) cout << 0 << endl;*/
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;

	}

};

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;//конструктор по умолчанию
	A.print();
	Fraction B = 5;//Single-argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK
	Fraction A(14, 4);
	A.to_proper();
	A.print();
	A.to_improper();
	A.print();
	A.reduce();
	A.print();
	A.to_proper();
	A.print();
	Fraction B(5, 2);
	Fraction C(5, 2);
	Fraction D = B * C;
	D.print();
	Fraction F(5, 2);
	Fraction G(2, 1, 2);
	Fraction E = F / G;
	E.print();
	Fraction X(1,3);
	Fraction Y(5,2);
	Fraction Z = X - Y;
	Z.print();

}

int nod(int a, int b)
{
	while (b > 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}