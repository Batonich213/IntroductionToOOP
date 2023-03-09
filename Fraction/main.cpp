#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Fraction.h";
////////////////////////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define IOSTREAM_OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HOME_WORK_1
#define HOME_WORK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	(A + B).print();

	/*Fraction C = A * B;
	C.print();
	Fraction D = A / B;
	D.print();
	*/
	int a = 2;
	int b = 3;
	a *= b;//a=6		//a = a * b;
	a /= b;//a=2

	/*A *= B;
	A.print();
	A /= B;
	A.print();*/
#endif // ARITHMETICAL_OPERATORS_CHECK

	/*int a, b;
	cout << "Введите два числа: "; cin >> a >> b;
	int c = add(a, b);*/

	//cout << (Fraction(1, 2) >= Fraction(5, 11)) << endl;

#ifdef IOSTREAM_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // IOSTREAM_OPERATORS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	//	(type)value;	//C-like notation (C-подобная форма записи)
	//	type(value);	//Functional notation (Функциональная форма записи)

	int a = 2;		//No conversions
	double b = 3;	//Converion from less to more
	int c = b;		//Converion from more to less without data loss
	int d = 5.2;	//Conversion from more to less with data loss
	//cout << d << endl;
	cout << (double)7 / 2 << endl;
#endif // TYPE_CONVERSIONS_BASICS

	/*
	-----------------------------------
	1. From other to Class:
		-Single-argument constructor;
		-Assignment operator;
	2. From Class to other types:
	-----------------------------------
	*/

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;	//Conversion from less to more (From 'int' to 'Fraction')
	//preformed by Single-argument constructor.
	cout << A << endl;

	Fraction B;		//Default constructor
	B = Fraction(7);			//Assignment operator
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

	//explicit - запрещает неявные преобразования, 
	//и оставляет возможность лишь явно преобразовывать типы.

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
			/*
----------------------------------
	operator type()
	{
		.....
		conversion code;
		.....
		return value;
	}
----------------------------------
*/

	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HOME_WORK_1
	Fraction A(2, 3, 4);
	cout << A << endl;
	double a = A;
	cout << a << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	Fraction B = 2.76;
	cout << B << endl;
#endif // HOME_WORK_2

}