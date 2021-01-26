#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

void ConvToRPNExp(char exp[]); // 후위 표기범의 수식으로 변환하는 함수
int GetOpPrec(char op); //연산자의 연산 우선순위 정보를 반환
int WhoPrecOp(char op1, char op2); //연산자끼리의 우선순위 비교
#endif