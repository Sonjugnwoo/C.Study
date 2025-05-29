// 문제 4 , 1000000 이하의 피보나치 수열  의 짝수 항들의 합을 구한다   ( 1 1 2 3 5 8 13 21 ..)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int  num = 1000000;
	int fb_1 = 1;  // (n-1) 항
	int fb_2 = 1;  //  (n-2) 항
	int fb = 0;    // 현재 n값
	int sum = 0;
	printf("%d-%d", fb_1, fb_2);
	// 피보나치 수열  n = (n-1) + (n-2)
	while (fb <= 1000000) // 피보나치 수열의 마지막 값이 주어진 수인 1000000 이하 인가 판별 
	{
		fb = fb_1 + fb_2;   // 다음 n값 계산
		fb_2 = fb_1;
		fb_1 = fb;
		printf("-%d", fb);  //   n 값 맞는지 확인 
		if (fb % 2 == 0) sum += fb;
	}
	printf("\n짝수의 합 : %d", sum);

	return 0;
}