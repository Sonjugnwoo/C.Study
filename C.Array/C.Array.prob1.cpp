//문제 1 , 입력받는 학생들의 성적을 높은 순으로 정렬하는 프로그램 (선택 정렬)
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

    // 선택정렬로 내림차순 정렬
    for (int i = 0; i < SIZE - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (student_score[j] > student_score[max_idx]) {
                max_idx = j; // 높은 점수 찾을시 max_idx 갱신;
            }
        }
        // 점수 교환
        int temp = student_score[i];
        student_score[i] = student_score[max_idx];
        student_score[max_idx] = temp;
        // 학생 번호(입력 순서 ) 교환
        int index = student_index[i];
        student_index[i] = student_index[max_idx];
        student_index[max_idx] = index;
    }

    // 결과 출력
    printf("학생들의 성적 내림차순\n");
    printf("-----------------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d 번 학생 : %d점\n", student_index[i], student_score[i]);
    }
    return 0;
}