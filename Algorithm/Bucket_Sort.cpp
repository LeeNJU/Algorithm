#include<vector>
#include<algorithm>
//Ͱ���򣺰���������A���ֳ�n��Ͱ��Ȼ��������е�Ԫ��ӳ�䵽ÿһ��Ͱ�У�Ȼ���ÿ��Ͱ�е�Ԫ�ؽ�����������ÿ��Ͱ�е�Ԫ�ش�С����������ɡ����м���������
//Ԫ�ض��Ǵ���0������,Ͱ������ؼ��ľ���ӳ�䣬��ÿ��Ԫ��ӳ�䵽��Ӧ��Ͱ�У���������Ѿ����˼򵥵��������ˣ���Ҫ���ݾ��������ѡ��Ͱ��������ӳ�亯��
//ӳ�亯��Ҫ����������������A[i] <= A[j]����ôindex(A[i]) <= index(A[j])

void Bucket_Sort(int A [], int n)
{
	std::vector<std::vector<int>> B(n,std::vector<int>());//B��ΪͰ
	for (int i = 0; i < n; ++i)//��A�е�Ԫ��ȡģ��ӳ�䵽Ͱ�ţ����뵽��Ӧ��Ͱ��
		B[A[i] % n].push_back(A[i]);
	for (int i = 0; i < n; ++i)
	{
		if (!B[i].empty())//��ÿһ��Ͱ�е�Ԫ�ؽ�������
		{
			std::sort(B[i].begin(), B[i].end());
		}
	}

	int index = 0;//���ΰ�BͰ��ÿ��Ԫ�ظ��Ƶ�����A��
	for (int i = 0; i < n; ++i)
	{
		if (!B[i].empty())
		{
			for (int j = 0; j < B[i].size(); ++j)
				A[index++] = B[i][j];
		}
	}
}