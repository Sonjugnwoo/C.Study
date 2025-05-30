//문제 7 , 사용자로 부터 5 명의 학생의 수학, 국어,영어 점수를 입력 받아서 평균이 가장 높은 사람 부터 평균이 가장 낮은 사람까지 정렬되어 출력
// 특히평균을 기준으로 평균 이상인 사람 옆에는 '합격', 아닌 사람은 '불합격' 을 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

 //함수 원형
int Ave(int start, int* k_score, int* m_score, int* e_score);
void SeletionSort(int* ave, int* student_idx);
void Pass(int* ave, int* student_idx);

int main()
{
	int k_score[SIZE];	// 국어 점수 배열
	int m_score[SIZE];	// 수학 점수 배열
	int e_score[SIZE];	// 영어 점수 배열
	int ave[SIZE];		// 평균 점수 배열
	int student_idx[SIZE];	// 학생 번호 (입력 순) 배열

	// 점수 입력 및 유효성 검사(0~100) 까지
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d 번 학생 \n", i + 1);
		printf("국어 : ");
		scanf("%d", &k_score[i]);
		if (k_score[i] < 0 || k_score[i] >100)
		{
			printf("0~100사이로 입력해주세요.\n");
			i--;
			continue;
		}
		printf("수학 : ");
		scanf("%d", &m_score[i]);
		if (m_score[i] < 0 || m_score[i] >100)
		{
			printf("0~100사이로 입력해주세요.\n");
			i--;
			continue;
		}
		printf("영어 : ");
		scanf("%d", &e_score[i]);
		if (e_score[i] < 0 || e_score[i] >100)
		{
			printf("0~100사이로 입력해주세요.\n");
			i--;
			continue;
		}
		printf("------------------\n");
		ave[i] = Ave(i, k_score, m_score, e_score);	//평균 계산후 평균 배열에 값 입력
		student_idx[i] = i+1;	//학생 번호 배열에 값 입력
	}

	SeletionSort(ave, student_idx);	//선택정렬 > 내림차순 정렬
	Pass(ave, student_idx);	//합격 불합격 함수 호출
	return 0;
}
// 평균 구하는 함수
int Ave(int start , int *k_score, int *m_score, int *e_score)
{
	int sum = k_score[start] + m_score[start] + e_score[start];
	return sum / 3;	//평균 값 반환
}
//선택 정렬 함수 (내림차순)
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
		// 점수 정렬
		int temp = ave[i];
		ave[i] = ave[max_idx];
		ave[max_idx] = temp;
		// 학생 번호 정렬
		int idx = student_idx[i];
		student_idx[i] = student_idx[max_idx];
		student_idx[max_idx] = idx;
	}
}
// 합격 불합격 확인 함수
void Pass(int* ave,int * student_idx)
{
	int pass = 0;
	// 전체 학생 평균 계산
	for (int i = 0; i < SIZE; i++)
	{
		pass += ave[i];
	}
	pass /= SIZE; // 전체 학생 평균

	printf("평균 점수 : %d\n", pass);
	printf("------------------\n");

	//결과 출력 
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d번 학생 : 평균 %d\n", student_idx[i], ave[i]);
		if (ave[i] >= pass)
		{

			printf("합격\n");
		}
		else printf("불합격\n");
		printf("------------------\n");
	}
}