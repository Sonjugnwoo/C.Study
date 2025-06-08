// 문제 4 ,  도서관리 프로그램 구조체 동적할당 사용 
//   구현할 기능 : 책 추가 , 책 검색 , 책 대출 및 반납 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//구조체 정의
typedef  struct Book	
{
	char *name;
	char *publ;
	char *auth;
	int borrow;
	int idx;
} book;

//함수원형
void RegisterBook(book* book_info, int total_book);	//책 추가 함수
void SearchBook(book* book_info, int total_book);	//책 검색 함수
void BorrowBook(book* book_info, int total_book);	//책 대출 함수
void ReturnBook(book* book_info, int total_book);	//책 반납 함수

int main()
{
	int size;
	int user_choice;
	int match;
	int total_book = 0;

	printf("도서 프로그램\n");
	printf("총 몇권의 책을 저장 : ");
	scanf("%d", &size);

	book* book_info = (book*)malloc(sizeof(book) * size);	//구조체 변수 book_info 에 동적 할당 
	if (book_info == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}
	//도서 프로그램
	while (1)
	{
		printf("1 : 책 추가\n2 : 책 검색\n3 : 책 대출\n4 : 책 반납\n5 : 시스템 종료\n");
		scanf("%d", &user_choice);

		//1 : 추가  2 : 검색 3: 대출 4 : 반납 : 5 시스템 종료
		switch (user_choice)
		{
		case 1:
			if (total_book == size)	// 입력값이랑 전체 책의 개수랑 같으면 안내
			{
				printf("더 이상 추가할수 없습니다.");
				return 1;
			}
			printf("책 추가\n");
			printf("------------\n");

			RegisterBook(book_info, total_book);	//추가 함수 호출
			total_book++;	//전체 책 수 세기
			break;
		case 2:
			if (total_book == 0)	//책을 추가안했는데 검색시 처음화면으로
			{
				printf("추가된 책이 없습니다. 책 추가 먼저 해주세요.\n");
				continue;
			}

			printf("책 검색\n");
			printf("------------\n");

			SearchBook(book_info, total_book);	//검색 함수 호출

			break;

		case 3:
			if (total_book == 0)	//책을 추가안했는데 검색시 처음화면으로
			{
				printf("추가된 책이 없습니다. 책 추가 먼저 해주세요.\n");
				continue;
			}

			printf("책 대출\n");
			printf("------------\n");

			BorrowBook(book_info, total_book);	//대출 함수 호출

			break;
		case 4:
			if (total_book == 0)	//책을 추가안했는데 검색시 처음화면으로
			{
				printf("추가된 책이 없습니다. 책 추가 먼저 해주세요.\n");
				continue;
			}

			printf("책 반납\n");
			printf("------------\n");

			ReturnBook(book_info, total_book);	//반납 함수 호출

			break;
		case 5:
			printf("시스템 종료\n");	//시스템 종료
			
			// 전체 메모리 해제
			for (int i = 0; i < total_book; i++) {
				free(book_info[i].name);
				free(book_info[i].publ);
				free(book_info[i].auth);
			}
			free(book_info);
			printf("------------\n");
			return 0;

		default:
			printf("잘못 입력 하셨습니다.\n");
			break;
		}
	
	}
	return 0;
}
//책 추가 함수 
void RegisterBook(book* book_info, int total_book)
{
	char buffer[1024];	// 임시 변수

	//책 정보를 입력받아 구조체(book_info)에 저장
	printf("책 제목 : ");
	scanf("%s", buffer);

	book_info[total_book].name = (char*)malloc(strlen(buffer)+1);	//메모리 동적 할당 (제목)
	if (book_info[total_book].name == NULL)
	{
		printf("메모리 할당 실패\n");
		return ;
	}
	strcpy(book_info[total_book].name, buffer);	// 입력받은 책 제목을 메모리 공간에 복사

	memset(buffer, 0, 1024); // 입력받은값 초기화 
	printf("책 출판사 : ");
	scanf("%s", buffer);

	book_info[total_book].publ = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당 (출판사)
	if (book_info[total_book].publ == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	strcpy(book_info[total_book].publ, buffer);	// 입력받은 책 출판사를 메모리 공간에 복사

	memset(buffer, 0, 1024);
	printf("책 저자 : ");
	scanf("%s", buffer);

	book_info[total_book].auth = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당 (저자)
	if (book_info[total_book].auth == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	strcpy(book_info[total_book].auth, buffer);	// 입력받은 책 저자를 메모리 공간에 복사


	book_info[total_book].idx = total_book + 1;
	book_info[total_book].borrow = 1;
	printf("------------\n");
}
void SearchBook(book* book_info, int total_book)
{
	int match = 0;
	char *search;
	char buffer[1024];
	int found = 0;	//책이 있는지 없는지 체크 할 변수
	int menu = 0;

	printf("1 : 완전 일치\n2 : 부분 일치\n");
	scanf("%d", &match);
	
	if (match == 1)
	{
		memset(buffer, 0, 1024);
		printf("완전 일치 선택\n");
		printf("------------\n");
		printf("책 정보 입력 : ");
		scanf("%s", buffer);

		search = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당
		if (search == NULL)
		{
			printf("메모리 할당 실패\n");
			return;
		}
		strcpy(search, buffer);	// 입력받은 검색할 정보를 메모리 공간에 복사

		//strcmp 완전일치시 책 정보 출력
		for (int i = 0; i < total_book; i++)
		{
			if ((strcmp(book_info[i].name, search) == 0 ||
				strcmp(book_info[i].publ, search) == 0 ||
				strcmp(book_info[i].auth, search) == 0) &&
				book_info[i].borrow == 1)
			{
				printf("------------\n");

				printf("책 제목 : %s\n", book_info[i].name);
				printf("책 출판사 : %s\n", book_info[i].publ);
				printf("책 저자 : %s\n", book_info[i].auth);
				printf("%d번 책\n", book_info[i].idx);
				printf("대출 가능\n");

				printf("------------\n");

				found = 1;
			}
		}
		if (!found)
		{
			printf("찾을 수 없습니다.\n");
			free(search);	//못찾을시 바로 메모리 정리
			return;
		}
		free(search);
	}
	else if (match == 2)
	{
		memset(buffer, 0, 1024);	
		printf("부분 일치 선택\n");
		printf("------------\n");

		printf("1 : 제목\n2 : 출판사\n3 : 저자\n");
		scanf("%d", &menu);

		printf("------------\n");

		//1 : 책 제목 2 : 출판사 3 : 저자
		//strstr :어떤 문자열 안에 특정 부분 문자열이 포함되어 있는지 (못찾으면 NULL 찾으면 주소 반환)
		switch (menu)
		{
		case 1 :
			printf("책 제목 입력 : ");
			scanf("%s", buffer);

			search = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당
			if (search == NULL)
			{
				printf("메모리 할당 실패\n");
				return;
			}
			strcpy(search, buffer);	// 입력받은 검색할 정보를 메모리 공간에 복사

			for (int i = 0; i < total_book; i++)
			{
				if (strstr(book_info[i].name, search) != NULL && book_info[i].borrow==1)
				{
					printf("------------\n");

					printf("책 제목 : %s\n", book_info[i].name);
					printf("책 출판사 : %s\n", book_info[i].publ);
					printf("책 저자 : %s\n", book_info[i].auth);
					printf("%d번 책\n", book_info[i].idx);
					printf("대출 가능\n");

					found = 1;
				}
			}
			if (!found)
			{
				printf("찾을 수 없습니다.\n");
			}
			free(search);
			printf("------------\n");
			break;
		case 2 :
			printf("책 출판사 입력 : ");
			scanf("%s", buffer);

			search = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당 
			if (search == NULL)
			{
				printf("메모리 할당 실패\n");
				return;
			}
			strcpy(search, buffer);
			for (int i = 0; i < total_book; i++)	//입력받은 검색할 정보를 메모리 공간에 복사
			{
				if (strstr(book_info[i].publ, search) != NULL && book_info[i].borrow == 1)
				{
					printf("------------\n");

					printf("책 제목 : %s\n", book_info[i].name);
					printf("책 출판사 : %s\n", book_info[i].publ);
					printf("책 저자 : %s\n", book_info[i].auth);
					printf("%d번 책\n", book_info[i].idx);
					printf("대출 가능\n");
							
					found = 1;
				}
			}
			if (!found)
			{
				printf("찾을 수 없습니다.\n");
			}
			free(search);
			printf("------------\n");
			break;
		case 3 :
			printf("책 저자 입력 : ");
			scanf("%s", buffer);

			search = (char*)malloc(strlen(buffer) + 1);	//메모리 동적 할당
			if (search == NULL)
			{
				printf("메모리 할당 실패\n");
				return;
			}
			strcpy(search, buffer);	// 입력받은 검색할 정보를 메모리 공간에 복사

			for (int i = 0; i < total_book; i++)
			{
				if (strstr(book_info[i].auth, search) != NULL && book_info[i].borrow == 1)
				{
					printf("------------\n");

					printf("책 제목 : %s\n", book_info[i].name);
					printf("책 출판사 : %s\n", book_info[i].publ);
					printf("책 저자 : %s\n", book_info[i].auth);
					printf("%d번 책\n", book_info[i].idx);
					printf("대출 가능\n");

					found = 1;
				}
			}
			if (!found)
			{
				printf("찾을 수 없습니다.\n");
			}
			printf("------------\n");
			free(search);
			break;
		default:
			printf("잘못된입력. 처음으로 돌아갑니다.\n");
			break;
		}
	}
}
//대출 함수 
void BorrowBook(book* book_info, int total_book)
{
	int choice = 0;
	int idx = 0;

	printf("1 : 책 번호 조회\n2 : 대출\n");
	scanf("%d", &choice);

	// 1. 책 번호 조회(검색 결과 출력 후 번호 입력) 또는 
	// 2. 바로 책 번호 입력을 통해 대출 처리.

	if (choice == 1)
	{
		SearchBook(book_info, total_book);	//책 정보 검색

		printf("대출할 책 번호 입력 : ");
		scanf("%d", &idx);

		if (idx < 1 || idx >total_book)
		{
			printf("잘못된 번호 입니다.");
			return;
		}
		//선택한 책이 대출 가능하면 대출 처리, 아니면 안내
		if (book_info[idx - 1].borrow == 1)
		{
			printf("%d번 책 대출 완료\n", idx);
			book_info[idx - 1].borrow = 0;
		}
		else
			printf("이미 대출 한책\n");
		return;
	}
	else if (choice == 2)
	{
		printf("대출할 책 번호 입력 : ");
		scanf("%d", &idx);

		if (idx < 1 || idx >total_book)
		{
			printf("잘못된 번호 입니다.");
			return;
		}
		//선택한 책이 대출 가능하면 대출 처리, 아니면 안내
		if (book_info[idx - 1].borrow == 1)
		{
			printf("%d번 책 대출 완료\n", idx);
			book_info[idx - 1].borrow = 0;
		}
		else
			printf("이미 대출 한책\n");
		return;

	}
}
void ReturnBook(book* book_info, int total_book)
{
	int idx = 0;
	int choice = 0;

	printf("1 : 번호 조회\n 2 : 반납\n");
	scanf("%d", &choice);

	// 1. 책 번호 조회(검색 결과 출력 후 번호 입력) 또는 
	// 2. 바로 책 번호 입력을 통해 반납 처리.
	if (choice == 1)
	{
		SearchBook(book_info, total_book);	//책 정보 검색

		printf("반납할 책 번호 입력 : ");
		scanf("%d", &idx);
		if (idx < 1 || idx >total_book)
		{
			printf("잘못된 번호 입니다.");
			return;
		}
		//선택한 책이 반납 가능하면 반납 처리, 아니면 안내
		if (book_info[idx - 1].borrow == 0)
		{
			printf("%d번 책 반납 완료\n", idx);
			book_info[idx - 1].borrow = 1;
		}
		else
			printf("이미 반납 한책\n");
		return;
	}
	else if (choice == 2)
	{
		printf("반납할 책 번호 입력 : ");
		scanf("%d", &idx);

		if (idx < 1 || idx >total_book)
		{
			printf("잘못된 번호 입니다.");
			return;
		}
		//선택한 책이 반납 가능하면 반납 처리, 아니면 안내
		if (book_info[idx - 1].borrow == 0)
		{
			printf("%d번 책 반납 완료\n", idx);
			book_info[idx - 1].borrow = 1;
		}
		else
			printf("이미 반납 한책\n");
		return;
	}
}