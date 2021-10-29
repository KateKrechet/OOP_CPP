#include <iostream>
#include <math.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


double distance(class Point& A, class Point& B);


class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//Constructors
	Point()
	{
		x = 0;
		y = 0;
		cout << "DefaultConstructor: " << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t " << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t " << this << endl;
	}
	//Operators

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t \t" << this << endl;
		return *this;
	}

	//Increment/Decrement

	Point& operator++()//Prefix increment
	{
		this->x++;
		this->y++;
		cout << "PrefixIncrement:\t" << this<<endl;
		return *this;
	}

	Point operator++(int)//Suffix increment
	{
		Point old = *this;//сохраняем текущее значение нашего объекта
		this->x++;
		this->y++;
		cout << "SuffixIncrement:\t" << this<<endl;
		return old;
	}

	//Method
	double distance(class Point& other)
	{
		/*double x_distance = other.x - this->x;
		double y_distance = other.y - this->y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print() const
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}

};

Point operator+(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() + right.get_x());
	buffer.set_y(left.get_y() + right.get_y());
	return buffer;
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "x=" << obj.get_x() << "\t" << "y=" << obj.get_y();
	return os;
}
istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x;
	is>> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

//#define DISTANCE
//#define STRUCT_POINT
//#define CONSTRUCTORS CHECK
//#define ASSIGMENT CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
#define delimiter "\n------------\n"

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A;//объявление переменной А типа Point
//объявление экземпляра А структуры Point
//объявление, создание объекта А структуры Point   
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STR

#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(2);
	//cout << "Координаты точки А: " << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B;
	B.set_x(3);
	B.set_y(3);
	cout << "Координаты точки В: " << B.get_x() << "\t" << B.get_y() << endl;


	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между А и В точками: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между В и А точками: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE
#ifdef CONSTRUCTORS CHECK
	Point A;
	A.print();
	Point B(2, 3);
	B.print();
	Point C = B;//CopyConstructor
	C.print();
	Point D;
	D = B;//CopyAssigment
	D.print();
#endif // CONSTRUCTORS CHECK
#ifdef ASSIGMENT CHECK
	int a, b, c;
	a = b = c = 1;
	cout << a << "\t" << b << "\t" << c << "\t" << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);//Point(2,3)-явный вызов конструктора
							//Т.о.создается временный безымянный объект, кот существует только в пределах выражения
							//и удаляется после завершения выражения
	cout << delimiter << endl;	A.print();
	B.print();
	C.print();

#endif // ASSIGMENT CHECK

#ifdef ARIFMETICAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	Point C = A + B;//Чтобы научить оператор складывать точки, его необходимо перегрузить для класса точка
	C.print();
#endif // ARIFMETICAL_OPERATORS_CHECK

	/*for (Point i(2, 3); i.get_x() < 10; i++)
	{
		i.print();
	}*/
	Point A(2, 3);
	Point B = A++;
	A.print();
	B.print();
	cout << A << endl;;
	cout << B<<endl;

	cout << "Введите координаты точки А: ";
	cin >> A;
	cout << A << endl;


}

double distance(class Point& A, class Point& B)
{
	//return A.distance(B);
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

}

