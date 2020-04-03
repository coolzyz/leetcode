/*
 * =====================================================================================
 *
 *       Filename:  1365.cpp
 *
 *    Description:  有多少小于当前数字的数字
 *
 *        Version:  1.0
 *        Created:  2020年03月30日 20时14分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zyz (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
			vector<int> ret;
			for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {

				int target = 0;
				for (vector<int>::iterator jt = nums.begin(); jt != nums.end(); ++jt) {
					if (*it > *jt) {
						target++;
					}
				}
				ret.push_back(target);
			}
			return ret;
		}
};

int main() {
	Solution s;
	vector<int> nums = {8, 7, 5};
	vector<int> ret = s.smallerNumbersThanCurrent(nums);

	for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
		cout << *it << "," << endl;
	}
	return 0;
}
