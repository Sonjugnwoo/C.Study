//���� 3 ,  N ���� �Է� �޾Ƽ� 1 ���� N ������ �Ҽ��� ������ ����ϴ� �Լ� �ۼ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
int PrimeCount(int num);

int main()
{
	int input_num;
	printf("N�� �Է� : ");
	scanf("%d", &input_num);

	printf("1 ~ %d ���� �Ҽ� ���� : %d",input_num, PrimeCount(input_num));  //��� ���
	return 0;
}
// �Ҽ� ���� Ȯ��
int PrimeCount(int num)
{
	int count = 0;  // �Ҽ� ����
	for (int i = 2; i <=num; i++)
	{
		int prime_check = 0; 
		for (int j = 2; j*j <=i; j++)
		{
			if (i % j == 0)  // ������ �������� �Ҽ��� �ƴ� 
			{
				prime_check = 1;
				break;
			}
		}
		if (prime_check== 0)	count++;
		
	}
	return count;
}