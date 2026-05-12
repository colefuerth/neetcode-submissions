class Solution:
    
    def xor_of_chars(self, s: str) -> int:
        i = 0
        for c in s:
            i ^= ord(c)
        return i
    
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        i1 = self.xor_of_chars(s1)
        i2 = self.xor_of_chars(s2[:len(s1)])
        for i in range(len(s1), len(s2)):
            if i1 == i2:
                return True
            i2 ^= ord(s2[i - len(s1)])
            i2 ^= ord(s2[i])
        return i1 == i2