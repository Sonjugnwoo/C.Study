//���� 13 , 1000 �ڸ��� ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 1000

//�Լ� ����
void BignumAdd(char* bignum_1, char* bignum_2);	//���ϱ� �Լ�
void BignumMin(char* bignum_1, char* bignum_2);	// ���� �Լ� 
void BignumMul(char* bignum_1, char* bignum_2);	// ���ϱ� �Լ�
void BignumDiv(char* bignum_1, char* bignum_2);	// ������ �Լ� (�̱���)
void Reverse(char* bignum_1, char* bignum_2);	// ������ �Լ�
int Compare(char* bignum_1, char* bignum_2);	// �� �Լ�

int main()
{
	char bignum_1[SIZE + 1];	//1000�ڸ� �� ���� �迭_1
	char bignum_2[SIZE + 1];	//1000�ڸ� �� ���� �迭_2

	// ���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand((unsigned int)time(NULL));	

	//ù�ڸ� 1~9�� �����
	bignum_1[0] = '1' + rand() % 9;	
	bignum_2[0] = '1' + rand() % 9;

	//ù�ڸ� ���� 1~9������
	for (int i = 1; i < SIZE; i++)
	{
		bignum_1[i] = '0' + rand() % 10;
		bignum_2[i] = '0' + rand() % 10;
	}
	// ���ڿ��� ���� NULL ���� ���� ( ���ڿ��� �������� NULL )
	bignum_1[SIZE] = '\0';
	bignum_2[SIZE] = '\0';
	
	// ������ ū �� ���
	printf("ù��° ū�� : %s\n", bignum_1);
	printf("�ι�° ū�� : %s\n", bignum_2);


	BignumAdd(bignum_1, bignum_2);	//����
	BignumMin(bignum_1, bignum_2);	//���� 
	BignumMul(bignum_1, bignum_2);	//����
	//BignumDiv(bignum_1, bignum_2);//������	
	return 0;
}

// ������ �Լ� 
void Reverse(char* bignum)
{
	int len = strlen(bignum);	 // ���ڿ� ���� ��� 

	// ���ڿ��� �հ� �ڸ� ��ȯ�Ͽ� ������
	for (int i = 0; i <len/2; i++)
	{
		char temp = bignum[i];
		bignum[i] = bignum[len-1-i];
		bignum[len-1-i] = temp;
	}
}
// �� �Լ� 
int Compare(char* bignum_1, char* bignum_2)
{
	//��ȯ��: bignum_1 >= bignum_2 �̸� 1, �ƴϸ� 0
	for (int i = 0; i < SIZE; i++)
	{
		//bignum_1 < bignum_2 0 ��ȯ
		if (bignum_1[i] < bignum_2[i])	
		{
			return 0;
		}
		//bignum_1 > bignum_2 1 ��ȯ
		else if (bignum_1[i] > bignum_2[i])
			return 1;
	}
	return 1;  
}
// ū �� ������ ����
void Swap(char* bignum_1, char* bignum_2)
{
	//�� �ڸ� ���� ��ȯ
	for (int i = 0; i < SIZE; i++)
	{
		int temp = bignum_1[i];		//�ӽ� ������ bignum_1 ����
		bignum_1[i] = bignum_2[i];	//bignum_1 �� bignum_2 ����
		bignum_2[i] = temp;			//bignum_2 �� �ӽ� ���� ����
	}
}
// ��� �Լ� 
void PrintBignum(char * bignum)
{
	int i = 0;
	while (i < SIZE - 1 && bignum[i] == '0') i++;	//���ڸ��� 0 �̸� i ����
	printf("%s\n", bignum + i); // i ���� ��� ����
}
// ���ϱ� �Լ� 
void BignumAdd(char * bignum_1,char *bignum_2)
{
	char result[SIZE + 2] ={'0'};	// ������� ������ �迭
	int carry = 0;					//�ø� �ڸ� ����

	//����� �����ڸ� ���� ���
	Reverse(bignum_1);
	Reverse(bignum_2);

	//���ϱ� ��� ��
	for (int i = 0; i < SIZE; i++)
	{
		int temp = (bignum_1[i] - '0') + (bignum_2[i] - '0') + carry;
		result[i] = (temp % 10) +'0';	//�����ڸ�
		carry = temp / 10;				//���� �ڸ��� ���� �ڸ���
	}

	// ������ �ڸ����� ��� �� ĳ���� ���������� ��� �迭�� �߰� 
	if (carry > 0)
	{
		result[SIZE] = carry +'0';
		result[SIZE+1] = '\0';	// ���ڿ� ���� NULL ����
	}
	else
		result[SIZE] = '\0';	// ���ڿ� ���� NULL ����

		// �ٽ� ������ ������
		Reverse(result);	

		// ��� ���
		PrintBignum(result);
}
// ���� �Լ� 
void BignumMin(char* bignum_1, char* bignum_2)
{
	char result[SIZE + 1] = { '0'};	// ������� ������ �迭
	int borrow = 0;					//���� �ڸ� ����

	// ū�� �� flag = 0 : bignum_2 �� ŭ ,flag =1 : bignum_1�� ŭ
	int flag  = Compare(bignum_1, bignum_2);

	// �׻� ū�� - �������� �ǵ��� Swap
	if (!flag)	Swap(bignum_1, bignum_2);		
	
	//���� ��� ��
	for (int i = SIZE-1; i >=0; i--)
	{

		int diff_1 = (bignum_1[i] - '0') + borrow;
		int diff_2 = bignum_2[i] - '0';
		int diff = diff_1 - diff_2;

		//diff�� 0���� ������ 1��������, diff �� 10 �����ֱ�
		if (diff < 0)
		{
			borrow = -1;
			diff += 10;
		}
		else
			borrow = 0;

		bignum_1[i] = diff  + '0';
	}
	bignum_1[SIZE] = '\0'; // ���ڿ� ���� NULL ����

	//bignum_1�� result�� �ֱ�
	for (int i = 0; i < SIZE; i++)
	{
		result[i] = bignum_1[i];
	}
	
	result[SIZE] = '\0'; // ���ڿ� ���� NULL ����

	// flag �� 0�̸�  bignum_2�� �� �Ǳ� ������ - ��� 
	if (!flag) printf("-");

	// ��� ���
	PrintBignum(result);
}
//  ���ϱ� �Լ� 
void BignumMul(char* bignum_1, char* bignum_2)
{
	int temp[2 * SIZE + 2 ] = {0};			 //�� �ڸ� ���� ����� ������ �ӽ� �迭
	char result[2 * SIZE + 2] = { '0' };	//���� ����� ������ ���ڿ� �迭
	int mul = 0;							//�ø� �ڸ� ����

	//����� �����ڸ� ���� ���
	Reverse(bignum_1);
	Reverse(bignum_2);

	//���� ��� ��
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// bignum_1[i]�� bignum_2[j]�� ���ؼ� temp[i + j]�� ����
			temp[i+j] += (bignum_1[i] - '0') * (bignum_2[j] - '0');	
		}
	}
	//�ڸ��ø� ó�� 
	for (int i = 0; i < 2*SIZE; i++)
	{
		result[i] = ((temp[i] + mul) % 10) +'0';
		mul = (temp[i]+mul) / 10;
	}
	// ������ �ڸ����� ��� �� ĳ���� ���������� ��� �迭�� �߰� 
	if (mul > 0)
	{
		result[2 * SIZE] = mul + '0';
		result[2 * SIZE + 1] = '\0';	// ���ڿ� ���� NULL ����
	}
	else
		result[2 * SIZE] = '\0';		// ���ڿ� ���� NULL ����


	//�ٽ� ������ ������
	Reverse(result);

	//��� ���
	PrintBignum(result);
}

/* �̱���....
void BignumDiv(char* bignum_1, char* bignum_2)
{
	char quot[SIZE + 1] = { 0 };
	char rema[SIZE + 2] = { 0 }; // �� �ڸ� �� ����
	rema[0] = '0';
	rema[1] = '\0';

	for (int i = 0; i < SIZE; i++)
	{
		// rema�� ���� �ڸ��� ���̱�
		int len = strlen(rema);
		rema[len] = bignum_1[i];
		rema[len + 1] = '\0';

		// �� �ڸ� ���ϱ�
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