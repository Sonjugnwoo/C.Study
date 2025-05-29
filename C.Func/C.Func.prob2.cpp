//문제 2 ,  1 부터 n 까지의 합을 구하는 함수를 작성
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수원형 
int Sum(int num);
int Sum2(int num);

int main()
{
	int input_num; //N값
	printf("N값 입력 :");
	scanf("%d", &input_num);

	printf("1번 sum 호출\n1 ~ %d 의 합 : %d\n", input_num, Sum(input_num));  //결과 출력
	printf("2번 sum 호출\n1 ~ %d 의 합 : %d\n", input_num, Sum2(input_num));
	return 0;
}

//1 ~ num 까지의 합
int Sum(int num)
{
	int sum = 0;
	for (int i = 1; i <= num; i++)
	 sum += i;
	return sum;
}
// 1~ num 합 구하는 다른 공식
int Sum2(int num)
{
	return num * (num + 1) / 2;
}