//MIPS Memory Modeling program 손무현

#include <stdio.h>

unsigned char progMEM[0x100000], dataMEM[0x100000], stakMEM[0x100000];
int MEM(unsigned int A, int V, int nRW, int S) {
    unsigned int sel, offset;
    unsigned char *pM;
    sel = A >> 20;    offset = A & 0xFFFFF;
    // address decoding and select a physical memory
    if (sel == 0x004)      pM = progMEM;  // program memory
    else if (sel == 0x100) pM = dataMEM;  // data memory
    else if (sel == 0x7FF) pM = stakMEM;  // stack
    else {
        printf("Empty memory\n");
        //exit(1);
    }
    // offset processing for alignment
    //……
    
    unsigned int address = 0;
    if (S == 0) {  // byte 접근
        address = A;
        if (nRW == 0) { // read
        //…Read
        return pM[address];
        }
        else if (nRW == 1) { // write
        //...Write
        pM[address] = V;
        }
    }
    else if (S == 1) { // half word 접근
        address = A & 0xFFFFFFFE;
        if (nRW == 0) { // read
        //…Read
        return pM[address];
        }
        else if (nRW == 1) { // write
        //...Write
        pM[address] = V;
        }
    }
    else if (S == 2) { // word
        address = A & 0xFFFFFFFC;
        if (nRW == 0) { // read
        //…Read
        return pM[address];
        }
        else if (nRW == 1) { // write
        //...Write
        pM[address] = V;
        }
    }
    else { //error
        printf("Invalid input\n");
    } 
    }

int main()
{
    int result = MEM(0x004FFFFF, 3, 0, 0);
    printf("%d\n",result);
}

