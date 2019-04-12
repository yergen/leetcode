#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.size() < 2)
			return{};

		unordered_map<int, int> hash_map;
		for (int i = 0; i < nums.size(); ++i)
		{
			hash_map.insert({ nums[i], i });
			int element = target - nums[i];
			if (hash_map.find(element) != hash_map.end() && i != hash_map[element])
			{
				return{ hash_map[element],i };
			}
		}

		return{};
	}
};