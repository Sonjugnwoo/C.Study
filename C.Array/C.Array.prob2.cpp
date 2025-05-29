//문제 2 ,입력받은 학생들의 성적을 막대 그래프로 나타내는 프로그램을 만들어 보세요. (버블정렬)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main()
{
    int student_score[SIZE];   //  점수 배열
    int student_index[SIZE];   // 학생 번호(입력 순서) 배열 
    int i = 0;
    // 점수 입력 및 유효성 검사
    while (i != SIZE)
    {
        printf("%d 번 학생 점수 입력 : ", i + 1);
        scanf("%d", &student_score[i]);
        if (student_score[i] < 0 || student_score[i] > 100)
        {
            printf("다시입력\n");
            continue;
        }
        student_index[i] = i + 1;  //입력 순서대로 학생 번호 저장
        i++;
    }

    //버블 정렬로 오름차순 정리
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (student_score[j] > student_score[j+1])
            {
                // 점수 교환
                int temp = student_score[j];
                student_score[j] = student_score[j + 1];
                student_score[j + 1] = temp;
                // 학생 번호(입력 순서 ) 교환
                int index = student_index[j];
                student_index[j] = student_index[j + 1];
                student_index[j + 1] = index;
            }
        }
    }
    // 결과 출력
    printf("학생들의 성적 내림차순\n");
    for (int i = SIZE-1; i >=0; i--)  // 오름차순 정리했기 문에 거꾸로 출력
    {
        printf("\n-----------------------\n");
        printf("%d 번 학생 : %d점\n", student_index[i], student_score[i]);
        for (int j = 0; j < student_score[i]; j++)
            printf("■"); // 그래프 출력
    }
    return 0;
}
