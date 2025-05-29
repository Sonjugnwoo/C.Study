//문제 1 , 입력값을 받아 입력값의 크기를 가진 삼각형을 출력
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int temp = 0;
	printf("삼각형 크기 입력 : ");
	scanf("%d", &temp);

	for (int i = 1; i <= temp; i++)  // 삼각형 크기  ( 줄 )
	{
		for (int j = 0; j < temp - i; j++)  // 공백 계산
		{
			printf(" ");
		}
		for (int k = 0; k < (2 * i) - 1; k++) // 삼각형 그리기 
		{
			printf("@");
		}
		printf("\n");
	}
	return 0;
}