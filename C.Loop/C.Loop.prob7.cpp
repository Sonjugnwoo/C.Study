// ���� 7 , ������ �ڿ��� N �� �Է� �޾� N �� ���μ� ���� �� ����� ����Ͽ���.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int input_num = 0;
	// ������ �ڿ��� input_num �Է�
	while (1)
	{
		printf("�ڿ��� �Է� : ");
		scanf("%d", &input_num);

		// ���� �� 0 �Ͻ� �ٽ� �Է� 
		if (input_num < 0) printf("���� �Դϴ�, �ٽ� �Է����ּ���.\n");
		else if (input_num == 0) printf("0�� ��� �Ұ� \n");
		else if (input_num == 1) printf("1�� ���μ����� X\n");
		else
			break;  // 2 �̻� �ڿ��� �Է� �� �ݺ� ���� 
	}

	printf("%d �� ���μ� ���� : ", input_num);

	//���μ� ���� ����
	while (input_num != 1)
	{
		for (int i = 2; i <= input_num; i++)
		{
			if (input_num % i == 0)
			{
				printf("%d", i);   //���μ� ���
				input_num /= i;    //������ ����
				if (input_num != 1) printf(" * ");  // �������� * �����
				break; // ���� ���μ� ã��
			}
		}
	}
	return 0;
}