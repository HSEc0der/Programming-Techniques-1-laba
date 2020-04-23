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
#include <cstdio>

int main() {
	setlocale(LC_ALL, "Russian");

	std::vector<std::string> Data;
	std::ifstream In("D:\\УЧЕБА\\Методы программирования\\19var\\DataCpp.txt");
	std::string str;
	while (!In.eof())
	{
		getline(In, str);
		Data.push_back(str);
	}
	///////////////////////////////

	std::string s; // полное имя файла, куда будет записан отсортированный массив
	sort(Data, 100, 2, 100,"");
	
}
