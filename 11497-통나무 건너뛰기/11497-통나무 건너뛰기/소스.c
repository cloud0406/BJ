#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))


int partition(int* list, int left, int right)
{
    int pivot = list[left], tmp, low = left, high = right + 1;

    do {
        do
            low++;
        while (low <= right && list[low] < pivot);

        do
            high--;
        while (high >= left && list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], tmp);
    } while (low < high);

    SWAP(list[left], list[high], tmp);
    return high;
}
void quick_sort(int* list, int left, int right)
{
    if (left < right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}//오름차순 퀵정렬

//제일 큰수가 가운데배치, 그 다음 큰수를 오른쪽, 왼쪽으로 하나씩 배치해나감
//결국 작은순서대로 0,n,1,n-1,2,n-2...인덱스에 배치됨
int arr[10001],tmp[10001];
int main() {
	int t, n,cnt=0,idx=0,max=0,fi,ri;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {//테스트 케이스만큼 반복
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {//배열에 입력받은 순서대로 저장
			scanf("%d", &arr[j]);
		}
        quick_sort(arr, 0, n - 1); //배열 오름차순 정렬
        
        fi = 0; ri = n - 1;//fi-첫번째 인덱스 ri-마지막 인덱스
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) { tmp[fi] = arr[j]; fi++; } //짝수 인덱스는 앞에서부터
            else { tmp[ri] = arr[j]; ri--; } //홀수 인덱스는 뒤에서부터 배치
        }
    
        for (int j = 0; j < n-1; j++) {//앞에서 부터 순서대로 차이값비교
            if (tmp[j] > tmp[j + 1]) {
                if (tmp[j] - tmp[j + 1] > max) max = tmp[j] - tmp[j + 1];
            }
            else { if (tmp[j + 1] - tmp[j] > max) max = tmp[j + 1] - tmp[j]; }
        }

        //마지막에 처음과 마지막 인덱스 차이비교
        if (tmp[0] > tmp[n - 1]) { if (tmp[0] - tmp[n - 1] > max) max = tmp[0] - tmp[n - 1]; }
        else { if (tmp[n - 1] - tmp[0] > max) max = tmp[n - 1] - tmp[0]; }

        printf("%d\n", max);
        max = 0;
	}
    return 0;
}