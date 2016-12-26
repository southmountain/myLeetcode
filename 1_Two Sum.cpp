#include "NeedHeader.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int>a;
	vector<int> c;
	for (int i = 0; i < nums.size(); i++)
	{
		int another = target - nums[i];
		if (a.find(another) != a.end())
		{
			c.push_back(a[another]);
			c.push_back(i);
			return c;
		}
		a[nums[i]] = i;
	}
        throw runtime_error("no");
    }
};