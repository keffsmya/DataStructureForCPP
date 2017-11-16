#include "stdafx.h"
#include "LeetCode_11_ContainerWithMostWater.h"
#include <vector>

int LeetCode_11_ContainerWithMostWater::maxArea(vector<int>& height)
{
	int area_Max = 0;
	int area_Temp = 0;
	int i = 0;
	int j = (int)height.size() - 1;

	while (i < j)
	{
		area_Temp = (j - i)*((height[i] < height[j] ? height[i] : height[j]));


		area_Max = (area_Max < area_Temp) ? area_Temp : area_Max;

		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area_Max;
}