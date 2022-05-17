class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        # filter out to handle cases
        lettersLogs = [log for log in logs if log[log.find(" ")+1].isalpha()]
        digitsLogs = [log for log in logs if log[log.find(" ")+1].isdigit()]

        # sort letters-logs by identifier if everything is the same to break ties
        lettersLogs.sort()
        # sort letter-logs by content 
        lettersLogs.sort(key = lambda log: log[log.find(" ")+1:])

        return lettersLogs + digitsLogs