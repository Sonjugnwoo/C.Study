// 문제 1, 두 개의 문자열을 비교하는 함수를 만들어서 같으면 1, 다르면 0 을 리턴
#include<stdio.h>
#include<string.h>

//함수원형
int StrEqul(char* str_a, char* str_b);
int Strcmp(char* str_a, char* str_b);

int main()
{
	char str_a[] = "abc";
	char str_b[] = "abc";
	
	printf("%d\n", StrEqul(str_a, str_b));

	printf("%d\n", Strcmp(str_a, str_b));
	return 0;
}

// 두 문자열 비교 직접 구현
int StrEqul(char* str_a, char* str_b)
{
	//길이 저장 변수
	int len_1 = 0;	
	int len_2 = 0;

	// 문자열 길이 계산
	while (str_a[len_1] != '\0')	len_1++;	
	while (str_b[len_2] != '\0')	len_2++;
	
	// 1 . 두 문자열의 길이 비교
	if (len_1 == len_2)
	{
		// 2 . 각 자리의 문자 비교 
		for (int i = 0; i < len_1; i++)
		{
			if (str_a[i] != str_b[i]) return 0; // 다르면 0 반환
		}
		return 1;	// 모두 같으면 1 반환
	}
	return 0;	// 길이가 다르면 0반환
}

//strcmp 내장함수 사용
int Strcmp(char* str_a, char* str_b)
{
	if (strcmp(str_a, str_b) == 0) return 1;	//strcmp : 두 문자가같으면 0 반환 다르면 0이 아닌값 반환 
	else return 0;
}
