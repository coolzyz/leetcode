"""
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
 

 示例 1：

 输入：x = 121
 输出：true
 示例 2：

 输入：x = -121
 输出：false
 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 """

class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        start = 0
        end = len(s) - 1
        while start < end:
            if s[start] != s[end]:
                return False

            start += 1
            end -= 1


        return True



if __name__ == "__main__":
    print(Solution().isPalindrome(121))



