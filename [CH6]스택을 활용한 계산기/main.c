/*
������Ʈ ��: ������ Ȱ���Ͽ� ���� �����
�ۼ��� ��: �Ǽҿ�
�ۼ���: 2021�� 1�� 26��
*/
#include<stdio.h>
#include"InfixToPostfix.h"

int main(void) {
	char exp[] = "3-2*4"; // ���� ǥ����� ����
	ConvToRPNExp(exp); // ���� ǥ����� �������� ��ȯ
	
	printf("%s\n", exp);
	return 0;
}