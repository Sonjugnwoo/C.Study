//문제 9 , 자기 자신을 호출하는 함수를 이용해서 1 부터 특정한 수까지의 곱을 구하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
int Factorial(int num);

int main()
{
	int input_num;	// 입력 받을 값
	printf("N값 입력 : ");
	scanf("%d", &input_num);

	//결과 출력
	printf("%d! : %d", input_num,Factorial(input_num));
	return 0;
}
//팩토리얼 함수 (재귀 호출)
int Factorial(int num)
{
	if (num == 1) return 1;	//  재귀 종료 조건
	return num * Factorial(num - 1);	// 재귀 호출
}
