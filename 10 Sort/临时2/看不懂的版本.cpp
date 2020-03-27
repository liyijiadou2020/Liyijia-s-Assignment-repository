#include<iostream>


/*
//�ٶȰٿư汾
//������
template<class T>
void Insertion_Sort(T start, T end, int delta)
{
	for (T i = start + delta; i < end; i += delta)	//��Ա�����Ĵ���������,������ֱ�Ӳ�������Ĳ�ͬ����"delta�滻��1"
	{
		for (T j = i; j > start; j -= delta)
		{
			if (*j < *(j - delta))
				swap(*j, *(j - delta));
			else
				break;
		}
	}
}



/*	ϣ������-������Ԫ�طֳ�����������,�ֱ���в�������.Ȼ��������������������,������=1(�Ѿ���������),�ٶ�ȫ��Ԫ�ؽ��в�������
*	�ݹ�ʵ��

template<class T>
void Shell_Sort(T start, T end)
{
	for (int delta = end - start ; delta != 0; delta /=2 )
	{
		for (int i = 0; i < delta; i++)
		{
			Insertion_Sort(start + i, end, delta);
		}
	}
}

*/



//Wikey version
//������
template<typename T>
void Merge_Sort(T arr[], int len) {
	T* a = arr;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		T* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}




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
