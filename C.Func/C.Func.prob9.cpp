//���� 9 , �ڱ� �ڽ��� ȣ���ϴ� �Լ��� �̿��ؼ� 1 ���� Ư���� �������� ���� ���ϴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
int Factorial(int num);

int main()
{
	int input_num;	// �Է� ���� ��
	printf("N�� �Է� : ");
	scanf("%d", &input_num);

	//��� ���
	printf("%d! : %d", input_num,Factorial(input_num));
	return 0;
}
//���丮�� �Լ� (��� ȣ��)
int Factorial(int num)
{
	if (num == 1) return 1;	//  ��� ���� ����
	return num * Factorial(num - 1);	// ��� ȣ��
}
