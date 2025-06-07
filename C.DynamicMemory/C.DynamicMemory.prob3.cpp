// 문제 3 ,  동적으로 할당된 배열의 크기를 다시 바꾸는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//함수 원형 
void Change(int** old, int size_1);	//배열 크기 변경 함수 

int main()
{
	int size_1;

	printf("할당할 크기를 입력 : ");
	scanf("%d", &size_1);

	//메모리 동적 할당 
	int* old = (int*)malloc(sizeof(int) * size_1);
	if (old == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	// 확인용 값 입력
	printf("초기 배열: ");
	for (int i = 0; i < size_1; i++) 
	{
		old[i] = i;
		printf("%d ", old[i]);
	}
	printf("\n");
	
	// 함수 호출 
	Change(&old, size_1);	// 이중 포인터로 전달해야 새로 할당한 배열의주소가 넘어감
	free(old);
	return 0; 
}
//크기 변경 함수 
void Change(int **old,int size_1)	// 이중 포인터로 전달해야 새로 할당한 배열의주소가 넘어감
{
	int size_2;

	printf("바꿀 크기 입력 : ");
	scanf("%d", &size_2);

	//동적 메모리 할당 
	int* arr = (int*)malloc(sizeof(int) * size_2);
	if (arr == NULL)
	{
		printf("메모리 할당 실패\n");
		free(*old);
		return ;
	}
	//새로운 배열에 크기가 작은 배열값 전달 
	int len = size_1 < size_2 ? size_1 : size_2;
	for (int i = 0; i < len; i++)
	{
		arr[i] = (*old)[i];
	}
	//남은 공간 채우기 
	for (int i = len; i < size_2; i++)
	{
		arr[i] = i;
	}
	//구 배열 할당 해제
	free(*old);
	//구 배열에 대입 
	*old = arr;

	//결과 출력 
	printf("크기 조정 후 배열: ");
	for (int i = 0; i < size_2; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}