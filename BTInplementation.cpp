#include "BTInplementation.h"
#include <Algorithm>

using namespace std;


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