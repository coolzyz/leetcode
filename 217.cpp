/*
 * =====================================================================================
 *
 *       Filename:  217.cpp
 *
 *    Description:  给定一个整数数组，判断是否存在重复元素
 *
 *        Version:  1.0
 *        Created:  2020年03月30日 09时58分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zyz (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
	public:
		bool containsDuplicate(vector<int>& nums) {
			if (nums.size() <= 1) {
				return false;
			}

			unordered_set<int> all;
			for (int i = 0; i < nums.size(); ++i) {
				// if (all.find(nums[i]) != all.end()) {
				// 	return true;
				// }
				all.insert(nums[i]);
			}
			return all.size() != nums.size();
		}
};
