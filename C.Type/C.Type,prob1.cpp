//문제 1 , 임의의 실수에서 소수점 이하 두자리수만 추출하여 정수형 변수에 대입하라. 
//예를들어 사용자로부터 입력받은 실수 f 가 12.3456이라면 34만 추출한다
#include <stdio.h>

int main()
{
	float f;
	float f2;
	int i;

	printf("실수 입력 : ");
	scanf_s("%f", &f);
	// 형변환후 소수점 둘째자리 추출
	i = int(f);
	f2 = 100 * (f - i);
	// 실수를 먼저 판별
	if (f - int(f) == 0)	printf("실수가 아닙니다.\n%d", int(f2));
	{
		if (i < 0)	printf("%d", -int(f2));   // f 값이 음수일때
		else printf("%d", int(f2));  // 정상 출력
	}
	return 0;
}
