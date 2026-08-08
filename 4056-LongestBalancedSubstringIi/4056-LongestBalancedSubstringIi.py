# Last updated: 8/8/2026, 3:42:56 PM
class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0

        ans = 1  
       
        cur = 1
        for i in range(1, n):
            if s[i] == s[i-1]:
                cur += 1
                ans = max(ans, cur)
            else:
                cur = 1

        cnt = {'a': 0, 'b': 0, 'c': 0}
        first = {(0, 0): -1}          
        for i, ch in enumerate(s):
            cnt[ch] += 1
            dAB = cnt['a'] - cnt['b']
            dAC = cnt['a'] - cnt['c']
            key = (dAB, dAC)
            if key in first:
                ans = max(ans, i - first[key])
            else:
                first[key] = i

        pairs = [('a', 'b', 'c'), ('a', 'c', 'b'), ('b', 'c', 'a')]

        for x, y, z in pairs:
            i = 0
            while i < n:
                if s[i] == z:
                    i += 1
                    continue

                start = i
                while i < n and s[i] != z:
                    i += 1
                end = i - 1   

                sum_map = {0: start - 1}
                cur_sum = 0
                for j in range(start, end + 1):
                    if s[j] == x:
                        cur_sum += 1
                    elif s[j] == y:
                        cur_sum -= 1
                    if cur_sum in sum_map:
                        ans = max(ans, j - sum_map[cur_sum])
                    else:
                        sum_map[cur_sum] = j

        return ans