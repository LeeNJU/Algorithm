#include<vector>
//���ཻ��(���鼯)������0��n����ͬ��Ԫ�أ���ЩԪ�طֱ����ڲ�ͬ���Ӽ�����Щ�Ӽ����������ཻ�����鼯��������Ҫ������
//find��union��find�ж�����Ԫ���Ƿ���ͬһ���Ӽ��У�union�����������Ӽ��ϲ�

//quick-find����������һ����СΪN�����飬�±�0��n-1��ʾn��Ԫ�أ������ֵ��ʾ��Ԫ�ص�id���������Ԫ�ص�idһ������ʾ
//������Ԫ������ͬһ���Ӽ�
//�÷����ĳ�ʼ����union�������Ӷ�ΪO(n)��find�������Ӷ�ΪO(1)
class QuickFindUF
{
private:
	std::vector<int> vec;

public:
	QuickFindUF(int n)
	{
		for (int i = 0; i < n; ++i) //�����ʼ����ÿ��Ԫ�ص�id���������±꣬��ʾÿ��Ԫ�ؿ�ʼʱ����һ���������Ӽ�
			vec.push_back(i);
	}


	bool connected(int p, int q) //�ж�Ԫ��p��q�Ƿ���ͬһ���Ӽ��У�ֻ��Ҫ�ж�p��q��id�Ƿ���ͬ
	{
		return vec[p] == vec[q];
	}


	void unions(int p, int q) //�������飬��id��pid��ȵ�Ԫ�ص�id�ĳ�qid
	{
		int pid = vec[p];
		int qid = vec[q];
		for (int i = 0; i < vec.size(); ++i)
		{
			if (pid == vec[i])
				vec[i] = qid;
		}
	}

};
