//문제 8 , 유클리도 호제법을 이용해서 N 개의 수들의 최대공약수를 구하는 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

//함수 원형
int Gcd(int a, int b);

int main()
{
	int input_num= 0 ;
	int num[SIZE];

	// N값 범위 입력 및 유효성 검사
	while (1) 
	{
		printf("N값 입력 : ");
		scanf("%d", &input_num);
		if (input_num < 1 || input_num >SIZE)
			printf("범위 초과\n");
		else break;
	}

	// 수 입력 및 유효성 검사
	for (int i = 0; i < input_num; i++)
	{
		printf("수 입력 : ");
		scanf("%d", &num[i]);
		if (num[i] == 0)
		{
			printf("0은 계산 불가\n");
			i--;
			continue;
		}
	}
	// 첫 번째 수를 시작값으로 하여 차례대로 최대공약수 계산
	int gdc = num[0]; 
	for (int i = 1; i < input_num; i++)
	{
		gdc = Gcd(gdc, num[i]);
	}
	//결과 출력
	printf("최대공약수 : %d", gdc);
	return 0;
}
//유클리드 호재법
int Gcd(int a,int b)
{
	while (a % b != 0 )
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return b; //최대공약수 반환
}
