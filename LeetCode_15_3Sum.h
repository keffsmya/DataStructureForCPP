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

			//Ҫ�������Ϊ0�����������ڵ�һ����ȷ��������£�ֻҪ����������Ϊ
			int target = -num[i];
			//���Խ�������Ҫ�����һ�������ұ߿�ʼ����������
			//������������ұߵ�һ�������ұߵ������һ��
			int front = i + 1;

			int back = num.size() - 1;

			//�����ѭ���в���2����
			while (front < back) {

				//�Ƚ�����������������
				int sum = num[front] + num[back];

				// Finding answer which start from number num[i]
				//����ͱ�Ԥ��ֵС����ô˵�����front̫С�ˣ���Ҫ��һ��
				if (sum < target)
					front++;
				//������ֵ��Ԥ��ֵ����ô˵��back̫���ˣ���Ҫǰ��һ��
				else if (sum > target)
					back--;
				//��ôʣ�µľ���������ȣ���������¾�����������Ҫ��
				else {
					//����һ��vector<int>�ͱ������洢���3sum
					vector<int> triplet(3, 0);
					triplet[0] = num[i];
					triplet[1] = num[front];
					triplet[2] = num[back];
					//�ֱ�ֵ�Ժ�Ͱ����ֵѹ��׼���õķ���ֵ��
					res.push_back(triplet);

					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					//�п���number2��ֹһ����Ϊ�˷�ֹ���������ֻҪnum[front]��ֵ�ǵȼ���triplet[1]��
					//��ô����Ҫ�ٽ���Ϊȥ�������ظ��Ŀ��ܣ������������while��������ִ��һ��
					//ִֻ��һ�Σ���ôֻ����λ��ִ��2�λ����ϣ���Ȼ�Ǵ������ظ�����
					while (front < back && num[front] == triplet[1]) front++;

					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}

			}

			// Processing duplicates of Number 1
			//������������һ�������ظ������
			while (i + 1 < num.size() && num[i + 1] == num[i])
				i++;

		}

		return res;
	}

};
