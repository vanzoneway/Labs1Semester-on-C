#include "goodscanf.h"
#include <stdio.h>
#include <stdint.h>
#include "menu.h"
#include <stdlib.h>
#define LEN 100
void doArray(float x[], int size) {
	printf("Press 1 if you wanna make a massiv from random elements\nPress 2 if you want to make massiv from needed elements\n");
	int w;
	do {
		w = goodScanfInt();
		if (w == 1) {
			for (int i = 0; i < size; i++) {
				x[i] = ( - 100 + rand() % (100 + 100 - 1) );

			}
		}
		if (w == 2) {
			for (int i = 0; i < size; i++) {
				printf("Input the %d element of array: \n", i);
				x[i] = goodScanfFloat();

			}
		}
		if (w != 2 && w != 1) {
			printf("You wrote an incorrect variant. Try again!\n>");
		}
	} while (w != 1 && w != 2);
}

float module(float x) {
	if (x >= 0) {
		return x;
	}
	else {
		return -x;
	}
}

void one_seven() {
	float massiv[LEN];
	printf("The size of array is ");
	int n;
	n = goodScanfInt();
	while (n < 0) {
		printf("The size of array can't be less then 0");
		n = goodScanfInt();
	}
	doArray(massiv,n);
	for (int i = 0; i < n; i++) {
		printf("(%.2f)  ", massiv[i]);
	}
	printf("\nWrite a number C: ");
	float C;
	C = goodScanfFloat();
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (massiv[i] > C) {
			counter++;
		}
	}
	printf("There is a %d elements more then C\n", counter);
	int counter2 = 0;
	for (int i = 0; i < n; i++) {
		if (module(massiv[i]) > module(massiv[counter2])) {
			counter2 = i;
		}
	}
	float result = 1;
	if (counter2 == n - 1) {
		printf("There is no elements after last symbol in massiv!\n");
	}else
	{
		while (counter2+1 < n) {
			result *= module(massiv[counter2+1]);
			counter2++;
		}
		printf(" Product of elements of array, which are situated after the module of the biggest element in massive is %f\n ", result);
	}
	
}

void two_seven() {
	float array[LEN];
	printf("Write a length of array: ");
	int n = goodScanfInt();
	while (n < 0) {
		printf("The size of array can't be less then 0");
		n = goodScanfInt();
	}
	doArray(array, n);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("(%.0f) ", array[i]);
	}
	printf("\n");
	printf("Write a k-element: ");
	int k = goodScanfInt();
	int counter = 0;
	for (int i = k-1; i < n + counter; i +=k+1) {
			int temp = array[n - 1 + counter];
			for (int j = n - 1 + counter; j > i; j--) {
				array[j] = array[j - 1];
			}
			array[n + counter] = temp;
			counter++;
			array[i + 1] = 0;
			
		}
	for (int i = 0; i < n+counter; i++) {
		printf("(%.0f) ", array[i]);
	}

	printf("\n");
}

void three_seven() {
	float array[LEN];
	printf("Write a length of array: ");
	int n = goodScanfInt();
	while (n < 0) {
		printf("The size of array can't be less then 0");
		n = goodScanfInt();
	}
	doArray(array, n);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("(%.0f) ", array[i]);
	}
	printf("\n");
	int counter = 0;
	int counter_max = 0;
	int result;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			if (array[i] == array[j]) {
				counter++;
			}			
		}
		if (counter > counter_max) {
			counter_max = counter;
			result = array[i];
		}
		counter = 0;

		
	}
	printf("Answer is %d\n", result);

}

int main() {
	print_menu();
	int variant = 0;
	do {
		 variant = goodScanfInt();
		switch (variant) {
		case 1:
			one_seven();
			print_menu();
			variant = goodScanfInt();
			break;
		case 2:
			two_seven();
			print_menu();
			variant = goodScanfInt();
			break;
		case 3:
			three_seven();
			print_menu();
			variant = goodScanfInt();
			break;
		default:
			printf("There is no variant such as that\n");
			break;

		}
		
	}while (variant != 4);
	return 0;
}