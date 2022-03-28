//Binary file (xxx.bin) 파일에서 명령어를 읽어 메모리에 저장하고 
//                      각각이 어떤 명령어인지를 하나씩 해석하는 프로그램을 작성한다.
FILE *pFile = NULL;
pFile = fopen("input.bin", "rb");
if (!pFile) {
    perror("fopen");
    exit(EXIT_FAILURE);
}
#include "stdio.h"

const int M_SIZE = 1024;
unsigned char MEM[M_SIZE]; //배열의 인덱스가 MEM을 접근하기 위한 주소가 됨, unsigned char : 1byte

unsinged int IR;

//각 함수에서 입력 받은 addr이 aligned access 인지 검사하고
// aligned access가 아닐 경우에는 오류 메시지를 출력하고
// addr을 aligned access가 되도록 주소를 교정하여 MEM을 access한다.

unsigned int memoryRead(unsigned int addr)//메모리를 word 단위로 읽는 함수
{
    ...
}
void memoryWrite(unsigned int addr, unsigned int data)//메모리를 word단위로 쓰는 함수
{
    ...
}

int main()
{
  FILE *pFile = NULL;
  char *inFile = "input.bin";
  errno_t err;

  err = fopen_s(&pFile, inFile, “rb");
  if (err) {
    printf("Cannot open file\n");
    return 1;
  }
  // 1. read given executable file and extract
  //    information and write the instructions
  //    to memory


  // 2. read instructions and decode
  //    then, print the instruction names


  fclose(pFile);

  return 0;
}
