#pragma once
#include <iostream>
using namespace std;
class Point
{
	//Создавая структуру или класс мы создаем новый тип данных
	//Классы и структуры еще называют пользовательскими типами данных
	//						КЛАСС - ЭТО ТИП ДАННЫХ!!!
	//					СТРУКТУРА - ЭТО ТИП ДАННЫХ!!!
	double x;
	double y;
public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);

	//				  Constructors:
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	//					Operators:
	Point& operator=(const Point& other);

	Point& operator++();	//Prefix increment
	Point operator++(int);

	//					Methods:
	double distance(const Point& other)const;
	void print()const;
};

Point operator+(const Point& left, const Point& right);

double distance(const Point& A, const Point& B);

int add(int a = 0, int b = 0);