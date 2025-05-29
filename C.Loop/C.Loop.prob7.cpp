// 문제 7 , 임의의 자연수 N 을 입력 받아 N 을 소인수 분해 한 결과를 출력하여라.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int input_num = 0;
	// 임의의 자연수 input_num 입력
	while (1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &input_num);

		// 음수 및 0 일시 다시 입력 
		if (input_num < 0) printf("음수 입니다, 다시 입력해주세요.\n");
		else if (input_num == 0) printf("0은 사용 불가 \n");
		else if (input_num == 1) printf("1은 소인수분해 X\n");
		else
			break;  // 2 이상 자연수 입력 시 반복 종료 
	}

	printf("%d 의 소인수 분해 : ", input_num);

	//소인수 분해 과정
	while (input_num != 1)
	{
		for (int i = 2; i <= input_num; i++)
		{
			if (input_num % i == 0)
			{
				printf("%d", i);   //소인수 출력
				input_num /= i;    //몫으로 갱신
				if (input_num != 1) printf(" * ");  // 마지막엔 * 미출력
				break; // 다음 소인수 찾기
			}
		}
	}
	return 0;
}