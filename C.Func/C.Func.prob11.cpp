//문제 11 , 10진수를 N진법으로 변환

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void Binary(int num);	//2진수
void Oct(int num);	//8진수
void Hex(int num);	//16진수

int main()
{
	int num;
	char prefix[3];

	printf("수 입력 :");
	scanf("%d", &num);
	while (1)
	{
		if (num == 0)
		{
			printf("0의 진수는 전부 0 입니다.\n");
			printf("새로운 수를 입력해주세요 :");
			scanf("%d", &num);
			continue;
		}
		printf("- 2진수 변환: 0b (예: 0b)\n");
		printf("- 8진수 변환 : 0   (예 : 0)\n");
		printf("- 16진수 변환 : 0x (예 : 0x)\n");
		printf("- 새로운 수 입력 : N\n");
		printf("- 프로그램 종료 : F\n");
		printf("접두사 입력 :");
		scanf("%s", prefix);
		
		if (strcmp(prefix, "0b") == 0)	Binary(num);
		else if (strcmp(prefix, "0") == 0)	Oct(num);
		else if (strcmp(prefix, "0x") == 0)	Hex(num);
		else if (strcmp(prefix, "F") == 0)
		{
			printf("프로그램 종료");
			break;
		}
		else if (strcmp(prefix, "N") == 0)
		{
			printf("수 입력 : ");
			scanf("%d", &num);
		}
		else
			printf("다시 입력 해주세요\n");
	}
	return 0;
}
void Binary(int num)
{
	int binary[40];
	int idx = 0;
	while (num >0 )
	{
		binary[idx] = num % 2;
		num /= 2;
		idx++;
	}
	printf("2진수 변환 결과 : ");
	for (int i = idx-1; i >=0; i--)
	{
		printf("%d", binary[i]);
	}
	printf("\n");
}
void Oct(int num)
{
	int oct[40];
	int idx = 0;

	while (num > 0)
	{
		oct[idx] = num % 8;
		num /= 8;
		idx++;
	}
	printf("8진수 변환 결과 : ");
	for (int i = idx - 1; i >= 0; i--)
	{
		printf("%d", oct[i]);
	}
	printf("\n");
}
void Hex(int num)
{
	int hex[40];
	int idx = 0;
	int temp_idx = 0;

	while (num > 0)
	{
		hex[idx] = num % 16;
		num /= 16;
		idx++;
	}
	printf("16진수 변환 결과 :");
	for (int i = idx - 1; i >= 0; i--)
	{
		if (hex[i] < 10)	printf("%d", hex[i]);
		else
			printf("%c", hex[i] - 10 + 'A');
	}
	printf("\n");
}