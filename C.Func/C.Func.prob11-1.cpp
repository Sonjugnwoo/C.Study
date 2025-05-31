//문제 11-1 , N진수 받아서 M진수로 변환
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수원형
void Binary(int num);	//2진수
void Oct(int num);	//8진수
void Hex(int num);	//16진수
void InputBinary(char* num); //2진수 입력받은 후 
void InputOct(char* num);	//8진수 입력받은 후 
void InputDecimal(char* num);	//10진수 입력받은 후
void InputHex(char* num);	//16진수 입력받은 후 

int main()
{
	char num[40];	
	//접두사 설명 및 입력
	printf("- 2진수  : 0b (예: 0b)\n");
	printf("- 8진수  : 0   (예 : 0)\n");
	printf("- 16진수 : 0x (예 : 0x)\n");
	printf("접두사 없을 시 10진수\n");
	printf("접두사 + 수 입력 :");
	scanf_s("%s", num,sizeof(num));

	//접두사 판별 후 함수 호출
	// strcmp : 두 문자열의 앞에서부터 지정한 길이만큼 비교
	if (strncmp(num, "0b", 2) == 0) // num 문자열의 길이 2만큼에 0b 가 있으면 0 반환
	{
		InputBinary(num);
	}
	else if (strncmp(num, "0", 2) == 0)
	{
		InputOct(num);
	}
	else if (strncmp(num, "0x", 2) == 0)
	{
		InputHex(num);
	}
	else
		InputDecimal(num);
	return 0;
}
// 2진수 입력 받은 후 
// 변수 및 방법은 전부다 똑같음 
void InputBinary(char* num)
{
	int base = 2;	// 2진수 
	int idx = 2;	// 앞에 0b만큼 빼주기 
	int len = strlen(num) - 2; // 입력받은 2진수 길이 계산 
	int temp = 0;	// 10진수로 변환 후 값 저장 함수 
	char choice[5];	

	//입력값 확인
	printf("입력받은값 %d진수 : ", base);
	for (int i = 2; i < len+2; i++) printf("%c", num[i]);

	// 접두사 설명 및 입력 
	printf("\n- 8진수  변환 : 0 (예 : 0)\n");
	printf("- 10진수 변환 : 10\n");
	printf("- 16진수 변환 : 0x (예 : 0x)\n");
	printf("변환할 진수 입력 :");
	scanf("%s", choice);

	// 10진수 변환
	while (num[idx] != '\0')
	{
		int power = 1;
		for (int i = 0; i < len - 1; i++) {
			power *= 2;
		}
		temp += (num[idx] - '0') * power;
		idx++;
		len--;
	}

	//입렫받은 접두사 판별 후 함수 호출
	if (strncmp(choice, "0",2) == 0)	Oct(temp);
	else if (strcmp(choice, "10") == 0) printf("10진수 변환 결과 : %d", temp);
	else if (strcmp(choice, "0x") == 0)	Hex(temp);
}
 // 8진수 입력 받은 후 
void InputOct(char* num)
{
	int base = 8;
	int idx = 1;
	int len = strlen(num) - 1;
	int temp = 0;
	char choice[5];

	printf("입력받은값 %d진수 : ", base);
	for (int i = idx; i < len + 1; i++) printf("%c", num[i]);
	printf("\n- 2진수  변환 : 0b (예 : 0b)\n");
	printf("- 10진수 변환 : 10\n");
	printf("- 16진수 변환 : 0x (예 : 0x)\n");
	printf("변환할 진수 입력 :");
	scanf("%s", choice);

	while (num[idx] != '\0')
	{
		int power = 1;
		for (int i = 0; i < len - 1; i++) {
			power *= 8;
		}
		temp += (num[idx] - '0') * power;
		idx++;
		len--;
	}

	if (strncmp(choice, "0b",2) == 0)	Binary(temp);
	else if (strcmp(choice, "10") == 0) printf("10진수 변환 결과 : %d", temp);
	else if (strcmp(choice, "0x") == 0)	Hex(temp);
}
// 10진수 입력 받은 후 
void InputDecimal(char* num)
{
	int base = 10;
	int idx = 0;
	int len = strlen(num);
	int temp = 0;
	char choice[5];

	printf("입력받은값 %d진수 : ", base);
	for (int i = idx; i < len + 1; i++) printf("%c", num[i]);
	printf("\n- 2진수  변환 : 0b (예 : 0b)\n");
	printf("- 8진수 변환 : 0 (예 : 0)\n");
	printf("- 16진수 변환 : 0x (예 : 0x)\n");
	printf("변환할 진수 입력 :");
	scanf("%s", choice);

	while (num[idx] != '\0')
	{
		int power = 1;
		for (int i = 0; i < len - 1; i++) {
			power *= 10;
		}
		temp += (num[idx] - '0') * power;
		idx++;
		len--;
	}

	if (strncmp(choice, "0b", 2) == 0)	Binary(temp);
	else if (strcmp(choice, "0") == 0)  Oct(temp);
	else if (strcmp(choice, "0x") == 0)	Hex(temp);
}
// 16진수 입력 받은 후 
void InputHex(char* num)
{
	int base = 16;
	int idx = 2;
	int len = strlen(num) - 2;
	int temp = 0;
	char choice[5];

	printf("입력받은값 %d진수 : ", base);
	for (int i = idx; i < len + 2; i++) printf("%c", num[i]);
	printf("\n- 2진수  변환 : 0b (예 : 0b)\n");
	printf("- 8진수  변환 : 0 (예 : 0)\n");
	printf("- 10진수 변환 : 10\n");
	printf("변환할 진수 입력 :");
	scanf("%s", choice);

	while (num[idx] != '\0')
	{
		int power = 1;
		for (int i = 0; i < len - 1; i++) {
			power *= 16;
		}
		if ((num[idx] - '0') < 10) temp += (num[idx] - '0') * power;
		else temp += (num[idx] - 'A' + 10) * power;
		idx++;
		len--;
	}

	if (strncmp(choice, "0b",2) == 0)	Binary(temp);
	else if (strcmp(choice, "0")==0)	Oct(temp);
	else if (strcmp(choice, "10") == 0) printf("10진수 변환 결과 : %d", temp);
}
// 2진수 변환기
void Binary(int num)
{
	int binary[40];
	int idx = 0;
	while (num > 0)
	{
		binary[idx] = num % 2;
		num /= 2;
		idx++;
	}
	printf("2진수 변환 결과 : ");
	for (int i = idx - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}
	printf("\n");
}
// 8진수 변환기
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
// 16진수 변환기
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