//	문제 2, 큰 수 계산기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

//구조체 정의
typedef struct bignum
{
	char digit[SIZE+1];
	char dot_digit[SIZE+1];
}big;

//함수원형
void PrintBignum(char *result);	//앞자리 0 제외 결과 출력
void Swap(char* num_1, char* num_2);	// 교환 함수
int Compare(char* num_1, char* num_2);	// 비교 함수 

//정수 함수 원형 (나누기 미구현 추후 할 예정)
void BignumAdd(big* bignum);	//더하기
void BignumSub(big* bignum);	//빼기
void BignumMul(big* bignum);	//곱하기

//실수 함수 원형 (나누기 미구현 추후 할 예정)
void BigFloatAdd(big* bignum);	//더하기
void BigFloatSub(big* bignum);	//빼기
void BigFloatMul(big* bignum);	//곱하기

int main()
{
	big bignum[2]; //큰 수 담을 구조체 배열 선언

	// 난수 시드 초기화 (매번 다른 난수 생성)
	srand((unsigned int)time(NULL));

	int menu = 0;
	char op;
	//정수 및 실수 선택
	printf("1 : 정수\n2 : 실수\n");
	scanf("%d", &menu);

	//첫자리 1~9로 만들기
	bignum[0].digit[0] = '1' + rand() % 9;
	bignum[1].digit[0] = '1' + rand() % 9;

	//첫자리 제외 1~9랜덤수
	for (int i = 1; i < SIZE; i++)
	{
		bignum[0].digit[i] = '0' + rand() % 10;
		bignum[1].digit[i] = '0' + rand() % 10;
	}
	// 문자열로 끝에 NULL 문자 삽입 ( 문자열의 마지막은 NULL )
	bignum[0].digit[SIZE] = '\0';
	bignum[1].digit[SIZE] = '\0';

	printf("------------\n");

	//계산기 프로그램 
	if (menu == 1) //정수 
	{
		//정수 숫자 2개 출력
		printf("첫번째 정수 : %s\n", bignum[0].digit);
		printf("두번째 정수 : %s\n", bignum[1].digit);
		printf("------------\n");

		// 사칙연산 계산
		printf("연산 선택 : ");
		scanf(" %c",&op);

		switch (op)
		{
		case '+':
			BignumAdd(bignum);	//덧셈 
			break;
		case '-':
			BignumSub(bignum);	//뺄셈
			break;
		case '*':
			BignumMul(bignum);	//곱셈
			break;
		case '/':				//나눗셈(미구현)
			
		default:
			printf("잘못된 입력 입니다.\n");
			break;
		}
	}
	else if (menu == 2)	// 실수 
	{

		// 1~9 랜덤수 생성 
		for (int i = 0; i < SIZE; i++)
		{
			bignum[0].dot_digit[i] = '0' + rand() % 10;
			bignum[1].dot_digit[i] = '0' + rand() % 10;
		}
		// 문자열로 끝에 NULL 문자 삽입 ( 문자열의 마지막은 NULL )
		bignum[0].dot_digit[SIZE] = '\0';
		bignum[1].dot_digit[SIZE] = '\0';
		//실수 숫자 2개 출력
		printf("첫번째 실수 : %s.%s\n", bignum[0].digit, bignum[0].dot_digit);
		printf("두번째 실수 : %s.%s\n", bignum[1].digit, bignum[1].dot_digit);
		printf("------------\n");

		// 사칙연산 계산
		printf("연산 선택 : ");
		scanf(" %c", &op);

		switch (op)
		{
		case '+':
			BigFloatAdd(bignum);	//덧셈
			break;
		case '-':
			BigFloatSub(bignum);	//뺄셈
			break;
		case '*':
			BigFloatMul(bignum);	//곱셈
			break;
			case '/':				//나눗셈 (미구현)

		default:
			printf("잘못된 입력 입니다.\n");
			break;
		}
	}
	else
		return 0;

	return 0;
}
//출력 함수 앞자리 0 지우고 출력
void PrintBignum(char* result)
{
	int i = 0;
	while (i < SIZE - 1 && result[i] == '0') i++;	//앞자리가 0 이면 i 증가
	printf("%s", result + i); // i 부터 출력 시작
}
//뒤집는 함수
void Reverse(char* bignum)
{
	int len = strlen(bignum);	//문자열 길이 계싼

	// 문자열의 앞과 뒤를 교환하여 뒤집기
	for (int i = 0; i <len /2; i++)
	{
		int temp = bignum[i];
		bignum[i] = bignum[len - 1 - i];
		bignum[len - 1 - i] = temp;
	}
}

// 비교 함수 
int Compare(char* num_1, char* num_2)
{
	//반환값: bignum_1 >= bignum_2 이면 1, 아니면 0
	for (int i = 0; i < SIZE; i++)
	{
		//bignum_1 > bignum_2 1 반환
		if (num_1[i] > num_2[i])
			return 1;
		//bignum_1 < bignum_2 0 반환
		else if (num_1[i] < num_2[i])
			return 0;
	}
	return 1;
}
// 큰 수 작은수 변경
void Swap(char* num_1, char* num_2)
{
	//각 자리 별로 교환
	for (int i = 0; i < SIZE; i++)
	{
		int temp = num_1[i];	//임시 변수에 bignum_1 저장
		num_1[i] = num_2[i];	//bignum_1 에 bignum_2 대입
		num_2[i] = temp;		//bignum_2 에 임시 변수 대입
	}
}
// 정수 더하기 함수 
void BignumAdd(big* bignum)
{
	//올림 자리 변수
	int carry = 0;

	//결과 및 정수 저장 배열
	char int_result[SIZE + 2] = { 0 };	
	char int_part_a[SIZE+1] = { 0 };	
	char int_part_b[SIZE+1] = { 0 };

	//원본 유지를 위해 문자열 복제
	//strcpy : 원본 문자열을 널 문자까지 복사하여 대상 배열에 그대로 저장하는  C표준함수
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);

	//뒤집어서 일의자리 부터 계산
	Reverse(int_part_a);
	Reverse(int_part_b);

	//더하기 계산 식
	for (int i = 0; i <SIZE; i++)
	{
		int temp = (int_part_a[i] - '0') + (int_part_b[i] -'0') + carry;
		int_result[i] = (temp % 10) + '0';
		carry = temp / 10;
	}
	// 마지막 자리까지 계산 후 캐리가 남아있으면 결과 배열에 추가 
	if (carry > 0)
	{
		int_result[SIZE] = carry + '0';
		int_result[SIZE + 1] = '\0';
	}
	else 
		int_result[SIZE] = '\0';

	// 다시 정방향 뒤집기
	Reverse(int_result);

	// 결과 출력
	printf("결과 : ");
	PrintBignum(int_result);
}
// 정수 빼기 함수 
void BignumSub(big* bignum)
{
	//내림 자리 변수
	int borrow = 0;	

	//결과 및 정수 저장 배열
	char int_result[SIZE + 2] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//원본 유지를 위해 문자열 복제
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);

	// 큰수 비교 flag = 0 : int_part_b 가 큼 ,flag =1 : int_part_a이 큼
	int flag = Compare(int_part_a, int_part_b);
	if (!flag)
	{
		// 항상 큰수 - 작은수가 되도록 Swap
		Swap(int_part_a, int_part_b);
		printf("-");
	}
	//뺄셈 계산 식
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int diff = (int_part_a[i]-'0') - (int_part_b[i]-'0') - borrow;

		//diff가 0보다 작으면 1빌려오기, diff 에 10 더해주기
		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		int_result[i] = (diff % 10) + '0';
	}
	int_result[SIZE] = '\0';
	//결과 출력 
	printf("결과 : ");
	PrintBignum(int_result);
}
//정수 곱하기 함수 
void BignumMul(big* bignum)
{
	int mul = 0;	//올림 자리 변수

	//결과 및 정수 저장 배열
	char int_result[4 * SIZE + 2] = {0};
	char int_part_a[SIZE + 1] = {0};
	char int_part_b[SIZE + 1] = {0};
	int mul_result[2 * SIZE + 2] = {0};

	//원본 유지를 위해 문자열 복제
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);

	//일의자리 부터 계산
	Reverse(int_part_a);
	Reverse(int_part_b);

	//곱셈 계산 식
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// int_part_a[i]와 int_part_b[j]를 곱해서 mul_result[i + j]에 누적
			mul_result[i + j] += (int_part_a[i]-'0') * (int_part_b[j]-'0');
		}
	}

	//자리올림 처리 
	for (int i = 0; i < 2 *SIZE; i++)
	{
		int_result[i] = (mul_result[i] + mul) % 10 + '0';
		mul = (mul_result[i] + mul) / 10;
	}

	// 마지막 자리까지 계산 후 캐리가 남아있으면 결과 배열에 추가
	if (mul > 0)
	{
		int_result[2 * SIZE] = mul + '0';
		int_result[2 * SIZE + 1] = '\0';
	}
	else
		int_result[2 * SIZE] = '\0';

	//다시 정방향 뒤집기
	Reverse(int_result);
	//결과 출력
	printf("결과 : ");
	PrintBignum(int_result);
}
//실수 덧셈 함수 
void BigFloatAdd(big *bignum)
{
	int carry = 0;
	int idx = 0;
	
	//결과 및 정수 저장 배열
	char int_result[SIZE + 2] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//결과 및 소수점 뒤 수 저장 배열
	char frac_result[SIZE + 2] = { 0 };
	char frac_part_a[SIZE + 1] = { 0 };
	char frac_part_b[SIZE + 1] = { 0 };

	//원본 유지를 위해 문자열 복사 
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);
	strcpy(frac_part_a, bignum[0].dot_digit);
	strcpy(frac_part_b, bignum[1].dot_digit);

	//뒤집어서 일의자리부터 계산
	Reverse(frac_part_a);
	Reverse(frac_part_b);
	Reverse(int_part_a);
	Reverse(int_part_b);

	//덧셈 계산 식 (정수 부분)
	for (int i = 0; i < SIZE; i++)
	{
		int temp = (int_part_a[i] - '0') + (int_part_b[i] - '0') + carry;
		int_result[i] = (temp % 10) + '0';
		carry = temp / 10;
	}
	if (carry > 0)
	{
		int_result[SIZE] = carry + '0';
		int_result[SIZE + 1] = '\0';
	}
	else
		int_result[SIZE] = '\0';

	//덧셈 계산 식 (소수점 뒷부분)
	carry = 0;
	for (int i = 0;i < SIZE; i++)
	{
		int temp = (frac_part_a[i] - '0') + (frac_part_b[i] - '0') + carry;
		frac_result[i] = (temp % 10) + '0';
		carry = temp / 10;
	}
	if (carry > 0)
	{
		int_result[0] = ((int_result[0] - '0') + 1) + '0';
		frac_result[SIZE] = '\0';
	}
	else
		frac_result[SIZE] = '\0';

	int num = (int_result[idx] - '0');	

	//일의자리가 10 이상이면 앞에 자리올림 
	while (num >= 10 && idx<SIZE)
	{
		// 앞자리(idx+1)에 1을 더해 자리올림
		int_result[idx + 1] = ((int_result[idx + 1] - '0') + 1)+'0';
		// 현재 자리는 0~9로 보정
		int_result[idx] = ((int_result[idx] - '0') % 10) +'0';
		// 다음 자리로 이동
		num = (int_result[++idx] - '0');
	}

	//정방향 뒤집기
	Reverse(frac_result);
	Reverse(int_result);

	//결과 출력
	printf("결과 : ");
	PrintBignum(int_result);
	printf(".%s", frac_result);
}
//실수 뺄셈 함수 
void BigFloatSub(big* bignum)
{
	int borrow = 0;
	int idx = SIZE - 1;

	//결과 및 정수 저장 배열
	char int_result[SIZE + 2] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//결과 및 소수점 뒤 수 저장 배열
	char frac_result[SIZE + 2] = { 0 };
	char frac_part_a[SIZE + 1] = { 0 };
	char frac_part_b[SIZE + 1] = { 0 };

	//원본유지를 위해 문자열 복제 
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);
	strcpy(frac_part_a, bignum[0].dot_digit);
	strcpy(frac_part_b, bignum[1].dot_digit);

	// 큰수 비교 flag = 0 : bignum_2 가 큼 ,flag =1 : bignum_1이 큼
	int flag = Compare(int_part_a, int_part_b);
	if (!flag)
	{
			Swap(int_part_a, int_part_b);	//정수 부분
			Swap(frac_part_a, frac_part_b);	//소수점 뒷 부분 
	}

	//뺄셈 계산 식 (소수점 뒷 부분)
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int diff_2 = (frac_part_a[i] - '0') - (frac_part_b[i] - '0') - borrow;
		//diff_2가 0보다 작으면 1 빌려오기, diff_2 에 10 더해주기
		if (diff_2 < 0)
		{
			diff_2 += 10;
			borrow = 1;
		}
		else
			borrow = 0;

		frac_result[i] = (diff_2 % 10) + '0';
	}
	frac_result[SIZE] = '\0';

	// borrow가 남아있다면 정수 부분에서 1 빌려오기
	if (borrow == 1)
	{
		// 오른쪽부터 0을 9로 바꾸며 빌릴 자리 찾기
		while (idx >= 0 && int_part_a[idx] == '0')
		{
			int_part_a[idx] = '9';
			idx--;
		}
		// 0이 아닌 자리에서 1 빼기
		if (idx >= 0)	int_part_a[idx]--;
	}

	//뺄셈 계산 식 (정수 부분) 
	borrow = 0;
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int diff = (int_part_a[i] - '0') - (int_part_b[i] - '0') - borrow;

		//diff가 0보다 작으면 1 빌려오기, diff 에 10 더해주기
		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		else
			borrow = 0;

		int_result[i] = (diff % 10) + '0';
	}
	int_result[SIZE] = '\0';

	idx = SIZE - 1;	//idx 초기화

	int num = (int_result[idx] - '0');
	
	// 정수 부분에서 일의자리가 0미만일시 처리
	while (num < 0 && idx >0)
	{
		// 현재 자리에 10을 더해 0~9로 보정
		int_result[idx] = ((int_result[idx] - '0') + 10) + '0';
		// 바로 앞자리에서 1을 빼서 빌림 처리
		int_result[idx - 1] = ((int_result[idx - 1] - '0') - 1) + '0';
		// 앞자리로 이동하여 반복
		num = (int_result[--idx] - '0');
	}

	//결과 출력 
	printf("결과 : ");
	if (!flag) 		printf("-");
	PrintBignum(int_result);
	printf(".%s", frac_result);
}
//실수 곱셈 함수 
void BigFloatMul(big* bignum)
{
	int mul = 0;
	int idx = 0;

	//결과 및 정수 저장 배열
	char int_result[4 * SIZE + 3] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//결과 및 소수점 뒷 수 저장 배열
	char frac_result[2 *SIZE + 2] = { 0 };
	char frac_part_a[SIZE + 1] = { 0 };
	char frac_part_b[SIZE + 1] = { 0 };

	//정수 + 실수 문자열 저장 배열
	char full_number[2 * SIZE + 2] = { 0 };
	char full_number_2[2 * SIZE + 2] = { 0 };
	
	//임시 저장 배열
	int mul_result[4 * SIZE + 2] = { 0 };


	//원본유지를 위해 문자열복제
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);
	strcpy(frac_part_a, bignum[0].dot_digit);
	strcpy(frac_part_b, bignum[1].dot_digit);
	
	//문자열 이어 붙이기
	//strcat : 대상 문자열 끝에 다른 문자열을 이어붙여 하나의 문자열로 만드는 C표준함수
	strcat(full_number,int_part_a);
	strcat(full_number, frac_part_a);
	strcat(full_number_2, int_part_b);
	strcat(full_number_2, frac_part_b);

	//뒤집어서 일의자리 부터 계산 
	Reverse(full_number);
	Reverse(full_number_2);

	//곱셈 계산 식
	for (int i = 0; i < 2 *SIZE; i++)
	{
		for (int j = 0; j <2* SIZE; j++)
		{
			// bignum_1[i]와 bignum_2[j]를 곱해서 temp[i + j]에 누적
			mul_result[i + j] += (full_number[i] - '0') * (full_number_2[j] - '0');
		}
	}

	//자리올림 처리 
	for (int i = 0; i < 4 * SIZE; i++)
	{
		int_result[i] = (mul_result[i] + mul) % 10 + '0';
		mul = (mul_result[i] + mul) / 10;
	}

	// 마지막 자리까지 계산 후 캐리가 남아있으면 결과 배열에 추가 
	if (mul > 0)
	{
		int_result[4 * SIZE] = mul + '0';
		int_result[4 * SIZE + 1] = '\0';
	}
	else
		int_result[4 * SIZE] = '\0';

	//다시 정방향 뒤집기
	Reverse(int_result);

	// 소수점 자리 찾기 
	int len = strlen(frac_part_a)+ strlen(frac_part_b);
	int total_len = strlen(int_result);
	
	//정수 배열 소수점기준으로 한칸씩 뒤로 밀기
	for (int i = total_len; i >=total_len-len; i--)
	{
		int_result[i+1] = int_result[i];
	}
	int_result[total_len-len] = '.';
	int_result[total_len + 1] = '\0';

	//결과 출력 
	printf("결과 : ");
	PrintBignum(int_result);
}