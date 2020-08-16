#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char str[500005]; tmp[500005]; //입력받을 문자열 ,출력할 문자열
int main() {
	int n, k,idx=1,check=0;

	scanf("%d%d", &n, &k);  
	scanf("%s", str);  
	
	tmp[0] = str[0];//첫번째 문자만 복사
	for (int i = 1; i < n; i++) { //나머지 숫자 
		while (k && idx && str[i] -'0'>tmp[idx-1]-'0') {
			//아직 지워야할 숫자가 있고, idx가 1이상이고, 입력받은 숫자가 출력할 문자열의 숫자보다 크면
			tmp[idx - 1] = str[i]; //출력할 문자열에서 이전숫자를 새로운 숫자로 바꿈
			k--; idx--; check++; //지워야할 숫자 하나감소, 인덱스 그대로해주기위해서 감소, 반복문 돌았는지 체크
		}
		if (check == 0) { tmp[idx] = str[i]; }// 조건이 하나라도 맞지 않았다면 숫자를 그냥 붙여줌
		else check = 0; //반복문을 돌았다면 다시 확인위해 초기화
		idx++;
	}
	
	while (k--) {// 전부 내림차순일 경우 ex)4321 - 조건을 한번도 충족시키지 않으므로 뒤에서부터 k개만큼 제거
		tmp[--idx] = 0; //널문자 삽입
	}
	for (int i = 0; i < idx; i++) { //출력
		printf("%c", tmp[i]);
	}
	
	

	return 0;
}