#include<iostream>
using namespace std;

/*
* 1.Bubble Sort
* 2.Select Sort
* 3.Insertion Sort
* 4.Shell Sort
* 5.Merge Sort
* 6.
* 7.
* 8.
* 9.
* 10.
*
*
*/






template<class T>
void Bubble_Sort(T Array[], int N)
{
	for (int p = N - 1; p >= 0; p--)		//最多要进行N-1轮冒泡
	{
		bool hasSwaped = false;			//flag是一个标记,当数组已经完全有序时 == 没有交换 == flag=0
		for (int i = 0; i < p; i++)		/* 一趟冒泡 */  //从第一个数一直向第p - 1个数冒泡
		{
			if (Array[i] > Array[i + 1]) {	//如果当前数比它后面一个数要大,那么把它换到后面去
				swap(Array[i], Array[i + 1]);
				hasSwaped = true;		//每次交换将Flag置1
			}
		}
		if (!hasSwaped)					//If the array has not been swaped anymore, then it is sorted , break , end sorting.
			break;
	}
}


template<class T>
void Select_Sort(T Array[], int N)
{
	for (int i = 0; i < N, i++)
	{
		int MinElementPosition = i;
		for (int j = i + 1; j < N; j++)
		{
			if (Array[i] < Array[MinElementPosition]) {
				MinElementPosition = j			//Position of MinElement has found.
			}
		}
		Swap(Array[MinElementPosition], Array[i]);
	}
}


/*
* 1. i - how many element in the sorted list
* 2. i>0 - there is still element in the sorted list
* 3. arr[i-1] > CurrentElement - If the biggest element is lager than CurrentElment,compare with next elem in the list
* 4. arr[i]=arr[i-1] - move to the next elem in the list
* 5. IF (i=0) or ( a[i-1] <= CurrentElemnt ) --> the right position has found.
*/
template<class T>
void Insertion_Sort(T arr[], int N)
{
	for (int p = 1; p < N - 1; p++)
	{
		T CurrentElement = arr[p];									//mark the current element
		for (int i = p; (i > 0) && (arr[i - 1] > CurrentElement); i--) //arr[i-1] is the max in the sorted array
		{
			arr[i] = arr[i - 1];
		}
		arr[i] = CurrentElement;	//Put the CurrentElement in the right position
	}
}



//研究研究!
//DrStream version1
void Shell_sort1(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) //gap change to half each time
	{
		for (int i = 0; i < gap; i++)
		{
			for (int j = i + gap; j < n; j += gap)
			{
				if (a[j] < a[j - gap]) {
					int temp = a[j];
					int k = j - gap;
					while ((k >= 0) && (a[k] > temp)) {	//If k<0 , position found. If a[k]<temp,position found.
						a[k + gap] = a[k];
						k -= gap;
					}
					a[k + gap] = temp;
				}

			}
		}
	}
}


//DrStream version2
void Shell_sort2(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int j = gap; j < n; j++)	//Array strats from a[gap]
		{
			if (a[j] < a[j - gap]) {	//Each element compare with elements from its group
				int temp = a[j];
				int k = j - gap;
				while (k >= 0 && a[k] > temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
		}
	}
}



//Wikey version
// =====Bottom-up=======
template<class T>
void Merge_Sort(T arr[], int N)
{
	T* a = arr;			//initialize pointer to original array
	T* b = new T[N];	//Open up space for tempary array
	for (int seg = 1; seg < N; seg += seg)	//seg=1,2,4,8,...
	{
		for (int start = 0; start < N; start += seg + seg)	//start = start + seg + seg ->?
		{
			int low = start;
			int mid = min(start + seg, N);
			int high = min(start + seg + seg, N);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
			{
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];	//学着用!
			}
			while (start1 < end1)
			{
				b[k++] = a[start1++];
			}
			while (start2 < end2)
			{
				b[k++] = a[start2++];
			}
			/* Swap(a,b)  ->?  */
			// b is sorted
			// a is unsorted
			T* temp = a;
			a = b;
			b = temp;
		}
		// ?
		if (a != arr) {
			for (int i = 0; i < N; i++)
			{
				b[i] = a[i];
			}
			b = a;
		}
		delete[] b;
	}

}