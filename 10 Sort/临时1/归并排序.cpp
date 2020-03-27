#include <iostream>
using namespace std;


//===========================递归==============================================
// 合并数组，排好序，然后在拷贝到原来的数组array
void MergeArray(int array[], int start, int end, int mid, int temp[]) {
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (array[i] < array[j]) {
			temp[k++] = array[i++];
		}
		else {
			temp[k++] = array[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = array[i++];
	}
	while (j <= end) {
		temp[k++] = array[j++];
	}
	for (int i = 0; i < k; i++) {
		array[start + i] = temp[i];
	}

}
// 归并排序，将数组前半部分后半部分分成最小单元，然后再合并
void MergeSort(int array[], int start, int end, int temp[]) {
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(array, start, mid, temp);	//递归
		MergeSort(array, mid + 1, end, temp);	//递归
		MergeArray(array, start, end, mid, temp);	//合并
	}

}
// 在这里创建临时数组，节省内存开销，因为以后的temp都是在递归里使用的。
void MergeSort(int array[], int len) {
	int start = 0;
	int end = len - 1;
	int* temp = new int[len];
	MergeSort(array, start, end, temp);
}

void PrintArray(int array[], int len) {
	for (int i = 0; i < len; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}

//===========================递归==============================================


int main4()
{
	int array[] = { 1,2,5,4,3,9,7,8,6 };

	MergeSort(array, 9);
	PrintArray(array, 9);



	return 0;
}