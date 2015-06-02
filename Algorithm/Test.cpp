#include <iostream>

using namespace std;

void Bucket_Sort(int A[], int n);

int main()
{
	int A [] = { 20, 8, 7, 7, 3, 5, 6, 4, 10, 15, 2};
	Bucket_Sort(A, 11);
	for (int i = 0; i < 11; ++i)
		std::cout << A[i] << " ";
	std::cout << std::endl;
	return 0;
}