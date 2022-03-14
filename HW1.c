//컴퓨터구조 1주차 과제 프로그램 
//바이오메디컬공학부 손무현

#include <stdio.h>
#include <stdlib.h> //rand()함수를 포함하는 라이브러리
#include <time.h>

void testOperator(int x, int y);

int main()
{
    int x = 0;
    int y = 0;
    //int sum = 0;

    srand(time(NULL)); // 계속 다른 시드값을 생성

    for (int i = 0; i < 5; i++)
    {
        x = rand()%10;
        y = rand()%10;
        testOperator(x,y);
    }

    return 0;
}

void testOperator(int x, int y)
{
  printf("x = %X\n",x); // 인수로 받은 정수x를 hexa로 표현
  printf("y = %X\n",y); // 인수로 받은 정수y를 hexa로 표현
  
  int s_x = x << 3; //shift 연산(x의 이진표현을 왼쪽으로 3칸 shift)
  int s_y = y >> 1; //shift 연산(y의 이진표현을 오른쪽으로 1칸 shift)
  
  printf("shift 연산이 수행된 x = %X\n",s_x); //그 결과 값을 hexa로 표시하여 비트 단위의 값이 어떻게 연산되었는 지 볼 수 있도록 한다
  printf("shift 연산이 수행된 y = %X\n",s_y); //그 결과 값을 hexa로 표시하여 비트 단위의 값이 어떻게 연산되었는 지 볼 수 있도록 한다
  
  int b_and = x & y; //비트wise 논리 연산(x와 y의 비트에 동시에 1이 있는 경우 1)
  int b_or = x | y; //비트wise 논리 연산(x와 y의 비트에 하나라도 1이 있는 경우 1)
  
  printf("비트wise논리연산(and)이 수행 x & y = %X\n",b_and); //그 결과 값을 hexa로 표시하여 비트 단위의 값이 어떻게 연산되었는 지 볼 수 있도록 한다
  printf("비트wise논리연산(or)이 수행 x | y = %X\n",b_or); //그 결과 값을 hexa로 표시하여 비트 단위의 값이 어떻게 연산되었는 지 볼 수 있도록 한다
}
