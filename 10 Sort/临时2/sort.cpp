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
	for (int p = N-1; p>=0 ; p--)		//���Ҫ����N-1��ð��
	{
		bool hasSwaped=false;			//flag��һ�����,�������Ѿ���ȫ����ʱ == û�н��� == flag=0
		for (int i = 0; i < p; i++)		/* һ��ð�� */  //�ӵ�һ����һֱ���p - 1����ð��
		{
			if (Array[i]>Array[i+1]){	//�����ǰ����������һ����Ҫ��,��ô������������ȥ
				Swap(Array[i], Array[i + 1]);
				hasSwaped = true;		//ÿ�ν�����Flag��1
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
	while ( h < len/2 ){	//����ȡһ��ʼ���������
		h *= 2;
	}
	while (h>=1) {			//ֻҪ����>=1��һֱѭ��
		for (int i = h; i < len; i++)	//����
		{
			for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) //��������
			{
				std::swap(arr[j], arr[j - h]);
			}
		}
		h / = 2;	//��������������ȡ��С������
	}
}





//�о��о�!
//DrStream version1
void Shell_sort1(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) //gap change to half each time
	{
		for (int i = 0; i < n; i++) //����
		{
			int CurretElement = a[i];
			int j = i;
			for (  ; (j>0) && ( a[j]>CurretElement ); j -= gap) //ÿ��gap��ȡһ��Ԫ��,��һ��
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

//�о�!!!
//Wikey
//�ݹ鷨
template<class T>
void Quick_Sort_Recursive(T arr[], int start,int end)
{
	if (start = end)		//�ײ�ݹ���ֹ����:start=end
		return;
	/* ָ���ʼ��,��arr��Ϊ[left,right-1]��[right,end]���� */
	T mid = arr[end];		//ѡ��arr[end]��Ϊ ��׼(pivot)		
	int left = start;		
	int right = end - 1;
	/* ��������Χ����Ѱ�� mid С��Ԫ��,Ȼ�����Ԫ�����Ҳ�Ԫ�ؽ���
	*  1.��[left,right-1]���ҵ���mid�����
	*  2.��[right,end]���ҵ���midС����
	*  3.����Ԫ��
	*/
	while (left<right)	// ����[left,right]��Χ
	{
		while (arr[left] < mid && left < right)		//arr[left]>mid
			left++;
		while (arr[right] >= mid && left < right)	//arr[right]<mid
			right--;
		std::swap(arr[left], arr[right]);
	}
	if (arr[left] >= arr[end])	//�������һ������pivot�Ƚ�,���С��Ԫ����ǰ��,��ô��С��Ԫ�ػ�������ȥ
		std::swap(arr[left, right]);
	else                        //���СԪ����ǰ,��ô��left + 1
		left++;
	Quick_Sort_Recursive(arr, start, left - 1);
	Quick_Sort_Recursive(arr, left + 1, end);
}

//�ⲿ�ӿ�
template<class T>
void Quick_Sort(T arr[], int len)
{
	Quick_Sort_Recursive(arr, 0, len - 1);
}


//Wikey
/* ���������� */
void max_heapify(int arr[], int start, int end)
{
	int dad = start;
	int son = 2 * dad + 1;
	while (son<=end){
		if (son + 1 <= end && arr[son] < arr[son + 1]) { //��sonָ��ϴ�ĺ���
			son += 1;
		}
		if (arr[dad] > arr[son])
			return;
		else {             //������ڵ�Ⱥ���ҪС,��ô�Ѹ��ڵ㻻����
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
/* �������� */
void heap_sort(int arr[], int len)
{
	//�����һ�����ڵ㿪ʼ �������ʼ����һ������		--> Ϊʲôi=len/2-1��???
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		max_heapify(arr, i, len - 1);
	}
	//���ϵذѸ��ڵ��õ����һ��λ��,Ȼ������λ�õ�Ԫ���ų��ٰ���������������
	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

/* �������� */
//Wikey
void Counting_Sort(int* ini_arr, int* sorted_arr, int n)
{
	/*
	* ini_arr - ��ʼ����������
	* sorted_arr - ���ź��������
	* n - ����������Ԫ�صĸ���
	*
	*/
	int* count_arr = new int[100];
	for (int k = 0; k < 100; k++)  //��count_arr��ʼ��Ϊ{0}
	{
		count_arr[k] = 0;
	}
	for (int i = 0; i < n; i++)		//ini_arrԪ�ص�ֵ��Ϊcount_arr���±�
	{
		count_arr[ ini_arr[i] ]++;	//count_arr��Ԫ�ش洢����ini_arr����ͬԪ�س��ֵĴ���
	}
	for (j = n; j > 0; j--)			//
	{
		sorted_arr[--count_arr[ini_arr[j - 1]]] = ini_arr[j - 1];
	}
	delete[] count_arr;
}




/* �������� */
void Counting_Sort(int* arr, int len)
{
	//�ҵ����ֵ����Сֵ
	int MaxElement = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > MaxElement)
			swap(arr[i], MaxElement);
	}
	//����CountArr�����Ԫ�صĸ���
	int CountArrSize = MaxElement;
	int* CountArr = new int[CountArrSize] {0};
	int counter = len;
	for (int i = 0; i < len; i++)
	{
		CountArr[arr[i]]++;
	}
	int* SourtedArr = new int[len] {0};
	//���������ԭ����
	for (int j = len; j>0; j--)
	{
		SourtedArr[j]=
	}
	delete[] CountArr;
}