#include <iostream>

using namespace std;

void MergeSort(int A[], int p, int r);

int main()
{
	int A [] = { 2,8,7,1,3,5,6,4,10, -3};
	MergeSort(A, 0, 9);
	for (int i = 0; i < 10; ++i)
		std::cout << A[i] << " ";
	std::cout << std::endl;
	return 0;
}