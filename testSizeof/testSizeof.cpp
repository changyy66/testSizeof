// testSizeof.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


int candy(vector<int> &ratings) {
	if (ratings.size() == 0)return 0;
	int total = 1;
	int dijian = 1;
	int nowNum = 1;
	int right;
	for (int i = 1; i < ratings.size(); i++)
	{
		if (ratings[i] > ratings[i - 1])
		{
			nowNum++;
			total += nowNum;
		}
		else
		{
			right = i;
			while (right < ratings.size() && ratings[right] <= ratings[right - 1])
			{
				right++;
			}
			int j = right - 1;
			int newNum = 1;
			while (j >= i)
			{
				total += newNum;
				if (ratings[j] != ratings[j - 1])
					newNum++;
				j--;
			}
			if (newNum > nowNum ) total += newNum - nowNum ;
			i = right - 1;
			nowNum = 1;
		}
	}
	return total;
}

int main()
{
	vector<int> d = { 1,2,1};
	cout << candy(d);
    return 0;
}

