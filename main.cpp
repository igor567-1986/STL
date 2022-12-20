#include<iostream>
#include<array>
#include<vector>
#include<list>
#include<algorithm>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

/*
-------------------------------------------------------------------
STL - Standard Template Library (����������� ��������� ����������)
��� ����� �����������, ����������, ����������, �������������� ��������, ���������� � �����������.
��������� - ��� ������, ������� ���������� �������� ������ �������� � ������.
� ������� ���������� ���� ���� ����� ����������, ������� ������� �� ����,
����� ��������� ������ ���������� ���� ���������.
��������� STL ��������� ����� �������, ��� ����� �������� � ������ ������������.
���������� ������:
���������������� (Sequence containers): array, vector, deque, list, forward_list;
������������� (Associative containers): map, multimap, set, multiset;
����������-�������� (Adaptors):			stack, queue � priority_queue;
��������������� ������������� ����������
(Unordered associative containers):		unordered_map, unordered_set, unordered_multimap, unordered_multiset;
-------------------------------------------------------------------
https://legacy.cplusplus.com/reference/stl/
-------------------------------------------------------------------
*/

template<typename T>void print(const std::vector<T>& vec);

//#define STL_ARRAY
//#define MY_EXCEPTION
//#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - ��� ���������, ������� ������ ������ � ���� ������������ �������.
	const int SIZE = 5;
	std::array<int, SIZE> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef MY_EXCEPTION
	try
	{
		throw std::exception("My test exception");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
#endif // MY_EXCEPTION

#ifdef STL_VECTOR

	//vector - ��� ���������, ������� ������ ������ � ���� ������������� �������.
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	//std::vector<int> vec(100000);
	//for (int i = 0; i < vec.size(); i++)vec[i] = rand();
	print(vec);
	vec.push_back(123);
	print(vec);
	
	/*
	capacity - size = ���������� ���������, ������� ����� ���� ��������� � ������ ��� ��������������� ������.
	���� ��� ���������� �������� capacity == size, �� ��������� ��������������� ������,
	� ������ ������� � ������� ���� ������ ������, ��� ��� ����������� ������.
	resize() - ������������� ������ ������ ������� ��� � �������, ��� � � ������� �������.
	shrink_to_fit() - ������� ��������������� ������� �� ������������ �������.
	reserve() - ��������� ��������� ��������������� (capacity), �������� ������ � ������� �������.
	*/
	vec.resize(7);
	print(vec);
	//vec.resize(10);
	//vec.shrink_to_fit();
	//print(vec);

	vec.reserve(12);
	print(vec);

	try
	{
		for (int i = 0; i < vec.capacity(); i++) 
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	int index;
	int number;
	int value;
	do
	{
		cout << "������� ������ ������������ ��������: "; cin >> index;
		if (index >= vec.size())cout << "Out of range" << endl;
	} while (index >= vec.size());
	cout << "������� ���������� ����������� ��������: "; cin >> number;
	cout << "������� �������� ������������ ��������: "; cin >> value;

	vec.insert(vec.begin() + index, number, value);
	print(vec);

	do
	{
		cout << "������� ������ ���������� ��������"; cin >> index;
		if (index >= vec.size())cout << "Out of range" << endl;
	} while (index>=vec.size());
	vec.erase(vec.begin()+index,vec.begin()+index+number);

#endif // STL_VECTOR
	std::list<int>list = { 3,5,8,13,21,34,55,69 };
	for (int i : list)cout << i << tab; cout << endl;
	int value;
	int index;
	cout << "������� ������ ����������� ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	std::advance
}
template<typename T>void print(const std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:    " << vec.size() << endl;
	cout << "Max size:" << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
}