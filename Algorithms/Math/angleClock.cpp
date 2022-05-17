class Solution {
public:
    double angleClock(int hours, int minutes) {
        /* 60 minutes/ticks * 60 - gives degree*/
        double minutesDegree = minutes * 6;
        double hoursDegree = (hours * 5)*6;
        /* Max degree must be less then 30 degrees */
        hoursDegree += static_cast<double>(minutes)/2.0;
        double ans = (minutesDegree - hoursDegree);

        while(ans < 0) ans += 360;
        while(ans >= 360) ans -= 360;

        if(ans > 180) return 360.0 - ans;
        return ans; 
    }
};