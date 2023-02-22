#include <stdio.h>
#include <locale.h>
float sqrtNum(float num, float tochn) {
	float x0,d,x1;
	x0 = num;
	do {
		x1 = 0.5 * (x0 + num / x0);
		d = x0 - x1;
		x0 = x1;

		if (d < 2 * tochn || d < 2 * tochn * tochn) {
			return x1;
		}
		} while (d > 2 * tochn || d > 2 * tochn * tochn);

}
void one_seven() {
	const float pi = 3.14f;
	printf("������� ������ ����������:\t");
	float r;
	scanf("%f", &r);
	printf("����� ���������� �����: %.2f\n������� ����� �����: %.2f\n\n\n", 2 * pi * r, pi * r * r);
}
void two_seven() {
	printf("������� ����� a,b,c ����� ������\n");
	float a, b, c, d;
	scanf_s("%f %f %f", &a, &b, &c);
	if (a > b && a>c) {
		d = a;
	}
	else if (b > a && b > c) {
		d = b;
	}
	else if (c > b && c > a) {
		d = c;
	}
	printf("���������� ����� d ����� %f\n\n\n", d);

}
void three_seven() {
	float x1, y1, x2, y2, x3, y3;
	printf("������� �������� ��������� x1 � y1 ����� A ����� ������\n");
	scanf("%f %f", &x1, &y1);
	printf("������� �������� ��������� x2 � y2 ����� B ����� ������\n");
	scanf("%f %f", &x2, &y2);
	printf("������� �������� ��������� x3 � y3 ����� C ����� ������\n");
	scanf("%f %f", &x3, &y3);
	float r1, r2, r3;
	r1 = x1 * x1 + y1 * y1;
	r1 = sqrtNum(r1, 0.1);
	r2 = x2 * x2 + y2 * y2;
	r2 = sqrtNum(r2, 0.1);
	r3 = x3 * x3 + y3 * y3;
	r3 = sqrtNum(r3, 0.1);
	int counter = 0;
	if (r1 == r2 && r2 == r3 && r1 == r3) {
		printf("����� A,B � C ��������� �� ���������� ���������� �� ������ ���������\n");
		counter++;
	}
	if (r1 >= r2 && r1 >= r3 && counter == 0) {
		counter++;
		printf("����� A ����� ���������\n");
		switch (r1 == r2 || r1 == r3) {
		case 1: r1 == r2 ? printf("��� ��� A=B\n") : printf("��� ���� A=C\n");
		case 0: break;
		}
	}
	if (r2 >= r3 && r2 >= r1 && counter == 0) {
		counter++;
		printf("����� B ����� ���������\n");
		switch (r2 == r3 || r2 == r1) {
		case 1: r2 == r3 ? printf("��� ��� B=C\n") : printf("��� ���� B=A\n");
		case 0: break;
		}
	}
	if (r3 >= r1 && r3 >= r2 && counter == 0) {
		printf("����� C ����� ���������\n");
		switch (r2 == r3 || r3 == r1) {
		case 1: r3 == r1 ? printf("��� ��� C=A\n") : printf("��� ���� B=C\n");
		case 0: break;
		}
	}
}
void four_seven() {
	int informatika[] = { 2,1}; 
	int kultorologia[] = { 3,4 };
	int mathematika[]= { 4,3 };
	int inyaz[] = { 4,1,2,3 };
	printf("������� ����� ��������:");
	int x;
	scanf("%d", &x);
	if (x > 4 || x<=0) {
		printf("� ��� ��� ��� ���������� �� ������ ����� ��������");
	}
	for (int i = 0; i < 2; i++) {
		if (x == informatika[i]) {
			printf("�����������\n");
		}
		if (x == kultorologia[i]) {
			printf("�������������\n");
		}
		if (x == mathematika[i]) {
			printf("����������\n");
		}
	}
	for (int i = 0; i < 4; i++) {
		if (x == inyaz[i]) {
			printf("����������� ����\n");
		}
	}

}


int main() {
	char* locale = setlocale(LC_ALL, "");
	four_seven();
	return 0;
}