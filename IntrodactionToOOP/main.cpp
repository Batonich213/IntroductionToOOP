#include "IntroductionToOOP.h"

void main()
{
	setlocale(LC_ALL, "Russian");

	//cout << add() << endl;
	//cout << "\n----------------------------\n";

#ifdef STRUCT_POINT
	int a;	//���������� ���������� 'a' ���� 'int'
	Point A;//���������� ���������� 'A' ���� 'Point'
	//�������� ������� 'A' ��������� 'Point'
	//�������� ���������� 'A' ��������� 'Point'
	//������� ������� � �������� ��� �������� ������������ ������� � ��������.

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONTRUCTORS_CHECK
	Point A;		//����� ���������� ����������� �� ��������� (Default constructor)
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;	//Single-argument constructor
	B.print();

	Point C(22, 33);
	C.print();

	Point D = C;	//Copy constructor
	D.print();

	Point E;		//Default constructor
	E = D;			//Copy assignment
	E.print();

	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;*/
#endif // CONTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	/*
------------------
1. ��������� ������;
2. ��� ���� ���������� �����;
3. � ���� ����� ���������� ��������� �����
   (������� ��� �� �������������� ������ ���� �������);
------------------
*/

	Point A(2, 3);
	A.print();

	Point B(4, 5);
	B.print();
	cout << delimiter << endl;
	cout << "���������� �� ����� A �� ����� B:" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� B �� ����� A:" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� A � B:  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� B � A:  " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	//Copy assignment:

	int a, b, c;
	a = b = c = 2;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << "\n-------------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n-------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);	A.print();
	Point B(4, 5);	B.print();
	Point C = A + B; C.print();
	C++; C.print();
}

