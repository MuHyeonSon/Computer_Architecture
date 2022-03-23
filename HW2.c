// 바이오메디컬공학부 201804594 손무현
// 컴퓨터구조 레포트2

// big-endian 형태로 데이터가 저장된 binary file에서
// 4-byte 정수들을 읽고 이를 little-endian 형태로 파일에
// 저장하는 프로그램을 작성한다.

#include <stdio.h>

int main()
{ 
  FILE *iFile = fopen("input.bin","rb");
    err = fopen_s(&pFile, "test.bin", "rb");
  if (err) {
    printf("Cannot open file\n");
    return 1;
  }
    while (1) {
    count = fread(&data, sizeof(data1), 1, pFile);
    if (count  != 1)
      break;
    printf("%8x\n", data);
  }
  fclose(pFile);


  FILE *pFile = NULL;
  errno_t err;
  int count;
  unsigned int data;
  unsigned int data1 = 0xAABBCCDD;
  unsigned int data2 = 0x11223344;

  // open a file to write data
  err = fopen_s(&, "input.bin", "wb");
  if (err) {
    printf("Cannot open file\n");
    return 1;
  }
  fwrite(&data1, sizeof(data1), 1, pFile);
  fwrite(&data2, sizeof(data2), 1, pFile);
  fclose(pFile);

  // open a file to read data
  err = fopen_s(&pFile, "test.bin", "rb");
  if (err) {
    printf("Cannot open file\n");
    return 1;
  }
    while (1) {
    count = fread(&data, sizeof(data1), 1, pFile);
    if (count  != 1)
      break;
    printf("%8x\n", data);
  }
  fclose(pFile);

  return 0;
}

unsigned int invertEndian(unsigned int inVal)
{
    int s = 1;
    char e;
    if(Big_Endian) 
    {
        e = 'b'
    }
    else
    {
        e = 'l'
    }
    if(e == 'b')
    {
        unsigned char bytes[4];
        int outVal;

        bytes[0] = (unsigned char)((inVal >> 24) & 0xff);
        bytes[1] = (unsigned char)((inVal >> 16) & 0xff);
        bytes[2] = (unsigned char)((inVal >> 8) & 0xff);
        bytes[3] = (unsigned char)((inVal >> 0) & 0xff);

        outVal = ((int)bytes[0] << 0) |
                 ((int)bytes[0] << 8) |  
                 ((int)bytes[0] << 16) |
                 ((int)bytes[0] << 24) |
        return outVal
    }
    else
    {
        unsigned char bytes[4];
        int outVal;

        bytes[0] = (unsigned char)((inVal >> 0) & 0xff);
        bytes[1] = (unsigned char)((inVal >> 8) & 0xff);
        bytes[2] = (unsigned char)((inVal >> 16) & 0xff);
        bytes[3] = (unsigned char)((inVal >> 24) & 0xff);

        outVal = ((int)bytes[0] << 24) |
                 ((int)bytes[0] << 16) |  
                 ((int)bytes[0] << 8) |
                 ((int)bytes[0] << 0) |
        return outVal
    }
}
