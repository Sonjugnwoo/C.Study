//	���� 2, ū �� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

//����ü ����
typedef struct bignum
{
	char digit[SIZE+1];
	char dot_digit[SIZE+1];
}big;

//�Լ�����
void PrintBignum(char *result);	//���ڸ� 0 ���� ��� ���
void Swap(char* num_1, char* num_2);	// ��ȯ �Լ�
int Compare(char* num_1, char* num_2);	// �� �Լ� 

//���� �Լ� ���� (������ �̱��� ���� �� ����)
void BignumAdd(big* bignum);	//���ϱ�
void BignumSub(big* bignum);	//����
void BignumMul(big* bignum);	//���ϱ�

//�Ǽ� �Լ� ���� (������ �̱��� ���� �� ����)
void BigFloatAdd(big* bignum);	//���ϱ�
void BigFloatSub(big* bignum);	//����
void BigFloatMul(big* bignum);	//���ϱ�

int main()
{
	big bignum[2]; //ū �� ���� ����ü �迭 ����

	// ���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand((unsigned int)time(NULL));

	int menu = 0;
	char op;
	//���� �� �Ǽ� ����
	printf("1 : ����\n2 : �Ǽ�\n");
	scanf("%d", &menu);

	//ù�ڸ� 1~9�� �����
	bignum[0].digit[0] = '1' + rand() % 9;
	bignum[1].digit[0] = '1' + rand() % 9;

	//ù�ڸ� ���� 1~9������
	for (int i = 1; i < SIZE; i++)
	{
		bignum[0].digit[i] = '0' + rand() % 10;
		bignum[1].digit[i] = '0' + rand() % 10;
	}
	// ���ڿ��� ���� NULL ���� ���� ( ���ڿ��� �������� NULL )
	bignum[0].digit[SIZE] = '\0';
	bignum[1].digit[SIZE] = '\0';

	printf("------------\n");

	//���� ���α׷� 
	if (menu == 1) //���� 
	{
		//���� ���� 2�� ���
		printf("ù��° ���� : %s\n", bignum[0].digit);
		printf("�ι�° ���� : %s\n", bignum[1].digit);
		printf("------------\n");

		// ��Ģ���� ���
		printf("���� ���� : ");
		scanf(" %c",&op);

		switch (op)
		{
		case '+':
			BignumAdd(bignum);	//���� 
			break;
		case '-':
			BignumSub(bignum);	//����
			break;
		case '*':
			BignumMul(bignum);	//����
			break;
		case '/':				//������(�̱���)
			
		default:
			printf("�߸��� �Է� �Դϴ�.\n");
			break;
		}
	}
	else if (menu == 2)	// �Ǽ� 
	{

		// 1~9 ������ ���� 
		for (int i = 0; i < SIZE; i++)
		{
			bignum[0].dot_digit[i] = '0' + rand() % 10;
			bignum[1].dot_digit[i] = '0' + rand() % 10;
		}
		// ���ڿ��� ���� NULL ���� ���� ( ���ڿ��� �������� NULL )
		bignum[0].dot_digit[SIZE] = '\0';
		bignum[1].dot_digit[SIZE] = '\0';
		//�Ǽ� ���� 2�� ���
		printf("ù��° �Ǽ� : %s.%s\n", bignum[0].digit, bignum[0].dot_digit);
		printf("�ι�° �Ǽ� : %s.%s\n", bignum[1].digit, bignum[1].dot_digit);
		printf("------------\n");

		// ��Ģ���� ���
		printf("���� ���� : ");
		scanf(" %c", &op);

		switch (op)
		{
		case '+':
			BigFloatAdd(bignum);	//����
			break;
		case '-':
			BigFloatSub(bignum);	//����
			break;
		case '*':
			BigFloatMul(bignum);	//����
			break;
			case '/':				//������ (�̱���)

		default:
			printf("�߸��� �Է� �Դϴ�.\n");
			break;
		}
	}
	else
		return 0;

	return 0;
}
//��� �Լ� ���ڸ� 0 ����� ���
void PrintBignum(char* result)
{
	int i = 0;
	while (i < SIZE - 1 && result[i] == '0') i++;	//���ڸ��� 0 �̸� i ����
	printf("%s", result + i); // i ���� ��� ����
}
//������ �Լ�
void Reverse(char* bignum)
{
	int len = strlen(bignum);	//���ڿ� ���� ���

	// ���ڿ��� �հ� �ڸ� ��ȯ�Ͽ� ������
	for (int i = 0; i <len /2; i++)
	{
		int temp = bignum[i];
		bignum[i] = bignum[len - 1 - i];
		bignum[len - 1 - i] = temp;
	}
}

// �� �Լ� 
int Compare(char* num_1, char* num_2)
{
	//��ȯ��: bignum_1 >= bignum_2 �̸� 1, �ƴϸ� 0
	for (int i = 0; i < SIZE; i++)
	{
		//bignum_1 > bignum_2 1 ��ȯ
		if (num_1[i] > num_2[i])
			return 1;
		//bignum_1 < bignum_2 0 ��ȯ
		else if (num_1[i] < num_2[i])
			return 0;
	}
	return 1;
}
// ū �� ������ ����
void Swap(char* num_1, char* num_2)
{
	//�� �ڸ� ���� ��ȯ
	for (int i = 0; i < SIZE; i++)
	{
		int temp = num_1[i];	//�ӽ� ������ bignum_1 ����
		num_1[i] = num_2[i];	//bignum_1 �� bignum_2 ����
		num_2[i] = temp;		//bignum_2 �� �ӽ� ���� ����
	}
}
// ���� ���ϱ� �Լ� 
void BignumAdd(big* bignum)
{
	//�ø� �ڸ� ����
	int carry = 0;

	//��� �� ���� ���� �迭
	char int_result[SIZE + 2] = { 0 };	
	char int_part_a[SIZE+1] = { 0 };	
	char int_part_b[SIZE+1] = { 0 };

	//���� ������ ���� ���ڿ� ����
	//strcpy : ���� ���ڿ��� �� ���ڱ��� �����Ͽ� ��� �迭�� �״�� �����ϴ�  Cǥ���Լ�
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);

	//����� �����ڸ� ���� ���
	Reverse(int_part_a);
	Reverse(int_part_b);

	//���ϱ� ��� ��
	for (int i = 0; i <SIZE; i++)
	{
		int temp = (int_part_a[i] - '0') + (int_part_b[i] -'0') + carry;
		int_result[i] = (temp % 10) + '0';
		carry = temp / 10;
	}
	// ������ �ڸ����� ��� �� ĳ���� ���������� ��� �迭�� �߰� 
	if (carry > 0)
	{
		int_result[SIZE] = carry + '0';
		int_result[SIZE + 1] = '\0';
	}
	else 
		int_result[SIZE] = '\0';

	// �ٽ� ������ ������
	Reverse(int_result);

	// ��� ���
	printf("��� : ");
	PrintBignum(int_result);
}
// ���� ���� �Լ� 
void BignumSub(big* bignum)
{
	//���� �ڸ� ����
	int borrow = 0;	

	//��� �� ���� ���� �迭
	char int_result[SIZE + 2] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//���� ������ ���� ���ڿ� ����
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);

	// ū�� �� flag = 0 : int_part_b �� ŭ ,flag =1 : int_part_a�� ŭ
	int flag = Compare(int_part_a, int_part_b);
	if (!flag)
	{
		// �׻� ū�� - �������� �ǵ��� Swap
		Swap(int_part_a, int_part_b);
		printf("-");
	}
	//���� ��� ��
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int diff = (int_part_a[i]-'0') - (int_part_b[i]-'0') - borrow;

		//diff�� 0���� ������ 1��������, diff �� 10 �����ֱ�
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
	//��� ��� 
	printf("��� : ");
	PrintBignum(int_result);
}
//���� ���ϱ� �Լ� 
void BignumMul(big* bignum)
{
	int mul = 0;	//�ø� �ڸ� ����

	//��� �� ���� ���� �迭
	char int_result[4 * SIZE + 2] = {0};
	char int_part_a[SIZE + 1] = {0};
	char int_part_b[SIZE + 1] = {0};
	int mul_result[2 * SIZE + 2] = {0};

	//���� ������ ���� ���ڿ� ����
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);

	//�����ڸ� ���� ���
	Reverse(int_part_a);
	Reverse(int_part_b);

	//���� ��� ��
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// int_part_a[i]�� int_part_b[j]�� ���ؼ� mul_result[i + j]�� ����
			mul_result[i + j] += (int_part_a[i]-'0') * (int_part_b[j]-'0');
		}
	}

	//�ڸ��ø� ó�� 
	for (int i = 0; i < 2 *SIZE; i++)
	{
		int_result[i] = (mul_result[i] + mul) % 10 + '0';
		mul = (mul_result[i] + mul) / 10;
	}

	// ������ �ڸ����� ��� �� ĳ���� ���������� ��� �迭�� �߰�
	if (mul > 0)
	{
		int_result[2 * SIZE] = mul + '0';
		int_result[2 * SIZE + 1] = '\0';
	}
	else
		int_result[2 * SIZE] = '\0';

	//�ٽ� ������ ������
	Reverse(int_result);
	//��� ���
	printf("��� : ");
	PrintBignum(int_result);
}
//�Ǽ� ���� �Լ� 
void BigFloatAdd(big *bignum)
{
	int carry = 0;
	int idx = 0;
	
	//��� �� ���� ���� �迭
	char int_result[SIZE + 2] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//��� �� �Ҽ��� �� �� ���� �迭
	char frac_result[SIZE + 2] = { 0 };
	char frac_part_a[SIZE + 1] = { 0 };
	char frac_part_b[SIZE + 1] = { 0 };

	//���� ������ ���� ���ڿ� ���� 
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);
	strcpy(frac_part_a, bignum[0].dot_digit);
	strcpy(frac_part_b, bignum[1].dot_digit);

	//����� �����ڸ����� ���
	Reverse(frac_part_a);
	Reverse(frac_part_b);
	Reverse(int_part_a);
	Reverse(int_part_b);

	//���� ��� �� (���� �κ�)
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

	//���� ��� �� (�Ҽ��� �޺κ�)
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

	//�����ڸ��� 10 �̻��̸� �տ� �ڸ��ø� 
	while (num >= 10 && idx<SIZE)
	{
		// ���ڸ�(idx+1)�� 1�� ���� �ڸ��ø�
		int_result[idx + 1] = ((int_result[idx + 1] - '0') + 1)+'0';
		// ���� �ڸ��� 0~9�� ����
		int_result[idx] = ((int_result[idx] - '0') % 10) +'0';
		// ���� �ڸ��� �̵�
		num = (int_result[++idx] - '0');
	}

	//������ ������
	Reverse(frac_result);
	Reverse(int_result);

	//��� ���
	printf("��� : ");
	PrintBignum(int_result);
	printf(".%s", frac_result);
}
//�Ǽ� ���� �Լ� 
void BigFloatSub(big* bignum)
{
	int borrow = 0;
	int idx = SIZE - 1;

	//��� �� ���� ���� �迭
	char int_result[SIZE + 2] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//��� �� �Ҽ��� �� �� ���� �迭
	char frac_result[SIZE + 2] = { 0 };
	char frac_part_a[SIZE + 1] = { 0 };
	char frac_part_b[SIZE + 1] = { 0 };

	//���������� ���� ���ڿ� ���� 
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);
	strcpy(frac_part_a, bignum[0].dot_digit);
	strcpy(frac_part_b, bignum[1].dot_digit);

	// ū�� �� flag = 0 : bignum_2 �� ŭ ,flag =1 : bignum_1�� ŭ
	int flag = Compare(int_part_a, int_part_b);
	if (!flag)
	{
			Swap(int_part_a, int_part_b);	//���� �κ�
			Swap(frac_part_a, frac_part_b);	//�Ҽ��� �� �κ� 
	}

	//���� ��� �� (�Ҽ��� �� �κ�)
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int diff_2 = (frac_part_a[i] - '0') - (frac_part_b[i] - '0') - borrow;
		//diff_2�� 0���� ������ 1 ��������, diff_2 �� 10 �����ֱ�
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

	// borrow�� �����ִٸ� ���� �κп��� 1 ��������
	if (borrow == 1)
	{
		// �����ʺ��� 0�� 9�� �ٲٸ� ���� �ڸ� ã��
		while (idx >= 0 && int_part_a[idx] == '0')
		{
			int_part_a[idx] = '9';
			idx--;
		}
		// 0�� �ƴ� �ڸ����� 1 ����
		if (idx >= 0)	int_part_a[idx]--;
	}

	//���� ��� �� (���� �κ�) 
	borrow = 0;
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int diff = (int_part_a[i] - '0') - (int_part_b[i] - '0') - borrow;

		//diff�� 0���� ������ 1 ��������, diff �� 10 �����ֱ�
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

	idx = SIZE - 1;	//idx �ʱ�ȭ

	int num = (int_result[idx] - '0');
	
	// ���� �κп��� �����ڸ��� 0�̸��Ͻ� ó��
	while (num < 0 && idx >0)
	{
		// ���� �ڸ��� 10�� ���� 0~9�� ����
		int_result[idx] = ((int_result[idx] - '0') + 10) + '0';
		// �ٷ� ���ڸ����� 1�� ���� ���� ó��
		int_result[idx - 1] = ((int_result[idx - 1] - '0') - 1) + '0';
		// ���ڸ��� �̵��Ͽ� �ݺ�
		num = (int_result[--idx] - '0');
	}

	//��� ��� 
	printf("��� : ");
	if (!flag) 		printf("-");
	PrintBignum(int_result);
	printf(".%s", frac_result);
}
//�Ǽ� ���� �Լ� 
void BigFloatMul(big* bignum)
{
	int mul = 0;
	int idx = 0;

	//��� �� ���� ���� �迭
	char int_result[4 * SIZE + 3] = { 0 };
	char int_part_a[SIZE + 1] = { 0 };
	char int_part_b[SIZE + 1] = { 0 };

	//��� �� �Ҽ��� �� �� ���� �迭
	char frac_result[2 *SIZE + 2] = { 0 };
	char frac_part_a[SIZE + 1] = { 0 };
	char frac_part_b[SIZE + 1] = { 0 };

	//���� + �Ǽ� ���ڿ� ���� �迭
	char full_number[2 * SIZE + 2] = { 0 };
	char full_number_2[2 * SIZE + 2] = { 0 };
	
	//�ӽ� ���� �迭
	int mul_result[4 * SIZE + 2] = { 0 };


	//���������� ���� ���ڿ�����
	strcpy(int_part_a, bignum[0].digit);
	strcpy(int_part_b, bignum[1].digit);
	strcpy(frac_part_a, bignum[0].dot_digit);
	strcpy(frac_part_b, bignum[1].dot_digit);
	
	//���ڿ� �̾� ���̱�
	//strcat : ��� ���ڿ� ���� �ٸ� ���ڿ��� �̾�ٿ� �ϳ��� ���ڿ��� ����� Cǥ���Լ�
	strcat(full_number,int_part_a);
	strcat(full_number, frac_part_a);
	strcat(full_number_2, int_part_b);
	strcat(full_number_2, frac_part_b);

	//����� �����ڸ� ���� ��� 
	Reverse(full_number);
	Reverse(full_number_2);

	//���� ��� ��
	for (int i = 0; i < 2 *SIZE; i++)
	{
		for (int j = 0; j <2* SIZE; j++)
		{
			// bignum_1[i]�� bignum_2[j]�� ���ؼ� temp[i + j]�� ����
			mul_result[i + j] += (full_number[i] - '0') * (full_number_2[j] - '0');
		}
	}

	//�ڸ��ø� ó�� 
	for (int i = 0; i < 4 * SIZE; i++)
	{
		int_result[i] = (mul_result[i] + mul) % 10 + '0';
		mul = (mul_result[i] + mul) / 10;
	}

	// ������ �ڸ����� ��� �� ĳ���� ���������� ��� �迭�� �߰� 
	if (mul > 0)
	{
		int_result[4 * SIZE] = mul + '0';
		int_result[4 * SIZE + 1] = '\0';
	}
	else
		int_result[4 * SIZE] = '\0';

	//�ٽ� ������ ������
	Reverse(int_result);

	// �Ҽ��� �ڸ� ã�� 
	int len = strlen(frac_part_a)+ strlen(frac_part_b);
	int total_len = strlen(int_result);
	
	//���� �迭 �Ҽ����������� ��ĭ�� �ڷ� �б�
	for (int i = total_len; i >=total_len-len; i--)
	{
		int_result[i+1] = int_result[i];
	}
	int_result[total_len-len] = '.';
	int_result[total_len + 1] = '\0';

	//��� ��� 
	printf("��� : ");
	PrintBignum(int_result);
}