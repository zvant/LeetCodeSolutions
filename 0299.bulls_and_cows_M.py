'''
https://leetcode.com/problems/bulls-and-cows/description/
2015/11
1304 ms
'''

class Solution(object):
    def getHint(self, secret, guess):
        count_A = 0
        count_B = 0
        secret_mask = []
        for idx in range(0, len(secret)):
            if secret[idx] == guess[idx]:
                count_A += 1
                secret_mask.append('M')
            else:
                secret_mask.append(secret[idx])
        
        for idx in range(0, len(secret)):
            if secret_mask[idx] != 'M':
                try:
                    find_idx = secret_mask.index(guess[idx])
                    secret_mask[find_idx] = 'N'
                    count_B += 1
                except:
                    pass
        
        return ''.join([str(count_A), 'A', str(count_B), 'B'])
