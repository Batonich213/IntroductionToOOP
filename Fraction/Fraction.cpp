#define _CRT_SECURE_NO_WARNINGS
#include "Fraction.h";

Fraction operator+(const Fraction& left, const Fraction& right);

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//				Constructors:
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;	//Сохраняем целую часть десятичной дроби
	decimal -= integer;	//Убираем целую часть из десятичной дроби
	denominator = 1e+9;	//Записываем максиммально возможный знаменатель
	numerator = decimal * denominator;//Всю дробную часть десятичной дроби загружаем в числитель
	reduce();
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

//				Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;	//Вызов функции - Function call (operator*)
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}

Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}

//				Type-cast operators:
//type name(parameters)
Fraction::operator int(/*parameters*/)
{
	return integer;
}
Fraction::operator double()
{
	return integer + (double)numerator / denominator;
}

//				Methods:
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else more = denominator, less = numerator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;	//GCD - Greates Common Divisor (Наибольший общий делитель)
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;	//копируем объект
	inverted.to_improper();
	std::swap(inverted.numerator, inverted.denominator);
	return inverted;
}
void Fraction::print()const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer) cout << "(";
		cout << numerator << "/" << denominator;
		if (integer) cout << ")";
	}
	else if (integer == 0)cout << 0;
	cout << endl;
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator*(Fraction left, Fraction right)	//Реализация функции - определение функции (Function definition)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	//создаем временный безымянный объект, и сразу же возвращаем его на место вызова.
	//Временные безымянные объекты существуют только в пределах одного выражения (до ;)
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

////////////////////////////////////////////////////////////////////////////////////
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
	!true == false;
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}

////////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
//#define PRIMITIVE_EXTRACTION
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	//Оператор извлечения из потока (Extraction operator)

#ifdef PRIMITIVE_EXTRACTION
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	/*obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	obj(integer, numerator, denominator);
#endif // PRIMITIVE_EXTRACTION

	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";
	int number[3] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);

	int n = 0;	//счетчик чисел, извлеченных из строки
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;

	obj = Fraction();	//Обнуляем объект, сбрасываем его до объекта по умолчанию.
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numerator(number[0]); obj.set_denominator(number[1]); break;
	case 3: obj(number[0], number[1], number[2]);
	}
	return is;
}