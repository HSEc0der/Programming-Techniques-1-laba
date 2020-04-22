#ifndef Vstavka
#define Vstavka

#include "Header.h"

void vstavka(N::our_class* mas, int length) {
	N::our_class temp;
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

#endif
