/*
��¥: 2020�� 12�� 24��
�̸�: �Ǽҿ�
������Ʈ��: ����Ž�� ����(���� �κ� ����)
*/
#include<stdio.h>
void sort(int arr[],int size);

int main(void) {
	int arr[]= { 5,34,2,6,1,23,7,9 }; 
	int size = sizeof(arr) / sizeof(int); 
	int num = 0;
	int index = size / 2;
	sort(arr,size); // 1. ���� Ž���� ���� �迭�� �����Ѵ�.
	printf("����Ž�� �� �迭");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("Ž���� ����:");
	scanf("%d", &num);
	BSearch(arr, size, num,index);

}

void sort(int arr[],int size) {
	int tmp = 0;
	int i = 0;

	while(i!=size){
		for (int j = 0; j <size; j++) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		i++;
	}
}

int BSearch(int arr[], int size,int num,int index) {

}