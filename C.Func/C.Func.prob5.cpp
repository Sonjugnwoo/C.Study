//���� 5 , 10 ���� ���ҵ� �� �ִ밪 ���ϴ� �Լ��� �̿��Ͽ�, 10 ���� ���Ҹ� �Է� �ް� �� ���Ҹ� ū ������ ����ϴ� �Լ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

//�Լ�����
void SelectionSort(int* num);
int MaxIndex(int* num,int start);

int main()
{
	int num[SIZE];   // �� �Է� ���� �迭 
	printf("10���� �� �Է�\n");
	for (int i = 0; i < SIZE; i++)  // �� 10�� �Է� 
	{		
		printf("%d��° �� : ", i + 1);  //�� ��ȣ üũ
		scanf("%d",&num[i]);	}
	SelectionSort(num);  // �Լ� ȣ��
	return 0;
}
// Maxidx ã�� �Լ� 
int MaxIndex(int* num,int start)
{
	int max_index = start;  // 
	for (int i = start+1; i < SIZE; i++)
	{
		if (num[max_index] < num[i]) max_index = i;
	}
	return max_index; // Maxidx ��ȯ
}
//���� ���� 
void SelectionSort(int* num)
{
	for (int i = 0; i < SIZE; i++)
	{
		int max_idx = MaxIndex(num,i);

		int temp = num[i];
		num[i] = num[max_idx];
		num[max_idx] = temp;
	}
	//��� ��� 
	printf("�������� ��� : ");
	for (int i = 0; i < SIZE; i++) 
		printf("%d\n", num[i]);
}