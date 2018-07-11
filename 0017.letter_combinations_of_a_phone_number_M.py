'''
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
2015/08
44 ms
'''

class Solution:
    buttons = []
    buttons.append([])
    buttons.append([])
    buttons.append(['a', 'b', 'c'])
    buttons.append(['d', 'e', 'f'])
    buttons.append(['g', 'h', 'i'])
    buttons.append(['j', 'k', 'l'])
    buttons.append(['m', 'n', 'o'])
    buttons.append(['p', 'q', 'r', 's'])
    buttons.append(['t', 'u', 'v'])
    buttons.append(['w', 'x', 'y', 'z'])
    
    # @param {string[]} digits
    # @param {string[]} combined
    def combine(self, digits, combined):
        if len(digits) <= 0:
            self.combinations.append(combined)
        else:
            digits_removed = digits[:]
            n = digits_removed[0]
            del digits_removed[0]
            for letter in self.buttons[int(n)]:
                combined_add = combined[:]
                combined_add.append(letter)
                self.combine(digits_removed, combined_add)
    
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        if len(digits) <= 0:
            return []
        
        self.combinations = []
        self.combine([letter for letter in digits], [])
        return [''.join(combination) for combination in self.combinations]
