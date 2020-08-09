#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct tail { //현재 꼬리 위치 확인 위해서
	int r; //행
	int c; //열
}tail;
typedef struct operation {//방향 전환
	int n;
	char op;
}operation;
int arr[102][102] = { 0 }; //모든 배열 0 - 사과 ,기본 n*n배열 바꿔준 후 0은 벽을 가리킴
tail T[10000];
operation o[100];
int main() {
	int n, k, angle = 90,r,c,l,x,s=0,oidx=0,tidx=0;
	int cnt = 0;
	char op;
	
	scanf("%d", &n); getchar();
	scanf("%d", &k); getchar();

	for (int i = 1; i <= n; i++) { //n x n 배열 기본 -2로 바꿈
		for (int j = 1; j <= n; j++) {
			arr[i][j] = -2;
		}
	}

	for (int i = 1; i <= k; i++) {//사과는 1로 변경
		scanf("%d %d", &r, &c); getchar();
		arr[r][c] = 1;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {// 방향전환 입력받기 (구조체에 차례대로 받음)
		scanf("%d %c", &x, &op); getchar();
		o[i].n = x; o[i].op = op;
	}
	//입력 끝
	r = 1; c = 1; T[s].r = 1;  T[s].c = 1; arr[r][c] = 2; //뱀이 있는 곳은 2로저장
	//r,c는 현재 머리 부분이 어디있는지 행과열 나타냄, T[s]는 매초마다 뱀의 움직임 저장
	while (1) {
		s++; //초 증가
		//각도별로 한칸 이동 후 조건 체크
		if (angle == 0) {
			r--;
			T[s].r = r; T[s].c = c; //뱀의 이동경로 저장
			if (arr[r][c] == 0 || arr[r][c] == 2) { break; } //벽 또는 몸통에 부딪히면 종료
			else if (arr[r][c] == 1) { //사과 먹으면
				arr[r][c] = 2;
			}
			else {//사과 아닐경우
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //꼬리 줄여줌
				//현재 꼬리위치 가리키는 T[tidx]이용, tidx를 하나 올려줘서 새로운 꼬리위치로 바꿈
			}
		}
		else if (angle == 90) {
			c++;
			T[s].r = r; T[s].c = c;
			if (arr[r][c] == 0 || arr[r][c] == 2) { break; }
			else if (arr[r][c] == 1) { //사과 먹으면
				arr[r][c] = 2;
			}
			else {//사과 아닐경우
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //꼬리 줄여줌
			}
		}
		else if (angle == 180) {
			r++;
			T[s].r = r; T[s].c = c;
			if ((arr[r][c] == 0)|| (arr[r][c] == 2)) { break; }
			else if (arr[r][c] == 1) { //사과 먹으면
				arr[r][c] = 2; 
			}
			else {//사과 아닐경우
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //꼬리 줄여줌
			}
		}
		else if (angle == 270) {
			c--;
			T[s].r = r; T[s].c = c;
			if (arr[r][c] == 0 || arr[r][c] == 2) { break; }
			else if (arr[r][c] == 1) { //사과 먹으면
				arr[r][c] = 2;
			}
			else {//사과 아닐경우
				arr[r][c] = 2; arr[T[tidx].r][T[tidx].c] = -2; tidx++; //꼬리 줄여줌
			}
		}

		if (s == o[oidx].n) {// 방향전환 해야하는 시간이 되면 방향전환해줌
			if (o[oidx].op == 'D') {// 90도증가
				angle += 90;
				if (angle == 360) { angle = 0; }
			}
			else {//90도 감소
				angle -= 90;  if (angle < 0) { angle += 360; }
			}
			oidx++;//다음 방향전환을 위해 oidx 하나 올려줌
		}
	}
	printf("%d", s); 
	return 0;
}