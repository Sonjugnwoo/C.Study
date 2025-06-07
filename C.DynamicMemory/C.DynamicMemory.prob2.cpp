// ���� 2 ,  �л��� ����� ���� �л��� ����� ����ϴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�Լ� ���� 
void ScoreAve(int** student, int subject, int students);	//��� ����
void ScoreRank(int* sum,int students);	//���

int main()
{
	//���� ���� 
	int score;
	int subject, students;

	//student[students][subject] ���� 
	int **student;

	// �� �Է� �� ��ȿ�� �˻� 
	printf("���� �� : ");
	scanf("%d", &subject);
	printf("�л� �� : ");
	scanf("%d", &students);
	if (subject <= 0 || students <= 0) {
		printf("�л� ���� ���� ���� 1 �̻��̾�� �մϴ�.\n");
		return 1;
	}

	printf("--------------\n");

	//���� �޸� �Ҵ� �� �Ҵ� ���� ���� ���
	student = (int**)malloc(sizeof(int*) * students);
	if (student == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}
	for (int i = 0; i < students; i++)
	{
		student[i] = (int*)malloc(sizeof(int) * subject);
		if (student[i] == NULL)
		{
			printf("�޸� �Ҵ� ����\n");
			for (int k = 0; k < i; k++) free(student[k]);
			free(student);
			return 1;
		}
	}
	//�Է� �� ��ȿ�� �˻� 
	for (int i = 0; i < students; i++)
	{
		printf("%d�� �л�\n",i + 1);

		for (int j = 0; j < subject; j++)
		{
			printf("%d���� ���� �Է� : ", j + 1);
			scanf("%d", &score);
			if (score < 0 || score >100)
			{
				printf("�����ʰ�");
				return 1;
			}
			student[i][j] = score;
		}
		printf("--------------\n");
	}


	ScoreAve(student, subject, students);	//������� �Լ� ȣ��
	
	//�޸� �Ҵ� ����
	for (int i = 0; i < students; i++)
	{
		free(student[i]);
	}
	free(student);

	return 0;
}
//��� ����
void ScoreAve(int ** student,int subject, int students)
{
	int sum = 0;
	//�Է°� ��ȿ�� �˻� 
	if (students <= 0 || subject <= 0) {
		printf("�л� ���� ���� ���� 1 �̻��̾�� �մϴ�.\n");
		return;
	}

	//���� �޸� �Ҵ� 
	int* ave = (int*)malloc(sizeof(int) * students);
	if (ave == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}

	//��� ���� ���
	for (int i = 0; i < students; i++)
	{
		sum = 0;
		for (int j = 0; j < subject; j++)
		{
			sum += student[i][j];
		}
		ave[i] = sum / subject;
	}

	ScoreRank(ave,students);//��� �Լ� ȣ��

	//�޸� �Ҵ� ����
	free(ave);
}

//��� �Լ� 
void ScoreRank(int* ave, int students)
{
	//��ȿ�� �˻� 
	if (students <= 0 || ave == NULL) {
		printf("�л� ���� 1 �̻��̾�� �ϸ�, ave �����Ͱ� ��ȿ�ؾ� �մϴ�.\n");
		return;
	}

	//���� �޸� �Ҵ�
	int* idx = (int*)malloc(sizeof(int) * students);
	if (idx==NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}

	//�л� ��ȣ �Է�
	for (int i = 0; i < students; i++)
	{
		idx[i] = i+1;
	}

	//�������� (��������) 
	for (int i = 0; i < students-1; i++)
	{
		int max_idx = i;
		{
			for (int j = i+1; j < students; j++)
			{
				if (ave[max_idx] < ave[j])
				{
					max_idx = j;
				}
			}
			// Swap ����
			int temp = ave[max_idx];
			ave[max_idx] = ave[i];
			ave[i] = temp;

			// SWap ���
			int rank = idx[max_idx];
			idx[max_idx] = idx[i];
			idx[i] = rank;

		}
	}
	//��� ��� 
	for (int i = 0; i < students; i++)
	{
		printf("%d�� �л� ��� ���� %d�� %d��\n", idx[i],ave[i],i+1);
	}

	//�޸� �Ҵ� ����
	free(idx);
}