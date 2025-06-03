//	문제 6, 도서 관리 프로그램
//  구현할 기능 : 책 추가 , 책 검색 , 책 대출 및 반납 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//함수 원형
void BookAdd(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], int idx);	//책 추가 함수
void BookSearch(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow,int idx);	//책 찾는 함수 (부분 일치)
void BookSearchPerfect(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow,int idx);	//책 찾는 함수 (완전 일치)
void BookBorrow(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx);	//책 대출 함수
void BookReturn(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx);	//책 반납 함수

int main()
{
	// 책 정보 담을 배열 
	char book_name[100][30];
	char book_publ[100][30];
	char book_auth[100][30];
	char book_search[30];

	int book_borrow[100] = { 0 };
	int user_choice;
	int match;
	int idx = 0;

	printf("도서 프로그램\n");
	//도서 프로그램 
	while (1)
	{
		printf("1 : 책 추가\n2 : 책 검색\n3 : 책 대출\n4 : 책 반납\n5 : 시스템 종료\n");
		scanf("%d", &user_choice);

		//1 : 추가  2 : 검색 3: 대출 4 : 반납 : 5 시스템 종료
		switch (user_choice)
		{
		case 1:
			printf("책 추가\n");
			printf("------------\n");
			if (idx == 100)//크기를 100으로 지정했기때문에 100 일시 더이상 추가 X
			{
				printf("더이상 책추가를 못합니다");
				return 0;
			}

			BookAdd(book_name, book_publ, book_auth, idx);	//추가 함수 호출

			book_borrow[idx] = 1;	// 책입력 들어올때마다 1로 설정
			idx++;	// 전체 책 수 세기
			break;
		case 2:
			if (idx == 0)	//입력된 값이 없는데 검색시 처음화면으로
			{
				printf("추가된 책이 없습니다. 책 추가 먼저 해주세요.\n");
				continue;
			}

			printf("책 검색\n");
			printf("------------\n");

			printf("1 : 완전일치\n2 : 부분일치\n");
			scanf("%d", &match);

			if (match == 1) printf("완전 일치 선택\n");
			else if (match == 2) printf("부분 일치 선택\n");
			else
			{
				printf("잘못 입력 처음화면으로 돌아갑니다.\n");
				break;
			}

			printf("검색할 책 정보 입력 : ");
			scanf("%s", book_search);

			if (match == 1)	BookSearchPerfect(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//완전일치 호출
			else BookSearch(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//부분일치 호출
			break;
		case 3:
			if (idx == 0)	//입력된 값이 없는데 검색시 처음화면으로
			{
				printf("추가된 책이 없습니다. 책 추가 먼저 해주세요.\n");
				continue;
			}

			printf("책 대출\n");
			printf("------------\n");

			printf("대출할 책의 제목: ");
			scanf("%s", book_search);

			BookBorrow(book_name, book_publ, book_auth, book_search, book_borrow, idx);	//대출 함수 호출
				break;
		case 4:
			if (idx == 0)	//입력된 값이 없는데 검색시 처음화면으로
			{
				printf("추가된 책이 없습니다. 책 추가 먼저 해주세요.\n");
				continue;
			}

			printf("책 반납\n");
			printf("------------\n");

			printf("반납할 책의 제목: ");
			scanf("%s", book_search);

			BookReturn(book_name, book_publ, book_auth, book_search, book_borrow, idx);	//반납 함수 호출
			break;
		case 5:
			printf("시스템 종료\n");	//시스템 종료 
			return 0;
		default:
			printf("잘못 입력 하셨습니다.\n");
			break;
		}
	}

	return 0;
}

//책 추가 함수 
void BookAdd(char(* book_name)[30], char(* book_publ)[30], char(* book_auth)[30],int idx)
{
	// 제목 출판사 저자 받은후 book_name,publ,auth 에 저장 
	printf("책 제목 : ");
	scanf("%s", book_name[idx]);

	printf("책 출판사 : ");
	scanf("%s", book_publ[idx]);

	printf("책 저자 : ");
	scanf("%s", book_auth[idx]);
}

//완전일치 함수 
void BookSearchPerfect(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search,int * book_borrow,int idx)
{
	
	int found = 0;		//책이 있는지 없는지 체크 할 변수

	//strcmp 완전일치시 책 정보 출력
	for (int i = 0; i < idx; i++)
	{

		if ((strcmp(book_name[i], book_search) == 0 ||
			strcmp(book_publ[i], book_search) == 0 ||
			strcmp(book_auth[i], book_search) == 0 )&&
			book_borrow[i] ==1)
		{
				printf("책 이름 : %s\n", book_name[i]);
				printf("책 출판사 : %s\n", book_publ[i]);
				printf("책 저자 : %s\n", book_auth[i]);
				printf("%d번째 책\n", i + 1);
				printf("대출 가능\n");
				found = 1;
		}
	}
	if (!found)
	{
		printf("찾지 못했습니다\n");
		return;
	}
}

//부분일치 함수 
void BookSearch(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx)
{
	int menu = 0;
	int found = 0;	//책이 있는지 없는지 체크 할 변수

	printf("1 : 제목 검색\n2 : 출판사 검색\n3 : 저자 검색\n");
	scanf("%d", &menu);

	//1 : 책 제목 2 : 출판사 3 : 저자
	//strstr :어떤 문자열 안에 특정 부분 문자열이 포함되어 있는지 (못찾으면 NULL 찾으면 주소 반환)
	if (menu == 1)
	{
		for (int i = 0; i < idx; i++)
		{
			
			if (strstr(book_name[i], book_search) != NULL && book_borrow[i] ==1)
			{
				printf("책 이름 : %s\n", book_name[i]);
				printf("책 출판사 : %s\n", book_publ[i]);
				printf("책 저자 : %s\n", book_auth[i]);
				printf("%d번째 책\n", i + 1);
				printf("대출 가능\n");
				found = 1;
			}
		}
		if (!found)
		{
			printf("찾지 못했습니다\n");
			return;
		}
	}
	else if (menu == 2)
	{
		for (int i = 0; i < idx; i++)
		{
			if (strstr(book_name[i], book_search) != NULL && book_borrow[i] == 1)
			{
				printf("책 이름 : %s\n", book_name[i]);
				printf("책 출판사 : %s\n", book_publ[i]);
				printf("책 저자 : %s\n", book_auth[i]);
				printf("%d번째 책\n", i + 1);
				found = 1;
			}
		}
		if (!found)
		{
			printf("찾지 못했습니다\n");
			return;
		}
	}
	else if (menu == 3)
	{
		for (int i = 0; i < idx; i++)
		{
			if (strstr(book_name[i], book_search) != NULL && book_borrow[i] == 1)
			{
				printf("책 이름 : %s\n", book_name[i]);
				printf("책 출판사 : %s\n", book_publ[i]);
				printf("책 저자 : %s\n", book_auth[i]);
				printf("%d번 책\n", i + 1);
				found = 1;
			}
		}
		if (!found)
		{
			printf("찾지 못했습니다\n");
			return;
		}
	}
	else
	printf("잘못 입력하셨습니다.\n");
}
void BookBorrow(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int *book_borrow ,int idx)
{

	char choice[2];
	int temp = 0;	//책 번호 찾을 변수
	int found = 0;	//책이 있는지 없는지 체크 할 변수

	//책 찾기 
	for (int i = 0; i < idx; i++)
	{
		if (strcmp(book_name[i], book_search) == 0)
		{
			found = 1;
			temp = i;
		}
	}
	if (!found)
	{
		printf("찾지 못했습니다.\n");
		return;
	}

	BookSearchPerfect(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//완벽하게 안다고 가정하고 완전 일치 호출

	printf("이책이 맞습니까 ? (Y , N) ");
	scanf("%s", choice);
	
	//strncmp  Y , N  있는지 첫번째 자리 확인 후 borrow >> 1 : 대출 가능 0 : 대출 X
	if (strncmp(choice,"Y", 1)== 0 )
	{
		if (book_borrow[temp] == 1)
		{
			printf("%s 대출완료\n", book_search);
			book_borrow[temp] = 0;
		}
		else
			printf("이미 대출한 책입니다.\n");
	}
	else if (strncmp(choice, "N", 1) == 0)
	{
		printf("처음 화면으로 돌아갑니다.\n");
	}
	else
		printf("잘못입력하셨습니다.\n");
}
void BookReturn(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx)
{
	char choice[2];
	int temp = 0;	//책 번호 찾을 변수
	int found = 0;	//책이 있는지 없는지 체크 할 변수

		//책 찾기 
	for (int i = 0; i < idx; i++)
	{
		if (strcmp(book_name[i], book_search) == 0)
		{
			found = 1;
			temp = i;
		}
	}
	if (!found)
	{
		printf("찾지 못했습니다.\n");
		return;
	}

	BookSearchPerfect(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//완벽하게 안다고 가정하고 완전 일치 호출

	printf("이책이 맞습니까 ? (Y , N) ");
	scanf("%s", choice);

	//strncmp  Y , N  있는지 첫번째 자리 확인 후 borrow >> 0 : 반납 가능 1 : 반납 X
	if (strncmp(choice, "Y", 1) == 0)
	{
		if (book_borrow[temp] == 0)
		{
			printf("%s 반납완료\n", book_search);
			book_borrow[temp] = 1;
		}
		else
			printf("이미 반납한 책입니다.\n");
	}
	else if (strncmp(choice, "N", 1) == 0)
	{
		printf("처음 화면으로 돌아갑니다.\n");
	}
	else
		printf("잘못입력하셨습니다.\n");
}