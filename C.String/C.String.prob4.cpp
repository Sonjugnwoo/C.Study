// 문제 4,  두 개의 문자열을 입력 받아서 같다면 "같다", 다르면 "다르다" 라고 출력하는 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수원형
void Equl(char* str_a, char* str_b);	// 문자열 비교 함수 

int main()
{
	// 문자열 저장 배열
	char str_a[100];
	char str_b[100];

	//문자열 입력 
	printf("문자열 입력 : ");
	scanf("%s", str_a);
	printf("문자열 입력 : ");
	scanf("%s", str_b);

	//함수 호출
	Equl(str_a, str_b);

	return  0;
}
//문자열 비교 함수 
void Equl(char *str_a, char* str_b)
{
	//strcmp가 0 을 반환하면 문자열은 똑같다 .
	if (strcmp(str_a, str_b) == 0) 
		printf("같다");
	else
		printf("다르다");
}