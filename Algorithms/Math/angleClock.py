class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:

        minutesDegree = (minutes * 6) % 360
        hoursDegree = (hour) * 30 
        # there 5 ticks between the each hour - each represent 6 degree - which gives us 30
        hoursDegree += (float(minutes)/60.0) * 30

        ans = hoursDegree - minutesDegree

        while ans > 360: ans -= 360
        while ans < 0: ans += 360

        if ans > 180: ans = 360 - ans

        return ans