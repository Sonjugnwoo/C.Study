//���� 7 , ����ڷ� ���� 5 ���� �л��� ����, ����,���� ������ �Է� �޾Ƽ� ����� ���� ���� ��� ���� ����� ���� ���� ������� ���ĵǾ� ���
// Ư������� �������� ��� �̻��� ��� ������ '�հ�', �ƴ� ����� '���հ�' �� ���

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

 //�Լ� ����
int Ave(int start, int* k_score, int* m_score, int* e_score);
void SeletionSort(int* ave, int* student_idx);
void Pass(int* ave, int* student_idx);

int main()
{
	int k_score[SIZE];	// ���� ���� �迭
	int m_score[SIZE];	// ���� ���� �迭
	int e_score[SIZE];	// ���� ���� �迭
	int ave[SIZE];		// ��� ���� �迭
	int student_idx[SIZE];	// �л� ��ȣ (�Է� ��) �迭

	// ���� �Է� �� ��ȿ�� �˻�(0~100) ����
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d �� �л� \n", i + 1);
		printf("���� : ");
		scanf("%d", &k_score[i]);
		if (k_score[i] < 0 || k_score[i] >100)
		{
			printf("0~100���̷� �Է����ּ���.\n");
			i--;
			continue;
		}
		printf("���� : ");
		scanf("%d", &m_score[i]);
		if (m_score[i] < 0 || m_score[i] >100)
		{
			printf("0~100���̷� �Է����ּ���.\n");
			i--;
			continue;
		}
		printf("���� : ");
		scanf("%d", &e_score[i]);
		if (e_score[i] < 0 || e_score[i] >100)
		{
			printf("0~100���̷� �Է����ּ���.\n");
			i--;
			continue;
		}
		printf("------------------\n");
		ave[i] = Ave(i, k_score, m_score, e_score);	//��� ����� ��� �迭�� �� �Է�
		student_idx[i] = i+1;	//�л� ��ȣ �迭�� �� �Է�
	}

	SeletionSort(ave, student_idx);	//�������� > �������� ����
	Pass(ave, student_idx);	//�հ� ���հ� �Լ� ȣ��
	return 0;
}
// ��� ���ϴ� �Լ�
int Ave(int start , int *k_score, int *m_score, int *e_score)
{
	int sum = k_score[start] + m_score[start] + e_score[start];
	return sum / 3;	//��� �� ��ȯ
}
//���� ���� �Լ� (��������)
void SeletionSort(int *ave, int* student_idx)
{
	for (int i = 0; i < SIZE-1; i++)
	{
		int max_idx = i;
		for (int j = i+1; j < SIZE; j++)
		{
			if (ave[max_idx] < ave[j])
				max_idx = j;

		}
		// ���� ����
		int temp = ave[i];
		ave[i] = ave[max_idx];
		ave[max_idx] = temp;
		// �л� ��ȣ ����
		int idx = student_idx[i];
		student_idx[i] = student_idx[max_idx];
		student_idx[max_idx] = idx;
	}
}
// �հ� ���հ� Ȯ�� �Լ�
void Pass(int* ave,int * student_idx)
{
	int pass = 0;
	// ��ü �л� ��� ���
	for (int i = 0; i < SIZE; i++)
	{
		pass += ave[i];
	}
	pass /= SIZE; // ��ü �л� ���

	printf("��� ���� : %d\n", pass);
	printf("------------------\n");

	//��� ��� 
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d�� �л� : ��� %d\n", student_idx[i], ave[i]);
		if (ave[i] >= pass)
		{

			printf("�հ�\n");
		}
		else printf("���հ�\n");
		printf("------------------\n");
	}
}