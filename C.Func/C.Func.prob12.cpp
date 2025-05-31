//문제 12 , 에라토스테네스의 체를 이용해서 1 부터 N 까지의 소수를 구하는 프로그램
// 에라토스테네스의 체 :   2부터 시작해 특정 수의 배수를 지워가며 소수를 빠르고 쉽게 찾는 방법
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
int prime(int num);

int main()
{
	int input_num;
	//입력 값
	printf("N값 입력 : ");
	scanf("%d", &input_num);

	//결과 출력
	printf("\n개수 : %d", prime(input_num));

	return 0;
}

//아리스토텔레스의 체
int prime(int input_num)
{
	int count = 0; // 소수 개수 저장 
	int num[100] = { 0 }; // num 배열 0 으로 초기화

	for (int i = 2; i <= input_num; i++) num[i] = 1;	//전부다 소수라고 가정하고 배열에 입력
	
	//아리스토텔레스의 체 알고리즘 2의배수 부터 시작해 특정 수의 배수 까지 지움  
	for (int i = 2; i *i<= input_num; i++)  //  16 = 4 * 4 쌍을 이루기때문에 제곱근으로 해서 효율적
	{
		if(num[i])
		for (int j = i * i; j <= input_num; j += i)
		{
			num[j] = 0;  // 배수들을 0으로 (소수가아님)
		}
	}
	// 결과 출력 
	for (int i = 0; i <= input_num; i++)
		if (num[i])
		{
			printf("소수 : %d ", i);  //남아 있는  값의 인덱스는 소수  
			count++; // 소수 개수 증가
		}
	return count;
}