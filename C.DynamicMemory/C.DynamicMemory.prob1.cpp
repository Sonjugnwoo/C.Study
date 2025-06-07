// 문제 1 ,  메인함수의 인자를 활용한 계산기

#include <stdio.h>
#include <string.h>


int main(int argc, char** argv)
{
	// 입력받은 정수 값 저장 변수 
	int int_part_a = 0;	
	int int_part_b = 0;

	printf("받은 인자의 개수 : %d \n", argc);	

	// 입력한 변수 확인 
	for (int i = 0; i < argc; i++)
	{
		printf("이 프로그램이 받은 인자 : %s\n", argv[i]);
	}
	// 입력받은 인자가 4보다 작으면 종료
	if (argc < 4) {
		printf("사용법: %s \n숫자1 + 숫자2\n", argv[0]);
		return 1;
	}
	// 입력받은 문자열의 길이 계산 
	int len_a = strlen(argv[1]);
	int len_b = strlen(argv[3]);

	// 10자리 제한 
	if (len_a > 10 || len_b > 10) {
		printf("숫자가 너무 깁니다.\n");
		return 1;
	}

	// 두 변수에 수 입력 10의 제곱 으로 자릿수 맞추기
	int pow = 1;
	for (int i = len_a-1; i >=0; i--)
	{
		int_part_a += (argv[1][i] - '0') * pow;
		pow *= 10;
	}
	pow = 1;
	for (int i = len_b - 1; i >= 0; i--)
	{
		int_part_b += (argv[3][i] - '0') * pow;
		pow *= 10;
	}

	// 사칙 연산 기호 확인 및 결과 출력
	if (strcmp(argv[2], "+") == 0)
	{
		int sum = int_part_a + int_part_b;
		printf("합계: %d\n", sum);
	}
	else if (strcmp(argv[2], "-") == 0)
	{
		int min = int_part_a - int_part_b;
		printf("합계: %d\n", min);
	}
	else if (strcmp(argv[2], "*") == 0)
	{
		int mul= int_part_a * int_part_b;
		printf("합계: %d\n", mul);
	}
	else if (strcmp(argv[2], "/") == 0)
	{
		int div = int_part_a / int_part_b;
		printf("합계: %d\n", div);
	}
			
	return 0;
}