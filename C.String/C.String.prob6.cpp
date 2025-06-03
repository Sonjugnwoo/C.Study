//	���� 6, ���� ���� ���α׷�
//  ������ ��� : å �߰� , å �˻� , å ���� �� �ݳ� 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//�Լ� ����
void BookAdd(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], int idx);	//å �߰� �Լ�
void BookSearch(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow,int idx);	//å ã�� �Լ� (�κ� ��ġ)
void BookSearchPerfect(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow,int idx);	//å ã�� �Լ� (���� ��ġ)
void BookBorrow(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx);	//å ���� �Լ�
void BookReturn(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx);	//å �ݳ� �Լ�

int main()
{
	// å ���� ���� �迭 
	char book_name[100][30];
	char book_publ[100][30];
	char book_auth[100][30];
	char book_search[30];

	int book_borrow[100] = { 0 };
	int user_choice;
	int match;
	int idx = 0;

	printf("���� ���α׷�\n");
	//���� ���α׷� 
	while (1)
	{
		printf("1 : å �߰�\n2 : å �˻�\n3 : å ����\n4 : å �ݳ�\n5 : �ý��� ����\n");
		scanf("%d", &user_choice);

		//1 : �߰�  2 : �˻� 3: ���� 4 : �ݳ� : 5 �ý��� ����
		switch (user_choice)
		{
		case 1:
			printf("å �߰�\n");
			printf("------------\n");
			if (idx == 100)//ũ�⸦ 100���� �����߱⶧���� 100 �Ͻ� ���̻� �߰� X
			{
				printf("���̻� å�߰��� ���մϴ�");
				return 0;
			}

			BookAdd(book_name, book_publ, book_auth, idx);	//�߰� �Լ� ȣ��

			book_borrow[idx] = 1;	// å�Է� ���ö����� 1�� ����
			idx++;	// ��ü å �� ����
			break;
		case 2:
			if (idx == 0)	//�Էµ� ���� ���µ� �˻��� ó��ȭ������
			{
				printf("�߰��� å�� �����ϴ�. å �߰� ���� ���ּ���.\n");
				continue;
			}

			printf("å �˻�\n");
			printf("------------\n");

			printf("1 : ������ġ\n2 : �κ���ġ\n");
			scanf("%d", &match);

			if (match == 1) printf("���� ��ġ ����\n");
			else if (match == 2) printf("�κ� ��ġ ����\n");
			else
			{
				printf("�߸� �Է� ó��ȭ������ ���ư��ϴ�.\n");
				break;
			}

			printf("�˻��� å ���� �Է� : ");
			scanf("%s", book_search);

			if (match == 1)	BookSearchPerfect(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//������ġ ȣ��
			else BookSearch(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//�κ���ġ ȣ��
			break;
		case 3:
			if (idx == 0)	//�Էµ� ���� ���µ� �˻��� ó��ȭ������
			{
				printf("�߰��� å�� �����ϴ�. å �߰� ���� ���ּ���.\n");
				continue;
			}

			printf("å ����\n");
			printf("------------\n");

			printf("������ å�� ����: ");
			scanf("%s", book_search);

			BookBorrow(book_name, book_publ, book_auth, book_search, book_borrow, idx);	//���� �Լ� ȣ��
				break;
		case 4:
			if (idx == 0)	//�Էµ� ���� ���µ� �˻��� ó��ȭ������
			{
				printf("�߰��� å�� �����ϴ�. å �߰� ���� ���ּ���.\n");
				continue;
			}

			printf("å �ݳ�\n");
			printf("------------\n");

			printf("�ݳ��� å�� ����: ");
			scanf("%s", book_search);

			BookReturn(book_name, book_publ, book_auth, book_search, book_borrow, idx);	//�ݳ� �Լ� ȣ��
			break;
		case 5:
			printf("�ý��� ����\n");	//�ý��� ���� 
			return 0;
		default:
			printf("�߸� �Է� �ϼ̽��ϴ�.\n");
			break;
		}
	}

	return 0;
}

//å �߰� �Լ� 
void BookAdd(char(* book_name)[30], char(* book_publ)[30], char(* book_auth)[30],int idx)
{
	// ���� ���ǻ� ���� ������ book_name,publ,auth �� ���� 
	printf("å ���� : ");
	scanf("%s", book_name[idx]);

	printf("å ���ǻ� : ");
	scanf("%s", book_publ[idx]);

	printf("å ���� : ");
	scanf("%s", book_auth[idx]);
}

//������ġ �Լ� 
void BookSearchPerfect(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search,int * book_borrow,int idx)
{
	
	int found = 0;		//å�� �ִ��� ������ üũ �� ����

	//strcmp ������ġ�� å ���� ���
	for (int i = 0; i < idx; i++)
	{

		if ((strcmp(book_name[i], book_search) == 0 ||
			strcmp(book_publ[i], book_search) == 0 ||
			strcmp(book_auth[i], book_search) == 0 )&&
			book_borrow[i] ==1)
		{
				printf("å �̸� : %s\n", book_name[i]);
				printf("å ���ǻ� : %s\n", book_publ[i]);
				printf("å ���� : %s\n", book_auth[i]);
				printf("%d��° å\n", i + 1);
				printf("���� ����\n");
				found = 1;
		}
	}
	if (!found)
	{
		printf("ã�� ���߽��ϴ�\n");
		return;
	}
}

//�κ���ġ �Լ� 
void BookSearch(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx)
{
	int menu = 0;
	int found = 0;	//å�� �ִ��� ������ üũ �� ����

	printf("1 : ���� �˻�\n2 : ���ǻ� �˻�\n3 : ���� �˻�\n");
	scanf("%d", &menu);

	//1 : å ���� 2 : ���ǻ� 3 : ����
	//strstr :� ���ڿ� �ȿ� Ư�� �κ� ���ڿ��� ���ԵǾ� �ִ��� (��ã���� NULL ã���� �ּ� ��ȯ)
	if (menu == 1)
	{
		for (int i = 0; i < idx; i++)
		{
			
			if (strstr(book_name[i], book_search) != NULL && book_borrow[i] ==1)
			{
				printf("å �̸� : %s\n", book_name[i]);
				printf("å ���ǻ� : %s\n", book_publ[i]);
				printf("å ���� : %s\n", book_auth[i]);
				printf("%d��° å\n", i + 1);
				printf("���� ����\n");
				found = 1;
			}
		}
		if (!found)
		{
			printf("ã�� ���߽��ϴ�\n");
			return;
		}
	}
	else if (menu == 2)
	{
		for (int i = 0; i < idx; i++)
		{
			if (strstr(book_name[i], book_search) != NULL && book_borrow[i] == 1)
			{
				printf("å �̸� : %s\n", book_name[i]);
				printf("å ���ǻ� : %s\n", book_publ[i]);
				printf("å ���� : %s\n", book_auth[i]);
				printf("%d��° å\n", i + 1);
				found = 1;
			}
		}
		if (!found)
		{
			printf("ã�� ���߽��ϴ�\n");
			return;
		}
	}
	else if (menu == 3)
	{
		for (int i = 0; i < idx; i++)
		{
			if (strstr(book_name[i], book_search) != NULL && book_borrow[i] == 1)
			{
				printf("å �̸� : %s\n", book_name[i]);
				printf("å ���ǻ� : %s\n", book_publ[i]);
				printf("å ���� : %s\n", book_auth[i]);
				printf("%d�� å\n", i + 1);
				found = 1;
			}
		}
		if (!found)
		{
			printf("ã�� ���߽��ϴ�\n");
			return;
		}
	}
	else
	printf("�߸� �Է��ϼ̽��ϴ�.\n");
}
void BookBorrow(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int *book_borrow ,int idx)
{

	char choice[2];
	int temp = 0;	//å ��ȣ ã�� ����
	int found = 0;	//å�� �ִ��� ������ üũ �� ����

	//å ã�� 
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
		printf("ã�� ���߽��ϴ�.\n");
		return;
	}

	BookSearchPerfect(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//�Ϻ��ϰ� �ȴٰ� �����ϰ� ���� ��ġ ȣ��

	printf("��å�� �½��ϱ� ? (Y , N) ");
	scanf("%s", choice);
	
	//strncmp  Y , N  �ִ��� ù��° �ڸ� Ȯ�� �� borrow >> 1 : ���� ���� 0 : ���� X
	if (strncmp(choice,"Y", 1)== 0 )
	{
		if (book_borrow[temp] == 1)
		{
			printf("%s ����Ϸ�\n", book_search);
			book_borrow[temp] = 0;
		}
		else
			printf("�̹� ������ å�Դϴ�.\n");
	}
	else if (strncmp(choice, "N", 1) == 0)
	{
		printf("ó�� ȭ������ ���ư��ϴ�.\n");
	}
	else
		printf("�߸��Է��ϼ̽��ϴ�.\n");
}
void BookReturn(char(*book_name)[30], char(*book_publ)[30], char(*book_auth)[30], char* book_search, int* book_borrow, int idx)
{
	char choice[2];
	int temp = 0;	//å ��ȣ ã�� ����
	int found = 0;	//å�� �ִ��� ������ üũ �� ����

		//å ã�� 
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
		printf("ã�� ���߽��ϴ�.\n");
		return;
	}

	BookSearchPerfect(book_name, book_publ, book_auth, book_search, book_borrow,idx);	//�Ϻ��ϰ� �ȴٰ� �����ϰ� ���� ��ġ ȣ��

	printf("��å�� �½��ϱ� ? (Y , N) ");
	scanf("%s", choice);

	//strncmp  Y , N  �ִ��� ù��° �ڸ� Ȯ�� �� borrow >> 0 : �ݳ� ���� 1 : �ݳ� X
	if (strncmp(choice, "Y", 1) == 0)
	{
		if (book_borrow[temp] == 0)
		{
			printf("%s �ݳ��Ϸ�\n", book_search);
			book_borrow[temp] = 1;
		}
		else
			printf("�̹� �ݳ��� å�Դϴ�.\n");
	}
	else if (strncmp(choice, "N", 1) == 0)
	{
		printf("ó�� ȭ������ ���ư��ϴ�.\n");
	}
	else
		printf("�߸��Է��ϼ̽��ϴ�.\n");
}