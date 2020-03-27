#pragma once
#include<iostream>
#include<vector>


//Wikey version
//�ݹ��
void Merge(vector<int>& Array, int front, int mid, int end) {
	// preconditions:
	// Array[front...mid] is sorted
	// Array[mid+1 ... end] is sorted
	// Copy Array[front ... mid] to LeftSubArray
	// Copy Array[mid+1 ... end] to RightSubArray
	vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
	vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
	int idxLeft = 0, idxRight = 0;
	LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
	RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
	// Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
	for (int i = front; i <= end; i++) {
		if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
			Array[i] = LeftSubArray[idxLeft];
			idxLeft++;
		}
		else {
			Array[i] = RightSubArray[idxRight];
			idxRight++;
		}
	}
}

void MergeSort(vector<int>& Array, int front, int end) {
	if (front >= end)
		return;
	int mid = front + (end - front) / 2;
	MergeSort(Array, front, mid);
	MergeSort(Array, mid + 1, end);
	Merge(Array, front, mid, end);
}