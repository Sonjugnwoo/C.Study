// 문제 2, 길이가 최대 100 인 문자열을 하나 입력 받아서 문자열을 역순으로 출력하는 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수원형
void Reverse(char* str);	//문자열 뒤집는 함수 

int main()
	{
		char str[101];	//문자열 저장  100 문자 + NULL 자리 

	//문자열 입력 
	printf("문자열 입력 : ");
	scanf("%s", str);

	//함수 호출
	Reverse(str);

	return 0;
}
//뒤집는 함수 
void Reverse(char *str)
{
	int len = 0;

	//받은 문자열 길이 계산
	while (str[len] != '\0') len++;	

	//문자열의 앞과 뒤를 교환하여 뒤집기 
	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	//결과 출력
	printf("%s", str);
}