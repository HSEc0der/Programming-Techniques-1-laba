#include <iostream>
#include "Header.h"
#include "fstream"
#include <vector>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <ctime>
#include "QuickSort.h"
#include "Vstavka.h"
#include "Bubble.h"


int main() {
	setlocale(LC_ALL, "Russian");

	std::vector<std::string> Data;
	std::ifstream In("D:\\УЧЕБА\\Методы программирования\\19var\\DataCpp.txt");
	std::string str;
	std::string s;
	while (!In.eof())
	{
		getline(In, str);
		Data.push_back(str);
	}

	int n = Data.size(); // количество строк в файле
	std::cout << n << "\n";
	int sep[9] = { 100, 500,1000,10000, 20000, 40000, 50000, 70000, n };
	//int sep[1] = { 100 };
	int length;


	for (int k = 0; k < 9; k++) {
		length = sep[k];
		N::our_class* cls = new N::our_class[length]; // динамический массив
		for (int i = 0; i < length; i++) {
			cls[i].set_all(Data[i]);

		}

		float start_time = clock(); // начало отсчета времени

		//bubble(cls, length);
		//vstavka(cls, length);
		//quicksort(cls, 0, length - 1);
		float end_time = clock(); // конец отсчета времени
		delete[] cls;
		std::cout << "Для n = " << sep[k] << " время выполнения: " << (end_time - start_time) / CLOCKS_PER_SEC << "\n";
	}
}
