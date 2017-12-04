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
	//��������������Ҷ�ڵ�֮��
	sum += countLeftLeavesSum(root->left);
	//��������������Ҷ�ڵ�֮��
	sum += countLeftLeavesSum(root->right);

	//������ �ȽϿ�����ڵ��Ƿ���Ҷ�ڵ㣬����ǣ��Ͱ����ֵ�ۼ�����
	if (root->left&&!(root->left->left)&&!(root->left->right))  sum += root->left->val;
	return sum;
}

#pragma endregion



/*!!!!!!!!!!!δ����!!!!!!!!!!!*/
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
����һ���ǿյ����������������������ɷǸ�����ɣ�ÿһ���ڵ�Ҫ���������ӽڵ�Ҫ����û���ӽڵ㣬���ң��������ڵ��������ӽڵ�Ļ�������ڵ��ֵ�ͻ�С�����������ӽڵ�
  Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

  If no such second minimum value exists, output - 1 instead.*/

int BinaryTree::findSecondMinimumValue(TreeNode* root)
{
	//�˷ѿռ�ļ�����
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

//һ���ڵ�����������ã�����Ӧ�ó������
int BinaryTree::dfs_secondMinVal(TreeNode* p, int first)
{
	//��ǰ��㲻����
	if (p == nullptr) return -1;
	//��ǰ�ڵ��ֵ������������ȵı���ֵ
	if (p->val != first) return p->val;
	//����ľ����ڵ���Ԥ��ֵ�������
	//������������
	int left = dfs_secondMinVal(p->left, first), right = dfs_secondMinVal(p->right, first);
	// if all nodes of a subtree = root->val, 
	// there is no second minimum value, return -1
	//���һ��������ֵ����-1����ζ��������������ڣ�ֱ�ӷ�����һ�������Ľ��
	if (left == -1) return right;
	if (right == -1) return left;
	//���������������ڵ�����£����ؽ�С����һ������Ϊ��������ڵ��ֵ������������С��
	//���Է���min(left, right)��ζ������������ڵ��е����ڶ�С�ģ�Ҳ�ͷ�����ĿҪ��
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

/*!!!!!!!!!!!δ����!!!!!!!!!!!*/
#pragma region LeetCode_450_DeleteNodeinaBST
TreeNode* BinaryTree::deleteNode(TreeNode* root, int key)
{
	//root�����ڵ������
	if (!root) return nullptr;
	//���root��ֵ����key
	if (root->val == key) {
		//������������������
		if (!root->right) {
			//û����������ֱ�Ӱ���������λ
			TreeNode* left = root->left;
			delete root;
			return left;
		}
		else 
		{
			//���������ڵ�����£�Ҫ�ҵ����������������ֵ����С���Ǹ�
			//������ֵ��ȥ��ȷ������������������������һ���̶��϶�������ĸĶ��̶���С
			TreeNode* right = root->right;
			while (right->left)
				right = right->left;
			swap(root->val, right->val);
		}
	}
	//Ȼ����ǽ��б���
	root->left = deleteNode(root->left, key);
	root->right = deleteNode(root->right, key);
	return root;
}
#pragma endregion

/*!!!!!!!!!!!���ɵķ���!!!!!!!!!!!*/
#pragma region LeetCode_116_PopulatingNextRightPointersInEachNode
//����ֻ��������������
void BinaryTree::connect(TreeLinkNode *root) {
	if (!root)
		return;
	while (root->left)
	{
		TreeLinkNode *p = root;
		while (p)
		{
			//������p->left��left��Ϊp->right
			p->left->next = p->right;
			//Ȼ���ټ���Ƿ����������ӽڵ���ڣ��еĻ��������ߵĽڵ���ұ��ӽڵ������ұߵĽڵ������ӽڵ�������
			if (p->next)
				p->right->next = p->next->left;

			//Ȼ��P�������ƶ���p->next;
			p = p->next;
		}
		//����һ����������Ժ󣬽�����һ�㵽����ߵĽڵ�
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

//ǰ�������������
inline void BinaryTree::inorderDFS(TreeNode* root, string& order) 
{
	if (!root) return;
	//ʹ��һ��char�������Ϊ��
	char buf[4];
	//��root->val��ֵ������buf����������棬�ڴ�����СΪint�͵Ĵ�С
	//��Ϊһ��int��32λ����char��8λ������ʹ�ô�СΪ4��char������װ���֣��������ܿ���
	memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars

	//Ȼ���buf��������ְ�����4λ4λ�ļӵ�ָ����stringĩβ
	for (int i = 0; i<4; i++) order.push_back(buf[i]);

	inorderDFS(root->left, order);
	inorderDFS(root->right, order);
}
/*
std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//��չ�ַ����Է������
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



/****************************δ����****************************/
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
		//����һ���½ڵ㣬��Ϊ��ͷ
		TreeLinkNode* tempChild = new TreeLinkNode(0);
		//������һ��ָ��ָ�����ͷ
		TreeLinkNode* currentChild = tempChild;
		//ʹ��root����Ϊѭ��������ֻҪroot��Ϊ��
		while (root != nullptr) {
			//�����ж���ߣ�
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

//����һ�ֱ���������·���ĺ÷���
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

	//Ȼ����������ʣ��ֵ�ֿ�ʼ������һ�ֵĲ��ң���Ϊ���������������пղ��������Բ���Ҫ�ڽ���һ���п�
	findPaths(node->left, sum - node->val, path, paths);
	findPaths(node->right, sum - node->val, path, paths);
	//���һ��Ҫ�Ѵ������ĳ�ջ����Ȼ������ԣ�����Ҫ
	path.pop_back();
}


#pragma endregion


/*****************û�кܺõ����*******************/
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

//������������е����β����������������ͣ�Ҫ��֤ÿһ�ζ���ֱ�ӵ��������������������
//��ô���õ����ֲ�����ÿ�ζ���Ҫ�ģ���Ѳ���Ҫ�Ĳ��ּӽ�ȥ��������ܶ�
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




