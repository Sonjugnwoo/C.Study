//���� 2 ,  1 ���� n ������ ���� ���ϴ� �Լ��� �ۼ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ����� 
int Sum(int num);
int Sum2(int num);

int main()
{
	int input_num; //N��
	printf("N�� �Է� :");
	scanf("%d", &input_num);

	printf("1�� sum ȣ��\n1 ~ %d �� �� : %d\n", input_num, Sum(input_num));  //��� ���
	printf("2�� sum ȣ��\n1 ~ %d �� �� : %d\n", input_num, Sum2(input_num));
	return 0;
}

//1 ~ num ������ ��
int Sum(int num)
{
	int sum = 0;
	for (int i = 1; i <= num; i++)
	 sum += i;
	return sum;
}
// 1~ num �� ���ϴ� �ٸ� ����
int Sum2(int num)
{
	return num * (num + 1) / 2;
}