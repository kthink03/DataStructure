/*
날짜: 2021. 01. 09
이름: 권소영
프로젝트 명: 연결리스트 기반 스택 */
#include"ListBaseStack.h"
#include<stdio.h>
#include<stdlib.h>

void LStackInit(ListStack* pstack) {
	pstack->head = NULL; // 포인터 변수 HEAD는 NULL로 초기화 
}
int LIsEmpty(ListStack* pstack) {
	if (pstack->head == NULL) {
		return 1;
	}
	else return 0;
}
void LPush(ListStack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //새로운 노드 생성 
	newNode->data = data; //새 노드에 데이터 저장 
	newNode->next = pstack->head; //새 노드가 최근에 추가된 노드를 가리킴

	pstack->head = newNode; //포인터 변수 head가 새 노드를 가리킴
}
Data LPop(ListStack* pstack) {
	Node* node = (Node*)malloc(sizeof(Node));
	Data data;

	if (LIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}
	node = pstack->head; //현재 스택의 헤드 데이터를 노드에 저장 
	data = node->data; //data에 헤드 노드의 데이터 값을 저장 

	pstack->head = pstack->head->next; //현재 스택의 헤더 삭제(POP)
	free(node); //노드 삭제

	return data;
}
Data LPeep(ListStack* pstack) {
	Data data;

	if (LIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}

	data = pstack->head->data;

	return data;
}