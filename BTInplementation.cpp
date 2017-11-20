#include "stdafx.h"
#include "BTInplementation.h"
#include <Algorithm>
#include <queue>
#include <stack>
#include <map>
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
	/*//queue<TreeNode*> queue1;
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
	//return true;*/




	/*����Ϊ���Բ��֣��Ǽ��������ڵ㲻ͬ�����������Ԫ�ص�ֵ��ͬ*/

	//�����ж����������ڵ��Ƿ�Ϊ�գ���Ϊ�յ�����£�ֱ�ӷ��رȽϵĽ����
	if (p == NULL || q == NULL) return (p == q);
	return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
#pragma endregion




#pragma region LeetCode_102_BinaryTreeLevelOrderTraversal

vector<vector<int>> BinaryTree::BinaryTreeLevelOrderTraversal(TreeNode* root)
{
	vector<vector<int>> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		vector<int> temp;
		int s = q.size();
		for (int i = 0; i < s; i++)
		{
			//���ض���ͷ��Ԫ�ص�����
			TreeNode* t = q.front();
			//Ȼ���ͷ��Ԫ�س���


			q.pop();
			if (t) temp.push_back(t->val);
			//Ȼ���������������ڣ��Ͱ�����������Ҳ���
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);

		}
		//Ȼ��������㣬
		res.push_back(temp);
	}

	

	return res;
}

#pragma endregion



#pragma region LeetCode_107_BinaryTreeLevelOrderTraversalII

vector<vector<int>> BinaryTree::BinaryTreeLevelOrderTraversalII(TreeNode* root)
{
	stack<vector<int>> restemp;
	vector<vector<int>> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		vector<int> temp;
		int s = q.size();
		for (int i = 0; i < s; i++)
		{
			//���ض���ͷ��Ԫ�ص�����
			TreeNode* t = q.front();
			//Ȼ���ͷ��Ԫ�س���
			
			
			q.pop();
			if(t) temp.push_back(t->val);
			//Ȼ���������������ڣ��Ͱ�����������Ҳ���
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
			
		}
		//Ȼ��������㣬
		restemp.push(temp);
	}

	while (!restemp.empty())
	{
		res.push_back(restemp.top());
		restemp.pop();
	}

	return res;
}

#pragma endregion



#pragma region LeetCode_226_InvertBinaryTree
TreeNode* BinaryTree::invertTree(TreeNode* root) {
	if (!root) return NULL;
	invertTreeNode(root);
	return root;
}

void BinaryTree::invertTreeNode(TreeNode* node)
{
	if (!node) return;

	if (node->left || node->right)
	{
		TreeNode* temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
	if (node->left) invertTreeNode(node->left);
	if (node->right) invertTreeNode(node->right);
	
}
#pragma endregion






#pragma region LeetCode_257_BinaryTreePaths
vector<string> BinaryTree::binaryTreePaths(TreeNode* root)
{
	vector<string> result;
	if (!root) return result;

	binaryTreePaths(result, root, to_string(root->val));
	return result;
		
}

void BinaryTree::binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
	if (!root->left && !root->right) {
		result.push_back(t);
		return;
	}

	if (root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
	if (root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}
#pragma endregion


#pragma region LeetCode_563_BinaryTreeTilt


//Given a binary tree, return the tilt of the whole tree.
//����һ�������������������������ƫб
//The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values.Null node has tilt 0.
//ƫб�Ķ��壺�����������������ĺ͡��롾��������������֮�͡��ġ����Բ
//The tilt of the whole tree is defined as the sum of all nodes' tilt.
//����һ������ƫб�ǴӸ��ڵ㿪ʼ���������й�ʽ�����ڵ�ġ�������������б��֮�͡�(��Ϊ�����Ҫ����һ������������б��֮��)+������������[������֮��]֮�
int BinaryTree::findTilt(TreeNode* root)
{
	if (!root)
		return 0;
	return std::abs(GetBTSum(root->left) - GetBTSum(root->right)) + findTilt(root->left) + findTilt(root->right);
}


int BinaryTree::GetBTSum(TreeNode* node)
{
	if (!node)
		return 0;
	return node->val + GetBTSum(node->left) + GetBTSum(node->right);
}
#pragma endregion



#pragma region LeetCode_104_maximunDepthofBinaryTree
///����Ѱ������������
int BinaryTree::maxDepth(TreeNode* root) {
	return root ? std::max(getThemaxlength(root->left), getThemaxlength(root->right))+1 :  0;
}

int BinaryTree::getThemaxlength(TreeNode* node)
{
	if (!node)return 0 ;
	int res = 0;
	queue<TreeNode*> q;

	q.push(node);
	while (!q.empty())
	{
		++res;
		for (int i = 0, n = q.size(); i < n; ++i)
		{
			TreeNode* p = q.front();
			q.pop();

			if (p->left)
				q.push(p->left);

			if (p->right)
				q.push(p->right);

		}
	}
	return res;

}
#pragma endregion


#pragma region LeetCode_572_SubtreeofAnotherTree
bool BinaryTree::isSubtree(TreeNode* s, TreeNode* t)
{
	return isSubtreetraverse(s, t);
};

//isSameTree����ǰ��LeetCode��ع��ܣ�����ֱ�ӽ���
//isSameTreeֻ�����Ե�ǰ���Ϊ�������Ƿ�Ϊsametree
//���Ի���Ҫһ�����������б���������Ҫ��ǰ��㣬��Ҫ������ȡ��������
bool BinaryTree::isSubtreetraverse(TreeNode* s, TreeNode* t)
{
	return s && (isSameTree(s, t) || isSubtreetraverse(s->left, t) || isSubtreetraverse(s->right, t));
}

#pragma endregion


#pragma region LeetCode_110_BalancedBinaryTree
//Given a binary tree, determine if it is height-balanced.

//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
bool BinaryTree::isBalanced(TreeNode* root)
{
	return isBlancedTraverse(root);
}


bool BinaryTree::isBlancedTraverse(TreeNode* root)
{
	//�����Ϊ�գ���ô����ƽ�������
	if (!root) return true;
	//�����ж����������ġ���󳤶ȡ�֮���Ƿ�С�ڵ���1
	bool B1 = (std::abs(getThemaxlength(root->left) - getThemaxlength(root->right))) <= 1;
	//���ű������ߵ���������Ϊƽ��������Ķ��壬���κΡ�һ���ڵ�����������ĳ���֮���С��2�����Ե�ǰ���ǵ�ǰ����ǲ�����
	bool B2 = isBlancedTraverse(root->left);
	bool B3 = isBlancedTraverse(root->right);

		return B1&&B2&&B3;
}
#pragma endregion



#pragma region LeetCode_101_SymmetricTree
/*Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).

For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :

      1
     / \
    2   2
   / \ / \
  3  4 4  3
But the following[1, 2, 2, null, 3, null, 3] is not:
      1
     / \
    2   2
     \   \
      3    3
Note:
Bonus points if you could solve it both recursively and iteratively.*/

bool BinaryTree::isSymmetric(TreeNode* root) {
	return isMirror(root, root);
}


//����������������ж������������Ƿ���ͬ����Ҳ�������ж�һ���������Ƿ��ǶԳƵ�,���������������Ҫ
bool BinaryTree::isMirror(TreeNode* t1, TreeNode* t2)
{
	if (!t1 && !t2) return true;
	if (!t1 || !t2) return false;
	return (t1->val == t2->val)
		&& isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

#pragma endregion


#pragma region LeetCode_508_MostFrequentSubtreeSum
/*Given the root of a tree
you are asked to find the most frequent subtree sum.
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node(including the node itself).
So what is the most frequent subtree sum value ? 
If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input :

	 5
	/ \
   2  -3
	return[2, -3, 4], since all the values happen only once, return all of them in any order.
	Examples 2
	Input:

     5
    / \
   2  -5
return[2], since 2 happens twice, however - 5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32 - bit signed integer.*/
vector<int> BinaryTree::findFrequentTreeSum(TreeNode* root) {
	map<int, int> counts;
	int maxCount = 0;
	countSubtreeSums(root, counts, maxCount);


	vector<int> maxSums;

	//������������������ȵ�����
	for (const auto& x : counts) {
		if (x.second == maxCount) maxSums.push_back(x.first);
	}

	return maxSums;


	
}

//��������ڱ����Ļ����ϸĽ���,��һ�ֺ������
int BinaryTree::countSubtreeSums(TreeNode* node, map<int, int> &counts, int& maxCount)
{
	if (!node) return 0;

	int sum = node->val;
	//���α������ߵ�����
	sum += countSubtreeSums(node->left, counts, maxCount);
	sum += countSubtreeSums(node->right, counts, maxCount);
	//������Ϊ�����һ�������counts[sum]�����ڣ���ô�ͻ�ֱ�Ӳ���һ���µģ�Ȼ���ھ���++��ͱ�Ϊ1;
	++counts[sum];
	//�ڱ����Ĺ�������ÿһ�����ֵĳ��ִ������жԱȣ��������ܱȽϳ�����ʹ�ô���
	maxCount = max(maxCount, counts[sum]);
	
	return sum;
}

#pragma endregion