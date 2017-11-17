#include "BTInplementation.h"
#include <Algorithm>
#include <queue>
using namespace std;

#pragma region LeetCode_687_LongestUnivaluePath
int BinaryTree::longestUnivaluePath(TreeNode* root)
{
	int loop =0;
	if (root) dfs(root,loop);
	//经过这个函数，loop的值会发生改变
	return loop;

}

int BinaryTree::dfs(TreeNode* node,int& lup)
{
	//这是两个迭代式，返回子项的ln和rn，在没有子项的情况下为
	int ln = node->LeftChild ? dfs(node->LeftChild, lup) : 0;
	int rn = node->RightChild ? dfs(node-> RightChild, lup) : 0;

	//这里是将他们和子项进行对比，看是否值相等，相等的话，就是子项返回的数值上加1，
	int resl = node->LeftChild != NULL&&node->value == node->LeftChild->value ? ln + 1 : 0;
	int resr = node->RightChild != NULL&&node->value == node->RightChild->value ? rn + 1 : 0;

	//因为有两个子项，所以数值较大的那个子项的数值会被保留下来，因为求的是最大相同分支长度
	lup = max(lup, resl + resr);
	return max(resl, resr);
}
#pragma endregion




#pragma region LeetCode_637_AverageofLevelInBinaryTree
///这个操作很常用，对于树的各层级操作最为合适
vector<double> BinaryTree::averageOfLevels(TreeNode* root)
{
	vector<double> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		long temp = 0;
		int s = q.size();
		for (int i = 0; i < s; i++)
		{
			//返回队列头部元素的引用
			TreeNode* t = q.front();
			//然后把头部元素出列
			q.pop();

			//然后如果左右子项存在，就把这两个子项也入队
			if (t->LeftChild) q.push(t->LeftChild);
			if (t->RightChild) q.push(t->RightChild);
			temp += t->value;
		}
		//然后进行运算，计算出每一层的总和平均
		res.push_back((double)temp / s);
	}
	return res;
}



#pragma endregion