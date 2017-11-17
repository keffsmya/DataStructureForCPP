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
	int ln = node->LeftChild ? dfs(node->LeftChild, lup) : 0;
	int rn = node->RightChild ? dfs(node-> RightChild, lup) : 0;

	//�����ǽ����Ǻ�������жԱȣ����Ƿ�ֵ��ȣ���ȵĻ�����������ص���ֵ�ϼ�1��
	int resl = node->LeftChild != NULL&&node->value == node->LeftChild->value ? ln + 1 : 0;
	int resr = node->RightChild != NULL&&node->value == node->RightChild->value ? rn + 1 : 0;

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
			if (t->LeftChild) q.push(t->LeftChild);
			if (t->RightChild) q.push(t->RightChild);
			temp += t->value;
		}
		//Ȼ��������㣬�����ÿһ����ܺ�ƽ��
		res.push_back((double)temp / s);
	}
	return res;
}



#pragma endregion