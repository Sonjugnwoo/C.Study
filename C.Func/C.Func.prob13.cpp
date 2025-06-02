//문제 13 , 1000 자릿수 계산기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 1000

//함수 원형
void BignumAdd(char* bignum_1, char* bignum_2);	//더하기 함수
void BignumMin(char* bignum_1, char* bignum_2);	// 빼기 함수 
void BignumMul(char* bignum_1, char* bignum_2);	// 곱하기 함수
void BignumDiv(char* bignum_1, char* bignum_2);	// 나누기 함수 (미구현)
void Reverse(char* bignum_1, char* bignum_2);	// 뒤집는 함수
int Compare(char* bignum_1, char* bignum_2);	// 비교 함수

int main()
{
	char bignum_1[SIZE + 1];	//1000자리 수 저장 배열_1
	char bignum_2[SIZE + 1];	//1000자리 수 저장 배열_2

	// 난수 시드 초기화 (매번 다른 난수 생성)
	srand((unsigned int)time(NULL));	

	//첫자리 1~9로 만들기
	bignum_1[0] = '1' + rand() % 9;	
	bignum_2[0] = '1' + rand() % 9;

	//첫자리 제외 1~9랜덤수
	for (int i = 1; i < SIZE; i++)
	{
		bignum_1[i] = '0' + rand() % 10;
		bignum_2[i] = '0' + rand() % 10;
	}
	// 문자열로 끝에 NULL 문자 삽입 ( 문자열의 마지막은 NULL )
	bignum_1[SIZE] = '\0';
	bignum_2[SIZE] = '\0';
	
	// 생성된 큰 수 출력
	printf("첫번째 큰수 : %s\n", bignum_1);
	printf("두번째 큰수 : %s\n", bignum_2);


	BignumAdd(bignum_1, bignum_2);	//덧셈
	BignumMin(bignum_1, bignum_2);	//뺄셈 
	BignumMul(bignum_1, bignum_2);	//곱셈
	//BignumDiv(bignum_1, bignum_2);//나눗셈	
	return 0;
}

// 뒤집는 함수 
void Reverse(char* bignum)
{
	int len = strlen(bignum);	 // 문자열 길이 계산 

	// 문자열의 앞과 뒤를 교환하여 뒤집기
	for (int i = 0; i <len/2; i++)
	{
		char temp = bignum[i];
		bignum[i] = bignum[len-1-i];
		bignum[len-1-i] = temp;
	}
}
// 비교 함수 
int Compare(char* bignum_1, char* bignum_2)
{
	//반환값: bignum_1 >= bignum_2 이면 1, 아니면 0
	for (int i = 0; i < SIZE; i++)
	{
		//bignum_1 < bignum_2 0 반환
		if (bignum_1[i] < bignum_2[i])	
		{
			return 0;
		}
		//bignum_1 > bignum_2 1 반환
		else if (bignum_1[i] > bignum_2[i])
			return 1;
	}
	return 1;  
}
// 큰 수 작은수 변경
void Swap(char* bignum_1, char* bignum_2)
{
	//각 자리 별로 교환
	for (int i = 0; i < SIZE; i++)
	{
		int temp = bignum_1[i];		//임시 변수에 bignum_1 저장
		bignum_1[i] = bignum_2[i];	//bignum_1 에 bignum_2 대입
		bignum_2[i] = temp;			//bignum_2 에 임시 변수 대입
	}
}
// 출력 함수 
void PrintBignum(char * bignum)
{
	int i = 0;
	while (i < SIZE - 1 && bignum[i] == '0') i++;	//앞자리가 0 이면 i 증가
	printf("%s\n", bignum + i); // i 부터 출력 시작
}
// 더하기 함수 
void BignumAdd(char * bignum_1,char *bignum_2)
{
	char result[SIZE + 2] ={'0'};	// 결과값을 저장할 배열
	int carry = 0;					//올림 자리 변수

	//뒤집어서 일의자리 부터 계산
	Reverse(bignum_1);
	Reverse(bignum_2);

	//더하기 계산 식
	for (int i = 0; i < SIZE; i++)
	{
		int temp = (bignum_1[i] - '0') + (bignum_2[i] - '0') + carry;
		result[i] = (temp % 10) +'0';	//일의자리
		carry = temp / 10;				//십의 자리는 다음 자리로
	}

	// 마지막 자리까지 계산 후 캐리가 남아있으면 결과 배열에 추가 
	if (carry > 0)
	{
		result[SIZE] = carry +'0';
		result[SIZE+1] = '\0';	// 문자열 끝에 NULL 문자
	}
	else
		result[SIZE] = '\0';	// 문자열 끝에 NULL 문자

		// 다시 정방향 뒤집기
		Reverse(result);	

		// 결과 출력
		PrintBignum(result);
}
// 빼기 함수 
void BignumMin(char* bignum_1, char* bignum_2)
{
	char result[SIZE + 1] = { '0'};	// 결과값을 저장할 배열
	int borrow = 0;					//내림 자리 변수

	// 큰수 비교 flag = 0 : bignum_2 가 큼 ,flag =1 : bignum_1이 큼
	int flag  = Compare(bignum_1, bignum_2);

	// 항상 큰수 - 작은수가 되도록 Swap
	if (!flag)	Swap(bignum_1, bignum_2);		
	
	//뺄셈 계산 식
	for (int i = SIZE-1; i >=0; i--)
	{

		int diff_1 = (bignum_1[i] - '0') + borrow;
		int diff_2 = bignum_2[i] - '0';
		int diff = diff_1 - diff_2;

		//diff가 0보다 작으면 1빌려오기, diff 에 10 더해주기
		if (diff < 0)
		{
			borrow = -1;
			diff += 10;
		}
		else
			borrow = 0;

		bignum_1[i] = diff  + '0';
	}
	bignum_1[SIZE] = '\0'; // 문자열 끝에 NULL 문자

	//bignum_1값 result에 넣기
	for (int i = 0; i < SIZE; i++)
	{
		result[i] = bignum_1[i];
	}
	
	result[SIZE] = '\0'; // 문자열 끝에 NULL 문자

	// flag 가 0이면  bignum_2가 더 컸기 때문에 - 출력 
	if (!flag) printf("-");

	// 결과 출력
	PrintBignum(result);
}
//  곱하기 함수 
void BignumMul(char* bignum_1, char* bignum_2)
{
	int temp[2 * SIZE + 2 ] = {0};			 //각 자리 곱셈 결과를 저장할 임시 배열
	char result[2 * SIZE + 2] = { '0' };	//곱셈 결과를 저장할 문자열 배열
	int mul = 0;							//올림 자리 변수

	//뒤집어서 일의자리 부터 계산
	Reverse(bignum_1);
	Reverse(bignum_2);

	//곱셈 계산 식
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// bignum_1[i]와 bignum_2[j]를 곱해서 temp[i + j]에 누적
			temp[i+j] += (bignum_1[i] - '0') * (bignum_2[j] - '0');	
		}
	}
	//자리올림 처리 
	for (int i = 0; i < 2*SIZE; i++)
	{
		result[i] = ((temp[i] + mul) % 10) +'0';
		mul = (temp[i]+mul) / 10;
	}
	// 마지막 자리까지 계산 후 캐리가 남아있으면 결과 배열에 추가 
	if (mul > 0)
	{
		result[2 * SIZE] = mul + '0';
		result[2 * SIZE + 1] = '\0';	// 문자열 끝에 NULL 문자
	}
	else
		result[2 * SIZE] = '\0';		// 문자열 끝에 NULL 문자


	//다시 정방향 뒤집기
	Reverse(result);

	//결과 출력
	PrintBignum(result);
}

/* 미구현....
void BignumDiv(char* bignum_1, char* bignum_2)
{
	char quot[SIZE + 1] = { 0 };
	char rema[SIZE + 2] = { 0 }; // 한 자리 더 여유
	rema[0] = '0';
	rema[1] = '\0';

	for (int i = 0; i < SIZE; i++)
	{
		// rema에 다음 자릿수 붙이기
		int len = strlen(rema);
		rema[len] = bignum_1[i];
		rema[len + 1] = '\0';

		// 몫 자리 구하기
		int q = 0;
		while (Compare(rema, bignum_2))
		{
			int borrow = 0;
			for (int j = SIZE - 1; j >= 0; j--)
			{
				int diff = (rema[j] - '0') - (bignum_2[j] - '0') + borrow;
				if (diff < 0)
				{
					diff += 10;
					borrow = -1;
				}
				else
					borrow = 0;

				rema[j] = diff + '0';
			}
			q++;

		}
		quot[i] = q + '0';
	}
	quot[SIZE] = '\0';
	PrintBignum(quot);
	PrintBignum(rema);
} */