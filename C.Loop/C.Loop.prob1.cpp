//���� 1 , �Է°��� �޾� �Է°��� ũ�⸦ ���� �ﰢ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int temp = 0;
	printf("�ﰢ�� ũ�� �Է� : ");
	scanf("%d", &temp);

	for (int i = 1; i <= temp; i++)  // �ﰢ�� ũ��  ( �� )
	{
		for (int j = 0; j < temp - i; j++)  // ���� ���
		{
			printf(" ");
		}
		for (int k = 0; k < (2 * i) - 1; k++) // �ﰢ�� �׸��� 
		{
			printf("@");
		}
		printf("\n");
	}
	return 0;
}