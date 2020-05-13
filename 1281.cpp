/*
 * =====================================================================================
 *
 *       Filename:  1281.cpp
 *
 *    Description:  积和之差
 *
 *        Version:  1.0
 *        Created:  2020年04月03日 19时30分17秒
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
		int subtractProductAndSum(int n) {
			int sum = 0;
			int muli = 1;
			while (n != 0) {
				sum += n%10;
				muli *= n % 10;
				n /= 10;
			}
			return muli - sum;
		}
};
