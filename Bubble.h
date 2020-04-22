#ifndef Bubble
#define Bubble

#include "Header.h"

void bubble(N::our_class* mas, int length) {
	N::our_class temp;
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
#endif
