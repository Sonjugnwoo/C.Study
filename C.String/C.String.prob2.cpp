// ���� 2, ���̰� �ִ� 100 �� ���ڿ��� �ϳ� �Է� �޾Ƽ� ���ڿ��� �������� ����ϴ� �Լ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ�����
void Reverse(char* str);	//���ڿ� ������ �Լ� 

int main()
	{
		char str[101];	//���ڿ� ����  100 ���� + NULL �ڸ� 

	//���ڿ� �Է� 
	printf("���ڿ� �Է� : ");
	scanf("%s", str);

	//�Լ� ȣ��
	Reverse(str);

	return 0;
}
//������ �Լ� 
void Reverse(char *str)
{
	int len = 0;

	//���� ���ڿ� ���� ���
	while (str[len] != '\0') len++;	

	//���ڿ��� �հ� �ڸ� ��ȯ�Ͽ� ������ 
	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	//��� ���
	printf("%s", str);
}