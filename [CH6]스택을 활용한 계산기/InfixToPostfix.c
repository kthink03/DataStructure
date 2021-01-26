#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"InfixToPostfix.h"
#include"ListBaseStack.h"

int GetOpPrec(char op) {
	// 연산자의 연산 우선순위 정보를 반환
	switch (op)
	{
	case '*':
	case '/':
		return 5; //가장 높은 연산의 우선순위
	case '+':
	case '-':
		return 3; //5보다 작고 1보다 높은 연산의 우선순위
	case '(':
		return 1; //가장 낮은 연산의 우선순위

		return -1; //등록되지 않은 연산자임을 알림
	}
}

int WhoPrecOp(char op1, char op2) {
	//연산자 간 우선순위 비교
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) //op1의 우선순위가 더 높다면
		return 1;
	else if (op1Prec < op2Prec) //op2의 우선순위가 더 높다면
		return -1;
	else
		return 0; //op1와 op2의 우선순위가 같은 경우 
}

void ConvToRPNExp(char exp[])// 후위 표기범의 수식으로 변환하는 함수
{
	ListStack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1); //변환된 수식을 담을 공간 마련(동적)

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // 할당된 배열을 0으로 초기화 
	LStackInit(&stack); //스택 초기화

	for (i = 0; i < expLen; i++) {
		tok = exp[i];//exp로 전달된 수식을 한 문자씩 tok에 저장

		if (isdigit(tok))//tok에 저장된 문자가 숫자인지 확인
		{
			convExp[idx++] = tok; // 숫자이면 배열 convExp에 그냥 저장 
		}
		else {
			//숫자가 아니라면
			switch (tok) {
			case '(': //여는 소괄호라면,
				LPush(&stack, tok); //스택에 쌓는다
				break;
			case ')': //닫는 소괄호에 들어오면 
				while (1) {
					popOp = LPop(&stack); // 1. 스택에서 연산자를 꺼낸다.
					if (popOp == '(') //2. 연산자 (가 나올떄까지 
 						break;
					convExp[idx++] = popOp; //3. 배열 convExp에 저장한다. 
				}
				break;
			case '+': case'-':
			case '*': case '/':
				while (!LIsEmpty(&stack) && WhoPrecOp(LPeep(&stack), tok) >= 0)
					convExp[idx++] = LPop(&stack);
				LPush(&stack, tok);
				break;
			}
		}
	}
	while (!LIsEmpty(&stack))
		convExp[idx++] = LPop(&stack); //스택에 남아있는 모든 연산자를 배열에 이동

	for (int i = 0; i < expLen; i++) {
		exp[i] = convExp[i];
	}
	free(convExp); //convExp를 소멸 
}
