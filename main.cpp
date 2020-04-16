#include <iostream>
#include "sort.h"
#include "fstream"
#include <vector>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <ctime>



using namespace std;
using namespace N;


// БЫСТРАЯ сортировка
void quicksort(our_class* mas,int first, int last) {
	our_class mid, count;
	int f = first;
	int l = last;
	mid = mas[(f + l) / 2];
	do {
		while (mas[f] < mid) {
			f++;
		}
		while (mas[l] > mid) {
			l--;
		}
		if (f <= l) {
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) {
		quicksort(mas, first, l);
	}
	if (f < last) {
		quicksort(mas, f, last);
	}
}

// сортировка ПУЗЫРЬКОМ
void bubble(our_class* mas, int length) {
	our_class temp;
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				// меняем элементы местами
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
}

// сортировка ВСТАВКА
void vstavka(our_class* mas, int length) {
	our_class temp;
	int item;
	for (int counter = 1;counter < length;counter++) {
		temp = mas[counter];
		item = counter - 1;
		while (item >= 0 && mas[item] > temp) {
			mas[item + 1] = mas[item];
			mas[item] = temp;
			item--;
		}
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
// считывание файла в vector Data

	vector<string> Data;
	ifstream In("D:\\19вариант\\DataCpp.txt");
	string str;
	string s;
	while (!In.eof())
	{
		getline(In, str);
		Data.push_back(str);
	}
	
	int n = Data.size(); // количество строк в файле
	cout << n << "\n";
	int sep[9] = { 100, 500,1000,10000, 20000, 40000, 50000, 70000, n};
	//int sep[1] = { 20000 };
	int length;


	for (int k = 0; k < 9; k++) {
		length = sep[k];
		N::our_class* cls = new N::our_class[length]; // динамический массив
		for (int i = 0; i < length; i++) {
			cls[i].set_all(Data[i]);

		}

		float start_time = clock(); // начало отсчета времени

		bubble(cls, length);
		vstavka(cls, length);
		quicksort(cls, 0, length - 1);

		float end_time = clock(); // конец отсчета времени
		
		delete[] cls;
		cout << "Для n = " << sep[k] << " время выполнения: " << (end_time - start_time) / CLOCKS_PER_SEC << "\n";
	}

}
