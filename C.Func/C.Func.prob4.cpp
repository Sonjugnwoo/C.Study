//���� 4 ,Ư���� �� N �� �Է¹޾Ƽ� N �� ���μ������� ����� ��µǰ� �غ�����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
void PF(int num);

int main()

{
	int input_num;
	// N�� �Է� �� ��ȿ�� �˻� 
	printf("N�� �Է� : ");
	scanf("%d", &input_num);
	if (input_num <= 1) 
	{
		printf("���μ����� ����� �����ϴ�.\n");
		return 0;
	}

	printf("%d ���μ� ���� : ", input_num);  //��� ���
	PF(input_num); // �Լ� ȣ��
	return 0;
}
// ���μ� ���� �Լ� 
void PF(int num)
{
	while (num != 1)
	{
		for (int i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{		
				printf("%d", i); // ���μ� ��� 
				num /= i; // ������ ����
				if (num != 1) printf(" * ");  // num == 1 �Ͻ�  * �����
				break;  // ���� ���μ� ã��
			}
		}
	}
}