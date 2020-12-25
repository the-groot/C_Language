#include <stdio.h>
#include <stdlib.h>

typedef struct BOOK {
	char writer[20];
	char name[30];
	int page;
}Book;


typedef struct COMPLEX {
	double real;
	double com;
}complex;

typedef struct PHONE {
	char name[20];
	char num[30];
}phone;

void print_book(Book* book) {					//1������	��������(����,����,��������)���
	for (int i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		fputs("����: ",stdout);
		printf("%s\n", book[i].writer);
		fputs("����: ",stdout);
		printf("%s\n", book[i].name);
		fputs("������ ��: ",stdout);
		printf("%d\n", book[i].page);
	}
}

void Read_book(Book* book) {				//1������ ��������(����,����,��������)�Է�
	int i = 0;
	printf("���� ���� �Է�\n");

	while (i < 3) {
		fputs("����: ", stdout);
		gets(book[i].writer);

		fputs("����: ", stdout);
		gets(book[i].name);

		fputs("������ ��: ", stdout);
		scanf("%d", &book[i].page);
		getchar();

		i++;
	}
	
}

Book* Read_book_dyn(Book* book,int n) {				//2������ ��������(����,����,��������)�Է� �����Ҵ�
	int i = 0;
	printf("���� ���� �Է�\n");

	while (i < n) {
		fputs("����: ", stdout);
		gets(book[i].writer);

		fputs("����: ", stdout);
		gets(book[i].name);

		fputs("������ ��: ", stdout);
		scanf("%d", &book[i].page);
		getchar();

		i++;
	}
	return book;
}

void print_book_dyn(Book* book, int n) {					//2������	��������(����,����,��������)��� �����Ҵ�
	for (int i = 0; i < n; i++) {
		printf("book %d\n", i + 1);
		fputs("����: ", stdout);
		printf("%s\n", book[i].writer);
		fputs("����: ", stdout);
		printf("%s\n", book[i].name);
		fputs("������ ��: ", stdout);
		printf("%d\n", book[i].page);
	}
}

void ADD(complex a, complex b) {
	complex result;
	result.real = a.real + b.real;
	result.com = a.com + b.com;
	printf("���� ���]�Ǽ�:%f, ���:%f\n", result.real,result.com);
	

}

void Multiple(complex a, complex b) {
	complex result;
	result.real = (a.real * b.real) - (a.com * b.com);
	result.com = (a.com * b.real) + (a.real * b.com);
	printf("���� ���]�Ǽ�:%f, ���:%f", result.real, result.com);
}

void main() {

	/*Book *book[3];
	Read_book(book);
	print_book(book);
	*/

	/*Book* book;
	int n;
	fputs("�迭 ũ��:",stdout);
	scanf("%d", &n);
	getchar();
	book = (Book*)malloc(sizeof(Book) * n);
	book = Read_book_dyn(book, n);
	print_book_dyn(book,n);
	free(book);*/


	/*	complex a, b;
		printf("���Ҽ� �Է�1[�Ǽ� ���]:");
		scanf("%lf %lf", &a.real, &a.com);
		printf("���Ҽ� �Է�2[�Ǽ� ���]:");
		scanf("%lf %lf", &b.real, &b.com);
		ADD(a, b);
		Multiple(a, b);*/


		/*int cnt_a=0, cnt_p=0;
		FILE* fp = fopen("wordcnt text.txt", "rt");
		char buf[200];
		if (fp == NULL) {
			printf("���� ���� ����\n");
			return -1;
		}

		while (fscanf(fp, "%s", buf) != EOF) {
			if ('A'==toupper(buf[0])) {
				cnt_a++;
			}
			else if (tolower(buf[0] == 'a')) {
				cnt_a++;
			}
			else if(toupper(buf[0])=='P'){
				cnt_p++;
			}
			else if (tolower(buf[0] == 'p')) {
				cnt_p++;
			}


		}
		printf("a:%d p:%d\n", cnt_a, cnt_p);
		fclose(fp);*/

		/*int flag=0;
		char str1[100], str2[100];

		FILE* fp1 = fopen("d1.txt", "rt");
		FILE* fp2 = fopen("d2.txt", "rt");

		if (fp1 == NULL || fp2 == NULL) {
			printf("���Ͽ���\n");
			return -1;
		}


		while (1) {
			if (feof(fp1) != 0 && feof(fp2) != 0)
				break;

			fgets(str1, sizeof(str1), fp1);
			fgets(str2, sizeof(str2), fp2);

			if (strcmp(str1, str2) == 0)
				flag = 1;
			else
				flag = 2;

		}
		if (flag == 1)
			printf("�����ϴ�");
		else
			printf("�ٸ��ϴ�");


		fclose(fp1);
		fclose(fp2);
		*/



	int n = 0;
	int cnt = 0,i=0,cnt2=0;
	phone a[10], b[10], c[10];
	FILE* fp = fopen("phone.txt", "w+");
	
	while (1) {
		if (feof != 0)
			break;
		fscanf(fp, "%s %s", a[i].name, a[i].num);
		i++;
	}
	
	while (1) {
		printf("*****MENU*****\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Search\n");
		printf("4.Print All\n");
		printf("5.Exit\n");
		printf("Choose the item:");
		scanf("%d", &n);

		if (n == 1) {
			printf("[INSERT]\n");
			fputs("Input Name:", stdout);
			scanf("%s", a[i].name);
			getchar();
			fputs("Input Tel Number:", stdout);
			scanf("%s", a[i].num);
			getchar();
			i++;
		}
		else if (n == 2) {
			printf("[Delete]\n");
			fputs("Input Name:", stdout);
			scanf("%s", b[cnt].name);
			
			for (int j = 0; j < 10; j++) {
				
				if (strcmp(b[cnt].name, a[j].name) == 0) {
					
					strcpy(a[j].name, "");
				}
				
			}
			cnt++;
		}

		if (n == 3) {
			printf("[Search]\n");
			fputs("Input Name:", stdout);
			scanf("%s", &c[cnt2].name);

			for (int k = 0; k < 10; k++) {
				if (strcmp(c[cnt2].name, a[k].name) == 0) {
					printf("%s�� ����:%s\n", a[k].name, a[k].num);
				}
			}
			cnt2++;
		}
		
		if (n == 4) {
			printf("[Print All Data]\n");
			for (int k = 0; k < i; k++) {
				printf("�̸�:[%s]\n", a[k].name);
				printf("��ȭ��ȣ:[%s]\n", a[k].num);
			}
		}


		else if (n == 5)
			break;
	}
	for (int k = 0; k < i; k++) {
		fwrite(a[k].name,sizeof(char) ,strlen(a[k].name), fp);
		fwrite(a[k].num, sizeof(char), strlen(a[k].num),fp);
	}
	

	fclose(fp);
}
