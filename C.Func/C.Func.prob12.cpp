//���� 12 , �����佺�׳׽��� ü�� �̿��ؼ� 1 ���� N ������ �Ҽ��� ���ϴ� ���α׷�
// �����佺�׳׽��� ü :   2���� ������ Ư�� ���� ����� �������� �Ҽ��� ������ ���� ã�� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
int prime(int num);

int main()
{
	int input_num;
	//�Է� ��
	printf("N�� �Է� : ");
	scanf("%d", &input_num);

	//��� ���
	printf("\n���� : %d", prime(input_num));

	return 0;
}

//�Ƹ������ڷ����� ü
int prime(int input_num)
{
	int count = 0; // �Ҽ� ���� ���� 
	int num[100] = { 0 }; // num �迭 0 ���� �ʱ�ȭ

	for (int i = 2; i <= input_num; i++) num[i] = 1;	//���δ� �Ҽ���� �����ϰ� �迭�� �Է�
	
	//�Ƹ������ڷ����� ü �˰��� 2�ǹ�� ���� ������ Ư�� ���� ��� ���� ����  
	for (int i = 2; i *i<= input_num; i++)  //  16 = 4 * 4 ���� �̷�⶧���� ���������� �ؼ� ȿ����
	{
		if(num[i])
		for (int j = i * i; j <= input_num; j += i)
		{
			num[j] = 0;  // ������� 0���� (�Ҽ����ƴ�)
		}
	}
	// ��� ��� 
	for (int i = 0; i <= input_num; i++)
		if (num[i])
		{
			printf("�Ҽ� : %d ", i);  //���� �ִ�  ���� �ε����� �Ҽ�  
			count++; // �Ҽ� ���� ����
		}
	return count;
}