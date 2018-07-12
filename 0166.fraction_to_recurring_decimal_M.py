'''
https://leetcode.com/problems/fraction-to-recurring-decimal/description/
2016/05
44 ms
'''

class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if type(numerator) != type(1) or type(denominator) != type(1) or denominator == 0:
            return None
        
        is_neg = '-' if numerator * denominator < 0 else ''
        numerator = abs(numerator)
        denominator = abs(denominator)

        int_part = numerator / denominator
        numerator = numerator % denominator
        
        if numerator == 0:
            return is_neg + str(int_part)
    
        numerator_list = []
        numerator_list.append(numerator)
        decimal_parts = []
    
        while True:
            numerator *= 10
            if numerator < denominator:
                decimal_parts.append('0')
            else:
                decimal_parts.append(str(numerator / denominator))
                numerator = numerator % denominator
            if (numerator in numerator_list) or numerator == 0:
                break
            else:
                numerator_list.append(numerator)
    
        if len(decimal_parts) <= 0:
            return is_neg + str(int_part)
        
        if numerator in numerator_list:
            decimal_parts.insert(numerator_list.index(numerator), '(')
            decimal_parts.append(')')
        
        return is_neg + str(int_part) + '.' + ''.join(decimal_parts)
