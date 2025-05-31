//���� 11 , 10������ N�������� ��ȯ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void Binary(int num);	//2����
void Oct(int num);	//8����
void Hex(int num);	//16����

int main()
{
	int num;
	char prefix[3];

	printf("�� �Է� :");
	scanf("%d", &num);
	while (1)
	{
		if (num == 0)
		{
			printf("0�� ������ ���� 0 �Դϴ�.\n");
			printf("���ο� ���� �Է����ּ��� :");
			scanf("%d", &num);
			continue;
		}
		printf("- 2���� ��ȯ: 0b (��: 0b)\n");
		printf("- 8���� ��ȯ : 0   (�� : 0)\n");
		printf("- 16���� ��ȯ : 0x (�� : 0x)\n");
		printf("- ���ο� �� �Է� : N\n");
		printf("- ���α׷� ���� : F\n");
		printf("���λ� �Է� :");
		scanf("%s", prefix);
		
		if (strcmp(prefix, "0b") == 0)	Binary(num);
		else if (strcmp(prefix, "0") == 0)	Oct(num);
		else if (strcmp(prefix, "0x") == 0)	Hex(num);
		else if (strcmp(prefix, "F") == 0)
		{
			printf("���α׷� ����");
			break;
		}
		else if (strcmp(prefix, "N") == 0)
		{
			printf("�� �Է� : ");
			scanf("%d", &num);
		}
		else
			printf("�ٽ� �Է� ���ּ���\n");
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
	printf("2���� ��ȯ ��� : ");
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
	printf("8���� ��ȯ ��� : ");
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
	printf("16���� ��ȯ ��� :");
	for (int i = idx - 1; i >= 0; i--)
	{
		if (hex[i] < 10)	printf("%d", hex[i]);
		else
			printf("%c", hex[i] - 10 + 'A');
	}
	printf("\n");
}