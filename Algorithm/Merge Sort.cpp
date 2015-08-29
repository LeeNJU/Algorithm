#include<vector>
#include<algorithm>
#include<limits.h>
//�鲢�����úϲ����򷨶������еݹ������Ȼ���ٺϲ�����������������С������г���Ϊ1ʱ���ݹ����������Ԫ�ر���Ϊ
//         �����ź����,���������������ź���֮������Ҫ�Ĳ������Ǻϲ�������������

void Merge(int A [], int p, int q, int r)//p,q,r��Ϊ�����±꣬������A[p..q]��A[q+1..r]
{
	int lengthA = q - p + 1;//��������������ĳ���
	int lengthB = r - q;

	std::vector<int> left(lengthA + 1, 0);//�����������飬�����������������飬Ȼ���������������ϲ���ԭ����A��
	std::vector<int> right(lengthB + 1, 0);
	std::copy(A + p, A + q + 1, left.begin());//ע��������±�
	std::copy(A + q + 1, A + r + 1, right.begin());
	left[lengthA] = INT_MAX;//�ڱ��ڵ���ѭ�������������ıȽϣ������һ��Ԫ�غ��ڱ��ڵ���������бȽ�
	right[lengthB] = INT_MAX;

	int i = 0, j = 0;//�ֱ�ָ��left��right����������
	for (int k = p; k <= r; ++k)//�ϲ����������鵽����A��
	{
		if (left[i] <= right[j])
		{
			A[k] = left[i];
			++i;
		}
		else
		{
			A[k] = right[j];
			++j;
		}
	}
}

//�鲢������ǵݹ���ã�ֱ��ÿ�������鳤��Ϊ1��Ȼ��ʼ�Ե����Ͻ��кϲ�����
void MergeSort(int A [], int p, int r)//p��rΪ�����±�
{
	if (p < r)
	{
		int q = (p + r) / 2;//�������������
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}