//컴퓨터구조 report5
//ALU_simulation

#include <stdio.h>

int ALU(int X, int Y, int S, int *Z);

int logicOperation(int X, int Y, int s1s0); //논리 연산을 담당하는 함수 if S3S2 == 0b11
                                            //s1s0에 따라서 AND, OR, XOR, NOR
int shiftOperation(int X, int Y, int s1s0); //시프트 연산을 담당하는 함수 if S3S2 == 0b00
                                            //s1s0에 따라서 No shift, SLL, SRL, SRA
int addSubtract(int X, int Y, int s0);      //산술연산을 담당하는 함수 if S3S2 == 0b10 or S3S2 == 0b01
                                            //s0에 따라서 ADD, SUB
int checkSetLess (int X, int Y);            //less than을 검사하는 함수 if S3S2 == 0b01
//LT(<) = 1 if X < Y: addSubtract() 함수를 이용하여 빼기를 수행하고 반환값의 MSB를 반환한다.

int checkZero(int Oa); //Add/Sub 모듈의 연산 결과가 0인지 검사하는 함수
                       //ZERO = 1 if Oa == 0, else ZERO = 0


int main(){
    
    int x,y,c,s,z;

    x = 00000003;
    y = 00000006;
    c = 2;
    printf("x: %8x, y: %8x\n", x, y);
    for (int i=0; i<16; i++) {
        s = ALU(x, y, i, &z);
        printf("s: %8x, z: %8x\n");
    }

   return 0;
}


    //피연산자 x
    //피연산자 y
    //연산자(제어값)
    //z 연산자의 결과가 0인지를 나타내는 값 0 -> z:1 , else -> z:0 

    //int O = ALU(x,y,s); // z값은 포인터를 이용해서 반환

    //printf("O = %d,Z = %d\n",O,z);



int ALU(int X, int Y, int c, int *Z)
{  
  int c32, c10;
  int ret;

  c32 = (c >> 2) & 0x3;
  c10 = c & 0x3;
  if (c32 == 0) { // shift
    ret = shiftOperation(X, Y, c10);
  } else if (c32 == 1) { // set less
    ret = checkSetLess (X,Y);
  } else if (c32 == 2) {// addsub
    ret = addSubtract (X,Y,1);
    *Z = checkZero(ret);
    
    } else {  // logic
    ret = logicOperation(X, Y, c10);
  }
   return ret;
}



int logicOperation (int X, int Y, int s1s0)
{
        if ( s1s0 < 0 || s1s0 > 3 ) {
            printf("error in logic\n");
            exit(1);
        }
        if (s1s0 == 0)
        	return X&Y;
        else if (s1s0 == 1)
        	return X|Y;
        else if (s1s0 == 2)
        	return X^Y;
        else
        	return ~(X^Y);
}

// V is 5bit shift amount
int shiftOperation (int V, int Y, int s1s0) {
    int ret;
    if ( s1s0 < 0 || s1s0 > 3 ) {
        printf("error in shift\n");
        exit(1);
    }
    if (s1s0 == 0) {
        //;
        ret = Y ;
    } else if (s1s0 == 1) {
        //…;
        ret = Y << V;
    } else if (s1s0 == 2) {
        //…;
        ret = Y >> V;
    } else {
        //…;
        ret = Y << V; // SRA??
    }
    return ret;
}




int addSubtract (int X, int Y, int s0)
{   
    int ret;
    if ( s0 < 0 || s0 > 1 ) {
        printf("error in addSubtract\n");
        exit(1);
    }
    if (s0 == 0) { // add
        //
      ret = X + Y;
    } else {       // subtract
        //…
        ret = X - Y;
    } 
        return ret;
}

int checkSetLess (int X, int Y) {
    int ret;
 
    // check if X < Y using addSubtract()
    //  and return 1 if it is true
    //  else return 0
    int resul = X - Y;
    if (resul < 0){
        ret = 1;
    }
    else{
        ret = 0;
    }

    return ret;
}

int checkZero(int Oa)
{    
    int ret;

    if(Oa == 0){
        ret = 1;
    }
    else{
        ret = 0;
    }
 
    // check if the result Oa is zero,
    //  and return 1 if it is
    //  else return 0

    return ret;
}

