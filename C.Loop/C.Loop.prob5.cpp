// ���� 5 , ����ڷ� ���� N ���� �Է� �ް� 1 ���� N ������ ���� ����Ѵ�. (factorial)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int input_num = 0;
	int mul = 1;
	printf("����� ���� �Է� :");
	scanf("%d", &input_num);   // �� �Է� ����
	if (input_num == 0) return 1;
	for (int i = 1; i <= input_num; i++)   // 1 ���� input_num ���� �ݺ�
	{
		mul *= i;	//   1���� input_num ���� ���ϱ� ex)1 * 2 * 3 * 4 ...
	}
	printf("��� : %d", mul);  // ��� 
	return 0;
}


// long long �Լ� ���� ���� ����
