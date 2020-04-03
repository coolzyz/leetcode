/*
 * =====================================================================================
 *
 *       Filename:  1342.cpp
 *
 *    Description:  将数字变成 0 的操作次数
 *
 *        Version:  1.0
 *        Created:  2020年03月30日 20时11分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zyz (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

class Solution {
	public:
		int numberOfSteps (int num) {

			int count = 0;
			while (num != 0) {
				count++;
				if (num % 2) {
					num -= 1;
				} else  {
					num /= 2;
				}
			}
			return count;
		}
};
