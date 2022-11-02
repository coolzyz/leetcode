"""
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

 示例 1：

 输入：strs = ["flower","flow","flight"]
 输出："fl"
 示例 2：

 输入：strs = ["dog","racecar","car"]
 输出：""
 解释：输入不存在公共前缀。
 """

import typing

class Solution:
    def longestCommonPrefix(self, strs)->str:
        l = len(strs)
        if l <= 0:
            return ""
        if l <= 1:
            return strs[0]

        check = strs[0]
        start = 0
        s = len(check)
        for i in range(s):
            for j in range(l):
                if j == 0:
                    continue
                if len(strs[j]) <= i or check[i] != strs[j][i]:
                     return check[start: i]

        return check



if __name__ == "__main__":
    print(Solution().longestCommonPrefix(["flower", "flow", "flight"]))
    print(Solution().longestCommonPrefix(["dog","racecar","car"]))

