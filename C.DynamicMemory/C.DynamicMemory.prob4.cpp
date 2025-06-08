// ���� 4 ,  �������� ���α׷� ����ü �����Ҵ� ��� 
//   ������ ��� : å �߰� , å �˻� , å ���� �� �ݳ� 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//����ü ����
typedef  struct Book	
{
	char *name;
	char *publ;
	char *auth;
	int borrow;
	int idx;
} book;

//�Լ�����
void RegisterBook(book* book_info, int total_book);	//å �߰� �Լ�
void SearchBook(book* book_info, int total_book);	//å �˻� �Լ�
void BorrowBook(book* book_info, int total_book);	//å ���� �Լ�
void ReturnBook(book* book_info, int total_book);	//å �ݳ� �Լ�

int main()
{
	int size;
	int user_choice;
	int match;
	int total_book = 0;

	printf("���� ���α׷�\n");
	printf("�� ����� å�� ���� : ");
	scanf("%d", &size);

	book* book_info = (book*)malloc(sizeof(book) * size);	//����ü ���� book_info �� ���� �Ҵ� 
	if (book_info == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}
	//���� ���α׷�
	while (1)
	{
		printf("1 : å �߰�\n2 : å �˻�\n3 : å ����\n4 : å �ݳ�\n5 : �ý��� ����\n");
		scanf("%d", &user_choice);

		//1 : �߰�  2 : �˻� 3: ���� 4 : �ݳ� : 5 �ý��� ����
		switch (user_choice)
		{
		case 1:
			if (total_book == size)	// �Է°��̶� ��ü å�� ������ ������ �ȳ�
			{
				printf("�� �̻� �߰��Ҽ� �����ϴ�.");
				return 1;
			}
			printf("å �߰�\n");
			printf("------------\n");

			RegisterBook(book_info, total_book);	//�߰� �Լ� ȣ��
			total_book++;	//��ü å �� ����
			break;
		case 2:
			if (total_book == 0)	//å�� �߰����ߴµ� �˻��� ó��ȭ������
			{
				printf("�߰��� å�� �����ϴ�. å �߰� ���� ���ּ���.\n");
				continue;
			}

			printf("å �˻�\n");
			printf("------------\n");

			SearchBook(book_info, total_book);	//�˻� �Լ� ȣ��

			break;

		case 3:
			if (total_book == 0)	//å�� �߰����ߴµ� �˻��� ó��ȭ������
			{
				printf("�߰��� å�� �����ϴ�. å �߰� ���� ���ּ���.\n");
				continue;
			}

			printf("å ����\n");
			printf("------------\n");

			BorrowBook(book_info, total_book);	//���� �Լ� ȣ��

			break;
		case 4:
			if (total_book == 0)	//å�� �߰����ߴµ� �˻��� ó��ȭ������
			{
				printf("�߰��� å�� �����ϴ�. å �߰� ���� ���ּ���.\n");
				continue;
			}

			printf("å �ݳ�\n");
			printf("------------\n");

			ReturnBook(book_info, total_book);	//�ݳ� �Լ� ȣ��

			break;
		case 5:
			printf("�ý��� ����\n");	//�ý��� ����
			
			// ��ü �޸� ����
			for (int i = 0; i < total_book; i++) {
				free(book_info[i].name);
				free(book_info[i].publ);
				free(book_info[i].auth);
			}
			free(book_info);
			printf("------------\n");
			return 0;

		default:
			printf("�߸� �Է� �ϼ̽��ϴ�.\n");
			break;
		}
	
	}
	return 0;
}
//å �߰� �Լ� 
void RegisterBook(book* book_info, int total_book)
{
	char buffer[1024];	// �ӽ� ����

	//å ������ �Է¹޾� ����ü(book_info)�� ����
	printf("å ���� : ");
	scanf("%s", buffer);

	book_info[total_book].name = (char*)malloc(strlen(buffer)+1);	//�޸� ���� �Ҵ� (����)
	if (book_info[total_book].name == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return ;
	}
	strcpy(book_info[total_book].name, buffer);	// �Է¹��� å ������ �޸� ������ ����

	memset(buffer, 0, 1024); // �Է¹����� �ʱ�ȭ 
	printf("å ���ǻ� : ");
	scanf("%s", buffer);

	book_info[total_book].publ = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ� (���ǻ�)
	if (book_info[total_book].publ == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	strcpy(book_info[total_book].publ, buffer);	// �Է¹��� å ���ǻ縦 �޸� ������ ����

	memset(buffer, 0, 1024);
	printf("å ���� : ");
	scanf("%s", buffer);

	book_info[total_book].auth = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ� (����)
	if (book_info[total_book].auth == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	strcpy(book_info[total_book].auth, buffer);	// �Է¹��� å ���ڸ� �޸� ������ ����


	book_info[total_book].idx = total_book + 1;
	book_info[total_book].borrow = 1;
	printf("------------\n");
}
void SearchBook(book* book_info, int total_book)
{
	int match = 0;
	char *search;
	char buffer[1024];
	int found = 0;	//å�� �ִ��� ������ üũ �� ����
	int menu = 0;

	printf("1 : ���� ��ġ\n2 : �κ� ��ġ\n");
	scanf("%d", &match);
	
	if (match == 1)
	{
		memset(buffer, 0, 1024);
		printf("���� ��ġ ����\n");
		printf("------------\n");
		printf("å ���� �Է� : ");
		scanf("%s", buffer);

		search = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ�
		if (search == NULL)
		{
			printf("�޸� �Ҵ� ����\n");
			return;
		}
		strcpy(search, buffer);	// �Է¹��� �˻��� ������ �޸� ������ ����

		//strcmp ������ġ�� å ���� ���
		for (int i = 0; i < total_book; i++)
		{
			if ((strcmp(book_info[i].name, search) == 0 ||
				strcmp(book_info[i].publ, search) == 0 ||
				strcmp(book_info[i].auth, search) == 0) &&
				book_info[i].borrow == 1)
			{
				printf("------------\n");

				printf("å ���� : %s\n", book_info[i].name);
				printf("å ���ǻ� : %s\n", book_info[i].publ);
				printf("å ���� : %s\n", book_info[i].auth);
				printf("%d�� å\n", book_info[i].idx);
				printf("���� ����\n");

				printf("------------\n");

				found = 1;
			}
		}
		if (!found)
		{
			printf("ã�� �� �����ϴ�.\n");
			free(search);	//��ã���� �ٷ� �޸� ����
			return;
		}
		free(search);
	}
	else if (match == 2)
	{
		memset(buffer, 0, 1024);	
		printf("�κ� ��ġ ����\n");
		printf("------------\n");

		printf("1 : ����\n2 : ���ǻ�\n3 : ����\n");
		scanf("%d", &menu);

		printf("------------\n");

		//1 : å ���� 2 : ���ǻ� 3 : ����
		//strstr :� ���ڿ� �ȿ� Ư�� �κ� ���ڿ��� ���ԵǾ� �ִ��� (��ã���� NULL ã���� �ּ� ��ȯ)
		switch (menu)
		{
		case 1 :
			printf("å ���� �Է� : ");
			scanf("%s", buffer);

			search = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ�
			if (search == NULL)
			{
				printf("�޸� �Ҵ� ����\n");
				return;
			}
			strcpy(search, buffer);	// �Է¹��� �˻��� ������ �޸� ������ ����

			for (int i = 0; i < total_book; i++)
			{
				if (strstr(book_info[i].name, search) != NULL && book_info[i].borrow==1)
				{
					printf("------------\n");

					printf("å ���� : %s\n", book_info[i].name);
					printf("å ���ǻ� : %s\n", book_info[i].publ);
					printf("å ���� : %s\n", book_info[i].auth);
					printf("%d�� å\n", book_info[i].idx);
					printf("���� ����\n");

					found = 1;
				}
			}
			if (!found)
			{
				printf("ã�� �� �����ϴ�.\n");
			}
			free(search);
			printf("------------\n");
			break;
		case 2 :
			printf("å ���ǻ� �Է� : ");
			scanf("%s", buffer);

			search = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ� 
			if (search == NULL)
			{
				printf("�޸� �Ҵ� ����\n");
				return;
			}
			strcpy(search, buffer);
			for (int i = 0; i < total_book; i++)	//�Է¹��� �˻��� ������ �޸� ������ ����
			{
				if (strstr(book_info[i].publ, search) != NULL && book_info[i].borrow == 1)
				{
					printf("------------\n");

					printf("å ���� : %s\n", book_info[i].name);
					printf("å ���ǻ� : %s\n", book_info[i].publ);
					printf("å ���� : %s\n", book_info[i].auth);
					printf("%d�� å\n", book_info[i].idx);
					printf("���� ����\n");
							
					found = 1;
				}
			}
			if (!found)
			{
				printf("ã�� �� �����ϴ�.\n");
			}
			free(search);
			printf("------------\n");
			break;
		case 3 :
			printf("å ���� �Է� : ");
			scanf("%s", buffer);

			search = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ�
			if (search == NULL)
			{
				printf("�޸� �Ҵ� ����\n");
				return;
			}
			strcpy(search, buffer);	// �Է¹��� �˻��� ������ �޸� ������ ����

			for (int i = 0; i < total_book; i++)
			{
				if (strstr(book_info[i].auth, search) != NULL && book_info[i].borrow == 1)
				{
					printf("------------\n");

					printf("å ���� : %s\n", book_info[i].name);
					printf("å ���ǻ� : %s\n", book_info[i].publ);
					printf("å ���� : %s\n", book_info[i].auth);
					printf("%d�� å\n", book_info[i].idx);
					printf("���� ����\n");

					found = 1;
				}
			}
			if (!found)
			{
				printf("ã�� �� �����ϴ�.\n");
			}
			printf("------------\n");
			free(search);
			break;
		default:
			printf("�߸����Է�. ó������ ���ư��ϴ�.\n");
			break;
		}
	}
}
//���� �Լ� 
void BorrowBook(book* book_info, int total_book)
{
	int choice = 0;
	int idx = 0;

	printf("1 : å ��ȣ ��ȸ\n2 : ����\n");
	scanf("%d", &choice);

	// 1. å ��ȣ ��ȸ(�˻� ��� ��� �� ��ȣ �Է�) �Ǵ� 
	// 2. �ٷ� å ��ȣ �Է��� ���� ���� ó��.

	if (choice == 1)
	{
		SearchBook(book_info, total_book);	//å ���� �˻�

		printf("������ å ��ȣ �Է� : ");
		scanf("%d", &idx);

		if (idx < 1 || idx >total_book)
		{
			printf("�߸��� ��ȣ �Դϴ�.");
			return;
		}
		//������ å�� ���� �����ϸ� ���� ó��, �ƴϸ� �ȳ�
		if (book_info[idx - 1].borrow == 1)
		{
			printf("%d�� å ���� �Ϸ�\n", idx);
			book_info[idx - 1].borrow = 0;
		}
		else
			printf("�̹� ���� ��å\n");
		return;
	}
	else if (choice == 2)
	{
		printf("������ å ��ȣ �Է� : ");
		scanf("%d", &idx);

		if (idx < 1 || idx >total_book)
		{
			printf("�߸��� ��ȣ �Դϴ�.");
			return;
		}
		//������ å�� ���� �����ϸ� ���� ó��, �ƴϸ� �ȳ�
		if (book_info[idx - 1].borrow == 1)
		{
			printf("%d�� å ���� �Ϸ�\n", idx);
			book_info[idx - 1].borrow = 0;
		}
		else
			printf("�̹� ���� ��å\n");
		return;

	}
}
void ReturnBook(book* book_info, int total_book)
{
	int idx = 0;
	int choice = 0;

	printf("1 : ��ȣ ��ȸ\n 2 : �ݳ�\n");
	scanf("%d", &choice);

	// 1. å ��ȣ ��ȸ(�˻� ��� ��� �� ��ȣ �Է�) �Ǵ� 
	// 2. �ٷ� å ��ȣ �Է��� ���� �ݳ� ó��.
	if (choice == 1)
	{
		SearchBook(book_info, total_book);	//å ���� �˻�

		printf("�ݳ��� å ��ȣ �Է� : ");
		scanf("%d", &idx);
		if (idx < 1 || idx >total_book)
		{
			printf("�߸��� ��ȣ �Դϴ�.");
			return;
		}
		//������ å�� �ݳ� �����ϸ� �ݳ� ó��, �ƴϸ� �ȳ�
		if (book_info[idx - 1].borrow == 0)
		{
			printf("%d�� å �ݳ� �Ϸ�\n", idx);
			book_info[idx - 1].borrow = 1;
		}
		else
			printf("�̹� �ݳ� ��å\n");
		return;
	}
	else if (choice == 2)
	{
		printf("�ݳ��� å ��ȣ �Է� : ");
		scanf("%d", &idx);

		if (idx < 1 || idx >total_book)
		{
			printf("�߸��� ��ȣ �Դϴ�.");
			return;
		}
		//������ å�� �ݳ� �����ϸ� �ݳ� ó��, �ƴϸ� �ȳ�
		if (book_info[idx - 1].borrow == 0)
		{
			printf("%d�� å �ݳ� �Ϸ�\n", idx);
			book_info[idx - 1].borrow = 1;
		}
		else
			printf("�̹� �ݳ� ��å\n");
		return;
	}
}