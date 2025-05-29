//문제 6 , 2 차원 배열의 각 원소에 1 을 더하는 함수의 인자
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수원형
void ArrAdd(int arr[][5]);
void ArrAdd2(int (*arr)[5]);

int main()
{
	int arr[2][5] = { {2,3,5,6,7 },{4,6,1,2,6,} };  // 2차원 배열 생성

	// 배열 원형 출력
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("arr[%d][%d] = ", i, j);
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	printf("첫번째 방법 (배열 표기법) ------------------\n");
	ArrAdd(arr);
	printf("두번째 방법 (포인터 표기법) ------------------\n");
	ArrAdd2(arr);
	return 0;
}
//배열 표기
void ArrAdd(int arr[][5])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] += 1;
			printf("arr[%d][%d] = ", i, j);		//결과 출력
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}

}
//포인터 표기
void ArrAdd2(int (*arr)[5])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] += 1;
			printf("arr[%d][%d] = ", i, j); 	//결과 출력
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}