#include <iostream>

using namespace std;

void HeapSort(int A[], int n);
int main()
{
	int A [] = { 4, 1, 2, 16, 9, 14, 8, 7 };
	HeapSort(A, 8);
	return 0;
}