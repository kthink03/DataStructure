#ifndef __LB_STACK_H__
#define __LB_STACK_H__

typedef int Data;
typedef struct _node { //���� ����Ʈ�� ��带 ǥ���� ����ü
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack { //���� ����Ʈ ��� ������ ǥ���� ����ü 
	Node* head;
}ListStack;


void LStackInit(ListStack* pstack); //���� �ʱ�ȭ
int LIsEmpty(ListStack* pstack); // ������ ������� Ȯ��

void LPush(ListStack* pstack, Data data); //������ push ����
Data LPop(ListStack* pstack); // ������ pop ����
Data LPeep(ListStack* pstack); // ������ peep ����
#endif