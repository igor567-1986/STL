#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------------------\n"

#define STD_STRING_PARCE
const std::map<int, std::string> violation =
{
	{0, "Проезд на красный"},
	{1, "Превышение скорости"},
	{2, "Парковка в неположеном месте"},
	{3, "Езда по встречной полосе"},
	{4, "Оскорбление офицера"},
	{5, "Езда в нетрзвом состоянии"},
	{6, "Дрифт на перекрестке"}
};

class Crime
{
	int id;
	std::string place;
public:
	Crime(int violation, const std::string& place)
		:id(violation), place(place) {}
	~Crime() {}
	friend std::ostream& operator<<(std::ostream& os, const Crime& obj);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj);
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << violation.at(obj.id) << ", " << obj.place;
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.id << " " << obj.place;
	return ofs;
}

void print(const std::map<std::string, std::list<Crime>>& base);


void main()
{
	setlocale(LC_ALL, "");
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777bb", {Crime(0, "Улица ленина"), Crime(6, "ул. Космонавтов"), Crime(3, "ул. Октябрьская")}},
		{"m123ab", {Crime(2, "площадь Революции")}},
		{"a234bb", {Crime(5, "ул. Ленина"), Crime(4, "ул. Ленина")}}
	};
	print(base);
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << endl;
		}
		cout << delimiter << endl;
	}
}