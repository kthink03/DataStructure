/*
��¥: 2021. 01. 09
�̸�: �Ǽҿ�
������Ʈ ��: ���Ḯ��Ʈ ��� ���� */
#include"ListBaseStack.h"
#include<stdio.h>
#include<stdlib.h>

void LStackInit(ListStack* pstack) {
	pstack->head = NULL; // ������ ���� HEAD�� NULL�� �ʱ�ȭ 
}
int LIsEmpty(ListStack* pstack) {
	if (pstack->head == NULL) {
		return 1;
	}
	else return 0;
}
void LPush(ListStack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //���ο� ��� ���� 
	newNode->data = data; //�� ��忡 ������ ���� 
	newNode->next = pstack->head; //�� ��尡 �ֱٿ� �߰��� ��带 ����Ŵ

	pstack->head = newNode; //������ ���� head�� �� ��带 ����Ŵ
}
Data LPop(ListStack* pstack) {
	Node* node = (Node*)malloc(sizeof(Node));
	Data data;

	if (LIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}
	node = pstack->head; //���� ������ ��� �����͸� ��忡 ���� 
	data = node->data; //data�� ��� ����� ������ ���� ���� 

	pstack->head = pstack->head->next; //���� ������ ��� ����(POP)
	free(node); //��� ����

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