#ifndef __AB_STACK__H__
#define __AB_STACK__H__

#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

/*스택 ADT*/
void StackInit(ArrayStack* pstack); //스택의 초기화
int SIsEmpty(ArrayStack* pstack); //스택이 비었는지 확인

void SPush(ArrayStack* pstack, Data data); //스택의 push 연산
Data SPop(ArrayStack* pstack); // 스택의 pop 연산
Data SPeek(ArrayStack* pstack); //스택의 peep 연산
#endif