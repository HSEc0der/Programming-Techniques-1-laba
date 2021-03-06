#include "Header.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

// конструктор
N::our_class::our_class(const std::string& str) {
	std::vector<std::string> v;
	int size = str.size();
	int left = 0;
	int right;
	int numspace = 5;
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ' && numspace > 0) {
			right = i;
			v.push_back(str.substr(left, right - left));
			left = i + 1;
			numspace--;
		}
	}
	home = std::stoi(v[0]);
	flat = std::stoi(v[1]);
	room = std::stoi(v[2]);
	s = std::stoi(v[3]);
	people = std::stoi(v[4]);
	fio = str.substr(left);
}

N::our_class::our_class() {
	home = 0;
	flat = 0;
	s = 0;
	fio = "";
	people = 0;
	room = 0;
}

//возвращает номер дома
int N::our_class::Home() {
	return home;
}
//возвращает номер квартиры
int N::our_class::Flat() {
	return flat;
}

//возвращает площадь
int N::our_class::S() {
	return s;
}

//возврашает ФИО
std::string N::our_class::Fio() {
	return fio;
}
//работает также, как конструктор
void N::our_class::set_all(const std::string& str) {
	std::vector<std::string> v;
	int size = str.size();
	int left = 0;
	int right;
	int numspace = 5;
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ' && numspace > 0) {
			right = i;
			v.push_back(str.substr(left, right - left));
			left = i + 1;
			numspace--;
		}
	}
	home = std::stoi(v[0]);
	flat = std::stoi(v[1]);
	room = std::stoi(v[2]);
	s = std::stoi(v[3]);
	people = std::stoi(v[4]);
	fio = str.substr(left);
}

std::string N::our_class::showSorted() {
	return std::to_string(s) + " " + std::to_string(home) + " " + std::to_string(flat) + " " + fio;
}

//// перегрузка оператора сравнения БОЛЬШЕ
bool N::operator>(const our_class& left, const our_class& right) {
	if ((left.s < right.s) || (left.s == right.s && left.home > right.home) || (left.s == right.s && left.home == right.home && left.flat > right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio > right.fio)) {
		return true;

	}
	else
		return false;
}

// перегрузка оператора сравнения БОЛЬШЕ ИЛИ РАВНО
bool N::operator>=(const our_class& left, const our_class& right) {
	if ((left.s < right.s) || (left.s == right.s && left.home > right.home) || (left.s == right.s && left.home == right.home && left.flat > right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio > right.fio) || (left.s == right.s &&
			left.home == right.home && left.flat == right.flat && left.fio == right.fio)) {
		return true;

	}
	else
		return false;
};


// перегрузка оператора МЕНЬШЕ
bool N::operator<(const our_class& left, const our_class& right) {
	if ((left.s > right.s) || (left.s == right.s && left.home < right.home) || (left.s == right.s && left.home == right.home && left.flat < right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio < right.fio)) {
		return true;

	}
	else
		return false;
};


//перегрузка оператора МЕНЬШЕ ИЛИ РАВНО
bool N::operator<=(const our_class& left, const our_class& right) {
	if ((left.s > right.s) || (left.s == right.s && left.home < right.home) || (left.s == right.s && left.home == right.home && left.flat < right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio < right.fio) ||
		(left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio == right.fio)) {
		return true;

	}
	else
		return false;
};
