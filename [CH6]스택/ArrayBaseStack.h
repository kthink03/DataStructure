#ifndef __AB_STACK__H__
#define __AB_STACK__H__

#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

/*���� ADT*/
void StackInit(ArrayStack* pstack); //������ �ʱ�ȭ
int SIsEmpty(ArrayStack* pstack); //������ ������� Ȯ��

void SPush(ArrayStack* pstack, Data data); //������ push ����
Data SPop(ArrayStack* pstack); // ������ pop ����
Data SPeek(ArrayStack* pstack); //������ peep ����
#endif