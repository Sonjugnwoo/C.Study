//���� 3 , �Ҽ�  1000��ã�Ƽ� �迭�� �ֱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	int prime[1000];   // �Ҽ� ���� �迭
	prime[0] = 2;      //  ù��° �ι�° �Ҽ� 2 , 3 �迭�� ����
	prime[1] = 3;
	int prime_number = 5; //�Ҽ� �����ƴ��� �Ǻ��� �� 
	int index = 2;	  // �迭 �ε���

	// �Ҽ� �Ǻ� �� �迭 ����
	while (index < 1000)  //1000�� �Ҽ� ã��������
	{
		int count = 0;
		for (int i = 0; i < index; i++)
		{
			if (prime_number % prime[i] != 0) count++;  // ������ �������������� count ++
			else break;	//������ �������� �Ҽ� X
		}
		if (count == index)
		{
			prime[index] = prime_number;
			index++;
		}
		prime_number += 2;
	}
	// ��� ��� 
	for (int i = 0; i < index; i++)
	{
		printf("�Ҽ� :%d\n", prime[i]);
	}
	return 0;
}