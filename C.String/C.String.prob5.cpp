//	���� 5, ���ڿ��� �� �� �Է� �޾Ƽ� ���� �Է¹��� ���ڿ����� ���߿� �Է¹��� ���ڿ��� ��ġ�� �˻��ϴ��Լ�
//	���� ���ٸ� - 1 �� �����ϰ� �ִٸ� �� ��ġ�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ� ���� 
int Search(char* str_a, char* str_b);	//���ڿ� ã�� �Լ� 

int main()
{
	// ���ڿ� ���� �迭
	char str_a[100];
	char str_b[100];

	//���ڿ� �Է� 
	printf("���ڿ� �Է� : ");
	scanf("%s", str_a);
	printf("���ڿ� �Է� : ");
	scanf("%s", str_b);

	//������ �� �Լ� ȣ��
	printf("%d�� �ε��� ",Search(str_a, str_b));

	return 0;

}
// ���ڿ� ã�� �Լ� 
int Search(char* str_a, char* str_b)
{
	// �� ���ڿ� ���� ���
	int len_1 = strlen(str_a);
	int len_2 = strlen(str_b);

	// idx �� len_2 �� ���� ������ ���ٰ� �Ǻ�
	for (int i = 0; i <=len_1-len_2; i++)
	{
		int idx = 0;	// ��� 0���� �ʱ�ȭ 
		for (int j = 0; j < len_2; j++)
		{
			if (str_a[i+j] == str_b[j])
			{
				idx++;	// ������  1������
			}
		}
		if (idx == len_2) return i;	// ���� �ε��� ��ȯ
	}
	return -1;	//������ -1 ��ȯ 
}