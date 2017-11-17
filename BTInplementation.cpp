#include "stdafx.h"
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
	int ln = node->left ? dfs(node->left, lup) : 0;
	int rn = node->right ? dfs(node->right, lup) : 0;

	//这里是将他们和子项进行对比，看是否值相等，相等的话，就是子项返回的数值上加1，
	int resl = node->left != NULL&&node->val == node->left->val ? ln + 1 : 0;
	int resr = node->right != NULL&&node->val == node->right->val ? rn + 1 : 0;

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
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
			temp += t->val;
		}
		//然后进行运算，计算出每一层的总和平均
		res.push_back((double)temp / s);
	}
	return res;
}
#pragma endregion


#pragma region LeetCode_100_SameTree
//这一题的比较条件是引用到同一个节点才算是相同
bool BinaryTree::isSameTree(TreeNode* p, TreeNode* q)
{
	//queue<TreeNode*> queue1;
	//queue<TreeNode*> queue2;

	//queue1.push(p);
	//queue2.push(q);

	//while ((!queue1.empty()) && (!queue2.empty()))
	//{
	//	if (queue1.size() != queue2.size())
	//	{
	//		return false;
	//	}

	//	for (int i = 0; i < queue1.size(); i++)
	//	{
	//		TreeNode* TNT1 = queue1.front();
	//		TreeNode* TNT2 = queue2.front();

	//		if (TNT1->val != TNT2->val) return false;

	//		queue1.pop();
	//		queue2.pop();

	//		if (TNT1->left) queue1.push(TNT1->left);
	//		if(TNT1->right) queue1.push(TNT1->right);

	//		if (TNT2->left) queue2.push(TNT2->left);
	//		if (TNT2->right) queue2.push(TNT2->right);
	//	}
	//}
	//return true;




	/*上面为尝试部分，是假设两个节点不同，但是里面的元素的值相同*/

	//首先判断这两个根节点是否为空，不为空的情况下，直接返回比较的结果，
	if (p == NULL || q == NULL) return (p == q);
	return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
#pragma endregion