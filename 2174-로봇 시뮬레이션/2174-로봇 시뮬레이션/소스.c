#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct a {
	int n; //가로
	int m; //세로
	int angle; //각도
}angle;
int main() {
	int arr[101][101] = { 0 };  //모든 배열에 0(없다는 표시), 로봇이 들어오면 숫자 바꿈
	int A, B,N,M,n,m,num,r,check=0; 
	char op,op2;
	angle a[101]; 

	scanf("%d %d", &A, &B); getchar(); //가로 세로 받고
	scanf("%d %d", &N, &M); getchar(); 

	for (int i = 0; i < N; i++) {
		scanf("%d %d %c", &n, &m, &op); getchar();
		arr[n][m] = i+1; //배열에 좌표에 맞게 몇번째 로봇인지 저장
		a[i].n = n; a[i].m = m; //구조체에도 좌표 저장
		if (op == 'N') { a[i].angle = 0; } //각각 각도 저장
		else if (op == 'E') { a[i].angle = 90; }
		else if (op == 'S') { a[i].angle = 180; }
		else if (op == 'W') { a[i].angle = 270; }
    }
	for (int i = 0; i < M; i++) {
		scanf("%d %c %d", &num, &op2, &r); getchar();
		for (int j = 0; j < r; j++) {
			if (op2 == 'L') { //왼쪽 회전
				a[num-1].angle -= 90; 
				if (a[num - 1].angle < 0) { a[num - 1].angle += 360; }
			}
			else if (op2 == 'R') { //오른쪽 회전
				a[num-1].angle += 90; 
				if (a[num - 1].angle == 360) { a[num - 1].angle = 0; }
			}
			else if (op2 == 'F') {//전진
				if(a[num-1].angle==0){//N으로 전진
					arr[a[num - 1].n][a[num - 1].m] = 0;//옮겨줄 것이므로 현재 로봇위치 비워둠
					a[num - 1].m++; //한칸 이동
					
					if(a[num-1].m>B){ //밖으로 나가면 
						check++; //체크 올려주고
						printf("Robot %d crashes into the wall",num); //충돌메시지
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) { //로봇이랑 충돌
						check++;//체크 ㅇㄹ려주고
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]); //충돌메시지
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num; //현재 로봇위치 배열에 표기
				}
				if (a[num - 1].angle == 90) { //E로 전진
					
					arr[a[num - 1].n][a[num - 1].m] = 0;
					a[num - 1].n++;
					
					if (a[num - 1].n > A) {
						check++;
						printf("Robot %d crashes into the wall",num);
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) {
						check++;
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]);
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num;
				}
				if (a[num - 1].angle == 180) { //S로 전진
					arr[a[num - 1].n][a[num - 1].m] = 0;
					a[num - 1].m--;
					if (a[num - 1].m < 1) {
						check++;
						printf("Robot %d crashes into the wall",num);
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) {
						check++;
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]);
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num;
				}
				if (a[num - 1].angle == 270) {//W로 전진
					arr[a[num - 1].n][a[num - 1].m] = 0;
					a[num - 1].n--;
					if (a[num - 1].n < 1) {
						check++;
						printf("Robot %d crashes into the wall",num);
						break;
					}
					if (arr[a[num - 1].n][a[num - 1].m] != 0) {
						check++;
						printf("Robot %d crashes into robot %d", num, arr[a[num - 1].n][a[num - 1].m]);
						break;
					}
					arr[a[num - 1].n][a[num - 1].m] = num;
				}
			}
		}
		if (check == 0) { continue; } //체크 그대로면 계속 반복문 돌리고
		else { break; } //충돌할 경우는 끝냄
	}
	if (check == 0) { printf("OK\n"); } //이상 없으면 ok출력
	return 0;
}