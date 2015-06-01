#include "QuickFindUF.h"

bool QuickFindUF::connected(int p, int q)
{
	return vec[p] == vec[q];
}

void QuickFindUF::unions(int p, int q)
{
	int pid = vec[p];
	int qid = vec[q];
	for (int i = 0; i < vec.size(); ++i)
	{
		if (pid == vec[i])
			vec[i] = qid;
	}
}