// ���� 5, ���Ͽ��� Ư���� �ܾ �˻��Ͽ� �� ��° �ٿ� �������� ��� ����ϴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//���� ����
	FILE* fp = fopen("D:\\study\\prob5.txt", "w+");
	
	//���Ͽ� ���� ���� 
	fputs(
		"C is a foundational programming language that has played a crucial role in the development of modern software systems\n\
		Its syntax and structure have influenced many other languages,\n\
		making it an essential tool for understanding core programming.", fp);

	fclose(fp); //���� �ݱ�
	
	//ã�� ���� �迭 
	char buffer[1024];
	char search[1024];
	printf("ã�� ���ڿ� : ");

	//���� ���� �Է� �ޱ� 
	//stdin : ǥ�� �Է�(Ű���� �Է� ��)�� �ǹ��ϴ� ���� ��Ʈ��
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")] = '\0'; // �ٹٲ� ���ڰ� ���� ������ �˻��� ����� �ȵ� �� �ֱ� ������ NULL�� ����

	int found = 0;
	int line = 1;

	//���� ����
	fp = fopen("D:\\study\\prob5.txt", "r");

	//���پ� �о� �κ� ���ڿ� �˻� 
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if (strstr(buffer, search) != NULL)
		{
			//��ġ �ϴٸ� ���
			printf("%d���ٿ� �ֽ��ϴ�.\n", line);
			found = 1;
		}
		line++;	//���� �ٷ� �̵�
	}
	//������ �ȳ�
	if (!found) printf("�����ϴ�.");

	//���� �ݱ�
	fclose(fp);
	return 0;
}