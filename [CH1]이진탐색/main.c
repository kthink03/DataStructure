/*
날짜: 2020년 12월 24일
이름: 권소영
프로젝트명: 이진탐색 구현(정렬 부분 포함)
*/
#include<stdio.h>
void sort(int arr[],int size);

int main(void) {
	int arr[]= { 5,34,2,6,1,23,7,9 }; 
	int size = sizeof(arr) / sizeof(int); 
	int num = 0;
	int index = size / 2;
	sort(arr,size); // 1. 이진 탐색을 위해 배열을 정렬한다.
	printf("이진탐색 전 배열");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("탐색할 숫자:");
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