// 문제 1,  사용자로 부터 경로를 입력 받아서 그 곳에 파일을 생성하고 a 를 입력해놓는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{   
    char buffer[1024];  //경로를 담을 임시 변수
    memset(buffer, 0, 1024);    //  버퍼 초기화
    FILE* fp;   //파일 변수

    // 경로 입력 
    printf("경로 입력 : \n");
    printf("Ex : D:\\study\\prob1.txt\n");
    scanf("%s", buffer);

    //동적 메모리 할당 
    char* path = (char*)malloc(strlen(buffer) + 1); 
    if (path == NULL)
    {
        printf("메모리 할당 실패\n");
        return 1;
    }
    strcpy(path, buffer);   //입력받은 경로 복사

    //fp 에 경로 입력 
    //r : 읽기 w : 쓰기 a : 추가 
    fp = fopen(path, "w");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        free(path);
        return 1;
    }

    fputs("a", fp); // 만들어진 폴더 안에 a 입력 

      // 성공 메시지 출력
    printf("%s 경로에 파일생성 완료\n", path);
    printf("파일에 'a'를 성공적으로 기록했습니다.\n");

    // 폴더 닫기 및 메모리 해제
    fclose(fp);
    free(path);
    return 0;
}
