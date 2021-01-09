/*
날짜:2021년 01월 09일
이름: 권소영
프로젝트 명:스택
*/

#include"ArrayBaseStack.h"
#include"ListBaseStack.h"
#include<stdio.h>


int main(void) {
	/*배열 기반 스택*/
	//stack의 생성 및 초기화
	ArrayStack stack;
	StackInit(&stack);

	//데이터 넣기
	SPush(&stack, 1); SPush(&stack, 1122); SPush(&stack, 131); SPush(&stack, 2); SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5); SPush(&stack, 6); SPush(&stack, 7); SPush(&stack, 8); SPush(&stack, 9); SPush(&stack, 10);
	
	//데이터 꺼내기
	printf("Array Base Stack\n");
	while (!SIsEmpty(&stack))
		printf("%d ",SPop(&stack));
	printf("\n");

	/*연결 리스트 기반 스택*/
	//stack의 생성 및 초기화
	ListStack Lstack;
	LStackInit(&Lstack);

	//데이터 넣기
	LPush(&Lstack, 12); LPush(&Lstack, 2); LPush(&Lstack, 132); LPush(&Lstack, 1512); LPush(&Lstack, 126); 
	LPush(&Lstack, 98); LPush(&Lstack, 4232); LPush(&Lstack, 142); LPush(&Lstack, 165); LPush(&Lstack, 1205);

	//데이터 꺼내기
	printf("List Base Stack\n");
	while (!LIsEmpty(&Lstack))
		printf("%d ",LPop(&Lstack));

	printf("\n");
	return 0;

}