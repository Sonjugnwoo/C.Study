// ���� 3,  prob3.txt �� ���ڿ��� �Է� �޾Ƽ� reverse_prob3.txt �� �� ���ڿ��� ������ ����ϴ� ���α׷�


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	//���ڿ� ���� �迭 
	char buffer[1024];
	char* input;

	FILE* fp = fopen("D:\\study\\prob3.txt", "w+");	//���� ����   w+ : ���� �б�
	if (fp == NULL)
	{
		printf("������ �� �� �����ϴ�.\n");
		return 1;
	}


	printf("prob3.txt �� ���� ���� �Է�  : ");
	scanf("%s", buffer);

	input = (char*)malloc(strlen(buffer) + 1);	//�޸� ���� �Ҵ� 
	if (input == NULL)
	{
		printf("�޸� �Ҵ� ����");
		return 1;
	}

	strcpy(input, buffer);	// �Է¹��� ��  ����

	fputs(input, fp);	//fp �� ������ �� �ֱ� 

	int len = strlen(input);	//���ڿ� ���� ����

	FILE* fp_2 = fopen("D:\\study\\reverse_prob3.txt", "w+");	//���� ����   w+ : ���� �б�
	if (fp_2 == NULL)
	{
		printf("������ �� �� �����ϴ�.\n");
		return 1;
	}
	//���� ������� ������ 
	for (int i = 0; i < len/2; i++)
	{
		int temp = input[i];
		input[i] = input[len - 1 - i];
		input[len - 1 - i] = temp;
	}

	fputs(input, fp_2);	//fp_2 �� ������ �� �ֱ� 
	printf("reverse_prob3.txt ���� : %s", input);
	// ���� �ݱ� �� �޸� ����
	fclose(fp);
	fclose(fp_2);
	free(input);
	return 0;
}