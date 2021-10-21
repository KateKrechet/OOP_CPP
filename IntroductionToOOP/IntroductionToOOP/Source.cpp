#include <iostream>
#include <math.h>
using namespace std;
//#define DISTANCE
//#define STRUCT_POINT

double distance(class Point A, class Point B);

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

	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t \t" << this << endl;
	}

	//Method
	double distance(Point other)
	{
		/*double x_distance = other.x - this->x;
		double y_distance = other.y - this->y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print() const
	{
		cout << "X = " << x << "\t" << "Y = " <<y<< endl;
	}

};


void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
#ifdef DISTANCE
	Point A;//объявление переменной А типа Point
//объявление экземпляра А структуры Point
//объявление, создание объекта А структуры Point   
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STR

	Point A;
	A.set_x(2);
	A.set_y(2);
	//cout << "Координаты точки А: " << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B;
	B.set_x(3);
	B.set_y(3);
	cout << "Координаты точки В: " << B.get_x() << "\t" << B.get_y() << endl;


	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки A до точки B: " << B.distance(A) << endl;
	cout << "Расстояние между А и В точками: " << distance(A, B) << endl;
	cout << "Расстояние между В и А точками: " << distance(B, A) << endl;
#endif // DISTANCE
	Point A;
	A.print();
	Point B(2,3);
	B.print();
	Point C = B;//CopyConstructor
	C.print();
	Point D;
	D = B;//CopyAssigment
	D.print();

}

double distance(class Point A, class Point B)
{
	//return A.distance(B);
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
	
}

