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




	/*上面为尝试部分，是假设两个节点不同，但是里面的元素的值相同*/

	//首先判断这两个根节点是否为空，不为空的情况下，直接返回比较的结果，
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
			//返回队列头部元素的引用
			TreeNode* t = q.front();
			//然后把头部元素出列


			q.pop();
			if (t) temp.push_back(t->val);
			//然后如果左右子项存在，就把这两个子项也入队
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);

		}
		//然后进行运算，
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
			//返回队列头部元素的引用
			TreeNode* t = q.front();
			//然后把头部元素出列
			
			
			q.pop();
			if(t) temp.push_back(t->val);
			//然后如果左右子项存在，就把这两个子项也入队
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
			
		}
		//然后进行运算，
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
//给出一个二叉树，返回这个二叉树的偏斜
//The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values.Null node has tilt 0.
//偏斜的定义：【左子数的所有数的和】与【右子数的所有数之和】的【绝对差】
//The tilt of the whole tree is defined as the sum of all nodes' tilt.
//所以一棵树的偏斜是从根节点开始，满足下列公式：本节点的【左右子树的倾斜度之和】(因为本题的要求是一棵树的所有倾斜度之和)+【左右子树的[所有数之和]之差】
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
///用来寻找树的最大深度
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

//isSameTree起以前的LeetCode相关功能，可以直接借用
//isSameTree只负责以当前结点为根的树是否为sametree
//所以还需要一个函数来进行遍历，不光要当前结点，还要遍历获取他的子树
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
	//如果根为空，那么算作平衡二叉树
	if (!root) return true;
	//首先判断两边子树的【最大长度】之差是否小于等于1
	bool B1 = (std::abs(getThemaxlength(root->left) - getThemaxlength(root->right))) <= 1;
	//接着遍历两边的子树，因为平衡二叉树的定义，【任何】一个节点的两个子数的长度之差不能小于2，所以当前光是当前结点是不够的
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


//这个函数可以用于判定两个二叉树是否镜像，同样的也可用于判定一个二叉树是否是对称的,所以这个函数很重要
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

	//最后遍历出和最大次数相等的数字
	for (const auto& x : counts) {
		if (x.second == maxCount) maxSums.push_back(x.first);
	}

	return maxSums;


	
}

//这个函数在遍历的基础上改进了,是一种后序遍历
int BinaryTree::countSubtreeSums(TreeNode* node, map<int, int> &counts, int& maxCount)
{
	if (!node) return 0;

	int sum = node->val;
	//依次遍历两边的子树
	sum += countSubtreeSums(node->left, counts, maxCount);
	sum += countSubtreeSums(node->right, counts, maxCount);
	//这是最为精髓的一步，如果counts[sum]不存在，那么就会直接插入一个新的，然后在经过++后就变为1;
	++counts[sum];
	//在遍历的过程中与每一个数字的出现次数进行对比，这样就能比较出最大的使用次数
	maxCount = max(maxCount, counts[sum]);
	
	return sum;
}

#pragma endregion