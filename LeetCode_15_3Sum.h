#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class LeetCode_15_3Sum
{
	vector<vector<int>> threeSum(vector<int>& num) {

		vector<vector<int> > res;

		std::sort(num.begin(), num.end());

		for (int i = 0; i < num.size(); i++) {

			//要想获得最后为0的三个数，在第一个数确定的情况下，只要另外两个数为
			int target = -num[i];
			//所以接下来就要从这第一个数的右边开始找这两个数
			//区间是这个数右边第一个和最右边的那最后一个
			int front = i + 1;

			int back = num.size() - 1;

			//在这个循环中查找2个数
			while (front < back) {

				//先将两个数加起来看看
				int sum = num[front] + num[back];

				// Finding answer which start from number num[i]
				//如果和比预期值小，那么说明这个front太小了，需要下一个
				if (sum < target)
					front++;
				//如果这个值比预期值大，那么说明back太大了，需要前移一个
				else if (sum > target)
					back--;
				//那么剩下的就是正好相等，这种情况下就是我们所需要的
				else {
					//声明一个vector<int>型变量来存储这个3sum
					vector<int> triplet(3, 0);
					triplet[0] = num[i];
					triplet[1] = num[front];
					triplet[2] = num[back];
					//分别赋值以后就把这个值压进准备好的返回值中
					res.push_back(triplet);

					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					//有可能number2不止一个，为了防止这种情况，只要num[front]的值是等价于triplet[1]的
					//那么就需要再进以为去掉这种重复的可能，这下面的两个while都会至少执行一次
					//只执行一次，那么只是移位，执行2次或以上，必然是存在了重复的数
					while (front < back && num[front] == triplet[1]) front++;

					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}

			}

			// Processing duplicates of Number 1
			//最后再来处理第一个数有重复的情况
			while (i + 1 < num.size() && num[i + 1] == num[i])
				i++;

		}

		return res;
	}

};
