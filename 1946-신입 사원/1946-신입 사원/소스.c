#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct grade {
	int s; //서류 등수
	int m; //면접 등수
}grade;
grade g[100001];
int main() {
	int t, n,tmp=0,cnt=1,max=0;
	
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) { //입력 받음
			scanf("%d %d", &g[j].s, &g[j].m);
		}

		for (int j = 0; j < n; j++) { //정렬 (서류 등수 순)
			for (int q = j; q < n; q++) {
				if (g[j].s > g[q].s) {
					tmp = g[j].s;
					g[j].s = g[q].s;
					g[q].s = tmp;

					tmp = g[j].m;
					g[j].m = g[q].m;
					g[q].m = tmp;
				}
			}
		} //정렬 끝
		//서류 등수대로 면접 등수를 살펴보며 앞순위의 제일 높은 면접 등수를 계속 저장해주고
		//그것보다 면접등수가 낮으면 서류,면접 순위 둘다 낮은 것이므로 패스
		//높을 경우는 조건 충족하므로 cnt 올려주고, 제일 높은 면접 등수 새로 갱신해줌
		max = g[0].m; //max-면접 등수 최대 순위

		for (int j = 1; j < n; j++) {//서류 등수 2등부터 비교
			if (max > g[j].m) { max = g[j].m; cnt++; }
		}

		printf("%d\n", cnt);
		cnt = 1; //서류 등수 1등은 무조건 포함되므로 1부터 시작
	}

	return 0;
}