// ���� 5, ���Ͽ��� Ư���� ���ڸ� �˻��Ͽ� �� ���� �������� ����ϴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//���� ����
	FILE* fp = fopen("D:\\study\\prob6.txt", "w+");
	//���Ͽ� ���� ���� 
	fputs(
	"One of the strengths of C is its powerful handling of data structures and memory management.\n\
	Programmers can define complex structures, manage dynamic memory allocation, and manipulate pointers to optimize performance.\n\
	This level of control is especially valuable in developing systems like library management software,\n\
	where efficient data organization and processing are critical", fp);
	fclose(fp);

	//ã�� ���� �迭 
	char buffer[1024];
	char search[1024];
	
	//���� ���� �Է� �ޱ� 
	printf("ã�� ���� : ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")] = '\0'; // �ٹٲ� ���ڰ� ���� ������ �˻��� ����� �ȵ� �� �ֱ� ������ NULL�� ����

		//���� ����
	fp = fopen("D:\\study\\prob6.txt", "r");

	int count = 0; 
	int idx = 0;

	//���پ� �о� �κ� ���ڿ� �˻� 
	while (fgets(buffer, sizeof(buffer), fp))
	{
		char* p = buffer;	//���� �� �ּ� ������
		char* found;		//�߰ߵ� ��ġ ���� ������

		while ((found = strstr(p, search)) !=NULL)	//���� �ٿ� �˻� ���ڿ� �ִ��� �ݺ�
		{
			count++;
			p = found + strlen(search);	//ã�� ��ġ �������� �ٽ� �˻� ���� 
			//+ strlen(search)�� ã�� ���ڿ��� "��" �������� �ٽ� �˻��ϱ� ����
			//strstr�� ã�� ���ڿ��� ù�κ��� �ּҸ� ��ȯ 
		}
		
	}
	//��� ���
	printf("%d�� �ֽ��ϴ�", count);

	//���� �ݱ�
	fclose(fp);
	return 0;
}