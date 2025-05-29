//문제 1 , 어느날 귀족이 돈벌이가 시원치 않아져서 이전에는 일정하게 10000 달러씩 챙겼지만 이제 일정치 않은 수입을 얻게 되었습니다. 
//인자를 2개 가지는 total_money   함수를 만들고 하나는 현재 귀족의 재산, 다른 하나는 오늘 귀족의 수입을 인자로 전달받는 새로운 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형 
int TotalMoney(int money, int import);  

int main()
{
	int money = 10000;  //현재 재산
	int input_money;    // 수입
	printf("수입 입력 : ");
	scanf("%d", &input_money);
	
	printf("귀족의 총 재산 : %d", TotalMoney(money,input_money)); //결과 출력
	return 0;
}

int TotalMoney(int money, int import)
{
	return money + import;  // 재산 + 수입 계산
}
