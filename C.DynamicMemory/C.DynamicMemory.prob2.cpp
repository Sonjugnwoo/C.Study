// 문제 2 ,  학생별 평균을 내어 학생의 등수를 출력하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//함수 원형 
void ScoreAve(int** student, int subject, int students);	//평균 점수
void ScoreRank(int* sum,int students);	//등수

int main()
{
	//변수 선언 
	int score;
	int subject, students;

	//student[students][subject] 선언 
	int **student;

	// 값 입력 및 유효성 검사 
	printf("과목 수 : ");
	scanf("%d", &subject);
	printf("학생 수 : ");
	scanf("%d", &students);
	if (subject <= 0 || students <= 0) {
		printf("학생 수와 과목 수는 1 이상이어야 합니다.\n");
		return 1;
	}

	printf("--------------\n");

	//동적 메모리 할당 및 할당 실패 오류 출력
	student = (int**)malloc(sizeof(int*) * students);
	if (student == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}
	for (int i = 0; i < students; i++)
	{
		student[i] = (int*)malloc(sizeof(int) * subject);
		if (student[i] == NULL)
		{
			printf("메모리 할당 실패\n");
			for (int k = 0; k < i; k++) free(student[k]);
			free(student);
			return 1;
		}
	}
	//입력 및 유효성 검사 
	for (int i = 0; i < students; i++)
	{
		printf("%d번 학생\n",i + 1);

		for (int j = 0; j < subject; j++)
		{
			printf("%d과목 점수 입력 : ", j + 1);
			scanf("%d", &score);
			if (score < 0 || score >100)
			{
				printf("범위초과");
				return 1;
			}
			student[i][j] = score;
		}
		printf("--------------\n");
	}


	ScoreAve(student, subject, students);	//평균점수 함수 호출
	
	//메모리 할당 해제
	for (int i = 0; i < students; i++)
	{
		free(student[i]);
	}
	free(student);

	return 0;
}
//평균 점수
void ScoreAve(int ** student,int subject, int students)
{
	int sum = 0;
	//입력값 유효성 검사 
	if (students <= 0 || subject <= 0) {
		printf("학생 수와 과목 수는 1 이상이어야 합니다.\n");
		return;
	}

	//동적 메모리 할당 
	int* ave = (int*)malloc(sizeof(int) * students);
	if (ave == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}

	//평균 점수 계산
	for (int i = 0; i < students; i++)
	{
		sum = 0;
		for (int j = 0; j < subject; j++)
		{
			sum += student[i][j];
		}
		ave[i] = sum / subject;
	}

	ScoreRank(ave,students);//등수 함수 호출

	//메모리 할당 해제
	free(ave);
}

//등수 함수 
void ScoreRank(int* ave, int students)
{
	//유효성 검사 
	if (students <= 0 || ave == NULL) {
		printf("학생 수가 1 이상이어야 하며, ave 포인터가 유효해야 합니다.\n");
		return;
	}

	//동적 메모리 할당
	int* idx = (int*)malloc(sizeof(int) * students);
	if (idx==NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}

	//학생 번호 입력
	for (int i = 0; i < students; i++)
	{
		idx[i] = i+1;
	}

	//선택정렬 (내림차순) 
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
			// Swap 점수
			int temp = ave[max_idx];
			ave[max_idx] = ave[i];
			ave[i] = temp;

			// SWap 등수
			int rank = idx[max_idx];
			idx[max_idx] = idx[i];
			idx[i] = rank;

		}
	}
	//결과 출력 
	for (int i = 0; i < students; i++)
	{
		printf("%d번 학생 평균 점수 %d점 %d등\n", idx[i],ave[i],i+1);
	}

	//메모리 할당 해제
	free(idx);
}