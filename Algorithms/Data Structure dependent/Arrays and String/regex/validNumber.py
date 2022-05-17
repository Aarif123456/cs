class Solution:
    # (\+|-) - handles optional sign
    # ((\d+(\.)?\d*) - handles both integer an decimals with dot at end or 
    # decimal with dot on both sides
    # (\.\d+) - handles final decimal cases
    # ((e|E)(\+|-)?\d+)? - handles optional exponent 
    # NOTE: we could just use a single "e" and ignore case here as well 
    
    reg = re.compile(r"^((\+|-)?((\d+(\.)?\d*)|(\.\d+))((e|E)(\+|-)?\d+)?)$")
    def isNumber(self, s: str) -> bool:
        return self.reg.fullmatch(s)
        