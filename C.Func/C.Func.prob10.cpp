//���� 10 , ����
//����ڰ� 1 �� ������ +, 2 �� ������ - �� ���� ������� �ؼ� ����� �˴ϴ�. ���� ������ ��� ����� ��� �����Ǿ�� �ϰ�, ����� ���

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
int Add(int* num);	// ���ϱ�
int Min(int* num);	// ����
int Mul(int* num);	// ���ϱ�
int Div(int* num);	// ������
void CE(int* num);	// �Է°� �ʱ�ȭ
void Put(int* num);	// �߰� ���
int AC(int* num);	// ��ü �ʱ�ȭ

int main()
{

	int num[2];	//���� ���� �迭

	//���� �Է�
	for (int i = 0; i <=1; i++)
	{
		printf("����  �Է� : ");
		scanf("%d", &num[i]);
	}
	//���� 
	while (1)
	{
		int op;	
		printf("�Էµ� �� : %d , %d\n", num[0], num[1]);	//�Է� �� �� ���
		printf("1 : +	2 : -	3 : *	4 : /	5 : CE	6 : AC	7 : �߰� ���	8 : ����\n");	
		printf("���� ���� : ");
		scanf("%d", &op);
		// �Է¹��� op ���ǹ� ����
		if (op == 1)	
		{
			printf("%d + %d = %d\n", num[0], num[1], Add(num));	//���ϱ� ��� ���
			num[0] = Add(num);	//������ num[0] �� �Է�
		}
		else if (op == 2)
		{
			printf("%d - %d = %d\n", num[0], num[1], Min(num));	//����	��� ���
			num[0] = Min(num);
		}
		else if (op == 3)
		{
			printf("%d * %d = %d\n", num[0], num[1], Mul(num));	//���ϱ� ��� ���
			num[0] = Mul(num);
		}
		else if (op == 4)
		{
			if(num[0] < num[1])	printf("%d %% %d = %d\n", num[0], num[1],Div(num));	//������ ��� ���(������)
			else printf("%d / %d = %d\n", num[0], num[1], Div(num));	//������ ��� ��� (��)
			num[0] = Div(num);
		}
		else if (op == 5)	CE(num);	//�Է°� �ʱ�ȭ
		else if (op == 6)
		{
			if(AC(num)) break;	//��ü �ʱ�ȭ
		}
		else if (op == 7)	Put(num);	//�߰� ���	
		else if (op == 8)	// ����
		{
			printf("�ý��� ����\n");	
			break;
		}
		else printf("���� ������. �ٽ� �������ּ���\n");
	}
	return 0;
}
// ���ϱ�
int Add(int* num)
{	
	return num[0] + num[1];
}
// ����
int Min(int* num)
{
	return num[0] - num[1];
}
// ���ϱ�
int Mul(int* num)
{
	return num[0] * num[1];
}
// ������
int Div(int* num)
{
	// 0�Ͻ� ������ ���ϴ� num[0] �ٽ� ��ȯ
	if (num[1] == 0) {
		printf("0���� ���� �� �����ϴ�!\n");
		return num[0]; 
	}
	if (num[0] < num[1])
		return num[0] % num[1];
	return num[0] / num[1];
}
// �Է°� �ʱ�ȭ
void CE(int* num)
{
	printf("�Է� �� ����\n");
	num[1] = 0;
	printf("���ο� �� �Է� : ");
	scanf("%d", &num[1]);
}
// ��ü �ʱ�ȭ
int AC(int* num)
{
	int op;

	printf("��ü �ʱ�ȭ�� �Ϸ�Ǿ����ϴ�.\n");
	printf("�ʱ�ȭ �� �ý��� ���Ḧ ���Ͻø� 8�� �Է��ϼ���. ����Ϸ��� �ƹ� ���ڳ� �Է��ϼ���: ");
	num[0] = 0;
	num[1] = 0;
	scanf("%d", &op);
	if (op == 8)
	{
		printf("�ý��� ����");
		return 1;
	}
	for (int i = 0; i < 2; i++)
	{
		printf("���ο� �� �Է� : ");
		scanf("%d", &num[i]);
	}
	return 0;
}
// �߰� ���
void Put(int* num)
{
	printf("���ο� �� �Է� : ");
	scanf("%d", &num[1]);
}