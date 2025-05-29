//문제 5 , 10 개의 원소들 중 최대값 구하는 함수를 이용하여, 10 개의 원소를 입력 받고 그 원소를 큰 순으로 출력하는 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

//함수원형
void SelectionSort(int* num);
int MaxIndex(int* num,int start);

int main()
{
	int num[SIZE];   // 수 입력 받을 배열 
	printf("10개의 수 입력\n");
	for (int i = 0; i < SIZE; i++)  // 수 10개 입력 
	{		
		printf("%d번째 수 : ", i + 1);  //수 번호 체크
		scanf("%d",&num[i]);	}
	SelectionSort(num);  // 함수 호출
	return 0;
}
// Maxidx 찾는 함수 
int MaxIndex(int* num,int start)
{
	int max_index = start;  // 
	for (int i = start+1; i < SIZE; i++)
	{
		if (num[max_index] < num[i]) max_index = i;
	}
	return max_index; // Maxidx 반환
}
//선택 정렬 
void SelectionSort(int* num)
{
	for (int i = 0; i < SIZE; i++)
	{
		int max_idx = MaxIndex(num,i);

		int temp = num[i];
		num[i] = num[max_idx];
		num[max_idx] = temp;
	}
	//결과 출력 
	printf("내림차순 결과 : ");
	for (int i = 0; i < SIZE; i++) 
		printf("%d\n", num[i]);
}