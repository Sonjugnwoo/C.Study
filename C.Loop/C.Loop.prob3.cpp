// 문제 3 , 1000이하의 3 or 5의 배수인 자연수 합 구하기
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num = 1000;
	int sum = 0;
	for (int i = 1; i <= num; i++)  //범위 지정
	{
		if (i % 3 == 0 || i % 5 == 0)  // 3 or 5 의 배수 판별
		{
			sum += i;   // 판별 해서 sum에 계속 더하기
		}
	}
	printf("%d", sum);

	return 0;
}