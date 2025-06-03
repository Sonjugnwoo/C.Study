//	문제 2, 큰 수 계산기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2


typedef struct bignum
{
	char digit[SIZE+1];
	char dot_digit[SIZE+1];
}big;

void PrintBignum(char *result);
void BignumAdd(big* bignum);
void BignumSub(big* bignum);
void BignumMul(big* bignum);

int main()
{
	srand((unsigned int)time(NULL));

	int menu = 0;
	big bignum[2];
	char op[2];
	printf("1 : 정수\n2 : 실수\n");
	scanf("%d", &menu);

	bignum[0].digit[0] = '1' + rand() % 9;
	bignum[1].digit[0] = '1' + rand() % 9;

	if (menu == 1)
	{
		for (int i = 1; i < SIZE; i++)
		{
			bignum[0].digit[i] = '0' + rand() % 10;
			bignum[1].digit[i] = '0' + rand() % 10;
		}
		bignum[0].digit[SIZE] = '\0';
		bignum[1].digit[SIZE] = '\0';

		printf("첫번째 큰수 : %s\n", bignum[0].digit);
		printf("두번째 큰수 : %s\n", bignum[1].digit);

		printf("연산 선택 : ");
		scanf("%s", &op);
		//BignumAdd(bignum);
		//BignumSub(bignum);
		BignumMul(bignum);
	}
	else if (menu == 2)
	{
		
	}
	else
		return 0;
}
void PrintBignum(char* result)
{
	int i = 0;
	while (i < SIZE - 1 && result[i] == '0') i++;	//앞자리가 0 이면 i 증가
	printf("%s\n", result + i); // i 부터 출력 시작
}
void Reverse(char* bignum)
{
	int len = strlen(bignum);
	for (int i = 0; i <len /2; i++)
	{
		int temp = bignum[i];
		bignum[i] = bignum[len - 1 - i];
		bignum[len - 1 - i] = temp;
	}
}
int Compare(char* num_1, char* num_2)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (num_1[i] > num_2[i])
			return 1;
		else if (num_1[i] < num_2[i])
			return 0;
	}
	return 1;
}
void BignumAdd(big *bignum)
{
	char big_result[SIZE + 2];
	int carry = 0;
	char temp_1[SIZE+1];
	char temp_2[SIZE+1];

	strcpy(temp_1, bignum[0].digit);
	strcpy(temp_2, bignum[1].digit);

	temp_1[SIZE] = '\0';
	temp_2[SIZE] = '\0';

	Reverse(temp_1);
	Reverse(temp_2);
	for (int i = 0; i <SIZE; i++)
	{
		int temp = (temp_1[i] - '0') + (temp_2[i] -'0') + carry;
		big_result[i] = (temp % 10) + '0';
		carry = temp / 10;
	}
	if (carry > 0)
	{
		big_result[SIZE] = carry + '0';
		big_result[SIZE + 1] = '\0';
	}
	else 
		big_result[SIZE] = '\0';

	Reverse(big_result);
	PrintBignum(big_result);
}
void BignumSub(big *bignum)
{
	char big_result[SIZE + 2];
	int borrow = 0;

	char temp_1[SIZE + 1];
	char temp_2[SIZE + 1];

	
	strcpy(temp_1, bignum[0].digit);
	strcpy(temp_2, bignum[1].digit);

	int flag = Compare(temp_1, temp_2);
	if (!flag)
	{
		for (int i = 0; i < SIZE ; i++)
		{
			int temp = temp_1[i];
			temp_1[i] = temp_2[i];
			temp_2[i] = temp;
		}
	}
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int diff = (temp_1[i]-'0') - (temp_2[i]-'0') - borrow;
		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		big_result[i] = (diff % 10) + '0';
	}
	big_result[SIZE] = '\0';
	if (!flag) printf("-");
	PrintBignum(big_result);
}
void BignumMul(big* bignum)
{
	char big_result[2 * SIZE + 2] = {'\0'};
	char temp_1[SIZE + 1] = {'\0'};
	char temp_2[SIZE + 1] = {'\0'};
	int temp[2 * SIZE + 2] = { 0 };

	int mul = 0;
	strcpy(temp_1, bignum[0].digit);
	strcpy(temp_2, bignum[1].digit);

	Reverse(temp_1);
	Reverse(temp_2);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			temp[i + j] += (temp_1[i]-'0') * (temp_2[j]-'0');
		}
	}
	for (int i = 0; i < 2 *SIZE; i++)
	{
		big_result[i] = (temp[i] + mul) % 10 + '0';
		mul = (temp[i] + mul) / 10;
	}
	if (mul > 0)
	{
		big_result[2 * SIZE] = mul + '0';
		big_result[2 * SIZE + 1] = '\0';
	}
	else
		big_result[2 * SIZE] = '\0';

	Reverse(big_result);
	PrintBignum(big_result);
}