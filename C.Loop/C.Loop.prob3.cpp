// ���� 3 , 1000������ 3 or 5�� ����� �ڿ��� �� ���ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num = 1000;
	int sum = 0;
	for (int i = 1; i <= num; i++)  //���� ����
	{
		if (i % 3 == 0 || i % 5 == 0)  // 3 or 5 �� ��� �Ǻ�
		{
			sum += i;   // �Ǻ� �ؼ� sum�� ��� ���ϱ�
		}
	}
	printf("%d", sum);

	return 0;
}