// ���� 4,  �� ���� ���ڿ��� �Է� �޾Ƽ� ���ٸ� "����", �ٸ��� "�ٸ���" ��� ����ϴ� �Լ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ�����
void Equl(char* str_a, char* str_b);	// ���ڿ� �� �Լ� 

int main()
{
	// ���ڿ� ���� �迭
	char str_a[100];
	char str_b[100];

	//���ڿ� �Է� 
	printf("���ڿ� �Է� : ");
	scanf("%s", str_a);
	printf("���ڿ� �Է� : ");
	scanf("%s", str_b);

	//�Լ� ȣ��
	Equl(str_a, str_b);

	return  0;
}
//���ڿ� �� �Լ� 
void Equl(char *str_a, char* str_b)
{
	//strcmp�� 0 �� ��ȯ�ϸ� ���ڿ��� �Ȱ��� .
	if (strcmp(str_a, str_b) == 0) 
		printf("����");
	else
		printf("�ٸ���");
}