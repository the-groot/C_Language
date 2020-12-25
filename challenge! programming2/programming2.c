#include <stdio.h>
#include <string.h>
#include <math.h>
void even_p(int[]); //짝수 판별 함수(1번문제)
void odd_p(int[]);	//홀수 판별 함수(1번문제)
void TentoTwo(int);	//10진수를 2진수로 출력하는 함수(2번문제)
void ReversePrint(int*);//배열 역순 출력하는 함수(2번문제)
void explanation_2(void);	//2번문제 설명문
void puddle(int*);	//홀수 앞에 짝수 뒤부터 저장하는 함수(3번문제)
void Palindrome(void);	//회문 판별 함수(4번문제)
void bubblesort(void);	//버블정렬 함수(내림차순)

void main() {
	/*int arr[10];
	printf("총 10개의 숫자 입력\n");
	for (int i = 0; i < 10; i++) {
		printf("입력: ");
		scanf("%d", &arr[i]);
	}

	odd_p(arr);
	even_p(arr);
	*/

	/*int n;
	printf("10진수 정수 입력: ");
	scanf("%d", &n);
	TentoTwo(n);/*

	/*int arr[10];
	int i = 0;
	printf("총 10개의 숫자 입력\n");
	while (i < 10) {
		printf("입력: ");
		scanf("%d", &arr[i]);
		i++;
	}
	puddle(arr);*/


	//Palindrome();
	//bubblesort();
}

void even_p(const int* arr) {
	int cnt = 0;
	printf("짝수 출력: ");
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 == 0) {
			cnt++;
		}
	}
		for (int i = 0; i < 10; i++) {
			if (arr[i] % 2 == 0) {
				printf("%d",arr[i]);

				if (cnt == 1)
					break;
					printf(", ");
					cnt--;
			}
			
		}
		printf("\n");
}

void odd_p(const int* arr) {
	int cnt = 0;
	printf("홀수 출력: ");
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 != 0) {
			cnt++;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 != 0) {
			printf("%d", arr[i]);

			if (cnt == 1)
				break;
			printf(", ");
			cnt--;
		}

	}
	printf("\n");
}


void explanation_2(void) {
	/* 정말 어려운 문제였다
	10진수 값을 2진수로 바꿔주기 위해
	배열을 통해 010101을 출력하려했다.
	그러려면 입력받은 값을 2의제곱으로 표현한 사잇값에서 작은값의 지수를 알아야했다

	무슨소리냐면
	12를 입력받으면      2^3    <=     12     <2^4
	5를 입력받으면		2^2     <=     5      <2^3
	여기서 12는 2^3의 3
	5는 2^2는 2
	작은 2의제곱의 지수를 알아야했다


	당연하게도 n(입력받은수)보다 큰 2의제곱에는 2진수로 표현했을때 1이 들어갈수 없으니까
	작은값의 2의제곱의 지수를 배열의 인덱스값에 맞춰 1을 넣어주려했다
	배열이 있으면 5는 2^2+2^1이니까 배열의 1번째와 2번째에 1을
	12는 2^3+2^2니까 3번째와 2번째에 1을 넣어주려했다

	 5는 101로 12는 1100으로 
	 근데 12는 실제로 0011로입력이된다 
	왜냐하면 3번째원소에 1이 들어가고(2^3) 2번쨰원소에 1이들어가면(2^2)        2^3+2^2=12니까
	0011이 저장돼있다
	
	그렇다면 출력할때 0011이나오니
	출력을 역순으로 출력해주면 되겠다고 생각했다

	그런데 여기서 또 문제가 생긴게 배열의 크기는 주어지지 않았기때문에int  arr[100]={0};로 초기화해주고
	역순으로 출력하면 0000....1100이렇게 나오지않겠는가?
	앞에있는 무의미한 00..들을 출력하지 않아야한다

	또 고민에 빠졌다가
	1이 나오는 인덱스의 최댓값 부터 역순으로 0까지 출력하면 되겠다고 생각했다


	출력은 문제없고 이제 1을넣어주는 알고리즘을 만들면되는데
	나는 처음에 생각한게
	12가 들어오면 3번째 인덱스에 1을넣고
	12-2^3=4
	2^2<=4<2^3	2번째 인덱스에 1을넣으면
	4-2^2=0 n은 0이되니까
	0011이되고 역순으로 출력하면 1100이 되겠구나싶었다

	알고리즘을 짰을때 n이 12->4로 갈때
	2의제곱값들을 그냥 2로 한 번만 나눠줬는데

	그렇게되니까 4도 100으로 나오고 5도 100으로나왔다
	2^2<=4<2^3 -->  2<=0<2^2            2^2<=5<2^3  -->    2<1<2^2
	2^2<=6<2^3 --> 2<=2<2^2 (6부터는 다시 됨, 9도 이상하게나옴)

	즉 n-2^(cnt-1)을 해주고나서
	2^(cnt-1)과 2^cnt를 2로나눠주는게아니라
	변한 n값에 따라 cnt를 다시 구해줘야하는것이었다

	그래서 다시 알고리즘짜서 다시 고쳤는데
	너무 꼬이고꼬이고꼬여서 힘들게풀었다
	거의 푸는데 1시간반걸림;;ㄹㅇ
	어려웠던문제였다

	
	*/
}

void TentoTwo(int n) {
	int a, b;							//a=2^(cnt-1), b=2^cnt
	int cnt = 0, remain = 1;			//cnt는 n을 2의제곱으로 표현했을때 근삿값(12의 cnt는 4  2^3<12<2^4, 6의 cnt는 3  2^2<6<2^3)의 지수, remain은 cnt를 찾기위한 변수
	int arr[100] = { 0 };	//2진수 표현하는 배열
	int n2 = n;				//n의 값을 변경시키지않기위해 복사된 n
	while (remain != 0) {			//n(n2)값에 근사한 2의제곱의 지수를 알아내기위한 반복문
		remain = n2 / 2;
		n2 = n2 / 2;
		cnt++;
	}
	a = pow(2, cnt - 1);		
	b = pow(2, cnt);
	
	

	while (a<=n && n<b) {				//2^(cnt-1) <=n < 2^cnt
		
		
		if (n == 0)
			break;						//n이 0이되면 탈출
		
		
		arr[cnt-1] = 1;					//a값의 지수인 배열의 인덱스에 1을넣고
		n = n-a;						//n=n-a를 해주고
		cnt = 0;						//cnt=0 초기화(n값이 변함에따라 cnt를 다시 구해주기위함) 
		n2 = n;							//n값이 변하지 않게 하기위해 n2에다 n의 값을 복사

		while(1) {
				
				remain = n2 / 2;		//바뀐 n(n2)값의 근사한 2의제곱의 지수를 구해줌
				n2 = n2 / 2;
				cnt++;
				
				if (remain == 0)
					break;			//remain==0이면 탈출
				

		}
		a = pow(2, cnt - 1);		//a와 b를 바꿔줌
		b = pow(2, cnt);
		

	}

	ReversePrint(arr);


}

void ReversePrint(int arr[]) {		//값이 저장된 배열은 8->0001이렇게 1이 역순으로 저장돼있으므로 역순으로 출력해줘야함 8->1000이렇게
	int i = 0;
	int idx = 0;
	while(i < 100) {
		
		
		if (arr[i] == 1) {		//배열을 돌면서 1이 가장 나중에 나오는 인덱스값을 idx에 저장
			idx = i;
		}
		
		i++;
	}
	

	for (int i = idx; i >= 0; i--) {		//idx부터 0까지 거꾸로 배열을 돌며 출력해줌
		printf("%d", arr[i]);
	}
}

void puddle(int* arr) {
	int a[10];
	int cnt1 = 0,cnt2=0;
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 != 0) {
			a[cnt1] = arr[i];
			cnt1++;
		}
		else {
			a[9 - cnt2] = arr[i];
			cnt2++;
		}
	}
	printf("배열 요소의 출력: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}

}


void Palindrome(void) {
	char str[100];
	int length;
	int value = 1;
	printf("문자열 입력: ");
	scanf("%s", str);
	length=strlen(str);
	
	
		for (int i = 0; i < length / 2; i++) {
			if (*(str + i) == *(str + length - 1 - i)) {
				value = 0;
			}
			else {
				value = 1;
					break;
			}
		}
	
	





	if (value == 0)
		printf("회문 입니다.");
	else
		printf("회문이 아닙니다.");
}

void bubblesort(void) {
	int n;
	int temp;
	printf("배열 크기 입력: ");
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("%d번째 원소 입력:", i);
		scanf("%3d", &arr[i]);
	}


	for (int j = n; j > 0; j--) {

		for (int i = 0; i < j-1; i++) {
			if (arr[i] < arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%2d", arr[i]);
	}







	free(arr);
}