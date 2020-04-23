#ifndef SORT
#define SORT

#include <vector>
#include <string>
#include "Header.h"
#include "Bubble.h"
#include "Vstavka.h"
#include "QuickSort.h"
#include <iostream>
#include <fstream>
#include <ctime>



void sort(std::vector<std::string>& mas, int length, int which_sort, int show, std::string fileName) {
	// which_sort == 0 -> cортировка пузырьком
	//which_sort == 1 -> сортировка вставками
	//which_sort == 2 -> быстрая сортировка
	// mas - источник данных
	//show - cколько даннных нужно вывести
	//fileName - имя файла, куду нужно записать отсортированный массив, если пустая строка - то ничего не нужно делать.
	double time;
	float start;
	float end;
	N::our_class* cls = new N::our_class[length]; // динамический массив
	for (int i = 0; i < length; i++) {
		cls[i].set_all(mas[i]);
	}
	switch (which_sort) {
	case 0:
	{	start = clock();
		bubble(cls, length);
		end = clock();
		break;
	}
	case 1:
	{	start = clock();
		vstavka(cls, length);
		end = clock();
		break;
	}
	case 2:
	{	start = clock();
		quicksort(cls, length);
		end = clock();
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
	std::cout << "Время работы программы: " << (end - start) / CLOCKS_PER_SEC;
	delete[] cls;

}

#endif
