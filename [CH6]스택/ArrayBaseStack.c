/*
날짜:2021년 01월 09일
이름: 권소영
프로젝트 명: 배열 기반 스택
*/
#include"ArrayBaseStack.h"
#include<stdio.h>

void StackInit(ArrayStack* pstack) {
	pstack->topIndex = -1; //(스택의 초기화)스택의 첫번째 인덱스가 -1이 된다 -> 빈 상태의 스택을 만든다
}
int SIsEmpty(ArrayStack* pstack) {
	//(스택이 비었는지 확인)
	if (pstack->topIndex == -1) {
		//첫번째 인덱스가 -1이면 비었음
		return 1;
	}
	else {
		return 0;
	}
}

void SPush(ArrayStack* pstack, Data data) {
	pstack->topIndex += 1;// 스택 인덱스 증가 (데이터가 삽입되었으므로)
	pstack->stackArr[pstack->topIndex] = data; // 데이터 저장
}
Data SPop(ArrayStack* pstack) {
	//pop 연산에서 해당 데이터 값을 삭제 + 반환하는 작업 
	int rIdx;

	if (SIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}

	rIdx = pstack->topIndex; //삭제할 데이터가 저장된 인덱스 값 저장
	pstack->topIndex -=1; //pop 연산으로 topindex 값 감소

	return pstack->stackArr[rIdx]; // 삭제된 데이터 반환
}
Data SPeek(ArrayStack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}