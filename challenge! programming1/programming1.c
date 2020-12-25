#include <stdio.h>
int TenToSixteen(void);		//1�� ����
int Multiple(void);			//2�� ����
int compare(int, int);		//2�� ����
void print(int, int);		//2�� ����
int GCD(void);				//3�� ����
int DVD(void);				//4�� ����
int PN(void);				//5�� ����
int Time(void);				//6�� ����
int Formula(void);			//7�� ����
int recursive(int n);

void main() {
	int n;
	//TenToSixteen();
	//Multiple();
	//GCD();
	//DVD();
	//PN();
	//Time();
	//Formula();
	printf("���� �Է�: ");
	scanf("%d", &n);
	printf("2�� %d���� %d", n, recursive(n));
}

int TenToSixteen(void) {
	int n;
	printf("10���� ���� �Է�: ");
	scanf("%d", &n);
	printf("16���� ���·� ���: %x", n);


}

int Multiple(void) {
	int a, b;
	printf("--------------------------------------------------------------------------------------------\n");
	printf("�� ���α׷��� �� ���� ������ �Է¹޾� �� ������ ���� ������ �������� ����մϴ�.\n");
	printf("�� ���� ������ �Է��Ͻÿ�:");
	scanf("%d %d", &a, &b);
	compare(a, b);
}

int compare(int a, int b) {
	int big, small;
	if (a > b) {
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}
	print(big, small);
}

void print(int big, int small) {
	int i = 0;
	int j = 1;
	for (i = small; i < big + 1; i++) {
		for (j = 1; j < 10; j++) {
			printf("%d X %d = %d\n", i, j, i * j);
		}
	}
}


int GCD(void) {
	int a, b, small, gcd = 1;
	printf("�� ���� ���� �Է�: ");
	scanf("%d %d", &a, &b);

	small = (a < b) ? a : b;

	for (int i = 1; i < small + 1; i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;

		}
	}

	printf("�� ���� �ִ�����: %d", gcd);



}

int DVD() {
	int money = 3500;
	int bread = 500, shrimp = 700, cola = 400;
	printf("���� ����� �����ϰ� �ִ� �ݾ� : 3500\n");

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (cola * i + bread * j + shrimp * k == 3500) {
					printf("ũ���� %d��, ����� %d��, �� �� %d��\n", j, k, i);
				}
			}
		}
	}
	printf("��� �����Ͻðڽ��ϱ�?");
}

int PN() {
	int i = 2, cnt = 0, j = 1, cnt_1 = 0;;
	for (i; i < 100; i++) {
		cnt = 0;
		for (int j = 1; j < i + 1; j++) {

			if (i % j == 0) {
				cnt++;
			}

		}
		if (cnt == 2) {
			printf("%d ", i);
			cnt_1++;
		}
		if (cnt_1 == 10)
			break;
	}
}

int Time(void) {
	int second, s = 0, h = 0, m = 0;
	printf("��(second) �Է�: ");
	scanf("%d", &second);

	if (second / 3600 >= 1) {
		h = second / 3600;
		second = second % 3600;
		m = second / 60;
		s = second % 60;

	}

	else if (second / 60 >= 1)

	{
		h = 0;
		m = second / 60;
		s = second % 60;

	}

	else
	{
		h = 0;
		m = 0;
		s = second % 60;
	}



	printf("[h:%d, m:%d, s:%d]", h, m, s);
}


int Formula(void) {
	int n;
	int k = 0;
	printf("��� n �Է�: ");
	scanf("%d", &n);

	while (n / 2 >= 1) {
		k++;
		n = n / 2;

	}
	printf("������ �����ϴ� k�� �ִ��� %d", k);

}

int recursive(int n) {
	if (n < 1)
		return 1;
	else
		return 2 * recursive(n - 1);

}