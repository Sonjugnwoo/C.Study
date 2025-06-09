// 문제 2,  prob2.txt 에 어떠한 긴 글이 들어 있는데, 이 글을 입력 받아서 특정한 문자열을 검색하는 프로그램
// test.txt 내용 : Learning step by step, I build new skills every day. Consistent effort and curiosity make progress possible.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//문자열 저장 배열 
	char buffer[1024];	
	char* search;

	int ch;
	int idx = 0;
	int count = 0;
	int found = 0;

	FILE* fp = fopen("D:\\study\\prob2.txt", "r+");	//파일 변수 r+ : 읽기 쓰기 
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	printf("찾을 문자열 : ");
	scanf("%s", buffer);

	search = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당
	if (search == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}
	strcpy(search, buffer);	//입력받은 값 복제 

	int len = strlen(search);	//문자열 길이 측정 

	//문자열 순회 하며 입력값이랑 같은지 검사 
	//fgetc : 한 문자 씩 읽어와서 int 값으로 반환 (아스키 코드)
	//EOF  : 파일이나 입력 스트림의 끝을 나타내는 특별한 값
	while ((ch = fgetc(fp)) != EOF)
	{
		count++;
		if (ch == search[idx])	//문자가 일치 할시 idx 증가시켜 다음 문자로 이동 
		{
			idx++;
			if (idx == len)
			{
				found = 1;	//찾으면 1 못찾으면 0
				fclose(fp);	//파일 닫기
				free(search);	//메모리 해제
				printf("%d", count- len+1);	//시작지점 출력 
				return 0;	//종료
			}
		}
		else
			idx = 0;		//아닐시 다시 0 
	}
	// 못찾았을시 안내 및 파일 닫기 , 메모리 해제
	if (!found)
	{
		fclose(fp);
		free(search);
		printf("찾지못했습니다.");
	}

	return 0;
}