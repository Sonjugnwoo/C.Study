//문제 4 ,특정한 수 N 을 입력받아서 N 을 소인수분해한 결과가 출력되게 해보세요
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
void PF(int num);

int main()

{
	int input_num;
	// N값 입력 및 유효성 검사 
	printf("N값 입력 : ");
	scanf("%d", &input_num);
	if (input_num <= 1) 
	{
		printf("소인수분해 결과가 없습니다.\n");
		return 0;
	}

	printf("%d 소인수 분해 : ", input_num);  //결과 출력
	PF(input_num); // 함수 호출
	return 0;
}
// 소인수 분해 함수 
void PF(int num)
{
	while (num != 1)
	{
		for (int i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{		
				printf("%d", i); // 소인수 출력 
				num /= i; // 몫으로 갱신
				if (num != 1) printf(" * ");  // num == 1 일시  * 미출력
				break;  // 다음 소인수 찾기
			}
		}
	}
}