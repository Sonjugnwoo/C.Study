// ���� 6 , ���� ���� �����ϴ� �ڿ��� a,b,c �� ������ ���Ͽ���
//  i)	a + b + c = 2000
//	ii)	a �� b > c, a, b, c �� ��� �ڿ���

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int count = 0;   // �����ϴ� (a,b,c) ������ ����  
	// a > b > c  ����, a = 1997, b = 2,c = 1 ���� ���� 
	for (int a = 1997; a > 667; a--)   // a : 1997 ~ 668 ���� �ݺ�   (668,667,665) 
	{
		for (int b = 2; b < a; b++) // b : 2 ~ a �� ���� �ݺ�
		{
			int c = 2000 - b - a;
			if (c > 0 && b > c)	 count++;   // ���� �ش�� count 1 ���� 
		}
	}
	printf("�� ������ �����ϴ� (a,b,c) ���� : %d", count); // ��� ���
	return 0;
}