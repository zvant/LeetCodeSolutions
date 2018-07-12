'''
https://leetcode.com/problems/integer-to-english-words/description/
2015/09
80 ms
'''

class Solution(object):
    numbers = ['Zero', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
    tens = ['One', 'Ten', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
    powers = ['One', 'Thousand', 'Million', 'Billion']
    
    def readSeg(self, seg):
        if seg < 0:
            return None
        if seg >= 1000:
            seg %= 1000
        reading = []
        if seg >= 100:
            reading.append(self.numbers[seg / 100])
            reading.append('Hundred')
            seg %= 100
        if seg == 0:
            pass
        elif seg < 20:
            reading.append(self.numbers[seg])
        else:
            reading.append(self.tens[seg / 10])
            if seg % 10 != 0:
                reading.append(self.numbers[seg % 10])
        return ' '.join(reading)
        
    def numberToWords(self, num):
        if num == 0:
            return self.numbers[num]
        result = []
        power = 0
        while num > 0:
            seg = num % 1000
            if seg > 0:
                if power > 0:
                    result.append(self.powers[power])
                result.append(self.readSeg(seg))
            power += 1
            num /= 1000
        
        return ' '.join(result[::-1])
