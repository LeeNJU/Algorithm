#include <iostream>

using namespace std;

void Counting_Sort(int A[], int B[], int k, int n);

int main()
{
	int A [] = { 20, 8, 7, 7, 3, 5, 6, 4, 10, 15, 2};
	int B [] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Counting_Sort(A, B, 20, 11);
	for (int i = 0; i < 11; ++i)
		std::cout << B[i] << " ";
	std::cout << std::endl;
	return 0;
}