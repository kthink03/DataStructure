/*
��¥:2021�� 01�� 09��
�̸�: �Ǽҿ�
������Ʈ ��:����
*/

#include"ArrayBaseStack.h"
#include"ListBaseStack.h"
#include<stdio.h>


int main(void) {
	/*�迭 ��� ����*/
	//stack�� ���� �� �ʱ�ȭ
	ArrayStack stack;
	StackInit(&stack);

	//������ �ֱ�
	SPush(&stack, 1); SPush(&stack, 1122); SPush(&stack, 131); SPush(&stack, 2); SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5); SPush(&stack, 6); SPush(&stack, 7); SPush(&stack, 8); SPush(&stack, 9); SPush(&stack, 10);
	
	//������ ������
	printf("Array Base Stack\n");
	while (!SIsEmpty(&stack))
		printf("%d ",SPop(&stack));
	printf("\n");

	/*���� ����Ʈ ��� ����*/
	//stack�� ���� �� �ʱ�ȭ
	ListStack Lstack;
	LStackInit(&Lstack);

	//������ �ֱ�
	LPush(&Lstack, 12); LPush(&Lstack, 2); LPush(&Lstack, 132); LPush(&Lstack, 1512); LPush(&Lstack, 126); 
	LPush(&Lstack, 98); LPush(&Lstack, 4232); LPush(&Lstack, 142); LPush(&Lstack, 165); LPush(&Lstack, 1205);

	//������ ������
	printf("List Base Stack\n");
	while (!LIsEmpty(&Lstack))
		printf("%d ",LPop(&Lstack));

	printf("\n");
	return 0;

}