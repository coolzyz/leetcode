"""
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

 示例 1：

 输入：s = "()"
 输出：true
 示例 2：

 输入：s = "()[]{}"
 输出：true
 示例 3：

 输入：s = "(]"
 输出：false

栈 左括号入栈、右括号出栈 最后栈是否为空
 """

def ok(b, c):
    return b == ')' and c == '(' or b == '}' and c == '{' or b == ']' and c == '['

class Solution: 

    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False
        stack = list()
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else:
                if len(stack) <= 0:
                    return False

                check = stack.pop()
                if not ok(c, check):
                    return False

        return len(stack) == 0




if __name__ == "__main__":
    print(Solution().isValid("(]"))
    print(Solution().isValid("()"))
    print(Solution().isValid("()[]{}"))
    print(Solution().isValid("((()))"))
