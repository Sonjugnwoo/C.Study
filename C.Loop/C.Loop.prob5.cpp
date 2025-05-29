// 문제 5 , 사용자로 부터 N 값을 입력 받고 1 부터 N 까지의 곱을 출력한다. (factorial)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int input_num = 0;
	int mul = 1;
	printf("계산할 숫자 입력 :");
	scanf("%d", &input_num);   // 값 입력 받음
	if (input_num == 0) return 1;
	for (int i = 1; i <= input_num; i++)   // 1 부터 input_num 까지 반복
	{
		mul *= i;	//   1부터 input_num 까지 곱하기 ex)1 * 2 * 3 * 4 ...
	}
	printf("결과 : %d", mul);  // 결과 
	return 0;
}


// long long 함수 사용시 범위 증가
