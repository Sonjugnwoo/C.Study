//���� 6 , 2 ���� �迭�� �� ���ҿ� 1 �� ���ϴ� �Լ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ�����
void ArrAdd(int arr[][5]);
void ArrAdd2(int (*arr)[5]);

int main()
{
	int arr[2][5] = { {2,3,5,6,7 },{4,6,1,2,6,} };  // 2���� �迭 ����

	// �迭 ���� ���
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("arr[%d][%d] = ", i, j);
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	printf("ù��° ��� (�迭 ǥ���) ------------------\n");
	ArrAdd(arr);
	printf("�ι�° ��� (������ ǥ���) ------------------\n");
	ArrAdd2(arr);
	return 0;
}
//�迭 ǥ��
void ArrAdd(int arr[][5])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] += 1;
			printf("arr[%d][%d] = ", i, j);		//��� ���
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}

}
//������ ǥ��
void ArrAdd2(int (*arr)[5])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] += 1;
			printf("arr[%d][%d] = ", i, j); 	//��� ���
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}