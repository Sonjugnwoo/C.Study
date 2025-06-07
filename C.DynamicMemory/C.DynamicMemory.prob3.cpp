// ���� 3 ,  �������� �Ҵ�� �迭�� ũ�⸦ �ٽ� �ٲٴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�Լ� ���� 
void Change(int** old, int size_1);	//�迭 ũ�� ���� �Լ� 

int main()
{
	int size_1;

	printf("�Ҵ��� ũ�⸦ �Է� : ");
	scanf("%d", &size_1);

	//�޸� ���� �Ҵ� 
	int* old = (int*)malloc(sizeof(int) * size_1);
	if (old == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	// Ȯ�ο� �� �Է�
	printf("�ʱ� �迭: ");
	for (int i = 0; i < size_1; i++) 
	{
		old[i] = i;
		printf("%d ", old[i]);
	}
	printf("\n");
	
	// �Լ� ȣ�� 
	Change(&old, size_1);	// ���� �����ͷ� �����ؾ� ���� �Ҵ��� �迭���ּҰ� �Ѿ
	free(old);
	return 0; 
}
//ũ�� ���� �Լ� 
void Change(int **old,int size_1)	// ���� �����ͷ� �����ؾ� ���� �Ҵ��� �迭���ּҰ� �Ѿ
{
	int size_2;

	printf("�ٲ� ũ�� �Է� : ");
	scanf("%d", &size_2);

	//���� �޸� �Ҵ� 
	int* arr = (int*)malloc(sizeof(int) * size_2);
	if (arr == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		free(*old);
		return ;
	}
	//���ο� �迭�� ũ�Ⱑ ���� �迭�� ���� 
	int len = size_1 < size_2 ? size_1 : size_2;
	for (int i = 0; i < len; i++)
	{
		arr[i] = (*old)[i];
	}
	//���� ���� ä��� 
	for (int i = len; i < size_2; i++)
	{
		arr[i] = i;
	}
	//�� �迭 �Ҵ� ����
	free(*old);
	//�� �迭�� ���� 
	*old = arr;

	//��� ��� 
	printf("ũ�� ���� �� �迭: ");
	for (int i = 0; i < size_2; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}