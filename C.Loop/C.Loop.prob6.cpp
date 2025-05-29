// 문제 6 , 다음 식을 만족하는 자연수 a,b,c 의 개수를 구하여라
//  i)	a + b + c = 2000
//	ii)	a ＞ b > c, a, b, c 는 모두 자연수

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int count = 0;   // 만족하는 (a,b,c) 조합의 개수  
	// a > b > c  조건, a = 1997, b = 2,c = 1 부터 시작 
	for (int a = 1997; a > 667; a--)   // a : 1997 ~ 668 까지 반복   (668,667,665) 
	{
		for (int b = 2; b < a; b++) // b : 2 ~ a 수 까지 반복
		{
			int c = 2000 - b - a;
			if (c > 0 && b > c)	 count++;   // 조건 해당시 count 1 증가 
		}
	}
	printf("위 조건을 만족하는 (a,b,c) 갯수 : %d", count); // 결과 출력
	return 0;
}