// 문제 3,  prob3.txt 에 문자열을 입력 받아서 reverse_prob3.txt 에 그 문자열을 역으로 출력하는 프로그램


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	//문자열 저장 배열 
	char buffer[1024];
	char* input;

	FILE* fp = fopen("D:\\study\\prob3.txt", "w+");	//파일 변수   w+ : 쓰기 읽기
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}


	printf("prob3.txt 에 넣을 문자 입력  : ");
	scanf("%s", buffer);

	input = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당 
	if (input == NULL)
	{
		printf("메모리 할당 실패");
		return 1;
	}

	strcpy(input, buffer);	// 입력받은 값  복제

	fputs(input, fp);	//fp 에 복제한 값 넣기 

	int len = strlen(input);	//문자열 길이 측정

	FILE* fp_2 = fopen("D:\\study\\reverse_prob3.txt", "w+");	//파일 변수   w+ : 쓰기 읽기
	if (fp_2 == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}
	//역순 출력위해 뒤집기 
	for (int i = 0; i < len/2; i++)
	{
		int temp = input[i];
		input[i] = input[len - 1 - i];
		input[len - 1 - i] = temp;
	}

	fputs(input, fp_2);	//fp_2 에 뒤집은 값 넣기 
	printf("reverse_prob3.txt 내용 : %s", input);
	// 폴더 닫기 및 메모리 해제
	fclose(fp);
	fclose(fp_2);
	free(input);
	return 0;
}