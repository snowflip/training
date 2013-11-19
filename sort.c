#include <stdio.h>

void bubblesort(int v[], int n)
{
	int i, j;
	int temp;
	for (i = 1; i <= n; i++) 
		for (j = 0; j < n - i; j++)
			if (v[j] > v[j + 1]) {
				temp = v[j + 1];
				v[j + 1] = v[j];
				v[j] = temp;
			}
}

void insertsort(int v[], int n)
{
	int i, j, k;
	int temp;
	for (i = 1; i < n; i++) {
		if (v[i] >= v[i - 1]) continue;

		temp = v[i];
		for (j = 0; j < i; j++)
			if (v[j] > v[i]) break;
		for (k = i; k > j; k--)
			v[k] = v[k - 1];
		v[j] = temp;
        }		
}

void insertsort1(int v[], int n)
{
	int i, j, k;
	int temp;

	for (i = 0; i < n - 1; i++) {
		if (v[i + 1] > v[i]) continue;
		for (j = 0; j < i + 1; j++)
			if (v[j] > v[i + 1]) break;
		temp = v[i + 1];
		for (k = i + 1; k > j; k--)
			v[k] = v[k - 1];
		v[j] = temp;
	}
}

void shellsort(int v[], int n)
{
	int gap;
	int l, i, j, k;
	int temp;

	for (gap = n / 2; gap > 0; gap /= 2)
	{	
		for (l = 0; l < gap; l++)
			for (i = l; i < n - gap; i += gap) {
				if (v[i + gap] > v[i]) continue;
				for (j = l; j < i + gap; j += gap)
					if (v[j] > v[i + gap]) break;
				temp = v[i + gap];
				for (k = i + gap; k > j; k -= gap)
					v[k] = v[k - gap];
				v[j] = temp;
			}			
	}
}

void selectsort(int v[], int n)
{
	int i, j, k;
	int min;
	for (i = 0; i < n - 1; i++) {
		min = v[i];
		for (j = i + 1; j < n; j++)		
			if (v[j] < min) {
				min = v[j];
				k = j;
		}
		if (min != v[i]) {
			v[k] = v[i];
			v[i] = min;
		}
	}
}

int partition(int v[], int n)
{
	int i, j;
	int pivot;
	int pivotIndex;
	int temp;
	pivot = v[0];
	pivotIndex = 0;
	for (i = 1; i < n; i++) {
		if (v[i] < pivot) {
			temp = v[i];
			for (j = i; j > pivotIndex; j--)
				v[j] = v[j - 1];
			v[pivotIndex++] = temp;
		}
	}
	return pivotIndex;
}

void quickpartition(int v[], int n, int left, int right)
{
	int index;
	if (left < right) {
		index = partition(v, n);
		quickpartition(v, index, 0, index - 1);
		quickpartition(v + index + 1, right - index, 0, right - index - 1);
	}
}

void quicksort(int v[], int n)
{
	quickpartition(v, n, 0, n - 1);
}

int main()
{
	int i;
	int a[] = {101, 5, 6, 2, 3, 9, 1, 7, 100, 88, 3, 79};
	
	quicksort(a, 12);

	for (i = 0; i < 12; i++) 
		 printf("%d\n", a[i]); 
	
	return 0;
}
