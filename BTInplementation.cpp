#include "BTInplementation.h"
#include <Algorithm>

using namespace std;


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