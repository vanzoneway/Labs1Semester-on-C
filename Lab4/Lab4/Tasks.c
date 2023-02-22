#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "goodscanf.h"
#define true 1;
#define false 0;
void doMatrixFloat(float*** table, int* n) {
	printf("Enter the size of matrix\n>");
	(*n) = goodScanfInt();
	srand(time(NULL));
	printf("1. - randomised Matrix\n0. - input by keyboard\n>");
	int variant = goodScanfInt();

	while (variant < 0 || variant>1) {
		printf("You wrote an incorrect variant. Try again!\n");
		variant = goodScanfInt();
	}
	(*table) = (int**)malloc(sizeof(float*) * (*n));
	for (int i = 0; i < (*n); i++) {
		(*table)[i] = (int*)malloc(sizeof(float) * (*n));
	}
	if (variant == 1) {
		for (int i = 0; i < (*n); i++) {
			for (int j = 0; j < (*n); j++) {
				(*table)[i][j] = -10 + rand() % 100;
			}
		}
	}
	else if (variant == 0) {
		for (int i = 0; i < (*n); i++) {
			for (int j = 0; j < (*n); j++) {
				printf("Enter [%d][%d] element of array:\n>", i, j);
				(*table)[i][j] = goodScanfFloat();
			}
		}
	}
}
void doMatrixInt(int*** table, int* n) {
	printf("Enter the size of matrix\n>");
	(*n) = goodScanfInt();
	srand(time(NULL));
	printf("1. - randomised Matrix\n0. - input by keyboard\n>");
	int variant = goodScanfInt();

	while (variant < 0 || variant>1) {
		printf("You wrote an incorrect variant. Try again!\n");
		variant = goodScanfInt();
	}
	(*table) = (int**)malloc(sizeof(int*) * (*n));
	for (int i = 0; i < (*n); i++) {
		(*table)[i] = (int*)malloc(sizeof(int) * (*n));
	}
	if (variant == 1) {
		for (int i = 0; i < (*n); i++) {
			for (int j = 0; j < (*n); j++) {
				(*table)[i][j] = -10 + rand() % 100;
			}
		}
	}
	else if (variant == 0) {
		for (int i = 0; i < (*n); i++) {
			for (int j = 0; j < (*n); j++) {
				printf("Enter [%d][%d] element of array:\n>", i, j);
				(*table)[i][j] = goodScanfInt();
			}
		}
	}
}
void printMatrixInt(int** table, int n) {
	for (int i = 0; i < n; i++) {            /*печатаем матрицу*/
		for (int j = 0; j < n; j++) {
			printf("(%d)  ", table[i][j]);
		}
		printf("\n\n");
	}
}
void printMatrixFloat(float** table, int n) {
	for (int i = 0; i < n; i++) {            /*печатаем матрицу*/
		for (int j = 0; j < n; j++) {
			printf("(%.1f)  ", table[i][j]);
		}
		printf("\n\n");
	}
}
void one_eight() {

		int n;
		int** table;
		doMatrixInt(&table,&n);
		printMatrixInt(table, n);
		for (int i = 0; i < n; i++) {
			int counter = 0;
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (table[i][j] < 0) {
					counter++;
				}
			}
			if (counter == 0) {
				for (int j = 0; j < n; j++) {
					sum += table[i][j];
				}
				printf("Sum of [%d] row, where is all elements more then 0: %d\n", i, sum);
			}
		}
		int x = n;
		int max_sumd = 0;

		for (int i = 1; i < n; i++) {
			int sumd1 = 0;
			int sumd2 = 0;
			for (int j = 0; j < (x-1); j++) {
				sumd1 += table[j + i][j];
				sumd2 += table[j][j + i];
				
			}
			x--;
			if (sumd1 > max_sumd) {
				max_sumd = sumd1;
			}
			else if (sumd2 > max_sumd) {
				max_sumd = sumd2;
				}
		}
		printf("Sum of maximum major diagonal is %d\n", max_sumd);

	}

void two_eight() {
	int n;
	float** table;
	doMatrixFloat(&table, &n);
	printMatrixFloat(table, n);
	
	for (int i = 0; i < n; i++) {
		int counter = 0;
		for (int j = 0;j < n; j++) {
			if (table[i][j] != 0) {
				counter++;
			}
		}
		if (counter == 0) {
			for (int j = 0; j < n; j++) {
				table[j][i] *= 2;
			}
			break;
		}
	}
	printf("RESULT\n--------\n\n");
	printMatrixFloat(table, n);
}
	
void three_eight() {
	int max_nech = 0;
	int** table;
	int n;
	doMatrixInt(&table, &n);
	printMatrixInt(table,n);
	for (int i = 0; i <= n / 2; i++) {
		for (int j = i; j <= n - 1 - i; j++) {
			if (table[j][i] % 2 != 0 && table[j][i] > max_nech) {
				max_nech = table[j][i];
			}
		}
	}
	printf("The largest odd element is %d \n", max_nech);

}
void add_task() {

	int n;
	int** table;

	doMatrixInt(&table, &n);
	printMatrixInt(table, n);
	for (int i = 0; i < n; i++) {
		*(table+i) = (int*)realloc(*(table + i), (n - i) * sizeof(int));

	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("(%d)  ", table[i][j]);
		}
		printf("\n\n");
	}

}




int main() {
	printf("What do you want to do ?\n");
	printf("1. First task\n");
	printf("2. Second task\n");
	printf("3. Third task\n");
	printf("4. Exit\n");
	int variant;
	do {
		variant = goodScanfInt();
		while (variant <= 0 || variant > 4) {
			printf("You wrote an incorrect variant. Try again! \n");
			variant = goodScanfInt();
		}
		switch (variant) {
		case 1:
			one_eight();
			printf("What do you want to do ?\n");
			printf("1. First task\n");
			printf("2. Second task\n");
			printf("3. Third task\n");
			printf("4. Exit\n");
			break;
		case 2:
			two_eight();
			printf("What do you want to do ?\n");
			printf("1. First task\n");
			printf("2. Second task\n");
			printf("3. Third task\n");
			printf("4. Exit\n");
			break;

		case 3:
			three_eight();
			printf("What do you want to do ?\n");
			printf("1. First task\n");
			printf("2. Second task\n");
			printf("3. Third task\n");
			printf("4. Exit\n");
			break;
		}


	} while (variant != 4);

}