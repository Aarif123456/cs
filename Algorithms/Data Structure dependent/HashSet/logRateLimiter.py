from collections import defaultdict
class Logger:

    def __init__(self, space=10):
        self.logTracker = defaultdict(lambda:-space)

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if self.logTracker[message] + 10 <= timestamp:
            self.logTracker[message] = timestamp
            return True
        return False


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)