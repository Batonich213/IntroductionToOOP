
#pragma once	//Äèðåêòèâà êîìïîíîâùèêà, êîòîðàÿ ãîâîðèò ÷òî äàííûé ôàéë 
//íóæíî âêëþ÷èòü â ñáîðêó îäèí ðàç, íåçàâèñèìî îò êîëè÷åñòâà #include-îâ

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
///////////				ÎÁÚßÂËÅÍÈÅ ÊËÀÑÑÀ - CLASS DECLARATION			///////////

class String;
String operator+(const String& left, const String& right);	//Ïðîòîòèï îïåðàòîðà +
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size;	//ðàçìåð ñòðîêè â Áàéòàõ
	char* str;	//óêàçàòåëü íà ñòðîêó â äèíàìè÷åñêîé ïàìÿòè
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Contructors:
	explicit String(int size = 80);
	String(const char* str);
	//Deep copy (Ïîáèòîâîå êîïèðîâàíèå)
	//other
	//this
	//Shallow copy (Ïîâåðõíîñòíîå êîïèðîâàíèå)
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);

	char operator[](int i)const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};

///////////			ÊÎÍÅÖ ÎÁÚßÂËÅÍÈß ÊËÀÑÑÀ - CLASS DECLARATION	END		///////////
///////////////////////////////////////////////////////////////////////////////////