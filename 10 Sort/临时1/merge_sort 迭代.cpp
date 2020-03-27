//------------------------------迭代---------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;


/******************** 解释版 *********************
// 区间[head1, head2-1]和[head2, tail2]都是排好序的，现在需要合并
void mergeSortHelper(vector<int>& v, int head1, int head2, int tail2) {
	int tail1 = head2 - 1, index = 0, len = tail2 - head1 + 1, start = head1;
	vector<int> tmp(len);
	while (head1 <= tail1 || head2 <= tail2) {
		if (head1 > tail1)
			tmp[index++] = v[head2++];
		else if (head2 > tail2)
			tmp[index++] = v[head1++];
		else {
			if (v[head1] <= v[head2])
				tmp[index++] = v[head1++];
			else
				tmp[index++] = v[head2++];
		}
	}

	for (int i = 0; i < len; ++i)
		v[start + i] = tmp[i];
}

void mergeSort(vector<int>& v) {
	int len = v.size();
	// 倍进枚举步长1,2,4,……
	for (int step = 1; step <= len; step <<= 1) {
		int offset = step + step;
		for (int index = 0; index < len; index += offset)
			mergeSortHelper(v, index, min(index + step, len - 1), min(index + offset - 1, len - 1));
	}
}

*/




// 注意被我注释掉的地方，解开来，很直观可以看到排序的过程是怎么做的！
void display(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}

bool isSorted(const vector<int>& v) {
	vector<int> sorted(v.begin(), v.end());
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < (int)v.size(); ++i)
		if (v[i] != sorted[i])
			return false;
	return true;
}

void mergeSortHelper(vector<int>& v, int head1, int head2, int tail2) 
{
	int tail1 = head2 - 1, index = 0, len = tail2 - head1 + 1, start = head1;
	// cout << "Before " << head1 << ' ' << tail1 << ' ' << head2 << ' ' << tail2 << endl;
	// display(v);
	vector<int> tmp(len);
	while (head1 <= tail1 || head2 <= tail2) {
		if (head1 > tail1)
			tmp[index++] = v[head2++];
		else if (head2 > tail2)
			tmp[index++] = v[head1++];
		else {
			if (v[head1] <= v[head2])
				tmp[index++] = v[head1++];
			else
				tmp[index++] = v[head2++];
		}
	}

	for (int i = 0; i < len; ++i)
		v[start + i] = tmp[i];
	// cout << "After ";
	// display(v);
	// cout << endl;
}

void mergeSort(vector<int>& v) {
	int len = v.size();
	for (int step = 1; step <= len; step <<= 1) {
		int offset = step + step;
		for (int index = 0; index < len; index += offset)
			mergeSortHelper(v, index, min(index + step, len - 1), min(index + offset - 1, len - 1));
	}
}


void gen(vector<int>& v, size_t size) {
	static const int MAX = 99997;
	v = vector<int>(size);
	for (int i = 0; i < size; ++i)
		v[i] = rand() % MAX;
}



int main3() {
	vector<int> v ;
	 for (int i = 0; i < 10; ++i)
	 v.push_back(10-i);
	 mergeSort(v);
	 display(v);

	/*
	*
	srand(time(0));
	for (size_t size = 0; size < 100; ++size) {
		vector<int> v;
		gen(v, size);
		mergeSort(v);
		if (!isSorted(v)) {
			cout << "FAIL with size = " << size << endl;
			break;
		}
		else {
			cout << "GOOD with size = " << size << endl;
		}
	}

	*/

	return 0;
}

//------------------------------迭代---------------------------------------
