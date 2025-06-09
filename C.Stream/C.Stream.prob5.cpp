// 문제 5, 파일에서 특정한 단어를 검색하여 몇 번째 줄에 나오는지 모두 출력하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//파일 변수
	FILE* fp = fopen("D:\\study\\prob5.txt", "w+");
	
	//파일에 넣을 내용 
	fputs(
		"C is a foundational programming language that has played a crucial role in the development of modern software systems\n\
		Its syntax and structure have influenced many other languages,\n\
		making it an essential tool for understanding core programming.", fp);

	fclose(fp); //파일 닫기
	
	//찾을 문자 배열 
	char buffer[1024];
	char search[1024];
	printf("찾을 문자열 : ");

	//공백 포함 입력 받기 
	//stdin : 표준 입력(키보드 입력 등)을 의미하는 파일 스트림
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")] = '\0'; // 줄바꿈 문자가 남아 있으면 검색이 제대로 안될 수 있기 때문에 NULL값 대입

	int found = 0;
	int line = 1;

	//파일 변수
	fp = fopen("D:\\study\\prob5.txt", "r");

	//한줄씩 읽어 부분 문자열 검색 
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if (strstr(buffer, search) != NULL)
		{
			//일치 하다면 출력
			printf("%d번줄에 있습니다.\n", line);
			found = 1;
		}
		line++;	//다음 줄로 이동
	}
	//없을시 안내
	if (!found) printf("없습니다.");

	//파일 닫기
	fclose(fp);
	return 0;
}