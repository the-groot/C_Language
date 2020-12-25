#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rolling_array(int* (*ptr)[4],int n,int);		//1번문제 오른쪽방향 90도 회전  (2차원 포인터배열, 배열의 (행=열)크기,반복횟수를 매개변수로받음)
int snail_array();	//2번문제 달팽이배열 함수
void explanation();	//달팽이배열 설명문
void random();	//3번 문제 0~99 난수출력 함수
void dice();	//4번 문제 주사위 출력 함수
void rsp();		//5번 문제 가위바위보 함수
void baseball();	//6번문제 야구게임 함수

void main() {
	/*int array[4][4] = {				//배열 초기화
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	
	

	rolling_array(array, sizeof(array) / sizeof(array[4]),4);			//함수 호출*/

	
	snail_array();
	//random();
	//dice();
	//rsp();
	//baseball();

}


int rolling_array(int* (*ptr)[4], int n, int cnt) {

	int arr[4][4];			//오른쪽방향으로 90도회전한 값을 받아줄 함수



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[j][3 - i] = ptr[i][j];		//반복문 한번 돌때마다 값이 오른쪽방향으로 90도회전함
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", arr[i][j]);				//한번 출력해줌
		}
		printf("\n");
	}
	printf("\n");

	cnt--;
	if (cnt == 0)
		return 1;			//cnt가0이 될때까지

	rolling_array(arr, sizeof(arr) / sizeof(arr[4]), cnt);		//재귀함수 호출 (arr를 그대로 놔두기위해서 재귀형식으로 코드를 짬)

}


int snail_array(void) {	//원래 매개변수에 이중배열이랑 n값을 main 함수에서 받으려고했는데 매개변수를 int* (*arr)[n]이렇게 배열의 크기에 n을 넣을수가없어
	//그냥 매개변수를 받지 않았다


	int k = 0, l = 0;	//k는행, l은열을 담당하는 변수
	int n,n2,n3;		//n은 배열의 크기(nxn),n2와 n3는 행과 열의 조건을 담당하는 변수
	int** arr;			//이차원배열 선언
	int cnt = 1;		//cnt는 1~n까지 증가하는 수이다.

	printf("달팽의 배열의 n값 입력: ");
	scanf("%d", &n);					//n값 받음
	arr = (int*)malloc(sizeof(int) * n);	//arr의 열을 n만큼 동적할당받음
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);		//arr의 행을 n만큼 동적할당 받음 --> nxn배열 완성
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = cnt;						//굳이 해줄 필요가 없긴한데 배열값 행->열 순서대로 초기화해줌
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", arr[i][j]);		//값 제대로 들어갔는지 출력해줌
		}
		printf("\n");
	}
	printf("\n");
	cnt = 1;		//cnt다시 1로 초기화
	n2 = n;
	n3 = n;			//n값을 n2,n3에 대입

	if (n == 2) {
		arr[1][1] = 3;
		arr[1][0] = 4;
	}



	while (n2 >= 3) {		//n2가 3이상일때까지
		//이렇게 한 이유는 밑에 n2식때문인데
		//반복문을 돌때마다 n2를 1씩줄여준다 그러다보면 배열의 크기가 몇이되든간에 3일때 끝이난다
		//그래서 while(n2 >3)이렇게 해도 사실 상관이없지만
		//n=3일때 반복문을 돌지않기때문에 n>=3이라고 작성했다

		


		for (l; l < n2 - 1; l++) {		//초기식을 초기화하지않는게 포인트였다 k와l이 증가되면 증가된대로
			//감소하면 감소한대로 다음 반복문으로 넘겨준다 그리고
			//조건식은 설명문에서 하겠슴
			//이게 가로 오른쪽
			arr[k][l] = cnt;
			cnt++;
		}

		for (k; k < n2 - 1; k++) {	//이게 세로 아래쪽
			arr[k][l] = cnt;
			cnt++;
		}

		for (l; l > n3 - n; l--) {	//이게 가로 왼쪽
			arr[k][l]=cnt;
			cnt++;
		}

		for (k; k > n3 - n; k--) {		//이게 세로 위쪽
			arr[k][l]=cnt;
			cnt++;
		}


		if (n%2!=0 && n2==3) {			//짝수일떄는 상관없지만 홀수일때  가운데값 3x3배열이면 arr[1][1]값이 제대로 안들어가서
										//홀수와 n2=3일때
			arr[n / 2][n / 2] = cnt;	//cnt값을 넣어주고 탈출시킨다
			break;
		}
		


		n2 =n2-1;					//n2는 감소시켜줌
		n3 = n3 + 1;				//n3는 증가시켜줌
		k++, l++;					//모퉁이 값을 입력해주기 위함


	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", arr[i][j]);			//출력해줌
		}
		printf("\n");
	}
	


	free(arr);	//동적할당 해제
	return 0;
}


void explanation() {
	/*
	달팽이 배열문제는 정말 어려웠다
	솔직히 원래같았으면 풀다가 막혀서 그냥 답 봤을거같은데
	끝까지 풀어낸 내 자신이 대견스럽다
	푸는데 알고리즘 생각하는데만 3시간정도 걸린거같다
	아 ㅅㅂ 쉽다고하는사람이 존경스럽네 난 ㄹㅇ 개어려웠음ㅋㅋㅋㅋㅋㅋ풀었으니다행이지

	우선 처음에 가장 고민이었던 것은
	감이 안잡힌다는것?
	알고리즘을 짜야하는데 규칙성이 보이지않았다
	오른쪽으로가다가 아래로가다가 왼쪽으로가다가 위쪽으로가는데
	그렇게 한바퀴를돌면 이미 입력한값으론 가면안된다
	다시 한바퀴를 돌때는 안쪽으로 돌아야한다
	이걸 몇 번 반복하는지는 n의값에따라 달랐고
	돌때마다 값이 줄어드는 것도 n의값에 따라 달랐다

	그래서 처음엔 행과 열을 분리해서 봤다
	arr[x][y]가 있으면 행([y]),열([x])를 따로 봤다
	4x4배열이라 치면 행의 움직임은 /0->1->2->3/->3->3->     /3->2->1->0/->0->0->1->2->2->1
									여기까지n  n-2만큼 반복		다시n		여긴??
	일단 처음에 알아낸게 이 규칙이었다

	근데 이렇게 하니까 도저히 모퉁이를 어떻게 풀어내야할지 감이안왔다
	그래 가로로 n만큼증가했다 n에서 몇번 n-2만큼반복하고 n만큼감소하고 
	그런데 이걸 반복문으로 짜려고하니까 아무리 생각해도 답이안나왔다
	그래서 몇시간 고민하다 내일풀자하고 다시 봤는데

	어제 보이지않았던게 보였다
	아마 다르게 보게 된건 작자가 부연 설명으로 '가로방향을 채우는 반복문과 세로방향으로 채우는 반복문을 독립적으로 구성하는것이 포인트'라고했다
	그걸 보고나서 행과 열을 독립적으로 봐보기 시작했다

	그랬더니 새로운게 보였는데 진행을 모퉁이까지하지않고 모퉁이전까지 하고 (오른쪽,아래,왼쪽,위) 계속 반복하니까
	진행 개수가 같다는걸 알게됐다
	5x5배열이라면 첫 사이클(right,down,left,up)이 4번만큼 가고
	두번째 사이클에는 2번만큼 가고 마지막 arr[2][2] 한배열에 1번만큼 간다
	4x4+2x4+1x1=25

	이것은 놀라운 발견이었다
	모퉁이를 포함시키지 않고 right,down,left,up을 진행시키면 4->2->1로 알아서 반복시킬각이보이는것이다

	그래서 right,down,left,up을 배열의 인덱스로 표현해서 규칙성을 찾아내보았다
	4x4배열

	[0][0]->[0][3]  (right)
	[0][4]->[3][4]	(down)
	[4][4]->[4][1]	(left)
	[4][0]->[1][0]	(up)

	[1][1]->[1][2]	(right)
	.
	.
	.

	뭔가 보이지 않는가?	right의 가로0->3증가하고
	down으로 갈때 4가되서 가로 고정 세로는 0->3
	left로갈때 4가되서 가로는 4->1
	up으로갈때 가로 0되고 세로는 4->1

	아무튼 반복문돌려서 0~3까지
	대충 뭐 어떻게 돌리면 답이나오겠거니 싶었다

	그런데 반복문을 짜면 i나 j가 값이 변한채로 진행돼야한다는것을 알았고
	초기식에 i나j를 초기화 하지않는게 관건이라 느꼈다

	그리고 첫사이클에서는 0~3만큼증가하고
	두사이클에서는 1~2만큼 증가하는걸로 보아
	right~up까지 한 번 반복하고 증가 범위도 줄어야한다는걸 알았다
	그걸알아내는게 조금 힘들었는데
	right과 up은 한 번 반복문을 돌때 n값이 작아진다치면
	i>n-3 이렇게하면 문제가 없었다

	그런데 left와 up을 아무리 생각해도 n의 조건식으로 하면
	답이안나온다
	그래서 n은 놔두고 n2와 n3를만들어서
	n2는 right,down 조건식
	n3는 left,up 조건식으로 하자
	해서 조건식을 만들었다
	만드는과정은 생략한다 
	아마 n2는 줄이고
	n3는 높여서 n3-3를 조건식으로했던거같다

	그렇게 하니까 잘나오긴한다
	짝수일때는
	그런데 홀수 일때 마지막 1개의 값이
	안들어가는거다

	그래서 홀수일때 조건식을 하나 더 써주고
	결국 nxn의 홀수의 배열에서
	가운데값은 5면 [2][2] 3이면 [1][1]
	아 나누기 2하면되겠구나

	그래서 if(n%2!=0)
	n이 홀수이면
	arr[n/2][n/2]에다 마지막 값을 넣으라는 식을넣어서
	완성했다



	코딩이 안될때 다음날해서 되는경우도있구나 싶었다






















	*/





}


void random(void) {
	printf("난수의 범위: 0부터 %d까지", RAND_MAX);
	for (int i = 0; i < 5; i++) {
		printf("난수 출력: %d\n", rand() % 100);
	}
}


void dice() {

	srand((int)time(NULL));

	
		printf("1주사위의 값:%d\n", rand() % 6 + 1);
		printf("2주사위의 값:%d\n", rand() % 6 + 1);
	




}

void rsp() {
	//질때까지
	//게임 결과 출력
	int win=0, lose=0, draw=0;
	int choice=0,c_choice=0;
	srand((int)time(NULL));

	while (lose < 1) {
		printf("바위는 1, 가위는 2, 보는 3:");
		scanf("%d", &choice);
		
		c_choice = (rand() % 3) + 1;
		


		if (choice == c_choice) {
			if (choice == 1)
			{
				printf("당신은 바위 선택, 컴퓨터는 바위 선택, 비겼습니다!\n");
			}
			else if (choice == 2) {
				printf("당신은 가위 선택, 컴퓨터는 가위 선택, 비겼습니다!\n");
			}

			else {
				printf("당신은 보 선택, 컴퓨터는 보 선택, 비겼습니다!\n");
			}

			draw++;
		}

		else if (choice == 1) {
			printf("당신은 바위 선택,");
			if (c_choice == 2) {
				win++;
				printf("컴퓨터는 가위 선택, 당신이 이겼습니다!\n");
			}
			else {
				lose++;
				printf("컴퓨터는 보 선택, 당신이 졌습니다!\n");
			}

		}
		else if (choice == 2) {
			printf("당신은 가위 선택,");
			if (c_choice == 1) {
				lose++;
				printf("컴퓨터는 바위 선택, 당신이 졌습니다!\n");
			}
			else {
				win++;
				printf("컴퓨터는 보 선택, 당신이 이겼습니다!\n");
			}
		}

		else {
			printf("당신은 보 선택,");
			if (c_choice == 1) {
				win++;
				printf("컴퓨터는 바위 선택, 당신이 이겼습니다!\n");
			}
			else {
				lose++;
				printf("컴퓨터는 가위 선택, 당신이 졌습니다!\n");
			}
		}
	}
	printf("%d승, %d무",win, draw);

}


void baseball() {
	int ca = 0, cb = 0, cc = 0;


	srand((int)time(NULL));


	while (ca == cb || ca == cc || cb == cc) {		//중복되는 수를 없애기 하나라도 같은 수가 있으면 난수 다시 입력

		ca = rand() % 9 + 1;
		cb = rand() % 9 + 1;
		cc = rand() % 9 + 1;

		printf("%d %d %d\n", ca, cb, cc);

	}
	

	int a, b, c;
	int cnt = 0;
	int strike = 0, ball = 0;
	
	while (strike<3) {				//strike가 3이나올때까지
		ball = 0, strike = 0;		//ball과 strike는 반복문 돌때마다 초기화

		printf("3개의 숫자 입력: ");
		scanf("%d %d %d", &a, &b, &c);

		if (a == ca) {				//위치와 값이 같으면 strike추가
			strike++;
		}

		else if (a == cb) {			//위치는 다른데 값이 같으면 ball추가
			ball++;
		}

		 else if (a == cc) {
			ball++;
		}

		if (b == ca) {
			ball++;
		}
		else if (b == cb) {
			strike++;
		}

		 else if (b == cc) {
			ball++;
		}

		if (c == ca) {
			ball++;
		}
		 else if (c == cb) {
			ball++;
		}
		 else if (c == cc) {
			strike++;
		}
					
		


		cnt++;
		printf("%d번째 도전 결과: %dstrike, %dball\n", cnt, strike, ball);
	}
}













