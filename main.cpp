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

void sort(std::vector<std::string> &mas, int length, int which_sort, int show, std::string fileName) {
	// which_sort == 0 -> cортировка пузырьком
	//which_sort == 1 -> сортировка вставками
	//which_sort == 2 -> быстрая сортировка
	// mas - источник данных
	//show - cколько даннных нужно вывести
	//fileName - имя файла, куду нужно записать отсортированный массив, если пустая строка - то ничего не нужно делать.
	N::our_class* cls = new N::our_class[length]; // динамический массив
	for (int i = 0; i < length; i++) {
		cls[i].set_all(mas[i]);	
	}
	switch (which_sort) {
		case 0:
			{
			bubble(cls, length);
			break;
			}
		case 1:
		{
			vstavka(cls, length);
			break;
		}
		case 2:
		{
			quicksort(cls, length);
			break;
		}
		default:
			std::cout << "Вы ввели не то число\n";
	}
	for (int i = 0; i < show; i++) {
		std::cout << cls[i].showSorted() << "\n";
	}
	// если передана непустая строка, то нужно записывать данные в файл
	if (!(fileName == "")) {
		std::fstream file;
		file.open(fileName, std::fstream::in | std::fstream::out);
		
		// проверяем, корректное ли имя файла
		if (file.is_open()) {
			for (int j = 0; j < length; j++) {
				file << cls[j].showSorted() << "\n";
			}
		}
		else {
			// запись в файл
			std::cout << "Вы ввели неправильное имя файла\n";
			return;
		}

	}
	else {
		std::cout << "Ничего записывать в файл не надо.\n";
	}
	delete[] cls;

}

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
