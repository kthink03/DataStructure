/*
��¥:2021�� 01�� 09��
�̸�: �Ǽҿ�
������Ʈ ��: �迭 ��� ����
*/
#include"ArrayBaseStack.h"
#include<stdio.h>

void StackInit(ArrayStack* pstack) {
	pstack->topIndex = -1; //(������ �ʱ�ȭ)������ ù��° �ε����� -1�� �ȴ� -> �� ������ ������ �����
}
int SIsEmpty(ArrayStack* pstack) {
	//(������ ������� Ȯ��)
	if (pstack->topIndex == -1) {
		//ù��° �ε����� -1�̸� �����
		return 1;
	}
	else {
		return 0;
	}
}

void SPush(ArrayStack* pstack, Data data) {
	pstack->topIndex += 1;// ���� �ε��� ���� (�����Ͱ� ���ԵǾ����Ƿ�)
	pstack->stackArr[pstack->topIndex] = data; // ������ ����
}
Data SPop(ArrayStack* pstack) {
	//pop ���꿡�� �ش� ������ ���� ���� + ��ȯ�ϴ� �۾� 
	int rIdx;

	if (SIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}

	rIdx = pstack->topIndex; //������ �����Ͱ� ����� �ε��� �� ����
	pstack->topIndex -=1; //pop �������� topindex �� ����

	return pstack->stackArr[rIdx]; // ������ ������ ��ȯ
}
Data SPeek(ArrayStack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}