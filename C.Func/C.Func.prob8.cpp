//���� 8 , ��Ŭ���� ȣ������ �̿��ؼ� N ���� ������ �ִ������� ���ϴ� �Լ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

//�Լ� ����
int Gcd(int a, int b);

int main()
{
	int input_num= 0 ;
	int num[SIZE];

	// N�� ���� �Է� �� ��ȿ�� �˻�
	while (1) 
	{
		printf("N�� �Է� : ");
		scanf("%d", &input_num);
		if (input_num < 1 || input_num >SIZE)
			printf("���� �ʰ�\n");
		else break;
	}

	// �� �Է� �� ��ȿ�� �˻�
	for (int i = 0; i < input_num; i++)
	{
		printf("�� �Է� : ");
		scanf("%d", &num[i]);
		if (num[i] == 0)
		{
			printf("0�� ��� �Ұ�\n");
			i--;
			continue;
		}
	}
	// ù ��° ���� ���۰����� �Ͽ� ���ʴ�� �ִ����� ���
	int gdc = num[0]; 
	for (int i = 1; i < input_num; i++)
	{
		gdc = Gcd(gdc, num[i]);
	}
	//��� ���
	printf("�ִ����� : %d", gdc);
	return 0;
}
//��Ŭ���� ȣ���
int Gcd(int a,int b)
{
	while (a % b != 0 )
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return b; //�ִ����� ��ȯ
}
