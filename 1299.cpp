/*
 * =====================================================================================
 *
 *       Filename:  1299.cpp
 *
 *    Description:  将每个元素替换为右侧最大元素
 *
 *        Version:  1.0
 *        Created:  2020年04月03日 20时00分31秒
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
#include <deque>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> replaceElements(vector<int>& arr) {

			int max = -11111111;
			deque<int> tmp;
			for (int i = arr.size() - 1; i >= 0; i--) {

				if (i == arr.size() - 1) {
					tmp.push_front(-1);
					max = arr.at(i);
				} else {
					tmp.push_front(max);
				}

				if (max < arr.at(i)) {
					max = arr.at(i);
				}
			}

			vector<int> ret;
			for (auto it = tmp.begin(); it != tmp.end(); ++it) {
				ret.push_back(*it);
			}
			return ret;
		}

		void print(vector<int> in) {
			for (auto it = in.begin(); it != in.end(); ++it) {
				cout<< *it << ",";
			}
		}
};

int main() {

	Solution s;
	vector<int> a = {17, 18, 5, 4, 6, 1};
	s.print(s.replaceElements(a));
	return 0;
}
