//���� 11-1 , N���� �޾Ƽ� M������ ��ȯ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ�����
void Binary(int num);	//2����
void Oct(int num);	//8����
void Hex(int num);	//16����
void InputBinary(char* num); //2���� �Է¹��� �� 
void InputOct(char* num);	//8���� �Է¹��� �� 
void InputDecimal(char* num);	//10���� �Է¹��� ��
void InputHex(char* num);	//16���� �Է¹��� �� 

int main()
{
	char num[40];	
	//���λ� ���� �� �Է�
	printf("- 2����  : 0b (��: 0b)\n");
	printf("- 8����  : 0   (�� : 0)\n");
	printf("- 16���� : 0x (�� : 0x)\n");
	printf("���λ� ���� �� 10����\n");
	printf("���λ� + �� �Է� :");
	scanf_s("%s", num,sizeof(num));

	//���λ� �Ǻ� �� �Լ� ȣ��
	// strcmp : �� ���ڿ��� �տ������� ������ ���̸�ŭ ��
	if (strncmp(num, "0b", 2) == 0) // num ���ڿ��� ���� 2��ŭ�� 0b �� ������ 0 ��ȯ
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
// 2���� �Է� ���� �� 
// ���� �� ����� ���δ� �Ȱ��� 
void InputBinary(char* num)
{
	int base = 2;	// 2���� 
	int idx = 2;	// �տ� 0b��ŭ ���ֱ� 
	int len = strlen(num) - 2; // �Է¹��� 2���� ���� ��� 
	int temp = 0;	// 10������ ��ȯ �� �� ���� �Լ� 
	char choice[5];	

	//�Է°� Ȯ��
	printf("�Է¹����� %d���� : ", base);
	for (int i = 2; i < len+2; i++) printf("%c", num[i]);

	// ���λ� ���� �� �Է� 
	printf("\n- 8����  ��ȯ : 0 (�� : 0)\n");
	printf("- 10���� ��ȯ : 10\n");
	printf("- 16���� ��ȯ : 0x (�� : 0x)\n");
	printf("��ȯ�� ���� �Է� :");
	scanf("%s", choice);

	// 10���� ��ȯ
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

	//�Ԏ����� ���λ� �Ǻ� �� �Լ� ȣ��
	if (strncmp(choice, "0",2) == 0)	Oct(temp);
	else if (strcmp(choice, "10") == 0) printf("10���� ��ȯ ��� : %d", temp);
	else if (strcmp(choice, "0x") == 0)	Hex(temp);
}
 // 8���� �Է� ���� �� 
void InputOct(char* num)
{
	int base = 8;
	int idx = 1;
	int len = strlen(num) - 1;
	int temp = 0;
	char choice[5];

	printf("�Է¹����� %d���� : ", base);
	for (int i = idx; i < len + 1; i++) printf("%c", num[i]);
	printf("\n- 2����  ��ȯ : 0b (�� : 0b)\n");
	printf("- 10���� ��ȯ : 10\n");
	printf("- 16���� ��ȯ : 0x (�� : 0x)\n");
	printf("��ȯ�� ���� �Է� :");
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
	else if (strcmp(choice, "10") == 0) printf("10���� ��ȯ ��� : %d", temp);
	else if (strcmp(choice, "0x") == 0)	Hex(temp);
}
// 10���� �Է� ���� �� 
void InputDecimal(char* num)
{
	int base = 10;
	int idx = 0;
	int len = strlen(num);
	int temp = 0;
	char choice[5];

	printf("�Է¹����� %d���� : ", base);
	for (int i = idx; i < len + 1; i++) printf("%c", num[i]);
	printf("\n- 2����  ��ȯ : 0b (�� : 0b)\n");
	printf("- 8���� ��ȯ : 0 (�� : 0)\n");
	printf("- 16���� ��ȯ : 0x (�� : 0x)\n");
	printf("��ȯ�� ���� �Է� :");
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
// 16���� �Է� ���� �� 
void InputHex(char* num)
{
	int base = 16;
	int idx = 2;
	int len = strlen(num) - 2;
	int temp = 0;
	char choice[5];

	printf("�Է¹����� %d���� : ", base);
	for (int i = idx; i < len + 2; i++) printf("%c", num[i]);
	printf("\n- 2����  ��ȯ : 0b (�� : 0b)\n");
	printf("- 8����  ��ȯ : 0 (�� : 0)\n");
	printf("- 10���� ��ȯ : 10\n");
	printf("��ȯ�� ���� �Է� :");
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
	else if (strcmp(choice, "10") == 0) printf("10���� ��ȯ ��� : %d", temp);
}
// 2���� ��ȯ��
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
	printf("2���� ��ȯ ��� : ");
	for (int i = idx - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}
	printf("\n");
}
// 8���� ��ȯ��
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
	printf("8���� ��ȯ ��� : ");
	for (int i = idx - 1; i >= 0; i--)
	{
		printf("%d", oct[i]);
	}
	printf("\n");
}
// 16���� ��ȯ��
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
	printf("16���� ��ȯ ��� :");
	for (int i = idx - 1; i >= 0; i--)
	{
		if (hex[i] < 10)	printf("%d", hex[i]);
		else
			printf("%c", hex[i] - 10 + 'A');
	}
	printf("\n");
}