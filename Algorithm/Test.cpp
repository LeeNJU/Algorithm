#include <iostream>

using namespace std;

void QuickSort(int A [], int p, int r);

int main()
{
	int A [] = { 2,8,7,1,3,5,6,4};
	QuickSort(A, 0, 7);
	for (int i = 0; i < 8; ++i)
		std::cout << A[i] << " ";
	std::cout << std::endl;
	return 0;
}