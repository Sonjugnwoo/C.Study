//문제 10 , 계산기
//사용자가 1 을 누르면 +, 2 를 누르면 - 와 같은 방식으로 해서 만들면 됩니다. 물론 이전의 계산 결과는 계속 누적되어야 하고, 지우기 기능

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
int Add(int* num);	// 더하기
int Min(int* num);	// 빼기
int Mul(int* num);	// 곱하기
int Div(int* num);	// 나누기
void CE(int* num);	// 입력값 초기화
void Put(int* num);	// 추가 계산
int AC(int* num);	// 전체 초기화

int main()
{

	int num[2];	//숫자 저장 배열

	//숫자 입력
	for (int i = 0; i <=1; i++)
	{
		printf("숫자  입력 : ");
		scanf("%d", &num[i]);
	}
	//계산기 
	while (1)
	{
		int op;	
		printf("입력된 수 : %d , %d\n", num[0], num[1]);	//입력 된 수 출력
		printf("1 : +	2 : -	3 : *	4 : /	5 : CE	6 : AC	7 : 추가 계산	8 : 종료\n");	
		printf("연산 선택 : ");
		scanf("%d", &op);
		// 입력받은 op 조건문 실행
		if (op == 1)	
		{
			printf("%d + %d = %d\n", num[0], num[1], Add(num));	//더하기 결과 출력
			num[0] = Add(num);	//누적값 num[0] 에 입력
		}
		else if (op == 2)
		{
			printf("%d - %d = %d\n", num[0], num[1], Min(num));	//빼기	결과 출력
			num[0] = Min(num);
		}
		else if (op == 3)
		{
			printf("%d * %d = %d\n", num[0], num[1], Mul(num));	//곱하기 결과 출력
			num[0] = Mul(num);
		}
		else if (op == 4)
		{
			if(num[0] < num[1])	printf("%d %% %d = %d\n", num[0], num[1],Div(num));	//나누기 결과 출력(나머지)
			else printf("%d / %d = %d\n", num[0], num[1], Div(num));	//나누기 결과 출력 (몫)
			num[0] = Div(num);
		}
		else if (op == 5)	CE(num);	//입력값 초기화
		else if (op == 6)
		{
			if(AC(num)) break;	//전체 초기화
		}
		else if (op == 7)	Put(num);	//추가 계산	
		else if (op == 8)	// 종료
		{
			printf("시스템 종료\n");	
			break;
		}
		else printf("없는 연산자. 다시 선택해주세요\n");
	}
	return 0;
}
// 더하기
int Add(int* num)
{	
	return num[0] + num[1];
}
// 빼기
int Min(int* num)
{
	return num[0] - num[1];
}
// 곱하기
int Mul(int* num)
{
	return num[0] * num[1];
}
// 나누기
int Div(int* num)
{
	// 0일시 나누기 못하니 num[0] 다시 반환
	if (num[1] == 0) {
		printf("0으로 나눌 수 없습니다!\n");
		return num[0]; 
	}
	if (num[0] < num[1])
		return num[0] % num[1];
	return num[0] / num[1];
}
// 입력값 초기화
void CE(int* num)
{
	printf("입력 값 삭제\n");
	num[1] = 0;
	printf("새로운 값 입력 : ");
	scanf("%d", &num[1]);
}
// 전체 초기화
int AC(int* num)
{
	int op;

	printf("전체 초기화가 완료되었습니다.\n");
	printf("초기화 후 시스템 종료를 원하시면 8을 입력하세요. 계속하려면 아무 숫자나 입력하세요: ");
	num[0] = 0;
	num[1] = 0;
	scanf("%d", &op);
	if (op == 8)
	{
		printf("시스템 종료");
		return 1;
	}
	for (int i = 0; i < 2; i++)
	{
		printf("새로운 값 입력 : ");
		scanf("%d", &num[i]);
	}
	return 0;
}
// 추가 계산
void Put(int* num)
{
	printf("새로운 값 입력 : ");
	scanf("%d", &num[1]);
}