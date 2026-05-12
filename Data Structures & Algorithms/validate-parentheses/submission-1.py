class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        parentheses = {
            '[' : ']',
            '(' : ')',
            '{' : '}'
        }
        for c in s:
            if c in parentheses:
                stack.append(c)
            else:
                if not stack or c != parentheses[stack.pop()]:
                    return False
        
        if stack:
            return False
        return True