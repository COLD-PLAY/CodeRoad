// 1.1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int i, gi, gi_;
void *address;

void *buildCode() {
	char *code = (char*)malloc(16);
	char *pMov = code;
	char *pJmp = code + 10;
	char *pAddress = code + 2;
	// mov gi, 18
	pMov[0] = 0xc7;
	pMov[1] = 0x05;
	*((int*)pAddress) = (int)&gi;
	*((int*)(pAddress + 4)) = 18;
	// jmp address
	pJmp[0] = 0xff;
	pJmp[1] = 0x25;
	*((int*)(pJmp + 2)) = (int)&address;
	return code;
}

int main(int argc, char **argv)
{
	void *code = buildCode();
	_asm {
		mov address, offset_lb1
	}
	gi = 12;
	cout << "gi = " << gi << endl;
	gi = 13;
_lb1:
	cout << "gi = " << gi << endl;
	getchar();
    return 0;
}