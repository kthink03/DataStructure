#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"InfixToPostfix.h"
#include"ListBaseStack.h"

int GetOpPrec(char op) {
	// �������� ���� �켱���� ������ ��ȯ
	switch (op)
	{
	case '*':
	case '/':
		return 5; //���� ���� ������ �켱����
	case '+':
	case '-':
		return 3; //5���� �۰� 1���� ���� ������ �켱����
	case '(':
		return 1; //���� ���� ������ �켱����

		return -1; //��ϵ��� ���� ���������� �˸�
	}
}

int WhoPrecOp(char op1, char op2) {
	//������ �� �켱���� ��
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) //op1�� �켱������ �� ���ٸ�
		return 1;
	else if (op1Prec < op2Prec) //op2�� �켱������ �� ���ٸ�
		return -1;
	else
		return 0; //op1�� op2�� �켱������ ���� ��� 
}

void ConvToRPNExp(char exp[])// ���� ǥ����� �������� ��ȯ�ϴ� �Լ�
{
	ListStack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1); //��ȯ�� ������ ���� ���� ����(����)

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // �Ҵ�� �迭�� 0���� �ʱ�ȭ 
	LStackInit(&stack); //���� �ʱ�ȭ

	for (i = 0; i < expLen; i++) {
		tok = exp[i];//exp�� ���޵� ������ �� ���ھ� tok�� ����

		if (isdigit(tok))//tok�� ����� ���ڰ� �������� Ȯ��
		{
			convExp[idx++] = tok; // �����̸� �迭 convExp�� �׳� ���� 
		}
		else {
			//���ڰ� �ƴ϶��
			switch (tok) {
			case '(': //���� �Ұ�ȣ���,
				LPush(&stack, tok); //���ÿ� �״´�
				break;
			case ')': //�ݴ� �Ұ�ȣ�� ������ 
				while (1) {
					popOp = LPop(&stack); // 1. ���ÿ��� �����ڸ� ������.
					if (popOp == '(') //2. ������ (�� ���Ë����� 
 						break;
					convExp[idx++] = popOp; //3. �迭 convExp�� �����Ѵ�. 
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
		convExp[idx++] = LPop(&stack); //���ÿ� �����ִ� ��� �����ڸ� �迭�� �̵�

	for (int i = 0; i < expLen; i++) {
		exp[i] = convExp[i];
	}
	free(convExp); //convExp�� �Ҹ� 
}
