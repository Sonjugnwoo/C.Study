// ���� 3, ���̰� �ִ� 100 �� ���ڿ��� �Է� �޾Ƽ� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ����ϴ� �Լ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ�����
void Change(char str[]);	//��ҹ��� ���� 

int main()
{
	char str[101];	//���ڿ� ����  100 ���� + NULL �ڸ� 

	//���ڿ� �Է� 
	printf("���ڿ� �Է� : ");
	scanf("%s", str);

	//�Լ� ȣ��
	Change(str);

	return 0;
}
//��ҹ��� ���� �Լ�
void Change(char *str)
{
	//���ڿ� ���� ��� 
	int len = strlen(str);

	//��ҹ��� �����
	for (int i = 0; i < len; i++)
	{
		// �ҹ��� -> �빮��
		if (str[i] >= 'a' && str[i] <='z')
			str[i] -= 32;
		// �빮�� -> �ҹ���
		else if (str[i]>='A' && str[i] <= 'Z')
			str[i] += 32;
		// ���ĺ� �ƴϸ� ��ȯ X
	}

	//��� ���
	printf("%s", str);
}