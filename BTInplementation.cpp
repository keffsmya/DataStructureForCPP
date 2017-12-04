#include "stdafx.h"
#include "BTInplementation.h"
#include <Algorithm>
#include <queue>
#include <stack>
#include <map>
#include <string>

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



#pragma region LeetCode_404_SumofLeftLeaves

int BinaryTree::sumOfLeftLeaves(TreeNode* root)
{
	int res;
	res = countLeftLeavesSum(root);
	return res;
}

int BinaryTree::countLeftLeavesSum(TreeNode* root)
{
	if (!root)  return 0;
	int sum = 0;
	//左子树的所有左叶节点之和
	sum += countLeftLeavesSum(root->left);
	//右子树的所有左叶节点之和
	sum += countLeftLeavesSum(root->right);

	//左后后序 比较看这个节点是否是叶节点，如果是，就把这个值累加起来
	if (root->left&&!(root->left->left)&&!(root->left->right))  sum += root->left->val;
	return sum;
}

#pragma endregion



/*!!!!!!!!!!!未掌握!!!!!!!!!!!*/
#pragma region LeetCode_513_FindBottomLeftTreeValue
int BinaryTree::findBottomLeftValue(TreeNode* root)
{
	int maxDepth = 0;
	int leftVal = root->val;

	findBottomLeftValue(root, maxDepth, leftVal, 0);
	return leftVal;

}

void BinaryTree::findBottomLeftValue(TreeNode* root, int& maxDepth, int& leftVal, int depth)
{
	if (!root) return;
	//traverse left and right
	findBottomLeftValue(root->left, maxDepth, leftVal, depth + 1);
	findBottomLeftValue(root->right, maxDepth, leftVal, depth + 1);

	//Update LeftVal And MaxDepth
	if (depth > maxDepth) {
		maxDepth = depth;
		leftVal = root->val;
	}
}
#pragma endregion 

#pragma region LeetCode_671_SecondMinimunNodeInaBinaryTree
/*Given a non - empty special binary tree consisting of nodes with the non - negative value, where each node in this tree has exactly two or zero sub - node.
  If the node has two sub - nodes, then this node's value is the smaller value among its two sub-nodes.
给出一个非空的特殊二叉树，这个二叉树由非负数组成，每一个节点要不是两个子节点要不就没有子节点，而且，如果这个节点有两个子节点的话，这个节点的值就会小于他的两个子节点
  Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

  If no such second minimum value exists, output - 1 instead.*/

int BinaryTree::findSecondMinimumValue(TreeNode* root)
{
	//浪费空间的简单做法
#pragma region Easyway
	/*if (!root) return -1;

	vector<int> resv;
	findSecondMinimumValue(root, resv);
	std::sort(resv.begin(), resv.end());
	switch ((int)resv.size())
	{

	case 0:
	case 1:
		return -1;
	default:
		int comp = resv[0];
		int temp = INT_MAX;
		for (int i = 0; i<(int)resv.size(); i++)
		{

			temp = resv[i];
			if (comp != temp) break;
			else if (i == (int)resv.size() - 1) return -1;
		}
		return temp;

	}*/
#pragma endregion Easyway

#pragma region DepthFirst Search
	if (!root) return -1;
	int ans = dfs_secondMinVal(root, root->val);
	return ans;
#pragma endregion DepthFirst Search


}

void BinaryTree::findSecondMinimumValue(TreeNode* root, vector<int>& vec)
{
	if (!root) return;

	//Traverse left and right tree
	findSecondMinimumValue(root->left, vec);
	findSecondMinimumValue(root->right, vec);

	vec.push_back(root->val);

}

//一个节点包含三个引用，所以应该充分利用
int BinaryTree::dfs_secondMinVal(TreeNode* p, int first)
{
	//当前结点不存在
	if (p == nullptr) return -1;
	//当前节点的值不能与深度优先的保留值
	if (p->val != first) return p->val;
	//下面的就是在等于预留值的情况下
	//遍历两个子树
	int left = dfs_secondMinVal(p->left, first), right = dfs_secondMinVal(p->right, first);
	// if all nodes of a subtree = root->val, 
	// there is no second minimum value, return -1
	//如果一边子树的值等于-1就意味着这边子树不存在，直接返回另一边子树的结果
	if (left == -1) return right;
	if (right == -1) return left;
	//在两边子树都存在的情况下，返回较小的那一个，因为本身这个节点的值根据题意是最小的
	//所以返回min(left, right)意味着是这个三个节点中倒数第二小的，也就符合题目要求
	return min(left, right);
}

#pragma endregion


#pragma region LeetCode_617_MergeTwoBinaryTrees
TreeNode* BinaryTree::mergeTrees(TreeNode* t1, TreeNode* t2)
{
#pragma region way_CreateNewTrees
	if (!t1 && !t2) return nullptr;
	else if (!t1) return t2;
	else if (!t2) return t1;


	TreeNode* node = new TreeNode(t1->val + t2->val);
	node->left = mergeTrees(t1->left, t2->left);
	node->right = mergeTrees(t1->right, t2->right);
	return node;
#pragma endregion


	
}


#pragma endregion

/*!!!!!!!!!!!未掌握!!!!!!!!!!!*/
#pragma region LeetCode_450_DeleteNodeinaBST
TreeNode* BinaryTree::deleteNode(TreeNode* root, int key)
{
	//root不存在的情况下
	if (!root) return nullptr;
	//如果root的值等于key
	if (root->val == key) {
		//这种情况下有两种情况
		if (!root->right) {
			//没有右子树，直接把左子树上位
			TreeNode* left = root->left;
			delete root;
			return left;
		}
		else 
		{
			//右子树存在的情况下，要找到这个右子树中所有值中最小的那个
			//将他赋值上去，确保其他所有数都比他大，这样一定程度上对这个树的改动程度最小
			TreeNode* right = root->right;
			while (right->left)
				right = right->left;
			swap(root->val, right->val);
		}
	}
	//然后就是进行遍历
	root->left = deleteNode(root->left, key);
	root->right = deleteNode(root->right, key);
	return root;
}
#pragma endregion

/*!!!!!!!!!!!精巧的方法!!!!!!!!!!!*/
#pragma region LeetCode_116_PopulatingNextRightPointersInEachNode
//此题只满足完美二叉树
void BinaryTree::connect(TreeLinkNode *root) {
	if (!root)
		return;
	while (root->left)
	{
		TreeLinkNode *p = root;
		while (p)
		{
			//首先是p->left的left设为p->right
			p->left->next = p->right;
			//然后再检查是否有他的链接节点存在，有的话把相对左边的节点的右边子节点和相对右边的节点的左边子节点相连接
			if (p->next)
				p->right->next = p->next->left;

			//然后P的引用移动到p->next;
			p = p->next;
		}
		//在这一层遍历完了以后，进入下一层到最左边的节点
		root = root->left;
	}
}


#pragma endregion



#pragma region LeetCode_449_SerializeandDeserializeBST
//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary search tree.There is no restriction on how your serialization / deserialization algorithm should work.You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//The encoded string should be as compact as possible.
//
//Note: Do not use class member / global / static variables to store states.Your serialize and deserialize algorithms should be stateless.

// Encodes a tree to a single string.
string BinaryTree::serialize(TreeNode* root) {

	string order;
	//inorderDFS(root, order);
	return order;
}

//前序深度优先搜索
inline void BinaryTree::inorderDFS(TreeNode* root, string& order) 
{
	if (!root) return;
	//使用一个char数组体积为四
	char buf[4];
	//把root->val的值拷贝到buf这个数组里面，内存分配大小为int型的大小
	//因为一个int是32位，而char是8位，所以使用大小为4的char数组来装数字，出于性能考虑
	memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars

	//然后把buf里面的数字按数字4位4位的加到指定的string末尾
	for (int i = 0; i<4; i++) order.push_back(buf[i]);

	inorderDFS(root->left, order);
	inorderDFS(root->right, order);
}
/*
std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//扩展字符串以方便操作
	int size = str.size();

	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}
*/

inline TreeNode* BinaryTree::reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
	if (pos >= (int)buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.

	int value;
	memcpy(&value, &buffer[pos], sizeof(int));
	if (value < minValue || value > maxValue) return NULL;

	TreeNode* node = new TreeNode(value);
	pos += sizeof(int);
	node->left = reconstruct(buffer, pos, minValue, value);
	node->right = reconstruct(buffer, pos, value, maxValue);
	return node;
}


// Decodes your encoded data to tree.
TreeNode* BinaryTree::deserialize(string data) {
	int pos = 0;

	return reconstruct(data, pos, INT_MIN, INT_MAX);

}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#pragma endregion



/****************************未掌握****************************/
#pragma region LeetCode_117_PopulatingNextRightPointersinEachNodeII

/*Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree ? Would your previous solution still work ?

Note :

	You may only use constant extra space.
	For example,
	Given the following binary tree,
	    1
	   / \
	  2    3
	 / \    \
	4   5    7
	After calling your function, the tree should look like :
        1->NULL
       / \
      2 -> 3->NULL
     / \    \
    4-> 5 -> 7->NULL*/

void BinaryTree::connect_II(TreeLinkNode *root) {
	while (root != nullptr) {
		//声明一个新节点，作为新头
		TreeLinkNode* tempChild = new TreeLinkNode(0);
		//再声明一个指针指向这个头
		TreeLinkNode* currentChild = tempChild;
		//使用root来作为循环条件，只要root不为空
		while (root != nullptr) {
			//首先判断左边，
			if (root->left != nullptr) 
			{ 
				currentChild->next = root->left; 
				currentChild = currentChild->next;
			}
			if (root->right != nullptr) 
			{ 
				currentChild->next = root->right;
				currentChild = currentChild->next;
			}
			root = root->next;
		}
		root = tempChild->next;
	}

		

}
#pragma endregion

//这是一种遍历并保存路径的好方法
#pragma region LeetCode_113_PathSumII

/*
Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.

For example :
Given the below binary tree and sum = 22,
        5
       / \
      4   8
     /   / \
    11  13  4
   / \     / \
  7   2    5  1
return
[
	[5, 4, 11, 2],
	[5, 8, 4, 5]
]
*/


vector<vector<int>> BinaryTree::pathSum(TreeNode* root, int sum) {
	vector<vector<int> > paths;
	vector<int> path;
	findPaths(root, sum, path, paths);
	return paths;

}


void BinaryTree::findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
	if (!node) return;
	path.push_back(node->val);
	if (!node->left && !node->right&&node->val == sum) paths.push_back(path);

	//然后子树带着剩余值又开始进行下一轮的查找，因为本迭代函数具有判空操作，所以不需要在进行一次判空
	findPaths(node->left, sum - node->val, path, paths);
	findPaths(node->right, sum - node->val, path, paths);
	//最后一步要把存下来的出栈，不然结果不对，很重要
	path.pop_back();
}


#pragma endregion


/*****************没有很好的理解*******************/
#pragma region LeetCode_337_HouseRobberIII
/*
The thief has found himself a new place for his thievery again.
There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house.
After a tour, the smart thief realized that "all houses in this place forms a binary tree".
It will automatically contact the police 
if two directly - linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

#pragma region myAttempt

//int BinaryTree::rob(TreeNode* root) {
//	vector<int> sums;
//	vector<int> path;
//	findAllRootToLeavesPaths(root, path, sums);
//	if ((int)sums.size() == 0) return 0;
//	int temp = INT_MIN;
//	for (vector<int>::iterator iter = sums.begin(); iter != sums.end(); iter++)
//	{
//		if (*iter > temp)
//		{
//			temp = *iter;
//		}
//	}
//
//	return temp;
//}
//
//void BinaryTree::findAllRootToLeavesPaths(TreeNode* node, vector<int>& path, vector<int>& sums)
//{
//	if (!node) return;
//	path.push_back(node->val);
//	int path_sum = 0;
//	if (!node->left && !node->right)
//	{
//		
//		for (vector<int>::iterator iter = path.begin(); iter != path.end(); iter++)
//		{
//			path_sum += *iter;
//		}
//	}
//	sums.push_back(path_sum);
//	if (node->left&&node->right)
//	{
//		if(node->left>node->right)  findAllRootToLeavesPaths(node->left, path, sums);
//		else findAllRootToLeavesPaths(node->right, path, sums);
//	}
//	path.pop_back();
//}
#pragma endregion

int BinaryTree::rob(TreeNode* root) {
	int l, r;
	return tryRob(root, l, r);
}

int BinaryTree::tryRob(TreeNode* root, int& l, int& r) {
	if (!root)
		return 0;

	int ll = 0, lr = 0, rl = 0, rr = 0;
	l = tryRob(root->left, ll, lr);
	r = tryRob(root->right, rl, rr);

	return max(root->val + ll + lr + rl + rr, l + r);
}

#pragma endregion


#pragma region LeetCode_129_SumRoottoLeafNumbers
int BinaryTree::sumNumbers(TreeNode* root) {
	return sumNumbersUtil(root,0);
}

//这个辅助函数中的整形参数不能是引用类型，要保证每一次都是直接的声明变量，如果是引用
//那么引用的数字不会是每次都想要的，会把不需要的部分加进去，结果会大很多
int BinaryTree :: sumNumbersUtil(TreeNode* node, int val)
{
	if (!node) return 0;

	val = val * 10 + node->val;

	if (!node->left && !node->right) return val;

	return sumNumbersUtil(node->left, val) + sumNumbersUtil(node->right, val);
}

#pragma endregion



#pragma region LeetCode_144_BinaryTreePreorderTraverse
vector<int> BinaryTree::preorderTraversal(TreeNode* root) {
	vector<int> res;

	preorderTraversalUtil(root, res);
	return res;
}

void BinaryTree::preorderTraversalUtil(TreeNode* root,vector<int>& vec)
{
	if (!root) return;
	vec.push_back(root->val);
	preorderTraversalUtil(root->left,vec);
	preorderTraversalUtil(root->right, vec);
}


#pragma endregion




