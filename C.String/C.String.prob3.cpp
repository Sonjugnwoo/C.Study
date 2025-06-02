// 문제 3, 길이가 최대 100 인 문자열을 입력 받아서 소문자는 대문자로, 대문자는 소문자로 출력하는 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수원형
void Change(char str[]);	//대소문자 변경 

int main()
{
	char str[101];	//문자열 저장  100 문자 + NULL 자리 

	//문자열 입력 
	printf("문자열 입력 : ");
	scanf("%s", str);

	//함수 호출
	Change(str);

	return 0;
}
//대소문자 변경 함수
void Change(char *str)
{
	//문자열 길이 계산 
	int len = strlen(str);

	//대소문자 변경식
	for (int i = 0; i < len; i++)
	{
		// 소문자 -> 대문자
		if (str[i] >= 'a' && str[i] <='z')
			str[i] -= 32;
		// 대문자 -> 소문자
		else if (str[i]>='A' && str[i] <= 'Z')
			str[i] += 32;
		// 알파벳 아니면 변환 X
	}

	//결과 출력
	printf("%s", str);
}