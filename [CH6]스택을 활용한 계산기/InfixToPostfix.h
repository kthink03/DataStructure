#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

void ConvToRPNExp(char exp[]); // ���� ǥ����� �������� ��ȯ�ϴ� �Լ�
int GetOpPrec(char op); //�������� ���� �켱���� ������ ��ȯ
int WhoPrecOp(char op1, char op2); //�����ڳ����� �켱���� ��
#endif