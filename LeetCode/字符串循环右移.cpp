
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "string"
#include "vector"
#include <stack>
using namespace std;

void LoopMove(char * str, int steps)
{
	int len = strlen(str);
	char tmp[100];
	strcpy(tmp, str + len - steps);
	strcpy(tmp + steps, str);
	*(tmp + len) = '\0';
	strcpy(str, tmp);
}

int main() {
	char pStr[] = "abcdefghi";
	int steps = 2;
	LoopMove(pStr, steps);
	cout << pStr;
	return 0;
}
