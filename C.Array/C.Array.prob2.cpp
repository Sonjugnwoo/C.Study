//���� 2 ,�Է¹��� �л����� ������ ���� �׷����� ��Ÿ���� ���α׷��� ����� ������.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main()
{
    int student_score[SIZE];   //  ���� �迭
    int student_index[SIZE];   // �л� ��ȣ(�Է� ����) �迭 
    int i = 0;
    // ���� �Է� �� ��ȿ�� �˻�
    while (i != SIZE)
    {
        printf("%d �� �л� ���� �Է� : ", i + 1);
        scanf("%d", &student_score[i]);
        if (student_score[i] < 0 || student_score[i] > 100)
        {
            printf("�ٽ��Է�\n");
            continue;
        }
        student_index[i] = i + 1;  //�Է� ������� �л� ��ȣ ����
        i++;
    }

    //���� ���ķ� �������� ����
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (student_score[j] > student_score[j+1])
            {
                // ���� ��ȯ
                int temp = student_score[j];
                student_score[j] = student_score[j + 1];
                student_score[j + 1] = temp;
                // �л� ��ȣ(�Է� ���� ) ��ȯ
                int index = student_index[j];
                student_index[j] = student_index[j + 1];
                student_index[j + 1] = index;
            }
        }
    }
    // ��� ���
    printf("�л����� ���� ��������\n");
    for (int i = SIZE-1; i >=0; i--)  // �������� �����߱� ������ �Ųٷ� ���
    {
        printf("\n-----------------------\n");
        printf("%d �� �л� : %d��\n", student_index[i], student_score[i]);
        for (int j = 0; j < student_score[i]; j++)
            printf("��"); // �׷��� ���
    }
    return 0;
}