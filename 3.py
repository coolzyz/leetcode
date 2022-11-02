"""
abcabcbb -> 3
pwwkew -> 3
' ' -> 1
'dvdf' -> 3
滑动窗口
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ret = 0
        tset = set()
        strlen = len(s)
    
        i = 0
        inited = False
        while i < strlen:
            #print('checking', i)
            if s[i] in tset:
                if ret < len(tset):
                    ret = len(tset)

                tset.clear()
                i = start
                inited = False
            else:
                tset.add(s[i])

                if not inited:
                    start = i
                    inited = True

            i += 1

        return ret if ret > len(tset) else len(tset)



if __name__ == "__main__":
    print(Solution().lengthOfLongestSubstring("abcabcbb"))
    print(Solution().lengthOfLongestSubstring("pwwkew"))
    print(Solution().lengthOfLongestSubstring(" "))
    print(Solution().lengthOfLongestSubstring("dvdf"))



