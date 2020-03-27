#include <iostream>
using namespace std;


//===========================�ݹ�==============================================
// �ϲ����飬�ź���Ȼ���ڿ�����ԭ��������array
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
// �鲢���򣬽�����ǰ�벿�ֺ�벿�ֳַ���С��Ԫ��Ȼ���ٺϲ�
void MergeSort(int array[], int start, int end, int temp[]) {
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(array, start, mid, temp);	//�ݹ�
		MergeSort(array, mid + 1, end, temp);	//�ݹ�
		MergeArray(array, start, end, mid, temp);	//�ϲ�
	}

}
// �����ﴴ����ʱ���飬��ʡ�ڴ濪������Ϊ�Ժ��temp�����ڵݹ���ʹ�õġ�
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

//===========================�ݹ�==============================================


int main4()
{
	int array[] = { 1,2,5,4,3,9,7,8,6 };

	MergeSort(array, 9);
	PrintArray(array, 9);



	return 0;
}