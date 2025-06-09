// ���� 2,  prob2.txt �� ��� �� ���� ��� �ִµ�, �� ���� �Է� �޾Ƽ� Ư���� ���ڿ��� �˻��ϴ� ���α׷�
// test.txt ���� : Learning step by step, I build new skills every day. Consistent effort and curiosity make progress possible.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//���ڿ� ���� �迭 
	char buffer[1024];	
	char* search;

	int ch;
	int idx = 0;
	int count = 0;
	int found = 0;

	FILE* fp = fopen("D:\\study\\prob2.txt", "r+");	//���� ���� r+ : �б� ���� 
	if (fp == NULL)
	{
		printf("������ �� �� �����ϴ�.\n");
		return 1;
	}

	printf("ã�� ���ڿ� : ");
	scanf("%s", buffer);

	search = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ�
	if (search == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}
	strcpy(search, buffer);	//�Է¹��� �� ���� 

	int len = strlen(search);	//���ڿ� ���� ���� 

	//���ڿ� ��ȸ �ϸ� �Է°��̶� ������ �˻� 
	//fgetc : �� ���� �� �о�ͼ� int ������ ��ȯ (�ƽ�Ű �ڵ�)
	//EOF  : �����̳� �Է� ��Ʈ���� ���� ��Ÿ���� Ư���� ��
	while ((ch = fgetc(fp)) != EOF)
	{
		count++;
		if (ch == search[idx])	//���ڰ� ��ġ �ҽ� idx �������� ���� ���ڷ� �̵� 
		{
			idx++;
			if (idx == len)
			{
				found = 1;	//ã���� 1 ��ã���� 0
				fclose(fp);	//���� �ݱ�
				free(search);	//�޸� ����
				printf("%d", count- len+1);	//�������� ��� 
				return 0;	//����
			}
		}
		else
			idx = 0;		//�ƴҽ� �ٽ� 0 
	}
	// ��ã������ �ȳ� �� ���� �ݱ� , �޸� ����
	if (!found)
	{
		fclose(fp);
		free(search);
		printf("ã�����߽��ϴ�.");
	}

	return 0;
}