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
	//�������������loop��ֵ�ᷢ���ı�
	return loop;

}

int BinaryTree::dfs(TreeNode* node,int& lup)
{
	//������������ʽ�����������ln��rn����û������������Ϊ
	int ln = node->left ? dfs(node->left, lup) : 0;
	int rn = node->right ? dfs(node->right, lup) : 0;

	//�����ǽ����Ǻ�������жԱȣ����Ƿ�ֵ��ȣ���ȵĻ�����������ص���ֵ�ϼ�1��
	int resl = node->left != NULL&&node->val == node->left->val ? ln + 1 : 0;
	int resr = node->right != NULL&&node->val == node->right->val ? rn + 1 : 0;

	//��Ϊ���������������ֵ�ϴ���Ǹ��������ֵ�ᱻ������������Ϊ����������ͬ��֧����
	lup = max(lup, resl + resr);
	return max(resl, resr);
}
#pragma endregion




#pragma region LeetCode_637_AverageofLevelInBinaryTree
///��������ܳ��ã��������ĸ��㼶������Ϊ����
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
			//���ض���ͷ��Ԫ�ص�����
			TreeNode* t = q.front();
			//Ȼ���ͷ��Ԫ�س���
			q.pop();

			//Ȼ���������������ڣ��Ͱ�����������Ҳ���
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
			temp += t->val;
		}
		//Ȼ��������㣬�����ÿһ����ܺ�ƽ��
		res.push_back((double)temp / s);
	}
	return res;
}
#pragma endregion


#pragma region LeetCode_100_SameTree
//��һ��ıȽ����������õ�ͬһ���ڵ��������ͬ
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




	/*����Ϊ���Բ��֣��Ǽ��������ڵ㲻ͬ�����������Ԫ�ص�ֵ��ͬ*/

	//�����ж����������ڵ��Ƿ�Ϊ�գ���Ϊ�յ�����£�ֱ�ӷ��رȽϵĽ����
	if (p == NULL || q == NULL) return (p == q);
	return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
#pragma endregion