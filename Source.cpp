#include "sort.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;
// �����������
N::our_class::our_class(const string& str) {
	size_t size = str.size(); // ����� ���������� �� ���� ������
	int i_left = 0; 
	int num_space = 5; // ����� ��������
	int i_right;
	vector<int> v;
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ' && num_space > 0) {
			i_right = i;
			v.push_back(stoi(str.substr(i_left, i_right)));
			i_left = i + 1;
			num_space--;
		}
	}
	home = v[0];
	flat = v[1];
	s = v[3];
	fio = str.substr(i_left, size);
	all_string = str;
}


// ����������� �� ���������
N::our_class::our_class() {
	home = 0;
	flat = 0;
	s = 0;
	fio = "";
	all_string = "";
};


// �������, �������� ��� ��, ��� � �����������
void N::our_class::set_all(string& str) {
	size_t size = str.size(); // ����� ���������� �� ���� ������
	int i_left = 0;
	int num_space = 5; // ����� ��������
	int i_right;
	vector<string> v;
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ' && num_space > 0) {
			i_right = i;
			v.push_back(str.substr(i_left, i_right));
			i_left = i + 1;
			num_space--;
		}
	}
	home = stoi(v[0]);
	flat = stoi(v[1]);
	//room = v[2];
	s = stoi(v[3]);
	fio = str.substr(i_left, size);
	all_string = str;
}

// ���������� ������, ������� ���� �� �����
string N::our_class::showAll() {
	return all_string;
}
string N::our_class::showSorted() {
	return to_string(home) + " " + to_string(flat) + " " + to_string(s) + " " + fio;
}
 
//// ���������� ��������� ��������� ������
bool N::operator>(const our_class& left, const our_class& right) {
	if ((left.s < right.s) || (left.s == right.s && left.home > right.home) || (left.s == right.s && left.home == right.home && left.flat > right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio > right.fio)) {
		return true;

	}
	else
		return false;
};


// ���������� ��������� ��������� ������ ��� �����
bool N::operator>=(const our_class& left, const our_class& right) {
	if ((left.s < right.s) || (left.s == right.s && left.home > right.home) || (left.s == right.s && left.home == right.home && left.flat > right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio > right.fio) || (left.s == right.s &&
			left.home == right.home && left.flat == right.flat && left.fio == right.fio)) {
		return true;

	}
	else
		return false;
};


// ���������� ��������� ������
bool N::operator<(const our_class& left, const our_class& right) {
	if ((left.s > right.s) || (left.s == right.s && left.home < right.home) || (left.s == right.s && left.home == right.home && left.flat < right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio < right.fio)) {
		return true;

	}
	else
		return false;
};


//���������� ��������� ������ ��� �����
bool N::operator<=(const our_class& left, const our_class& right) {
	if ((left.s > right.s) || (left.s == right.s && left.home < right.home) || (left.s == right.s && left.home == right.home && left.flat < right.flat)
		|| (left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio < right.fio) ||
		(left.s == right.s && left.home == right.home && left.flat == right.flat && left.fio == right.fio)) {
		return true;

	}
	else
		return false;
};