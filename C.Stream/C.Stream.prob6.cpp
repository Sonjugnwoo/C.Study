// 문제 5, 파일에서 특정한 문자를 검색하여 몇 개나 나오는지 출력하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//파일 변수
	FILE* fp = fopen("D:\\study\\prob6.txt", "w+");
	//파일에 넣을 내용 
	fputs(
	"One of the strengths of C is its powerful handling of data structures and memory management.\n\
	Programmers can define complex structures, manage dynamic memory allocation, and manipulate pointers to optimize performance.\n\
	This level of control is especially valuable in developing systems like library management software,\n\
	where efficient data organization and processing are critical", fp);
	fclose(fp);

	//찾을 문자 배열 
	char buffer[1024];
	char search[1024];
	
	//공백 포함 입력 받기 
	printf("찾을 문자 : ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")] = '\0'; // 줄바꿈 문자가 남아 있으면 검색이 제대로 안될 수 있기 때문에 NULL값 대입

		//파일 변수
	fp = fopen("D:\\study\\prob6.txt", "r");

	int count = 0; 
	int idx = 0;

	//한줄씩 읽어 부분 문자열 검색 
	while (fgets(buffer, sizeof(buffer), fp))
	{
		char* p = buffer;	//현재 줄 주소 포인터
		char* found;		//발견된 위치 저장 포인터

		while ((found = strstr(p, search)) !=NULL)	//현재 줄에 검색 문자열 있는지 반복
		{
			count++;
			p = found + strlen(search);	//찾은 위치 다음부터 다시 검색 시작 
			//+ strlen(search)는 찾은 문자열의 "끝" 다음부터 다시 검색하기 위함
			//strstr은 찾은 문자열의 첫부분의 주소를 반환 
		}
		
	}
	//결과 출력
	printf("%d개 있습니다", count);

	//파일 닫기
	fclose(fp);
	return 0;
}