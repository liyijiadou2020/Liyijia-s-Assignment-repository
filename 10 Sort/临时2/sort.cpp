#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
void Swap(T& A, T& B)
{
	T temp = A;
	A = B;
	B = temp;
}



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
	for (int p = N-1; p>=0 ; p--)		//最多要进行N-1轮冒泡
	{
		bool hasSwaped=false;			//flag是一个标记,当数组已经完全有序时 == 没有交换 == flag=0
		for (int i = 0; i < p; i++)		/* 一趟冒泡 */  //从第一个数一直向第p - 1个数冒泡
		{
			if (Array[i]>Array[i+1]){	//如果当前数比它后面一个数要大,那么把它换到后面去
				Swap(Array[i], Array[i + 1]);
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
		for (int j = i+1; j < N; j++)
		{
			if (Array[i]<Array[MinElementPosition]){
				MinElementPosition = j			//Position of MinElement has found.
			}
		}
		swap(Array[MinElementPosition], Array[i]);
	}
}


//Wikey Insertion_Sort
template<class T>
void Insertion_Sort(T arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		T key = arr[i];
		int j = i - 1;
		while ( (j>0) && (key<arr[j]) )
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}



//Wikey Shell_Sort
template<class T>
void Shell_Sort(T arr[], int len)
{
	int h = 1;
	while ( h < len/2 ){	//用来取一开始的最大增量
		h *= 2;
	}
	while (h>=1) {			//只要增量>=1就一直循环
		for (int i = h; i < len; i++)	//分组
		{
			for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) //组内排序
			{
				std::swap(arr[j], arr[j - h]);
			}
		}
		h / = 2;	//组内完成排序后再取更小的增量
	}
}





//研究研究!
//DrStream version1
void Shell_sort1(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) //gap change to half each time
	{
		for (int i = 0; i < n; i++) //分组
		{
			int CurretElement = a[i];
			int j = i;
			for (  ; (j>0) && ( a[j]>CurretElement ); j -= gap) //每隔gap个取一个元素,放一组
			{
				a[j] = a[j - gap];
			}
			a[j] = CurretElement;
		}
	}
}


//DrStream version2
void Shell_sort2(int a[], int n)
{
	for (int gap = n/2; gap > 0; gap/=2)
	{
		for (int j = gap; j < n; j++)	//Array strats from a[gap]
		{
			if (a[j] < a[j - gap]) {	//Each element compare with elements from its group
				int temp = a[j];
				int k = j - gap;
				while (k>=0&&a[k]>temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
		}
	}
}

//研究!!!
//Wikey
//递归法
template<class T>
void Quick_Sort_Recursive(T arr[], int start,int end)
{
	if (start = end)		//底层递归终止条件:start=end
		return;
	/* 指针初始化,将arr分为[left,right-1]和[right,end]两半 */
	T mid = arr[end];		//选择arr[end]作为 基准(pivot)		
	int left = start;		
	int right = end - 1;
	/* 在整个范围内搜寻比 mid 小的元素,然后将左侧元素与右侧元素交换
	*  1.在[left,right-1]中找到比mid大的数
	*  2.在[right,end]中找到比mid小的数
	*  3.交换元素
	*/
	while (left<right)	// 整个[left,right]范围
	{
		while (arr[left] < mid && left < right)		//arr[left]>mid
			left++;
		while (arr[right] >= mid && left < right)	//arr[right]<mid
			right--;
		std::swap(arr[left], arr[right]);
	}
	if (arr[left] >= arr[end])	//左侧的最后一个数与pivot比较,如果小的元素在前面,那么把小的元素换到后面去
		std::swap(arr[left, right]);
	else                        //如果小元素在前,那么把left + 1
		left++;
	Quick_Sort_Recursive(arr, start, left - 1);
	Quick_Sort_Recursive(arr, left + 1, end);
}

//外部接口
template<class T>
void Quick_Sort(T arr[], int len)
{
	Quick_Sort_Recursive(arr, 0, len - 1);
}


//Wikey
/* 调整成最大堆 */
void max_heapify(int arr[], int start, int end)
{
	int dad = start;
	int son = 2 * dad + 1;
	while (son<=end){
		if (son + 1 <= end && arr[son] < arr[son + 1]) { //让son指向较大的孩子
			son += 1;
		}
		if (arr[dad] > arr[son])
			return;
		else {             //如果父节点比孩子要小,那么把父节点换下来
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
/* 堆排序函数 */
void heap_sort(int arr[], int len)
{
	//从最后一个父节点开始 把数组初始化成一个最大堆		--> 为什么i=len/2-1呢???
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		max_heapify(arr, i, len - 1);
	}
	//不断地把根节点拿到最后一个位置,然后把最后位置的元素排除再把无序区调成最大堆
	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

/* 计数排序 */
//Wikey
void Counting_Sort(int* ini_arr, int* sorted_arr, int n)
{
	/*
	* ini_arr - 初始待排序数组
	* sorted_arr - 已排好序的数组
	* n - 待排数组中元素的个数
	*
	*/
	int* count_arr = new int[100];
	for (int k = 0; k < 100; k++)  //将count_arr初始化为{0}
	{
		count_arr[k] = 0;
	}
	for (int i = 0; i < n; i++)		//ini_arr元素的值作为count_arr的下标
	{
		count_arr[ ini_arr[i] ]++;	//count_arr的元素存储的是ini_arr中相同元素出现的次数
	}
	for (j = n; j > 0; j--)			//
	{
		sorted_arr[--count_arr[ini_arr[j - 1]]] = ini_arr[j - 1];
	}
	delete[] count_arr;
}




/* 计数排序 */
void Counting_Sort(int* arr, int len)
{
	//找到最大值和最小值
	int MaxElement = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > MaxElement)
			swap(arr[i], MaxElement);
	}
	//构建CountArr来存放元素的个数
	int CountArrSize = MaxElement;
	int* CountArr = new int[CountArrSize] {0};
	int counter = len;
	for (int i = 0; i < len; i++)
	{
		CountArr[arr[i]]++;
	}
	int* SourtedArr = new int[len] {0};
	//反向输出回原数组
	for (int j = len; j>0; j--)
	{
		SourtedArr[j]=
	}
	delete[] CountArr;
}