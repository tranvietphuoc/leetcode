
class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        l = list(s)
        result = 0
        
        while len(l) > 0:
            cur = l.pop(0)
            
            if len(l) > 0 and roman[l[0]] > roman[cur]:
                result +=  roman[l[0]] - roman[cur]
                l.pop(0)  # remove next element
            else:
                result += roman[cur]
        return result
