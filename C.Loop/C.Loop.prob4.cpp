// ���� 4 , 1000000 ������ �Ǻ���ġ ����  �� ¦�� �׵��� ���� ���Ѵ�   ( 1 1 2 3 5 8 13 21 ..)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int  num = 1000000;
	int fb_1 = 1;  // (n-1) ��
	int fb_2 = 1;  //  (n-2) ��
	int fb = 0;    // ���� n��
	int sum = 0;
	printf("%d-%d", fb_1, fb_2);
	// �Ǻ���ġ ����  n = (n-1) + (n-2)
	while (fb <= 1000000) // �Ǻ���ġ ������ ������ ���� �־��� ���� 1000000 ���� �ΰ� �Ǻ� 
	{
		fb = fb_1 + fb_2;   // ���� n�� ���
		fb_2 = fb_1;
		fb_1 = fb;
		printf("-%d", fb);  //   n �� �´��� Ȯ�� 
		if (fb % 2 == 0) sum += fb;
	}
	printf("\n¦���� �� : %d", sum);

	return 0;
}