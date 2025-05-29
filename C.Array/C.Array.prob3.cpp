//문제 3 , 소수  1000개찾아서 배열에 넣기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	int prime[1000];   // 소수 저장 배열
	prime[0] = 2;      //  첫번째 두번째 소수 2 , 3 배열에 저장
	prime[1] = 3;
	int prime_number = 5; //소수 인지아닌지 판별할 수 
	int index = 2;	  // 배열 인덱스

	// 소수 판별 및 배열 저장
	while (index < 1000)  //1000개 소수 찾을때까지
	{
		int count = 0;
		for (int i = 0; i < index; i++)
		{
			if (prime_number % prime[i] != 0) count++;  // 나누어 떨어지지않으면 count ++
			else break;	//나누어 떨어지면 소수 X
		}
		if (count == index)
		{
			prime[index] = prime_number;
			index++;
		}
		prime_number += 2;
	}
	// 결과 출력 
	for (int i = 0; i < index; i++)
	{
		printf("소수 :%d\n", prime[i]);
	}
	return 0;
}