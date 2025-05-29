//문제 3 ,  N 값을 입력 받아서 1 부터 N 까지의 소수의 개수를 출력하는 함수 작성
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
int PrimeCount(int num);

int main()
{
	int input_num;
	printf("N값 입력 : ");
	scanf("%d", &input_num);

	printf("1 ~ %d 까지 소수 개수 : %d",input_num, PrimeCount(input_num));  //결과 출력
	return 0;
}
// 소수 개수 확인
int PrimeCount(int num)
{
	int count = 0;  // 소수 개수
	for (int i = 2; i <=num; i++)
	{
		int prime_check = 0; 
		for (int j = 2; j*j <=i; j++)
		{
			if (i % j == 0)  // 나누어 떨어지면 소수가 아님 
			{
				prime_check = 1;
				break;
			}
		}
		if (prime_check== 0)	count++;
		
	}
	return count;
}