/*
프로젝트 명: 스택을 활용하여 계산기 만들기
작성자 명: 권소영
작성일: 2021년 1월 26일
*/
#include<stdio.h>
#include"InfixToPostfix.h"

int main(void) {
	char exp[] = "3-2*4"; // 중위 표기법의 수식
	ConvToRPNExp(exp); // 후위 표기법의 수식으로 변환
	
	printf("%s\n", exp);
	return 0;
}