//	문제 5, 문자열을 두 개 입력 받아서 먼저 입력받은 문자열에서 나중에 입력받은 문자열의 위치를 검색하는함수
//	만일 없다면 - 1 을 리턴하고 있다면 그 위치를 리턴
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수 원형 
int Search(char* str_a, char* str_b);	//문자열 찾는 함수 

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

	//결과출력 및 함수 호출
	printf("%d번 인덱스 ",Search(str_a, str_b));

	return 0;

}
// 문자열 찾는 함수 
int Search(char* str_a, char* str_b)
{
	// 각 문자열 길이 계산
	int len_1 = strlen(str_a);
	int len_2 = strlen(str_b);

	// idx 와 len_2 의 수가 같으면 같다고 판별
	for (int i = 0; i <=len_1-len_2; i++)
	{
		int idx = 0;	// 계속 0으로 초기화 
		for (int j = 0; j < len_2; j++)
		{
			if (str_a[i+j] == str_b[j])
			{
				idx++;	// 같으면  1씩증가
			}
		}
		if (idx == len_2) return i;	// 시작 인덱스 반환
	}
	return -1;	//없으면 -1 반환 
}